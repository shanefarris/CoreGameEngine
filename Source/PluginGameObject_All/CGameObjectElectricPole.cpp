#include "CGameObjectElectricPole.h"
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

CGameObjectElectricPole::CGameObjectElectricPole(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "ElectricPole.mesh");
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

	GameObjectType = "ELECTRICPOLE";
}

void CGameObjectElectricPole::Update(const f32& elapsedTime)
{
}

CGameObjectElectricPole::~CGameObjectElectricPole()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectElectricPoleFactory::CGameObjectElectricPoleFactory()
{
	GameObjectType = "ELECTRICPOLE";
}

CGameObjectElectricPoleFactory::~CGameObjectElectricPoleFactory()
{
}

Core::CGameObject* CGameObjectElectricPoleFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectElectricPole(Name, Pos);
}
}
}
