#include "CFpsClientStrategy.h"
#include "INetworkStrategy.h"
#include "CNetworkManager.h"

#include "RakNet/RakNetTypes.h"

using namespace Core::Network;
using namespace Core::Plugin;

CFpsClientStrategy::CFpsClientStrategy()
{
}

CFpsClientStrategy::~CFpsClientStrategy()
{
}

void CFpsClientStrategy::Initialize()
{
	if(CNetworkManager::Instance()->isServer())
	{
	}
}

void CFpsClientStrategy::Update(RakNet::Packet* Packet)
{
	switch(Packet->data[0])
	{
	case DISCONNECT:
		ReceiveDisconnect(Packet);
		break;
	case LOAD_MAP:
		ReceiveLoadMap(Packet);
		break;
	case CREATE_OBJECT:
		ReceiveCreateObject(Packet);
		break;
	case DELETE_OBJECT:
		ReceiveDeleteObject(Packet);
		break;
	default:
		break;
	}
}

bool CFpsClientStrategy::ReceiveDisconnect(RakNet::Packet* Packet)
{
	return true;
}

bool CFpsClientStrategy::ReceiveLoadMap(RakNet::Packet* Packet)
{	
	return true;
}

bool CFpsClientStrategy::ReceiveCreatePlayer(RakNet::Packet* Packet)
{
	return true;
}

bool CFpsClientStrategy::ReceiveCreateObject(RakNet::Packet* Packet)
{
	return true;
}

bool CFpsClientStrategy::ReceiveDeleteObject(RakNet::Packet* Packet)
{
	return true;
}

void CFpsClientStrategy::SendCreateObject(const String &instanceName)
{	
}

void CFpsClientStrategy::SendAction(char action)
{
}

void CFpsClientStrategy::SendString(char action, const String &str)
{
}

