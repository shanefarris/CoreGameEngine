#ifndef __CBUILDINGELECTRICTOWER_H__
#define __CBUILDINGELECTRICTOWER_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingElectricTower : public CBuilding
	{
	public:
		CBuildingElectricTower(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingElectricTower();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingElectricTowerFactory : public IBuildingFactory
	{
	public:
		CBuildingElectricTowerFactory();
		~CBuildingElectricTowerFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGELECTRICTOWER_H__
