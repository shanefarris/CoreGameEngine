#include "CGameObjectOldVillageWall.h"
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

CGameObjectOldVillageWall::CGameObjectOldVillageWall(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "OldVillageWall.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("h9");
MaterialManager::getSingleton().getByName("h9")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "OLDVILLAGEWALL";
}

void CGameObjectOldVillageWall::Update(const f32& elapsedTime)
{
}

CGameObjectOldVillageWall::~CGameObjectOldVillageWall()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectOldVillageWallFactory::CGameObjectOldVillageWallFactory()
{
	GameObjectType = "OLDVILLAGEWALL";
}

CGameObjectOldVillageWallFactory::~CGameObjectOldVillageWallFactory()
{
}

Core::CGameObject* CGameObjectOldVillageWallFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectOldVillageWall(Name, Pos);
}
}
}
