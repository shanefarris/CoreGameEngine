#include "CGameObjectWalkwayCurve.h"
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

CGameObjectWalkwayCurve::CGameObjectWalkwayCurve(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "WalkwayCurve.mesh");
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

	GameObjectType = "WALKWAYCURVE";
}

void CGameObjectWalkwayCurve::Update(const f32& elapsedTime)
{
}

CGameObjectWalkwayCurve::~CGameObjectWalkwayCurve()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectWalkwayCurveFactory::CGameObjectWalkwayCurveFactory()
{
	GameObjectType = "WALKWAYCURVE";
}

CGameObjectWalkwayCurveFactory::~CGameObjectWalkwayCurveFactory()
{
}

Core::CGameObject* CGameObjectWalkwayCurveFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectWalkwayCurve(Name, Pos);
}
}
}
