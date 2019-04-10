#define DLL_EXPORT

#include "Factories.h"
#include "CFpsClientStrategy.h"

using namespace Core::Plugin;

// CNetworkingFactory_FpsClient
CNetworkingFactory_FpsClient::CNetworkingFactory_FpsClient()
{
	LabelName = "FPS";
}

Core::Network::INetworkStrategy* CNetworkingFactory_FpsClient::GetStrategy()
{
	return new CFpsClientStrategy();
}
