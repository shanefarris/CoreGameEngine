#ifndef _OGREBULLETDYNAMICS_RaycastVehicle_H
#define _OGREBULLETDYNAMICS_RaycastVehicle_H

#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletDynamicsConstraint.h"

namespace OgreBulletDynamics
{
    // VehicleRayCaster  class
    class VehicleRayCaster
    {
    public:
        VehicleRayCaster(DynamicsWorld *world);
        virtual ~VehicleRayCaster();
        
        btVehicleRaycaster *getBulletVehicleRayCaster()
        {
			return static_cast <btVehicleRaycaster*> (mBulletVehicleRayCaster);
		};
         
    private:
        btDefaultVehicleRaycaster *mBulletVehicleRayCaster;        
    };

    // VehicleTuning  class
    class VehicleTuning
    {
    public:
        VehicleTuning(const Ogre::Real suspensionStiffness, 
			const Ogre::Real suspensionCompression,
            const Ogre::Real suspensionDamping, 
			const Ogre::Real maxSuspensionTravelCm, 
			const Ogre::Real frictionSlip);
        virtual ~VehicleTuning();
        
        btRaycastVehicle::btVehicleTuning *getBulletTuning() { return mBulletTuning; };
        
    private:
        btRaycastVehicle::btVehicleTuning *mBulletTuning;        
    };

    // RaycastVehicle  class
    class WheelInfo
    {
    public:
        WheelInfo(btWheelInfo &w): 
		mWheel(&w) { };
        virtual ~WheelInfo() { };

        btWheelInfo *getBulletWheelInfo(){return static_cast<btWheelInfo *> (mWheel);}
       
    protected:
        btWheelInfo                   *mWheel;
    };

    // RaycastVehicle  class
    class RaycastVehicle : public ActionInterface
    {
    public:
        RaycastVehicle(WheeledRigidBody *body,  
            VehicleTuning        *vt,
            VehicleRayCaster     *caster = 0);

        virtual ~RaycastVehicle();

        btRaycastVehicle *getBulletVehicle() { return static_cast<btRaycastVehicle *> (mActionInterface); };
        void setCoordinateSystem(int rightIndex,int upIndex,int forwardIndex);

        void addWheel(Ogre::SceneNode *node,
            const Ogre::Vector3 &connectionPoint,
            const Ogre::Vector3 &wheelDirection,
            const Ogre::Vector3 &wheelAxle,
            const Ogre::Real suspensionRestLength,
            const Ogre::Real wheelRadius,
            const bool isFrontWheel,
            const Ogre::Real wheelFriction,
            const Ogre::Real rollInfluence);

        void setWheelsAttached();		// when all wheels are attached, make vehicle aware of it
        void setTransform();			// update wheels when needed.
        void applyEngineForce (float engineForce, int wheel);
        void setSteeringValue(float steering, int wheel);

     protected:
         VehicleTuning                   *mTuning;
         VehicleRayCaster                *mRayCaster;
         std::vector<btWheelInfo *>         mWheelsInfo;
         std::vector<Ogre::SceneNode *>      mWheelNodes;
         WheeledRigidBody* mChassisBody;
         Ogre::SceneNode *mNode;
    };
}
#endif //_OGREBULLETDYNAMICS_RaycastVehicle_H

