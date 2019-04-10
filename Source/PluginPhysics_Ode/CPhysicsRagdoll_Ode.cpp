#include "CPhysicsRagdoll_Ode.h"
#include "CPlayer.h"
#include "CGameManager.h"
#include "CProjectile.h"
#include "CWeapon.h"

#include "Wrapper/Body.h"
#include "Wrapper/Geometry.h"
#include "Wrapper/World.h"
#include "Wrapper/Prefab/DotLoader.h"
#include "Wrapper/Prefab/Vehicle.h"
#include "Wrapper/Prefab/Ragdoll.h"

#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreStringConverter.h"

using namespace Core;
using namespace Core::Physics;

u32 CPhysicsRagdoll_Ode::ragdoll_count = 0;

CPhysicsRagdoll_Ode::CPhysicsRagdoll_Ode(CPlayer* Player, Ode::World* World, Ode::DotLoader* DotLoader, const CRagdollBoneInformation& RagdollBoneInformation)
{
	m_World = World;
	counter = 0;
	// Remember: needs to have the skeleton, and the node needs to be attached to the 
	// parent before "takePhysicalControl" will execute correctly

	// Load the ragdoll
	String ragdollName = RagdollBoneInformation.ConfigFile;
	String objectName = RagdollBoneInformation.ConfigOptions[0];
	m_Ragdoll = static_cast <Ode::Ragdoll*>(DotLoader->loadObject(ragdollName, objectName, ragdollName + StringConverter::toString(ragdoll_count++)));

	// Did we create a successful ragdoll
	if(m_Ragdoll)
	{
		// Attach the object.  Ragdoll is an inherited entity
		entity = static_cast<Entity*>(m_Ragdoll);
		Player->GetPlayerNode()->attachObject(entity);
	}
}

CPhysicsRagdoll_Ode::~CPhysicsRagdoll_Ode()
{
	// m_Ragdoll inherits from Entity so it can't just be deleted.
	m_Ragdoll->releasePhysicalControl();
	CGameManager::Instance()->GetSceneManager()->destroyEntity(m_Ragdoll);
}

void CPhysicsRagdoll_Ode::Update(const f32& elapsedTime)
{
	if (m_Ragdoll->isPhysical() && 
		!m_Ragdoll->isStatic() && 
		m_Ragdoll->isAwake() && 
		m_Ragdoll->_timeSincePhysical > 5.0)
	{
		//radgoll->turnToStone();
		m_Ragdoll->sleep();
	}
	else if (m_Ragdoll->isPhysical())
    {
        if (!m_Ragdoll->isStatic())
        {
			m_Ragdoll->_timeSincePhysical += elapsedTime;
            m_Ragdoll->update();	// RagDoll Activated
        }
    }
}

bool CPhysicsRagdoll_Ode::Pick(CProjectile* Projectile)
{
	if(m_Ragdoll && Projectile)
	{
		auto ray = new Ode::RayGeometry(10.0f, m_World, m_World->getDefaultSpace());
		ray->setDefinition(*Projectile->GetPosition(), *Projectile->GetDirection());

		Ode::Body* body = nullptr;
		Vector3 position;
		if(m_Ragdoll->pickRagdoll(ray, body, position))
		{
			if(body)
			{
				body->addForceAt(*Projectile->GetDirection() * (Projectile->GetWeapon()->Power * 10000.0f), position);
				return true;
			}
		}
	}
	return false;
}

void CPhysicsRagdoll_Ode::TakePhysicalControl()
{
	if(m_Ragdoll)
	{
		m_Ragdoll->takePhysicalControl(m_World, m_World->getDefaultSpace(), false /* Is this static */);
		m_Ragdoll->setSelfCollisions(true);
		m_Ragdoll->_timeSincePhysical = 0.0f;
	}
}