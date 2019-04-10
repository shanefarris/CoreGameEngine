#include "CGameObjectStairs3.h"
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

CGameObjectStairs3::CGameObjectStairs3(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Stairs3.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("floor03_d");
MaterialManager::getSingleton().getByName("floor03_d")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STAIRS3";
}

void CGameObjectStairs3::Update(const f32& elapsedTime)
{
}

CGameObjectStairs3::~CGameObjectStairs3()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStairs3Factory::CGameObjectStairs3Factory()
{
	GameObjectType = "STAIRS3";
}

CGameObjectStairs3Factory::~CGameObjectStairs3Factory()
{
}

Core::CGameObject* CGameObjectStairs3Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStairs3(Name, Pos);
}
}
}
