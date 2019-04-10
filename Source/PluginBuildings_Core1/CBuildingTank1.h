#ifndef __CBUILDINGTANK1_H__
#define __CBUILDINGTANK1_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingTank1 : public CBuilding
	{
	public:
		CBuildingTank1(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingTank1();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingTank1Factory : public IBuildingFactory
	{
	public:
		CBuildingTank1Factory();
		~CBuildingTank1Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGTANK1_H__
