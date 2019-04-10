#ifndef __CBUILDINGVILLAGE_CHURCH_H__
#define __CBUILDINGVILLAGE_CHURCH_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingVillage_church : public CBuilding
	{
	public:
		CBuildingVillage_church(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingVillage_church();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingVillage_churchFactory : public IBuildingFactory
	{
	public:
		CBuildingVillage_churchFactory();
		~CBuildingVillage_churchFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGVILLAGE_CHURCH_H__
