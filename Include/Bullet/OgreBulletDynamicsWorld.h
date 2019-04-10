#ifndef _OGREBULLETDYNAMICS_DynamicWorld_H
#define _OGREBULLETDYNAMICS_DynamicWorld_H

#include "OgreBulletDynamicsPreRequisites.h"
#include "OgreBulletCollisionsWorld.h"
#include "Debug/OgreBulletCollisionsDebugDrawer.h"

namespace OgreBulletDynamics
{
    // basic rigid body class
    class CORE_EXPORT DynamicsWorld : public OgreBulletCollisions::CollisionsWorld
    {
    public:
        DynamicsWorld(SceneManager *mgr, const AxisAlignedBox &bounds, const reVector3Df &gravity, bool init = true);

	    ~DynamicsWorld();

        template <class BTDNYWORLDCLASS> void createBtDynamicsWorld(BTDNYWORLDCLASS *&createdWorld)
        {
			createdWorld = new BTDNYWORLDCLASS(mDispatcher, mBroadphase, mConstraintsolver, &mDefaultCollisionConfiguration);
            mWorld = createdWorld;
        }

        void stepSimulation(const Real elapsedTime, int maxSubSteps = 1, const Real fixedTimestep = 1./60.);
        void addRigidBody (RigidBody *rb, short collisionGroup, short collisionMask);
        inline btDynamicsWorld * getBulletDynamicsWorld() const {return static_cast<btDynamicsWorld *> (mWorld);};
        void removeConstraint(TypedConstraint *constraint);
        void addConstraint(TypedConstraint *constraint);
        bool isConstraintRegistered(TypedConstraint *constraint) const;
        void addVehicle(RaycastVehicle *v);

    private:
        btConstraintSolver                                *mConstraintsolver;
		std::deque <TypedConstraint *>                    mConstraints;
		std::deque <ActionInterface *>                    mActionInterface;
    };
}
#endif //_OGREBULLETDYNAMICS_DynamicWorld_H

