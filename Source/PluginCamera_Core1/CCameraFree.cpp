#include "CGameManager.h"
#include "CCameraManager.h"
#include "CInputManager.h"
#include "CCameraFree.h"
#include "CInputEvent.h"
#include "CInputListener.h"

#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreRoot.h"

using namespace Core;

CCameraFree::CCameraFree(const char* Name, SceneNode* Parent)
{
	m_Mode = ECM_FREE;
	MoveScale = 0.0f; 
	TimeUntilNextToggle = 0.0f;
	SceneDetailIndex = 0;

	m_CameraNode->setPosition(0, 0, 0);

	m_Camera->lookAt(Vector3(0.0f, 0.0f, 0.0f));
	// Default should be 0,0,0 otherwise its an offset to the player
	m_Camera->setPosition(0.0f, 0.0f, 0.0f);
	m_Camera->setNearClipDistance(1);
}

void CCameraFree::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition)
{
}

void CCameraFree::Update(const f32& elapsedTime) 
{
	TimeUntilNextToggle -= elapsedTime;

	Vector3 direction = m_Camera->getOrientation() * Vector3::NEGATIVE_UNIT_Z;
	direction.normalise();
	auto translateVector = Vector3::ZERO;

	// one of the input modes is immediate, so setup what is needed for immediate movement
	if(TimeUntilNextToggle >= 0)
		TimeUntilNextToggle -= elapsedTime;

	// Move MOVE_SPEED units per second
	MoveScale = m_MoveSpeed * elapsedTime;

	auto inputManager = CInputManager::Instance();

	// Mouse
	CInputMouseEvent evt;
	inputManager->GetMouseEvent(evt);
	if(inputManager->IsMouseDown(MB_Right))
	{
		translateVector.x += evt.relX * m_MouseRotationScale;
		translateVector.y -= evt.relY * m_MouseRotationScale;
	}
	else
	{
		m_RotX = Degree(-evt.relX * m_MouseRotationScale);
		m_RotY = Degree(-evt.relY * m_MouseRotationScale);
	}

	if(inputManager->IsKeyDown(KC_W)) 
	{
		translateVector += direction * MoveScale;
	}
	if(inputManager->IsKeyDown(KC_S)) 
	{
		translateVector -= direction * MoveScale;
	}
	if(inputManager->IsKeyDown(KC_A)) 
	{
		translateVector.x = -MoveScale;
	}
	if(inputManager->IsKeyDown(KC_D))
	{
		translateVector.x = MoveScale;
	}
	if(inputManager->IsKeyDown(KC_PGUP))
	{
		translateVector.y = MoveScale;	// Move camera up
	}
	if(inputManager->IsKeyDown(KC_PGDOWN))
	{
		translateVector.y = -MoveScale;	// Move camera down
	}

	if(inputManager->IsKeyDown(KC_R) && TimeUntilNextToggle <=0)
	{
		SceneDetailIndex = (SceneDetailIndex + 1) % 3;
		switch(SceneDetailIndex) 
		{
			case 0 : m_Camera->setPolygonMode(PM_SOLID); break;
			case 1 : m_Camera->setPolygonMode(PM_WIREFRAME); break;
			case 2 : m_Camera->setPolygonMode(PM_POINTS); break;
		}
		TimeUntilNextToggle = 0.5;
	}

	// update camera
	m_Camera->yaw(m_RotX);
	m_Camera->pitch(m_RotY);
	if(translateVector != Vector3::ZERO)
		m_Camera->move(translateVector);
	//m_CameraNode->translate(m_TranslateVector);
}