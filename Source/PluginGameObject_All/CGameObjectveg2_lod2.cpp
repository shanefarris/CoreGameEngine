#include "CGameObjectVeg2_lod2.h"
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

CGameObjectVeg2_lod2::CGameObjectVeg2_lod2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "veg2_lod2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_veg2_lod2leaf33");
MaterialManager::getSingleton().getByName("_veg2_lod2leaf33")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "VEG2_LOD2";
}

void CGameObjectVeg2_lod2::Update(const f32& elapsedTime)
{
}

CGameObjectVeg2_lod2::~CGameObjectVeg2_lod2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectVeg2_lod2Factory::CGameObjectVeg2_lod2Factory()
{
	GameObjectType = "VEG2_LOD2";
}

CGameObjectVeg2_lod2Factory::~CGameObjectVeg2_lod2Factory()
{
}

Core::CGameObject* CGameObjectVeg2_lod2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectVeg2_lod2(Name, Pos);
}
}
}
