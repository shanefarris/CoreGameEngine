#include "CGameObjectLemonSlice.h"
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

CGameObjectLemonSlice::CGameObjectLemonSlice(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "LemonSlice.mesh");
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

	GameObjectType = "LEMONSLICE";
}

void CGameObjectLemonSlice::Update(const f32& elapsedTime)
{
}

CGameObjectLemonSlice::~CGameObjectLemonSlice()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectLemonSliceFactory::CGameObjectLemonSliceFactory()
{
	GameObjectType = "LEMONSLICE";
}

CGameObjectLemonSliceFactory::~CGameObjectLemonSliceFactory()
{
}

Core::CGameObject* CGameObjectLemonSliceFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectLemonSlice(Name, Pos);
}
}
}
