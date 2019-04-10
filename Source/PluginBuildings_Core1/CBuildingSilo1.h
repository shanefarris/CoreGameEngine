#ifndef __CBUILDINGSILO1_H__
#define __CBUILDINGSILO1_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingSilo1 : public CBuilding
	{
	public:
		CBuildingSilo1(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingSilo1();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingSilo1Factory : public IBuildingFactory
	{
	public:
		CBuildingSilo1Factory();
		~CBuildingSilo1Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGSILO1_H__
