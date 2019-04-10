#ifndef __CBUILDINGTANK1_LOD2_H__
#define __CBUILDINGTANK1_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingTank1_lod2 : public CBuilding
	{
	public:
		CBuildingTank1_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingTank1_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingTank1_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingTank1_lod2Factory();
		~CBuildingTank1_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGTANK1_LOD2_H__
