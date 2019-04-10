#include "CNavMeshVehicle.h"
#include "CPlayer.h"
#include "CGameManager.h"

#include "NavMesh/DetourCrowd.h"
#include "NavMesh/OgreDetourCrowd.h"
#include "NavMesh/OgreDetourTileCache.h"

#include "Terrain/OgreTerrainGroup.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::AI::NavMesh;

CNavMeshVehicle::CNavMeshVehicle(CPlayer* Player, OgreDetourCrowd* detourCrowd)
	: m_Player(Player),
	m_DetourCrowd(detourCrowd),
	m_Agent(nullptr),
	m_AgentId(-1),
	m_ManualVelocity(Vector3::ZERO),
	m_Destination(detourCrowd->getLastDestination()),
	isStopped(false),
	isAgentControlled(true),
	m_DetourTileCache(nullptr),
	m_TempObstacle(0),
	m_ClipTo(nullptr),
	m_RaySceneQuery(nullptr),
	m_DebugNode(nullptr),
	m_DestinationRadius(0.1f * 0.1f)
{
	Load(m_Player->GetPosition());
}

CNavMeshVehicle::~CNavMeshVehicle()
{
	Unload();
}

void CNavMeshVehicle::GetDestination(Vector3& Destination) const
{
	if (isAgentControlled && IsLoaded())
		Destination = m_Destination;
	else
		Destination = INVALID_POS;
}

void CNavMeshVehicle::SetPosition(Vector3& Position)
{
	if(!isAgentControlled || !IsLoaded()) 
	{
		m_Player->SetPlayerPosition(Position);
		return;
	}

	// Find position on navmesh
	if (!m_DetourCrowd->m_recast->findNearestPointOnNavmesh(Position, Position))
		return;

	// Remove agent from crowd and re-add at position
	m_DetourCrowd->removeAgent(m_AgentId);
	m_AgentId = m_DetourCrowd->addAgent(Position);
	m_Agent = m_DetourCrowd->getAgent(m_AgentId);

	if(m_Player->GetPlayerNode())   // TODO remove this check by initing mNode in this class' constructor
		m_Player->GetPlayerNode()->setPosition(Position);
}

void CNavMeshVehicle::UpdateDestination(Vector3& Destination, bool UpdatePreviousPath)
{
	if(!isAgentControlled || !IsLoaded())
		return;

	// Find position on navmesh
	if(!m_DetourCrowd->m_recast->findNearestPointOnNavmesh(Destination, Destination))
		return;

	m_DetourCrowd->setMoveTarget(m_AgentId, Destination, UpdatePreviousPath);
	m_Destination = Destination;
	isStopped = false;
	m_ManualVelocity = Vector3::ZERO;
}

void CNavMeshVehicle::UpdatePosition(const f32& ElapsedTime)
{
	if(!IsLoaded())
		return;

	if (isAgentControlled) 
	{
		if(GetAgent()->active) 
		{
			Vector3 agentPos;
			OgreRecast::FloatAToOgreVect3(GetAgent()->npos, agentPos);

			m_Player->GetPlayerNode()->setPosition(agentPos);
		}
	} 
	else 
	{
		// Move character manually to new position
		Vector3 velocity;
		GetVelocity(velocity);
		if(velocity.isZeroLength())
			return;

		// Make other agents avoid first character by placing a temporary obstacle in its position
		m_DetourTileCache->removeTempObstacle(m_TempObstacle);   // Remove old obstacle
		m_Player->GetPlayerNode()->setPosition(m_Player->GetPosition() + ElapsedTime * velocity);
		// TODO check whether this position is within navmesh
		m_TempObstacle = m_DetourTileCache->addTempObstacle(m_Player->GetPosition());   // Add new obstacle
	}

	// Clip position to terrain height
	if (m_ClipTo)
		ClipToTerrainHeight();
}

void CNavMeshVehicle::ClipToTerrain(TerrainGroup* terrainGroup)
{
	m_ClipTo = terrainGroup;
}

void CNavMeshVehicle::ClipToTerrainHeight()
{
	// Setup the scene query
	Ray queryRay(m_Player->GetPlayerNode()->getPosition(), Vector3::NEGATIVE_UNIT_Y);

	// Perform the scene query
	TerrainGroup::RayResult result = m_ClipTo->rayIntersects(queryRay);
	if(result.hit) 
	{
		Real terrainHeight = result.position.y;

		Vector3 pos = m_Player->GetPlayerNode()->getPosition();
		pos.y = terrainHeight;
		m_Player->GetPlayerNode()->setPosition(pos);
	} 
	else 
	{
		// Try querying terrain above character
		queryRay.setOrigin(m_Player->GetPlayerNode()->getPosition());
		queryRay.setDirection(Vector3::UNIT_Y);

		// Perform scene query again
		result = m_ClipTo->rayIntersects(queryRay);
		if(result.hit) 
		{
			Real terrainHeight = result.position.y;

			Vector3 pos = m_Player->GetPlayerNode()->getPosition();
			pos.y = terrainHeight;
			m_Player->GetPlayerNode()->setPosition(pos);
		}
	}
}

bool CNavMeshVehicle::DestinationReached() const
{
	Vector3 destination;
	GetDestination(destination);
	return (m_Player->GetPlayerNode()->getPosition().squaredDistance(destination) <= m_DestinationRadius);
}

void CNavMeshVehicle::SetDestination(const Vector3& Destination)
{
	if (!isAgentControlled || !IsLoaded())
		return;

	m_Destination = Destination;
	m_ManualVelocity = Vector3::ZERO;
	isStopped = false;
}

void CNavMeshVehicle::Stop()
{
	if(!isAgentControlled || !IsLoaded()) 
	{
		m_ManualVelocity = Vector3::ZERO;
		isStopped = true;
		return;
	}

	if(m_DetourCrowd->stopAgent(GetAgentId())) 
	{
		m_Destination = INVALID_POS;
		m_ManualVelocity = Vector3::ZERO;
		isStopped = true;
	}
}

void CNavMeshVehicle::MoveForward()
{
	auto lookDirection = m_Player->GetDirection();
	lookDirection.normalise();

	SetVelocity(GetMaxSpeed() * lookDirection);
}

void CNavMeshVehicle::SetVelocity(const Vector3& Velocity)
{
	m_ManualVelocity = Velocity;
	isStopped = false;
	m_Destination = INVALID_POS;

	if(isAgentControlled && IsLoaded())
		m_DetourCrowd->requestVelocity(GetAgentId(), m_ManualVelocity);
}

void CNavMeshVehicle::GetVelocity(Vector3& Velocity)
{
	if(!IsLoaded())
	{
		Velocity = INVALID_POS;
	}

	if(isAgentControlled) 
	{
		Vector3 velocity;
		OgreRecast::FloatAToOgreVect3(GetAgent()->nvel, velocity);
		Velocity = velocity;
	} 
	else 
	{
		Velocity = m_ManualVelocity;
	}
}

f32 CNavMeshVehicle::GetMaxSpeed()
{
	if(IsLoaded())
		return GetAgent()->params.maxSpeed;
	else
		return 0.0f;
}

f32 CNavMeshVehicle::GetMaxAcceleration()
{
	if(IsLoaded())
		return GetAgent()->params.maxAcceleration;
	else
		return 0.0f;
}

bool CNavMeshVehicle::IsMoving()
{
	Vector3 velocity;
	GetVelocity(velocity);
	auto speed = velocity.length();
	return !isStopped || speed != 0;
}

void CNavMeshVehicle::SetDetourTileCache(OgreDetourTileCache *dtTileCache)
{
	m_DetourTileCache = dtTileCache;
}

void CNavMeshVehicle::Load()
{
	if(IsLoaded())
		return; // nothing to do

	Load(m_Player->GetPosition());
}

void CNavMeshVehicle::Load(Vector3& Position)
{
	if(IsLoaded()) 
	{
		SetPosition(Position);
	} 
	else
	{
		m_AgentId = m_DetourCrowd->addAgent(Position);
		m_Agent = m_DetourCrowd->getAgent(m_AgentId);
	}

	SetPosition(Position);
}

void CNavMeshVehicle::Unload()
{
	m_DetourCrowd->removeAgent(GetAgentId());
	m_AgentId = -1;
	m_Agent = nullptr;
}

void CNavMeshVehicle::SetDebugVisibility(bool Visible)
{
	m_DebugNode->setVisible(Visible);
}

void CNavMeshVehicle::SetAgentControlled(bool AgentControlled)
{
	if (isAgentControlled != AgentControlled) 
	{
		if (AgentControlled) 
		{
			if(m_TempObstacle)
				m_DetourTileCache->removeTempObstacle(m_TempObstacle);

			m_TempObstacle = 0;
			m_AgentId = m_DetourCrowd->addAgent(m_Player->GetPosition());
			m_Destination = m_DetourCrowd->getLastDestination();
			m_ManualVelocity = Vector3::ZERO;
			isStopped = true;
		} 
		else 
		{
			m_TempObstacle = m_DetourTileCache->addTempObstacle(m_Player->GetPosition());   // Add temp obstacle at current position
			m_DetourCrowd->removeAgent(m_AgentId);
			m_AgentId = -1;
			m_Destination = INVALID_POS;
			isStopped = false;
		}
		isAgentControlled = AgentControlled;
	}
}

void CNavMeshVehicle::Update(const f32& elapsedTime)
{
	UpdatePosition(elapsedTime);

	if (m_ClipTo)
		ClipToTerrainHeight();
}