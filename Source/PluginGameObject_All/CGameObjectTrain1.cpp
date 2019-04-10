#include "CGameObjectTrain1.h"
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

CGameObjectTrain1::CGameObjectTrain1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Train1.mesh");
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

	GameObjectType = "TRAIN1";
}

void CGameObjectTrain1::Update(const f32& elapsedTime)
{
}

CGameObjectTrain1::~CGameObjectTrain1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectTrain1Factory::CGameObjectTrain1Factory()
{
	GameObjectType = "TRAIN1";
}

CGameObjectTrain1Factory::~CGameObjectTrain1Factory()
{
}

Core::CGameObject* CGameObjectTrain1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectTrain1(Name, Pos);
}
}
}
