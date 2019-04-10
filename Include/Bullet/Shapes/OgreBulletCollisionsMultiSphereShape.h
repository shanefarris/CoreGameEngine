#ifndef _OGREBULLETCOLLISIONS_MultiSphereShape_H
#define _OGREBULLETCOLLISIONS_MultiSphereShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic MultiSphereShape
    class CORE_EXPORT MultiSphereCollisionShape : public CollisionShape
    {
    public:
        MultiSphereCollisionShape(
            const Ogre::Vector3& inertiaHalfExtents,
            const Ogre::Vector3* positions,
            const Ogre::Real* radi,
            int numSpheres);
	    virtual ~MultiSphereCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_MultiSphereShape_H

