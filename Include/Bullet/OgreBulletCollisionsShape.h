#ifndef _OGREBULLETCOLLISIONS_Shape_H
#define _OGREBULLETCOLLISIONS_Shape_H

#include "OgreBulletCollisionsPreRequisites.h"

namespace OgreBulletCollisions
{
	// basic Shape
	class CORE_EXPORT CollisionShape 
    {
    public:
	    CollisionShape();
        virtual ~CollisionShape();
        
        inline btCollisionShape* getBulletShape () { return mShape; };

        virtual bool drawWireFrame(DebugLines *wire, 
            const Ogre::Vector3 &pos = Ogre::Vector3::ZERO, 
            const Ogre::Quaternion &quat= Ogre::Quaternion::IDENTITY) const;

		bool drawConvexWireFrame(DebugLines *wire, const Ogre::Vector3 &pos, const Ogre::Quaternion &quat) const;

    protected:
        btCollisionShape*       mShape;        

    };
}
#endif //_OGREBULLETCOLLISIONS_Shape_H

