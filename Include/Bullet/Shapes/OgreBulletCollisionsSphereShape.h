#ifndef _OGREBULLETCOLLISIONS_SphereShape_H
#define _OGREBULLETCOLLISIONS_SphereShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic SphereShape
    class CORE_EXPORT SphereCollisionShape : public CollisionShape
    {
    public:
        SphereCollisionShape(const Ogre::Real  radius);
	    virtual ~SphereCollisionShape();

    private:
    };
}
#endif //_OGREBULLETCOLLISIONS_SphereShape_H

