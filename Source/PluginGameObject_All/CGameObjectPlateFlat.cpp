#include "CGameObjectPlateFlat.h"
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

CGameObjectPlateFlat::CGameObjectPlateFlat(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "PlateFlat.mesh");
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

	GameObjectType = "PLATEFLAT";
}

void CGameObjectPlateFlat::Update(const f32& elapsedTime)
{
}

CGameObjectPlateFlat::~CGameObjectPlateFlat()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectPlateFlatFactory::CGameObjectPlateFlatFactory()
{
	GameObjectType = "PLATEFLAT";
}

CGameObjectPlateFlatFactory::~CGameObjectPlateFlatFactory()
{
}

Core::CGameObject* CGameObjectPlateFlatFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectPlateFlat(Name, Pos);
}
}
}
