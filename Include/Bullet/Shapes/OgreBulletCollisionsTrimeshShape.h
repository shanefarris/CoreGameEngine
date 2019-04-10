#ifndef _OGREBULLETCOLLISIONS_TrimeshShape_H
#define _OGREBULLETCOLLISIONS_TrimeshShape_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
    // -------------------------------------------------------------------------
    // basic TrimeshShape
    class CORE_EXPORT TriangleMeshCollisionShape : public CollisionShape
    {
	public:
		TriangleMeshCollisionShape(Ogre::Vector3 *_vertices, unsigned int _vertex_count, unsigned int *_indices, unsigned int_index_count, bool use32bitsIndices = true);
	    virtual ~TriangleMeshCollisionShape();

		bool drawWireFrame(DebugLines *wire, 
			const Ogre::Vector3 &pos = Ogre::Vector3::ZERO, 
			const Ogre::Quaternion &quat= Ogre::Quaternion::IDENTITY) const;

    private:
        btTriangleMesh*         mTriMesh;
    };
}
#endif //_OGREBULLETCOLLISIONS_TrimeshShape_H

