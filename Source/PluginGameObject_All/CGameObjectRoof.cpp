#include "CGameObjectRoof.h"
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

CGameObjectRoof::CGameObjectRoof(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "roof.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("h9");
MaterialManager::getSingleton().getByName("h9")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "ROOF";
}

void CGameObjectRoof::Update(const f32& elapsedTime)
{
}

CGameObjectRoof::~CGameObjectRoof()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectRoofFactory::CGameObjectRoofFactory()
{
	GameObjectType = "ROOF";
}

CGameObjectRoofFactory::~CGameObjectRoofFactory()
{
}

Core::CGameObject* CGameObjectRoofFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectRoof(Name, Pos);
}
}
}
