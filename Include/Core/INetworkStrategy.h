#if defined(COMPILE_NETWORK)

#ifndef __INETWORKSTRATEGY_H__
#define __INETWORKSTRATEGY_H__

#include "RakNet/WindowsIncludes.h"
#include "Defines.h"

namespace RakNet
{
	struct Packet;
}

namespace Core
{
namespace Network
{
	class CORE_EXPORT INetworkStrategy
	{
	public:
		virtual ~INetworkStrategy() { }

		virtual void Update(RakNet::Packet* Packet) = 0;

	};

}
}

#endif // __INETWORKSTRATEGY_H__

#endif