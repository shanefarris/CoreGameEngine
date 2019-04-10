#include "CGameObjectFryingPan.h"
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

CGameObjectFryingPan::CGameObjectFryingPan(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "FryingPan.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("fryingpanmat");
MaterialManager::getSingleton().getByName("fryingpanmat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "FRYINGPAN";
}

void CGameObjectFryingPan::Update(const f32& elapsedTime)
{
}

CGameObjectFryingPan::~CGameObjectFryingPan()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectFryingPanFactory::CGameObjectFryingPanFactory()
{
	GameObjectType = "FRYINGPAN";
}

CGameObjectFryingPanFactory::~CGameObjectFryingPanFactory()
{
}

Core::CGameObject* CGameObjectFryingPanFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectFryingPan(Name, Pos);
}
}
}
