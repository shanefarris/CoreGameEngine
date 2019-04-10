#include "CGameObjectBarrel2.h"
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

CGameObjectBarrel2::CGameObjectBarrel2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "barrel2.mesh");
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

	GameObjectType = "BARREL2";
}

void CGameObjectBarrel2::Update(const f32& elapsedTime)
{
}

CGameObjectBarrel2::~CGameObjectBarrel2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectBarrel2Factory::CGameObjectBarrel2Factory()
{
	GameObjectType = "BARREL2";
}

CGameObjectBarrel2Factory::~CGameObjectBarrel2Factory()
{
}

Core::CGameObject* CGameObjectBarrel2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectBarrel2(Name, Pos);
}
}
}
