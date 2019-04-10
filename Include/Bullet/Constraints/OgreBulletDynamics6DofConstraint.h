#ifndef _OGREBULLETDYNAMICS_SixDofConstraint_H
#define _OGREBULLETDYNAMICS_SixDofConstraint_H

#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletDynamicsConstraint.h"

namespace OgreBulletDynamics
{
    // SixDofConstraint  class
    class SixDofConstraint : public TypedConstraint
    {
    public:
        SixDofConstraint(RigidBody * rbA, RigidBody * rbB, 
            const Ogre::Vector3& FrameInAVector, const Ogre::Quaternion& FrameInAOrientation,
            const Ogre::Vector3& FrameInBVector, const Ogre::Quaternion& FrameInBOrientation);

		void	setLinearLowerLimit(const Ogre::Vector3& linearLower);
		void	setLinearUpperLimit(const Ogre::Vector3& linearUpper);
		void	setAngularLowerLimit(const Ogre::Vector3& angularLower);
		void	setAngularUpperLimit(const Ogre::Vector3& angularUpper);

		void	setLimit(const int axis, const Ogre::Real lo, const Ogre::Real hi);
		//! Test limit
		/*!
		- free means upper < lower,
		- locked means upper == lower
		- limited means upper > lower
		- limitIndex: first 3 are linear, next 3 are angular
		*/
		bool	 isLimited(int limitIndex);

        virtual ~SixDofConstraint();

    };
}
#endif //_OGREBULLETDYNAMICS_SixDofConstraint_H

