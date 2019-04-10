#include "CPlayerZombie_small.h"
#include "CPlayerPimpl.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "CItemsManager.h"
#include "IPhysicsStrategy.h"
#include "CPlayerSoundComponent.h"
#include "AnimationMapping.h"
#include "Ai/CFpsVehicle.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreAnimationState.h"

using namespace Core::Physics;
using namespace Core::Plugin;

namespace Core
{
namespace Plugin
{

CPlayerZombie_small::CPlayerZombie_small(const char* Name, IPhysicsStrategy* PhysicsStrategy) : CPlayer(Name, PhysicsStrategy)
{
	m_PlayerPimpl->m_MeshName = "zombie_small.mesh";
	auto sceneManager = m_PlayerPimpl->m_GameManager->GetSceneManager();

	// Setup basic node structure to handle 3rd person cameras
	m_PlayerPimpl->m_PlayerNode = sceneManager->getRootSceneNode()->createChildSceneNode(Name);

	m_PlayerPimpl->m_PlayerEntity = sceneManager->createEntity(Name, m_PlayerPimpl->m_MeshName);
	m_PlayerPimpl->m_PlayerNode->attachObject(m_PlayerPimpl->m_PlayerEntity);

	m_PlayerPimpl->m_PlayerNode->setPosition(0, 0, 0);

	// ====== Set the player type ========
	m_PlayerPimpl->m_PlayerType = "ZOMBIE_SMALL";
	// ===================================

	// === Set the player bone names =====
	m_PlayerPimpl->m_RootBoneName = "";
	m_PlayerPimpl->m_HeadBoneName = "";
	// ===================================

	// Does the characater have a controller
	m_PlayerPimpl->isCharacterController = true;
	// ===================================

	m_PlayerPimpl->PostInit(this);
}

CPlayerZombie_small::~CPlayerZombie_small()
{
	m_PlayerPimpl->m_GameManager->GetSceneManager()->destroySceneNode(m_PlayerPimpl->Name);
}

void CPlayerZombie_small::SetupMapping()
{
}

void CPlayerZombie_small::Update(const f32& elapsedTime)
{
	UpdateDefault(elapsedTime);
}

void CPlayerZombie_small::OnShotFired()
{
	CPlayer::OnShotFired();
}
// CPlayerZombie_smallFactory
CPlayerZombie_smallFactory::CPlayerZombie_smallFactory()
{
	PlayerType = "ZOMBIE_SMALL";
}

CPlayerZombie_smallFactory::~CPlayerZombie_smallFactory()
{
}

Core::CPlayer* CPlayerZombie_smallFactory::CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy)
{
	return new CPlayerZombie_small(Name, PhysicsStrategy);
}

}
}
