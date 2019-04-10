#ifndef __PLUGIN_IPHYSCYSSTRATEGYFACTORY_H__
#define __PLUGIN_IPHYSCYSSTRATEGYFACTORY_H__

#include "Defines.h"
#include "CoreStructures.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	namespace Physics
	{
		class IPhysicsStrategy;
	}

	namespace Plugin
	{
		class IPhysicsStrategyFactory
		{
		public:
			virtual Core::Physics::IPhysicsStrategy* GetStrategy() = 0;

			String Label;

		};
	}
}

#endif // __PLUGIN_IPHYSCYSSTRATEGYFACTORY_H__