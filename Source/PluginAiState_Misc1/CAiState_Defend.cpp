#include "CAiState_Defend.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "Ai/CFpsVehicle.h"
#include "CInventoryItem.h"
#include "CWeapon.h"
#include "CTextOutput.h"
#include "IO/CoreLogging.h"

using namespace Core;
using namespace Core::Plugin;

CAiState_Defend::CAiState_Defend(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_DEFEND;
	m_StateLabel = "Defend";
	m_Level = 1;
	m_CheckCount = 0;
	m_GameObjectManager = CGameObjectManager::Instance();
}

Core::AI::E_CHARACTER_STATE_OUTCOME CAiState_Defend::Update(f32 elapsedTime)
{
	if(!m_Player->GetAiTarget())
	{
		LookForTargets();
		return WORKING;
	}
	else if(m_Player->GetAiTarget()->GetPlayer()->GetHealth() <= 0)
	{
		// Remove our target, it's dead
		m_Player->SetAiTarget(nullptr);
		
		LookForTargets();
		return WORKING;
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
				const f32 d = Vec3Utilities::distance(m_Player->GetPosition(), m_Player->GetAiTarget()->Position());
				if(weapon->GetRange() >= d)
				{
					auto dir = m_Player->GetAiTarget()->Position() - m_Player->GetPosition();
					dir.y = 0.0f;
					m_Player->SetDirection(dir);
					m_Player->UseItem(m_Player->GetAiTarget()->GetPlayer());
				}
			}
			else
			{
				// No weapon, can't defend, this should also count against leadership.
				return FailState();
			}
		}
	}

	return WORKING;
}

Core::AI::E_CHARACTER_STATE_OUTCOME CAiState_Defend::FailState()
{
	m_Player->SetAiTarget(nullptr);
	m_State = FAILED;
	return m_State;
}

void CAiState_Defend::LookForTargets()
{
	auto target = CGameObjectManager::Instance()->GetClosestVisibleEnemy(m_Player);
	if(target)
	{
		m_Player->SetAiTarget(target->GetAiVehicle());
	}
}

CAiState_DefendFactory::CAiState_DefendFactory()
{
	LabelName = "Defend";
	Type = EPS_DEFEND;
	Level = 0;
}

CAiState_DefendFactory::~CAiState_DefendFactory()
{
}

Core::AI::CCharacterState* CAiState_DefendFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_Defend(Player);
}