#ifndef __CBUILDINGOLDHOUSE5_H__
#define __CBUILDINGOLDHOUSE5_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingOldHouse5 : public CBuilding
	{
	public:
		CBuildingOldHouse5(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingOldHouse5();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingOldHouse5Factory : public IBuildingFactory
	{
	public:
		CBuildingOldHouse5Factory();
		~CBuildingOldHouse5Factory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGOLDHOUSE5_H__
