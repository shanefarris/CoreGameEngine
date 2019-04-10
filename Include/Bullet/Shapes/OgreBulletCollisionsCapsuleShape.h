#ifndef _OGREBULLETCOLLISIONS_CapsuleShape_H
#define _OGREBULLETCOLLISIONS_CapsuleShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic CapsuleShape
    class CORE_EXPORT CapsuleCollisionShape : public CollisionShape
    {
    public:
        CapsuleCollisionShape(const Ogre::Real radius, const Ogre::Real height, const Ogre::Vector3 &axe);
	    virtual ~CapsuleCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_CapsuleShape_H

