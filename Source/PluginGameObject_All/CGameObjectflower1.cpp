#include "CGameObjectFlower1.h"
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

CGameObjectFlower1::CGameObjectFlower1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "flower1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_flower1blossom1");
MaterialManager::getSingleton().getByName("_flower1blossom1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "FLOWER1";
}

void CGameObjectFlower1::Update(const f32& elapsedTime)
{
}

CGameObjectFlower1::~CGameObjectFlower1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectFlower1Factory::CGameObjectFlower1Factory()
{
	GameObjectType = "FLOWER1";
}

CGameObjectFlower1Factory::~CGameObjectFlower1Factory()
{
}

Core::CGameObject* CGameObjectFlower1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectFlower1(Name, Pos);
}
}
}
