#ifndef __CBUILDINGVILLAGE_HOUSE7_H__
#define __CBUILDINGVILLAGE_HOUSE7_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_house7 : public CBuilding
	{
	public:
		CBuildingVillage_house7(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_house7();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_house7Factory : public IBuildingFactory
	{
	public:
		CBuildingVillage_house7Factory();
		~CBuildingVillage_house7Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_HOUSE7_H__
