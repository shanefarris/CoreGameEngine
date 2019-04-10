#ifndef __CBUILDINGOLDHOUSE4_H__
#define __CBUILDINGOLDHOUSE4_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse4 : public CBuilding
	{
	public:
		CBuildingOldHouse4(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse4();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse4Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse4Factory();
		~CBuildingOldHouse4Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE4_H__
