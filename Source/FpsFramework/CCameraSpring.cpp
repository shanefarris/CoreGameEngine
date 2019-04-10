#if 1
#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CCameraSpring.h"
#include "CCameraManager.h"
#include "CInputManager.h"
#include "CPlayer.h"
#include "CInputEvent.h"

#include "OgreCamera.h"
#include "OgreSceneNode.h"

using namespace Core;

CCameraSpring::CCameraSpring(const char* Name, SceneNode* Parent)
{
	m_Mode = ECM_SPRING;

	//m_CameraNode->setAutoTracking (true, m_TargetNode);		// The camera will always look at the camera target
	//m_CameraNode->setFixedYawAxis (true);					// Needed because of auto tracking

	// Default settings
	m_Stiffness = 15.0f;
	m_Dampening = 10.0f;
	m_Mass = 20.0f;

	m_Camera = CCameraManager::Instance()->GetCamera();

	m_Camera->lookAt(Vector3(0.0f, 0.0f, 10.0f));
	// Default should be 0,0,0 otherwise its an offset to the player
	m_Camera->setPosition(0.0f, 0.0f, 0.0f);

	isPlayerFriendly = true;
}

void CCameraSpring::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition) 
{
	m_CameraNode->setPosition(cameraPosition);
	m_TargetNode->setPosition(targetPosition);
}

void CCameraSpring::Update(const f32& elapsedTime) 
{
	if(!isEnabled)
		return;

	// If there is no player there's nothing to chase
	if(!CGameObjectManager::Instance()->GetHumanPlayer())
		return;

	// Update direction
	m_Direction = m_Camera->getOrientation() * Vector3::NEGATIVE_UNIT_Z;
	m_Direction.normalise();

	//Set the desired position, e.g. somewhere behind and above the camera
	m_DesiredPosition = CGameObjectManager::Instance()->GetHumanPlayer()->GetPlayerNode()->getPosition();
	m_DesiredPosition = (m_Direction * -15) + m_DesiredPosition  + Vector3(0, 25, 0);

	Vector3 cameraPosition = m_Camera->getPosition();
    
	//Get the stretch by subtracting desired position from current position and multiply by stiffness
	m_Stretch.x = (cameraPosition.x - m_DesiredPosition.x) * -m_Stiffness;
	m_Stretch.y = (cameraPosition.y - m_DesiredPosition.y) * -m_Stiffness;
	m_Stretch.z = (cameraPosition.z - m_DesiredPosition.z) * -m_Stiffness;
    
	//Get the dampened velocity by multiplying velocity by dampening
	m_DampenedVelocity.x = m_Velocity.x * m_Dampening;
	m_DampenedVelocity.y = m_Velocity.y * m_Dampening;
	m_DampenedVelocity.z = m_Velocity.z * m_Dampening;

	//Force is the stretch minus the dampened velocity
	m_Force = m_Stretch - m_DampenedVelocity;

	//Get the acceleration based on F=MA(A = F/M)
	m_Acceleration.x = m_Force.x * (1 / m_Mass);
	m_Acceleration.y = m_Force.y * (1 / m_Mass);
	m_Acceleration.z = m_Force.z * (1 / m_Mass);

	//Add the acceleration to the velocity
	m_Velocity +=m_Acceleration;

	// New camera position
	m_Camera->setPosition(cameraPosition + m_Velocity);

	CInputMouseEvent evt;
	CInputManager::Instance()->GetMouseEvent(evt);
	Radian RotX = Degree(-evt.relX * 0.13f);
	Radian RotY = Degree(-evt.relY * 0.13f);
	m_Camera->yaw(RotX);
	m_Camera->pitch(RotY);
}

#endif