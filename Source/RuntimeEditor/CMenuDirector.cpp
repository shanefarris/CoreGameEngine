#include "CMenuDirector.h"
#include "CGameObject.h"

#include "EditorObjects.h"
#include "CEditorHelper.h"
#include "CObjectsMenu.h"
#include "CSoundProperties.h"
#include "CMeshMenu.h"
#include "CPlayerProperties.h"
#include "CVolumeMenu.h"
#include "CPhysicsProfileMenu.h"
#include "CPhysicsSandboxOde.h"
#include "CAStarMenu.h"
#include "CSpawnPoints.h"
#include "CBuildingMenu.h"
#include "CMeshHierarchy.h"
#include "CLightMenu.h"

// Gui
#include "IGuiStrategy.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

#include <OgreRenderWindow.h>

using namespace Core;
using namespace Core::GUI;
using namespace Core::Editor;

CMenuDirector* CMenuDirector::MenuDirector = nullptr;
bool CMenuDirector::isRunning = false;

#define EDITOR_LAYOUT "Editor.layout"
#define PROPERTIES_MENU "Properties.layout"
#define GUI_STRATEGY_NAME "MYGUI"

CMenuDirector* CMenuDirector::Instance()
{
	if(!MenuDirector || !CMenuDirector::isRunning)
		MenuDirector = new CMenuDirector();
	return MenuDirector;
}

CMenuDirector::CMenuDirector() 
	: GeneralProperty(0), 
	isPaused(true), 
	isSceneLoading(false), 
	isRayTest(false),
	m_ObjectsMenu(nullptr), 
	m_SoundProperties(nullptr), 
	m_MeshMenu(nullptr), 
	m_PlayerProperties(nullptr), 
	m_VolumeMenu(nullptr),
	m_MeshHierarchy(nullptr),
	m_LightMenu(nullptr),
	m_CameraDirection(Vector3::ZERO)
{
}

CMenuDirector::~CMenuDirector()
{
	Shutdown();
}

void CMenuDirector::Start()
{
	isRunning = true;
	isVisible = false;
	
	GUI::CGuiManager* manager = CGuiManager::Instance();
	if(!manager->GetStrategy(GUI_STRATEGY_NAME))
	{
		m_GuiStrategy = static_cast<GUI::CGuiStrategy_MyGui*>(manager->CreateStrategy(GUI_STRATEGY_NAME));
		m_GuiStrategy->Initialize(EDITOR_LAYOUT);
	}

	// Set the menus
	m_ObjectsMenu = new CObjectsMenu(m_GuiStrategy);
	m_SoundProperties = new CSoundProperties(m_GuiStrategy);
	m_MeshMenu = new CMeshMenu(m_GuiStrategy);
	m_PlayerProperties = new CPlayerProperties(m_GuiStrategy);
	m_VolumeMenu = new CVolumeMenu(m_GuiStrategy);
	m_PhysicsProfileMenu = new CPhysicsProfileMenu(m_GuiStrategy);
	m_AStarMenu = new CAStarMenu(m_GuiStrategy);
	m_SpawnPoints = new CSpawnPoints(m_GuiStrategy);
	m_BuildingMenu = new CBuildingMenu(m_GuiStrategy);
	m_MeshHierarchy = new CMeshHierarchy(m_GuiStrategy);
	m_LightMenu = new CLightMenu(m_GuiStrategy);
	#ifdef COMPILE_ODE
	m_PhysicsSandboxOde = new CPhysicsSandboxOde(m_GuiStrategy);
	#endif

	// Set visibility
	m_ObjectsMenu->SetVisible(false);
	m_SoundProperties->SetVisible(false);
	m_MeshMenu->SetVisible(false);
	m_PlayerProperties->SetVisible(false);
	m_VolumeMenu->SetVisible(false);
	m_PhysicsProfileMenu->SetVisible(false);
	m_AStarMenu->SetVisible(false);
	m_SpawnPoints->SetVisible(false);
	m_BuildingMenu->SetVisible(false);
	m_MeshHierarchy->SetVisible(false);
	m_LightMenu->SetVisible(false);
	#ifdef COMPILE_ODE
	m_PhysicsSandboxOde->SetVisible(false);
	#endif

	// Set menu positions
	auto height = CGameManager::Instance()->GetRenderWindow()->getHeight();
	auto width = CGameManager::Instance()->GetRenderWindow()->getWidth();
	m_ObjectsMenu->GetForm()->setPosition(0, height - m_ObjectsMenu->GetForm()->getHeight());
	m_SoundProperties->GetForm()->setPosition(0, 0);	
	m_MeshMenu->GetForm()->setPosition(0, 0);
	m_PlayerProperties->GetForm()->setPosition(0, 0);
	m_VolumeMenu->GetForm()->setPosition(0, 0);
	m_PhysicsProfileMenu->GetForm()->setPosition(0, 0);
	m_AStarMenu->GetForm()->setPosition(0, 0);
	m_SpawnPoints->GetForm()->setPosition(0, 0);
	m_BuildingMenu->GetForm()->setPosition(0, 0);
	m_MeshHierarchy->GetForm()->setPosition(0, 0);
	m_LightMenu->GetForm()->setPosition(0, 0);
	#ifdef COMPILE_ODE
	m_PhysicsSandboxOde->GetForm()->setPosition(0, 0);
	#endif

	// Add listeners
	CInputManager::Instance()->AddMouseListener(m_ObjectsMenu, "ObjectsMenu");
	CInputManager::Instance()->AddKeyListener(m_ObjectsMenu, "m_ObjectsMenu");
	CInputManager::Instance()->AddMouseListener(m_MeshMenu, "m_MeshMenu");
	CInputManager::Instance()->AddKeyListener(m_MeshMenu, "m_MeshMenu");
	CInputManager::Instance()->AddMouseListener(m_VolumeMenu, "m_VolumeMenu");
	CInputManager::Instance()->AddKeyListener(m_VolumeMenu, "m_VolumeMenu");
	CInputManager::Instance()->AddMouseListener(m_SpawnPoints, "m_SpawnPoints");
	CInputManager::Instance()->AddKeyListener(m_SpawnPoints, "m_SpawnPoints");
	CInputManager::Instance()->AddMouseListener(m_BuildingMenu, "m_BuildingMenu");
	CInputManager::Instance()->AddKeyListener(m_BuildingMenu, "m_BuildingMenu");
	CInputManager::Instance()->AddMouseListener(m_MeshHierarchy, "m_MeshHierarchy");
	CInputManager::Instance()->AddKeyListener(m_MeshHierarchy, "m_MeshHierarchy");
	
	// Play/Pause
	m_GuiStrategy->AssignWidget(btnPlay, "btnPlay");
	m_GuiStrategy->AssignWidget(btnPause, "btnPause");
	m_GuiStrategy->AssignWidget(sldMasterSpeed, "sldMasterSpeed");
	btnPlay->eventMouseButtonClick = MyGUI::newDelegate(this, &CMenuDirector::btnPlay_Click);
	btnPause->eventMouseButtonClick = MyGUI::newDelegate(this, &CMenuDirector::btnPause_Click);
	
	// Setup images
	btnPlay->setImageTexture("btnPlay.png");
	btnPlay->setSize(31, 31);
	btnPlay->setVisible(true);
	btnPlay->setEnabled(true);
	btnPause->setImageTexture("btnPause.png");
	btnPause->setSize(31, 31);
	btnPause->setVisible(false);
	btnPause->setEnabled(false);
}

void CMenuDirector::Shutdown()
{
	CInputManager::Instance()->RemoveMouseListener(m_ObjectsMenu);
	CInputManager::Instance()->RemoveMouseListener(m_MeshMenu);
	CInputManager::Instance()->RemoveMouseListener(m_VolumeMenu);
	CInputManager::Instance()->RemoveMouseListener(m_SpawnPoints);
	CInputManager::Instance()->RemoveMouseListener(m_BuildingMenu);
	CInputManager::Instance()->RemoveMouseListener(m_MeshHierarchy);
	
	CInputManager::Instance()->RemoveKeyListener(m_ObjectsMenu);
	CInputManager::Instance()->RemoveKeyListener(m_MeshMenu);
	CInputManager::Instance()->RemoveKeyListener(m_VolumeMenu);
	CInputManager::Instance()->RemoveKeyListener(m_SpawnPoints);
	CInputManager::Instance()->RemoveKeyListener(m_BuildingMenu);
	CInputManager::Instance()->RemoveKeyListener(m_MeshHierarchy);

	CORE_DELETE(m_ObjectsMenu);
	CORE_DELETE(m_SoundProperties);
	CORE_DELETE(m_MeshMenu);
	CORE_DELETE(m_PlayerProperties);
	CORE_DELETE(m_VolumeMenu);
	CORE_DELETE(m_PhysicsProfileMenu);
	CORE_DELETE(m_AStarMenu);
	CORE_DELETE(m_SpawnPoints);
	CORE_DELETE(m_BuildingMenu);
	CORE_DELETE(m_MeshHierarchy);
	CORE_DELETE(m_LightMenu);
	#ifdef COMPILE_ODE
	CORE_DELETE(m_PhysicsSandboxOde);
	#endif

	CGuiManager::Instance()->DeleteStrategy(GUI_STRATEGY_NAME);
	m_GuiStrategy = nullptr;

	isRunning = false;
}

void CMenuDirector::btnPlay_Click(MyGUI::Widget* _sender)
{	
	Play();
}

void CMenuDirector::btnPause_Click(MyGUI::Widget* _sender)
{	
	Pause();
}

void CMenuDirector::SetVisible(bool Visible)
{
	isVisible = Visible;
	m_ObjectsMenu->SetVisible(isVisible);
	MyGUI::PointerManager::getInstance().setVisible(isVisible);

	if(!isVisible)
	{
		m_SoundProperties->GetForm()->setVisible(false);
		m_MeshMenu->GetForm()->setVisible(false);
		m_PlayerProperties->GetForm()->setVisible(false);
		m_VolumeMenu->GetForm()->setVisible(false);
		m_PhysicsProfileMenu->GetForm()->setVisible(false);
		m_AStarMenu->GetForm()->setVisible(false);
		m_SpawnPoints->GetForm()->setVisible(false);
		m_BuildingMenu->GetForm()->setVisible(false);
		m_MeshHierarchy->GetForm()->setVisible(false);
		m_LightMenu->GetForm()->setVisible(false);
		#ifdef COMPILE_ODE
		m_PhysicsSandboxOde->GetForm()->setVisible(false);
		#endif
	}
}

void CMenuDirector::SetSoundPropMenuView(bool Visible, SOUND_OBJ* SoundObject)
{
	if(m_SoundProperties)
		m_SoundProperties->SetVisible(Visible, SoundObject);
}

void CMenuDirector::SetPhysicsProfileMenuView(bool Visible)
{
	if(m_PhysicsProfileMenu)
		m_PhysicsProfileMenu->SetVisible(Visible);
}

void CMenuDirector::SetMeshMenuView(bool Visible)
{
	if(m_MeshMenu)
		m_MeshMenu->SetVisible(Visible);
}

void CMenuDirector::SetMeshMenuView(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	if(m_MeshMenu)
		m_MeshMenu->SetVisible(Visible, Selected, GameObject);
}

void CMenuDirector::SetPlayerPropMenuView(bool Visible, CPlayer* Player)
{
	if(m_PlayerProperties)
		m_PlayerProperties->SetVisible(Visible, Player);
}

void CMenuDirector::SetVolumeMenuView(bool Visible)
{
	if(m_VolumeMenu)
		m_VolumeMenu->SetVisible(Visible);
}

void CMenuDirector::SetPhysicsSandboxOdeView(bool Visible)
{
	#ifdef COMPILE_ODE
	if(m_PhysicsSandboxOde)
		m_PhysicsSandboxOde->SetVisible(Visible);
	#endif
}

void CMenuDirector::SetPhysicsSandboxOdeView(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	#ifdef COMPILE_ODE
	if(m_PhysicsSandboxOde)
		m_PhysicsSandboxOde->SetVisible(Visible, Selected, GameObject);
	#endif
}

void CMenuDirector::SetAStarMenuView(bool Visible)
{
	if(m_AStarMenu)
		m_AStarMenu->SetVisible(Visible);
}

void CMenuDirector::SetAStarMenuView(bool Visible, const SELECTED& Selected)
{
	if(m_AStarMenu)
		m_AStarMenu->SetVisible(Visible, Selected);
}

void CMenuDirector::SetSpawnPointsMenuVisible(bool Visible)
{
	if(m_SpawnPoints)
		m_SpawnPoints->SetVisible(Visible);
}

void CMenuDirector::SetSpawnPointsMenuVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	if(m_SpawnPoints)
		m_SpawnPoints->SetVisible(Visible, Selected, GameObject);
}

void CMenuDirector::SetBuildingMenuVisible(bool Visible)
{
	if(m_BuildingMenu)
		m_BuildingMenu->SetVisible(Visible);
}

void CMenuDirector::SetBuildingMenuVisible(bool Visible, const SELECTED& Selected, CBuilding* Building)
{
	if(m_BuildingMenu)
		m_BuildingMenu->SetVisible(Visible, Selected, Building);
}

void CMenuDirector::SetMeshHierarchyMenuVisible(bool Visible)
{
	if(m_MeshHierarchy)
		m_MeshHierarchy->SetVisible(Visible);
}

void CMenuDirector::SetMeshHierarchyMenuVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	if(m_MeshHierarchy)
		m_MeshHierarchy->SetVisible(Visible, Selected, GameObject);
}

void CMenuDirector::SetLightMenuVisible(bool Visible)
{
	if(m_LightMenu)
		m_LightMenu->SetVisible(Visible);
}

void CMenuDirector::SetLightMenuVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	if(m_LightMenu)
		m_LightMenu->SetVisible(Visible, Selected, GameObject);
}

void CMenuDirector::Update(f32 elapsedTime)
{
	// Are we in the middle of loading a scene
	if(!isSceneLoading)
	{
		// Check if we want to load a new scene
		if(m_ObjectsMenu)
		{
			if(m_ObjectsMenu->SceneFileName.length() > 0)
			{
				isSceneLoading = true;
				CEditorHelper::LoadSceneFile(m_ObjectsMenu->SceneFileName);
				m_ObjectsMenu->SceneFileName.clear();
				isSceneLoading = false;
			}
		}
		
		if(isPaused)
		{
			if(!CGameManager::Instance()->GetConsoleVisible())
				CCameraManager::Instance()->Update(elapsedTime);
		}
		else if(!isPaused)
		{
			elapsedTime *= sldMasterSpeed->getScrollPosition() * 0.01f;
			Physics::CPhysicsManager::Instance()->Update(elapsedTime);
			if(!CGameManager::Instance()->GetConsoleVisible())
				CCameraManager::Instance()->Update(elapsedTime);
			CGameObjectManager::Instance()->Update(elapsedTime);
			Nature::CNatureManager::Instance()->Update(elapsedTime);
			CItemsManager::Instance()->Update(elapsedTime);
			Effects::CEffectsManager::Instance()->Update(elapsedTime);
			CBillboardManager::Instance()->Update(elapsedTime);
		}
	}
}

void CMenuDirector::Save(const String& FileName)
{
	if(FileName.length() == 0)
	{
		m_GuiStrategy->ShowMessageBox("File name missing",  "Enter a file name");
		return;
	}

	if(CGameManager::Instance()->SaveGame(FileName.c_str()))
		m_GuiStrategy->ShowMessageBox("Level saved",  "Done");
	else
		m_GuiStrategy->ShowMessageBox("Error saving level",  "Error");
	
	if(m_MeshMenu)
		m_MeshMenu->SavePagedGeometry();
}

void CMenuDirector::Play()
{
	isPaused = false;
	btnPlay->setVisible(false);
	btnPlay->setEnabled(false);
	btnPause->setVisible(true);
	btnPause->setEnabled(true);

	// Set our camera if we have a human player
	m_CameraPosition = CCameraManager::Instance()->GetCameraPos();
	m_CameraDirection = CCameraManager::Instance()->GetCamera()->getDirection();

	auto player = CGameObjectManager::Instance()->GetHumanPlayer();
	if(player)
	{
		// Setup camera
		CCameraManager::Instance()->RemoveAllCameras();
		if(player->GetIsFps())
		{
			CCameraManager::Instance()->CreateCamera(ECM_FPS);
		}
		else
		{
			CCameraManager::Instance()->CreateCamera(ECM_CHASE);
		}
		
		// Show sights if the player has in item in hand
		auto item = player->GetCurrentInventoryItem();
		if(item)
		{
			item->ShowSight(true);
		}
	}
	CCameraManager::Instance()->SetEnabled(true);

	// Hide our menus by default
	SetVisible(false);
}

void CMenuDirector::Pause()
{
	isPaused = true;
	btnPlay->setVisible(true);
	btnPlay->setEnabled(true);
	btnPause->setVisible(false);
	btnPause->setEnabled(false);

	// Kill our chase camera and go back to free camera if we have a human player
	CCameraManager::Instance()->RemoveAllCameras();
	CCameraManager::Instance()->CreateCamera(ECM_GOD);
	CCameraManager::Instance()->SetCameraPos(m_CameraPosition);
	CCameraManager::Instance()->GetCamera()->setDirection(m_CameraDirection);
	CCameraManager::Instance()->SetEnabled(false);

	// Reset from player settings
	auto player = CGameObjectManager::Instance()->GetHumanPlayer();
	if(player)
	{
		// Show sights if the player has a weapon in hand
		auto item = player->GetCurrentInventoryItem();
		if(item)
		{
			item->ShowSight(false);
		}
	}

	// Show our menus by default
	SetVisible(true);
}
