#include "CGameObjectCrate3.h"
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

CGameObjectCrate3::CGameObjectCrate3(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Crate3.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("mat_woodbox4_5_1");
MaterialManager::getSingleton().getByName("mat_woodbox4_5_1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "CRATE3";
}

void CGameObjectCrate3::Update(const f32& elapsedTime)
{
}

CGameObjectCrate3::~CGameObjectCrate3()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectCrate3Factory::CGameObjectCrate3Factory()
{
	GameObjectType = "CRATE3";
}

CGameObjectCrate3Factory::~CGameObjectCrate3Factory()
{
}

Core::CGameObject* CGameObjectCrate3Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectCrate3(Name, Pos);
}
}
}
