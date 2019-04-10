#include "CBuildingMenu.h"
#include "IO/CFileSystem.h"
#include "CEditorHelper.h"
#include "CGameManager.h"
#include "CMenuDirector.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsManager.h"
#include "CGameObjectManager.h"
#include "CInputManager.h"
#include "CBuilding.h"
#include "AI/CFpsVehicle.h"
#include "CPlayer.h"
#include "CInputEvent.h"

// Gui
#include "MyGui/MyGUI.h"
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

CBuildingMenu::CBuildingMenu(GUI::CGuiStrategy_MyGui* Strategy) : m_Strategy(Strategy)
{
	Strategy->AssignWidget(frmBuilding, "frmBuilding");
	Strategy->AssignWidget(cmbBuildingList, "cmbBuildingList");
	Strategy->AssignWidget(rdoBuildingSphereObstacle, "rdoBuildingSphereObstacle");
	Strategy->AssignWidget(rdoBuildingBoxObstacle, "rdoBuildingBoxObstacle");
	Strategy->AssignWidget(btnBuildingPlace, "btnBuildingPlace");
	Strategy->AssignWidget(btnBuildingClose, "btnBuildingClose");
	Strategy->AssignWidget(cmbBuildingType, "cmbBuildingType");
	Strategy->AssignWidget(txtBuildingName, "txtBuildingName");
	Strategy->AssignWidget(btnBuildingCancel, "btnBuildingCancel");
	Strategy->AssignWidget(btnBuildingSave, "btnBuildingSave");
	Strategy->AssignWidget(txtBuildingPosX, "txtBuildingPosX");
	Strategy->AssignWidget(txtBuildingPosY, "txtBuildingPosY");
	Strategy->AssignWidget(txtBuildingPosZ, "txtBuildingPosZ");
	Strategy->AssignWidget(txtBuildingScaleX, "txtBuildingScaleX");
	Strategy->AssignWidget(txtBuildingScaleY, "txtBuildingScaleY");
	Strategy->AssignWidget(txtBuildingScaleZ, "txtBuildingScaleZ");
	Strategy->AssignWidget(cmbBuildingTeam, "cmbBuildingTeam");
	
	cmbBuildingList->eventComboChangePosition = MyGUI::newDelegate(this, &CBuildingMenu::cmbBuildingList_ComboAccept);
	rdoBuildingSphereObstacle->eventMouseButtonClick = MyGUI::newDelegate(this, &CBuildingMenu::rdoBuildingSphereObstacle_Click);
	rdoBuildingBoxObstacle->eventMouseButtonClick = MyGUI::newDelegate(this, &CBuildingMenu::rdoBuildingBoxObstacle_Click);
	btnBuildingPlace->eventMouseButtonClick = MyGUI::newDelegate(this, &CBuildingMenu::btnBuildingPlace_Click);
	btnBuildingClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CBuildingMenu::btnBuildingClose_Click);
	cmbBuildingType->eventComboChangePosition = MyGUI::newDelegate(this, &CBuildingMenu::cmbBuildingType_ComboAccept);
	btnBuildingCancel->eventMouseButtonClick = MyGUI::newDelegate(this, &CBuildingMenu::btnBuildingCancel_Click);
	btnBuildingSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CBuildingMenu::btnBuildingSave_Click);
	cmbBuildingTeam->eventComboChangePosition = MyGUI::newDelegate(this, &CBuildingMenu::cmbBuildingTeam_ComboAccept);
	
	PopulateMeshList();
	PopulateTypeList();

	rdoBuildingSphereObstacle->setEnabled(false);
	rdoBuildingBoxObstacle->setEnabled(false);
	
	isPlaceMesh = false;
	m_Building = nullptr;

	// Populate cmbBuildingTeam 
	cmbBuildingTeam->removeAllItems();
	for(u32 i = 1; i < NUM_TEAMS + 1; i++)
		cmbBuildingTeam->addItem(StringConverter::toString(i));
}

CBuildingMenu::~CBuildingMenu()
{
}

bool CBuildingMenu::MouseMoved(const CInputMouseEvent &arg)
{
	return true;
}

bool CBuildingMenu::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(isPlaceMesh)
		PlaceMesh(f32(arg.width), f32(arg.height));
	return true;
}

bool CBuildingMenu::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	return true;
}

bool CBuildingMenu::KeyPressed(const CInputKeyEvent &arg)
{
	if(arg.KeyCode == KC_DELETE)
	{
		if(m_Building)
		{
			CGameObjectManager::Instance()->RemoveBuilding(m_Building);
			m_Building = nullptr;
		}
	}
	return true;
}

bool CBuildingMenu::KeyReleased(const CInputKeyEvent &arg)
{
	return true;
}

void CBuildingMenu::cmbBuildingList_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CBuildingMenu::rdoBuildingSphereObstacle_Click(MyGUI::WidgetPtr _sender)
{
}

void CBuildingMenu::rdoBuildingBoxObstacle_Click(MyGUI::WidgetPtr _sender)
{
}

void CBuildingMenu::btnBuildingPlace_Click(MyGUI::WidgetPtr _sender)
{
	isPlaceMesh = true;
}

void CBuildingMenu::btnBuildingClose_Click(MyGUI::WidgetPtr _sender)
{
	Close();
}

void CBuildingMenu::cmbBuildingType_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CBuildingMenu::btnBuildingCancel_Click(MyGUI::WidgetPtr _sender)
{
	Close();
}

void CBuildingMenu::btnBuildingSave_Click(MyGUI::WidgetPtr _sender)
{
	Save();
}

void CBuildingMenu::cmbBuildingTeam_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
	if(m_Building)
	{
		String value = cmbBuildingTeam->getItemNameAt(_index).asUTF8();
		E_PLAYER_TEAM team = (E_PLAYER_TEAM)StringConverter::parseUnsignedInt(value);
		if(team != m_Building->GetTeam())
		{
			m_Building->SetTeam(team);
			if(m_Building->GetAiTarget())
			{
				if(m_Building->GetAiTarget()->GetPlayer()->GetPlayerTeam() == m_Building->GetTeam())
				{
					m_Building->SetAiTarget(nullptr);
				}
			}
		}
	}
}

void CBuildingMenu::PopulateMeshList()
{
	cmbBuildingList->removeAllItems();
	Vector<const char*> list;
	CGameObjectManager::Instance()->GetAllBuildingTypes(list);
	for(u32 i = 0; i < list.size(); i++)
	{
		cmbBuildingList->addItem(list[i]);
	}
}

void CBuildingMenu::ResetControls()
{
	// Might not be a static list so load it just in case every time
	PopulateMeshList();
	cmbBuildingList->setOnlyText("");
	txtBuildingName->setOnlyText("");
}

void CBuildingMenu::PlaceMesh(f32 Width, f32 Height)
{
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{		
		String value = cmbBuildingList->getCaption().asUTF8();
		if(value.length() > 0)
		{
			m_Building = CGameObjectManager::Instance()->CreateBuilding(value.c_str(), EPT_TEAM_1, "", Physics::CPhysicsManager::Instance()->GetStrategy());	
			if(m_Building)
			{
				m_Building->SetPosition(pos);
				txtBuildingPosX->setCaption(StringConverter::toString(pos.x));
				txtBuildingPosY->setCaption(StringConverter::toString(pos.y));
				txtBuildingPosZ->setCaption(StringConverter::toString(pos.z));
			}
		}
	}

	if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) ||
		CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
	{
		isPlaceMesh = true;
	}
	else
	{
		isPlaceMesh = false;
	}
}

void CBuildingMenu::Close()
{
	if(m_Building)
	{
		m_Building->GetNode()->showBoundingBox(false);
	}

	isPlaceMesh = false;
	CMenuDirector::Instance()->SetBuildingMenuVisible(false);
	m_Building = nullptr;
	m_Selected.Type = ST_NONE;
}

void CBuildingMenu::SetVisible(bool Visible)
{
	if(Visible && frmBuilding->getVisible())
	{
		return;
	}
	else if(Visible)
	{
		ResetControls();
	}

	if(!Visible && m_Building)
		m_Building->GetNode()->showBoundingBox(false);

	frmBuilding->setVisible(Visible);
	isPlaceMesh = false;
}

void CBuildingMenu::SetVisible(bool Visible, const SELECTED& Selected, CBuilding* Building)
{
	if(Visible && frmBuilding->getVisible())
		return;

	if(Visible && Building)
	{
		m_Building = Building;
		m_Selected = Selected;

		PopulateMeshList();				// Might not be a static list so load it just in case every time

		//cmbBuildingList->setOnlyText(m_Building->GetName());	// Mesh
		txtBuildingName->setOnlyText(m_Building->GetName());		// Name

		// Populate controls
		if(m_Building)
		{
			// Position
			Vector3 pos = m_Building->GetNode()->getPosition();
			txtBuildingPosX->setCaption(StringConverter::toString(pos.x));
			txtBuildingPosY->setCaption(StringConverter::toString(pos.y));
			txtBuildingPosZ->setCaption(StringConverter::toString(pos.z));

			// Scale
			Vector3 scale = m_Building->GetNode()->getScale();
			txtBuildingScaleX->setCaption(StringConverter::toString(scale.x));
			txtBuildingScaleY->setCaption(StringConverter::toString(scale.y));
			txtBuildingScaleZ->setCaption(StringConverter::toString(scale.z));

			// Building type
			auto type = m_Building->GetCategory();
			cmbBuildingType->setIndexSelected((int)type);		
		}

		// Show the bounding box
		m_Building->GetNode()->showBoundingBox(true);
	}
	else if(Visible && !m_Building)
	{
		ResetControls();
	}

	if(!Visible && m_Building)
	{
		m_Building = nullptr;
	}

	frmBuilding->setVisible(Visible);
	isPlaceMesh = false;
}

void CBuildingMenu::Save()
{
	// Update position
	Vector3 pos;
	if(txtBuildingPosX->getCaption() != "" &&
		txtBuildingPosY->getCaption() != "" &&
		txtBuildingPosZ->getCaption() != "")
	{
		pos.x = StringConverter::parseReal(txtBuildingPosX->getCaption());
		pos.y = StringConverter::parseReal(txtBuildingPosY->getCaption());
		pos.z = StringConverter::parseReal(txtBuildingPosZ->getCaption());
		m_Building->SetPosition(pos);
	}

	// Update scale
	Vector3 scale = m_Building->GetNode()->getPosition();
	if(txtBuildingScaleX->getCaption() != "" &&
		txtBuildingScaleY->getCaption() != "" &&
		txtBuildingScaleZ->getCaption() != "")
	{
		scale.x = StringConverter::parseReal(txtBuildingScaleX->getCaption());
		scale.y = StringConverter::parseReal(txtBuildingScaleY->getCaption());
		scale.z = StringConverter::parseReal(txtBuildingScaleZ->getCaption());
		m_Building->GetNode()->setScale(scale);
	}

	// Update type
	auto type = cmbBuildingType->getOnlyText();
	if(type == "Supply")
		m_Building->SetCategory(EBC_SUPPLY);
	else if(type == "Training")
		m_Building->SetCategory(EBC_TRAINING);
	else if(type == "Prop")
		m_Building->SetCategory(EBC_PROP);
	else if(type == "Defence")
		m_Building->SetCategory(EBC_DEFENCE);
	else
		m_Building->SetCategory(EBC_OTHER);

	// Update building attributes
	if(m_Selected.Type != ST_NONE && m_Building)
	{
	}

	m_Strategy->ShowMessageBox("General properties saved.", "Done");
}

void CBuildingMenu::PopulateTypeList()
{
	cmbBuildingType->removeAllItems();
	cmbBuildingType->addItem("Supply", 0);
	cmbBuildingType->addItem("Training", 1);
	cmbBuildingType->addItem("Prop", 2);
	cmbBuildingType->addItem("Defence", 3);
	cmbBuildingType->addItem("Other", 4);
}