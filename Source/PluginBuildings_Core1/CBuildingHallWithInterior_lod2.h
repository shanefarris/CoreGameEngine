#ifndef __CBUILDINGHALLWITHINTERIOR_LOD2_H__
#define __CBUILDINGHALLWITHINTERIOR_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHallWithInterior_lod2 : public CBuilding
	{
	public:
		CBuildingHallWithInterior_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHallWithInterior_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHallWithInterior_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingHallWithInterior_lod2Factory();
		~CBuildingHallWithInterior_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALLWITHINTERIOR_LOD2_H__
