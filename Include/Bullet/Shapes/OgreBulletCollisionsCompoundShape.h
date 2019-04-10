#ifndef _OGREBULLETCOLLISIONS_CompoundCollisionShape_H
#define _OGREBULLETCOLLISIONS_CompoundCollisionShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic CompoundShape
    class CORE_EXPORT CompoundCollisionShape : public CollisionShape
    {
    public:
		CompoundCollisionShape();
		CompoundCollisionShape(btCompoundShape *);
	    virtual ~CompoundCollisionShape();

        void addChildShape(CollisionShape *shape, 
                            const Ogre::Vector3 &pos = Ogre::Vector3::ZERO, 
                            const Ogre::Quaternion &quat = Ogre::Quaternion::IDENTITY);


        bool drawWireFrame(DebugLines *wire, 
            const Ogre::Vector3 &pos = Ogre::Vector3::ZERO, 
            const Ogre::Quaternion &quat= Ogre::Quaternion::IDENTITY) const;

    protected:
        std::vector<CollisionShape *> mShapes;
    };
}
#endif //_OGREBULLETCOLLISIONS_CompoundCollisionShape_H

