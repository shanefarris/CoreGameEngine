#ifndef __CBUILDINGSILO1_LOD2_H__
#define __CBUILDINGSILO1_LOD2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingSilo1_lod2 : public CBuilding
	{
	public:
		CBuildingSilo1_lod2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingSilo1_lod2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingSilo1_lod2Factory : public IBuildingFactory
	{
	public:
		CBuildingSilo1_lod2Factory();
		~CBuildingSilo1_lod2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGSILO1_LOD2_H__
