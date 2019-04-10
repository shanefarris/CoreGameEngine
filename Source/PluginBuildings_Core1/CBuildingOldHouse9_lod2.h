#ifndef __CBUILDINGOLDHOUSE9_LOD2_H__
#define __CBUILDINGOLDHOUSE9_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse9_lod2 : public CBuilding
	{
	public:
		CBuildingOldHouse9_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse9_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse9_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse9_lod2Factory();
		~CBuildingOldHouse9_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE9_LOD2_H__
