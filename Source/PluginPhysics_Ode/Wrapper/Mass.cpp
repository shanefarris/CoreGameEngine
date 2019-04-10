#include "PreReqs.h"
#include "Mass.h"

#include "OgreMatrix3.h"
#include "OgreQuaternion.h"

using namespace Ode;
using namespace Ogre;

Mass::Mass()
{
	dMassSetZero(&_mass); 
}

Mass::Mass(const f32& mass, const Vector3& center_of_gravity, const Matrix3& intertia_matrix)
{
	dMassSetParameters
	(
		&_mass,
		(dReal)mass,
		(dReal)center_of_gravity.x,(dReal)center_of_gravity.y,(dReal)center_of_gravity.z,
		(dReal)intertia_matrix[0][0],(dReal)intertia_matrix[1][1],(dReal)intertia_matrix[2][2],
		(dReal)intertia_matrix[0][1],(dReal)intertia_matrix[0][2],(dReal)intertia_matrix[1][2]
	); 
}

Mass::~Mass()
{
}

void Mass::adjust(const f32& mass)
{
	dMassAdjust(&_mass,(dReal)mass); 
}

void Mass::translate(const Vector3& offset)
{
	dMassTranslate(&_mass,offset.x,offset.y,offset.z); 
}

void Mass::rotate(const Ogre::Quaternion& orientation)
{
	Matrix3 m;
	orientation.ToRotationMatrix(m);
	dMatrix3 r;

	r[0] = m[0][0];
	r[1] = m[0][1];
	r[2] = m[0][2];

	r[3] = m[1][0];
	r[4] = m[1][1];
	r[5] = m[1][2];

	r[6] = m[2][0];
	r[7] = m[2][1];
	r[8] = m[2][2];

	r[9] = 0.0;
	r[10] = 0.0;
	r[11] = 0.0;

	dMassRotate(&_mass,r); 
}

const f32 Mass::getMassValue() const
{
	return (f32)_mass.mass;
}

Vector3 Mass::getCenterOfGravity() const
{
	// not sure why its a dVector4 in dMass and not a dVector3
	// and I think ode requires the center of mass to be the bodies position so this 
	// would always return Vector3::ZERO
	return Vector3((f32)_mass.c[0], (f32)_mass.c[1], (f32)_mass.c[2]);
}



Ogre::Matrix3 Mass::getLocalInertiaTensor() const
{
	return Ogre::Matrix3(   
		(f32)_mass.I[0], (f32)_mass.I[1], (f32)_mass.I[2],
		(f32)_mass.I[4], (f32)_mass.I[5], (f32)_mass.I[6],
		(f32)_mass.I[8], (f32)_mass.I[9], (f32)_mass.I[10]);
}
void Mass::add(const Mass& other)
{
	dMassAdd(&_mass,&(other._mass)); 
}

const dMass* Mass::getMassPtr() const
{
	return &_mass;
}

SphereMass::SphereMass():Mass()
{
}

SphereMass::SphereMass(const f32& mass, const f32& radius)
{
	dMassSetSphereTotal(&_mass,(dReal)mass,(dReal)radius); 
}

SphereMass::~SphereMass()
{
}

void SphereMass::setDensity(const f32& density, const f32& radius)
{
	dMassSetSphere(&_mass,(dReal)density,(dReal)radius); 
}

CapsuleMass::CapsuleMass() : Mass()
{
}

CapsuleMass::CapsuleMass(const f32& mass, const f32& radius, const Vector3& direction, const f32& length)
{
	int dir = (direction == Vector3::UNIT_X) ? 1 : (direction == Vector3::UNIT_Y) ? 2 : (direction == Vector3::UNIT_Z) ? 3 : 0;
	assert(dir);
	dMassSetCappedCylinderTotal(&_mass, (dReal)mass, dir, (dReal)radius, (dReal)length); 
}

CapsuleMass::~CapsuleMass()
{
}

void CapsuleMass::setDensity(const f32& density, const f32& radius,const Vector3& direction, const f32& length)
{
	int dir = (direction == Vector3::UNIT_X) ? 1 : (direction == Vector3::UNIT_Y) ? 2 : (direction == Vector3::UNIT_Z) ? 3 : 0;
	assert(dir && "Invalid direction specified for CapsuleMass");
	dMassSetCappedCylinder(&_mass, (dReal)density, dir, (dReal)radius, (dReal)length); 
}

CylinderMass::CylinderMass():Mass()
{
}

CylinderMass::CylinderMass(const f32& mass,const Vector3& direction, const f32& radius, const f32& length)
{
	int dir = (direction == Vector3::UNIT_X) ? 1 : (direction == Vector3::UNIT_Y) ? 2 : (direction == Vector3::UNIT_Z) ? 3 : 0;
	assert(dir);
	dMassSetCylinderTotal(&_mass, (dReal)mass, dir, (dReal)radius, (dReal)length); 
}

CylinderMass::~CylinderMass()
{
}

void CylinderMass::setDensity(const f32& density, const Vector3& direction, const f32& radius, const f32& length)
{
	int dir = (direction == Vector3::UNIT_X) ? 1 : (direction == Vector3::UNIT_Y) ? 2 : (direction == Vector3::UNIT_Z) ? 3 : 0;
	assert(dir);
	dMassSetCylinder(&_mass, (dReal)density, dir, (dReal)radius, (dReal)length); 
}

BoxMass::BoxMass():Mass()
{
}

BoxMass::BoxMass(const f32& mass, const Vector3& size)
{
	dMassSetBoxTotal(&_mass, (dReal)mass, (dReal)size.x, (dReal)size.y, (dReal)size.z);
}

BoxMass::~BoxMass()
{
}

void BoxMass::setDensity(const f32& density, const Vector3& size)
{
	dMassSetBox(&_mass, (dReal)density, (dReal)size.x, (dReal)size.y, (dReal)size.z); 
}
