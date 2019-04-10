#ifndef _OGREBULLETCOLLISIONS_TriangleShape_H
#define _OGREBULLETCOLLISIONS_TriangleShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic TriangleShape
    class CORE_EXPORT TriangleCollisionShape : public CollisionShape
    {
    public:
        TriangleCollisionShape(const Ogre::Vector3 &p1, const Ogre::Vector3 &p2, const Ogre::Vector3 &p3);	
        TriangleCollisionShape( 
            Ogre::Real p1X, Ogre::Real p1Y, Ogre::Real p1Z, 
            Ogre::Real p2X, Ogre::Real p2Y, Ogre::Real p2Z,  
            Ogre::Real p3X, Ogre::Real p3Y, Ogre::Real p3Z);

	    virtual ~TriangleCollisionShape();

    };
}
#endif //_OGREBULLETCOLLISIONS_TriangleShape_H

