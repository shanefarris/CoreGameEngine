#include "CAiState_FindEnemy.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "Ai/CFpsVehicle.h"
#include "Ai/Obstacle.h"
#include "CTextOutput.h"
#include "CCharacterStateManager.h"
#include "IO/CoreLogging.h"

using namespace Core;
using namespace Core::Plugin;

CAiState_FindEnemy::CAiState_FindEnemy(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_FIND_ENEMY;
	m_StateLabel = "FindEnemy";
	m_Level = 1;
	m_CheckCount = 0;
	m_GameObjectManager = CGameObjectManager::Instance();
}

Core::AI::E_CHARACTER_STATE_OUTCOME CAiState_FindEnemy::Update(f32 elapsedTime)
{
	CCharacterStateManager::Instance()->Search(m_Player, elapsedTime);
	CORE_TEXT("CharacterState_FindEnemy", "looking for an enemy");

	if(m_CheckCount >= 10)
	{	
		m_CheckCount = 0;
		CPlayer* target_player = nullptr;
		Vector<CPlayer*> players;
		
		m_GameObjectManager->GetAllPlayers(players);
		for(u32 i = 0; i < players.size(); i++)
		{
			CPlayer* target = players[i];
			// Check the team
			if(target->GetPlayerTeam() != m_Player->GetPlayerTeam())
			{
				// Can we see them
				if(m_Player->CanSee(target->GetPosition()) && target->GetHealth() > 0)
				{
					if(target)
					{
						f32 d = Vec3Utilities::distance (m_Player->GetPosition(), target->GetPosition());
						if(d < m_Player->GetViewRange())
						{
							// Found a target, we are done
							m_Player->SetAiTarget(target->GetAiVehicle());
							m_State = SUCCESS;

							#ifdef _DEBUG
								CORE_TEXT("CharacterState_FindEnemy", "Found an enemy");
								String msg = "CharacterState_FindEnemy success for player: " + String(m_Player->GetName());
								CORE_LOG(msg.c_str());
							#endif
						}
					}
				}
			}
		}
	}
	m_CheckCount++;
	return m_State;
}

CAiState_FindEnemyFactory::CAiState_FindEnemyFactory()
{
	LabelName = "FindEnemy";
	Type = EPS_FIND_ENEMY;
	Level = 0;
}

CAiState_FindEnemyFactory::~CAiState_FindEnemyFactory()
{
}

Core::AI::CCharacterState* CAiState_FindEnemyFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_FindEnemy(Player);
}