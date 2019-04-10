#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/INetworkingFactory.h"
#include "Factories.h"

#include "CFpsClientStrategy.h"
#include "CChatStrategy.h"

namespace Core
{
namespace Plugin
{
	CNetworkingFactory_FpsClient* networkingFactory_FpsClient = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<INetworkingFactory*>& list)
		{
			networkingFactory_FpsClient = new CNetworkingFactory_FpsClient();
			if(networkingFactory_FpsClient)
				list.push_back(networkingFactory_FpsClient);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_NETWORKING;
		}
	}

}
}