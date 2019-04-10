#include "CPlayerFpsArms.h"
#include "CPlayerPimpl.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "CItemProfile.h"
#include "CInventoryItem.h"
#include "CItemsManager.h"
#include "CInputManager.h"
#include "CInputEvent.h"
#include "CInputListener.h"
#include "IPhysicsStrategy.h"
#include "CPlayerSoundComponent.h"
#include "AnimationMapping.h"
#include "Ai/CFpsVehicle.h"
#include "CGameObjectManager.h"

#include "OgreEntity.h"
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreOverlayManager.h"
#include "OgreAnimationState.h"

using namespace Core::Physics;
using namespace Core::Plugin;

namespace Core
{
namespace Plugin
{
CPlayerFpsArms::CPlayerFpsArms(const char* Name, IPhysicsStrategy* PhysicsStrategy) : CPlayer(Name, PhysicsStrategy)
{
	//// Beretta
	//auto berettaNode = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode("beretta_node");
	//auto berettaEntity = CGameManager::Instance()->GetSceneManager()->createEntity("beretta_entity", "beretta.mesh");
	////berettaNode->attachObject(berettaEntity);
	////berettaNode->setPosition(0, 10, 0);
	//berettaNode->setScale(0.415786f, 0.415786f, 0.415786f);
	//berettaNode->rotate(Quaternion(0.500133f, 0.500363f, -0.500304f, 0.4992f));

	//auto holderNode = berettaNode->createChildSceneNode("holder_node");
	//auto holderEntity = CGameManager::Instance()->GetSceneManager()->createEntity("holder_entity", "holder.mesh");
	//holderNode->attachObject(holderEntity);
	//holderNode->setPosition(24.891f, -0.548618f, 8.17257f);
	//holderNode->setScale(1.0f, 1.0f, 1.0f);
	//holderNode->rotate(Quaternion(5.68433e-013f, 1.16415e-010f, 0.0f, 1.0f));

	//auto trigerNode = berettaNode->createChildSceneNode("triger_node");
	//auto trigerEntity = CGameManager::Instance()->GetSceneManager()->createEntity("triger_entity", "triger.mesh");
	//trigerNode->attachObject(trigerEntity);
	//trigerNode->setPosition(4.60053f, -0.548618f, -9.42175f);
	//trigerNode->setScale(1, 1, 1);
	//trigerNode->rotate(Quaternion(1.5234e-011f, 2.91038e-011f, 0.0f, 1.0f));

	//auto beretta_topNode = berettaNode->createChildSceneNode("beretta_top_node");
	//auto beretta_topEntity = CGameManager::Instance()->GetSceneManager()->createEntity("beretta_top_entity", "beretta_top.mesh");
	//beretta_topNode->attachObject(beretta_topEntity);
	//beretta_topNode->setPosition(-2.06516f, -0.548622f, -18.0231f);
	//beretta_topNode->setScale(1, 1, 1);
	//beretta_topNode->rotate(Quaternion(1.5234e-011f, 2.91038e-011f, 0.0f, 1.0f));

	//auto peenNode = berettaNode->createChildSceneNode("peen_node");
	//auto peenEntity = CGameManager::Instance()->GetSceneManager()->createEntity("peen_entity", "peen.mesh");
	//peenNode->attachObject(peenEntity);
	//peenNode->setPosition(28.6745f, -0.548622f, -17.3448f);
	//peenNode->setScale(1, 1, 1);
	//peenNode->rotate(Quaternion(1.5234e-011f, 2.91038e-011f, 0, 1));

	// Player arms
	m_PlayerPimpl->m_MeshName = "hands.mesh";
	m_PlayerPimpl->m_PlayerNode = CGameManager::Instance()->GetSceneManager()->createSceneNode("arm_node");
	m_PlayerPimpl->m_PlayerEntity = CGameManager::Instance()->GetSceneManager()->createEntity("arm_entity", "hands.mesh");
	m_PlayerPimpl->m_PlayerNode->attachObject(m_PlayerPimpl->m_PlayerEntity);
	//m_PlayerPimpl->m_PlayerNode->rotate(Quaternion(Degree(180), Vector3::UNIT_Y));

	//auto overlay = OverlayManager::getSingleton().create("3dOverlay");
	//overlay->add3D(m_PlayerPimpl->m_PlayerNode);
	////m_PlayerPimpl->m_PlayerNode->setPosition(Vector3(0, -0.25f, 0));
	//overlay->show();

	//auto quat = Quaternion(Degree(-90), Vector3::UNIT_X) * Quaternion(Degree(180), Vector3::UNIT_Y);
	//m_PlayerPimpl->m_PlayerEntity->attachObjectToBone("Bip01 R Hand",(MovableObject*)berettaEntity, quat, Vector3(.4f, 0.0f, 0.0f));

	// ====== Set the player type ========
	m_PlayerPimpl->m_PlayerType = "FPSARMS";
	// ===================================

	// === Set the player bone names =====
	m_PlayerPimpl->m_RootBoneName = "";
	m_PlayerPimpl->m_HeadBoneName = "";
	// ===================================

	// Does the characater have a controller
	m_PlayerPimpl->isCharacterController = true;
	// ===================================

	m_PlayerPimpl->PostInit(this);

	// Map animation names and sounds
	SetupMapping();

	SetHumanPlayer(true);
	m_PlayerPimpl->isFpsView = true;
	CGameObjectManager::Instance()->SetHumanPlayer(this);
}

CPlayerFpsArms::~CPlayerFpsArms()
{
	m_PlayerPimpl->m_GameManager->GetSceneManager()->destroySceneNode(m_PlayerPimpl->Name);
}

void CPlayerFpsArms::SetupMapping()
{
	// Animations
	m_PlayerPimpl->m_AnimationMaps[EAS_WALK] = new SoundToAnimation("walking", "");
	m_PlayerPimpl->m_AnimationMaps[EAS_RUN] = new SoundToAnimation("run", "");
	m_PlayerPimpl->m_AnimationMaps[EAS_RELOAD] = new SoundToAnimation("reload", "");
	m_PlayerPimpl->m_AnimationMaps[EAS_AIM_STAND] = new SoundToAnimation("fire", "");
	m_PlayerPimpl->m_AnimationMaps[EAS_IDLE] = new SoundToAnimation("idle", "");
	m_PlayerPimpl->m_AnimationMaps[EAS_SPRINT] = new SoundToAnimation("sprint", "");
	m_PlayerPimpl->m_AnimationMaps[EAS_CHANGE_ITEM] = new SoundToAnimation("change", "");

	m_PlayerPimpl->m_AnimationState = m_PlayerPimpl->m_PlayerEntity->getAnimationState(m_PlayerPimpl->m_AnimationMaps[EAS_WALK]->Animation);
	m_PlayerPimpl->m_AnimationState->setEnabled(true);
	m_PlayerPimpl->m_AnimationState->setTimePosition(0);

	// Sounds
	m_PlayerPimpl->m_PlayerSoundComponent->SetShot("Rifle1_mono.ogg");
}

void CPlayerFpsArms::Update(const f32& elapsedTime)
{
	UpdateDefault(elapsedTime);
	return;

	m_PlayerPimpl->m_Movement = Vector3::ZERO;

	auto orien = CCameraManager::Instance()->GetCamera()->getOrientation();
	m_PlayerPimpl->m_PlayerNode->setOrientation(orien);
	//m_PlayerPimpl->m_PlayerNode->setPosition(CCameraManager::Instance()->GetCameraPos() + (orien * Ogre::Vector3(0.3,-0.15,-1.1)));

	// Are we in good health
	if(m_PlayerPimpl->m_Health <= 0.0f)
		return;

	// If console is not opened, and is this the human player
	if(!m_PlayerPimpl->m_GameManager->GetConsoleVisible())
	{
		// Update direction
		m_PlayerPimpl->m_Direction = m_PlayerPimpl->m_PlayerNode->getOrientation() * Vector3::UNIT_Z;
		m_PlayerPimpl->m_Direction.normalise();

		// Get movement
		f32 scalar = 0;
		auto inputManager = CInputManager::Instance();
		if(inputManager->IsKeyDown(KC_LSHIFT))
			scalar = m_PlayerPimpl->m_RunSpeed;
		else
			scalar = m_PlayerPimpl->m_WalkSpeed;

		if(inputManager->IsKeyDown(KC_W)) 
		{
			m_PlayerPimpl->m_Movement += m_PlayerPimpl->m_Direction;
		}
		if(inputManager->IsKeyDown(KC_S)) 
		{
			m_PlayerPimpl->m_Movement += -m_PlayerPimpl->m_Direction;
		}
		if(inputManager->IsKeyDown(KC_A)) 
		{
			m_PlayerPimpl->m_Movement.z += m_PlayerPimpl->m_Direction.x * -1;
			m_PlayerPimpl->m_Movement.x += m_PlayerPimpl->m_Direction.z;
		}
		if(inputManager->IsKeyDown(KC_D))
		{
			m_PlayerPimpl->m_Movement.x += m_PlayerPimpl->m_Direction.z * -1;
			m_PlayerPimpl->m_Movement.z += m_PlayerPimpl->m_Direction.x;
		}

		// Move
		if(m_PlayerPimpl->m_Movement != Vector3::ZERO)
		{
			m_PlayerPimpl->m_Movement *= scalar * elapsedTime;
			m_PlayerPimpl->m_PlayerNode->translate(m_PlayerPimpl->m_Movement);
		}

		// Pickup object
		if(inputManager->IsKeyDown(KC_G))
		{
			OnPickupItem();
		}

		// mouse
		CInputMouseEvent evt;
		inputManager->GetMouseEvent(evt);
		Radian m_RotX = Degree(-evt.relX * 0.13f);

		// update camera
		m_PlayerPimpl->m_PlayerNode->yaw(m_RotX, Node::TS_WORLD);	

		// Picking shots
		if (m_PlayerPimpl->m_CurrItem && 
			m_PlayerPimpl->m_CurrItem->GetType() == EIT_WEAPON && 
			inputManager->IsMouseDown(MB_Left))
		{
			OnShotFired();	
		}
	}
}

void CPlayerFpsArms::OnShotFired()
{
	CPlayer::OnShotFired();
}
// CPlayerFpsArmsFactory
CPlayerFpsArmsFactory::CPlayerFpsArmsFactory()
{
	PlayerType = "FPSARMS";
}

CPlayerFpsArmsFactory::~CPlayerFpsArmsFactory()
{
}

Core::CPlayer* CPlayerFpsArmsFactory::CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy)
{
	return new CPlayerFpsArms(Name, PhysicsStrategy);
}

}
}
