#include "CAiState_Wander.h"
#include "CGameObjectManager.h"
#include "CPlayer.h"
#include "Ai/CFpsVehicle.h"
#include "Ai/Obstacle.h"
#include "CTextOutput.h"
#include "IO/CoreLogging.h"

#include "OgreSceneNode.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::Plugin;

CAiState_Wander::CAiState_Wander(CPlayer* Player) : CCharacterState(Player)
{
	m_TargetCenter = Vector3(500,0,500);
	m_State = WORKING;
	m_StateType = EPS_WANDERING;
	m_StateLabel = "Wander";
	m_Level = 1;
}

E_CHARACTER_STATE_OUTCOME CAiState_Wander::Update(f32 elapsedTime) 
{
	// Get obs list
	Vector<Obstacle*> obs;
	CGameObjectManager::Instance()->GetSphereObstacles(obs);

	// Get walls
	Vector<AI::Wall*> walls;
	CGameObjectManager::Instance()->GetWalls(walls);

	Vector3 avoidance = Vector3::ZERO;
	Vector3 steer = Vector3::ZERO;

	avoidance = m_Player->GetAiVehicle()->steerForWallAvoidance(walls);
	avoidance += m_Player->GetAiVehicle()->steerToAvoidOabstacles_QuickSphere(obs);
	if (avoidance == Vector3::ZERO)
	{
		Vector3 wander2d = m_Player->GetAiVehicle()->steerForWander(elapsedTime);
		wander2d.y = 0;
		steer = m_Player->GetAiVehicle()->Forward() + (wander2d * 1.0f /* turningness */);	
		CORE_TEXT("non_avoidance", "nonavoidance:" + StringConverter::toString(steer));
	}
	else
	{
		steer = avoidance;
		steer.y = 0;
		CORE_TEXT("avoidance", "avoidance:" + StringConverter::toString(steer));
	}
	m_Player->GetAiVehicle()->ApplySteeringForce (steer, elapsedTime);

	// Update nodes and animations
	// ---------------------------
	Vector3 pos = Vector3(
		m_Player->GetAiVehicle()->Position().x,
		m_Player->GetAiVehicle()->Position().y,
		m_Player->GetAiVehicle()->Position().z);
	m_Player->SetPlayerPosition(pos);

	Vector3 forwDir = Vector3(
		m_Player->GetAiVehicle()->Forward().x, 
		m_Player->GetAiVehicle()->Forward().y, 
		m_Player->GetAiVehicle()->Forward().z);
	m_Player->GetPlayerNode()->setDirection(forwDir, Ogre::SceneNode::TS_WORLD, Vector3::UNIT_Z);  

	CORE_TEXT("forward", "forward:" + StringConverter::toString(m_Player->GetAiVehicle()->Forward()));

	// Never stop wandering until we are interupted
	m_State = WORKING;

	return m_State;
}

CAiState_WanderFactory::CAiState_WanderFactory()
{
	LabelName = "Wander";
	Type = EPS_WANDERING;
	Level = 1;
}

CAiState_WanderFactory::~CAiState_WanderFactory() 
{ 
}

Core::AI::CCharacterState* CAiState_WanderFactory::GetCharacterState(CPlayer* Player)
{
	return new CAiState_Wander(Player);
}