#define DLL_EXPORT

#include "Factories.h"
#include "PhysicsStructures.h"
#include "CPhysicsStrategy_Ode.h"

using namespace Core::Plugin;

CPhysicsStrategyFactory_Ode::CPhysicsStrategyFactory_Ode()
{
	Label = "ODE";
}

CPhysicsStrategyFactory_Ode::~CPhysicsStrategyFactory_Ode()
{
}

Core::Physics::IPhysicsStrategy* CPhysicsStrategyFactory_Ode::GetStrategy()
{
	return new Core::Physics::CPhysicsStrategy_Ode();
}
