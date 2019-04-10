#include "CGameObjectCrate.h"
#include "CGameManager.h"
#include "CGameObject.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"

using namespace Core;

namespace Core
{
namespace Plugin
{
CGameObjectCrate::CGameObjectCrate(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	CGameManager* gm = CGameManager::Instance();
	SceneManager* sm = gm->GetSceneManager();
	Node = sm->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Node->setScale(1, 1, 1);
	Entity = sm->createEntity(Name + String("_entity"), "crate.mesh");
	Node->attachObject(Entity);

	// TODO: customize phyics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	// ===================================

	GameObjectType = "CRATE_1";
}

void CGameObjectCrate::Update(const f32& elapsedTime)
{
	std::cerr << "create update" << std::endl;
}

CGameObjectCrate::~CGameObjectCrate()
{
}

CGameObjectCrateFactory::CGameObjectCrateFactory()
{
	GameObjectType = "CRATE_1";
}

CGameObjectCrateFactory::~CGameObjectCrateFactory()
{
}

Core::CGameObject* CGameObjectCrateFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectCrate(Name, Pos);
}


}
}