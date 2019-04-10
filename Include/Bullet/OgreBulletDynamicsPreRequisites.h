#ifndef _OGREBULLETDYNAMICS_PREREQUISITES_H
#define _OGREBULLETDYNAMICS_PREREQUISITES_H

#include "btBulletCollisionCommon.h"
#include "btBulletDynamicsCommon.h"

#include "Defines.h"
#include "OgreBulletCollisions.h"

namespace OgreBulletDynamics
{
    class RigidBody;
    class PhysicState;
    class DynamicsWorld;

	class ActionInterface;

    class TypedConstraint;
    class HingeConstraint;
    class SixDofConstraint;
    class PointToPointConstraint;
	class ConeTwistConstraint;

    class WheeledRigidBody;
    class VehicleRayCaster;
    class VehicleTuning;
    class RaycastVehicle;
    class WheelInfo;

	class RagDoll;
}

#endif //_OGREBULLETDYNAMICS_PREREQUISITES_H