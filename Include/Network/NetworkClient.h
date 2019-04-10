#ifndef NETWORK_CLIENT_H
#define NETWORK_CLIENT_H

#include "RakNet\RakNetTypes.h"
#include "NetworkInterface.h"

#define CLIENTPORT 0

namespace Core
{
namespace Network
{
	class CORE_EXPORT NetworkClient : public NetworkInterface
	{
	public:
		NetworkClient(u16 port = CLIENTPORT);
		virtual ~NetworkClient();

		bool Connect(const char* host, u16 port);

	private:
		RakNet::SystemAddress* m_SystemAddress;

	};

}
}

#endif // NETWORK_CLIENT_H