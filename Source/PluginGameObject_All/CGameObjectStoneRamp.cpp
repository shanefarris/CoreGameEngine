#include "CGameObjectStoneRamp.h"
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

CGameObjectStoneRamp::CGameObjectStoneRamp(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "StoneRamp.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("h4");
MaterialManager::getSingleton().getByName("h4")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "STONERAMP";
}

void CGameObjectStoneRamp::Update(const f32& elapsedTime)
{
}

CGameObjectStoneRamp::~CGameObjectStoneRamp()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectStoneRampFactory::CGameObjectStoneRampFactory()
{
	GameObjectType = "STONERAMP";
}

CGameObjectStoneRampFactory::~CGameObjectStoneRampFactory()
{
}

Core::CGameObject* CGameObjectStoneRampFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectStoneRamp(Name, Pos);
}
}
}
