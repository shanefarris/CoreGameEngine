#include "CGameObjectRazor.h"
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

CGameObjectRazor::CGameObjectRazor(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "razor.mesh");
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

	GameObjectType = "RAZOR";
}

void CGameObjectRazor::Update(const f32& elapsedTime)
{
}

CGameObjectRazor::~CGameObjectRazor()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectRazorFactory::CGameObjectRazorFactory()
{
	GameObjectType = "RAZOR";
}

CGameObjectRazorFactory::~CGameObjectRazorFactory()
{
}

Core::CGameObject* CGameObjectRazorFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectRazor(Name, Pos);
}
}
}
