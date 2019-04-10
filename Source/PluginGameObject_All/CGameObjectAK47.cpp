#include "CGameObjectAK47.h"
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

CGameObjectAK47::CGameObjectAK47(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "AK47.mesh");
	Entity->setQueryFlags(0);
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

	GameObjectType = "AK47";
}

void CGameObjectAK47::Update(const f32& elapsedTime)
{
}

CGameObjectAK47::~CGameObjectAK47()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAK47Factory::CGameObjectAK47Factory()
{
	GameObjectType = "AK47";
}

CGameObjectAK47Factory::~CGameObjectAK47Factory()
{
}

Core::CGameObject* CGameObjectAK47Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAK47(Name, Pos);
}
}
}
