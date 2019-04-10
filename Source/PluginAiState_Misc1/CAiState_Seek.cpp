#include "CAiState_Seek.h"
#include "CPlayer.h"
#include "Ai/CFpsVehicle.h"
#include "Ai/Obstacle.h"
#include "CCharacterStateManager.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::Plugin;

CAiState_Seek::CAiState_Seek(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_SEEK_ENEMY;
	m_StateLabel = "Seek";
	m_Level = 1;
	m_VehicleTarget = nullptr;
}

E_CHARACTER_STATE_OUTCOME CAiState_Seek::Update(f32 elapsedTime) 
{
	if(m_Player->GetAiTarget())
	{
		m_State = CCharacterStateManager::Instance()->SeekVehicle(m_Player, elapsedTime);
		return m_State;
	}
	return FAILED;
}

CAiState_SeekFactory::CAiState_SeekFactory()
{
	LabelName = "Seek";
	Type = EPS_SEEK_ENEMY;
	Level = 1;
}

CAiState_SeekFactory::~CAiState_SeekFactory() 
{ 
}

Core::AI::CCharacterState* CAiState_SeekFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_Seek(Player);
}