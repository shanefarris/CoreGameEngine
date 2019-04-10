#include "CHud.h"
#include "CGuiStrategy_MyGui.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "CGameManager.h"
#include "CInputManager.h"
#include "CGuiManager.h"
#include "CPhysicsManager.h"
#include "CItemsManager.h"
#include "CNatureManager.h"

// Ogre
#include "OgreCamera.h"
#include "OgreSceneQuery.h"
#include "OgreSceneManager.h"
#include "OgreRenderWindow.h"
#include "OgreStringConverter.h"

using namespace Core;

CHud::CHud(Core::GUI::CGuiStrategy_MyGui* Strategy)
{
	Strategy->Initialize("TD_Hud.layout");

	Strategy->AssignWidget(btnPlaceSolider, "btnPlaceSolider");
	Strategy->AssignWidget(btnPlaceMarine, "btnPlaceMarine");
	Strategy->AssignWidget(txtMoney, "txtMoney");
	Strategy->AssignWidget(txtMessages, "txtMessages");
	Strategy->AssignWidget(frm, "_Main");

	MyGUI::PointerManager::getInstance().setVisible(true);
	frm->setVisible(true);

	btnPlaceSolider->eventMouseButtonClick = MyGUI::newDelegate(this, &CHud::btnPlaceSolider_Click);
	btnPlaceMarine->eventMouseButtonClick = MyGUI::newDelegate(this, &CHud::btnPlaceMarine_Click);

	isPlaceSolider = false;	
	isPlaceMarine = false;

	CInputManager::Instance()->AddMouseListener(this, "HUD");
	CInputManager::Instance()->AddKeyListener(this, "HUD");

	// Set menu positions
	f32 height = CGameManager::Instance()->GetRenderWindow()->getHeight();
	f32 width = CGameManager::Instance()->GetRenderWindow()->getWidth();
	frm->setPosition(0, height - frm->getHeight());
}

CHud::~CHud()
{
	CInputManager::Instance()->RemoveMouseListener("HUD");
	CInputManager::Instance()->RemoveKeyListener("HUD");
}

void CHud::btnPlaceSolider_Click(MyGUI::Widget* _sender)
{
	isPlaceSolider = true;
}

void CHud::btnPlaceMarine_Click(MyGUI::Widget* _sender)
{
	isPlaceMarine = true;
}

void CHud::PlacePlayer(f32 Width, f32 Height)
{
	auto point = MyGUI::InputManager::getInstance().getMousePosition();
	auto mouseRay = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(point.left / Width, point.top / Height);
	auto pos = Nature::CNatureManager::Instance()->GetTerrainPosition(mouseRay);

	if(pos != INVALID_POS)
	{
		String playerType;
		if(isPlaceSolider)
		{
			playerType = "SOLDIER";		
		}
		else if(isPlaceMarine)
		{
			playerType = "GENMARINE";
		}
		auto player = CGameObjectManager::Instance()->CreatePlayer(playerType.c_str(), EPT_TEAM_2, "", Physics::CPhysicsManager::Instance()->GetStrategy(), false);
		player->SetPlayerPosition(pos);
		player->SetCharacterState(EPS_DEFEND);
		//player->SetLoSType(ELT_BASIC);
		player->DebugLoS(true);
		auto item = CItemsManager::Instance()->PickupUnplaced("weapon1");
		if(item)
		{
			player->AddItem(item);
		}
	}

	if(CInputManager::Instance()->GetKeyboard()->isKeyDown(OIS::KC_LSHIFT) ||
		CInputManager::Instance()->GetKeyboard()->isKeyDown(OIS::KC_RSHIFT))
	{
	}
	else
	{
		isPlaceSolider = false;
		isPlaceMarine = false;
	}
}

bool CHud::mouseMoved(const OIS::MouseEvent &arg)
{
	return true;
}

bool CHud::mousePressed(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	if(isPlaceSolider || isPlaceMarine)
	{
		PlacePlayer(f32(arg.state.width), f32(arg.state.height));
	}
	return true;
}

bool CHud::mouseReleased(const OIS::MouseEvent &arg, OIS::MouseButtonID id)
{
	return true;
}

bool CHud::keyPressed(const OIS::KeyEvent &arg)
{
	return true;
}

bool CHud::keyReleased(const OIS::KeyEvent &arg)
{
	return true;
}
