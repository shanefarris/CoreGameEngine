#ifndef __CBUILDINGOLDHOUSE10_H__
#define __CBUILDINGOLDHOUSE10_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse10 : public CBuilding
	{
	public:
		CBuildingOldHouse10(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse10();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse10Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse10Factory();
		~CBuildingOldHouse10Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE10_H__
