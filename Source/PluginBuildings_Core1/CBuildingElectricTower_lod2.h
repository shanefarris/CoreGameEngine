#ifndef __CBUILDINGELECTRICTOWER_LOD2_H__
#define __CBUILDINGELECTRICTOWER_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingElectricTower_lod2 : public CBuilding
	{
	public:
		CBuildingElectricTower_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingElectricTower_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingElectricTower_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingElectricTower_lod2Factory();
		~CBuildingElectricTower_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGELECTRICTOWER_LOD2_H__
