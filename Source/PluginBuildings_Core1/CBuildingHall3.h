#ifndef __CBUILDINGHALL3_H__
#define __CBUILDINGHALL3_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHall3 : public CBuilding
	{
	public:
		CBuildingHall3(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHall3();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHall3Factory : public IBuildingFactory
	{
	public:
		CBuildingHall3Factory();
		~CBuildingHall3Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALL3_H__
