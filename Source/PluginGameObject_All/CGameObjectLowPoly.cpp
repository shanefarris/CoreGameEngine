#include "CGameObjectLowPoly.h"
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

CGameObjectLowPoly::CGameObjectLowPoly(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Low Poly.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("standard_1");
MaterialManager::getSingleton().getByName("standard_1")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "LOWPOLY";
}

void CGameObjectLowPoly::Update(const f32& elapsedTime)
{
}

CGameObjectLowPoly::~CGameObjectLowPoly()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectLowPolyFactory::CGameObjectLowPolyFactory()
{
	GameObjectType = "LOWPOLY";
}

CGameObjectLowPolyFactory::~CGameObjectLowPolyFactory()
{
}

Core::CGameObject* CGameObjectLowPolyFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectLowPoly(Name, Pos);
}
}
}
