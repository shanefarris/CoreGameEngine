//// In this mode the camera is constrained to the limits of a plane. The camera always points to the target, perpendicularly to the plane.
//
//#ifndef __CCAMERA_BINDEDPLANE_H__
//#define __CCAMERA_BINDEDPLANE_H__
//
//#include "Defines.h"
//#include "ICamera.h"
//
//namespace Core
//{
//class DllExport PlaneBindedCameraMode : public ICamera
//	{
//	public:
//
//        PlaneBindedCameraMode(CameraControlSystem* cam, Ogre::Plane &plane, const Ogre::Vector3 &fixedAxis = Ogre::Vector3::UNIT_Y) 
//            : mFixedAxis(fixedAxis)
//			, mPlane(plane)
//        {
//            mTightness = 1;
//        }
//
//        virtual ~PlaneBindedCameraMode(){};
//
//        virtual bool init()
//        {
//            m_Camera->setFixedYawAxis(true, mFixedAxis);
//            m_Camera->setAutoTracking(true);
//
//            return true;
//        }
//
//        virtual void Update(const Ogre::Real& elapsedTime)
//        {
//            Ogre::Real distance = mPlane.getDistance(mCameraCS->getCameraTargetPosition());
//
//            Ogre::Vector3 cameraCurrentPosition = mCameraCS->getCameraPosition();
//            Ogre::Vector3 cameraFinalPositionIfNoTightness = mCameraCS->getCameraTargetPosition() -
//                mPlane.normal.normalisedCopy() * distance;
//
//            Ogre::Vector3 diff = (cameraFinalPositionIfNoTightness - cameraCurrentPosition) * mTightness;
//            mCameraPosition += diff;
//        };
//
//        virtual void instantUpdate()
//        {
//            Ogre::Real distance = mPlane.getDistance(mCameraCS->getCameraTargetPosition());
//            mCameraPosition = mCameraCS->getCameraTargetPosition() - 
//                mPlane.normal.normalisedCopy() * distance;
//        };
//		
//    protected:
//        Ogre::Vector3 mFixedAxis;
//        Ogre::Plane mPlane;
//	};
//}
//
//#endif // __CCAMERA_BINDEDPLANE_H__