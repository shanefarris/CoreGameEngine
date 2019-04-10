#ifndef __CBUILDINGOLDHOUSE7_LOD2_H__
#define __CBUILDINGOLDHOUSE7_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse7_lod2 : public CBuilding
	{
	public:
		CBuildingOldHouse7_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse7_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse7_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse7_lod2Factory();
		~CBuildingOldHouse7_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE7_LOD2_H__
