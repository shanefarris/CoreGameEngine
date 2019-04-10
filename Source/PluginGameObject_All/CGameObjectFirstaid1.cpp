#include "CGameObjectFirstaid1.h"
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

CGameObjectFirstaid1::CGameObjectFirstaid1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Firstaid1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("firstaid1");
MaterialManager::getSingleton().getByName("firstaid1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "FIRSTAID1";
}

void CGameObjectFirstaid1::Update(const f32& elapsedTime)
{
}

CGameObjectFirstaid1::~CGameObjectFirstaid1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectFirstaid1Factory::CGameObjectFirstaid1Factory()
{
	GameObjectType = "FIRSTAID1";
}

CGameObjectFirstaid1Factory::~CGameObjectFirstaid1Factory()
{
}

Core::CGameObject* CGameObjectFirstaid1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectFirstaid1(Name, Pos);
}
}
}
