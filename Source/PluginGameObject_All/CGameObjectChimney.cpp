#include "CGameObjectChimney.h"
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

CGameObjectChimney::CGameObjectChimney(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	Node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Entity = CGameManager::Instance()->GetSceneManager()->createEntity(Name + String("_entity"), "Chimney.mesh");
	Entity->setQueryFlags(SQF_GAMEOBJECT);
	Node->attachObject(Entity);
	Entity->setMaterialName("rust01_d");
MaterialManager::getSingleton().getByName("rust01_d")->load();
	//Node->setScale(1.0f, 1.0f, 1.0f);

	// TODO: Customize physics profile here
	// ===================================
	PhysicsProfile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
	if(PhysicsProfile)
	{
		Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(this);
	}
	// ===================================

	GameObjectType = "CHIMNEY";
}

void CGameObjectChimney::Update(const f32& elapsedTime)
{
}

CGameObjectChimney::~CGameObjectChimney()
{
	Physics::CPhysicsManager::Instance()->GetStrategy()->DestroyPhysicsBody(this);
}

CGameObjectChimneyFactory::CGameObjectChimneyFactory()
{
	GameObjectType = "CHIMNEY";
}

CGameObjectChimneyFactory::~CGameObjectChimneyFactory()
{
}

Core::CGameObject* CGameObjectChimneyFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectChimney(Name, Pos);
}
}
}
