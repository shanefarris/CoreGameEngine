#ifndef   _OGREBULLETCOLLISIONS_GImpact_Shapes_H
#define   _OGREBULLETCOLLISIONS_GImpact_Shapes_H

#include "OgreBulletCollisionsPreRequisites.h"

#include "BulletCollision/Gimpact/btGImpactShape.h"
#include "BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h"

#include "OgreBulletCollisionsShape.h"

namespace OgreBulletCollisions
{
	class CORE_EXPORT GImpactConcaveShape : public CollisionShape
	{
	public:
		GImpactConcaveShape(Ogre::Vector3 *_vertices, unsigned int _vertex_count, unsigned int *_indices, unsigned int_index_count);
		virtual ~GImpactConcaveShape();

		bool drawWireFrame(DebugLines *wire, 
			const Ogre::Vector3 &pos = Ogre::Vector3::ZERO, 
			const Ogre::Quaternion &quat= Ogre::Quaternion::IDENTITY) const;

	private:
		btTriangleMesh*         mTriMesh;
	};
}
#endif