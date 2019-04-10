#include "CCameraChase.h"
#include "CCameraManager.h"
#include "CInputManager.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "CInputEvent.h"

#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreVector3.h"

using namespace Core;

CCameraChase::CCameraChase(const char* Name, SceneNode* Parent)
{
	m_Mode = ECM_CHASE;

	CPlayer* player = CGameObjectManager::Instance()->GetHumanPlayer();
	if(player)
		m_Camera->setDirection(player->GetPlayerNode()->getOrientation() * Vector3::UNIT_Z); // Don't use player's direction because it needs to be updated at least once to be correct.
	else
		m_Camera->setDirection(Vector3(0.0f, 1.0f, 10.0f));

	// Default should be 0,0,0 otherwise its an offset to the player
	m_Camera->setPosition(0.0f, 0.0f, 0.0f);

	isPlayerFriendly = true;
}

void CCameraChase::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition) 
{
}

void CCameraChase::Update(const f32& elapsedTime) 
{
	if(!isEnabled)
		return;

	// If there is no player there's nothing to chase
	auto player = CGameObjectManager::Instance()->GetHumanPlayer();
	if(!player)
		return;

	// Update direction
	auto direction = player->GetDirection().normalisedCopy();

	//Set the desired position, e.g. somewhere behind and above the camera
	auto desiredPosition = player->GetPlayerNode()->getPosition();
	desiredPosition = (direction * -5) + desiredPosition  + Vector3(0, 9.5, 0);

	// New camera position
	m_CameraManager->SetCameraPos(desiredPosition);

	CInputMouseEvent evt;
	CInputManager::Instance()->GetMouseEvent(evt);
	Radian RotX = Degree(-evt.relX * 0.13f);
	Radian RotY = Degree(-evt.relY * 0.13f);
	m_Camera->yaw(RotX);
	m_Camera->pitch(RotY);
}