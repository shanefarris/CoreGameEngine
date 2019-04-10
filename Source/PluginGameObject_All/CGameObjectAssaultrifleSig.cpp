#include "CGameObjectAssaultrifleSig.h"
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

CGameObjectAssaultrifleSig::CGameObjectAssaultrifleSig(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "AssaultrifleSig.mesh");
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

	GameObjectType = "ASSAULTRIFLESIG";
}

void CGameObjectAssaultrifleSig::Update(const f32& elapsedTime)
{
}

CGameObjectAssaultrifleSig::~CGameObjectAssaultrifleSig()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAssaultrifleSigFactory::CGameObjectAssaultrifleSigFactory()
{
	GameObjectType = "ASSAULTRIFLESIG";
}

CGameObjectAssaultrifleSigFactory::~CGameObjectAssaultrifleSigFactory()
{
}

Core::CGameObject* CGameObjectAssaultrifleSigFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAssaultrifleSig(Name, Pos);
}
}
}
