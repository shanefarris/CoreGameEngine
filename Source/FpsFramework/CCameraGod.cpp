#include "CCameraGod.h"
#include "CCameraManager.h"
#include "CInputManager.h"
#include "CTextOutput.h"
#include "CInputEvent.h"
#include "CInputListener.h"
#include "IO/CoreLogging.h"

#include "OgreCamera.h"
#include "OgreSceneNode.h"
#include "OgreStringConverter.h"
#include "OgreVector3.h"

using namespace Core;

CCameraGod::CCameraGod(const char* Name, SceneNode* Parent)
{
	m_Mode = ECM_GOD;
	MoveScale = 0.0f; 
	TimeUntilNextToggle = 0.0f;
	SceneDetailIndex = 0;
	m_MoveSpeed = 50.0f;

	m_TargetNode = nullptr;

	m_CameraNode->setPosition(0, 0, 0);
}

void CCameraGod::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition)
{
}

void CCameraGod::Update(const f32& elapsedTime) 
{
	if(!isEnabled)
		return;

	TimeUntilNextToggle -= elapsedTime;

	Vector3 direction = m_Camera->getOrientation() * Vector3::NEGATIVE_UNIT_Z;
	direction.normalise();
	auto translateVector = Vector3::ZERO;

	// one of the input modes is immediate, so setup what is needed for immediate movement
	if(TimeUntilNextToggle >= 0)
		TimeUntilNextToggle -= elapsedTime;

	// Move MOVE_SPEED units per second
	auto inputManager = CInputManager::Instance();
	MoveScale = m_MoveSpeed * elapsedTime;
	if(inputManager->IsKeyDown(KC_LSHIFT) || inputManager->IsKeyDown(KC_RSHIFT)) 
	{
		MoveScale *= 0.1f;
	}

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
	
	if(evt.relZ)
	{
		translateVector += direction * (MoveScale / 2.0f) * (f32)evt.relZ;
	}

	if(inputManager->IsKeyDown(KC_W)) 
	{
		translateVector += m_Camera->getDirection() * MoveScale;
	}
	if(inputManager->IsKeyDown(KC_S)) 
	{
		translateVector -= m_Camera->getDirection() * MoveScale;
	}
	if(inputManager->IsKeyDown(KC_A)) 
	{
		translateVector += m_Camera->getRight() * -MoveScale;
	}
	if(inputManager->IsKeyDown(KC_D))
	{
		translateVector += m_Camera->getRight() * MoveScale;
	}
	if(inputManager->IsKeyDown(KC_PGUP))
	{
		translateVector.y += MoveScale;
	}
	if(inputManager->IsKeyDown(KC_PGDOWN))
	{
		translateVector.y += -MoveScale;
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
	m_CameraNode->translate(translateVector);
	CORE_TEXT("cam_pos", StringConverter::toString(m_CameraNode->getPosition()).c_str());
}