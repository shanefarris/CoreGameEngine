#ifndef __CFPSCLIENTSTRATEGY_H__
#define __CFPSCLIENTSTRATEGY_H__

#if defined(_WIN32)
#include "RakNet/WindowsIncludes.h"
#endif
#include "INetworkStrategy.h"

namespace RakNet
{
	struct Packet;
	struct RakNetGUID;
}

namespace Core
{
namespace Plugin
{
	class GameObject;

	class CORE_EXPORT CFpsServerStrategy : public Core::Network::INetworkStrategy
	{
	public:
		CFpsServerStrategy();
		virtual ~CFpsServerStrategy();

		void Initialize();
		virtual void Update(RakNet::Packet* Packet);

	private:
		Map<u32, RakNet::RakNetGUID*>	 m_Clients;

	};

}
}

#endif // __CFPSCLIENTSTRATEGY_H__