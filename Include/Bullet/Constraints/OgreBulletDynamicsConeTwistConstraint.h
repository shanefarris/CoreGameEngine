#ifndef _OGREBULLETDYNAMICS_ConeTwistConstraint_H
#define _OGREBULLETDYNAMICS_ConeTwistConstraint_H

#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletDynamicsConstraint.h"

namespace OgreBulletDynamics
{
    // ConeTwistConstraint  class
    class ConeTwistConstraint : public TypedConstraint
    {
    public:
        ConeTwistConstraint(RigidBody * rbA, RigidBody * rbB,
            const Ogre::Vector3& FrameInAVector, const Ogre::Quaternion& FrameInAOrientation,
            const Ogre::Vector3& FrameInBVector, const Ogre::Quaternion& FrameInBOrientation);

        virtual ~ConeTwistConstraint();
       
        void setLimit(Ogre::Real a, Ogre::Real b, Ogre::Real c);
    };
}
#endif //_OGREBULLETDYNAMICS_ConeTwistConstraint_H
