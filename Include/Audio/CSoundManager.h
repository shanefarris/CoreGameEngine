#ifndef __SOUND_MANAGER_H__
#define __SOUND_MANAGER_H__

#include "Defines.h"

#include "SoundEnginePrereqs.h"
#include "CSound.h"
#include "OgreFrameListener.h"

#if SOUND_THREADED
#	include <boost/thread/thread.hpp>
#	include <boost/thread/recursive_mutex.hpp>
#	include <boost/thread/xtime.hpp>
#endif

namespace Sound 
{
	class CListener;
	class ListenerFactory;

	/*
	 * CFormatData.
	 * @remark This is a storage class to hold data about different
	 * OpenAL buffer formats.
	 */
	class CFormatData
	{
	public:
		CFormatData(BufferFormat alEnum, ALString alChar, const String& description)
		{
			formatEnum = alEnum;
			formatName = alChar;
			formatDescription = description;
		}
		// OpenAL buffer type
		BufferFormat formatEnum;
		// OpenAL buffer type name
		ALString formatName;
		// Buffer type description
		String formatDescription;
	};

	typedef Map<String, CSound*>			SoundMap;
	typedef Vector<CSound*>					SoundList;
	typedef Map<AudioFormat, CFormatData*>	FormatMap;
	typedef Ogre::MapIterator<FormatMap>	FormatMapIterator;

	/*
	 * CSoundManager.
	 * @remark This class is responsible for creating and managing all of the
	 *     sounds and listeners used in the application.  Sounds  and Listeners
	 *	   should only ever be created using the creation methods provided in this class
	 */
	class CORE_EXPORT CSoundManager : public Ogre::FrameListener
	{
	public:
		static CSoundManager* Instance();
		~CSoundManager();

		/*
		 * Creates a sound.  This is the only way sounds should be instantiated
		 * @param name The name used to refer to the sound
		 * @param fileName The name of the sound file to load
		 * @param loop Should the sound be looped once it has finished playing
		 * @param stream Should the sound be streamed or should the whole file be loaded into memory at once
		 * @return Returns a pointer to the newly created sound
		 */
		CSound* CreateSound(const String& fileName, bool loop = false, bool stream = false);
		CSound* CreateSound(const String& name, const String& fileName, bool loop = false, bool stream = false);

		CSound* GetSound(const char* Name) const;		// Returns the requested sound object. @param name The name of the sound to return 
		bool HasSound(const char* Name) const;			// Returns true if the specified sound is loaded in the CSoundManager. @param name The name of the sound to check for
		void DestroySound(const char* Name);			// Destroys the specified sound. @param name The name of the sound to destroy 
		void DestroySound(CSound* sound);				// Destroys the specified sound. @param sound A pointer to the sound to destroy 
		void DestroyAllSounds();						// Destroys all sounds loaded in the CSoundManager 
		void PauseAllSounds();							// Pauses all sounds that are currently playing. 
		void ResumeAllSounds();							// Resumes all sounds that were paused with the previous call to PauseAllSounds().
		CListener* GetListener() const;					// This is how you should Get a pointer to the listener object.
		/*
		 * Sets the Doppler factor.
		 * The Doppler factor is a simple scaling factor of the source and listener
		 * velocities to exaggerate or deemphasize the Doppler (pitch) shift resulting
		 * from the Doppler Effect Calculations.
		 * @note Negative values will be ignored.
		 */
		void SetDopplerFactor(f32 dopplerFactor);
		f32 GetDopplerFactor() const { return m_DopplerFactor; }		// Returns the Doppler factor

		/* 
		 * Sets the speed of sound used in the Doppler calculations.
		 * This Sets the propagation speed used in the Doppler calculations.
		 * The default is 343.3 m/s (Speed of sound through air), but the
		 * units can be assigned to anything that you want as long as the
		 * velocities of the Sounds and CListener are expressed in the same units.
		 * @note Negative values will be ignored.
		 */
		void	SetSpeedOfSound(f32 speedOfSound);
		f32		GetSpeedOfSound() const { return m_SpeedOfSound; }			// Returns the speed of sound 
		int		MaxSources() const { return m_MaxNumSources; }				// Returns the maximum number of sources allowed by the hardware
		int		EaxSupport() const { return m_EAXVersion; }					// Returns the version of EAX that is supported
		bool	XRamSupport() const { return m_XRAMSupport; }				// Returns true if X-Ram is supported, otherwise false 
		void	_RemoveBufferRef(const String& bufferName);					// Removes a BufferRef from the BufferMap
		void	_AddBufferRef(const String& bufferName, BufferRef buffer);	// Adds a BufferRef to the BufferMap to be used later
		f32		_GetLastDeltaTime() const { return m_LastDeltaTime; }		// Used by the fading: returns the time since last frame
		void	LoadAllSounds(const char* ResourceName);					// Load all sounds in the resource manager
		void	GetDeviceList(Vector<String>& list);						// Returns a list of all posible sound devices on the system
		void	GetSoundList(Vector<String>& list);							// Returns a list of all sounds loaded

		// Used to see if our threaded load method is done
		void	SetIsBaseSoundsLoaded(bool isLoaded) { m_IsBaseSoundsLoaded = isLoaded; }
		bool	GetIsBaseSoundsLoaded() { return m_IsBaseSoundsLoaded; }
		void	SetIsBaseSoundsLoading(bool isLoading) { m_IsBaseSoundsLoading = isLoading; }
		bool	GetIsBaseSoundsLoading() { return m_IsBaseSoundsLoading; }

		SourceRef	_RequestSource(CSound *sound);							// Requests a dynamically allocated Source
		SourceRef	_ReleaseSource(CSound *sound);							// Releases a dynamically allocated Source
		ALboolean	EaxSetBufferMode(Size numBuffers, BufferRef *buffers, EAXMode bufferMode);// Sets the mode to be used by sound buffers if X-Ram is supported
		ALenum		EaxGetBufferMode(BufferRef buffer, ALint *reserved = 0);// Returns the eaxBufferMode if X-Ram is supported
		FormatMapIterator GetSupportedFormatIterator();						// Returns an iterator for the list of supported buffer formats 
		const CFormatData* RetrieveFormatData(AudioFormat format) const;	// Contains information for the specified buffer format or nullptr if the specified format is not found

		static const String FILE_TYPE;
		static const String OGG;
		static const String WAV;
		static const String SOUND_FILE;
		static const String LOOP_STATE;
		static const String STREAM;
		static const String AUDIO_FORMAT;

		static const BufferFormat xRamAuto;
		static const BufferFormat xRamHardware;
		static const BufferFormat xRamAccessible;

	protected:
		CSoundManager();

		bool frameStarted(const Ogre::FrameEvent& evt);
		const String errorToString(int code) const;						// Translate the OpenAL error code to a string
		
		CSoundFactory*		m_SoundFactory;
		ListenerFactory*	m_ListenerFactory;

		bool	m_EAXSupport;
		int		m_EAXVersion;
		bool	m_XRAMSupport;
		bool	m_EFXSupport;
		int		m_SendsPerSource;
		f32		m_DopplerFactor;
		f32		m_SpeedOfSound;

	private:
		static CSoundManager* SoundManager;

		int CreateSourcePool();
		void CreateListener();
		void InitializeDevice();
		void CheckFeatureSupport();
		void UpdateSounds();
		void UpdateSourceAllocations();
		static void _LoadAllSounds(const String& ResourceName);

		struct UpdateSound;
		struct SortLowToHigh;
		struct SortHighToLow;

		int m_MaxNumSources;
		FormatMap m_SupportedFormats;

		int m_MajorVersion;
		int m_MinorVersion;

		SoundMap  m_SoundMap;
		SoundList m_PauseResumeAll;
		SoundList m_SoundsToDestroy;

		SourcePool m_SourcePool;
		SoundList m_ActiveSounds;
		SoundList m_QueuedSounds;

		ALCcontext* m_Context;
		ALCdevice* m_Device;

		f32 m_LastDeltaTime;

		// Base resource sounds load on a separate thread
		bool m_IsBaseSoundsLoaded;
		bool m_IsBaseSoundsLoading;

		// Mutex so we can protect against corruption
		SOUNDENGINE_AUTO_MUTEX

		#if SOUND_THREADED
			static boost::thread *mOgreALThread;
			static bool mShuttingDown;

			static void threadUpdate();
		#endif

		// XRAM Funtions Pointers
		Size m_XRamSize;
		Size m_XRamFree;

		EAXSetBufferMode m_SetXRamMode;
		EAXGetBufferMode m_GetXRamMode;
	};

} // Namespace

#endif
