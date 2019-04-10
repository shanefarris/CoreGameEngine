#ifndef _OGREBULLETDYNAMICS_TypedConstraint_H
#define _OGREBULLETDYNAMICS_TypedConstraint_H

#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletCollisionsObject.h"

namespace OgreBulletDynamics
{
    // basic constraint class
    class CORE_EXPORT TypedConstraint
    {
    public:
        TypedConstraint(DynamicsWorld *world);
        TypedConstraint(RigidBody *bodyA);
        TypedConstraint(RigidBody *bodyA, RigidBody *bodyB);

	    virtual ~TypedConstraint();

        inline btTypedConstraint* getBulletTypedConstraint() const { return static_cast<btTypedConstraint*>(mConstraint); };

    protected:
        btTypedConstraint       *mConstraint;
        DynamicsWorld           *mWorld;
        RigidBody               *mBodyA;
        RigidBody               *mBodyB;
	}; 

	// basic constraint action class
	class CORE_EXPORT ActionInterface
	{
	public:
		ActionInterface(DynamicsWorld *world);
		ActionInterface(RigidBody *bodyA);
		ActionInterface(RigidBody *bodyA, RigidBody *bodyB); 

		virtual ~ActionInterface();

		inline btActionInterface* getBulletActionInterface() const {return static_cast <btActionInterface*> (mActionInterface);};

	protected:
		btActionInterface       *mActionInterface;
		DynamicsWorld           *mWorld;
		RigidBody               *mBodyA;
		RigidBody               *mBodyB;
	};
}
#endif //_OGREBULLETDYNAMICS_TypedConstraint_H
