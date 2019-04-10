#ifndef __CNETWORKMANAGER_H__
#define __CNETWORKMANAGER_H__

#include "RakNet/WindowsIncludes.h"
#include "Defines.h"

namespace Core
{
namespace Network
{
	class NetworkData;
	class NetworkInterface;
	class INetworkStrategy;

	#define MAX_PACKETS 10000

	class CORE_EXPORT CNetworkManager
	{
	public:
		static CNetworkManager* Instance();
		virtual ~CNetworkManager();

		bool StartClient(const String& Address, u32 Port);
		bool StartServer();
		void Stop();

		void Update(u32 MaxPackets = MAX_PACKETS) const;

		void SendToNetwork(const NetworkData* m_NetworkData);
		bool isServer() const { return this->isServerInstance; }
		void SetNetworkStrategy(INetworkStrategy* NetworkStrategy);

	protected:
		static CNetworkManager* NetworkManager;

		CNetworkManager();
		
		bool ReceiveAndProcessPacket();
		bool ReceivePacket(NetworkData* Data) const;
		bool ProcessPacket(NetworkData* Data) const;

	private:
		NetworkInterface*	m_NetworkInterface;
		NetworkData*		m_NetworkData;
		bool				isServerInstance;
		INetworkStrategy*	m_NetworkStrategy;
	};

}
}

#endif // __CNETWORKMANAGER_H__