#ifndef __CBUILDINGVILLAGE_HOUSE3_H__
#define __CBUILDINGVILLAGE_HOUSE3_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_house3 : public CBuilding
	{
	public:
		CBuildingVillage_house3(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_house3();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_house3Factory : public IBuildingFactory
	{
	public:
		CBuildingVillage_house3Factory();
		~CBuildingVillage_house3Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_HOUSE3_H__
