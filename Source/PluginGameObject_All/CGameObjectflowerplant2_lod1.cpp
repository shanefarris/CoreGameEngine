#include "CGameObjectFlowerplant2_lod1.h"
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

CGameObjectFlowerplant2_lod1::CGameObjectFlowerplant2_lod1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "flowerplant2_lod1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("flowerplant2");
MaterialManager::getSingleton().getByName("flowerplant2")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "FLOWERPLANT2_LOD1";
}

void CGameObjectFlowerplant2_lod1::Update(const f32& elapsedTime)
{
}

CGameObjectFlowerplant2_lod1::~CGameObjectFlowerplant2_lod1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectFlowerplant2_lod1Factory::CGameObjectFlowerplant2_lod1Factory()
{
	GameObjectType = "FLOWERPLANT2_LOD1";
}

CGameObjectFlowerplant2_lod1Factory::~CGameObjectFlowerplant2_lod1Factory()
{
}

Core::CGameObject* CGameObjectFlowerplant2_lod1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectFlowerplant2_lod1(Name, Pos);
}
}
}
