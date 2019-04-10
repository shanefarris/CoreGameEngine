#ifndef _OGREBULLETCOLLISIONS_MinkowskiSumShape_H
#define _OGREBULLETCOLLISIONS_MinkowskiSumShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic MinkowskiSumShape
    class CORE_EXPORT MinkowskiSumCollisionShape : public CollisionShape
    {
    public:
	    MinkowskiSumCollisionShape(CollisionShape* shapeA, CollisionShape* shapeB);
	    virtual ~MinkowskiSumCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_MinkowskiSumShape_H

