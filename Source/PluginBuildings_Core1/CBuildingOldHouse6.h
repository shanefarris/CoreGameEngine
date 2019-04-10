#ifndef __CBUILDINGOLDHOUSE6_H__
#define __CBUILDINGOLDHOUSE6_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse6 : public CBuilding
	{
	public:
		CBuildingOldHouse6(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse6();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse6Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse6Factory();
		~CBuildingOldHouse6Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE6_H__
