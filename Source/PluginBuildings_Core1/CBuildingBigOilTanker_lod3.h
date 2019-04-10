#ifndef __CBUILDINGBIGOILTANKER_LOD3_H__
#define __CBUILDINGBIGOILTANKER_LOD3_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingBigOilTanker_lod3 : public CBuilding
	{
	public:
		CBuildingBigOilTanker_lod3(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingBigOilTanker_lod3();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingBigOilTanker_lod3Factory : public IBuildingFactory
	{
	public:
		CBuildingBigOilTanker_lod3Factory();
		~CBuildingBigOilTanker_lod3Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGBIGOILTANKER_LOD3_H__
