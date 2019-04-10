#ifndef __IPLAYERFACTORY_H__
#define __IPLAYERFACTORY_H__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	class CPlayer;

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	namespace Plugin
	{
		class IPlayerFactory
		{
		public:
			virtual Core::CPlayer* CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy) = 0;

			const char* PlayerType;
		};
	}
}

#endif //__IPLAYERFACTORY_H__