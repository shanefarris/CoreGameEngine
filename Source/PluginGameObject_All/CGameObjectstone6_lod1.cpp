#include "CGameObjectStone6_lod1.h"
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

CGameObjectStone6_lod1::CGameObjectStone6_lod1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone6_lod1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_stone6_lod1stones_df2");
MaterialManager::getSingleton().getByName("_stone6_lod1stones_df2")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE6_LOD1";
}

void CGameObjectStone6_lod1::Update(const f32& elapsedTime)
{
}

CGameObjectStone6_lod1::~CGameObjectStone6_lod1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone6_lod1Factory::CGameObjectStone6_lod1Factory()
{
	GameObjectType = "STONE6_LOD1";
}

CGameObjectStone6_lod1Factory::~CGameObjectStone6_lod1Factory()
{
}

Core::CGameObject* CGameObjectStone6_lod1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone6_lod1(Name, Pos);
}
}
}
