#include "CGameObjectStone6.h"
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

CGameObjectStone6::CGameObjectStone6(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone6.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_stone6stones_df2");
MaterialManager::getSingleton().getByName("_stone6stones_df2")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE6";
}

void CGameObjectStone6::Update(const f32& elapsedTime)
{
}

CGameObjectStone6::~CGameObjectStone6()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone6Factory::CGameObjectStone6Factory()
{
	GameObjectType = "STONE6";
}

CGameObjectStone6Factory::~CGameObjectStone6Factory()
{
}

Core::CGameObject* CGameObjectStone6Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone6(Name, Pos);
}
}
}
