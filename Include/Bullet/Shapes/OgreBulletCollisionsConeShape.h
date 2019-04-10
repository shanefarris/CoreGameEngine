#ifndef _OGREBULLETCOLLISIONS_ConeShape_H
#define _OGREBULLETCOLLISIONS_ConeShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic ConeShape
    class CORE_EXPORT ConeCollisionShape : public CollisionShape
    {
    public:
        ConeCollisionShape(Ogre::Real radius, Ogre::Real height, const Ogre::Vector3 &axe);
	    virtual ~ConeCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_ConeShape_H

