#include "CGameObjectVeg1.h"
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

CGameObjectVeg1::CGameObjectVeg1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "veg1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_veg1leaf33");
MaterialManager::getSingleton().getByName("_veg1leaf33")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "VEG1";
}

void CGameObjectVeg1::Update(const f32& elapsedTime)
{
}

CGameObjectVeg1::~CGameObjectVeg1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectVeg1Factory::CGameObjectVeg1Factory()
{
	GameObjectType = "VEG1";
}

CGameObjectVeg1Factory::~CGameObjectVeg1Factory()
{
}

Core::CGameObject* CGameObjectVeg1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectVeg1(Name, Pos);
}
}
}
