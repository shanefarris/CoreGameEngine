// In this mode the camera position and orientation never change. 

#ifndef __CCAMERA_FIXED_H__
#define __CCAMERA_FIXED_H__

#include "Defines.h"
#include "ICamera.h"

#include "OgreVector3.h"

namespace Core
{
    class CCameraFixed : public ICamera
	{
	public:

        CCameraFixed(const char* Name);
        ~CCameraFixed();

        void Update(const f32& elapsedTime);
        void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);

        inline void SetCameraPosition(const Vector3& Position);
        inline void SetCameraOrientation(Quaternion orient);
        inline void SetCameraOrientation(const Radian& roll, const Radian& yaw, const Radian& pitch);
		
    private:
        Vector3			mLastPosition;
        Quaternion		mLastOrientation;
		Quaternion		mCameraOrientation;
	};
}

#endif // __CCAMERA_FIXED_H__
