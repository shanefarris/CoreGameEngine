#ifndef __CBUILDINGOLDHOUSE1_LOD2_H__
#define __CBUILDINGOLDHOUSE1_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse1_lod2 : public CBuilding
	{
	public:
		CBuildingOldHouse1_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse1_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse1_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse1_lod2Factory();
		~CBuildingOldHouse1_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE1_LOD2_H__
