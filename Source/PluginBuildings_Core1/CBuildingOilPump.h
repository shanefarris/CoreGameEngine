#ifndef __CBUILDINGOILPUMP_H__
#define __CBUILDINGOILPUMP_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOilPump : public CBuilding
	{
	public:
		CBuildingOilPump(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOilPump();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOilPumpFactory : public IBuildingFactory
	{
	public:
		CBuildingOilPumpFactory();
		~CBuildingOilPumpFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOILPUMP_H__
