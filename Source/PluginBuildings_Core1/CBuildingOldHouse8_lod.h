#ifndef __CBUILDINGOLDHOUSE8_LOD_H__
#define __CBUILDINGOLDHOUSE8_LOD_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse8_lod : public CBuilding
	{
	public:
		CBuildingOldHouse8_lod(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse8_lod();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse8_lodFactory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse8_lodFactory();
		~CBuildingOldHouse8_lodFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE8_LOD_H__
