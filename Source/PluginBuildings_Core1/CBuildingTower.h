#ifndef __CBUILDINGTOWER_H__
#define __CBUILDINGTOWER_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingTower : public CBuilding
	{
	public:
		CBuildingTower(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingTower();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingTowerFactory : public IBuildingFactory
	{
	public:
		CBuildingTowerFactory();
		~CBuildingTowerFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGTOWER_H__
