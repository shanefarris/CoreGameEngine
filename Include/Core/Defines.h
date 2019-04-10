#ifndef __DEFINES_H__
#define __DEFINES_H__

// Need to have this here, for forward declared, it will throw a redefinition compile error.
#include "OgreString.h"

using namespace Ogre;

// Types
#define EngineDevice	Ogre::Root
#define Vector			std::vector
#define Map				std::map

// Primitives
typedef unsigned char	u8; 
typedef signed char		s8; 
typedef char			c8; 
typedef unsigned short	u16;
typedef signed short	s16; 
typedef unsigned int	u32;
typedef signed int		s32;
typedef unsigned long   ul32;
typedef float			f32; 

#ifdef CORE_DLL
	#ifdef _DEBUG
		// Used for unit testing on classes that are not normally exported
		#define CORE_DEBUG_EXPORT __declspec(dllexport)
	#else
		#define CORE_DEBUG_EXPORT
	#endif
	#define CORE_EXPORT __declspec(dllexport)
#else
	#ifdef _DEBUG
		#define CORE_DEBUG_EXPORT __declspec(dllimport)
	#else
		#define CORE_DEBUG_EXPORT
	#endif
	#define CORE_EXPORT __declspec(dllimport)
#endif

// Define the version code
#define CORE_VERSION_MAJOR 1
#define CORE_VERSION_MINOR 0
#define CORE_VERSION_PATCH 0
#define CORE_VERSION = (CORE_VERSION_MAJOR << 16) | (CORE_VERSION_MINOR << 8) | CORE_VERSION_PATCH
#define CORE_VERSION_CODENAME "Buck Futter"

// Number of teams in a game
#define NUM_TEAMS 4

// Invalid 3d vector position
#define INVALID_POS Vector3(-99999, -99999, -99999)

// Default physics profile sizes
#define DEFAULT_PROFILE_RADIUS  -1
#define DEFAULT_PROFILE_SIZE	Vector3(-1, -1, -1)

// Deleting
#ifndef CORE_DELETE
	#define CORE_DELETE(x) { delete x; x = nullptr; }
#endif

// Macro to surpress warning that parameters aren't used.
#define UNUSED_PARAMETER(expr) (void)expr

// Exception
#ifndef CORE_THROW
#define CORE_THROW(desc, src) throw Ogre::ExceptionFactory::create( \
	Ogre::ExceptionCodeType<Ogre::Exception::ERR_INTERNAL_ERROR>(), desc, src, __FILE__, __LINE__ );
#endif

#endif // __DEFINES_H__
