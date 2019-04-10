#include "CSpawnManager.h"
#include "Structures.h"
#include "CPlayer.h"
#include "IO/CoreLogging.h"

using namespace Core;

CSpawnManager* CSpawnManager::SpawnManager = nullptr;

CSpawnManager* CSpawnManager::Instance()
{
	if(SpawnManager == nullptr)
		SpawnManager = new CSpawnManager();
	return SpawnManager;
}

CSpawnManager::CSpawnManager() : m_SpawnPointIndex(1)
{
}

CSpawnManager::~CSpawnManager()
{
	try
	{
		for(auto it = m_SpawnPoints.begin(); it != m_SpawnPoints.end();)
		{
			CORE_DELETE((*it).second);
		}
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CSpawnManager()");
	}
}

u32 CSpawnManager::AddSpawnPoint(const Vector3& Position, E_PLAYER_TEAM Team, const f32& CoolDown)
{
	return AddSpawnPoint(m_SpawnPointIndex, Position, Team, CoolDown);
}

u32 CSpawnManager::AddSpawnPoint(u32 Id, const Vector3& Position, E_PLAYER_TEAM Team, const f32& CoolDown)
{
	if(m_SpawnPoints.find(Id) == m_SpawnPoints.end())
	{
		auto sp = new SPAWN_POINT();
		sp->Id = Id;
		sp->Position = Position;
		sp->Team = Team;

		m_SpawnPoints[Id] = sp;
	
		// Get next free id
		for(auto it = m_SpawnPoints.begin(); it != m_SpawnPoints.end();)
		{
			if((*it).second->Id != ++m_SpawnPointIndex)
				break;
		}

		return sp->Id;
	}
	return 0;
}

bool CSpawnManager::RemoveSpawnPoint(u32 Id)
{
	m_SpawnPoints.erase(Id);
	return true;
}

Map<u32, SPAWN_POINT*>& CSpawnManager::GetAllSpawnPoints()
{
	return m_SpawnPoints;
}

SPAWN_POINT* CSpawnManager::GetSpawnPoint(u32 Id)
{
	auto it = m_SpawnPoints.find(Id);
	if(it != m_SpawnPoints.end())
		return (*it).second;
	return nullptr;
}

SPAWN_POINT* CSpawnManager::GetSpawnPoint(const Vector3& Position, const f32& Threshold)
{
	Vector3 currentPoint = INVALID_POS;
	SPAWN_POINT* spawnPoint = nullptr;

	for(auto it = m_SpawnPoints.begin(); it != m_SpawnPoints.end(); it++)
	{
		if((*it).second->Position.distance(Position) < currentPoint.distance(Position))
		{
			currentPoint = (*it).second->Position;
			if(Threshold > 0.0f)
			{
				if(currentPoint.distance(Position) <= Threshold)
				{
					return (*it).second;
				}
			}
			spawnPoint = (*it).second;
		}
	}
	return spawnPoint;
}

bool CSpawnManager::SpawnPlayer(u32 Id, CPlayer* Player)
{
	auto spawnPoint = GetSpawnPoint(Id);
	if(spawnPoint)
	{
		Player->SetPlayerPosition(spawnPoint->Position);
		return true;
	}
	return false;
}

bool CSpawnManager::SpawnPlayer(const Vector3& Position, const f32& Threshold, CPlayer* Player)
{
	auto spawnPoint = GetSpawnPoint(Position, Threshold);
	if(spawnPoint)
	{
		Player->SetPlayerPosition(spawnPoint->Position);
		return true;
	}
	return false;
}
