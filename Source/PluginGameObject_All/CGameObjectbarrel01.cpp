#include "CGameObjectBarrel01.h"
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

CGameObjectBarrel01::CGameObjectBarrel01(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "barrel01.mesh");
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

	GameObjectType = "BARREL01";
}

void CGameObjectBarrel01::Update(const f32& elapsedTime)
{
}

CGameObjectBarrel01::~CGameObjectBarrel01()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectBarrel01Factory::CGameObjectBarrel01Factory()
{
	GameObjectType = "BARREL01";
}

CGameObjectBarrel01Factory::~CGameObjectBarrel01Factory()
{
}

Core::CGameObject* CGameObjectBarrel01Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectBarrel01(Name, Pos);
}
}
}
