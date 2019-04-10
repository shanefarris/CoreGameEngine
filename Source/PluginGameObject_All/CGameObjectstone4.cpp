#include "CGameObjectStone4.h"
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

CGameObjectStone4::CGameObjectStone4(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone4.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_stone4stones_df2");
MaterialManager::getSingleton().getByName("_stone4stones_df2")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE4";
}

void CGameObjectStone4::Update(const f32& elapsedTime)
{
}

CGameObjectStone4::~CGameObjectStone4()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone4Factory::CGameObjectStone4Factory()
{
	GameObjectType = "STONE4";
}

CGameObjectStone4Factory::~CGameObjectStone4Factory()
{
}

Core::CGameObject* CGameObjectStone4Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone4(Name, Pos);
}
}
}
