#include "CGameObjectOrange.h"
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

CGameObjectOrange::CGameObjectOrange(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Orange.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("orangemat");
MaterialManager::getSingleton().getByName("orangemat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "ORANGE";
}

void CGameObjectOrange::Update(const f32& elapsedTime)
{
}

CGameObjectOrange::~CGameObjectOrange()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectOrangeFactory::CGameObjectOrangeFactory()
{
	GameObjectType = "ORANGE";
}

CGameObjectOrangeFactory::~CGameObjectOrangeFactory()
{
}

Core::CGameObject* CGameObjectOrangeFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectOrange(Name, Pos);
}
}
}
