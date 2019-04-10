#ifndef __PLUGIN_INETWORKINGFACTORY_H__
#define __PLUGIN_INETWORKINGFACTORY_H__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	namespace Network
	{
		class INetworkStrategy;
	}

	namespace Plugin
	{
		class INetworkingFactory
		{
		public:
			virtual Core::Network::INetworkStrategy* GetStrategy() = 0;

			String LabelName;
		};
	}
}

#endif // __PLUGIN_INETWORKINGFACTORY_H__