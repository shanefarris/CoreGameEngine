#include "CGameObjectFlowerplant_lod0.h"
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

CGameObjectFlowerplant_lod0::CGameObjectFlowerplant_lod0(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "flowerplant_lod0.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("flowerplant");
MaterialManager::getSingleton().getByName("flowerplant")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "FLOWERPLANT_LOD0";
}

void CGameObjectFlowerplant_lod0::Update(const f32& elapsedTime)
{
}

CGameObjectFlowerplant_lod0::~CGameObjectFlowerplant_lod0()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectFlowerplant_lod0Factory::CGameObjectFlowerplant_lod0Factory()
{
	GameObjectType = "FLOWERPLANT_LOD0";
}

CGameObjectFlowerplant_lod0Factory::~CGameObjectFlowerplant_lod0Factory()
{
}

Core::CGameObject* CGameObjectFlowerplant_lod0Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectFlowerplant_lod0(Name, Pos);
}
}
}
