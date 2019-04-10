#include "CGameObjectEmptyBowl.h"
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

CGameObjectEmptyBowl::CGameObjectEmptyBowl(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "EmptyBowl.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("foodbowlmat");
MaterialManager::getSingleton().getByName("foodbowlmat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "EMPTYBOWL";
}

void CGameObjectEmptyBowl::Update(const f32& elapsedTime)
{
}

CGameObjectEmptyBowl::~CGameObjectEmptyBowl()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectEmptyBowlFactory::CGameObjectEmptyBowlFactory()
{
	GameObjectType = "EMPTYBOWL";
}

CGameObjectEmptyBowlFactory::~CGameObjectEmptyBowlFactory()
{
}

Core::CGameObject* CGameObjectEmptyBowlFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectEmptyBowl(Name, Pos);
}
}
}
