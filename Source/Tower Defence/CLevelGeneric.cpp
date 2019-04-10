#include "CLevelGeneric.h"
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "CGameObjectManager.h"
#include "CGuiManager.h"
#include "CCameraManager.h"
#include "CGuiStrategy_MyGui.h"
#include "IPhysicsStrategy.h"
#include "CItemsManager.h"
#include "CItemProfile.h"
#include "CPlayer.h"

#include "CHud.h"

#include "IO/CoreLogging.h"

#include "OgreRoot.h"
#include "OgreRenderWindow.h"

using namespace Ogre;
using namespace Core;

void CLevelGeneric::Update(const f32& deltaTime)
{
	CGameManager::Instance()->UpdateGame(deltaTime);
}

bool CLevelGeneric::Load()
{
	try{
		// Create ODE physics strategy
		Physics::CPhysicsManager::Instance()->CreateStrategy("ODE");
		Physics::CPhysicsManager::Instance()->GetStrategy()->InitWorld();
		Physics::CPhysicsManager::Instance()->GetStrategy()->ShowDebug(false);

		CGameManager::Instance()->LoadGame("td1.scd", "CLevelGeneric");

		// Melee profile
		CItemProfile profile(EIT_MELEE);
		profile.Desc = "Basic Melee Attack";
		profile.Name = "BasicMelee";
		profile.Range = 3.0f;
		profile.Power = 3.4f;
		CItemsManager::Instance()->AddProfile(profile);

		// Set default values for players
		Vector<CPlayer*> players;
		CGameObjectManager::Instance()->GetAllPlayers(players);
		for(auto it = players.begin(); it != players.end(); it++)
		{
			(*it)->SetLoSType(ELT_BASIC);
			if((*it)->GetPlayerTeam() == EPT_TEAM_1)
			{
				(*it)->SetCharacterState(EPS_FIND_ENEMY);
				auto item = CItemsManager::Instance()->PickupUnplaced("BasicMelee");
				if(item)
				{
					(*it)->AddItem(item);
				}
			}
			else
			{
				(*it)->SetCharacterState(EPS_DEFEND);
				(*it)->SetLoSType(ELT_BASIC);
				(*it)->SetHumanPlayer(true);
				
				//(*it)->DebugLoS(true);
				auto item = CItemsManager::Instance()->PickupUnplaced("weapon1");
				if(item)
					(*it)->AddItem(item);
			}
		}

		//auto strategy = static_cast<GUI::CGuiStrategy_MyGui*>(GUI::CGuiManager::Instance()->CreateStrategy("MyGui", GUI::EGS_MYGUI));
		//auto width = CGameManager::Instance()->GetRenderWindow()->getWidth() / 2;
		//auto height = CGameManager::Instance()->GetRenderWindow()->getHeight() / 2;
		//strategy->SetMousePosition(Vector2(width, height));
		//
		//m_Hud = new CHud(strategy);
		
		CCameraManager::Instance()->CreateCamera(ECM_FPS);
		//CCameraManager::Instance()->SetCameraPos(Vector3(0, 550, 0));
		//CCameraManager::Instance()->SetMoveSpeed(100.0f);

		m_FrameListener = new CFpsFrameListener(CGameManager::Instance()->GetRenderWindow());
		//m_FrameListener->AddGuiStrategy(strategy);
		CGameManager::Instance()->GetEngineDevice()->addFrameListener(m_FrameListener);	
 	}
	catch(char* e)
	{
		std::cerr << e << std::endl;
	}
	return true;
}

CLevelGeneric::~CLevelGeneric()
{
	CORE_DELETE(m_Hud);

	m_GameManager->GetEngineDevice()->removeFrameListener(m_FrameListener);
	CORE_DELETE(m_FrameListener);
}

#include "CGame.h"

#ifdef WIN32
#define WIN32_LEAN_AND_MEAN
#include "windows.h"

INT WINAPI WinMain( HINSTANCE hInst, HINSTANCE, LPSTR strCmdLine, INT argc) 
{ 
    try 
	{
		Core::CGame game;
		game.AddGameState(new CLevelGeneric());
		game.Run();
    } 
	catch(Exception& e) 
	{
		std::cerr << "An exception has occurred: " << e.what() << std::endl;
		MessageBox(NULL, e.what(), "An exception has occurred", MB_OK);
    }
	catch(...) 
	{
		std::cerr << "An exception has occurred" << std::endl;
		MessageBox(NULL, "Oops", "An exception has occurred", MB_OK);
    }
	return 0;
}

int main(int argc, char **argv)
{
	try
	{
		Core::CGame game;
		game.AddGameState(new CLevelGeneric());
		game.Run();
	}
	catch(Exception& e) 
	{
		std::cerr << "An exception has occurred: " << e.what() << std::endl;
    }
	catch(...) 
	{
		std::cerr << "An exception has occurred" << std::endl;
    }
    return 0;
}
#endif