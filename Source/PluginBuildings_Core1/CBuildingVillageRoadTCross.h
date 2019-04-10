#ifndef __CBUILDINGVILLAGEROADTCROSS_H__
#define __CBUILDINGVILLAGEROADTCROSS_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillageRoadTCross : public CBuilding
	{
	public:
		CBuildingVillageRoadTCross(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillageRoadTCross();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillageRoadTCrossFactory : public IBuildingFactory
	{
	public:
		CBuildingVillageRoadTCrossFactory();
		~CBuildingVillageRoadTCrossFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGEROADTCROSS_H__
