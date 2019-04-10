#ifndef __CBUILDINGOLDHOUSE11_H__
#define __CBUILDINGOLDHOUSE11_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse11 : public CBuilding
	{
	public:
		CBuildingOldHouse11(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse11();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse11Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse11Factory();
		~CBuildingOldHouse11Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE11_H__
