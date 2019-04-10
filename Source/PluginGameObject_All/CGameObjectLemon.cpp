#include "CGameObjectLemon.h"
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

CGameObjectLemon::CGameObjectLemon(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Lemon.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("lemonmat");
MaterialManager::getSingleton().getByName("lemonmat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "LEMON";
}

void CGameObjectLemon::Update(const f32& elapsedTime)
{
}

CGameObjectLemon::~CGameObjectLemon()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectLemonFactory::CGameObjectLemonFactory()
{
	GameObjectType = "LEMON";
}

CGameObjectLemonFactory::~CGameObjectLemonFactory()
{
}

Core::CGameObject* CGameObjectLemonFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectLemon(Name, Pos);
}
}
}
