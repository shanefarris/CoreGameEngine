#ifndef __CBUILDINGOILTANK_H__
#define __CBUILDINGOILTANK_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOilTank : public CBuilding
	{
	public:
		CBuildingOilTank(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOilTank();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOilTankFactory : public IBuildingFactory
	{
	public:
		CBuildingOilTankFactory();
		~CBuildingOilTankFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOILTANK_H__
