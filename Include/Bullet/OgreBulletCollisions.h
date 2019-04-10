#ifndef __OGREBULLETCOLLISIONS_H__
#define __OGREBULLETCOLLISIONS_H__

#include "OgreBulletCollisionsPreRequisites.h"

//#ifdef _PRECOMP

    #include "Utils/OgreBulletConverter.h"

	//Debug Helpers
	#include "Debug/OgreBulletCollisionsDebugLines.h"
	#include "Debug/OgreBulletCollisionsDebugShape.h"
	#include "Debug/OgreBulletCollisionsDebugDrawer.h"
	#include "Debug/OgreBulletCollisionsDebugContact.h"

    //Shapes
    #include "OgreBulletCollisionsShape.h"
    #include "Shapes/OgreBulletCollisionsBoxShape.h"
    #include "Shapes/OgreBulletCollisionsConeShape.h"
    #include "Shapes/OgreBulletCollisionsSphereShape.h"
    #include "Shapes/OgreBulletCollisionsCylinderShape.h"
	#include "Shapes/OgreBulletCollisionsTriangleShape.h"
	#include "Shapes/OgreBulletCollisionsTerrainShape.h"
	#include "Shapes/OgreBulletCollisionsCylinderShape.h"
	#include "Shapes/OgreBulletCollisionsCapsuleShape.h"
    #include "Shapes/OgreBulletCollisionsStaticPlaneShape.h"
    #include "Shapes/OgreBulletCollisionsCompoundShape.h"
    #include "Shapes/OgreBulletCollisionsMultiSphereShape.h"
    #include "Shapes/OgreBulletCollisionsConvexHullShape.h"
    #include "Shapes/OgreBulletCollisionsMinkowskiSumShape.h"
	#include "Shapes/OgreBulletCollisionsTrimeshShape.h"
	#include "Shapes/OgreBulletCollisionsGImpactShape.h"

    //Utils
    #include "Utils/OgreBulletCollisionsMeshToShapeConverter.h"

    // Ray
    //#include "OgreBulletCollisionsConvexCast.h"

    // Core Collisions
    #include "OgreBulletCollisionsObject.h"
    #include "OgreBulletCollisionsObjectState.h"
    #include "OgreBulletCollisionsWorld.h"
    #include "OgreBulletCollisionsRay.h"

    #include "OgreString.h"
    #include "OgreFontManager.h"

    #include "BulletCollision/CollisionShapes/btMinkowskiSumShape.h"
    #include "BulletCollision/CollisionShapes/btTriangleShape.h"


//#endif //_PRECOMP

#endif //__OGREBULLETCOLLISIONS_H__

