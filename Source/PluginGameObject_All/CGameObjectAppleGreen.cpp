#include "CGameObjectAppleGreen.h"
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

CGameObjectAppleGreen::CGameObjectAppleGreen(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "AppleGreen.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("applegreenmat");
MaterialManager::getSingleton().getByName("applegreenmat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "APPLEGREEN";
}

void CGameObjectAppleGreen::Update(const f32& elapsedTime)
{
}

CGameObjectAppleGreen::~CGameObjectAppleGreen()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAppleGreenFactory::CGameObjectAppleGreenFactory()
{
	GameObjectType = "APPLEGREEN";
}

CGameObjectAppleGreenFactory::~CGameObjectAppleGreenFactory()
{
}

Core::CGameObject* CGameObjectAppleGreenFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAppleGreen(Name, Pos);
}
}
}
