#ifndef __CBUILDINGHALL1_LOD2_H__
#define __CBUILDINGHALL1_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHall1_lod2 : public CBuilding
	{
	public:
		CBuildingHall1_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHall1_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHall1_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingHall1_lod2Factory();
		~CBuildingHall1_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALL1_LOD2_H__
