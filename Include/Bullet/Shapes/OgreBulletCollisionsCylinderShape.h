#ifndef _OGREBULLETCOLLISIONS_CylinderShape_H
#define _OGREBULLETCOLLISIONS_CylinderShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic CylinderShape
    class CORE_EXPORT CylinderCollisionShape : public CollisionShape
    {
    public:
        CylinderCollisionShape(const Ogre::Vector3  &halfExtents, const Ogre::Vector3 &axe);
	    virtual ~CylinderCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_CylinderShape_H

