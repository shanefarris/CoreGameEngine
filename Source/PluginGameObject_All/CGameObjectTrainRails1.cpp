#include "CGameObjectTrainRails1.h"
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

CGameObjectTrainRails1::CGameObjectTrainRails1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "TrainRails1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("rails_d");
MaterialManager::getSingleton().getByName("rails_d")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "TRAINRAILS1";
}

void CGameObjectTrainRails1::Update(const f32& elapsedTime)
{
}

CGameObjectTrainRails1::~CGameObjectTrainRails1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectTrainRails1Factory::CGameObjectTrainRails1Factory()
{
	GameObjectType = "TRAINRAILS1";
}

CGameObjectTrainRails1Factory::~CGameObjectTrainRails1Factory()
{
}

Core::CGameObject* CGameObjectTrainRails1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectTrainRails1(Name, Pos);
}
}
}
