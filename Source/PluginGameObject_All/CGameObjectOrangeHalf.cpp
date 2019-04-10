#include "CGameObjectOrangeHalf.h"
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

CGameObjectOrangeHalf::CGameObjectOrangeHalf(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "OrangeHalf.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("orangemat");
MaterialManager::getSingleton().getByName("orangemat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "ORANGEHALF";
}

void CGameObjectOrangeHalf::Update(const f32& elapsedTime)
{
}

CGameObjectOrangeHalf::~CGameObjectOrangeHalf()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectOrangeHalfFactory::CGameObjectOrangeHalfFactory()
{
	GameObjectType = "ORANGEHALF";
}

CGameObjectOrangeHalfFactory::~CGameObjectOrangeHalfFactory()
{
}

Core::CGameObject* CGameObjectOrangeHalfFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectOrangeHalf(Name, Pos);
}
}
}
