#ifndef __CBUILDINGOLDHOUSE6_LOD2_H__
#define __CBUILDINGOLDHOUSE6_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse6_lod2 : public CBuilding
	{
	public:
		CBuildingOldHouse6_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse6_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse6_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse6_lod2Factory();
		~CBuildingOldHouse6_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE6_LOD2_H__
