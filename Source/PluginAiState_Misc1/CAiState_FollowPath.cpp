#include "CAiState_FollowPath.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "Ai/CFpsVehicle.h"
#include "Ai/Obstacle.h"
#include "Ai/PolylineSegmentedPathwaySingleRadius.h"

#include "OgreSceneNode.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::Plugin;

PolylineSegmentedPathwaySingleRadius* gPath = nullptr;

CAiState_FollowPath::CAiState_FollowPath(CPlayer* Player) : CCharacterState(Player)
{
	m_State = WORKING;
	m_StateType = EPS_WALKING;
	m_StateLabel = "FollowPath";
	m_Level = 1;
	m_Player->GetAiPathPoints(m_PathPoints);

	if(m_PathPoints.size() > 0)
	{
		const float pathRadius = 2;
		Vector3* pathPoints = new Vector3[m_PathPoints.size() - 1];
		for(u32 i = 0; i < m_PathPoints.size(); i++)
		{
			pathPoints[i] = m_PathPoints[i];
			
		}
		
		gPath = new PolylineSegmentedPathwaySingleRadius (m_PathPoints.size(),
                                                              pathPoints,
                                                              pathRadius,
                                                              false);
	}
}

E_CHARACTER_STATE_OUTCOME CAiState_FollowPath::Update(f32 elapsedTime) 
{
	// Do we have a target
	if(m_PathPoints.size() == 0)
	{
		m_State = SUCCESS;
		return m_State;
	}

	// move forward
    Vector3 steeringForce = m_Player->GetAiVehicle()->Forward();

    // probability that a lower priority behavior will be given a chance to "drive" even if a higher priority behavior might otherwise be triggered.
    const float leakThrough = 0.1f;

    // determine if obstacle avoidance is required
    Vector3 obstacleAvoidance;
	Vector<Obstacle*> list;
	CGameObjectManager::Instance()->GetObstacles(list);
	obstacleAvoidance = m_Player->GetAiVehicle()->steerToAvoidObstacles (6.0f, (ObstacleGroup&)list);

    // if obstacle avoidance is needed, do it
    if (obstacleAvoidance != Vector3::ZERO)
    {
        steeringForce += obstacleAvoidance;
    }
    else
    {
		// add in wander component (according to user switch)
		steeringForce += m_Player->GetAiVehicle()->steerForWander (elapsedTime);

		// do (interactively) selected type of path following
		const float pfLeadTime = 3;
		u32 pathDirection = 1;
		const Vector3 pathFollow =  m_Player->GetAiVehicle()->steerToStayOnPath(pfLeadTime, *gPath);

		// add in to steeringForce
		steeringForce += pathFollow * 0.5;
    }

    // return steering constrained to global XZ "ground" plane
	steeringForce.y = 0;

	m_Player->GetAiVehicle()->ApplySteeringForce(steeringForce, elapsedTime);

	// Update nodes and animations
	// ---------------------------
	m_Player->GetPlayerNode()->setPosition(
		m_Player->GetAiVehicle()->Position().x,
		m_Player->GetAiVehicle()->Position().y,
		m_Player->GetAiVehicle()->Position().z);
	Vector3 forwDir = Vector3(
		m_Player->GetAiVehicle()->Forward().x, 
		m_Player->GetAiVehicle()->Forward().y, 
		m_Player->GetAiVehicle()->Forward().z);
	m_Player->GetPlayerNode()->setDirection(forwDir, Ogre::SceneNode::TS_WORLD, Vector3::UNIT_Z);  

	return m_State;
}

CAiState_FollowPathFactory::CAiState_FollowPathFactory()
{
	LabelName = "FollowPath";
	Type = EPS_WALKING;
	Level = 1;
}

CAiState_FollowPathFactory::~CAiState_FollowPathFactory() 
{ 
}

Core::AI::CCharacterState* CAiState_FollowPathFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_FollowPath(Player);
}