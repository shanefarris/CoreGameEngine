#ifndef _OGREBULLETCOLLISIONS_BoxShape_H
#define _OGREBULLETCOLLISIONS_BoxShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic BoxShape
    class CORE_EXPORT BoxCollisionShape : public CollisionShape
    {
    public:
        BoxCollisionShape(const Ogre::Vector3  &boxBounds);
	    virtual ~BoxCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_BoxShape_H

