#ifndef __CBUILDINGHALL1_H__
#define __CBUILDINGHALL1_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHall1 : public CBuilding
	{
	public:
		CBuildingHall1(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHall1();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHall1Factory : public IBuildingFactory
	{
	public:
		CBuildingHall1Factory();
		~CBuildingHall1Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALL1_H__
