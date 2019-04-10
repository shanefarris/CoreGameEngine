#ifndef __CBUILDINGVILLAGE_HOUSE1_H__
#define __CBUILDINGVILLAGE_HOUSE1_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_house1 : public CBuilding
	{
	public:
		CBuildingVillage_house1(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_house1();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_house1Factory : public IBuildingFactory
	{
	public:
		CBuildingVillage_house1Factory();
		~CBuildingVillage_house1Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_HOUSE1_H__
