#ifndef __CBUILDINGOILTANK2_H__
#define __CBUILDINGOILTANK2_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOilTank2 : public CBuilding
	{
	public:
		CBuildingOilTank2(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOilTank2();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOilTank2Factory : public IBuildingFactory
	{
	public:
		CBuildingOilTank2Factory();
		~CBuildingOilTank2Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOILTANK2_H__
