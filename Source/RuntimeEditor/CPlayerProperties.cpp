#include "CPlayerProperties.h"
#include "CCharacterStateManager.h"
#include "CEditorHelper.h"
#include "CMenuDirector.h"
#include "CItemProfile.h"
#include "CGameObjectManager.h"
#include "CItemsManager.h"
#include "CPlayer.h"
#include "CInventoryItem.h"
#include "AI/CFpsVehicle.h"
#include "CCharacterState.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

// Ogre
#include "OgreSceneNode.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::GUI;
using namespace Core::Editor;

CPlayerProperties::CPlayerProperties(CGuiStrategy_MyGui* Strategy) : m_Player(nullptr)
{
	Strategy->AssignWidget(frmPlayerProperties, "frmPlayerProperties");
	Strategy->AssignWidget(txtPlayerName, "txtPlayerName");
	Strategy->AssignWidget(btnPlayerCancel, "btnPlayerCancel");
	Strategy->AssignWidget(btnPlayerSave, "btnPlayerSave");
	Strategy->AssignWidget(chkPlayerShowLoS, "chkPlayerShowLoS");
	Strategy->AssignWidget(chkPlayerShowBB, "chkPlayerShowBB");
	Strategy->AssignWidget(chkPlayerShowCC, "chkPlayerShowCC");
	Strategy->AssignWidget(lstPlayerItems, "lstPlayerItems");
	Strategy->AssignWidget(cmbPlayerAllItems, "cmbPlayerAllItems");
	Strategy->AssignWidget(btnPlayerAddItem, "btnPlayerAddItem");
	Strategy->AssignWidget(btnPlayerRemoveItem, "btnPlayerRemoveItem");
	Strategy->AssignWidget(cmbPlayerState, "cmbPlayerState");
	Strategy->AssignWidget(cmbPlayerTarget, "cmbPlayerTarget");
	Strategy->AssignWidget(cmbPlayerTeam, "cmbPlayerTeam");
	Strategy->AssignWidget(chkPlayerIsHuman, "chkPlayerIsHuman");
	Strategy->AssignWidget(txtPlayerPosX, "txtPlayerPosX");
	Strategy->AssignWidget(txtPlayerPosY, "txtPlayerPosY");
	Strategy->AssignWidget(txtPlayerPosZ, "txtPlayerPosZ");
	
	btnPlayerCancel->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::btnPlayerCancel_Click);
	btnPlayerSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::btnPlayerSave_Click);
	chkPlayerShowLoS->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::chkPlayerShowLoS_Click);
	chkPlayerShowBB->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::chkPlayerShowBB_Click);
	chkPlayerShowCC->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::chkPlayerShowCC_Click);
	cmbPlayerAllItems->eventComboChangePosition = MyGUI::newDelegate(this, &CPlayerProperties::cmbPlayerAllItems_ComboAccept);
	btnPlayerAddItem->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::btnPlayerAddItem_Click);
	btnPlayerRemoveItem->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::btnPlayerRemoveItem_Click);
	cmbPlayerState->eventComboChangePosition = MyGUI::newDelegate(this, &CPlayerProperties::cmbPlayerState_ComboAccept);
	cmbPlayerTarget->eventComboChangePosition = MyGUI::newDelegate(this, &CPlayerProperties::cmbPlayerTarget_ComboAccept);
	cmbPlayerTeam->eventComboChangePosition = MyGUI::newDelegate(this, &CPlayerProperties::cmbPlayerTeam_ComboAccept);
	chkPlayerIsHuman->eventMouseButtonClick = MyGUI::newDelegate(this, &CPlayerProperties::chkPlayerIsHuman_Click);

	isVisible = false;

	// Populate cmbPlayerTeam 
	cmbPlayerTeam->removeAllItems();
	for(u32 i = 1; i < NUM_TEAMS + 1; i++)
		cmbPlayerTeam->addItem(StringConverter::toString(i));

	// Popuate available AI states
	cmbPlayerState->removeAllItems();
	Vector<const char*> states;
	AI::CCharacterStateManager::Instance()->GetAllStates(states);
	for(auto it = states.cbegin(); it != states.cend(); it++)
		cmbPlayerState->addItem(String((*it)));
}

CPlayerProperties::~CPlayerProperties()
{
}

void CPlayerProperties::SetVisible(bool Visible, CPlayer* Player)
{
	// If already visible then don't reload it
	if(frmPlayerProperties->getVisible() && Visible)
		return;

	frmPlayerProperties->setVisible(Visible);

	if(Visible && Player)
	{
		m_Player = Player;
		isHuman = m_Player->GetIsHumanPlayer();
		txtPlayerName->setCaption(Player->GetName());
		
		// Populate cmbItemsInventory
		cmbPlayerAllItems->removeAllItems();
		Vector<CItemProfile*> profiles;
		CItemsManager::Instance()->GetItemProfiles(profiles);
		for(u32 i = 0; i < profiles.size(); i++)
			cmbPlayerAllItems->addItem(profiles[i]->Name);

		// Popluate inventory list
		lstPlayerItems->removeAllItems();
		auto items = m_Player->GetItems();
		for(u32 i = 0; i < items.size(); i++)
			lstPlayerItems->addItem(items[i]->Name);

		// Team
		cmbPlayerTeam->setOnlyText(StringConverter::toString((u32)m_Player->GetPlayerTeam() + 1));

		// Target
		PoplatePlayerTargets();
		if(m_Player->GetAiTarget())
			cmbPlayerTarget->setOnlyText(m_Player->GetAiTarget()->GetPlayer()->GetName());
		else
			cmbPlayerTarget->setOnlyText("");

		// State
		if(m_Player->GetCharacterState())
		{
			AI::CCharacterState* state = m_Player->GetCharacterState();
			const char* stateName = state->GetStateName();

			if(stateName)
				cmbPlayerState->setOnlyText(String(stateName));
		}
		else
			cmbPlayerState->setOnlyText("");

		// Checkboxes
		chkPlayerShowLoS->setStateSelected(false);
		chkPlayerShowBB->setStateSelected(false);
		chkPlayerShowBB->setStateSelected(isHuman);

		m_Player->DebugLoS(false);
		m_Player->GetPlayerNode()->showBoundingBox(false);

		// Position
		txtPlayerPosX->setCaption(StringConverter::toString(m_Player->GetPosition().x));
		txtPlayerPosY->setCaption(StringConverter::toString(m_Player->GetPosition().y));
		txtPlayerPosZ->setCaption(StringConverter::toString(m_Player->GetPosition().z));
		
	}
}

void CPlayerProperties::btnPlayerCancel_Click(MyGUI::Widget* _sender)
{
	CMenuDirector::Instance()->SetPlayerPropMenuView(false);
}

void CPlayerProperties::btnPlayerSave_Click(MyGUI::Widget* _sender)
{
	if(m_Player)
	{
		// Name
		String value = txtPlayerName->getOnlyText();
		if(value != m_Player->GetName())
			m_Player->SetName(value.c_str());

		// Team
		value = cmbPlayerTeam->getOnlyText();
		E_PLAYER_TEAM team = (E_PLAYER_TEAM)(StringConverter::parseUnsignedInt(value) - 1);
		m_Player->SetPlayerTeam(team);

		// AI Target
		value = cmbPlayerTarget->getOnlyText();
		if(value.length() > 0)
		{
			CPlayer* target = CGameObjectManager::Instance()->GetPlayerByName(value.c_str());
			if(target)
				m_Player->SetAiTarget(target->GetAiVehicle());
		}

		// Inventory items
		m_Player->RemoveAllItems();

		auto itemCount = lstPlayerItems->getItemCount();
		for(u32 i = 0; i < itemCount; i++)
		{
			String name = lstPlayerItems->getItemNameAt(i);
			auto item = CItemsManager::Instance()->PickupUnplaced(name.c_str());
			if(item)
			{
				m_Player->AddItem(item);
				lstPlayerItems->addItem(name);
			}
		}

		// Character state
		value = cmbPlayerState->getOnlyText();
		if(value == "FollowPath")
		{
			if(CCharacterStateManager::Instance()->GetPathCount())
			{
				Vector<Vector3> path;
				CCharacterStateManager::Instance()->GetPathByIndex(0, path);
				m_Player->SetAiPathPoints(path);
				m_Player->SetCharacterState(EPS_WALKING);
				m_Player->SetTextLabelCaption("FollowPath");
			}
		}
		else if(value.length() > 0)
		{
			m_Player->SetExactCharacterState(value.c_str());
			m_Player->SetTextLabelCaption(value.c_str());
		}

		// Text label
		if(value.length() > 0)
			m_Player->SetTextLabelEnabled(true);
		else
			m_Player->SetTextLabelEnabled(false);

		// Set is human
		m_Player->SetHumanPlayer(isHuman);

		// Set position
		Vector3 pos;
		pos.x = StringConverter::parseReal(txtPlayerPosX->getCaption());
		pos.y = StringConverter::parseReal(txtPlayerPosY->getCaption());
		pos.z = StringConverter::parseReal(txtPlayerPosZ->getCaption());
		m_Player->SetPlayerPosition(pos);

	}
	frmPlayerProperties->setVisible(false);
}

void CPlayerProperties::chkPlayerShowLoS_Click(MyGUI::Widget* _sender)
{
	bool show = !chkPlayerShowLoS->getStateSelected();
	chkPlayerShowLoS->setStateSelected(show);
	
	if(m_Player)
		m_Player->DebugLoS(show);
}

void CPlayerProperties::chkPlayerShowBB_Click(MyGUI::Widget* _sender)
{
	bool show = !chkPlayerShowBB->getStateSelected();
	chkPlayerShowBB->setStateSelected(show);

	if(m_Player)
		m_Player->GetPlayerNode()->showBoundingBox(show);
}

void CPlayerProperties::chkPlayerShowCC_Click(MyGUI::Widget* _sender)
{
	chkPlayerShowCC->setStateSelected(!chkPlayerShowCC->getStateSelected());
}

void CPlayerProperties::cmbPlayerAllItems_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CPlayerProperties::btnPlayerAddItem_Click(MyGUI::Widget* _sender)
{
	String name = cmbPlayerAllItems->getCaption();
	lstPlayerItems->addItem(name);
}

void CPlayerProperties::btnPlayerRemoveItem_Click(MyGUI::Widget* _sender)
{
	lstPlayerItems->removeItemAt(lstPlayerItems->getIndexSelected());
}

void CPlayerProperties::cmbPlayerState_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
	//String value = cmbPlayerState->getItemNameAt(_index).asUTF8();
}

void CPlayerProperties::cmbPlayerTarget_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
}

void CPlayerProperties::cmbPlayerTeam_ComboAccept(MyGUI::ComboBox* _sender, size_t _index)
{
	String value = cmbPlayerState->getItemNameAt(_index).asUTF8();
	E_PLAYER_TEAM team = (E_PLAYER_TEAM)StringConverter::parseUnsignedInt(value);
	if(team != m_Player->GetPlayerTeam())
	{
		m_Player->SetPlayerTeam(team);
		if(m_Player->GetAiTarget())
		{
			if(m_Player->GetAiTarget()->GetPlayer()->GetPlayerTeam() == m_Player->GetPlayerTeam())
			{
				m_Player->SetAiTarget(nullptr);
			}
		}
		PoplatePlayerTargets();
	}
}

void CPlayerProperties::chkPlayerIsHuman_Click(MyGUI::Widget* _sender)
{
	isHuman = !chkPlayerIsHuman->getStateSelected();
	chkPlayerIsHuman->setStateSelected(isHuman);
}

void CPlayerProperties::PoplatePlayerTargets()
{
	// Populate cmbPlayerTarget
	cmbPlayerTarget->removeAllItems();
	Vector<CPlayer*> players;
	CGameObjectManager::Instance()->GetAllPlayers(players);
	for(u32 i = 0; i < players.size(); i++)
	{
		if(players[i]->GetPlayerTeam() != m_Player->GetPlayerTeam())
			cmbPlayerTarget->addItem(players[i]->GetName());
	}
}
