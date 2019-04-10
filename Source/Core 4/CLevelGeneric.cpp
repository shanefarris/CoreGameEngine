#include "CLevelGeneric.h"
#include "CoreEngine.h"


#include "OgreRoot.h"
#include "OgreResourceManager.h"

#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CGameObject.h"
#include "CGuiManager.h"

using namespace Ogre;
using namespace Core;
using namespace Core::Editor;
using namespace Core::Effects;
using namespace Core::Physics;

#define SERVERPORT 12123
#define CLIENTPORT 6001

void CLevelGeneric::Update(const f32& deltaTime)
{
	CGameManager::Instance()->UpdateGame(deltaTime);
	//CNetworkManager::Instance()->Update();
}

bool CLevelGeneric::Load()
{
	try
	{
		m_RuntimeEditorManager = nullptr;

		CCameraManager::Instance()->SetCameraPos(Vector3(0, 10, 0));
		CCameraManager::Instance()->SetMoveSpeed(20.0f);

		// Create ODE physics strategy
		CPhysicsManager::Instance()->CreateStrategy("ODE");
		CPhysicsManager::Instance()->GetStrategy()->InitWorld();
		CPhysicsManager::Instance()->GetStrategy()->ShowDebug(false);

		CGameManager::Instance()->LoadGame("td0.scd", "General");

		auto strategy = GUI::CGuiManager::Instance()->CreateStrategy("DEFAULT");

		m_FrameListenerFramework = new CFpsFrameListener(m_GameManager->GetRenderWindow());
		m_GameManager->GetEngineDevice()->addFrameListener(m_FrameListenerFramework);
	}
	catch(char* e)
	{
		std::cerr << e << std::endl;
	}
	return true;
}

CLevelGeneric::~CLevelGeneric()
{
	m_GameManager->GetEngineDevice()->removeFrameListener(m_FrameListenerFramework);
	CORE_DELETE(m_FrameListenerFramework);
	CORE_DELETE(m_RuntimeEditorManager);
}


