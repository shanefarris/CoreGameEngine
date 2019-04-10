#ifndef __SOUNDENGINE_PREREQS_H__
#define __SOUNDENGINE_PREREQS_H__

#include "Defines.h"

namespace Sound
{
	#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
	#	include "al.h"
	#	include "alc.h"
	#	include "xram.h"
	#elif OGRE_COMPILER == OGRE_COMPILER_GNUC
	#	include "AL/al.h"
	#	include "AL/alc.h"
	#	if defined(SOUNDENGINE_EXPORT) && OGRE_COMP_VER >= 400
	#		define __attribute__ ((visibility("default")))
	#	else
	#		define OgreAL_Export
	#	endif
		// fake EAX/X-RAM
		typedef ALenum (*EAXGetBufferMode)(ALuint buffer, ALint *pReserved);
		typedef ALboolean (*EAXSetBufferMode)(ALsizei n, ALuint *buffers, ALint value);
	#else // Other Compilers
	#	include "al.h"
	#	include "alc.h"
	#	include "xram.h"
	#	define OgreAL_Export
	#endif

	#ifndef SOUND_THREADED
	#	define SOUND_THREADED 0
	#endif

	#define SOUNDENGINE_AUTO_MUTEX_NAME ogrealMutex
	#if SOUND_THREADED
	#	define SOUNDENGINE_AUTO_MUTEX mutable boost::recursive_mutex SOUNDENGINE_AUTO_MUTEX_NAME;
	#	define SOUNDENGINE_LOCK_AUTO_MUTEX boost::recursive_mutex::scoped_lock ogrealAutoMutexLock(SOUNDENGINE_AUTO_MUTEX_NAME);
	#else
	#	define SOUNDENGINE_AUTO_MUTEX
	#	define SOUNDENGINE_LOCK_AUTO_MUTEX
	#endif

	enum AudioFormat
	{
		DEFAULT,
		MONO_CHANNEL,
		STEREO_CHANNEL,
		QUAD_CHANNEL,
		MULTI_CHANNEL_51,
		MULTI_CHANNEL_61,
		MULTI_CHANNEL_71
	};

	typedef ALenum BufferFormat;
	typedef ALenum State;
	typedef ALenum Error;
	typedef ALuint SourceRef;
	typedef ALuint BufferRef;
	typedef ALuint EAXMode;
	typedef ALsizei Size;
	typedef ALchar* ALString;
	typedef std::vector<char> Buffer;
	typedef std::queue<SourceRef> SourcePool;

	// Struct used with STL containers
	struct DeleteObject
	{
		template<typename T>
		void operator()(const T* ptr)const
		{
			delete ptr;
		}
	};

	// Struct used with STL containers
	struct DeleteFirst
	{
		template<typename T1, typename T2>
		void operator()(std::pair<T1*, T2> pair)const
		{
			delete pair.first;
		}
	};

	// Struct used with STL containers
	struct DeleteSecond
	{
		template<typename T1, typename T2>
		void operator()(std::pair<T1, T2*> pair)const
		{
			delete pair.second;
		}
	};
}

#endif
