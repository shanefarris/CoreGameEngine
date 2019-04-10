#ifndef __CBUILDINGOILTANK6_H__
#define __CBUILDINGOILTANK6_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOilTank6 : public CBuilding
	{
	public:
		CBuildingOilTank6(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOilTank6();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOilTank6Factory : public IBuildingFactory
	{
	public:
		CBuildingOilTank6Factory();
		~CBuildingOilTank6Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOILTANK6_H__
