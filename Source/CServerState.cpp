#include "CNetworkManager.h"
#include "CGameManager.h"

#include "CInputManager.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"

#include "IO/CoreLogging.h"
#include "OgreTimer.h"
#include "OgreWindowEventUtilities.h"
#include "OgreRenderWindow.h"

using namespace Core;
using namespace Core::Network;

#define WIN32_LEAN_AND_MEAN

int main(int argc, char **argv)
{
	CGameManager::Instance();
	CGameManager::Instance()->GetRenderWindow()->setHidden(true);

	// Create ODE physics strategy
	auto physicsManager = Physics::CPhysicsManager::Instance();
	physicsManager->CreateStrategy("ODE");
	physicsManager->GetStrategy()->InitWorld();
	physicsManager->GetStrategy()->ShowDebug(false);

	auto networkManager = CNetworkManager::Instance();
	auto test = networkManager->StartServer();

	auto timer = new Timer();
	auto lastTime = timer->getMilliseconds();
	auto activeState = nullptr;

	while(true)
	{
		auto deltaTime = (timer->getMilliseconds() - lastTime) / 1000.0f;
		lastTime = timer->getMilliseconds();

		if(physicsManager->GetStrategy())
			physicsManager->GetStrategy()->Update(deltaTime);
		networkManager->Update();

		Ogre::WindowEventUtilities::messagePump();	// Ogre specific:handle any window events
	}

	return 0;
}
