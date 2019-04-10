#include "CSoundFactory.h"
#include "CSound.h"
#include "COggSound.h"
#include "CWavSound.h"
#include "CSoundManager.h"
#include "SoundEngineException.h"

#include "OgreStringConverter.h"
#include "OgreResourceGroupManager.h"

namespace Sound 
{
	String CSoundFactory::FACTORY_TYPE_NAME = "OgreAL_Sound";

	CSoundFactory::CSoundFactory()
	{
	}

	CSoundFactory::~CSoundFactory()
	{
		BufferMap::iterator bufferItr = m_BufferMap.begin();
		while(bufferItr != m_BufferMap.end())
		{
			alDeleteBuffers(1, &bufferItr->second);
			bufferItr++;
		}

		m_BufferMap.clear();
	}

	const String& CSoundFactory::getType(void) const
	{
		return FACTORY_TYPE_NAME;
	}

	Ogre::MovableObject* CSoundFactory::createInstanceImpl(const String& name, const Ogre::NameValuePairList* params)
	{
		String fileName = params->find(CSoundManager::SOUND_FILE)->second;
		bool loop = Ogre::StringConverter::parseBool(params->find(CSoundManager::LOOP_STATE)->second);
		bool stream = Ogre::StringConverter::parseBool(params->find(CSoundManager::STREAM)->second);
		
		// Check to see if we can just piggy back another buffer
		if(!stream)
		{
			BufferMap::iterator bufferItr = m_BufferMap.find(fileName);
			if(bufferItr != m_BufferMap.end())
			{
				// We have this buffer loaded already!
				return new CSound((BufferRef)bufferItr->second, name, fileName, loop);
			}
		}

		Ogre::ResourceGroupManager *groupManager = Ogre::ResourceGroupManager::getSingletonPtr();
		String group = groupManager->findGroupContainingResource(fileName);
		Ogre::DataStreamPtr soundData = groupManager->openResource(fileName, group);

		CSound *sound = nullptr;
		if(fileName.find(".ogg") != std::string::npos || fileName.find(".OGG") != std::string::npos)
		{
			sound = new COggSound(name, soundData, loop, stream);			
		}
		else if(fileName.find(".wav") != std::string::npos || fileName.find(".WAV") != std::string::npos)
		{
			//sound = new CWavSound(name, soundData, loop, stream);
		}
		else
		{
			throw Ogre::Exception(Ogre::Exception::ERR_INVALIDPARAMS,
				"CSound file '" + fileName + "' is of an unsupported file type, ",
				"CSound::CSoundManager::_createSound");
		}

		if(!stream)
		{
			// Save the reference to this buffer so we can point to it again later
			m_BufferMap[fileName] = sound->GetBufferRef();
		}
		return sound;
	}

	void CSoundFactory::destroyInstance(Ogre::MovableObject* obj)
	{
		delete obj;
	}

	void CSoundFactory::_RemoveBufferRef(const String& bufferName)
	{
		BufferMap::iterator bufferItr = m_BufferMap.find(bufferName);
		if(bufferItr != m_BufferMap.end())
		{
			m_BufferMap.erase(bufferItr);
		}
	}

	void CSoundFactory::_AddBufferRef(const String& bufferName, BufferRef buffer)
	{
		BufferMap::const_iterator bufferItr = m_BufferMap.find(bufferName);
		CheckCondition(bufferItr != m_BufferMap.end(), 13, "Buffer named " + bufferName + " already exists!");

		CheckCondition(alIsBuffer(buffer) == AL_TRUE, 13, "Not a valid BufferRef");
		CheckError(alGetError(), "Failed to check buffer");

		m_BufferMap[bufferName] = buffer;
	}
}