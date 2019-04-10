#include "CGameObjectSphere.h"
#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CGameObject.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"

using namespace Core;

namespace Core
{
namespace Plugin
{

CGameObjectSphere::CGameObjectSphere(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	CGameManager* gm = CGameManager::Instance();
	SceneManager* sm = gm->GetSceneManager();
	Node = sm->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Node->setScale(0.02f, 0.02f, 0.02f);
	Entity = sm->createEntity(Name + String("_entity"), "sphere.mesh");
	Node->attachObject(Entity);

	GameObjectType = "SPHERE_1";
}

CGameObjectSphere::~CGameObjectSphere()
{
}

CGameObjectSphereFactory::CGameObjectSphereFactory()
{
	GameObjectType = "SPHERE_1";
}

CGameObjectSphereFactory::~CGameObjectSphereFactory()
{
}

Core::CGameObject* CGameObjectSphereFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectSphere(Name, Pos);
}



CGameObjectSpawnPoint::CGameObjectSpawnPoint(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	CGameManager* gm = CGameManager::Instance();
	SceneManager* sm = gm->GetSceneManager();
	Node = sm->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Node->setScale(0.02f, 0.02f, 0.02f);
	Entity = sm->createEntity(Name + String("_entity"), "spawn_point.mesh");
	Node->attachObject(Entity);

	GameObjectType = "SPAWN_POINT";
}

CGameObjectSpawnPoint::~CGameObjectSpawnPoint()
{
}

CGameObjectSpawnPointFactory::CGameObjectSpawnPointFactory()
{
	GameObjectType = "SPAWN_POINT";
}

CGameObjectSpawnPointFactory::~CGameObjectSpawnPointFactory()
{
}

Core::CGameObject* CGameObjectSpawnPointFactory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectSpawnPoint(Name, Pos);
}


}
}