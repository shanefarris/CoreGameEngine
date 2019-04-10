#include "CGameObjectShootingPlace.h"
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

CGameObjectShootingPlace::CGameObjectShootingPlace(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "ShootingPlace.mesh");
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

	GameObjectType = "SHOOTINGPLACE";
}

void CGameObjectShootingPlace::Update(const f32& elapsedTime)
{
}

CGameObjectShootingPlace::~CGameObjectShootingPlace()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectShootingPlaceFactory::CGameObjectShootingPlaceFactory()
{
	GameObjectType = "SHOOTINGPLACE";
}

CGameObjectShootingPlaceFactory::~CGameObjectShootingPlaceFactory()
{
}

Core::CGameObject* CGameObjectShootingPlaceFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectShootingPlace(Name, Pos);
}
}
}
