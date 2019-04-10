#include "CGameObjectTree3.h"
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

CGameObjectTree3::CGameObjectTree3(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "tree3.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_tree3bigtreedf1");
MaterialManager::getSingleton().getByName("_tree3bigtreedf1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "TREE3";
}

void CGameObjectTree3::Update(const f32& elapsedTime)
{
}

CGameObjectTree3::~CGameObjectTree3()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectTree3Factory::CGameObjectTree3Factory()
{
	GameObjectType = "TREE3";
}

CGameObjectTree3Factory::~CGameObjectTree3Factory()
{
}

Core::CGameObject* CGameObjectTree3Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectTree3(Name, Pos);
}
}
}
