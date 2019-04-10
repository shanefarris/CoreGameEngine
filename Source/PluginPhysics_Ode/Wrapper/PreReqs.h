#ifndef _OGREODEPREREQS_H_
#define _OGREODEPREREQS_H_

#include "Core/Defines.h"
#include "ode/ode.h"

namespace Ode 
{
	typedef dTriIndex TriangleIndex;


	class World;
	class Space;

	class Body;
	class Mass;

	class JointGroup;
	class Joint;

    class Geometry;
    typedef std::vector<Geometry*>   GeometryList;
    typedef std::vector<Geometry*> GeometryArray;

    class RayGeometry;
    class CylinderGeometry;
    class SphereGeometry;
    class InfinitePlaneGeometry;
    class TransformGeometry;
	
	class TriangleMeshData;
	class TriangleMeshDataPtr;
	class TriangleMeshGeometry;
	class BoxGeometry;
    class CapsuleGeometry;


	class Contact;

    class StepListener;

    class StepHandler;
    class BasicStepper;
    class QuickStepper;

    class StepMode;
    class BasicStepMode;
    class QuickStepMode;

	class CollisionListener;
	class CollisionCallback;
	class MaintainedItem;


	class EntityInformer;
    typedef std::vector<Vector3> Vector3Array;
	typedef std::map<unsigned char,Vector3Array* > BoneMapping;
	typedef std::pair<unsigned short,Vector3Array* > BoneMappingKey;

	typedef size_t MaterialID;
	typedef std::map<MaterialID,Contact*> MaterialMap;
    typedef std::pair<MaterialID,MaterialMap* > MaterialMapPair;

    class DebugObject;
    class DebugContact;
    class DebugContactText;
    class DebugNormal;
	
	class TriangleMeshDataManager;
	class TriangleMeshData;
}


#endif

