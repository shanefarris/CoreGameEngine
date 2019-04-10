#ifndef __CPHYSICSSTRATEGY_FACTORIES_H__
#define __CPHYSICSSTRATEGY_FACTORIES_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/IPhysicsStrategyFactory.h"
#include "ICamera.h"

namespace Core
{
	namespace Plugin
	{
		class CPhysicsStrategyFactory_Ode : public Core::Plugin::IPhysicsStrategyFactory
		{
		public:
			CPhysicsStrategyFactory_Ode();
			~CPhysicsStrategyFactory_Ode();

			Core::Physics::IPhysicsStrategy* GetStrategy();
		};
	}
}

#endif // __CPHYSICSSTRATEGY_FACTORIES_H__