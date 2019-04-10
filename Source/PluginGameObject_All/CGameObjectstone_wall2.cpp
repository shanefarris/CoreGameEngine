#include "CGameObjectStone_wall2.h"
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

CGameObjectStone_wall2::CGameObjectStone_wall2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone_wall2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("stonewall2");
MaterialManager::getSingleton().getByName("stonewall2")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE_WALL2";
}

void CGameObjectStone_wall2::Update(const f32& elapsedTime)
{
}

CGameObjectStone_wall2::~CGameObjectStone_wall2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone_wall2Factory::CGameObjectStone_wall2Factory()
{
	GameObjectType = "STONE_WALL2";
}

CGameObjectStone_wall2Factory::~CGameObjectStone_wall2Factory()
{
}

Core::CGameObject* CGameObjectStone_wall2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone_wall2(Name, Pos);
}
}
}
