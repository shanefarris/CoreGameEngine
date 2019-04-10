#include "CGameObjectStone_wall3.h"
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

CGameObjectStone_wall3::CGameObjectStone_wall3(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone_wall3.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("stonewall3");
MaterialManager::getSingleton().getByName("stonewall3")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE_WALL3";
}

void CGameObjectStone_wall3::Update(const f32& elapsedTime)
{
}

CGameObjectStone_wall3::~CGameObjectStone_wall3()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone_wall3Factory::CGameObjectStone_wall3Factory()
{
	GameObjectType = "STONE_WALL3";
}

CGameObjectStone_wall3Factory::~CGameObjectStone_wall3Factory()
{
}

Core::CGameObject* CGameObjectStone_wall3Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone_wall3(Name, Pos);
}
}
}
