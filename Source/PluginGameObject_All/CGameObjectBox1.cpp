#include "CGameObjectBox1.h"
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

CGameObjectBox1::CGameObjectBox1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Box1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("mat_gratebox5_1");
MaterialManager::getSingleton().getByName("mat_gratebox5_1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "BOX1";
}

void CGameObjectBox1::Update(const f32& elapsedTime)
{
}

CGameObjectBox1::~CGameObjectBox1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectBox1Factory::CGameObjectBox1Factory()
{
	GameObjectType = "BOX1";
}

CGameObjectBox1Factory::~CGameObjectBox1Factory()
{
}

Core::CGameObject* CGameObjectBox1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectBox1(Name, Pos);
}
}
}
