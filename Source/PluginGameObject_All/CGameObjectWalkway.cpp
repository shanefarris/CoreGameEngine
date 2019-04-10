#include "CGameObjectWalkway.h"
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

CGameObjectWalkway::CGameObjectWalkway(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Walkway.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("floor01_d");
MaterialManager::getSingleton().getByName("floor01_d")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "WALKWAY";
}

void CGameObjectWalkway::Update(const f32& elapsedTime)
{
}

CGameObjectWalkway::~CGameObjectWalkway()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectWalkwayFactory::CGameObjectWalkwayFactory()
{
	GameObjectType = "WALKWAY";
}

CGameObjectWalkwayFactory::~CGameObjectWalkwayFactory()
{
}

Core::CGameObject* CGameObjectWalkwayFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectWalkway(Name, Pos);
}
}
}
