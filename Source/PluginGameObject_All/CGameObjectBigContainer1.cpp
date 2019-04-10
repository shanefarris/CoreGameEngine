#include "CGameObjectBigContainer1.h"
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

CGameObjectBigContainer1::CGameObjectBigContainer1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "BigContainer1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("mat_container_b5");
MaterialManager::getSingleton().getByName("mat_container_b5")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "BIGCONTAINER1";
}

void CGameObjectBigContainer1::Update(const f32& elapsedTime)
{
}

CGameObjectBigContainer1::~CGameObjectBigContainer1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectBigContainer1Factory::CGameObjectBigContainer1Factory()
{
	GameObjectType = "BIGCONTAINER1";
}

CGameObjectBigContainer1Factory::~CGameObjectBigContainer1Factory()
{
}

Core::CGameObject* CGameObjectBigContainer1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectBigContainer1(Name, Pos);
}
}
}
