#include "CGameObjectM4a1_1.h"
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

CGameObjectM4a1_1::CGameObjectM4a1_1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "m4a1_1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("03-default");
MaterialManager::getSingleton().getByName("03-default")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "M4A1_1";
}

void CGameObjectM4a1_1::Update(const f32& elapsedTime)
{
}

CGameObjectM4a1_1::~CGameObjectM4a1_1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectM4a1_1Factory::CGameObjectM4a1_1Factory()
{
	GameObjectType = "M4A1_1";
}

CGameObjectM4a1_1Factory::~CGameObjectM4a1_1Factory()
{
}

Core::CGameObject* CGameObjectM4a1_1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectM4a1_1(Name, Pos);
}
}
}
