#ifndef _OGREBULLETDYNAMICS_HingeConstraint_H
#define _OGREBULLETDYNAMICS_HingeConstraint_H

#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletDynamicsConstraint.h"

namespace OgreBulletDynamics
{
    // HingeConstraint  class
    class HingeConstraint : public TypedConstraint
    {
    public:
        HingeConstraint(RigidBody * rbA, RigidBody * rbB, const Ogre::Vector3& pivotInA,
                            const Ogre::Vector3& pivotInB, const Ogre::Vector3& axisInA, 
                            const Ogre::Vector3& axisInB);
        HingeConstraint(RigidBody * rbA, const Ogre::Vector3& pivotInA, const Ogre::Vector3&  axisInA);
        virtual ~HingeConstraint();
    };
}
#endif //_OGREBULLETDYNAMICS_HingeConstraint_H

