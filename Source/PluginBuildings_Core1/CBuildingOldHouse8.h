#ifndef __CBUILDINGOLDHOUSE8_H__
#define __CBUILDINGOLDHOUSE8_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse8 : public CBuilding
	{
	public:
		CBuildingOldHouse8(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse8();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse8Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse8Factory();
		~CBuildingOldHouse8Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE8_H__
