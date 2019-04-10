#ifndef __IBUILDINGFACTORY_H__
#define __IBUILDINGFACTORY_H__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	class CBuilding;

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	namespace Plugin
	{
		class IBuildingFactory
		{
		public:
			virtual Core::CBuilding* CreateBuilding(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy) = 0;

			const char* BuildingType;
		};
	}
}

#endif //__IBUILDINGFACTORY_H__