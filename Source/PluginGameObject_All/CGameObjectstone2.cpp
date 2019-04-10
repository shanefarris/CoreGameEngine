#include "CGameObjectStone2.h"
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

CGameObjectStone2::CGameObjectStone2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_stone2stones_df2");
MaterialManager::getSingleton().getByName("_stone2stones_df2")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE2";
}

void CGameObjectStone2::Update(const f32& elapsedTime)
{
}

CGameObjectStone2::~CGameObjectStone2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone2Factory::CGameObjectStone2Factory()
{
	GameObjectType = "STONE2";
}

CGameObjectStone2Factory::~CGameObjectStone2Factory()
{
}

Core::CGameObject* CGameObjectStone2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone2(Name, Pos);
}
}
}
