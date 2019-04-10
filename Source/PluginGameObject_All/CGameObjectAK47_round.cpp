#include "CGameObjectAK47_round.h"
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "IPhysicsStrategy.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"


using namespace Core;

namespace Core
{
namespace Plugin
{

CGameObjectAK47_round::CGameObjectAK47_round(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "AK47_round.mesh");
	Entity->setQueryFlags(0);
	Node->attachObject(Entity);
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "AK47_ROUND";
}

void CGameObjectAK47_round::Update(const f32& elapsedTime)
{
}

CGameObjectAK47_round::~CGameObjectAK47_round()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAK47_roundFactory::CGameObjectAK47_roundFactory()
{
	GameObjectType = "AK47_ROUND";
}

CGameObjectAK47_roundFactory::~CGameObjectAK47_roundFactory()
{
}

Core::CGameObject* CGameObjectAK47_roundFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAK47_round(Name, Pos);
}
}
}
