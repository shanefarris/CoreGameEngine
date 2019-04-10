#ifndef __CBUILDINGVILLAGE_HOUSE5_H__
#define __CBUILDINGVILLAGE_HOUSE5_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_house5 : public CBuilding
	{
	public:
		CBuildingVillage_house5(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_house5();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_house5Factory : public IBuildingFactory
	{
	public:
		CBuildingVillage_house5Factory();
		~CBuildingVillage_house5Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_HOUSE5_H__
