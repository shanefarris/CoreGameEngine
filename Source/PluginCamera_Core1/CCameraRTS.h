#ifndef __CCAMERARTS_H__
#define __CCAMERARTS_H__

#include "Defines.h"
#include "ICamera.h"

#include "OgreMath.h"
#include "OgreVector3.h"
#include "OgreQuaternion.h"

namespace Core
{
	namespace Nature
	{
		class CNatureManager;
	}

	class CCameraRTS : public ICamera
	{
	private:
		Radian		m_RotX;
		Radian		m_RotY;
		Degree		m_RotScale;
		Degree		m_RotateSpeed;

		f32 MoveScale;
		Quaternion mRotation;
        Radian mCameraPitch;
        Vector3 mUpAxis;
        Vector3 mLeftAxis;
        Vector3 mHeightAxis;
        f32 mMoveFactor;
        f32 mHeightDisplacement;
        f32 mLateralDisplacement;
        f32 mVerticalDisplacement;
        f32 mZoom;
        f32 mMinZoom;
        f32 mMaxZoom;

		f32 borderWidthPercentage;
		s32 leftBorder;
		s32 rightBorder;
		s32 topBorder;
		s32 bottomBorder;

		Quaternion mCameraOrientation;

		Nature::CNatureManager*	m_NatureManager;

	public:
		CCameraRTS(const char* Name, const Vector3 &upAxis = Vector3::NEGATIVE_UNIT_Z, const Vector3 &leftAxis = Vector3::NEGATIVE_UNIT_X, const Radian cameraPitch = Radian(Degree(45)), f32 minZoom = 0, f32 maxZoom = 1000);

		void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);
		void Update(const f32& elapsedTime);

		void SetCameraPitch(const Radian& cameraPitch);
        Radian GetCameraPitch();       
        inline void SetMoveFactor(const f32& unitsPerSecond);		// Set the moving speed factor (increase the height)
        void SetZoom(const f32& zoom);
        f32 GetZoom();
	};
}

#endif // __CCAMERARTS_H__