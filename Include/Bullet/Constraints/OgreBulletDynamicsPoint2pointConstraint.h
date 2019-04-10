#ifndef _OGREBULLETDYNAMICS_PointTopointConstraint_H
#define _OGREBULLETDYNAMICS_PointTopointConstraint_H

#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletDynamicsConstraint.h"

namespace OgreBulletDynamics
{
    // PointTopointConstraint  class
    class CORE_EXPORT PointToPointConstraint : public TypedConstraint
    {
    public:
	    PointToPointConstraint(RigidBody *body, const Ogre::Vector3 &pivot);
	    virtual ~PointToPointConstraint();

        inline btPoint2PointConstraint * getBulletPoint2PointConstraint () const;

        void setTau (float tau);
        void setDamping (float damping);

        float getTau () const;
        float getDamping () const;

        void	setPivotA(const Ogre::Vector3& pivotA);
        void	setPivotB(const Ogre::Vector3& pivotB);

    };

    inline btPoint2PointConstraint * PointToPointConstraint::getBulletPoint2PointConstraint () const 
    {
        return static_cast <btPoint2PointConstraint *> (mConstraint);
    }
}
#endif //_OGREBULLETDYNAMICS_PointTopointConstraint_H

