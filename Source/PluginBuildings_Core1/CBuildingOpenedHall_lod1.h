#ifndef __CBUILDINGOPENEDHALL_LOD1_H__
#define __CBUILDINGOPENEDHALL_LOD1_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOpenedHall_lod1 : public CBuilding
	{
	public:
		CBuildingOpenedHall_lod1(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOpenedHall_lod1();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOpenedHall_lod1Factory : public IBuildingFactory
	{
	public:
		CBuildingOpenedHall_lod1Factory();
		~CBuildingOpenedHall_lod1Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOPENEDHALL_LOD1_H__
