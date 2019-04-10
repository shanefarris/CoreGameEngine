#include "CGameObjectGasPipeCurve.h"
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

CGameObjectGasPipeCurve::CGameObjectGasPipeCurve(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "GasPipeCurve.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("con1");
MaterialManager::getSingleton().getByName("con1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "GASPIPECURVE";
}

void CGameObjectGasPipeCurve::Update(const f32& elapsedTime)
{
}

CGameObjectGasPipeCurve::~CGameObjectGasPipeCurve()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectGasPipeCurveFactory::CGameObjectGasPipeCurveFactory()
{
	GameObjectType = "GASPIPECURVE";
}

CGameObjectGasPipeCurveFactory::~CGameObjectGasPipeCurveFactory()
{
}

Core::CGameObject* CGameObjectGasPipeCurveFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectGasPipeCurve(Name, Pos);
}
}
}
