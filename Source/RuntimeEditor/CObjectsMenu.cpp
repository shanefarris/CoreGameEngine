#include "CObjectsMenu.h"
#include "CItemsManager.h"
#include "CGameManager.h"
#include "CItemProfile.h"
#include "CInputManager.h"
#include "SceneImporterPackage.h"
#include "CEditorHelper.h"
#include "CMenuDirector.h"
#include "IO/CFileSystem.h"
#include "CScriptManager.h"
#include "RuntimeEditor/CRuntimeEditorManager.h"
#include "Ai/Wall.h"
#include "Audio/CSound.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "CCharacterStateManager.h"
#include "CGameObjectManager.h"
#include "CPlayer.h"
#include "Audio/CSoundManager.h"
#include "CGameObject.h"
#include "CCameraManager.h"
#include "CNatureManager.h"
#include "CInputEvent.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

// Ogre
#include "OgreRay.h"
#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreManualObject.h"
#include "OgreBillboardChain.h"
#include "OgreStringConverter.h"
#include "OgreMaterialManager.h"
#include "OgreRenderWindow.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::GUI;
using namespace Core::Editor;
using namespace Core::Physics;

void sound_event(Sound::CSound* sound)
{
	std::cout << "fart" << std::endl;
}

CObjectsMenu::CObjectsMenu(CGuiStrategy_MyGui* Strategy)
{
	Strategy->AssignWidget(btnAddPlayer, "btnAddPlayer");
	Strategy->AssignWidget(cmbPlayers, "cmbPlayers");
	Strategy->AssignWidget(btnPlaceObsBox, "btnPlaceObsBox");
	Strategy->AssignWidget(btnPlaceObsSphere, "btnPlaceObsSphere");
	Strategy->AssignWidget(btnAddPathPoint, "btnAddPathPoint");
	Strategy->AssignWidget(btnAddAStarNodes, "btnAddAStarNodes");
	Strategy->AssignWidget(btnPhysicsProfile, "btnPhysicsProfile");
	Strategy->AssignWidget(btnAddWall, "btnAddWall");
	Strategy->AssignWidget(btnSave, "btnSave");
	Strategy->AssignWidget(cmbFileType, "cmbFileType");
	Strategy->AssignWidget(btnLoadSceneFile, "btnLoadSceneFile");
	Strategy->AssignWidget(btnPlaceItem, "btnPlaceItem");
	Strategy->AssignWidget(cmbItemsInventory, "cmbItemsInventory");
	Strategy->AssignWidget(txtSceneFile, "txtSceneFile");
	Strategy->AssignWidget(btnPlacePlane, "btnPlacePlane");
	Strategy->AssignWidget(cmbPaths, "cmbPaths");
	Strategy->AssignWidget(cmbSoundFiles, "cmbSoundFiles");
	Strategy->AssignWidget(btnAddSound, "btnAddSound");
	Strategy->AssignWidget(btnAddMesh, "btnAddMesh");
	Strategy->AssignWidget(btnAddBuilding, "btnAddBuilding");
	Strategy->AssignWidget(btnAddVolume, "btnAddVolume");
	Strategy->AssignWidget(chkShowPhyDebug, "chkShowPhyDebug");
	Strategy->AssignWidget(btnPhysSandbox, "btnPhysSandbox");
	Strategy->AssignWidget(txtFirstRayTest, "txtFirstRayTest");
	Strategy->AssignWidget(lstRayTestAll, "lstRayTestAll");
	Strategy->AssignWidget(btnSpawnPoints, "btnSpawnPoints");
	Strategy->AssignWidget(btnHierarchy, "btnHierarchy");
	Strategy->AssignWidget(btnAddLight, "btnAddLight");
	Strategy->AssignWidget(txtAmbientX, "txtAmbientX");
	Strategy->AssignWidget(txtAmbientY, "txtAmbientY");
	Strategy->AssignWidget(txtAmbientZ, "txtAmbientZ");
	Strategy->AssignWidget(cmdSaveLight, "cmdSaveLight");
	Strategy->AssignWidget(cmbShadowTechnique, "cmbShadowTechnique");

	Strategy->AssignWidget(frm, "_Main");

	MyGUI::PointerManager::getInstance().setVisible(true);

	btnAddPlayer->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddPlayer_Click);
	btnPlaceObsBox->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnPlaceObsBox_Click);
	btnPlaceObsSphere->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnPlaceObsSphere_Click);
	btnAddPathPoint->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddPathPoint_Click);
	btnAddAStarNodes->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddAStarNodes_Click);
	btnPhysicsProfile->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnPhysicsProfile_Click);
	btnAddWall->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddWall_Click);
	btnSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnSave_Click);
	btnLoadSceneFile->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnLoadSceneFile_Click);
	btnPlaceItem->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnPlaceItem_Click);
	btnPlacePlane->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnPlacePlane_Click);
	btnAddSound->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddSound_Click);
	btnAddMesh->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddMesh_Click);
	btnAddBuilding->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddBuilding_Click);
	btnAddVolume->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddVolume_Click);
	chkShowPhyDebug->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::chkShowPhyDebug_Click);
	btnPhysSandbox->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnPhysSandbox_Click);
	btnSpawnPoints->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnSpawnPoints_Click);
	btnHierarchy->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnHierarchy_Click);
	btnAddLight->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::btnAddLight_Click);
	cmdSaveLight->eventMouseButtonClick = MyGUI::newDelegate(this, &CObjectsMenu::cmdSaveLight_Click);

	// Assume we have a physics strategy
	using namespace Core::Physics;
	m_Physics = CPhysicsManager::Instance()->GetStrategy();

	PopulateInventoryItemList();
	PopulatePathsList();
	PopulatePlayerList();
	PopulateSoundsList();

	isPlacePlayer = false;
	isPlaceObsBox_Click = false;	
	isPlaceObsSphere_Click = false;
	isAddPathPoint_Click = false;	
	isAddWall_Click = false;		
	isPlaceInventoryItem = false;					
	isAddSound = false;	
	isMouseReleased = true;

	curr_player = nullptr;
	m_WallManObj = nullptr;
	m_WallMatNameRed = "wall_mat_red";
	m_WallMatNameWhite = "wall_mat_white";
	m_WallCounter = 0;
	path_count = 0;

	keepRunning = true;
}

CObjectsMenu::~CObjectsMenu()
{
}

void CObjectsMenu::btnAddPlayer_Click(MyGUI::Widget* _sender)
{
	isPlacePlayer = true;
}

void CObjectsMenu::btnPlaceObsBox_Click(MyGUI::Widget* _sender)
{
	isPlaceObsBox_Click = true;
}

void CObjectsMenu::btnPlaceObsSphere_Click(MyGUI::Widget* _sender)
{
	isPlaceObsSphere_Click = true;
}

void CObjectsMenu::btnAddPathPoint_Click(MyGUI::Widget* _sender)
{
	isAddPathPoint_Click = true;
}

void CObjectsMenu::btnAddAStarNodes_Click(MyGUI::Widget* _sender)
{
	CMenuDirector::Instance()->SetAStarMenuView(true);
}

void CObjectsMenu::btnPhysicsProfile_Click(MyGUI::Widget* _sender)
{
	CMenuDirector::Instance()->SetPhysicsProfileMenuView(true);
}

void CObjectsMenu::btnAddWall_Click(MyGUI::Widget* _sender)
{
	isAddWall_Click = true;
}

void CObjectsMenu::btnSave_Click(MyGUI::Widget* _sender)
{	
	CMenuDirector::Instance()->Save(txtSceneFile->getOnlyText());
}

void CObjectsMenu::btnPlaceItem_Click(MyGUI::Widget* _sender)
{	
	ItemName = cmbItemsInventory->getCaption().asUTF8();
	isPlaceInventoryItem = true;
}

void CObjectsMenu::btnLoadSceneFile_Click(MyGUI::Widget* _sender)
{	
	SceneFileName = txtSceneFile->getOnlyText();
}

void CObjectsMenu::btnPlacePlane_Click(MyGUI::Widget* _sender)
{	
	CRuntimeEditorManager::Instance()->CreatePlane();
}

void CObjectsMenu::btnAddMesh_Click(MyGUI::Widget* _sender)
{	
	CMenuDirector::Instance()->SetMeshMenuView(true);
}

void CObjectsMenu::btnAddBuilding_Click(MyGUI::Widget* _sender)
{	
	CMenuDirector::Instance()->SetBuildingMenuVisible(true);
}

void CObjectsMenu::btnAddSound_Click(MyGUI::Widget* _sender)
{
	isAddSound = true;
	SoundFile = cmbSoundFiles->getCaption().asUTF8();
}

void CObjectsMenu::btnAddVolume_Click(MyGUI::Widget* _sender)
{	
	CMenuDirector::Instance()->SetVolumeMenuView(true);
}

void CObjectsMenu::chkShowPhyDebug_Click(MyGUI::Widget* _sender)
{
	chkShowPhyDebug->setStateSelected(!chkShowPhyDebug->getStateSelected());
	IPhysicsStrategy* physics = CPhysicsManager::Instance()->GetStrategy();
	if(physics)
	{
		physics->ShowDebug(chkShowPhyDebug->getStateSelected());
	}
}

void CObjectsMenu::btnPhysSandbox_Click(MyGUI::Widget* _sender)
{
#ifdef COMPILE_ODE

	if(m_Selected.Selected)
	{
		if(m_Selected.Type == ST_OBJ)
		{
			CGameObject* obj = static_cast<CGameObject*>(m_Selected.Selected);

			// Open the ode sandbox
			CMenuDirector::Instance()->SetPhysicsSandboxOdeView(true, m_Selected, obj);
		}
	}

#endif
}

void CObjectsMenu::btnSpawnPoints_Click(MyGUI::Widget* _sender)
{
	CMenuDirector::Instance()->SetSpawnPointsMenuVisible(true);
}

void CObjectsMenu::btnHierarchy_Click(MyGUI::Widget* _sender)
{
	CMenuDirector::Instance()->SetMeshHierarchyMenuVisible(true);
}

void CObjectsMenu::btnAddLight_Click(MyGUI::WidgetPtr _sender)
{
	CMenuDirector::Instance()->SetLightMenuVisible(true);
}

void CObjectsMenu::cmdSaveLight_Click(MyGUI::WidgetPtr _sender)
{
	// Shadow Technique
	ShadowTechnique shadowTechnique;
	String value = cmbShadowTechnique->getCaption().asUTF8();
	if(value == "SHADOWDETAILTYPE_ADDITIVE")
		shadowTechnique = SHADOWDETAILTYPE_ADDITIVE;
	else if(value == "SHADOWDETAILTYPE_MODULATIVE")
		shadowTechnique = SHADOWDETAILTYPE_MODULATIVE;
	else if(value == "SHADOWDETAILTYPE_INTEGRATED")
		shadowTechnique = SHADOWDETAILTYPE_INTEGRATED;
	else if(value == "SHADOWDETAILTYPE_STENCIL")
		shadowTechnique = SHADOWDETAILTYPE_STENCIL;
	else if(value == "SHADOWDETAILTYPE_TEXTURE")
		shadowTechnique = SHADOWDETAILTYPE_TEXTURE;
	else if(value == "SHADOWTYPE_STENCIL_MODULATIVE")
		shadowTechnique = SHADOWTYPE_STENCIL_MODULATIVE;
	else if(value == "SHADOWTYPE_STENCIL_ADDITIVE")
		shadowTechnique = SHADOWTYPE_STENCIL_ADDITIVE;
	else if(value == "SHADOWTYPE_TEXTURE_MODULATIVE")
		shadowTechnique = SHADOWTYPE_TEXTURE_MODULATIVE;
	else if(value == "SHADOWTYPE_TEXTURE_ADDITIVE")
		shadowTechnique = SHADOWTYPE_TEXTURE_ADDITIVE;
	else if(value == "SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED")
		shadowTechnique = SHADOWTYPE_TEXTURE_ADDITIVE_INTEGRATED;
	else if(value == "SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED")
		shadowTechnique = SHADOWTYPE_TEXTURE_MODULATIVE_INTEGRATED;
	else
		shadowTechnique = SHADOWTYPE_NONE;

	// Ambient light
	auto ambientX = StringConverter::parseReal(txtAmbientX->getCaption());
	auto ambientY = StringConverter::parseReal(txtAmbientY->getCaption());
	auto ambientZ = StringConverter::parseReal(txtAmbientZ->getCaption());

	CGameManager::Instance()->GetSceneManager()->setShadowTechnique(shadowTechnique);
	CGameManager::Instance()->GetSceneManager()->setAmbientLight(ColourValue(ambientX, ambientY, ambientZ));
}

void CObjectsMenu::SetVisible(bool Visible)
{
	frm->setVisible(Visible);
}

void CObjectsMenu::PopulateInventoryItemList()
{
	// Populate cmbItemsInventory
	Vector<CItemProfile*> items;
	CItemsManager::Instance()->GetItemProfiles(items);
	for(u32 i = 0; i < items.size(); i++)
	{
		cmbItemsInventory->addItem(items[i]->Name);
	}
}

void CObjectsMenu::PopulatePathsList()
{
	// Clear list
	cmbPaths->removeAllItems();

	PathDefinition paths;
	CCharacterStateManager::Instance()->GetAllPaths(paths);

	for(auto it = paths.cbegin(); it != paths.cend(); it++)
	{
		cmbPaths->addItem(it->first);
	}
}

void CObjectsMenu::PopulateSoundsList()
{
	cmbSoundFiles->removeAllItems();

	String defaultSoundResourceName = CGameManager::Instance()->GetBaseAudioResourceName();
	if(ResourceGroupManager::getSingleton().resourceGroupExists(defaultSoundResourceName))
	{
		auto res = Ogre::ResourceGroupManager::getSingleton().listResourceNames(defaultSoundResourceName);
		for(auto it = res->cbegin(); it != res->cend(); it++)
		{
			std::cerr << (*it) << std::endl;

			// Check for the "ogg" extension
			if(IO::CFileSystem::GetFileExtension((*it)) == "ogg")
			{
				cmbSoundFiles->addItem((*it));

			}
		}
	}
}

void CObjectsMenu::PopulatePlayerList()
{
	// remove the list
	cmbPlayers->removeAllItems();

	// Add to the list
	Vector<const char*> list;
	CGameObjectManager::Instance()->GetPlayerTypes(list);
	for(u32 i = 0; i < list.size(); i++)
	{
		cmbPlayers->addItem(MyGUI::UString(list[i]));
	}
}

void CObjectsMenu::PlaceObsBox(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{
		CEditorHelper::AddObstacleBox(pos);
	}

	if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) ||
		CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
	{
		isPlaceObsBox_Click = true;
	}
	else
	{
		isPlaceObsBox_Click = false;
	}
}

void CObjectsMenu::AddPathPoint(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{
		Vector3 point(pos.x, pos.y + 1, pos.z);
		CEditorHelper::AddPathNodeShape(point);
		PathPoints.push_back(point);

		// Draw a line between the last two points
		if(PathPoints.size() > 1)
		{
			Vector3 from = PathPoints[PathPoints.size() -1];
			Vector3 to = PathPoints[PathPoints.size() -2];
			CEditorHelper::Draw3D_Line(from, to, ColourValue::Blue, String(""));
		}
	}

	if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) ||
		CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
	{
		isAddPathPoint_Click = true;
	}
	else
	{
		isAddPathPoint_Click = false;
	}
}

void CObjectsMenu::AddWall(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{
		if(m_WallCounter == 0)
		{
			m_CurrWallFrom = pos + Vector3(0, 1, 0);
			m_WallCounter++;
		}
		else
		{
			if(m_WallManObj)
			{
				CGameManager::Instance()->GetSceneManager()->destroyManualObject(m_WallManObj);
				m_WallManObj = nullptr;
			}

			Vector3 to = pos + Vector3(0, 1, 0);
			isAddWall_Click = false;
			m_WallCounter = 0;

			// create the wall
			CGameObjectManager::Instance()->AddWall(m_CurrWallFrom, to);

			// draw
			CGameObjectManager::Instance()->GetWalls(m_Walls);
			ManualObject* m = CEditorHelper::Draw3D_Line(
				m_Walls[m_Walls.size() -1]->GetFrom(), m_Walls[m_Walls.size() -1]->GetTo(), ColourValue::Red, m_WallMatNameRed);

			if(m)
				m_WallManObjs.push_back(m);

		}
	}
}

void CObjectsMenu::DrawDynamicLine(f32 width, f32 height)
{
	Vector3 pos = CEditorHelper::FindY(width, height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{
		if(m_WallManObj)
		{
			m_WallManObj->clear();
			m_WallManObj->begin(m_WallMatNameWhite, RenderOperation::OT_LINE_LIST);
			m_WallManObj->position(m_CurrWallFrom);
			m_WallManObj->position(pos);
			m_WallManObj->end();
		}
		else
		{
			m_WallManObj = CEditorHelper::Draw3D_Line(m_CurrWallFrom, pos, ColourValue::White, m_WallMatNameWhite);
		}
	}
}

void CObjectsMenu::PlaceObsSphere(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{
		CEditorHelper::AddObstacleSphere(pos);
	}

	if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) ||
		CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
	{
		isPlaceObsSphere_Click = true;
	}
	else
	{
		isPlaceObsSphere_Click = false;
	}
}

void CObjectsMenu::PlaceInventoryItem(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height) + Vector3(0, 3, 0);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{
		CItemsManager::Instance()->PlaceItem(ItemName.c_str(), pos);
	}

	if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) ||
		CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
	{
		isPlaceInventoryItem = true;
	}
	else
	{
		isPlaceInventoryItem = false;
	}
}

void CObjectsMenu::PlacePlayer(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{		
		String value = cmbPlayers->getCaption().asUTF8();
		if(value == "")
			return;
		else
			curr_player = CGameObjectManager::Instance()->CreatePlayer(value.c_str(), EPT_TEAM_1, "", m_Physics, false);

		if(curr_player)
		{
			curr_player->SetPlayerPosition(pos);
			m_Players.push_back(curr_player);
		}
	}

	if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) ||
		CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
	{
		isPlacePlayer = true;
	}
	else
	{
		isPlacePlayer = false;
	}
}

void CObjectsMenu::AddSound(f32 Width, f32 Height)
{
	using namespace Sound;
	static int soundCounter = 0;
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{
		// Create a lookup name for the sound
		String name;
		auto index = SoundFile.rfind(".", SoundFile.size());
		if(index != -1)
			name = SoundFile.substr(0, index);
		else
			name = SoundFile;

		name += StringConverter::toString(soundCounter++);
		transform(name.begin(), name.end(), name.begin(), toupper);

		CSound* sound = nullptr;
		if(CSoundManager::Instance()->HasSound(SoundFile.c_str()))
			sound = CSoundManager::Instance()->GetSound(SoundFile.c_str());
		else
			sound = CSoundManager::Instance()->CreateSound(name, SoundFile);
		if(sound)
		{
			sound->SetLoop(false);
			sound->SoundEvent_OnPlay = sound_event;
			sound->Play();

			SOUND_OBJ obj;
			CEditorHelper::CreateSoundObject(pos, obj);
			obj.SoundName = name;
			//obj.Node->attachObject(sound);
			sound->SetPosition(obj.Node->getPosition());
			CRuntimeEditorManager::Instance()->AddSoundObject(obj);
		}

	}
	isAddSound = false;
}

bool CObjectsMenu::MouseMoved(const CInputMouseEvent &arg)
{
	if(isAddWall_Click && m_WallCounter > 0)
	{
		DrawDynamicLine(f32(arg.width), f32(arg.height));
	}

	if(!isMouseReleased)
	{
	}

	return true;
}

bool CObjectsMenu::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	isMouseReleased = false;
	Ray ray;
	CInputManager::Instance()->GetMouseRay(ray);
	dragBeginPoint = Nature::CNatureManager::Instance()->GetTerrainPosition(ray);

	// Don't respond if we are controlling a player
	if(!CMenuDirector::Instance()->isPaused && CGameObjectManager::Instance()->GetHumanPlayer())
		return true;

	// Check if we are testing a ray first
	if(CMenuDirector::Instance()->isRayTest)
	{
		// Pick middle of the screen
		Ray pickRay = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(0.5, 0.5);

		SPhysicsRayCastReport report;
		CPhysicsManager::Instance()->GetStrategy()->RaycastClosestShape(pickRay.getOrigin(), pickRay.getDirection() * 1000, report);
		if(report.BodyType == Physics::GAME_OBJECT && report.Data)
		{
			txtFirstRayTest->setCaption(static_cast<CGameObject*>(report.Data)->Name.c_str());
		}
		else if(report.BodyType == Physics::PLAYER && report.Data)
		{
			txtFirstRayTest->setCaption(static_cast<CPlayer*>(report.Data)->GetName());
		}
		return true;
	}

	if(CEditorHelper::FindSelected(f32(arg.width), f32(arg.height), m_Selected))
	{
		if(m_Selected.Selected)
		{
			if(m_Selected.Type == ST_PLAYER)
			{
				CPlayer* player = static_cast<CPlayer*>(m_Selected.Selected);
				CMenuDirector::Instance()->SetPlayerPropMenuView(true, player);
			}
			else if(m_Selected.Type == ST_PATH)
			{
				auto obj = static_cast<CGameObject*>(m_Selected.Selected);
				char* name = nullptr;
				Vector<Vector3> path;
				CCharacterStateManager::Instance()->GetPathByPoint(obj->Node->getPosition(), path, &name);
			}
			else if(m_Selected.Type == ST_OBJ)
			{
				auto obj = static_cast<CGameObject*>(m_Selected.Selected);
				CMenuDirector::Instance()->SetMeshMenuView(true, m_Selected, obj);
			}
			else if(m_Selected.Type == ST_BUILDING)
			{
				auto obj = static_cast<CBuilding*>(m_Selected.Selected);
				CMenuDirector::Instance()->SetBuildingMenuVisible(true, m_Selected, obj);
			}
			else if(m_Selected.Type == ST_SPAWN_POINT)
			{
				CGameObject* obj = static_cast<CGameObject*>(m_Selected.Selected);
				CMenuDirector::Instance()->SetSpawnPointsMenuVisible(true, m_Selected, obj);
			}
			else if(m_Selected.Type == ST_SOUND_ENTITY)
			{
				Entity* entity = static_cast<Entity*>(m_Selected.Selected);
				SOUND_OBJ* obj = CRuntimeEditorManager::Instance()->GetSoundObject(entity->getName().c_str());
				if(obj)
				{
					obj->Node->showBoundingBox(true);
					CMenuDirector::Instance()->SetSoundPropMenuView(true, obj);
				}
			}
			else if(m_Selected.Type == ST_LIGHT)
			{
				if(m_Selected.Selected)
				{
					auto obj = static_cast<CGameObject*>(m_Selected.Selected);
					if(obj)
					{
						CMenuDirector::Instance()->SetLightMenuVisible(true, m_Selected, obj);
					}
				}
			}
		}
	}
	else if(isPlaceObsBox_Click)
	{
		PlaceObsBox(f32(arg.width), f32(arg.height));
	}
	else if(isAddPathPoint_Click)
	{
		AddPathPoint(f32(arg.width), f32(arg.height));
	}
	else if(isAddWall_Click)
	{
		AddWall(f32(arg.width), f32(arg.height));
	}
	else if(isPlaceInventoryItem)
	{
		PlaceInventoryItem(f32(arg.width), f32(arg.height));
	}
	else if(isAddSound)
	{
		AddSound(f32(arg.width), f32(arg.height));
	}
	else if(isPlaceObsSphere_Click)
	{
		PlaceObsSphere(f32(arg.width), f32(arg.height));
	}
	else if(isPlacePlayer)
	{
		PlacePlayer(f32(arg.width), f32(arg.height));
	}
	else
	{

	}
	return true;
}

bool CObjectsMenu::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	isMouseReleased = true;
	return true;
}

bool CObjectsMenu::KeyPressed(const CInputKeyEvent &arg)
{
	return true;
}

bool CObjectsMenu::KeyReleased(const CInputKeyEvent &arg)
{
	// Don't respond if we are controlling a player
	if(!CMenuDirector::Instance()->isPaused && CGameObjectManager::Instance()->GetHumanPlayer())
		return true;

	if(arg.KeyCode == KC_LSHIFT || arg.KeyCode == KC_RSHIFT)
	{
		if(isAddPathPoint_Click)
		{
			// We are done, save to the characater manager
			isAddPathPoint_Click = false;
			String name = String("path_") + StringConverter::toString(path_count);
			CCharacterStateManager::Instance()->AddPath(name.c_str(), PathPoints);
			path_count++;
			PathPoints.clear();
			PopulatePathsList();
		}
		isPlacePlayer = false;
		isPlaceObsBox_Click = false;	
		isPlaceObsSphere_Click = false;
		isAddPathPoint_Click = false;	
		isAddWall_Click = false;		
		isPlaceInventoryItem = false;					
		isAddSound = false;	
	}

	return true;
}

void CObjectsMenu::DrawSelectionBox()
{
	auto width = CGameManager::Instance()->GetRenderWindow()->getWidth();
	auto height = CGameManager::Instance()->GetRenderWindow()->getHeight();

	Ray ray;
	CInputManager::Instance()->GetMouseRay(ray);
	auto terrainPointer = Nature::CNatureManager::Instance()->GetTerrainPosition(ray);

	auto camPos = CCameraManager::Instance()->GetCameraPos();
	auto elementSize = max<f32>((camPos - dragBeginPoint).length(), (camPos - terrainPointer).length()) / 500.0;

	Vector3 nextBoxCorner2;
	nextBoxCorner2.x = terrainPointer.x;
	nextBoxCorner2.z = dragBeginPoint.z;
	DrawTerrainLine(dragBeginPoint, nextBoxCorner2, rayLine1, elementSize);

	auto nextBoxCorner1 = terrainPointer;
	DrawTerrainLine(nextBoxCorner1, nextBoxCorner2, rayLine2, elementSize);

	nextBoxCorner2.x = dragBeginPoint.x;
	nextBoxCorner2.z = terrainPointer.z;
	DrawTerrainLine(nextBoxCorner1, nextBoxCorner2, rayLine3, elementSize);

	nextBoxCorner1 = dragBeginPoint;
	DrawTerrainLine(nextBoxCorner1, nextBoxCorner2, rayLine4, elementSize);
}

void CObjectsMenu::DrawTerrainLine(Vector3 lineEnd1, Vector3 lineEnd2, BillboardChain* billboardChain, f32 elementWidth)
{
	// don't assume the Y component is correct
	lineEnd1.y = Nature::CNatureManager::Instance()->GetTerrainHeightAt(lineEnd1.x, lineEnd1.z);
	lineEnd2.y = Nature::CNatureManager::Instance()->GetTerrainHeightAt(lineEnd2.x, lineEnd2.z);

	auto chainElementCount = billboardChain->getNumChainElements(0);
	auto distBetweenElements = (lineEnd2 - lineEnd1) / chainElementCount;
	auto nextBillboardElementPosition = lineEnd1;
	for (int i = 0; i < 10; i++)
	{
		billboardChain->addChainElement(0, BillboardChain::Element(nextBillboardElementPosition, elementWidth, i / 100.0f, ColourValue(1.0f, 1.0, 1.0), Quaternion::IDENTITY));
		nextBillboardElementPosition += distBetweenElements;
		nextBillboardElementPosition.y = 
			Nature::CNatureManager::Instance()->GetTerrainHeightAt(nextBillboardElementPosition.x, nextBillboardElementPosition.z) + 0.01f;
	}

	billboardChain->setVisible(true);
}