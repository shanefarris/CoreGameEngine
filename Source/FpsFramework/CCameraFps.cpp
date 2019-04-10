#if 1
#include "CCameraFps.h"
#include "CCameraManager.h"
#include "CInputManager.h"
#include "CPlayer.h"
#include "CGameObjectManager.h"
#include "CInputEvent.h"

#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreVector3.h"

using namespace Core;

CCameraFps::CCameraFps(const char* Name, SceneNode* Parent)
{
	m_Mode = ECM_FPS;

	m_Camera->lookAt(Vector3::NEGATIVE_UNIT_Z);
	// Default should be 0,0,0 otherwise its an offset to the player
	m_Camera->setPosition(0.0f, 0.0f, 0.0f);

	isPlayerFriendly = true;
}

void CCameraFps::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition) 
{
	m_CameraNode->setPosition(cameraPosition);
	m_TargetNode->setPosition(targetPosition);
}

void CCameraFps::Update(const f32& elapsedTime) 
{
	if(!isEnabled)
		return;

	// If there is no player there's nothing to chase
	if(!CGameObjectManager::Instance()->GetHumanPlayer())
		return;

	// Update direction
	auto direction = CGameObjectManager::Instance()->GetHumanPlayer()->GetDirection();
	direction.normalise();

	//Set the desired position, e.g. somewhere behind and above the camera
	auto desiredPosition = CGameObjectManager::Instance()->GetHumanPlayer()->GetPlayerNode()->getPosition();
	desiredPosition = direction + desiredPosition + Vector3(0, 8, 0);

	// New camera position
	m_Camera->setPosition(desiredPosition);

	CInputMouseEvent evt;
	CInputManager::Instance()->GetMouseEvent(evt);
	Radian RotX = Degree(-evt.relX * 0.13f);
	Radian RotY = Degree(-evt.relY * 0.13f);
	m_Camera->yaw(RotX);
	m_Camera->pitch(RotY);
}

#endif