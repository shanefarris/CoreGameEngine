#ifndef __CBUILDINGOPENEDHALL_H__
#define __CBUILDINGOPENEDHALL_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOpenedHall : public CBuilding
	{
	public:
		CBuildingOpenedHall(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOpenedHall();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOpenedHallFactory : public IBuildingFactory
	{
	public:
		CBuildingOpenedHallFactory();
		~CBuildingOpenedHallFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOPENEDHALL_H__
