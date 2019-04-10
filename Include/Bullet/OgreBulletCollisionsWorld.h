#ifndef _OGREBULLETCOLLISIONS_CollisionWorld_H
#define _OGREBULLETCOLLISIONS_CollisionWorld_H

#include "OgreBulletCollisionsPreRequisites.h"

namespace OgreBulletCollisions
{
    // basic CollisionWorld
    class CORE_EXPORT CollisionsWorld 
    {
    public:
        CollisionsWorld(SceneManager *scn, const AxisAlignedBox &bounds, bool init = true, bool set32bitsAxisSweep = true);
	    virtual ~CollisionsWorld();

        void addObject(Object *obj, int filterGrp = 1, short int collisionFilter = -1);
		bool removeObject(Object *obj);	// Returns false if obj was not found.
        void discreteCollide();

        bool isObjectregistered(Object *) const;
        Object *findObject(SceneNode *node) const;
        Object *findObject(btCollisionObject *object) const;

        bool getShowDebugContactPoints() const { return mShowDebugContactPoints; }
        void setShowDebugContactPoints(bool show);
        bool getShowDebugShapes() const { return mShowDebugShapes; }
        void setShowDebugShapes(bool val);

		DebugDrawer *getDebugDrawer(){return mDebugDrawer;};
		void setDebugDrawer(DebugDrawer *debugdrawer);

		DebugLines *getDebugContactPoints(){return mDebugContactPoints;};
		void setDebugContactPoints(DebugLines *debugcontacts);


        SceneManager *getSceneManager() const {return mScnMgr;}
        btCollisionWorld *getBulletCollisionWorld() const {return mWorld;}

        void launchRay (CollisionRayResultCallback &ray, short int collisionFilterMask = -1);

    protected:
        btCollisionWorld*          mWorld;
        btCollisionDispatcher*     mDispatcher;

		btBroadphaseInterface*	   mBroadphase;

        AxisAlignedBox       mBounds;

		btDefaultCollisionConfiguration	mDefaultCollisionConfiguration;

        std::deque<Object *>        mObjects;

        bool                        mShowDebugShapes;
        bool                        mShowDebugContactPoints;
        DebugLines *                mDebugContactPoints;

        SceneManager *        mScnMgr;
		OgreBulletCollisions::DebugDrawer *mDebugDrawer;
    };
}
#endif //_OGREBULLETCOLLISIONS_CollisionWorld_H

