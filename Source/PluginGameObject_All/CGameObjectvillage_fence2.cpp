#include "CGameObjectVillage_fence2.h"
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

CGameObjectVillage_fence2::CGameObjectVillage_fence2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "village_fence2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("villagefence2");
MaterialManager::getSingleton().getByName("villagefence2")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "VILLAGE_FENCE2";
}

void CGameObjectVillage_fence2::Update(const f32& elapsedTime)
{
}

CGameObjectVillage_fence2::~CGameObjectVillage_fence2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectVillage_fence2Factory::CGameObjectVillage_fence2Factory()
{
	GameObjectType = "VILLAGE_FENCE2";
}

CGameObjectVillage_fence2Factory::~CGameObjectVillage_fence2Factory()
{
}

Core::CGameObject* CGameObjectVillage_fence2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectVillage_fence2(Name, Pos);
}
}
}
