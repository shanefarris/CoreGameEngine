#ifndef _OGREBULLETCOLLISIONS_PREREQUISITES_H
#define _OGREBULLETCOLLISIONS_PREREQUISITES_H

#include "Defines.h"
#include "btBulletCollisionCommon.h"
#include "BulletCollision/Gimpact/btGImpactShape.h"
#include "BulletCollision/Gimpact/btGImpactCollisionAlgorithm.h"

/* Some <math.h> files do not define M_PI... */
#ifndef M_PI
#define M_PI 3.14159265
#endif

#if _MSC_VER
	#ifdef CORE_DLL
		#define CORE_EXPORT __declspec(dllexport)
	#else
		#define CORE_EXPORT __declspec(dllimport)
	#endif

	// disable: "non dll-interface class used as base for dll-interface class"
	// Happens when deriving from Singleton because bug in compiler ignores
	// template export
	#pragma warning (disable : 4275)

	// disable: "inconsistent dll linkage"
	// Same problem with Singletons
	#pragma warning (disable : 4273)
#endif

namespace OgreBulletCollisions
{
    class BtOgreConverter;
    class OgreBtConverter;

    class CollisionsWorld;

    class CollisionRayResultCallback;
    class CollisionClosestRayResultCallback;

    class DebugLines;

    class DebugDrawer;

    class DebugContact;
    class DebugNormal;
    class DebugContactText;
    
    class DebugCollisionShape;
    class BoxDebugShape;
    class SphereDebugShape;
    class ConeDebugShape;
    class TriangleMeshDebugShape;
    class RayDebugShape;

	class GImpactConcaveShape;
	class HeightmapCollisionShape;
    class CollisionShape;
    class BoxCollisionShape;
    class SphereCollisionShape;
    class CylinderCollisionShape;
	class CapsuleCollisionShape;
    class ConeCollisionShape;

    class CompoundCollisionShape;

    class MultiSphereCollisionShape;
    class MinkowskiSumCollisionShape;

    class ConvexHullCollisionShape;
    class TriangleMeshCollisionShape;

    class Object;

    class ObjectState;

	class CollisionShapebject;

    typedef std::vector<Ogre::Vector3> Vector3Array;
    typedef std::map<unsigned short, Vector3Array* > BoneIndex;
    typedef std::pair<unsigned short, Vector3Array* > BoneKeyIndex;

}

#endif //_OGREBULLETCOLLISIONS_PREREQUISITES_H

