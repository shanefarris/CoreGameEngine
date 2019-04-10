#include "CGameObjectVeg4_lod1.h"
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

CGameObjectVeg4_lod1::CGameObjectVeg4_lod1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "veg4_lod1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_veg4_lod1leaf2_df");
MaterialManager::getSingleton().getByName("_veg4_lod1leaf2_df")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "VEG4_LOD1";
}

void CGameObjectVeg4_lod1::Update(const f32& elapsedTime)
{
}

CGameObjectVeg4_lod1::~CGameObjectVeg4_lod1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectVeg4_lod1Factory::CGameObjectVeg4_lod1Factory()
{
	GameObjectType = "VEG4_LOD1";
}

CGameObjectVeg4_lod1Factory::~CGameObjectVeg4_lod1Factory()
{
}

Core::CGameObject* CGameObjectVeg4_lod1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectVeg4_lod1(Name, Pos);
}
}
}
