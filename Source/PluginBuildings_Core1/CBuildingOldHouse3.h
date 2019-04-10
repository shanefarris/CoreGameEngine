#ifndef __CBUILDINGOLDHOUSE3_H__
#define __CBUILDINGOLDHOUSE3_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse3 : public CBuilding
	{
	public:
		CBuildingOldHouse3(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse3();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse3Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse3Factory();
		~CBuildingOldHouse3Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE3_H__
