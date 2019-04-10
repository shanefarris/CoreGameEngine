#if 0
#include "GameNetworking.h"
#include "CChatStrategy.h"
#include "NetworkData.h"

CChatStrategy::ChatNetworkCommunicator(int id)
: INetworkStrategy(id)
{
}

CChatStrategy::~ChatNetworkCommunicator()
{

}

void CChatStrategy::Initialize()
{
}

bool CChatStrategy::ReceiveAction(char action, NetworkData* m_NetworkData)
{
	bool actionFound = true;

	switch(action)
	{
	case CHAT:
		_rcvChatData(m_NetworkData);
		break;
	default:
		actionFound = false;
	}
	return actionFound;
}


void CChatStrategy::_listen_chat(const String &str)
{
	//if(!isNoSignals)
	//{
	//	SendString(CHAT, str);
	//	if(isServer())
	//		gui->AddText(str.c_str());
	//}
}

void CChatStrategy::_rcvChatData(NetworkData* m_NetworkData)
{
	//String str;
	//m_NetworkData->ReadString(str);

	//if(isServer())
	//{
	//	SendString(CHAT, str);
	//}

	//gui->AddText(str.c_str());
}

void CChatStrategy::UpdateLocal(NetworkData* Data)
{
	isNoSignals = true;
	char action = 0;

	while(Data->GetBytesRead() != Data->GetSize())
	{
		Data->ReadVar(action);
		ReceiveAction(action, Data);
	}
	isNoSignals = false;
}
#endif