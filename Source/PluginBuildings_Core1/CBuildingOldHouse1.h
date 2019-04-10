#ifndef __CBUILDINGOLDHOUSE1_H__
#define __CBUILDINGOLDHOUSE1_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse1 : public CBuilding
	{
	public:
		CBuildingOldHouse1(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse1();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse1Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse1Factory();
		~CBuildingOldHouse1Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE1_H__
