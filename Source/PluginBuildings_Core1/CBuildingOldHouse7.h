#ifndef __CBUILDINGOLDHOUSE7_H__
#define __CBUILDINGOLDHOUSE7_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse7 : public CBuilding
	{
	public:
		CBuildingOldHouse7(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse7();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse7Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse7Factory();
		~CBuildingOldHouse7Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE7_H__
