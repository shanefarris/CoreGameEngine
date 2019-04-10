#ifndef __CBUILDINGRUINEDHALL_H__
#define __CBUILDINGRUINEDHALL_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingRuinedHall : public CBuilding
	{
	public:
		CBuildingRuinedHall(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingRuinedHall();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingRuinedHallFactory : public IBuildingFactory
	{
	public:
		CBuildingRuinedHallFactory();
		~CBuildingRuinedHallFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGRUINEDHALL_H__
