#include "CGameObjectTree2.h"
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

CGameObjectTree2::CGameObjectTree2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "tree2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_tree2bigtreedf1");
MaterialManager::getSingleton().getByName("_tree2bigtreedf1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "TREE2";
}

void CGameObjectTree2::Update(const f32& elapsedTime)
{
}

CGameObjectTree2::~CGameObjectTree2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectTree2Factory::CGameObjectTree2Factory()
{
	GameObjectType = "TREE2";
}

CGameObjectTree2Factory::~CGameObjectTree2Factory()
{
}

Core::CGameObject* CGameObjectTree2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectTree2(Name, Pos);
}
}
}
