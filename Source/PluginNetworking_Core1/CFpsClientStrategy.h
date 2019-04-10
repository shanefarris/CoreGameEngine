#ifndef __CFPSCLIENTSTRATEGY_H__
#define __CFPSCLIENTSTRATEGY_H__

#if defined(_WIN32)
#include "RakNet/WindowsIncludes.h"
#endif
#include "INetworkStrategy.h"

namespace RakNet
{
	struct Packet;
}

namespace Core
{
namespace Plugin
{
	class GameObject;

	class CORE_EXPORT CFpsClientStrategy : public Core::Network::INetworkStrategy
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

		CFpsClientStrategy();
		virtual ~CFpsClientStrategy();

		void Initialize();
		virtual void Update(RakNet::Packet* Packet);

	private:
		bool ReceiveDisconnect(RakNet::Packet* Packet);
		bool ReceiveLoadMap(RakNet::Packet* Packet);
		bool ReceiveCreatePlayer(RakNet::Packet* Packet);
		bool ReceiveCreateObject(RakNet::Packet* Packet);
		bool ReceiveDeleteObject(RakNet::Packet* Packet);
		void SendCreateObject(const String &instanceName);
		void SendAction(char action);
		void SendString(char action, const String &str);
		template <class T> void SendVar(char Action, const T &var)
		{
		}
	};

}
}

#endif // __CFPSCLIENTSTRATEGY_H__