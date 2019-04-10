#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/IPhysicsStrategyFactory.h"
#include "Factories.h"

namespace Core
{
namespace Plugin
{
	extern "C"
	{
		CPhysicsStrategyFactory_Ode* OdeFactory = nullptr;

		DECLDIR void GetFactories(Vector<IPhysicsStrategyFactory*>& list)
		{
			OdeFactory = new CPhysicsStrategyFactory_Ode();
			if(OdeFactory)
				list.push_back(OdeFactory);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_PHYSICSSTRATEGY;
		}
	}

}
}