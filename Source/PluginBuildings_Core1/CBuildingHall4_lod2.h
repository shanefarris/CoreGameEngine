#ifndef __CBUILDINGHALL4_LOD2_H__
#define __CBUILDINGHALL4_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHall4_lod2 : public CBuilding
	{
	public:
		CBuildingHall4_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHall4_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHall4_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingHall4_lod2Factory();
		~CBuildingHall4_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALL4_LOD2_H__
