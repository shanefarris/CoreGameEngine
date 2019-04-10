#ifndef __CBUILDINGOLDHOUSE4SOCKET_H__
#define __CBUILDINGOLDHOUSE4SOCKET_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse4Socket : public CBuilding
	{
	public:
		CBuildingOldHouse4Socket(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse4Socket();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse4SocketFactory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse4SocketFactory();
		~CBuildingOldHouse4SocketFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE4SOCKET_H__
