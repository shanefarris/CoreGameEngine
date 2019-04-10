#include "CGameObjectFence1Curve.h"
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

CGameObjectFence1Curve::CGameObjectFence1Curve(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Fence1Curve.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("con01_d");
MaterialManager::getSingleton().getByName("con01_d")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "FENCE1CURVE";
}

void CGameObjectFence1Curve::Update(const f32& elapsedTime)
{
}

CGameObjectFence1Curve::~CGameObjectFence1Curve()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectFence1CurveFactory::CGameObjectFence1CurveFactory()
{
	GameObjectType = "FENCE1CURVE";
}

CGameObjectFence1CurveFactory::~CGameObjectFence1CurveFactory()
{
}

Core::CGameObject* CGameObjectFence1CurveFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectFence1Curve(Name, Pos);
}
}
}
