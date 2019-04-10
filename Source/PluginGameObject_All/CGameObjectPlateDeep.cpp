#include "CGameObjectPlateDeep.h"
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

CGameObjectPlateDeep::CGameObjectPlateDeep(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "PlateDeep.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("platemat");
MaterialManager::getSingleton().getByName("platemat")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "PLATEDEEP";
}

void CGameObjectPlateDeep::Update(const f32& elapsedTime)
{
}

CGameObjectPlateDeep::~CGameObjectPlateDeep()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectPlateDeepFactory::CGameObjectPlateDeepFactory()
{
	GameObjectType = "PLATEDEEP";
}

CGameObjectPlateDeepFactory::~CGameObjectPlateDeepFactory()
{
}

Core::CGameObject* CGameObjectPlateDeepFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectPlateDeep(Name, Pos);
}
}
}
