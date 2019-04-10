#include "CGameObjectStone3_lod2.h"
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

CGameObjectStone3_lod2::CGameObjectStone3_lod2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "stone3_lod2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_stone3_lod2stones_df");
MaterialManager::getSingleton().getByName("_stone3_lod2stones_df")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONE3_LOD2";
}

void CGameObjectStone3_lod2::Update(const f32& elapsedTime)
{
}

CGameObjectStone3_lod2::~CGameObjectStone3_lod2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStone3_lod2Factory::CGameObjectStone3_lod2Factory()
{
	GameObjectType = "STONE3_LOD2";
}

CGameObjectStone3_lod2Factory::~CGameObjectStone3_lod2Factory()
{
}

Core::CGameObject* CGameObjectStone3_lod2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStone3_lod2(Name, Pos);
}
}
}
