#include "CGameObjectElectricPole_lod2.h"
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

CGameObjectElectricPole_lod2::CGameObjectElectricPole_lod2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "ElectricPole_lod2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("metal01_d");
MaterialManager::getSingleton().getByName("metal01_d")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "ELECTRICPOLE_LOD2";
}

void CGameObjectElectricPole_lod2::Update(const f32& elapsedTime)
{
}

CGameObjectElectricPole_lod2::~CGameObjectElectricPole_lod2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectElectricPole_lod2Factory::CGameObjectElectricPole_lod2Factory()
{
	GameObjectType = "ELECTRICPOLE_LOD2";
}

CGameObjectElectricPole_lod2Factory::~CGameObjectElectricPole_lod2Factory()
{
}

Core::CGameObject* CGameObjectElectricPole_lod2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectElectricPole_lod2(Name, Pos);
}
}
}
