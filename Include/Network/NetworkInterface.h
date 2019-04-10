#ifndef NETWORK_INTERFACE_H
#define NETWORK_INTERFACE_H

#include "RakNet/WindowsIncludes.h"
#include "Defines.h"

namespace RakNet
{
	class RakPeerInterface;
}

namespace Core
{
namespace Network
{
	class NetworkData;

	class CORE_EXPORT NetworkInterface
	{
	public:
		NetworkInterface();
		virtual ~NetworkInterface();

		virtual void SendPacket(const NetworkData* data);
		bool ReceivePacket(NetworkData* data) const;

	protected:
		bool isServer;
		RakNet::RakPeerInterface *peer;
	};

}
}

#endif // NETWORK_CLIENT_H