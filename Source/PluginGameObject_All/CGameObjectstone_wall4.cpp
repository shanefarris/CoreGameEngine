#include "CGameObjectStone_wall4.h"
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

CGameObjectStone_wall4::CGameObjectStone_wall4(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone_wall4.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("stonewall4");
MaterialManager::getSingleton().getByName("stonewall4")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE_WALL4";
}

void CGameObjectStone_wall4::Update(const f32& elapsedTime)
{
}

CGameObjectStone_wall4::~CGameObjectStone_wall4()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone_wall4Factory::CGameObjectStone_wall4Factory()
{
	GameObjectType = "STONE_WALL4";
}

CGameObjectStone_wall4Factory::~CGameObjectStone_wall4Factory()
{
}

Core::CGameObject* CGameObjectStone_wall4Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone_wall4(Name, Pos);
}
}
}
