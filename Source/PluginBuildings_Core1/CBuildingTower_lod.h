#ifndef __CBUILDINGTOWER_LOD_H__
#define __CBUILDINGTOWER_LOD_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingTower_lod : public CBuilding
	{
	public:
		CBuildingTower_lod(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingTower_lod();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingTower_lodFactory : public IBuildingFactory
	{
	public:
		CBuildingTower_lodFactory();
		~CBuildingTower_lodFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGTOWER_LOD_H__
