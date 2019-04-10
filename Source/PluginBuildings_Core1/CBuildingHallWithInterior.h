#ifndef __CBUILDINGHALLWITHINTERIOR_H__
#define __CBUILDINGHALLWITHINTERIOR_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHallWithInterior : public CBuilding
	{
	public:
		CBuildingHallWithInterior(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHallWithInterior();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHallWithInteriorFactory : public IBuildingFactory
	{
	public:
		CBuildingHallWithInteriorFactory();
		~CBuildingHallWithInteriorFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALLWITHINTERIOR_H__
