#include "CCameraChaseSpaceShip.h"
#include "CCameraManager.h"
#include "CInputManager.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "CInputEvent.h"

#include "OgreCamera.h"
#include "OgreSceneNode.h"

using namespace Core;

CCameraChaseSpaceShip::CCameraChaseSpaceShip(const char* Name)
{
	m_Mode = ECM_CHASE;

	CPlayer* player = CGameObjectManager::Instance()->GetHumanPlayer();
	if(player)
		m_Camera->lookAt(player->GetDirection());
	else
		m_Camera->lookAt(Vector3(0.0f, 1.0f, 10.0f));

	// Default should be 0,0,0 otherwise its an offset to the player
	m_Camera->setPosition(0.0f, 0.0f, 0.0f);

	isPlayerFriendly = true;
}

void CCameraChaseSpaceShip::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition) 
{
	//m_CameraNode->setPosition(cameraPosition);
	//m_TargetNode->setPosition(targetPosition);
}

void CCameraChaseSpaceShip::Update(const f32& elapsedTime) 
{
	if(!isEnabled)
		return;

	// If there is no player there's nothing to chase
	CPlayer* player = CGameObjectManager::Instance()->GetHumanPlayer();
	if(!player)
		return;

	// Update direction
	auto direction = player->GetDirection().normalisedCopy();

	//Set the desired position, e.g. somewhere behind and above the camera
	auto desiredPosition = player->GetPlayerNode()->getPosition();
	desiredPosition = (direction * -40) + desiredPosition  + Vector3(0, 50, 0);

	// New camera position
	m_CameraManager->SetCameraPos(desiredPosition);

	CInputMouseEvent evt;
	CInputManager::Instance()->GetMouseEvent(evt);
	Radian RotX = Degree(-evt.relX * 0.13f);
	Radian RotY = Degree(-evt.relY * 0.13f);
	m_Camera->yaw(RotX);
	m_Camera->pitch(RotY);
}