#ifndef __CBUILDINGBIGOILTANKER_H__
#define __CBUILDINGBIGOILTANKER_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingBigOilTanker : public CBuilding
	{
	public:
		CBuildingBigOilTanker(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingBigOilTanker();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingBigOilTankerFactory : public IBuildingFactory
	{
	public:
		CBuildingBigOilTankerFactory();
		~CBuildingBigOilTankerFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGBIGOILTANKER_H__
