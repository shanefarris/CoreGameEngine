#include "CGameObjectAmmobox1.h"
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

CGameObjectAmmobox1::CGameObjectAmmobox1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "ammobox1.mesh");
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

	GameObjectType = "AMMOBOX1";
}

void CGameObjectAmmobox1::Update(const f32& elapsedTime)
{
}

CGameObjectAmmobox1::~CGameObjectAmmobox1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAmmobox1Factory::CGameObjectAmmobox1Factory()
{
	GameObjectType = "AMMOBOX1";
}

CGameObjectAmmobox1Factory::~CGameObjectAmmobox1Factory()
{
}

Core::CGameObject* CGameObjectAmmobox1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAmmobox1(Name, Pos);
}
}
}
