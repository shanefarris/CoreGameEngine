#ifndef _OGREBULLETDYNAMICS_PhysicState_H
#define _OGREBULLETDYNAMICS_PhysicState_H

#include "OgreBulletDynamicsPreRequisites.h"

namespace OgreBulletDynamics
{
    // Object transforms
    class PhysicState : public btMotionState
    {
    public:
	    PhysicState(RigidBody *parent);
	    ~PhysicState();

	    virtual void getWorldTransform(btTransform& worldTrans ) const;
	    virtual void setWorldTransform(const btTransform& worldTrans);	
    
    protected:
        RigidBody *mObject;
    };
}
#endif //_OGREBULLETDYNAMICS_PhysicState_H

