#include "CCharacterStateManager.h"
#include "CPluginManager.h"
#include "CGameObjectManager.h"
#include "CPlayer.h"
#include "PlayerEnums.h"
#include "CCharacterState.h"
#include "CTextOutput.h"
#include "AI/CFpsVehicle.h"
#include "AI/Obstacle.h"
#include "IO/CoreLogging.h"

#include "Plugins\IAiStateFactory.h"

#include "OgreSceneNode.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::AI;

CCharacterStateManager* CCharacterStateManager::CharacterStateManager = nullptr;

CCharacterStateManager* CCharacterStateManager::Instance()
{
	if(CharacterStateManager == nullptr)
		CharacterStateManager = new CCharacterStateManager();
	return CharacterStateManager;
}

CCharacterStateManager::CCharacterStateManager()
{
	m_PluginManager = CPluginManager::Instance();
	Init();
}

CCharacterStateManager::~CCharacterStateManager()
{
	try
	{
		m_PluginManager = nullptr;

		m_States.clear();

		// Remove all paths
		auto it = m_Paths.begin(); 
		while(it != m_Paths.end())
		{
			auto paths = (*it).second;
			auto it2 = paths.begin();
			while(it2 != paths.end())
			{
				paths.erase(it2++);
			}
		}
		m_Paths.clear();
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CCharacterStateManager()");
	}
}

void CCharacterStateManager::Init()
{
	m_States = m_PluginManager->GetAiStateFactories();
}

CCharacterState* CCharacterStateManager::GetState(E_PLAYER_STATE Type, CPlayer* Player, u32 Level)
{
	for(auto it = m_States.cbegin(); it != m_States.cend(); it++)
	{
		if((*it)->Type == Type)
		{
			return (*it)->GetCharacterState(Player);
		}
	}
	return nullptr;
}

CCharacterState* CCharacterStateManager::GetState(const char* StateName, CPlayer* Player)
{
	for(auto it = m_States.cbegin(); it != m_States.cend(); it++)
	{
		if(strncmp((*it)->LabelName.c_str(), StateName, (*it)->LabelName.size()) == 0)
			return (*it)->GetCharacterState(Player);
	}
	return nullptr;
}

void CCharacterStateManager::GetAllStates(Vector<const char*>& States)
{
	for(u32 i = 0; i < m_States.size(); i++)
	{
		States.push_back(m_States[i]->LabelName.c_str());
	}
}

void CCharacterStateManager::GetLoadedStates(Vector<String>& Names)
{
	Names.clear();
	for(auto it = m_States.cbegin(); it != m_States.cend(); it++)
	{
		Names.push_back((*it)->LabelName);
	}
}

void CCharacterStateManager::AddPath(const char* Name, const Vector<Vector3>& Paths)
{
	// Name must be unique 
	String name = Name;
	if(m_Paths.find(name) == m_Paths.end())
	{
		m_Paths[Name] = Paths;
	}
}

u32 CCharacterStateManager::GetPathCount()
{
	return (u32)m_Paths.size();
}

bool CCharacterStateManager::GetPathByName(const char* Name, Vector<Vector3>& Path)
{
	auto it = m_Paths.find(Name);
	if(it == m_Paths.end())
	{
		return false;
	}
	Path = it->second;
	return true;
}

bool CCharacterStateManager::GetPathByIndex(u32 Index, Vector<Vector3>& Path, char** Name)
{
	if(Index > m_Paths.size())
		return false;

	u32 count = 0;
	for(auto it = m_Paths.cbegin(); it != m_Paths.cend(); it++)
	{
		if(count == Index)
		{
			Path = it->second;
			if(Name)
				*Name = (char*)it->first.c_str();
			return true;
		}
	}
	return false;
}

bool CCharacterStateManager::GetPathByPoint(const Vector3& Point, Vector<Vector3>& Path, char** Name)
{
	// Iterate over every point in each path until the same point is found
	for(auto it = m_Paths.cbegin(); it != m_Paths.cend(); it++)
	{
		for(auto i = it->second.cbegin(); i != it->second.cend(); i++)
		{
			if(Point == (*i))
			{
				Path = it->second;
				if(Name)
					*Name = (char*)it->first.c_str();
				return true;
			}
		}
	}
	return false;
}

void CCharacterStateManager::GetAllPaths(PathDefinition& Paths)
{
	Paths = m_Paths;
}

bool CCharacterStateManager::SetName(const char* OldName, const char* NewName)
{
	auto it = m_Paths.find(OldName);
	if(it == m_Paths.end())
	{
		return false;
	}
	
	// Remove the entry and create a new one
	Vector<Vector3> path = it->second;
	m_Paths.erase(it);
	m_Paths[NewName] = path;

	return true;
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::SeekVehicle(CPlayer* Player, const f32& elapsedTime)
{
	f32 radius = Player->GetAiVehicle()->Radius() + Player->GetAiTarget()->Radius();
	return SeekVehicle(Player, elapsedTime, radius);
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::SeekVehicle(CPlayer* Player, const f32& elapsedTime, const f32& Radius)
{
	E_CHARACTER_STATE_OUTCOME state;
	
	// Get the target every time, because it could change
	auto target = Player->GetAiTarget();

	// Do we have a target
	if(!target)
	{
		Player->SetAiTarget(nullptr);
		state = SUCCESS;
		return state;
	}

	const f32 d = Vec3Utilities::distance(Player->GetPlayerNode()->getPosition(), target->Position());
    
	if(d < Radius)
	{
		state = SUCCESS;
	}
	else
	{
		Player->GetAiVehicle()->ApplySteeringForce(Player->GetAiVehicle()->steerForPursuit(*target), elapsedTime);

		// Update position
		MoveVehicle(Player); 
		
		state = WORKING;
	}
	
	return state;
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::SeekPosition(CPlayer* Player, const Vector3& Position, const f32& elapsedTime)
{
	const f32 d = Vec3Utilities::distance(Player->GetPlayerNode()->getPosition(), Position);
	const f32 r = Player->GetAiVehicle()->Radius() /*+ 2.0f*/;	// TODO: should be dynamic
    
	if (d < r)
	{
		return SUCCESS;
	}
	else
	{
		Player->GetAiVehicle()->ApplySteeringForce(Player->GetAiVehicle()->steerForSeek(Position), elapsedTime);

		// Update position
		MoveVehicle(Player);  
	}
	return WORKING;
}

void CCharacterStateManager::Avoidance(CPlayer* Player, Vector3& SteeringAvoidance)
{
	// Get obs list
	Vector<AI::Obstacle*> obs;
	CGameObjectManager::Instance()->GetSphereObstacles(obs);

	// Get walls
	Vector<AI::Wall*> walls;
	CGameObjectManager::Instance()->GetWalls(walls);

	SteeringAvoidance = Player->GetAiVehicle()->steerForWallAvoidance(walls);
	// TODO: Fix and implement this again
	//avoidance += m_Player->GetAiVehicle()->steerToAvoidOabstacles_QuickSphere(obs);
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::Wander(CPlayer* Player, const f32& elapsedTime)
{
	Vector3 steer;
	CCharacterStateManager::Avoidance(Player, steer);

	if (steer == Vector3::ZERO)
	{
		Vector3 wander2d = Player->GetAiVehicle()->steerForWander(elapsedTime);
		wander2d.y = 0;
		steer = Player->GetAiVehicle()->Forward() + (wander2d * 2);	// wander vector * turness
	}
	else
	{
		steer.y = 0;
	}
	
	Player->GetAiVehicle()->ApplySteeringForce(steer, elapsedTime);

	// Update position
	MoveVehicle(Player); 

	CORE_TEXT("forward", "forward:" + StringConverter::toString(Player->GetAiVehicle()->Forward()));
	
	return WORKING;
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::Search(CPlayer* Player, const f32& elapsedTime)
{
	Vector3 steer;
	CCharacterStateManager::Avoidance(Player, steer);

	if (steer == Vector3::ZERO)
	{
		Vector3 wander2d = Player->GetAiVehicle()->steerForWander(elapsedTime);
		wander2d.y = 0;
		steer = Player->GetAiVehicle()->Forward() + (wander2d * 2);	// wander vector * turness
	}
	else
	{
		steer.y = 0;
	}
	
	Player->GetAiVehicle()->ApplySteeringForce(steer, elapsedTime);

	// Update position
	MoveVehicle(Player); 

	CORE_TEXT("forward", "forward:" + StringConverter::toString(Player->GetAiVehicle()->Forward()));
	
	return WORKING;
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::CenterOfMass(const Vector<CPlayer*> Players, CPlayer* Player, const f32& elapsedTime, const f32& MaxDistance, const f32& CosMaxAngle)
{
	// Create an Ai group of vehicles	
	Vector<AbstractVehicle*> aiGroup;
	for(auto it = Players.cbegin(); it != Players.cend(); it++)
		aiGroup.push_back((*it)->GetAiVehicle());

	auto steer = Player->GetAiVehicle()->steerForCohesion(MaxDistance, CosMaxAngle, aiGroup);
	Player->GetAiVehicle()->ApplySteeringForce(steer, elapsedTime);
	
	// Update position
	MoveVehicle(Player); 
	
	return WORKING;
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::AlignWithGroup(const Vector<CPlayer*> Players, CPlayer* Player, const f32& elapsedTime, const f32& MaxDistance, const f32& CosMaxAngle)
{
	// Create an Ai group of vehicles	
	Vector<AbstractVehicle*> aiGroup;
	for(auto it = Players.cbegin(); it != Players.cend(); it++)
		aiGroup.push_back((*it)->GetAiVehicle());

	auto steer = Player->GetAiVehicle()->steerForAlignment(MaxDistance, CosMaxAngle, aiGroup);
	Player->GetAiVehicle()->ApplySteeringForce(steer, elapsedTime);
	
	// Update position
	MoveVehicle(Player);  
	
	return WORKING;
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::SeparateFromGroup(const Vector<CPlayer*> Players, CPlayer* Player, const f32& elapsedTime, const f32& MaxDistance, const f32& CosMaxAngle)
{
	// Create an Ai group of vehicles	
	Vector<AbstractVehicle*> aiGroup;
	for(auto it = Players.cbegin(); it != Players.cend(); it++)
		aiGroup.push_back((*it)->GetAiVehicle());

	auto steer = Player->GetAiVehicle()->steerForSeparation(MaxDistance, CosMaxAngle, aiGroup);
	Player->GetAiVehicle()->ApplySteeringForce(steer, elapsedTime);
	
	// Update position
	MoveVehicle(Player); 
	
	return WORKING;
}

E_CHARACTER_STATE_OUTCOME CCharacterStateManager::EvadeVehicle(CPlayer* Player, CPlayer* Menace, const f32& elapsedTime, const f32& MaxPredictionTime)
{
	Player->GetAiVehicle()->ApplySteeringForce(Player->GetAiVehicle()->steerForEvasion(*Menace->GetAiVehicle(), MaxPredictionTime), elapsedTime);

	// Update position
	MoveVehicle(Player); 
	
	return WORKING;
}

void CCharacterStateManager::MoveVehicle(CPlayer* Player)
{
	Vector3 pos = Vector3(
		Player->GetAiVehicle()->Position().x,
		Player->GetAiVehicle()->Position().y,
		Player->GetAiVehicle()->Position().z);
	Player->SetPlayerPosition(pos);

	Vector3 forwDir = Vector3(
		Player->GetAiVehicle()->Forward().x, 
		/*Player->GetAiVehicle()->forward().y*/ 0.0f, 
		Player->GetAiVehicle()->Forward().z);
	Player->GetPlayerNode()->setDirection(forwDir, Ogre::SceneNode::TS_WORLD, Vector3::UNIT_Z);
}