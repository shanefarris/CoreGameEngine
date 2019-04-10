#if defined(COMPILE_NETWORK)

#include "CNetworkManager.h"
#include "NetworkData.h"
#include "INetworkStrategy.h"
#include "IO/CoreLogging.h"
#include "CPluginManager.h"

#include "Plugins/INetworkingFactory.h"

#include "RakNet/RakNetTypes.h"
#include "RakNet/RakPeerInterface.h"

using namespace RakNet;
using namespace Core;
using namespace Core::Plugin;
using namespace Core::Network;

#define MAXCONN 10
#define SERVERPORT 12123

CNetworkManager* CNetworkManager::NetworkManager = nullptr;

CNetworkManager* CNetworkManager::Instance()
{
	if(NetworkManager)
		return NetworkManager;
	else 
		return new CNetworkManager();
}

CNetworkManager::CNetworkManager()
{
	m_ServerAddress = nullptr;
	m_NetworkData = new NetworkData();
	m_Peer = RakPeerInterface::GetInstance();
	m_BitStreamOut = new BitStream();
}

CNetworkManager::~CNetworkManager()
{
	m_Peer->Shutdown(300);
	RakNet::RakPeerInterface::DestroyInstance(m_Peer);

	CORE_DELETE(m_NetworkData);
}

bool CNetworkManager::StartClient(const String& Address, u32 Port)
{
	isServerInstance = false;
	m_NetworkData = new NetworkData();

	SocketDescriptor sd(6001, 0);
	m_Peer->Startup(1, &sd, 1);
	m_Peer->SetOccasionalPing(true);

	// Create connection
	NetworkData networkData;
	bool anwser = false;

	// Try 5 times before we quit
	for(int i = 0; i < 5; i++)
	{
		if(m_Peer->Connect(Address.c_str(), Port, 0, 0, 0))
		{
			while(true)
			{
				for (auto packet = m_Peer->Receive(); packet; m_Peer->DeallocatePacket(packet), packet = m_Peer->Receive())
				{
#ifdef _WIN32
					Sleep(30);
#else
					usleep(30 * 1000);
#endif

					// Check if this is a network message packet
					if((u8)packet->data[0] == ID_CONNECTION_REQUEST_ACCEPTED) 
					{
						isConnected = true;
						m_ServerAddress = &packet->systemAddress;
						return true;
					}

				}

			}
		}
	}
	return false;
}

bool CNetworkManager::StartServer()
{
	SocketDescriptor s1(SERVERPORT, 0);
	m_Peer->Startup(MAXCONN, &s1, 1);
	m_Peer->SetMaximumIncomingConnections(MAXCONN);
	m_Peer->SetOccasionalPing(true);
	m_Peer->SetUnreliableTimeout(1000);

	isServerInstance = true;
	isConnected = true;
	m_NetworkData = new NetworkData();

	return true;
}

void CNetworkManager::Update(u32 MaxPackets)
{
	for (auto packet = m_Peer->Receive(); packet; m_Peer->DeallocatePacket(packet), packet = m_Peer->Receive())
	{
		u32 count = 0;

		// Check if this is a network message packet
		switch (packet->data[0]) 
		{
		case ID_DISCONNECTION_NOTIFICATION:
			// Connection lost normally
			isConnected = false;
			CORE_LOG("ID_DISCONNECTION_NOTIFICATION");
			break;

		case ID_CONNECTION_LOST:
			// Couldn't deliver a reliable packet - i.e. the other system was abnormally terminated
			CORE_LOG("ID_CONNECTION_LOST");
			break;

		case ID_NEW_INCOMING_CONNECTION:
			CORE_LOG("A connection is incoming");
			break;

		default:
			break;
		}

		// Iterate through all the plugins
		for each (auto strategy in m_NetworkStrategies)
		{
			strategy.second->Update(packet);
		}

		m_Peer->DeallocatePacket(packet);

		count++;
		if(count < MaxPackets)
			break;

		packet = m_Peer->Receive();
	}
}

bool CNetworkManager::Disconnect() 
{
	if (!m_Peer) 
	{
		CORE_ERR("ERROR: no client mem alloc, could not disconnect.");
		return false;
	}

	m_Peer->Shutdown(300);
	isConnected = false;

	return true;
}

bool CNetworkManager::Login(const String& Name, const String& Password) 
{
	if (!m_Peer || !isConnected) 
	{
		CORE_ERR("ERROR: No peer or not connected before logging in.");
		return false;
	}

	RakNet::BitStream bsOut;
	bsOut.Write((RakNet::MessageID)ENMT_LOGIN);
	bsOut.Write(Name.c_str());
	bsOut.Write(Password.c_str());
	m_Peer->Send(&bsOut,HIGH_PRIORITY,RELIABLE_ORDERED,0,*m_ServerAddress,false);

	//BitStream outgoingBitstream;
	//outgoingBitstream.Write((MessageID)LOGIN);
	//outgoingBitstream.Write((u8)Name.length());
	//outgoingBitstream.Write("test");
	//outgoingBitstream.Write((u8)Password.length());
	//outgoingBitstream.Write("tester");
	//auto result = m_Peer->Send(&outgoingBitstream, HIGH_PRIORITY, RELIABLE_ORDERED, 0, *m_ServerAddress, false) > 0;

	return true;
}

bool CNetworkManager::AddStrategy(const char* LabelName)
{
	auto plugins = CPluginManager::Instance()->GetNetworkingFactories();
	for each (auto p in plugins)
	{
		if(strncmp(LabelName, p->LabelName.c_str(), p->LabelName.length()) == 0)
		{
			m_NetworkStrategies[LabelName] = p->GetStrategy();
			return true;
		}
	}
	return false;
}

void CNetworkManager::RemoveStrategy(const char* LabelName)
{
	if(m_NetworkStrategies.find(LabelName) != m_NetworkStrategies.end())
	{
		m_NetworkStrategies.erase(LabelName);
	}
}

#endif