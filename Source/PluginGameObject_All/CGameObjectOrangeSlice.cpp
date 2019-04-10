#include "CGameObjectOrangeSlice.h"
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

CGameObjectOrangeSlice::CGameObjectOrangeSlice(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "OrangeSlice.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("orangemat");
MaterialManager::getSingleton().getByName("orangemat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "ORANGESLICE";
}

void CGameObjectOrangeSlice::Update(const f32& elapsedTime)
{
}

CGameObjectOrangeSlice::~CGameObjectOrangeSlice()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectOrangeSliceFactory::CGameObjectOrangeSliceFactory()
{
	GameObjectType = "ORANGESLICE";
}

CGameObjectOrangeSliceFactory::~CGameObjectOrangeSliceFactory()
{
}

Core::CGameObject* CGameObjectOrangeSliceFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectOrangeSlice(Name, Pos);
}
}
}
