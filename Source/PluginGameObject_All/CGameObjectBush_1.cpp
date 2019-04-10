#include "CGameObjectBush_1.h"
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

CGameObjectBush_1::CGameObjectBush_1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Bush_1.mesh");
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

	GameObjectType = "BUSH_1";
}

void CGameObjectBush_1::Update(const f32& elapsedTime)
{
}

CGameObjectBush_1::~CGameObjectBush_1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectBush_1Factory::CGameObjectBush_1Factory()
{
	GameObjectType = "BUSH_1";
}

CGameObjectBush_1Factory::~CGameObjectBush_1Factory()
{
}

Core::CGameObject* CGameObjectBush_1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectBush_1(Name, Pos);
}
}
}
