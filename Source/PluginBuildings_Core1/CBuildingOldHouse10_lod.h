#ifndef __CBUILDINGOLDHOUSE10_LOD_H__
#define __CBUILDINGOLDHOUSE10_LOD_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse10_lod : public CBuilding
	{
	public:
		CBuildingOldHouse10_lod(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse10_lod();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse10_lodFactory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse10_lodFactory();
		~CBuildingOldHouse10_lodFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE10_LOD_H__
