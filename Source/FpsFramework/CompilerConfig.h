#ifndef __COMPILER_CONFIG_H__
#define __COMPILER_CONFIG_H__

//#define CORE_DLL 
//#define COMPILE_SCRIPT
//#define COMPILE_CEGUI 
//#define COMPILE_QUICKGUI 
//#define COMPILE_NETWORK
//#define COMPILE_OVERLAYS
//#define COMPILE_EFFECT_FIRE

#if defined( WIN32) || defined(WIN64)
	#pragma warning(disable : 4099)
	#pragma warning(disable : 4217)
	#pragma warning(disable : 4049)

	#ifdef VDL
	#include <vld.h> 
	#endif

	#if defined(COMPILE_NETWORK)
		#if defined(_DEBUG)
			#pragma comment( lib, "RakNetDLLDebug.lib" )
		#else
			#pragma comment( lib, "RakNetDLL.lib" )
		#endif
	#endif
#endif


#endif // __COMPILER_CONFIG_H__