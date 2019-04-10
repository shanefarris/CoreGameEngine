#include "CGameObjectHumvee_1.h"
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "IPhysicsStrategy.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreMaterialManager.h"


using namespace Core;

namespace Core
{
namespace Plugin
{

CGameObjectHumvee_1::CGameObjectHumvee_1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "humvee_1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("humvee_1");
MaterialManager::getSingleton().getByName("humvee_1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "HUMVEE_1";
}

void CGameObjectHumvee_1::Update(const f32& elapsedTime)
{
}

CGameObjectHumvee_1::~CGameObjectHumvee_1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectHumvee_1Factory::CGameObjectHumvee_1Factory()
{
	GameObjectType = "HUMVEE_1";
}

CGameObjectHumvee_1Factory::~CGameObjectHumvee_1Factory()
{
}

Core::CGameObject* CGameObjectHumvee_1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectHumvee_1(Name, Pos);
}
}
}
