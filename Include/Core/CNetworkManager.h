#if defined(COMPILE_NETWORK)

#ifndef __CNETWORKMANAGER_H__
#define __CNETWORKMANAGER_H__

#include "RakNet/WindowsIncludes.h"
#include "RakNet/MessageIdentifiers.h"
#include "Defines.h"

namespace RakNet
{
	class  BitStream;
	class  RakPeerInterface;
	struct Packet;
	struct RakNetGUID;
	struct SystemAddress;
	enum   DefaultMessageIDTypes;
}

namespace Core
{
	namespace Network
	{
		class Client;
		class NetworkData;
		class NetworkInterface;
		class INetworkStrategy;

		enum E_NETWORK_MESSAGE_TYPE
		{
			ENMT_SPAWN_POSITION = ID_USER_PACKET_ENUM + 1,
			ENMT_POSITION_UPDATE = ID_USER_PACKET_ENUM + 2,
			ENMT_YOUR_TURN = ID_USER_PACKET_ENUM + 3,
			ENMT_NEW_CLIENT = ID_USER_PACKET_ENUM + 4,
			ENMT_LOGIN = ID_USER_PACKET_ENUM + 5,
			ENMT_NONE = ID_USER_PACKET_ENUM + 6,
		};

		#define MAX_PACKETS 10000

		class CORE_EXPORT CNetworkManager
		{
		public:
			static CNetworkManager* Instance();
			virtual ~CNetworkManager();

			bool StartClient(const String& Address, u32 Port);
			bool StartServer();

			void Update(u32 MaxPackets = MAX_PACKETS);
			bool isServer() const { return isServerInstance; }
			bool Disconnect();
			bool Login(const String& Name, const String& Password);
			bool Send(E_NETWORK_MESSAGE_TYPE MessageType);

			bool AddStrategy(const char* LabelName);
			void RemoveStrategy(const char* LabelName);

			RakNet::RakPeerInterface* GetInterface() { return m_Peer; }

		private:
			CNetworkManager();

			static CNetworkManager*		NetworkManager;

			RakNet::RakPeerInterface*	m_Peer;
			RakNet::BitStream*			m_BitStreamOut;
			NetworkData*				m_NetworkData;
			RakNet::SystemAddress*		m_ServerAddress;
			bool						isServerInstance;
			bool						isConnected;

			Map<String, INetworkStrategy*>   m_NetworkStrategies;
		};

	}
}

#endif // __CNETWORKMANAGER_H__

#endif // COMPILE_NETWORK