#ifndef __CBUILDINGOILTANK6_LOD2_H__
#define __CBUILDINGOILTANK6_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOilTank6_lod2 : public CBuilding
	{
	public:
		CBuildingOilTank6_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOilTank6_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOilTank6_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingOilTank6_lod2Factory();
		~CBuildingOilTank6_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOILTANK6_LOD2_H__
