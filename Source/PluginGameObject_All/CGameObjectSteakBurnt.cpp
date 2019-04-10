#include "CGameObjectSteakBurnt.h"
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

CGameObjectSteakBurnt::CGameObjectSteakBurnt(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "SteakBurnt.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("meatsteakburntmat");
MaterialManager::getSingleton().getByName("meatsteakburntmat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STEAKBURNT";
}

void CGameObjectSteakBurnt::Update(const f32& elapsedTime)
{
}

CGameObjectSteakBurnt::~CGameObjectSteakBurnt()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectSteakBurntFactory::CGameObjectSteakBurntFactory()
{
	GameObjectType = "STEAKBURNT";
}

CGameObjectSteakBurntFactory::~CGameObjectSteakBurntFactory()
{
}

Core::CGameObject* CGameObjectSteakBurntFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectSteakBurnt(Name, Pos);
}
}
}
