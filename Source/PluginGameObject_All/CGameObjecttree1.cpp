#include "CGameObjectTree1.h"
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

CGameObjectTree1::CGameObjectTree1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "tree1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_tree1bigtreedf1");
MaterialManager::getSingleton().getByName("_tree1bigtreedf1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "TREE1";
}

void CGameObjectTree1::Update(const f32& elapsedTime)
{
}

CGameObjectTree1::~CGameObjectTree1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectTree1Factory::CGameObjectTree1Factory()
{
	GameObjectType = "TREE1";
}

CGameObjectTree1Factory::~CGameObjectTree1Factory()
{
}

Core::CGameObject* CGameObjectTree1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectTree1(Name, Pos);
}
}
}
