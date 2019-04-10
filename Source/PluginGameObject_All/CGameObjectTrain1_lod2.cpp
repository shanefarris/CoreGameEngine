#include "CGameObjectTrain1_lod2.h"
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

CGameObjectTrain1_lod2::CGameObjectTrain1_lod2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Train1_lod2.mesh");
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

	GameObjectType = "TRAIN1_LOD2";
}

void CGameObjectTrain1_lod2::Update(const f32& elapsedTime)
{
}

CGameObjectTrain1_lod2::~CGameObjectTrain1_lod2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectTrain1_lod2Factory::CGameObjectTrain1_lod2Factory()
{
	GameObjectType = "TRAIN1_LOD2";
}

CGameObjectTrain1_lod2Factory::~CGameObjectTrain1_lod2Factory()
{
}

Core::CGameObject* CGameObjectTrain1_lod2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectTrain1_lod2(Name, Pos);
}
}
}
