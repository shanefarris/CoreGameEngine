#include "CGameObjectVeg9.h"
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

CGameObjectVeg9::CGameObjectVeg9(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "veg9.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("_veg9palm1_trunk_df");
MaterialManager::getSingleton().getByName("_veg9palm1_trunk_df")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "VEG9";
}

void CGameObjectVeg9::Update(const f32& elapsedTime)
{
}

CGameObjectVeg9::~CGameObjectVeg9()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectVeg9Factory::CGameObjectVeg9Factory()
{
	GameObjectType = "VEG9";
}

CGameObjectVeg9Factory::~CGameObjectVeg9Factory()
{
}

Core::CGameObject* CGameObjectVeg9Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectVeg9(Name, Pos);
}
}
}
