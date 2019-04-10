#ifndef _OGREBULLETCOLLISIONS_ConvexHullShape_H
#define _OGREBULLETCOLLISIONS_ConvexHullShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic ConvexHullShape
    class CORE_EXPORT ConvexHullCollisionShape : public CollisionShape
    {
    public:
        ConvexHullCollisionShape(const Ogre::Real* points, int numPoints, int stride);
        ConvexHullCollisionShape();
		ConvexHullCollisionShape(btConvexHullShape *shape);

	    virtual ~ConvexHullCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_ConvexHullShape_H

