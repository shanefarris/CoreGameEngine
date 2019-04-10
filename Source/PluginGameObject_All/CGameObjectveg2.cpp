#include "CGameObjectVeg2.h"
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

CGameObjectVeg2::CGameObjectVeg2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "veg2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_veg2leaf33");
MaterialManager::getSingleton().getByName("_veg2leaf33")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "VEG2";
}

void CGameObjectVeg2::Update(const f32& elapsedTime)
{
}

CGameObjectVeg2::~CGameObjectVeg2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectVeg2Factory::CGameObjectVeg2Factory()
{
	GameObjectType = "VEG2";
}

CGameObjectVeg2Factory::~CGameObjectVeg2Factory()
{
}

Core::CGameObject* CGameObjectVeg2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectVeg2(Name, Pos);
}
}
}
