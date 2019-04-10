#if 0
#include "LocalSpace.h"

using namespace Core;
using namespace Core::AI;

LocalSpace::LocalSpace()
{
    resetLocalSpace ();
};

LocalSpace::LocalSpace (const Vector3& Side, const Vector3& Up, const Vector3& Forward, const Vector3& Position)
    : _side( Side ), _up( Up ), _forward( Forward ), _position( Position ) 
{
}

LocalSpace::LocalSpace (const Vector3& Up, const Vector3& Forward, const Vector3& Position)
    : _side(), _up( Up ), _forward( Forward ), _position( Position )
{
    setUnitSideFromForwardAndUp ();
}

LocalSpace::~LocalSpace() 
{ 
}

void LocalSpace::resetLocalSpace (void)
{
	// ------------------------------------------------------------------------
	// reset transform: set local space to its identity state, equivalent to a
	// 4x4 homogeneous transform like this:
	//
	//     [ X 0 0 0 ]
	//     [ 0 1 0 0 ]
	//     [ 0 0 1 0 ]
	//     [ 0 0 0 1 ]
	//
	// where X is 1 for a left-handed system and -1 for a right-handed system.

	_forward = Vector3::UNIT_Z;
    _side = localRotateForwardToSide (_forward);
	_up = Vector3::UNIT_Y;
	_position = Vector3::ZERO;
};

Vector3 LocalSpace::localizeDirection (const Vector3& globalDirection) const
{
	// transform a direction in global space to its equivalent in local space

    // dot offset with local basis vectors to obtain local coordiantes
    return Vector3 (globalDirection.dotProduct (_side),
                 globalDirection.dotProduct (_up),
                 globalDirection.dotProduct (_forward));
};

Vector3 LocalSpace::localizePosition (const Vector3& globalPosition) const
{
	// transform a point in global space to its equivalent in local space

    // global offset from local origin
    Vector3 globalOffset = globalPosition - _position;

    // dot offset with local basis vectors to obtain local coordiantes
    return localizeDirection (globalOffset);
};

Vector3 LocalSpace::globalizePosition (const Vector3& localPosition) const
{
	// transform a point in local space to its equivalent in global space
    return _position + globalizeDirection (localPosition);
};

Vector3 LocalSpace::globalizeDirection (const Vector3& localDirection) const
{
	// transform a direction in local space to its equivalent in global space
    return ((_side    * localDirection.x) +
            (_up      * localDirection.y) +
            (_forward * localDirection.z));
};

void LocalSpace::setUnitSideFromForwardAndUp (void)
{
	// set "side" basis vector to normalized cross product of forward and up

    // derive new unit side basis vector from forward and up
    if (rightHanded())
        _side = Vec3Utilities::crossProduct (_forward, _up);
    else
        _side = Vec3Utilities::crossProduct (_forward, _up);
    _side = Vec3Utilities::normalise (_side);
}

void LocalSpace::regenerateOrthonormalBasisUF (const Vector3& newUnitForward)
{
	// regenerate the orthonormal basis vectors given a new Forward(which is expected to have unit length)
    _forward = newUnitForward;

    // derive new side basis vector from NEW forward and OLD up
    setUnitSideFromForwardAndUp ();

    // derive new Up basis vector from new Side and new Forward
    // (should have unit length since Side and Forward are
    // perpendicular and unit length)
    if (rightHanded())
        _up = Vec3Utilities::crossProduct (_side, _forward);
    else
        _up = Vec3Utilities::crossProduct (_forward, _side);
}

void LocalSpace::regenerateOrthonormalBasis (const Vector3& newForward)
{
	// for when the new forward is NOT know to have unit length
    regenerateOrthonormalBasisUF (Vec3Utilities::normalise(newForward));
}

void LocalSpace::regenerateOrthonormalBasis (const Vector3& newForward, const Vector3& newUp)
{
	// for supplying both a new forward and and new up
    _up = newUp;
    regenerateOrthonormalBasis (Vec3Utilities::normalise(newForward));
}

Vector3 LocalSpace::localRotateForwardToSide (const Vector3& v) const
{
	// rotate, in the canonical direction, a vector pointing in the "forward" (+Z) direction to the "side" (+/-X) direction
    return Vector3 (rightHanded () ? -v.z : +v.z, v.y, v.x);
}

Vector3 LocalSpace::globalRotateForwardToSide (const Vector3& globalForward) const
{
	// not currently used, just added for completeness
    const Vector3 localForward = localizeDirection (globalForward);
    const Vector3 localSide = localRotateForwardToSide (localForward);
    return globalizeDirection (localSide);
}

#endif