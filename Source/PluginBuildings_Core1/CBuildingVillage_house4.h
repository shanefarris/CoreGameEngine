#ifndef __CBUILDINGVILLAGE_HOUSE4_H__
#define __CBUILDINGVILLAGE_HOUSE4_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_house4 : public CBuilding
	{
	public:
		CBuildingVillage_house4(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_house4();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_house4Factory : public IBuildingFactory
	{
	public:
		CBuildingVillage_house4Factory();
		~CBuildingVillage_house4Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_HOUSE4_H__
