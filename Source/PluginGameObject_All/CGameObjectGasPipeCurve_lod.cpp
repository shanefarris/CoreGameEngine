#include "CGameObjectGasPipeCurve_lod.h"
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

CGameObjectGasPipeCurve_lod::CGameObjectGasPipeCurve_lod(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "GasPipeCurve_lod.mesh");
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

	GameObjectType = "GASPIPECURVE_LOD";
}

void CGameObjectGasPipeCurve_lod::Update(const f32& elapsedTime)
{
}

CGameObjectGasPipeCurve_lod::~CGameObjectGasPipeCurve_lod()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectGasPipeCurve_lodFactory::CGameObjectGasPipeCurve_lodFactory()
{
	GameObjectType = "GASPIPECURVE_LOD";
}

CGameObjectGasPipeCurve_lodFactory::~CGameObjectGasPipeCurve_lodFactory()
{
}

Core::CGameObject* CGameObjectGasPipeCurve_lodFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectGasPipeCurve_lod(Name, Pos);
}
}
}
