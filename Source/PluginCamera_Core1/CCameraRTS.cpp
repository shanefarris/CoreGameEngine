#include "CCameraRTS.h"
#include "CCameraManager.h"
#include "CInputManager.h"
#include "CNatureManager.h"
#include "CInputEvent.h"

#include "OgreCamera.h"

using namespace Core;

CCameraRTS::CCameraRTS(const char* Name, const Vector3 &upAxis, const Vector3 &leftAxis, const Radian cameraPitch, f32 minZoom, f32 maxZoom)
	: mUpAxis(upAxis.normalisedCopy()),
    mLeftAxis(leftAxis.normalisedCopy()),
    MoveScale(5.0f),
    mCameraPitch(cameraPitch),
    mMinZoom(minZoom),
    mMaxZoom(maxZoom),
    mZoom(20.0f),
	mHeightDisplacement(0.0f)
{
	m_Mode = ECM_RTS;

	mRotation = Quaternion(cameraPitch, leftAxis);
    mHeightAxis = -upAxis.crossProduct(leftAxis).normalisedCopy();

    mLateralDisplacement = 0;
    mVerticalDisplacement = 0;

	borderWidthPercentage = 0.03f; // 3%
            
	mCameraOrientation = mRotation;

	// Set the nature manager
	m_NatureManager = Nature::CNatureManager::Instance();

	m_Camera = CCameraManager::Instance()->GetCamera();
	auto height = m_NatureManager->GetTerrainHeightAt(0, 0);
	m_Camera->setPosition(Vector3(0, height + mZoom, 0));
	m_Camera->setFixedYawAxis(false);
	m_Camera->setAutoTracking(false);
	m_Camera->lookAt(0, 0, 0);

	// not using node
	m_CameraNode = nullptr;
	m_TargetNode = nullptr;
}

void CCameraRTS::SetCameraPitch(const Radian& cameraPitch)
{
    mCameraPitch = cameraPitch;
    mRotation = Quaternion(mCameraPitch, mLeftAxis);
}

Radian CCameraRTS::GetCameraPitch()
{ 
	return mCameraPitch; 
}

void CCameraRTS::SetMoveFactor(const f32& unitsPerSecond)
{ 
	MoveScale = unitsPerSecond; 
}

void CCameraRTS::SetZoom(const f32& zoom)
{
    if(zoom > mMinZoom && zoom < mMaxZoom)
    {
        mHeightDisplacement = zoom - mZoom;
        mZoom = zoom;
    }
}

f32 CCameraRTS::GetZoom()
{ 
	return mZoom; 
}

void CCameraRTS::InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition)
{
	Ogre::Vector3 displacement = ((mUpAxis * mVerticalDisplacement)
        + (mHeightAxis * mHeightDisplacement)
        + (mLeftAxis * mLateralDisplacement));

    Vector3 mCameraPosition = m_Camera->getPosition();
	mCameraPosition += displacement;

    mHeightDisplacement = 0;
    mLateralDisplacement = 0;
    mVerticalDisplacement = 0; 

    mCameraOrientation = mRotation;

	m_Camera->setPosition(mCameraPosition);
    m_Camera->setOrientation(mCameraOrientation);
}

void CCameraRTS::Update(const f32& elapsedTime) 
{
	// Mouse
	CInputMouseEvent evt;
	CInputManager::Instance()->GetMouseEvent(evt);
	leftBorder = evt.width * borderWidthPercentage;
    rightBorder = evt.width - (evt.width * borderWidthPercentage);
    topBorder = evt.height * borderWidthPercentage;
    bottomBorder = evt.height - (evt.height * borderWidthPercentage);

	if(evt.absX < leftBorder)
    {
		mLateralDisplacement += MoveScale * (leftBorder - evt.absX) / (f32)leftBorder;
    }
    else if(evt.absX > rightBorder)
    {
		mLateralDisplacement -= MoveScale * (evt.absX - rightBorder) / (f32)leftBorder;
    }

	if(evt.absY < topBorder)
    {
		mVerticalDisplacement += MoveScale * (topBorder - evt.absY) / (f32)topBorder;
    }
    else if(evt.absY > bottomBorder)
    {
		mVerticalDisplacement -= MoveScale * (evt.absY - bottomBorder) / (f32)topBorder;
    }

	if(evt.relZ != 0)
    {
		f32 desiredDisplacement = MoveScale * (Math::Sign((f32)evt.relZ) * 4.0f);
		f32 desiredZoom = mZoom + desiredDisplacement;

		SetZoom(desiredZoom);
    }

	auto displacement = ((mUpAxis * mVerticalDisplacement) + 
		(mHeightAxis * mHeightDisplacement) + 
		(mLeftAxis * mLateralDisplacement)) * elapsedTime * MoveScale;

    auto mCameraPosition = m_Camera->getPosition();
	mCameraPosition += displacement;

	auto terrainHeight = m_NatureManager->GetTerrainHeightAt(mCameraPosition.x, mCameraPosition.z);
	if(mCameraPosition.y <= terrainHeight)
	{
		mCameraPosition.y = terrainHeight + 1.0f;
	}

    mHeightDisplacement = 0;
    mLateralDisplacement = 0;
    mVerticalDisplacement = 0; 

    mCameraOrientation = mRotation;

	m_Camera->setPosition(mCameraPosition);
    m_Camera->setOrientation(mCameraOrientation);
}

