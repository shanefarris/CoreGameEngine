#ifndef __PLUGIN_ICAMERAFACTORY_H__
#define __PLUGIN_ICAMERAFACTORY_H__

#include "Defines.h"
#include "CoreStructures.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	class ICamera;

	namespace Plugin
	{
		class ICameraFactory
		{
		public:
			virtual Core::ICamera* GetCamera(const char* Name) = 0;

			E_CAMERA_MODE Type;
		};
	}
}

#endif // __PLUGIN_ICAMERAFACTORY_H__