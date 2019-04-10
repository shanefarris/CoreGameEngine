#include "CGameObjectAK47_clip.h"
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "IPhysicsStrategy.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"


using namespace Core;

namespace Core
{
namespace Plugin
{

CGameObjectAK47_clip::CGameObjectAK47_clip(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "AK47_clip.mesh");
	Entity->setQueryFlags(0);
	Node->attachObject(Entity);
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "AK47_CLIP";
}

void CGameObjectAK47_clip::Update(const f32& elapsedTime)
{
}

CGameObjectAK47_clip::~CGameObjectAK47_clip()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectAK47_clipFactory::CGameObjectAK47_clipFactory()
{
	GameObjectType = "AK47_CLIP";
}

CGameObjectAK47_clipFactory::~CGameObjectAK47_clipFactory()
{
}

Core::CGameObject* CGameObjectAK47_clipFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectAK47_clip(Name, Pos);
}
}
}
