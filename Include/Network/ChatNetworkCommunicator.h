#if 0
#ifndef CHAT_NETWORK_COMMUNICATOR_H
#define CHAR_NETWORK_COMMUNICATOR_H

#include "Defines.h"
#include "INetworkStrategy.h"
#include "NetworkData.h"


class ChatNetworkCommunicator : public INetworkStrategy
{
public:

	ChatNetworkCommunicator(int id = -1);
	~ChatNetworkCommunicator();

	void Initialize();
	virtual void SendUpdate(u32 address, u16 port) {}

private:
	virtual bool ReceiveAction(char action, NetworkData* m_NetworkData);
	void _listen_chat(const String &str);
	void _rcvChatData(NetworkData* m_NetworkData);

private:
	//possible actions
	enum NetworkAction
	{
		CHAT
	};

};

#endif // CHAR_NETWORK_COMMUNICATOR_H

#endif