#include "CGameObjectConstruct.h"
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

CGameObjectConstruct::CGameObjectConstruct(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "construct.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("mat_woodbox_5_1");
MaterialManager::getSingleton().getByName("mat_woodbox_5_1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "CONSTRUCT";
}

void CGameObjectConstruct::Update(const f32& elapsedTime)
{
}

CGameObjectConstruct::~CGameObjectConstruct()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectConstructFactory::CGameObjectConstructFactory()
{
	GameObjectType = "CONSTRUCT";
}

CGameObjectConstructFactory::~CGameObjectConstructFactory()
{
}

Core::CGameObject* CGameObjectConstructFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectConstruct(Name, Pos);
}
}
}
