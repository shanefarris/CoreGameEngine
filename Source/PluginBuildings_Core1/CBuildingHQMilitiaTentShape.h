#ifndef __CBUILDINGHQMILITIATENTSHAPE_H__
#define __CBUILDINGHQMILITIATENTSHAPE_H__

#include "Defines.h"
#include "CBuilding.h"
#include "Plugins/IBuildingFactory.h"

namespace Core
{
namespace Plugin
{
	class CBuildingHQMilitiaTentShape : public CBuilding
	{
	public:
		CBuildingHQMilitiaTentShape(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuildingHQMilitiaTentShape();

		void Update(const f32& elapsedTime);

	private:
		void SetupMapping();
	};

	class CBuildingHQMilitiaTentShapeFactory : public IBuildingFactory
	{
	public:
		CBuildingHQMilitiaTentShapeFactory();
		~CBuildingHQMilitiaTentShapeFactory();

		CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CBUILDINGHQMILITIATENTSHAPE_H__
