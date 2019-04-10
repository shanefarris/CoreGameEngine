// DECLDIR will perform an export for us
#define DLL_EXPORT

#include "CGameObjectFAB1.h"
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

CGameObjectFAB1::CGameObjectFAB1(const char* Name, Vector3& Pos) : CGameObject(Name)
{
	CGameManager* gm = CGameManager::Instance();
	SceneManager* sm = gm->GetSceneManager();
	Node = sm->getRootSceneNode()->createChildSceneNode(Name + String("_node"), Pos);
	Node->setScale(1, 1, 1);
	Entity = sm->createEntity(Name + String("_entity"), "Firstaid1.mesh");
	Node->attachObject(Entity);

	GameObjectType = "FAB_1";
}

CGameObjectFAB1::~CGameObjectFAB1()
{
}

CGameObjectFAB1Factory::CGameObjectFAB1Factory()
{
	GameObjectType = "FAB_1";
}

CGameObjectFAB1Factory::~CGameObjectFAB1Factory()
{
}

Core::CGameObject* CGameObjectFAB1Factory::CreateObject(const char* Name, Vector3& Pos)
{
	return new Plugin::CGameObjectFAB1(Name, Pos);
}


}
}