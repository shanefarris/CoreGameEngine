#ifndef __CBUILDINGOLDSHED_H__
#define __CBUILDINGOLDSHED_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldShed : public CBuilding
	{
	public:
		CBuildingOldShed(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldShed();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldShedFactory : public IBuildingFactory
	{
	public:
		CBuildingOldShedFactory();
		~CBuildingOldShedFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDSHED_H__
