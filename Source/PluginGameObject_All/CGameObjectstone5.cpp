#include "CGameObjectStone5.h"
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

CGameObjectStone5::CGameObjectStone5(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone5.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_stone5stones_df");
MaterialManager::getSingleton().getByName("_stone5stones_df")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE5";
}

void CGameObjectStone5::Update(const f32& elapsedTime)
{
}

CGameObjectStone5::~CGameObjectStone5()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone5Factory::CGameObjectStone5Factory()
{
	GameObjectType = "STONE5";
}

CGameObjectStone5Factory::~CGameObjectStone5Factory()
{
}

Core::CGameObject* CGameObjectStone5Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone5(Name, Pos);
}
}
}
