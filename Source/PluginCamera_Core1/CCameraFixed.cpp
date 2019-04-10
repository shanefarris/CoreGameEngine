#include "CCameraFixed.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "CInputManager.h"

#include "OgreCamera.h"
#include "OgreRoot.h"
#include "OgreRenderWindow.h"
#include "OgreRenderSystemCapabilities.h"

using namespace Core;

CCameraFixed::CCameraFixed(const char* Name) 
    : mLastPosition(Vector3::ZERO)
    , mLastOrientation(Quaternion::IDENTITY) 
{
	m_Mode = ECM_FIXED;

	m_Camera = CCameraManager::Instance()->GetCamera();
    m_Camera->setFixedYawAxis(true, Vector3::UNIT_Y);
    m_Camera->setAutoTracking(false);

	m_Camera->lookAt(Vector3::ZERO);

	// Default should be 0,0,0 otherwise its an offset to the player
	m_Camera->setPosition(0.0f, 10.0f, 0.0f);
	m_Camera->setNearClipDistance(1);
}

CCameraFixed::~CCameraFixed() 
{
}

void CCameraFixed::Update(const f32& elapsedTime) 
{ 
}

void CCameraFixed::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition)
{
    m_Camera->setPosition(mLastPosition);
    mCameraOrientation = mLastOrientation;
};

void CCameraFixed::SetCameraPosition(const Vector3& Position)
{
    mLastPosition = Position;
    m_Camera->setPosition(Position);
}

void CCameraFixed::SetCameraOrientation(Quaternion orient)
{
    mLastOrientation = orient;
    mCameraOrientation = mLastOrientation;
}

void CCameraFixed::SetCameraOrientation(const Radian& roll, const Radian& yaw, const Radian& pitch)
{
    mLastOrientation = Quaternion(roll,Vector3::UNIT_Z) 
                    * Quaternion(yaw,Vector3::UNIT_Y)
                    * Quaternion(pitch,Vector3::UNIT_X);

    mCameraOrientation = mLastOrientation;
}

