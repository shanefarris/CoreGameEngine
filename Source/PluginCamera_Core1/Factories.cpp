#define DLL_EXPORT

#include "Factories.h"
#include "CCameraFixed.h"
#include "CCameraRTS.h"
#include "CCameraFree.h"
#include "CCameraChaseSpaceShip.h"

using namespace Core::Plugin;

// CCameraFactory_Fixed
CCameraFactory_Fixed::CCameraFactory_Fixed()
{
	Type = ECM_FIXED;
}

CCameraFactory_Fixed::~CCameraFactory_Fixed()
{
}

Core::ICamera* CCameraFactory_Fixed::GetCamera(const char* Name)
{
	return new CCameraFixed(Name);
}

// CCameraFactory_RTS
CCameraFactory_RTS::CCameraFactory_RTS()
{
	Type = ECM_RTS;
}

CCameraFactory_RTS::~CCameraFactory_RTS()
{
}

Core::ICamera* CCameraFactory_RTS::GetCamera(const char* Name)
{
	return new CCameraRTS(Name);
}

// CCameraFactory_Free
CCameraFactory_Free::CCameraFactory_Free()
{
	Type = ECM_RTS;
}

CCameraFactory_Free::~CCameraFactory_Free()
{
}

Core::ICamera* CCameraFactory_Free::GetCamera(const char* Name)
{
	return new CCameraFree(Name);
}

// CCameraFactory_ChaseSpaceShip
CCameraFactory_ChaseSpaceShip::CCameraFactory_ChaseSpaceShip()
{
	Type = ECM_CSS;
}

CCameraFactory_ChaseSpaceShip::~CCameraFactory_ChaseSpaceShip()
{
}

Core::ICamera* CCameraFactory_ChaseSpaceShip::GetCamera(const char* Name)
{
	return new CCameraChaseSpaceShip(Name);
}