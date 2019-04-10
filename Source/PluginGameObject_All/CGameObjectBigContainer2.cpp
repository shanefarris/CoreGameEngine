#include "CGameObjectBigContainer2.h"
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

CGameObjectBigContainer2::CGameObjectBigContainer2(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "BigContainer2.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("mat_containter_l");
MaterialManager::getSingleton().getByName("mat_containter_l")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "BIGCONTAINER2";
}

void CGameObjectBigContainer2::Update(const f32& elapsedTime)
{
}

CGameObjectBigContainer2::~CGameObjectBigContainer2()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectBigContainer2Factory::CGameObjectBigContainer2Factory()
{
	GameObjectType = "BIGCONTAINER2";
}

CGameObjectBigContainer2Factory::~CGameObjectBigContainer2Factory()
{
}

Core::CGameObject* CGameObjectBigContainer2Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectBigContainer2(Name, Pos);
}
}
}
