#ifndef __CBUILDINGBROKENHOUSE_H__
#define __CBUILDINGBROKENHOUSE_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingBrokenHouse : public CBuilding
	{
	public:
		CBuildingBrokenHouse(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingBrokenHouse();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingBrokenHouseFactory : public IBuildingFactory
	{
	public:
		CBuildingBrokenHouseFactory();
		~CBuildingBrokenHouseFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGBROKENHOUSE_H__
