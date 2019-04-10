#include "CGameObjectTarget2.h"
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

CGameObjectTarget2::CGameObjectTarget2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Target2.mesh");
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

	GameObjectType = "TARGET2";
}

void CGameObjectTarget2::Update(const f32& elapsedTime)
{
}

CGameObjectTarget2::~CGameObjectTarget2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectTarget2Factory::CGameObjectTarget2Factory()
{
	GameObjectType = "TARGET2";
}

CGameObjectTarget2Factory::~CGameObjectTarget2Factory()
{
}

Core::CGameObject* CGameObjectTarget2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectTarget2(Name, Pos);
}
}
}
