#ifndef __CBUILDINGVILLAGE_HOUSE2_H__
#define __CBUILDINGVILLAGE_HOUSE2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_house2 : public CBuilding
	{
	public:
		CBuildingVillage_house2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_house2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_house2Factory : public IBuildingFactory
	{
	public:
		CBuildingVillage_house2Factory();
		~CBuildingVillage_house2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_HOUSE2_H__
