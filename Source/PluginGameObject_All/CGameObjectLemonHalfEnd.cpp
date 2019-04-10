#include "CGameObjectLemonHalfEnd.h"
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

CGameObjectLemonHalfEnd::CGameObjectLemonHalfEnd(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "LemonHalfEnd.mesh");
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

	GameObjectType = "LEMONHALFEND";
}

void CGameObjectLemonHalfEnd::Update(const f32& elapsedTime)
{
}

CGameObjectLemonHalfEnd::~CGameObjectLemonHalfEnd()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectLemonHalfEndFactory::CGameObjectLemonHalfEndFactory()
{
	GameObjectType = "LEMONHALFEND";
}

CGameObjectLemonHalfEndFactory::~CGameObjectLemonHalfEndFactory()
{
}

Core::CGameObject* CGameObjectLemonHalfEndFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectLemonHalfEnd(Name, Pos);
}
}
}
