#include "CMeshMenu.h"
#include "IO/CFileSystem.h"
#include "CEditorHelper.h"
#include "CGameManager.h"
#include "CGameObject.h"
#include "CMenuDirector.h"
#include "CPhysicsManager.h"
#include "IPhysicsStrategy.h"
#include "RuntimeEditor/CRuntimeEditorManager.h"
#include "CGameObjectManager.h"
#include "CInputManager.h"
#include "CCharacterStateManager.h"
#include "CInputEvent.h"

// Gui
#include "IGuiStrategy.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

// Ogre
#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreRenderWindow.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::Editor;

CMeshMenu::CMeshMenu(GUI::CGuiStrategy_MyGui* Strategy) : m_Strategy(Strategy)
{
	Strategy->AssignWidget(frmMesh, "frmMesh");
	Strategy->AssignWidget(cmbMeshList, "cmbMeshList");
	Strategy->AssignWidget(rdoMeshSphereObstacle, "rdoMeshSphereObstacle");
	Strategy->AssignWidget(rdoMeshBoxObstacle, "rdoMeshBoxObstacle");
	Strategy->AssignWidget(chkMeshRandom, "chkMeshRandom");
	Strategy->AssignWidget(txtMeshCount, "txtMeshCount");
	Strategy->AssignWidget(btnMeshPlace, "btnMeshPlace");
	Strategy->AssignWidget(btnMeshClose, "btnMeshClose");
	Strategy->AssignWidget(txtMeshMinX, "txtMeshMinX");
	Strategy->AssignWidget(txtMeshMinZ, "txtMeshMinZ");
	Strategy->AssignWidget(txtMeshMaxX, "txtMeshMaxX");
	Strategy->AssignWidget(txtMeshMaxZ, "txtMeshMaxZ");
	Strategy->AssignWidget(cmbMeshEnvAtt, "cmbMeshEnvAtt");
	Strategy->AssignWidget(txtGameObjectName, "txtGameObjectName");

	Strategy->AssignWidget(txtGenPropPosX, "txtGenPropPosX");
	Strategy->AssignWidget(txtGenPropPosY, "txtGenPropPosY");
	Strategy->AssignWidget(txtGenPropPosZ, "txtGenPropPosZ");
	Strategy->AssignWidget(txtGenPropScaleX, "txtGenPropScaleX");
	Strategy->AssignWidget(txtGenPropScaleY, "txtGenPropScaleY");
	Strategy->AssignWidget(txtGenPropScaleZ, "txtGenPropScaleZ");
	Strategy->AssignWidget(btnPropertiesCancel, "btnPropertiesCancel");
	Strategy->AssignWidget(btnPropertiesSave, "btnPropertiesSave");
	Strategy->AssignWidget(cmbGOPhysicsProfile, "cmbGOPhysicsProfile");
	
	cmbMeshList->eventComboChangePosition = MyGUI::newDelegate(this, &CMeshMenu::cmbMeshList_ComboAccept);
	rdoMeshSphereObstacle->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshMenu::rdoMeshSphereObstacle_Click);
	rdoMeshBoxObstacle->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshMenu::rdoMeshBoxObstacle_Click);
	chkMeshRandom->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshMenu::chkMeshRandom_Click);
	btnMeshPlace->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshMenu::btnMeshPlace_Click);
	btnMeshClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshMenu::btnMeshClose_Click);
	cmbMeshEnvAtt->eventComboChangePosition = MyGUI::newDelegate(this, &CMeshMenu::cmbMeshEnvAtt_ComboAccept);

	btnPropertiesCancel->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshMenu::btnPropertiesCancel_Click);
	btnPropertiesSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CMeshMenu::btnPropertiesSave_Click);
	
	PopulateMeshList();
	
	isPlaceMesh = false;
	m_GameObject = nullptr;
}

CMeshMenu::~CMeshMenu()
{
}

void CMeshMenu::cmbMeshList_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CMeshMenu::rdoMeshSphereObstacle_Click(MyGUI::Widget* _sender)
{
	rdoMeshSphereObstacle->setStateSelected(!rdoMeshSphereObstacle->getStateSelected());
}

void CMeshMenu::rdoMeshBoxObstacle_Click(MyGUI::Widget* _sender)
{
}

void CMeshMenu::chkMeshRandom_Click(MyGUI::Widget* _sender)
{
	chkMeshRandom->setStateSelected(!chkMeshRandom->getStateSelected());
	txtMeshCount->setEnabled(chkMeshRandom->getStateSelected());
	btnMeshPlace->setEnabled(chkMeshRandom->getStateSelected());
	btnMeshClose->setEnabled(chkMeshRandom->getStateSelected());
	txtMeshMinX->setEnabled(chkMeshRandom->getStateSelected()); 
	txtMeshMinZ->setEnabled(chkMeshRandom->getStateSelected()); 
	txtMeshMaxX->setEnabled(chkMeshRandom->getStateSelected()); 
	txtMeshMaxZ->setEnabled(chkMeshRandom->getStateSelected()); 
}

void CMeshMenu::btnMeshPlace_Click(MyGUI::Widget* _sender)
{	
	// Are we placing a bunch of random stuff
	if(chkMeshRandom->getStateSelected())
		PlaceRandomMesh((f32)CGameManager::Instance()->GetRenderWindow()->getWidth(), 
						(f32)CGameManager::Instance()->GetRenderWindow()->getHeight());
	else
		isPlaceMesh = true;
}

void CMeshMenu::btnMeshClose_Click(MyGUI::Widget* _sender)
{
	Close();
}

void CMeshMenu::btnPropertiesCancel_Click(MyGUI::Widget* _sender)
{	
	Close();
}

void CMeshMenu::btnPropertiesSave_Click(MyGUI::Widget* _sender)
{
	Save();
}

bool CMeshMenu::MouseMoved(const CInputMouseEvent &arg)
{
	return true;
}

bool CMeshMenu::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(isPlaceMesh)
		PlaceMesh(f32(arg.width), f32(arg.height));
	return true;
}

bool CMeshMenu::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	return true;
}

bool CMeshMenu::KeyPressed(const CInputKeyEvent &arg)
{
	if(arg.KeyCode == KC_DELETE)
	{
		if(m_GameObject)
		{
			CGameObjectManager::Instance()->RemoveGameObject(m_GameObject);
			m_GameObject = nullptr;
		}
	}
	return true;
}

bool CMeshMenu::KeyReleased(const CInputKeyEvent &arg)
{
	return true;
}

void CMeshMenu::cmbMeshEnvAtt_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

ENVIRONMENT_ATTRIBUTE_TYPE CMeshMenu::GetEnvironmentAttributeType()
{
	ENVIRONMENT_ATTRIBUTE_TYPE ret = EAT_NONE;
	String value = cmbMeshEnvAtt->getOnlyText();
	if(value == "Pickup")
		ret = EAT_PICKUP;
	else if(value == "Dangerous")
		ret = EAT_DANGEROUS;
	else if(value == "Neutral")
		ret = EAT_NEUTRAL;
	else if(value == "Mission")
		ret = EAT_MISSION;
	else if(value == "Unknown")
		ret = EAT_UNKNOWN;
	return ret;
}

void CMeshMenu::PopulateMeshList()
{
	cmbMeshList->removeAllItems();
	Vector<const char*> list;
	CGameObjectManager::Instance()->GetAllObjectTypes(list);
	for(u32 i = 0; i < list.size(); i++)
	{
		cmbMeshList->addItem(list[i]);
	}
}

void CMeshMenu::PopulationPhysicsProfiles()
{
	cmbGOPhysicsProfile->removeAllItems();
	Physics::PhysicsProfileList list;
	Physics::CPhysicsManager::Instance()->GetPhysicsProfileList(list);
	for(auto it = list.cbegin(); it != list.cend(); it++)
	{
		cmbGOPhysicsProfile->addItem((*it).first.c_str());
	}
}

void CMeshMenu::ResetControls()
{
	// Might not be a static list so load it just in case every time
	PopulateMeshList();
	cmbMeshList->setOnlyText("");
	cmbGOPhysicsProfile->setOnlyText("");
	txtGameObjectName->setOnlyText("");
	cmbMeshEnvAtt->setOnlyText("");
	PopulationPhysicsProfiles();
}

String CMeshMenu::GetEnvironmentAttributeType(ENVIRONMENT_ATTRIBUTE_TYPE Type)
{
	String ret = "None";
	if(Type == EAT_PICKUP)
		ret = "Pickup";
	else if(Type == EAT_DANGEROUS)
		ret = "Dangerous";
	else if(Type == EAT_NEUTRAL)
		ret = "Neutral";
	else if(Type == EAT_MISSION)
		ret = "Mission";
	else if(Type == EAT_UNKNOWN)
		ret = "Unknown";
	return ret;
}

void CMeshMenu::PlaceMesh(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y &&
		cmbMeshList->getCaption().asUTF8() != "")
	{		
		auto obj = CGameObjectManager::Instance()->CreateObject(cmbMeshList->getCaption().asUTF8().c_str());
		if(obj)
		{
			obj->EnvironmentType = GetEnvironmentAttributeType();
			obj->SetPosition(pos);
			obj->Name = txtGameObjectName->getOnlyText();
			CGameObjectManager::Instance()->AddBoxObstacle(obj);

			// Hide bounding box of existing object
			if(m_GameObject)
				m_GameObject->Node->showBoundingBox(false);

			m_GameObject = obj;

			// Show bounding box of new object
			m_GameObject->Node->showBoundingBox(true);

			// Set our selected object type
			m_Selected.Type = ST_OBJ;
		}
	}

	// Set position text boxes
	if(m_GameObject)
	{
		Vector3 pos = m_GameObject->Node->getPosition();
		txtGenPropPosX->setCaption(StringConverter::toString(pos.x));
		txtGenPropPosY->setCaption(StringConverter::toString(pos.y));
		txtGenPropPosZ->setCaption(StringConverter::toString(pos.z));
	}

	if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) || CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
	{
		isPlaceMesh = true;
	}
	else
	{
		isPlaceMesh = false;
	}
}

void CMeshMenu::PlaceRandomMesh(f32 Width, f32 Height)
{
	// TODO: missing: yaw, scale, BatchMax, BatchStart, ImposterMax, ImposterStart, PageSize, GeoType
	// Validate our input
	f32 MeshMinX = 0;
	f32 MeshMinZ = 0;
	f32 MeshMaxX = 0;
	f32 MeshMaxZ = 0;
	f32 Count = 0;
	if(txtMeshMinX->getOnlyText().length() > 0)
	{
		MeshMinX = StringConverter::parseReal(txtMeshMinX->getOnlyText());
		if(MeshMinX == 0)
			return;
	}
	
	if(txtMeshMinZ->getOnlyText().length() > 0)
	{
		MeshMinZ = StringConverter::parseReal(txtMeshMinZ->getOnlyText());
		if(MeshMinZ == 0)
			return;
	}
	
	if(txtMeshMaxX->getOnlyText().length() > 0)
	{
		MeshMaxX = StringConverter::parseReal(txtMeshMaxX->getOnlyText());
		if(MeshMaxX == 0)
			return;
	}
	
	if(txtMeshMaxZ->getOnlyText().length() > 0)
	{
		MeshMaxZ = StringConverter::parseReal(txtMeshMaxZ->getOnlyText());
		if(MeshMaxZ == 0)
			return;
	}
	
	if(txtMeshCount->getOnlyText().length() > 0)
	{
		Count = StringConverter::parseReal(txtMeshCount->getOnlyText());
		if(Count <= 0)
			return;
	}
	
	// Count how many has an invalid y axis
	u32 invalidCount = 0;
	
	if(cmbMeshList->getCaption().asUTF8() != "")
	{
		String ObjectType = String(cmbMeshList->getCaption().asUTF8().c_str());
		Vector<Vector3> list = CEditorHelper::RandomMeshPlacerOnY_Terrain(ObjectType, MeshMaxZ, MeshMinZ, MeshMaxX, MeshMinX, (u32)Count);
			
		PAGED_GEO pg;
		pg.ObjectType = ObjectType;
		pg.GeoSet.BatchMax = Count;
		pg.GeoSet.Entity = 0;
		pg.GeoSet.HeightMax = MeshMaxZ;
		pg.GeoSet.HeightMin = MeshMinZ;
		pg.GeoSet.WidthMax = MeshMaxX;
		pg.GeoSet.WidthMin = MeshMinX;
		
		for(u32 i = 0; i < list.size(); i++)
		{
			if(list[i].y == -9999)
			{
				invalidCount++;
			}
			else
			{
				GEO_SET_SUBSET set;
				set.Position = list[i];
				pg.GeoSet.Objects.push_back(set);
			}
		}
		
		m_PagedGeos.push_back(pg);
		
		if(invalidCount > 0)
		{
			String msg = "Invalid Y axis count: " + StringConverter::toString(invalidCount);
			m_Strategy->ShowMessageBox(msg.c_str(), "Note");
		}
	}
}

void CMeshMenu::Close()
{
	isPlaceMesh = false;
	CMenuDirector::Instance()->SetMeshMenuView(false);
	m_GameObject = nullptr;
	m_Selected.Type = ST_NONE;
}

void CMeshMenu::SavePagedGeometry()
{
	for(u32 i = 0; i < m_PagedGeos.size(); i++)
	{
		CRuntimeEditorManager::Instance()->WritePagedGeometry(m_PagedGeos[i]);
	}
}

void CMeshMenu::SetVisible(bool Visible)
{
	if(Visible && frmMesh->getVisible())
	{
		return;
	}
	else if(Visible)
	{
		ResetControls();
	}

	if(!Visible && m_GameObject)
		m_GameObject->Node->showBoundingBox(false);

	frmMesh->setVisible(Visible);
	isPlaceMesh = false;
}

void CMeshMenu::SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	if(Visible && frmMesh->getVisible())
		return;

	if(Visible && GameObject)
	{
		m_GameObject = GameObject;		// Set our game object
		m_Selected = Selected;			// Set our selected type

		PopulateMeshList();				// Might not be a static list so load it just in case every time
		PopulationPhysicsProfiles();

		cmbMeshList->setOnlyText(GameObject->GameObjectType);	// Mesh
		txtGameObjectName->setOnlyText(GameObject->Name);		// Name
		cmbMeshEnvAtt->setOnlyText(GetEnvironmentAttributeType(GameObject->EnvironmentType));	// Environment Attribute

		// Set position text boxes
		if(m_GameObject)
		{
			Vector3 pos = m_GameObject->Node->getPosition();
			txtGenPropPosX->setCaption(StringConverter::toString(pos.x));
			txtGenPropPosY->setCaption(StringConverter::toString(pos.y));
			txtGenPropPosZ->setCaption(StringConverter::toString(pos.z));
		}

		// Show the bounding box
		m_GameObject->Node->showBoundingBox(true);
	}
	else if(Visible && !GameObject)
	{
		ResetControls();
	}

	if(!Visible && m_GameObject)
	{
		m_GameObject = nullptr;
	}

	frmMesh->setVisible(Visible);
	isPlaceMesh = false;
}

void CMeshMenu::Save()
{
	if(!m_GameObject)
	{
		m_Strategy->ShowMessageBox("No model selected.", "Error");
		return;
	}

	// Update position
	Vector3 pos = m_GameObject->Node->getPosition();
	if(txtGenPropPosX->getCaption() != "" &&
		txtGenPropPosY->getCaption() != "" &&
		txtGenPropPosZ->getCaption() != "")
	{
		pos.x = StringConverter::parseReal(txtGenPropPosX->getCaption());
		pos.y = StringConverter::parseReal(txtGenPropPosY->getCaption());
		pos.z = StringConverter::parseReal(txtGenPropPosZ->getCaption());
		m_GameObject->SetPosition(pos);
	}

	// Update game object attributes
	if(m_Selected.Type != ST_NONE && m_GameObject)
	{
		String name =  txtGameObjectName->getOnlyText();
		if(m_Selected.Type == ST_PATH)
		{				
			// Get the old name
			char* oldname = new char;
			Vector<Vector3> path;
			CCharacterStateManager::Instance()->GetPathByPoint(m_GameObject->Node->getPosition(), path, &oldname);
				
			// Change the name
			CCharacterStateManager::Instance()->SetName(oldname, name.c_str());
				
		}
		else if(m_Selected.Type == ST_OBJ)
		{
			// Name
			m_GameObject->Name = name;

			// Update physics profile
			String profileName = cmbGOPhysicsProfile->getCaption();
			if(profileName.length() > 0)
			{
				auto profile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(profileName.c_str());
				if(profile)
				{
					// Remove the physics shape if one is already created
					Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(m_GameObject);

					// Save the profile
					m_GameObject->PhysicsProfile = profile;

					// Add a physics shape
					Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(m_GameObject);
				}
			}
		}
	}

	m_Strategy->ShowMessageBox("General properties saved.", "Done");
}