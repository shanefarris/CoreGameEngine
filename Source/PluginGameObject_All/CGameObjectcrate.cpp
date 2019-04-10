#include "CGameObjectCrate.h"
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "IPhysicsStrategy.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreMaterialManager.h"


using namespace Core;

namespace Core
{
namespace Plugin
{

CGameObjectCrate::CGameObjectCrate(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "crate.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("ac3d/crate/mat001_tex00");
MaterialManager::getSingleton().getByName("ac3d/crate/mat001_tex00")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "CRATE";
}

void CGameObjectCrate::Update(const f32& elapsedTime)
{
}

CGameObjectCrate::~CGameObjectCrate()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectCrateFactory::CGameObjectCrateFactory()
{
	GameObjectType = "CRATE";
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
