#ifndef __CBUILDINGTOWERREDWHITE_H__
#define __CBUILDINGTOWERREDWHITE_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingTowerRedWhite : public CBuilding
	{
	public:
		CBuildingTowerRedWhite(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingTowerRedWhite();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingTowerRedWhiteFactory : public IBuildingFactory
	{
	public:
		CBuildingTowerRedWhiteFactory();
		~CBuildingTowerRedWhiteFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGTOWERREDWHITE_H__
