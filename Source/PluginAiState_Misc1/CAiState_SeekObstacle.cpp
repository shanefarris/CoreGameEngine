#include "CAiState_SeekObstacle.h"
#include "CGameObjectManager.h"
#include "CPlayer.h"
#include "Ai/CFpsVehicle.h"
#include "Ai/Obstacle.h"

#include "OgreSceneNode.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::Plugin;

CAiState_SeekObstacle::CAiState_SeekObstacle(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_SEEK_OBS;
	m_StateLabel = "SeekObstacle";
	m_Level = 1;
	m_TargetObstacle = nullptr;
}

bool CAiState_SeekObstacle::FindClosestObstacle()
{
	// Get obstacle list
	std::vector<AI::Obstacle*> list;
	CGameObjectManager::Instance()->GetObstacles(list);
	
	m_TargetObstacle = AI::Obstacle::closestObstacle(m_Player->GetAiVehicle(), list);
	if(m_TargetObstacle)
	{
		return true;
	}

	return false;
}

E_CHARACTER_STATE_OUTCOME CAiState_SeekObstacle::Update(f32 elapsedTime) 
{
	// Do we have a target
	if(!m_TargetObstacle)
	{
		if(!FindClosestObstacle())
		{
			m_State = SUCCESS;
			return m_State;
		}
		m_TargetPosition = m_TargetObstacle->getPosition();
	}

	if(m_TargetPosition.distance(m_Player->GetPosition()) < 5.0)
	{
		m_State = SUCCESS;
		return m_State;
	}

	m_Player->GetAiVehicle()->ApplySteeringForce(m_Player->GetAiVehicle()->steerForSeek(m_TargetPosition), elapsedTime);

	// Update player
	m_Player->GetPlayerNode()->setPosition(Vector3(
		m_Player->GetAiVehicle()->Position().x,
		m_Player->GetAiVehicle()->Position().y,
		m_Player->GetAiVehicle()->Position().z));
	Vector3 forwDir = Vector3(
		m_Player->GetAiVehicle()->Forward().x, 
		m_Player->GetAiVehicle()->Forward().y, 
		m_Player->GetAiVehicle()->Forward().z);
	m_Player->GetPlayerNode()->setDirection(forwDir, Ogre::SceneNode::TS_WORLD, Vector3::UNIT_Z);  

	return m_State;
}
	
CAiState_SeekObstacleFactory::CAiState_SeekObstacleFactory()
{
	LabelName = "SeekObstacle";
	Type = EPS_SEEK_OBS;
	Level = 1;
}

CAiState_SeekObstacleFactory::~CAiState_SeekObstacleFactory() 
{ 
}

Core::AI::CCharacterState* CAiState_SeekObstacleFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_SeekObstacle(Player);
}
