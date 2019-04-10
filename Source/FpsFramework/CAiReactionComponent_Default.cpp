#include "CAiReactionComponent_Default.h"
#include "CPlayer.h"
#include "CCharacterState.h"
#include "Ai/Vec3Utilities.h"
#include "Ai/CFpsVehicle.h"
#include "PlayerEnums.h"
#include "IO/CoreLogging.h"

using namespace Core;
using namespace Core::AI;

CAiReactionComponent_Default::CAiReactionComponent_Default(CPlayer* Player) : IAiReactionComponent(Player)
{
}

CAiReactionComponent_Default::~CAiReactionComponent_Default()
{
}

void CAiReactionComponent_Default::OnCharacterStateChange()
{
	// Found an enemy
	if(m_Player->GetPlayerState() == EPS_FIND_ENEMY &&
		m_Player->GetCharacterState()->GetOutcomeState() == AI::SUCCESS && 
		m_Player->GetAiTarget())
	{
		// If we have a weapon, then attack, otherwise find a weapon
		if(m_Player->GetCurrentInventoryItem())
		{
			m_Player->SetCharacterState(EPS_ATTACKING);
			#ifdef _DEBUG_LOG
				String msg = "CAiReactionComponent_Default::OnCharacterStateChange Changing to EPS_ATTACKING for player: " + String(m_Player->GetName()) + 
					" because EPS_FIND_ENEMY is successful and it has a target.";
				CORE_LOG(msg.c_str());
			#endif
		}
		else
		{
			m_Player->SetCharacterState(EPS_SEEK_ITEM);
			#ifdef _DEBUG_LOG
				String msg = "CAiReactionComponent_Default::OnCharacterStateChange Changing to EPS_SEEK_ITEM for player: " + String(m_Player->GetName()) + 
					" because EPS_FIND_ENEMY is successful and we have no weapon.";
				CORE_LOG(msg.c_str());
			#endif
		}
	}

	// Killed an enemy
	else if(m_Player->GetPlayerState() == EPS_ATTACKING &&
			m_Player->GetCharacterState()->GetOutcomeState() == AI::SUCCESS)
	{
		if(m_Player->GetCharacterState()->GetStateType() == EPS_DEFEND)
		{
			// Do nothing we defend until told otherwise or we die.
		}
		else
		{
			m_Player->SetCharacterState(EPS_FIND_ENEMY);
			#ifdef _DEBUG_LOG
				String msg = "CAiReactionComponent_Default::OnCharacterStateChange Changing to EPS_FIND_ENEMY for player: " + String(m_Player->GetName()) + 
					" because EPS_ATTACKING is successful.";
				CORE_LOG(msg.c_str());
			#endif
		}
	}

	// Died attacking an enemy
	else if(m_Player->GetPlayerState() == EPS_ATTACKING &&
			m_Player->GetCharacterState()->GetOutcomeState() == AI::FAILED)
	{
		if(m_Player->GetCharacterState()->GetStateType() == EPS_DEFEND)
		{
			// Do nothing we defend until told otherwise or we die.
		}
		else
		{
			m_Player->SetCharacterState(EPS_FIND_ENEMY);
			#ifdef _DEBUG_LOG
				String msg = "CAiReactionComponent_Default::OnCharacterStateChange Changing to EPS_FIND_ENEMY for player: " + String(m_Player->GetName()) + 
					" because EPS_ATTACKING is failed.";
				CORE_LOG(msg.c_str());
			#endif
		}
	}
}
