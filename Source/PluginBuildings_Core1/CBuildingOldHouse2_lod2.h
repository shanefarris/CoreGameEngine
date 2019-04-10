#ifndef __CBUILDINGOLDHOUSE2_LOD2_H__
#define __CBUILDINGOLDHOUSE2_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse2_lod2 : public CBuilding
	{
	public:
		CBuildingOldHouse2_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse2_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse2_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse2_lod2Factory();
		~CBuildingOldHouse2_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE2_LOD2_H__
