#ifndef NETWORK_SERVER_H
#define NETWORK_SERVER_H

#define MAXCONN 10
#define SERVERPORT 12123

#include "NetworkInterface.h"

namespace Core
{
namespace Network
{
	class CORE_EXPORT NetworkServer : public NetworkInterface
	{
	public:
		NetworkServer(u16 port = SERVERPORT, int maxConnections = MAXCONN);
		virtual ~NetworkServer();

	private:
		void Start() { }

	};

}
}

#endif // NETWORK_SERVER_H