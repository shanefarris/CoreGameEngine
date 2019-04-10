#ifndef __CCAMERA_FACTORIES_H__
#define __CCAMERA_FACTORIES_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/ICameraFactory.h"
#include "ICamera.h"

namespace Core
{
	namespace Plugin
	{
		class CCameraFactory_Fixed : public Core::Plugin::ICameraFactory
		{
		public:
			CCameraFactory_Fixed();
			~CCameraFactory_Fixed();

			Core::ICamera* GetCamera(const char* Name);
		};

		class CCameraFactory_RTS : public Core::Plugin::ICameraFactory
		{
		public:
			CCameraFactory_RTS();
			~CCameraFactory_RTS();

			Core::ICamera* GetCamera(const char* Name);
		};

		class CCameraFactory_Free : public Core::Plugin::ICameraFactory
		{
		public:
			CCameraFactory_Free();
			~CCameraFactory_Free();

			Core::ICamera* GetCamera(const char* Name);
		};

		class CCameraFactory_ChaseSpaceShip : public Core::Plugin::ICameraFactory
		{
		public:
			CCameraFactory_ChaseSpaceShip();
			~CCameraFactory_ChaseSpaceShip();

			Core::ICamera* GetCamera(const char* Name);
		};
	}
}

#endif // __CCAMERA_FACTORIES_H__