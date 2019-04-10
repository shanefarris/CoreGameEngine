#include "CGameObjectCrate01.h"
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

CGameObjectCrate01::CGameObjectCrate01(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "crate01.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
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

	GameObjectType = "CRATE01";
}

void CGameObjectCrate01::Update(const f32& elapsedTime)
{
}

CGameObjectCrate01::~CGameObjectCrate01()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectCrate01Factory::CGameObjectCrate01Factory()
{
	GameObjectType = "CRATE01";
}

CGameObjectCrate01Factory::~CGameObjectCrate01Factory()
{
}

Core::CGameObject* CGameObjectCrate01Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectCrate01(Name, Pos);
}
}
}
