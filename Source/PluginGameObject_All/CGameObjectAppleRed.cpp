#include "CGameObjectAppleRed.h"
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

CGameObjectAppleRed::CGameObjectAppleRed(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "AppleRed.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("appleredmat");
MaterialManager::getSingleton().getByName("appleredmat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "APPLERED";
}

void CGameObjectAppleRed::Update(const f32& elapsedTime)
{
}

CGameObjectAppleRed::~CGameObjectAppleRed()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAppleRedFactory::CGameObjectAppleRedFactory()
{
	GameObjectType = "APPLERED";
}

CGameObjectAppleRedFactory::~CGameObjectAppleRedFactory()
{
}

Core::CGameObject* CGameObjectAppleRedFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAppleRed(Name, Pos);
}
}
}
