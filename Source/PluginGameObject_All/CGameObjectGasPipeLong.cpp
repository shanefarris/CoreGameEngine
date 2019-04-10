#include "CGameObjectGasPipeLong.h"
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

CGameObjectGasPipeLong::CGameObjectGasPipeLong(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "GasPipeLong.mesh");
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

	GameObjectType = "GASPIPELONG";
}

void CGameObjectGasPipeLong::Update(const f32& elapsedTime)
{
}

CGameObjectGasPipeLong::~CGameObjectGasPipeLong()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectGasPipeLongFactory::CGameObjectGasPipeLongFactory()
{
	GameObjectType = "GASPIPELONG";
}

CGameObjectGasPipeLongFactory::~CGameObjectGasPipeLongFactory()
{
}

Core::CGameObject* CGameObjectGasPipeLongFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectGasPipeLong(Name, Pos);
}
}
}
