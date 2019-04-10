#include "CAiState_AttackEnemy.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "Ai/CFpsVehicle.h"
#include "CInventoryItem.h"
#include "CWeapon.h"
#include "CTextOutput.h"
#include "CCharacterStateManager.h"
#include "IO/CoreLogging.h"

using namespace Core;
using namespace Core::Plugin;

CAiState_AttackEnemy::CAiState_AttackEnemy(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_ATTACKING;
	m_StateLabel = "AttackEnemy";
	m_Level = 1;
	m_CheckCount = 0;
	m_GameObjectManager = CGameObjectManager::Instance();
}

Core::AI::E_CHARACTER_STATE_OUTCOME CAiState_AttackEnemy::Update(f32 elapsedTime)
{
	if(!m_Player->GetAiTarget())
	{
		#ifdef _DEBUG
			String msg = "CAiState_AttackEnemy failed for player: " + String(m_Player->GetName()) + " because doens't have a target.";
			CORE_LOG(msg.c_str());
		#endif
		m_State = FAILED;
	}
	else
	{
		// If target is dead then we are successful
		if(m_Player->GetAiTarget()->GetPlayer()->GetHealth() <= 0)
		{
			// Remove our target, it's dead
			m_Player->SetAiTarget(nullptr);
			m_State = SUCCESS;
		}
		else
		{
			// Check inventory
			auto item = m_Player->GetCurrentInventoryItem();
			if(item)
			{
				// Are we in range?
				CWeapon* weapon = static_cast<CWeapon*>(item);
				if(weapon)
				{
					//// Can we still see the target
					//if(!m_Player->CanSee(m_Player->GetAiTarget()->position()))
					//{
					//	#ifdef _DEBUG
					//		String msg = "CAiState_AttackEnemy failed for player: " + String(m_Player->GetName()) + " because it can't see it.";
					//		CORE_LOG(msg.c_str());
					//	#endif

					//	m_Player->GetAiVehicle()->setSpeed(m_Player->GetWalkSpeed());
					//	m_Player->GetAiVehicle()->setMaxSpeed(m_Player->GetWalkSpeed());

					//	m_State = FAILED;
					//	return m_State;
					//}

					const f32 d = Vec3Utilities::distance (m_Player->GetPosition(), m_Player->GetAiTarget()->Position());
					if(weapon->GetRange() <= d)
					{
						Pursue(elapsedTime, weapon->GetRange());
					}
					else if(d > m_Player->GetViewRange())
					{
						#ifdef _DEBUG
							String msg = "CAiState_AttackEnemy failed for player: " + String(m_Player->GetName()) + ", out of view range.";
							CORE_LOG(msg.c_str());
						#endif

						return FailState();
					}
					else
					{
						auto dir = m_Player->GetAiTarget()->Position() - m_Player->GetPosition();
						dir.y = 0.0f;
						m_Player->SetDirection(dir);
						m_Player->GetAiVehicle()->SetSpeed(m_Player->GetWalkSpeed());
						m_Player->GetAiVehicle()->SetMaxSpeed(m_Player->GetWalkSpeed());
						m_Player->UseItem(m_Player->GetAiTarget()->GetPlayer());
					}
				}
				else
				{
					return FailState();
				}
			}
		}
	}

	return m_State;
}

void CAiState_AttackEnemy::Pursue(const f32& elapsedTime, const f32& Radius)
{
	m_Player->GetAiVehicle()->SetSpeed(m_Player->GetRunSpeed());
	m_Player->GetAiVehicle()->SetMaxSpeed(m_Player->GetRunSpeed());
	CCharacterStateManager::Instance()->SeekPosition(m_Player, m_Player->GetAiTarget()->Position(), elapsedTime);
}

Core::AI::E_CHARACTER_STATE_OUTCOME CAiState_AttackEnemy::FailState()
{
	m_Player->SetAiTarget(nullptr);
	m_Player->GetAiVehicle()->SetSpeed(m_Player->GetWalkSpeed());
	m_Player->GetAiVehicle()->SetMaxSpeed(m_Player->GetWalkSpeed());

	m_State = FAILED;
	return m_State;
}

CAiState_AttackEnemyFactory::CAiState_AttackEnemyFactory()
{
	LabelName = "AttackEnemy";
	Type = EPS_ATTACKING;
	Level = 0;
}

CAiState_AttackEnemyFactory::~CAiState_AttackEnemyFactory()
{
}

Core::AI::CCharacterState* CAiState_AttackEnemyFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_AttackEnemy(Player);
}