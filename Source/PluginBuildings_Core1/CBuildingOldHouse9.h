#ifndef __CBUILDINGOLDHOUSE9_H__
#define __CBUILDINGOLDHOUSE9_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse9 : public CBuilding
	{
	public:
		CBuildingOldHouse9(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse9();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse9Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse9Factory();
		~CBuildingOldHouse9Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE9_H__
