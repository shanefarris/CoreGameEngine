#include "CBuilding.h"
#include "CGameManager.h"
#include "CProjectile.h"
#include "CPlayer.h"
#include "CInventoryItem.h"
#include "CGameObject.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "CoreStructures.h"
#include "IO/CoreLogging.h"

// AI
#include "Ai/CFpsVehicle.h"
#include "CLineOfSightStrategy_Defaults.h"

// Ogre
#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"

using namespace Core;

CBuilding::CBuilding(const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy)
	: m_BuildingNode(nullptr),
	m_BuildingEntity(nullptr),
	m_Health(100.0f),
	m_ViewRange(10.0f),
	m_BuildingState(EBS_IDLE),
	m_AbstractVehicle(nullptr),
	m_Target(nullptr),
	Name(LabelName),
	isDestroyed(false),
	m_BuildingCategory(EBC_OTHER),
	m_PhysicsStrategy(PhysicsStrategy),
	m_LoadType(ELT_NONE)
{
}

CBuilding::~CBuilding()
{
	try
	{
		// Remove all game objects
		while(m_GameObjects.size() > 0)
		{
			m_PhysicsStrategy->DestroyPhysicsBody(m_GameObjects[0]);
			CORE_DELETE(m_GameObjects[0]);
			m_GameObjects.erase(m_GameObjects.begin());
		}

		CORE_DELETE(m_Target);
		CORE_DELETE(m_AbstractVehicle);
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CBuilding()");
	}
}

void CBuilding::UpdateDefault(const f32& elapsedTime)
{
}

void CBuilding::PostInit()
{
}

void CBuilding::OnHit(CProjectile* Projectile, const Vector3& Direction)
{
	if(Projectile)
	{
		m_Health -= Projectile->GetDamage();

		// Find if player is dead
		if(m_Health <= 0.0f && isDestroyed == false)
		{
			isDestroyed = true;

			m_Health = 0.0f;
		}
	}
}

void CBuilding::OnHit(CInventoryItem* InventoryItem, CPlayer* Owner, const Vector3& Direction)
{
	if(InventoryItem && Owner)
	{
		m_Health -= InventoryItem->Power;
		// Find if player is dead
		if(m_Health <= 0.0f && isDestroyed == false)
		{
			isDestroyed = true;

			m_Health = 0.0f;
		}
	}
}

void CBuilding::OnKill(CPlayer* PlayerKilled, CProjectile* Projectile)
{
}

void CBuilding::OnKill(CPlayer* PlayerKilled, CInventoryItem* InventoryItem)
{
}

SceneNode* CBuilding::GetNode()
{
	return m_BuildingNode;
}

Entity* CBuilding::GetEntity()
{
	return m_BuildingEntity;
}

f32 CBuilding::GetHealth()
{
	return m_Health;
}

f32 CBuilding::GetViewRange()
{
	return m_ViewRange;
}

E_BUILDING_STATE CBuilding::GetState()
{
	return m_BuildingState;
}

AI::CFpsVehicle* CBuilding::GetAiVehicle()
{
	return m_AbstractVehicle;
}

E_PLAYER_TEAM CBuilding::GetTeam()
{
	return m_Team;
}

Vector3 CBuilding::GetPosition()
{
	return m_BuildingNode->getPosition();
}

AI::CFpsVehicle* CBuilding::GetAiTarget()
{
	return m_Target;
}

void CBuilding::SetPosition(const Vector3& Position)
{
	// TODO: all game objects will need to be updated based on an offset
	if(m_PhysicsStrategy && m_GameObjects.size() > 0)
	{
		m_PhysicsStrategy->SetPosition(m_GameObjects[0], Position);
	}

	if(m_BuildingNode)
	{
		m_BuildingNode->setPosition(Position);
	}
}

bool CBuilding::CanSee(const Vector3& Position)
{
	// TODO
	return false;
}

void CBuilding::AddItem(CInventoryItem* Item)
{
	// TODO
}

void CBuilding::RemoveItem(CInventoryItem* Item)
{
	// TODO
}

void CBuilding::RemoveAllItems()
{
	// TODO
}

void CBuilding::UseItem(CPlayer* Player, CInventoryItem* Item )
{
	// TODO
}