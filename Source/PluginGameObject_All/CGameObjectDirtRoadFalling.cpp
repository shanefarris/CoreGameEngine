#include "CGameObjectDirtRoadFalling.h"
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

CGameObjectDirtRoadFalling::CGameObjectDirtRoadFalling(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "DirtRoadFalling.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("road_village");
MaterialManager::getSingleton().getByName("road_village")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "DIRTROADFALLING";
}

void CGameObjectDirtRoadFalling::Update(const f32& elapsedTime)
{
}

CGameObjectDirtRoadFalling::~CGameObjectDirtRoadFalling()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectDirtRoadFallingFactory::CGameObjectDirtRoadFallingFactory()
{
	GameObjectType = "DIRTROADFALLING";
}

CGameObjectDirtRoadFallingFactory::~CGameObjectDirtRoadFallingFactory()
{
}

Core::CGameObject* CGameObjectDirtRoadFallingFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectDirtRoadFalling(Name, Pos);
}
}
}
