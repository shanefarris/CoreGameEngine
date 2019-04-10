#include "CSpawnPoints.h"
#include "CGameObjectManager.h"
#include "CGameObject.h"
#include "CSpawnManager.h"
#include "CInputManager.h"
#include "CGuiManager.h"
#include "CUtility.h"
#include "CInputEvent.h"

#include "CEditorHelper.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

// Ogre
#include "OgreSceneNode.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::Editor;

CSpawnPoints::CSpawnPoints(GUI::CGuiStrategy_MyGui* Strategy) : m_Strategy(Strategy)
{
	Strategy->AssignWidget(frmSpawnPoint, "frmSpawnPoint");
	Strategy->AssignWidget(cmbSpawnPoints, "cmbSpawnPoints");
	Strategy->AssignWidget(txtSpawnPointId, "txtSpawnPointId");
	Strategy->AssignWidget(txtSpawnPointX, "txtSpawnPointX");
	Strategy->AssignWidget(txtSpawnPointY, "txtSpawnPointY");
	Strategy->AssignWidget(txtSpawnPointZ, "txtSpawnPointZ");
	Strategy->AssignWidget(cmbSpawnPointTeam, "cmbSpawnPointTeam");
	Strategy->AssignWidget(txtSpawnPointCoolDown, "txtSpawnPointCoolDown");
	Strategy->AssignWidget(btnSpawnPointPlace, "btnSpawnPointPlace");
	Strategy->AssignWidget(btnSpawnPointClose, "btnSpawnPointClose");
	Strategy->AssignWidget(btnSpawnPointUpdate, "btnSpawnPointUpdate");

	cmbSpawnPoints->eventComboChangePosition = MyGUI::newDelegate(this, &CSpawnPoints::cmbSpawnPoints_ComboAccept);
	btnSpawnPointPlace->eventMouseButtonClick = MyGUI::newDelegate(this, &CSpawnPoints::btnSpawnPointPlace_Click);
	btnSpawnPointClose->eventMouseButtonClick = MyGUI::newDelegate(this, &CSpawnPoints::btnSpawnPointClose_Click);
	btnSpawnPointUpdate->eventMouseButtonClick = MyGUI::newDelegate(this, &CSpawnPoints::btnSpawnPointUpdate_Click);

	isPlaceSpawnPoint = false;
	m_GameObject = nullptr;
	txtSpawnPointId->setEnabled(false);
	btnSpawnPointUpdate->setEnabled(false);
}

CSpawnPoints::~CSpawnPoints()
{
}

void CSpawnPoints::cmbSpawnPoints_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
	auto item = *cmbSpawnPoints->getItemDataAt<SPAWN_POINT*>(cmbSpawnPoints->getIndexSelected());
	if(item)
	{
		txtSpawnPointId->setCaption(StringConverter::toString(item->Id));
		txtSpawnPointX->setCaption(StringConverter::toString(item->Position.x));
		txtSpawnPointY->setCaption(StringConverter::toString(item->Position.y));
		txtSpawnPointZ->setCaption(StringConverter::toString(item->Position.z));
		cmbSpawnPointTeam->setIndexSelected((u32)item->Team);
		txtSpawnPointCoolDown->setCaption(StringConverter::toString(item->CoolDown));
	}
	else
	{
		m_Strategy->ShowMessageBox("Error parsing spawn data.", "Error");
	}
}

void CSpawnPoints::btnSpawnPointPlace_Click(MyGUI::WidgetPtr _sender)
{
	isPlaceSpawnPoint = true;
}

void CSpawnPoints::btnSpawnPointClose_Click(MyGUI::WidgetPtr _sender)
{
	SetVisible(false);
}

void CSpawnPoints::btnSpawnPointUpdate_Click(MyGUI::WidgetPtr _sender)
{
}

bool CSpawnPoints::MouseMoved(const CInputMouseEvent &arg)
{
	return true;
}

bool CSpawnPoints::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(isPlaceSpawnPoint)
		PlaceSpawnPoint(f32(arg.width), f32(arg.height));
	return true;
}

bool CSpawnPoints::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	return true;
}

bool CSpawnPoints::KeyPressed(const CInputKeyEvent &arg)
{
	if(arg.KeyCode == KC_DELETE)
	{
		if(m_GameObject)
		{
			CGameObjectManager::Instance()->RemoveGameObject(m_GameObject);
			m_GameObject = nullptr;
		}
	}

	if(arg.KeyCode == KC_LSHIFT || arg.KeyCode == KC_RSHIFT)
	{
		isPlaceSpawnPoint = false;
	}
	return true;
}

bool CSpawnPoints::KeyReleased(const CInputKeyEvent &arg)
{
	return true;
}

void CSpawnPoints::SetVisible(bool Visible)
{
	frmSpawnPoint->setVisible(Visible);
	if(Visible)
		PopulateControls();
}

void CSpawnPoints::SetVisible(bool Visible, const SELECTED& Selected, CGameObject* GameObject)
{
	frmSpawnPoint->setVisible(Visible);
	m_Selected = Selected;
	m_GameObject = GameObject;

	if(Visible)
		PopulateControls();
}

void CSpawnPoints::PlaceSpawnPoint(f32 Width, f32 Height)
{
	// Team selection is required
	E_PLAYER_TEAM team;
	if(cmbSpawnPointTeam->getCaption().length() == 0)
	{
		m_Strategy->ShowMessageBox("Select team first", "Tean Required");
		isPlaceSpawnPoint = false;
		return;
	}
	else
	{
		team = (E_PLAYER_TEAM)cmbSpawnPointTeam->getIndexSelected();
	}

	// Get optional cooldown value
	f32 coolDown = StringConverter::parseReal(txtSpawnPointCoolDown->getCaption());

	auto spawnPoints = CSpawnManager::Instance()->GetAllSpawnPoints();
	Vector3 pos = CEditorHelper::FindY(Width, Height);
	String name = SPAWN_POINT_MESH + StringConverter::toString(spawnPoints.size());
	if(pos != Vector3::NEGATIVE_UNIT_Y)
	{		
		// Create the mesh
		auto obj = CGameObjectManager::Instance()->CreateObject(SPAWN_POINT_MESH, name.c_str(), pos);
		if(obj)
		{
			obj->EnvironmentType = EAT_EDITOR;
			obj->GameObjectType = SPAWN_POINT_MESH;

			// Hide bounding box of existing object
			if(m_GameObject)
				m_GameObject->Node->showBoundingBox(false);

			m_GameObject = obj;

			// Show bounding box of new object
			m_GameObject->Node->showBoundingBox(true);

			// Set our selected object type
			m_Selected.Type = ST_SPAWN_POINT;
		}

		if(CInputManager::Instance()->IsKeyDown(KC_LSHIFT) ||
			CInputManager::Instance()->IsKeyDown(KC_RSHIFT))
		{
			isPlaceSpawnPoint = true;
		}
		else
		{
			isPlaceSpawnPoint = false;
		}

		// Now add the spawn point to the engine
		u32 id = CSpawnManager::Instance()->AddSpawnPoint(pos, team, coolDown);
		if(id > 0)
		{
			String item = StringConverter::toString(id) + String(": ") + StringConverter::toString(pos);
			
			auto spawnPoint = CSpawnManager::Instance()->GetSpawnPoint(id);
			cmbSpawnPoints->addItem(item, spawnPoint);
		}
		else
		{
			m_Strategy->ShowMessageBox("Error creating spawn point.", "Error");
		}
	}
	else
	{
		m_Strategy->ShowMessageBox("Unable to find terrain.", "Error");
	}
}

void CSpawnPoints::PopulateControls()
{
	cmbSpawnPoints->removeAllItems();
	auto spawnPoints = CSpawnManager::Instance()->GetAllSpawnPoints();
	for(auto it = spawnPoints.cbegin(); it != spawnPoints.cend(); it++)
	{
		String item = StringConverter::toString((*it).second->Id) +
					  String(": ") +
					  StringConverter::toString((*it).second->Position);
		cmbSpawnPoints->addItem(item);
	}

	cmbSpawnPointTeam->removeAllItems();
	for(u32 i = 0; i < NUM_TEAMS; i++)
	{
		cmbSpawnPointTeam->addItem(StringConverter::toString(i + 1));
	}
}
