#include "SoundEngineException.h"
#include "CSoundManager.h"
#include "CListener.h"
#include "CSoundFactory.h"
#include "IO/CFileSystem.h"
#include "IO/CoreLogging.h"

#include "OgreRoot.h"

#if SOUND_THREADED
	boost::thread* Sound::CSoundManager::mOgreALThread = nullptr;
	bool Sound::CSoundManager::mShuttingDown = false;
#endif

namespace Sound 
{
const String CSoundManager::SOUND_FILE = "SoundFile";
const String CSoundManager::LOOP_STATE = "LoopState";
const String CSoundManager::STREAM = "Stream";

const ALenum CSoundManager::xRamAuto = alGetEnumValue("AL_STORAGE_AUTO");
const ALenum CSoundManager::xRamHardware = alGetEnumValue("AL_STORAGE_HARDWARE");
const ALenum CSoundManager::xRamAccessible = alGetEnumValue("AL_STORAGE_ACCESSIBLE");

CSoundManager* CSoundManager::SoundManager = nullptr;

CSoundManager* CSoundManager::Instance()
{
	if(SoundManager == nullptr)
		SoundManager = new CSoundManager();
	return SoundManager;
}

CSoundManager::CSoundManager() : 
	m_EAXSupport(false),
	m_EAXVersion(0),
	m_XRAMSupport(false),
	m_EFXSupport(false),
	m_SendsPerSource(10),
	m_Context(nullptr),
	m_Device(nullptr),
	m_DopplerFactor(1.0f),
	m_SpeedOfSound(343.3f),
	m_MaxNumSources(0),
	m_MajorVersion(0),
	m_MinorVersion(0),
	m_LastDeltaTime(0.0f),
	m_IsBaseSoundsLoaded(false),
	m_IsBaseSoundsLoading(false)
{
	CORE_LOG("*-*-* OgreAL Initialization");

	// Create and register CSound and CListener Factories
	m_SoundFactory = new CSoundFactory();
	m_ListenerFactory = new ListenerFactory();
	
	Ogre::Root::getSingleton().addMovableObjectFactory(m_SoundFactory);
	Ogre::Root::getSingleton().addMovableObjectFactory(m_ListenerFactory);

	CORE_LOG("*-*-* Creating OpenAL");

	InitializeDevice();

	CheckFeatureSupport();

	CreateListener();

	#if SOUND_THREADED
		// Kick off the update thread
		CORE_LOG("Creating OgreAL Thread");
		mOgreALThread = new boost::thread(boost::function0<void>(&CSoundManager::threadUpdate));
	#else
		// Register for frame events
		Ogre::Root::getSingleton().addFrameListener(this);
	#endif
}

CSoundManager::~CSoundManager()
{
	CORE_LOG("*-*-* OgreAL Shutdown");

	#if SOUND_THREADED
		// Clean up the threading
		CORE_LOG("Shutting Down OgreAL Thread");
		mShuttingDown = true;
		mOgreALThread->join();
		CORE_DELETE(mOgreALThread);
	#else
		// Unregister for frame events
		Ogre::Root::getSingleton().removeFrameListener(this);
	#endif

	// delete all CSound pointers in the SoundMap
	DestroyAllSounds();

	// Destroy the CListener and all Sounds
	delete CListener::Instance();

	// Clean out m_ActiveSounds and m_QueuedSounds
	m_ActiveSounds.clear();
	m_QueuedSounds.clear();

	// Clean up the SourcePool
	while(!m_SourcePool.empty())
	{
		alDeleteSources(1, &m_SourcePool.front());
		CheckError(alGetError(), "Failed to destroy source");
		m_SourcePool.pop();
	}

	// delete all CFormatData pointers in the FormatMap;
	std::for_each(m_SupportedFormats.begin(), m_SupportedFormats.end(), DeleteSecond());
	m_SupportedFormats.clear();

	// Unregister the CSound and CListener Factories
	Ogre::Root::getSingleton().removeMovableObjectFactory(m_SoundFactory);
	Ogre::Root::getSingleton().removeMovableObjectFactory(m_ListenerFactory);
	CORE_DELETE(m_ListenerFactory);
	CORE_DELETE(m_SoundFactory);

	CORE_LOG("*-*-* Releasing OpenAL");

	// Release the OpenAL Context and the Audio device
	alcMakeContextCurrent(nullptr);
	alcDestroyContext(m_Context);
	alcCloseDevice(m_Device);
}

CSound* CSoundManager::CreateSound(const String& fileName, bool loop, bool stream)
{
	String name = fileName + StringConverter::toString(m_SoundMap.size());
	return CreateSound(name, fileName, loop, stream);
}

CSound* CSoundManager::CreateSound(const String& name, const String& fileName, bool loop, bool stream)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	CheckCondition(m_SoundMap.find(name) == m_SoundMap.end(), 13, "A Sound with name '" + name + "' already exists.");

	Ogre::NameValuePairList fileTypePair;
	fileTypePair[SOUND_FILE] = fileName;
	fileTypePair[LOOP_STATE] = Ogre::StringConverter::toString(loop);
	fileTypePair[STREAM] = Ogre::StringConverter::toString(stream);
	
	CSound *newSound = static_cast<CSound*>(m_SoundFactory->createInstance(name, nullptr, &fileTypePair));
	m_SoundMap[name] = newSound;
	return newSound;
}

CSound* CSoundManager::GetSound(const char* Name) const
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	SoundMap::const_iterator soundItr = m_SoundMap.find(Name);
	if(soundItr == m_SoundMap.end())
	{
		String msg = "Object named '" + String(Name) + "' does not exist. CSoundManager::GetSound";
		CORE_LOG(msg.c_str());
		return nullptr;
	}

	return soundItr->second;
}

bool CSoundManager::HasSound(const char* Name) const
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	SoundMap::const_iterator soundItr = m_SoundMap.find(Name);
	if(soundItr != m_SoundMap.end())
		return true;
	else
		return false;
}

void CSoundManager::DestroySound(CSound *sound)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	DestroySound(sound->getName().c_str());
}

void CSoundManager::DestroySound(const char* Name)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	SoundMap::iterator soundItr = m_SoundMap.find(Name);
	if(soundItr != m_SoundMap.end())
	{			
		m_SoundsToDestroy.push_back(soundItr->second);
		m_SoundMap.erase(soundItr);
	}
}

void CSoundManager::DestroyAllSounds()
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	// delete all CSound pointers in the SoundMap
	std::for_each(m_SoundMap.begin(), m_SoundMap.end(), DeleteSecond());
	m_SoundMap.clear();
}

void CSoundManager::PauseAllSounds()
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	SoundMap::iterator soundItr;
	for(soundItr = m_SoundMap.begin(); soundItr != m_SoundMap.end(); soundItr++)
	{
		if(soundItr->second->IsPlaying())
		{
			soundItr->second->Pause();
			m_PauseResumeAll.push_back(soundItr->second);
		}
	}
}

void CSoundManager::ResumeAllSounds()
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	SoundList::iterator soundItr;
	for(soundItr = m_PauseResumeAll.begin(); soundItr != m_PauseResumeAll.end(); soundItr++)
	{
		(*soundItr)->Play();
	}
	m_PauseResumeAll.clear();
} 

void CSoundManager::CreateListener()
{
	CListener *listener = CListener::Instance();
	if(!listener)
	{
		listener = static_cast<CListener*>
			(m_ListenerFactory->createInstance("ListenerSingleton", nullptr));
	}
}

CListener* CSoundManager::GetListener() const
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	return CListener::Instance();
}

struct CSoundManager::UpdateSound
{
	void operator()(std::pair<std::string, CSound*> pair)const
	{
		pair.second->UpdateSound();
	}
};

struct CSoundManager::SortLowToHigh
{
	bool operator()(const CSound *sound1, const CSound *sound2)const
	{
		// First we see if either sound has stopped and not given up its source
		if(sound1->IsStopped() && !sound2->IsStopped())
			return true;
		else if(sound2->IsStopped() && !sound1->IsStopped())
			return false;
		else if(sound1->IsStopped() && sound2->IsStopped())
			return sound1 < sound2;

		// If they are both playing we'll test priority
		if(sound1->GetPriority() < sound2->GetPriority())
			return true;
		else if (sound1->GetPriority() > sound2->GetPriority())
			return false;

		// If they are the same priority we'll test against the
		// distance from the listener
		f32 distSound1, distSound2;
		Vector3 listenerPos = CListener::Instance()->GetDerivedPosition();
		if(sound1->IsRelativeToListener())
		{
			distSound1 = sound1->GetPosition().length();
		}
		else
		{
			distSound1 = sound1->GetDerivedPosition().distance(listenerPos);
		}

		if(sound2->IsRelativeToListener())
		{
			distSound2 = sound1->GetPosition().length();
		}
		else
		{
			distSound2 = sound2->GetDerivedPosition().distance(listenerPos);
		}

		if(distSound1 > distSound2)
			return true;
		else if(distSound1 < distSound2)
			return false;

		// If they are at the same priority and distance from the listener then
		// they are both equally well suited to being sacrificed so we compare
		// their pointers since it really doesn't matter
		return sound1 < sound2;
	}
};

struct CSoundManager::SortHighToLow
{
	bool operator()(const CSound *sound1, const CSound *sound2)const
	{
		// First we'll test priority
		if(sound1->GetPriority() > sound2->GetPriority())
			return true;
		else if (sound1->GetPriority() < sound2->GetPriority())
			return false;

		// If they are the same priority we'll test against the
		// distance from the listener
		f32 distSound1, distSound2;
		Vector3 listenerPos = CListener::Instance()->GetDerivedPosition();
		if(sound1->IsRelativeToListener())
		{
			distSound1 = sound1->GetPosition().length();
		}
		else
		{
			distSound1 = sound1->GetDerivedPosition().distance(listenerPos);
		}

		if(sound2->IsRelativeToListener())
		{
			distSound2 = sound1->GetPosition().length();
		}
		else
		{
			distSound2 = sound2->GetDerivedPosition().distance(listenerPos);
		}

		if(distSound1 < distSound2)
			return true;
		else if(distSound1 > distSound2)
			return false;

		// If they are at the same priority and distance from the listener then
		// they are both equally well suited to stealing a source so we compare
		// their pointers since it really doesn't matter
		return sound1 < sound2;
	}
};

bool CSoundManager::frameStarted(const Ogre::FrameEvent& evt)
{
	// Do this before any fading Gets updated
	m_LastDeltaTime = evt.timeSinceLastFrame;

	// Destroy any sounds that were queued last frame
	SoundList::iterator soundItr = m_SoundsToDestroy.begin();
	while(!m_SoundsToDestroy.empty())
	{
		delete (*soundItr);
		soundItr = m_SoundsToDestroy.erase(soundItr);
	}

	UpdateSounds();
	return true;
}

void CSoundManager::SetDopplerFactor(f32 dopplerFactor)
{
	// Negative values are invalid
	if(dopplerFactor < 0) return;

	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	m_DopplerFactor = dopplerFactor;
	alDopplerFactor(m_DopplerFactor);
	CheckError(alGetError(), "Failed to Set Doppler Factor");
}

void CSoundManager::SetSpeedOfSound(f32 speedOfSound)
{
	// Negative values are invalid
	if(speedOfSound < 0) return;

	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	m_SpeedOfSound = speedOfSound;
	alSpeedOfSound(m_SpeedOfSound);
	CheckError(alGetError(), "Failed to Set Speed of CSound");
}

void CSoundManager::GetDeviceList(Vector<String>& list)
{
	const ALCchar* deviceList = alcGetString(nullptr, ALC_DEVICE_SPECIFIER);

	/*
	** The list returned by the call to alcGetString has the names of the
	** devices seperated by nullptr characters and the list is terminated by
	** two nullptr characters, so we can cast the list into a string and it
	** will automatically stop at the first nullptr that it sees, then we
	** can move the pointer ahead by the lenght of that string + 1 and we
	** will be at the begining of the next string.  Once we hit an empty 
	** string we know that we've found the double nullptr that terminates the
	** list and we can stop there.
	*/
	while(*deviceList != '\0')
	{
		try
		{
			ALCdevice *device = alcOpenDevice(deviceList);

			if(device)
			{
			  CheckError(alcGetError(device), "Unable to open device");

				// Device seems to be valid
				ALCcontext *context = alcCreateContext(device, nullptr);
				CheckError(alcGetError(device), "Unable to create context");
				if(context)
				{
					// Context seems to be valid
					alcMakeContextCurrent(context);
					CheckError(alcGetError(device), "Unable to make context current");
					list.push_back(alcGetString(device, ALC_DEVICE_SPECIFIER));
					alcMakeContextCurrent(nullptr);
					CheckError(alcGetError(device), "Unable to clear current context");
					alcDestroyContext(context);
					CheckError(alcGetError(device), "Unable to destroy context");
				}
				alcCloseDevice(device);
			}else{
			  // There is a chance that because the device could not be
			  // opened, the error flag was Set, clear it.
			  alcGetError(device);
			}
		}
		catch(...)
		{
			// Don't die here, we'll just skip this device.
		}

		deviceList += strlen(deviceList) + 1;
	}
}

FormatMapIterator CSoundManager::GetSupportedFormatIterator()
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	return FormatMapIterator(m_SupportedFormats.begin(), m_SupportedFormats.end());
}

const CFormatData* CSoundManager::RetrieveFormatData(AudioFormat format) const
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	FormatMap::const_iterator itr = m_SupportedFormats.find(format);
	if(itr != m_SupportedFormats.end())
		return itr->second;
	else
		return 0;
}

ALboolean CSoundManager::EaxSetBufferMode(Size numBuffers, BufferRef *buffers, EAXMode bufferMode)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	CORE_LOG(" === Setting X-RAM Buffer Mode");
	if(bufferMode == xRamHardware)
	{
		ALint size;
		alGetBufferi(*buffers, AL_SIZE, &size);
		// If the buffer won't fit in xram, return false
		if(m_XRamSize < (m_XRamFree + size)) return AL_FALSE;

		String msg = " === Allocating " + Ogre::StringConverter::toString(size) + " bytes of X-RAM";
		CORE_LOG(msg.c_str());
	}
	// Try Setting the buffer mode, if it fails return false
	if(m_SetXRamMode(numBuffers, buffers, bufferMode) == AL_FALSE) return AL_FALSE;

	m_XRamFree = alGetEnumValue("AL_EAX_RAM_FREE");
	return AL_TRUE;
}

ALenum CSoundManager::EaxGetBufferMode(BufferRef buffer, ALint *reserved)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	return m_GetXRamMode(buffer, reserved);
}

void CSoundManager::_RemoveBufferRef(const String& bufferName)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	m_SoundFactory->_RemoveBufferRef(bufferName);
}

void CSoundManager::_AddBufferRef(const String& bufferName, BufferRef buffer)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	m_SoundFactory->_AddBufferRef(bufferName, buffer);
}

SourceRef CSoundManager::_RequestSource(CSound *sound)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	if(sound->GetSource() != AL_NONE)
	{
		// This sound already has a source, so we'll just return the same one
		return sound->GetSource();
	}

	SoundList::iterator soundItr;
	for(soundItr = m_QueuedSounds.begin(); soundItr != m_QueuedSounds.end(); soundItr++)
	{
		if((*soundItr) == sound)
		{
			// This sound has already requested a source
			return AL_NONE;
			break;
		}
	}

	if(!m_SourcePool.empty())
	{
		m_ActiveSounds.push_back(sound);
		SourceRef source = m_SourcePool.front();
		m_SourcePool.pop();
		return source;
	}
	else
	{
		if(m_ActiveSounds.size() > 0)
		{
			CSound *activeSound = m_ActiveSounds.front();
			Vector3 listenerPos = CListener::Instance()->GetDerivedPosition();
			f32 distSound = sound->GetDerivedPosition().distance(listenerPos);
			f32 distActiveSound = activeSound->GetDerivedPosition().distance(listenerPos);

			if(sound->GetPriority() > activeSound->GetPriority() ||
				sound->GetPriority() == activeSound->GetPriority() && distSound < distActiveSound)
			{
				activeSound->Pause();
				SourceRef source = activeSound->GetSource();
				m_ActiveSounds.erase(m_ActiveSounds.begin());
				m_QueuedSounds.push_back(activeSound);

				m_ActiveSounds.push_back(sound);
				return source;
			}
			else
			{
				m_QueuedSounds.push_back(sound);
				return AL_NONE;
			}
		}
		else
		{
			CORE_ERR("No active sounds in  CSoundManager::_RequestSource");
		}
	}
	return AL_NONE;
}

SourceRef CSoundManager::_ReleaseSource(CSound *sound)
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	bool soundFound = false;
	SoundList::iterator soundItr;
	for(soundItr = m_ActiveSounds.begin(); soundItr != m_ActiveSounds.end(); soundItr++)
	{
		if((*soundItr) == sound)
		{
			m_ActiveSounds.erase(soundItr);
			soundFound = true;
			break;
		}
	}

	// If it's not in the active list, check the queued list
	if(!soundFound)
	{
		for(soundItr = m_QueuedSounds.begin(); soundItr != m_QueuedSounds.end(); soundItr++)
		{
			if((*soundItr) == sound)
			{
				m_QueuedSounds.erase(soundItr);
				break;
			}
		}
	}

	SourceRef source = sound->GetSource();
	if(source != AL_NONE)
	{
		if(!m_QueuedSounds.empty())
		{
			CSound *queuedSound = m_QueuedSounds.front();
			m_QueuedSounds.erase(m_QueuedSounds.begin());

			queuedSound->SetSource(source);
			queuedSound->Play();
			m_ActiveSounds.push_back(queuedSound);
		}
		else
		{
			m_SourcePool.push(source);
		}
	}

	return AL_NONE;
}

int CSoundManager::CreateSourcePool()
{
	SourceRef source;

	int numSources = 0;
	while(alGetError() == AL_NO_ERROR && numSources < 100)
	{
		source = 0;
		alGenSources(1, &source);
		if(source != 0)
		{
			m_SourcePool.push(source);
			numSources++;
		}
		else
		{
			// Clear out the error
			alGetError();
			break;
		}
	}

	return numSources;
}

void CSoundManager::InitializeDevice()
{
	// TODO: make deviceName data driven
	const String& deviceName = "";

	alcGetIntegerv(nullptr, ALC_MAJOR_VERSION, sizeof(m_MajorVersion), &m_MajorVersion);
	CheckError(alcGetError(nullptr), "Failed to retrieve version info");
	alcGetIntegerv(nullptr, ALC_MINOR_VERSION, sizeof(m_MinorVersion), &m_MinorVersion);
	CheckError(alcGetError(nullptr), "Failed to retrieve version info");
	
	String msg = "OpenAL Version: " + Ogre::StringConverter::toString(m_MajorVersion) + "." + Ogre::StringConverter::toString(m_MinorVersion);
	CORE_LOG(msg.c_str());

	/*
	** OpenAL versions prior to 1.0 DO NOT support device enumeration, so we
	** need to test the current version and decide if we should try to find 
	** an appropriate device or if we should just open the default device.
	*/
	bool deviceInList = false;
	if(m_MajorVersion >= 1 && m_MinorVersion >= 1)
	{
		CORE_LOG("Available Devices");
		CORE_LOG("-----------------");

		// List devices in log and see if the sugested device is in the list
		std::vector<String> deviceList;
		GetDeviceList(deviceList);

		std::stringstream ss;
		for(auto it = deviceList.begin(); it != deviceList.end() && (*it).compare("") != 0; it++)
		{
			deviceInList = (*it).compare(deviceName) == 0;
			ss << " * " << (*it);
			CORE_LOG(ss.str().c_str());
			ss.clear(); ss.str("");
		}
	}

	// If the suggested device is in the list we use it, otherwise select the default device
	m_Device = alcOpenDevice(deviceInList ? deviceName.c_str() : nullptr);	
	CheckError(alcGetError(m_Device), "Failed to open Device");
	CheckCondition(m_Device != nullptr, 13, "Failed to open audio device");

	msg = "Choosing: " + String(alcGetString(m_Device, ALC_DEVICE_SPECIFIER));
	CORE_LOG(msg.c_str());

	// Create OpenAL Context
	if(m_Device)
	{
		m_Context = alcCreateContext(m_Device, nullptr);
		CheckError(alcGetError(m_Device), "Failed to create Context");
		CheckCondition(m_Context != nullptr, 13, "Failed to create OpenAL Context");

		alcMakeContextCurrent(m_Context);
		CheckError(alcGetError(m_Device), "Failed to Set current context");
	}
}

void CSoundManager::CheckFeatureSupport()
{
	// Check for Supported Formats
	ALenum eBufferFormat = 0;
	eBufferFormat = alcGetEnumValue(m_Device, "AL_FORMAT_MONO16");
	if(eBufferFormat) m_SupportedFormats[MONO_CHANNEL] = 
		new CFormatData(eBufferFormat, "AL_FORMAT_MONO16", "Monophonic CSound");
	eBufferFormat = alcGetEnumValue(m_Device, "AL_FORMAT_STEREO16");
	if(eBufferFormat) m_SupportedFormats[STEREO_CHANNEL] = 
		new CFormatData(eBufferFormat, "AL_FORMAT_STEREO16", "Stereo CSound");
	eBufferFormat = alcGetEnumValue(m_Device, "AL_FORMAT_QUAD16");
	if(eBufferFormat) m_SupportedFormats[QUAD_CHANNEL] = 
		new CFormatData(eBufferFormat, "AL_FORMAT_QUAD16", "4 Channel CSound");
	eBufferFormat = alcGetEnumValue(m_Device, "AL_FORMAT_51CHN16");
	if(eBufferFormat) m_SupportedFormats[MULTI_CHANNEL_51] = 
		new CFormatData(eBufferFormat, "AL_FORMAT_51CHN16", "5.1 Surround CSound");
	eBufferFormat = alcGetEnumValue(m_Device, "AL_FORMAT_61CHN16");
	if(eBufferFormat) m_SupportedFormats[MULTI_CHANNEL_61] = 
		new CFormatData(eBufferFormat, "AL_FORMAT_61CHN16", "6.1 Surround CSound");
	eBufferFormat = alcGetEnumValue(m_Device, "AL_FORMAT_71CHN16");
	if(eBufferFormat) m_SupportedFormats[MULTI_CHANNEL_71] = 
		new CFormatData(eBufferFormat, "AL_FORMAT_71CHN16", "7.1 Surround CSound");

	// Log supported formats
	FormatMapIterator itr = GetSupportedFormatIterator();
	CORE_LOG("Supported Formats");
	CORE_LOG("-----------------");
	String msg;
	while(itr.hasMoreElements())
	{
		msg = " * " + std::string(static_cast<char*>(itr.peekNextValue()->formatName)) + ", " + itr.peekNextValue()->formatDescription;
		CORE_LOG(msg.c_str());
		itr.getNext();
	}

	// Check for EAX Support
	std::stringbuf versionString;
	for(int version = 5; version >= 2; version--)
	{
		versionString.str("EAX"+Ogre::StringConverter::toString(version)+".0");
		if(alIsExtensionPresent(versionString.str().data()) == AL_TRUE)
		{
			m_EAXSupport = true;
			m_EAXVersion = version;
			versionString.str("EAX " + Ogre::StringConverter::toString(version) + ".0 Detected");
			CORE_LOG(versionString.str().c_str());
			break;
		}
	}

	// Check for EFX Support
	if(alcIsExtensionPresent(m_Device, "ALC_EXT_EFX") == AL_TRUE)
	{
		CORE_LOG("EFX Extension Found");
	}

	// Check for X-RAM extension
	if(alIsExtensionPresent("EAX-RAM") == AL_TRUE)
	{
		m_XRAMSupport = true;
		CORE_LOG("X-RAM Detected");

		EAXSetBufferMode SetXRamMode = (EAXSetBufferMode)alGetProcAddress("EAXSetBufferMode");
		EAXGetBufferMode GetXRamMode = (EAXGetBufferMode)alGetProcAddress("EAXGetBufferMode");
		m_XRamSize = alGetEnumValue("AL_EAX_RAM_SIZE");
		m_XRamFree = alGetEnumValue("AL_EAX_RAM_FREE");
		
		String msg = "X-RAM: " + Ogre::StringConverter::toString(m_XRamSize) + " (" + Ogre::StringConverter::toString(m_XRamFree) + " free)";
		CORE_LOG(msg.c_str());
	}

	// Create our pool of sources
	m_MaxNumSources = CreateSourcePool();
}

void CSoundManager::UpdateSounds()
{
	// Lock Mutex
	SOUNDENGINE_LOCK_AUTO_MUTEX

	// Update the CSound and Listeners if necessary	
	std::for_each(m_SoundMap.begin(), m_SoundMap.end(), UpdateSound());
	CListener::Instance()->UpdateListener();

	// Sort the active and queued sounds
	std::sort(m_ActiveSounds.begin(), m_ActiveSounds.end(), SortLowToHigh());
	std::sort(m_QueuedSounds.begin(), m_QueuedSounds.end(), SortHighToLow());

	// Check to see if we should sacrifice any sounds
	UpdateSourceAllocations();
}

void CSoundManager::UpdateSourceAllocations()
{
	while(!m_QueuedSounds.empty())
	{
		CSound *queuedSound = m_QueuedSounds.front();
		CSound *activeSound = m_ActiveSounds.front();

		f32 distQueuedSound, distActiveSound;
		Vector3 listenerPos = CListener::Instance()->GetDerivedPosition();
		if(queuedSound->IsRelativeToListener())
		{
			distQueuedSound = queuedSound->GetPosition().length();
		}
		else
		{
			distQueuedSound = queuedSound->GetDerivedPosition().distance(listenerPos);
		}

		if(activeSound->IsRelativeToListener())
		{
			distActiveSound = activeSound->GetPosition().length();
		}
		else
		{
			distActiveSound = activeSound->GetDerivedPosition().distance(listenerPos);
		}

		if(queuedSound->GetPriority() > activeSound->GetPriority() ||
			queuedSound->GetPriority() == activeSound->GetPriority() && distQueuedSound < distActiveSound)
		{
			// Remove the sounds from their respective lists
			m_ActiveSounds.erase(m_ActiveSounds.begin());
			m_QueuedSounds.erase(m_QueuedSounds.begin());

			// Steal the source from the currently active sound
			activeSound->Pause();
			activeSound->unqueueBuffers();
			SourceRef source = activeSound->GetSource();
			activeSound->SetSource(AL_NONE);

			// Kickstart the currently queued sound
			queuedSound->SetSource(source);
			queuedSound->Play();

			// Add the sound back to the correct lists
			m_ActiveSounds.push_back(queuedSound);
			m_QueuedSounds.push_back(activeSound);
		}
		else
		{
			// We have no more sounds that we can sacrifice
			break;
		}
	}
}

void CSoundManager::LoadAllSounds(const char* ResourceName)
{
#if defined(SOUND_THREADED)
	String name = ResourceName;
	boost::thread thread1(Sound::CSoundManager::_LoadAllSounds, name);
	//_LoadAllSounds(name);
#else
	String name = ResourceName;
	_LoadAllSounds(ResourceName);
#endif
}

void CSoundManager::_LoadAllSounds(const String& ResourceName)
{
	// Set this to true so we won't interupt this method.
	CSoundManager::Instance()->SetIsBaseSoundsLoading(true);
	if(ResourceGroupManager::getSingleton().resourceGroupExists(ResourceName))
	{
		auto res = Ogre::ResourceGroupManager::getSingleton().listResourceNames(ResourceName);
		//#pragma omp parallel for
		for(auto it = res->cbegin(); it != res->cend(); it++)
		{
			std::cerr << (*it) << std::endl;

			// Check for the "ogg" extension
			if(IO::CFileSystem::GetFileExtension((*it)) == "ogg")
			{
				// Remove the extension
				String name;
				auto index = it->rfind(".", it->size());
				if(index != -1)
					name = it->substr(0, index);
				else
					name = *it;

				transform(name.begin(), name.end(), name.begin(), toupper);

				CSoundManager::Instance()->CreateSound(name, *it);
			}
		}
	}
	else
	{
		String msg = "Invalid resource name for CSoundManager::LoadAllSounds: " + String(ResourceName);
		CORE_ERR(msg.c_str());
	}
	CSoundManager::Instance()->SetIsBaseSoundsLoading(false);
	CSoundManager::Instance()->SetIsBaseSoundsLoaded(true);
}

void CSoundManager::GetSoundList(Vector<String>& list)
{
	for(SoundMap::const_iterator it = m_SoundMap.begin();
		it != m_SoundMap.end();
		it++)
	{
		list.push_back(it->first);
	}
}

#if SOUND_THREADED
static void CSoundManager::threadUpdate()
{
	while(!mShuttingDown)
	{
		CSoundManager::Instance()->UpdateSounds();
		mOgreALThread->yield();
	}
}
#endif

} // Namespace
