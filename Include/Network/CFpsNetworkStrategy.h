#ifndef __CFPSNETWORKSTRATEGY_H__
#define __CFPSNETWORKSTRATEGY_H__

#include "INetworkStrategy.h"

namespace Core
{
namespace Network
{
	class GameObject;

	class CORE_EXPORT CFpsNetworkStrategy : public INetworkStrategy
	{
	public:
		//possible actions
		enum NetworkAction
		{
			CONNECT_TO_SERVER,
			SYSTEM_MESSAGE,
			DISCONNECT,
			LOAD_MAP,
			GET_OWN_PLAYER,
			CREATE_OBJECT,
			DELETE_OBJECT,
		};

		CFpsNetworkStrategy();
		virtual ~CFpsNetworkStrategy();

		void Initialize();
		virtual void UpdateLocal(NetworkData* Data);
		virtual void SendUpdate(String address, u16 port) {}

	private:
		//receive functions
		virtual bool ReceiveAction(char action, NetworkData* m_NetworkData);
		void ReceiveConnectToServer(NetworkData* NetworkData);
		void ReceiveSystemMessage(NetworkData* NetworkData);
		void ReceiveDisconnect(NetworkData* NetworkData);
		void ReceiveLoadMap(NetworkData* NetworkData);
		void ReceiveGetOwnPlayer(NetworkData* NetworkData);
		void ReceiveCreateObject(NetworkData* NetworkData);
		void ReceiveDeleteObject(NetworkData* NetworkData);

		//send functions
		void SendCreateObject(const String &instanceName, const String &templateName, s32 networkId, NetworkData::MsgType type = NetworkData::SEND_ALL, String address = 0, u16 port = 0);
		void SendAction(char action, NetworkData::MsgType type = NetworkData::SEND_ALL, String address = 0, u16 port = 0);
		void SendString(char action, const String &str, NetworkData::MsgType type, String address, u16 port);
		template <class T> void SendVar(char Action, const T &var, NetworkData::MsgType type, String address, u16 port);
		
		void server_createNewHumanLogic(bool isLocalControl, String& playerName, s32& networkId);

		bool AddObjectToMap(String address, u16 port, String &instanceName, s32 networkId);
		String RemoveObjectFromMap(String address, u16 port);

	private:
		typedef struct ADDRESS
		{
			String addr;
			u16 port;
		} Address;

		typedef struct PLAYER
		{
			String instanceName;
			s32 networkId;
		} Player ;

		struct ADDRESS_COMPARE 
		{
			bool operator()(Address addr1, Address addr2) const 
			{
				if(addr1.addr < addr2.addr)
					return true;
				else if(addr1.addr == addr2.addr)
					return (addr1.port < addr2.port);
				else
					return false;
			}
		};

		Map<Address, Player, ADDRESS_COMPARE> players;
	};

}
}

#endif // __CFPSNETWORKSTRATEGY_H__