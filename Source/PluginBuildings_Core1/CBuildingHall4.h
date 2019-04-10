#ifndef __CBUILDINGHALL4_H__
#define __CBUILDINGHALL4_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHall4 : public CBuilding
	{
	public:
		CBuildingHall4(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHall4();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHall4Factory : public IBuildingFactory
	{
	public:
		CBuildingHall4Factory();
		~CBuildingHall4Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHALL4_H__
