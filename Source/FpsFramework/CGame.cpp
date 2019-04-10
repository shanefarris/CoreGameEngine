#include "CGame.h"
#include "CGameState.h"
#include "CGameManager.h"
#include "CInputManager.h"
#include "CGameObjectManager.h"
#include "CScriptManager.h"
#include "CPluginManager.h"
#include "CGuiManager.h"
#include "CCharacterStateManager.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "CItemsManager.h"
#include "CBillboardManager.h"
#include "CNatureManager.h"
#include "CEffectsManager.h"
#include "CPhysicsManager.h"
#include "CMissionManager.h"

#include "OgreConsole.h"
#include "CLuaConsole.h"
#include "CTextOutput.h"

#include "IO/CoreLogging.h"

#include "OgreRoot.h"
#include "OgreTimer.h"
#include "OgreWindowEventUtilities.h"

using namespace Core;

CGame::CGame()
	: m_GameManager(nullptr),
	m_InputManager(nullptr),
	m_PluginManager(nullptr),
	m_GuiManager(nullptr),
	m_CharacterStateManager(nullptr),
	m_GameObjectManager(nullptr),
	m_CameraManager(nullptr),
	m_ItemsManager(nullptr),
	m_BillboardManager(nullptr),
	m_NatureManager(nullptr),
	m_EffectsManager(nullptr),
	m_PhysicsManager(nullptr),
	m_MissionManager(nullptr),
	m_TextOutput(nullptr),
	m_ActiveState(nullptr),
	m_Timer(nullptr)
{
	m_GameManager = CGameManager::Instance();
	m_InputManager = CInputManager::Instance();
	m_PluginManager = CPluginManager::Instance();
	m_CharacterStateManager = AI::CCharacterStateManager::Instance();
	m_GameObjectManager = CGameObjectManager::Instance();
	m_CameraManager = CCameraManager::Instance();
	m_GuiManager = GUI::CGuiManager::Instance();
	m_ItemsManager = CItemsManager::Instance();
	m_NatureManager = Nature::CNatureManager::Instance();
	m_BillboardManager = CBillboardManager::Instance();
	m_PhysicsManager = Physics::CPhysicsManager::Instance();
	m_MissionManager = Mission::CMissionManager::Instance();
	m_TextOutput = OgreSpecific::CTextOutput::Instance();

	m_Timer = new Timer();
	m_LastTime = m_Timer->getMilliseconds();
	m_ActiveState = nullptr;

	// Set this game object so the game manager can communicate with it
	m_GameManager->SetGame(this);

	// Default scene
	m_GameManager->CreateScene("OctreeSceneManager", "main_scene");

	// Call OnStart script
	CALL_VOIDFUNCVOID("Start")
}

CGame::~CGame()
{
	try
	{
		for(auto it = m_States.begin(); it != m_States.end(); it++)
			CORE_DELETE((*it));
		m_States.clear();

		auto console = Core::OgreConsole::Instance();
		auto luaConsole = CLuaConsole::Instance();

		CORE_DELETE(console);
		CORE_DELETE(luaConsole);
		CORE_DELETE(m_TextOutput);
		CORE_DELETE(m_Timer);

		m_EffectsManager = Effects::CEffectsManager::Instance();
		CORE_DELETE(m_EffectsManager);

		CORE_DELETE(m_PluginManager);
		CORE_DELETE(m_CharacterStateManager);
		CORE_DELETE(m_GuiManager);
		CORE_DELETE(m_InputManager);
		CORE_DELETE(m_CameraManager);
		CORE_DELETE(m_GameObjectManager);
		CORE_DELETE(m_NatureManager);
		CORE_DELETE(m_ItemsManager);
		CORE_DELETE(m_BillboardManager);
		CORE_DELETE(m_PhysicsManager);
		CORE_DELETE(m_MissionManager);
		CORE_DELETE(m_GameManager);
	}
	catch(std::exception& e)
	{
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CGame()");
	}
}

void CGame::Run()
{
	// Advance to our initial state
	AdvanceState();
	
	while(m_GameManager->GetQuit() == false)
	{
		m_DeltaTime = (m_Timer->getMilliseconds() - m_LastTime) / 1000.0f;
		m_LastTime = m_Timer->getMilliseconds();

		// Call OnPreUpdateGame script
		CALL_VOIDFUNCFLOAT("PreUpdateGame", m_DeltaTime);

		if(m_GameManager->GetEngineDevice()->renderOneFrame() == false)
			m_GameManager->SetQuit(true);

		m_InputManager->Capture();					// Game level update of the input events
		m_ActiveState->Update(m_DeltaTime);			// update level state
		Ogre::WindowEventUtilities::messagePump();	// Ogre specific:handle any window events

		// Call OnPostUpdateGame script
		CALL_VOIDFUNCFLOAT("PostUpdateGame", m_DeltaTime);
	}

	// End the last state here
	if(m_ActiveState)
	{
		m_ActiveState->End();					// close out state
		CORE_DELETE(m_ActiveState);				// free up resources
	}
}

void CGame::AddGameState(CGameState* GameState)
{
	m_States.push_back(GameState);
}

void CGame::AdvanceState()
{
	// Only end the active state here if there is still a state in the queue, otherwise end the state outside the update loop
	if(m_States.size() > 1)
	{
		// If already have active one, exit out
		if(m_ActiveState)
		{
			m_ActiveState->End();					// close out state
			CORE_DELETE(m_ActiveState);				// free up resources
		}
	}

	// if there is another state in the queue
	if(m_States.size() > 0)
	{
		m_ActiveState = m_States.back();		// assign next state

		// trigger the rendering of new state
		if(m_ActiveState->Load())
		{
			CALL_VOIDFUNCVOID("LoadLevel");		// Call OnLoadLevel script
			m_States.pop_back();				// clear out state from the queue
		}
		else
		{
			CORE_ERR("Unable to load state.");
		}
	}
	else
	{
		m_GameManager->SetQuit(true);			// sense no more states, exit out
		return;
	}
}