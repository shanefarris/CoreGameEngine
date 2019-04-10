#include "CFpsServerStrategy.h"
#include "INetworkStrategy.h"
#include "CNetworkManager.h"
#include "IO/CoreLogging.h"

#include "RakNet/BitStream.h"
#include "RakNet/RakNetTypes.h"
#include "RakNet/RakPeerInterface.h"

using namespace Core::Network;
using namespace Core::Plugin;

CFpsServerStrategy::CFpsServerStrategy()
{
}

CFpsServerStrategy::~CFpsServerStrategy()
{
}

void CFpsServerStrategy::Update(RakNet::Packet* Packet)
{
	u8 packetIdentifier = 255;
		if ((unsigned char)Packet->data[0] == ID_TIMESTAMP)
		{
			packetIdentifier = (u8)Packet->data[sizeof(u8) + sizeof(u8)];
		}
		else
		{
			packetIdentifier = (u8)Packet->data[0];
		}

	// Check if this is a network message packet
		switch (packetIdentifier) 
		{
		case ID_DISCONNECTION_NOTIFICATION:
			// Connection lost normally
			CORE_LOG("ID_DISCONNECTION_NOTIFICATION");
			break;

		case ID_CONNECTION_LOST:
			// Couldn't deliver a reliable packet - i.e. the other system was abnormally terminated
			CORE_LOG("ID_CONNECTION_LOST");
			break;

		case ID_NEW_INCOMING_CONNECTION:
			{
				CORE_LOG("A connection is incoming");

				auto peer = CNetworkManager::Instance()->GetInterface();
				auto client_id = (int)m_Clients.size();

				if((u32)m_Clients.size() > 0)
				{
					RakNet::BitStream bsOut;
					bsOut.Reset();
					bsOut.Write((RakNet::MessageID)ENMT_NEW_CLIENT);
					bsOut.Write(client_id);
					for(u32 i=0; i < (u32)m_Clients.size(); ++i)
					{
						std::cout << "  To: " << i << " - " << m_Clients[i]->g << std::endl;
						peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, peer->GetSystemAddressFromGuid(*m_Clients[i]), false);
					}
					bsOut.Reset();

					std::cout << "Sending each client's position to new client\n";
					for (int i = 0; i < (int)m_Clients.size(); ++i) {
						std::cout << "sending for " << i << std::endl;
						bsOut.Reset();
						bsOut.Write((RakNet::MessageID)ENMT_NEW_CLIENT);
						bsOut.Write(i);
						peer->Send(&bsOut, HIGH_PRIORITY, RELIABLE_ORDERED, 0, Packet->systemAddress, false);
					}
				}

				// Add client 
				m_Clients[client_id] = &Packet->guid;

				break;
			}

		case ENMT_LOGIN:
			{
				CORE_LOG("LOGIN");

				RakNet::RakString name;
				RakNet::RakString password;
				RakNet::BitStream bsIn(Packet->data, Packet->length,false);

				bsIn.IgnoreBytes(sizeof(RakNet::MessageID));

				bsIn.Read(name);
				printf("%s\n", name.C_String());

				bsIn.Read(password);
				printf("%s\n", password.C_String());

				break;
			}
		default:
			break;
		}
}
