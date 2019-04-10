#ifndef __INETWORKSTRATEGY_H__
#define __INETWORKSTRATEGY_H__

#include "RakNet/WindowsIncludes.h"
#include "Defines.h"
#include "NetworkData.h"
#include "CNetworkManager.h"

namespace Core
{
namespace Network
{
	class CORE_EXPORT INetworkStrategy
	{
	public:
		virtual ~INetworkStrategy() { }

		virtual void SendUpdate(String address, u16 port) = 0;
		virtual void UpdateLocal(NetworkData* NetworkData) = 0;

		void SetLocalControl(bool control) { isLocalControl = control; }
		bool IsLocalControl() const { return isLocalControl; }

	protected:
		virtual bool ReceiveAction(char Action, NetworkData* Data) = 0;
		virtual void SendAction(char Action, NetworkData::MsgType type = NetworkData::SEND_ALL, String address = 0, u16 port = 0) = 0;
		virtual void SendString(char Action, const String &str, NetworkData::MsgType type = NetworkData::SEND_ALL, String address = 0, u16 port = 0) = 0;

	protected:
		NetworkData* m_NetworkData;
		bool		 isLocalControl;
		bool		 isNoSignals;
	};

}
}

#endif // __INETWORKSTRATEGY_H__