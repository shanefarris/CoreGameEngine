#include "CGameObjectConcrete.h"
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "IPhysicsStrategy.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"


using namespace Core;

namespace Core
{
namespace Plugin
{

CGameObjectConcrete::CGameObjectConcrete(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Concrete.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "CONCRETE";
}

void CGameObjectConcrete::Update(const f32& elapsedTime)
{
}

CGameObjectConcrete::~CGameObjectConcrete()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectConcreteFactory::CGameObjectConcreteFactory()
{
	GameObjectType = "CONCRETE";
}

CGameObjectConcreteFactory::~CGameObjectConcreteFactory()
{
}

Core::CGameObject* CGameObjectConcreteFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectConcrete(Name, Pos);
}
}
}
