#include "CGameObjectShootingRangeWall1.h"
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

CGameObjectShootingRangeWall1::CGameObjectShootingRangeWall1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "ShootingRangeWall1.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("shootingrangewall1");
MaterialManager::getSingleton().getByName("shootingrangewall1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "SHOOTINGRANGEWALL1";
}

void CGameObjectShootingRangeWall1::Update(const f32& elapsedTime)
{
}

CGameObjectShootingRangeWall1::~CGameObjectShootingRangeWall1()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectShootingRangeWall1Factory::CGameObjectShootingRangeWall1Factory()
{
	GameObjectType = "SHOOTINGRANGEWALL1";
}

CGameObjectShootingRangeWall1Factory::~CGameObjectShootingRangeWall1Factory()
{
}

Core::CGameObject* CGameObjectShootingRangeWall1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectShootingRangeWall1(Name, Pos);
}
}
}
