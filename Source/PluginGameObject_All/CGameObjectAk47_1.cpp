#include "CGameObjectAk47_1.h"
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

CGameObjectAk47_1::CGameObjectAk47_1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "ak47_1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("ak47_1");
MaterialManager::getSingleton().getByName("ak47_1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "AK47_1";
}

void CGameObjectAk47_1::Update(const f32& elapsedTime)
{
}

CGameObjectAk47_1::~CGameObjectAk47_1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAk47_1Factory::CGameObjectAk47_1Factory()
{
	GameObjectType = "AK47_1";
}

CGameObjectAk47_1Factory::~CGameObjectAk47_1Factory()
{
}

Core::CGameObject* CGameObjectAk47_1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAk47_1(Name, Pos);
}
}
}
