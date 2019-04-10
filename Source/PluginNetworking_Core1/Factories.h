#ifndef __CNETWORKING_FACTORIES_H__
#define __CNETWORKING_FACTORIES_H__

#if defined(_WIN32)
#include "RakNet/WindowsIncludes.h"
#endif

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/INetworkingFactory.h"

namespace Core
{
	namespace Plugin
	{
		class CNetworkingFactory_FpsClient : public Core::Plugin::INetworkingFactory
		{
		public:
			CNetworkingFactory_FpsClient();
			~CNetworkingFactory_FpsClient() { }

			Core::Network::INetworkStrategy* GetStrategy();
		};

	}
}

#endif // __CNETWORKING_FACTORIES_H__