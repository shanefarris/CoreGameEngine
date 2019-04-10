#ifndef __CBUILDINGBROKENHOUSE_LOD3_H__
#define __CBUILDINGBROKENHOUSE_LOD3_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingBrokenHouse_lod3 : public CBuilding
	{
	public:
		CBuildingBrokenHouse_lod3(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingBrokenHouse_lod3();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingBrokenHouse_lod3Factory : public IBuildingFactory
	{
	public:
		CBuildingBrokenHouse_lod3Factory();
		~CBuildingBrokenHouse_lod3Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGBROKENHOUSE_LOD3_H__
