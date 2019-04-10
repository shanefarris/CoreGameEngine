#ifndef _OGREBULLETCOLLISIONS_StaticPlaneShape_H
#define _OGREBULLETCOLLISIONS_StaticPlaneShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic BoxShape
    class CORE_EXPORT StaticPlaneCollisionShape : public CollisionShape
    {
    public:
        StaticPlaneCollisionShape(const Ogre::Vector3 normal, Ogre::Real distance);
	    virtual ~StaticPlaneCollisionShape();

        bool drawWireFrame(DebugLines *wire, 
            const Ogre::Vector3 &pos = Ogre::Vector3::ZERO, 
            const Ogre::Quaternion &quat= Ogre::Quaternion::IDENTITY) const;
    };
}
#endif //_OGREBULLETCOLLISIONS_StaticPlaneShape_H

