#ifndef __CBUILDINGVILLAGE_HOUSE6_H__
#define __CBUILDINGVILLAGE_HOUSE6_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_house6 : public CBuilding
	{
	public:
		CBuildingVillage_house6(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_house6();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_house6Factory : public IBuildingFactory
	{
	public:
		CBuildingVillage_house6Factory();
		~CBuildingVillage_house6Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_HOUSE6_H__
