#ifndef __CBUILDINGHALL3_LOD2_H__
#define __CBUILDINGHALL3_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHall3_lod2 : public CBuilding
	{
	public:
		CBuildingHall3_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHall3_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHall3_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingHall3_lod2Factory();
		~CBuildingHall3_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALL3_LOD2_H__
