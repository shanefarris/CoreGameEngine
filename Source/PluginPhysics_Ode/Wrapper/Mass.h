#ifndef _OGREODEMASS_H_
#define _OGREODEMASS_H_

#include "PreReqs.h"

namespace Ode 
{
	class Mass
	{
		friend class Body;

	public:
		Mass();
        Mass(const f32& mass, const Vector3& center_of_gravity, const Ogre::Matrix3& intertia_matrix); 
		virtual ~Mass();

		inline Mass(const Mass& other)
		{
			memcpy(&_mass,&(other._mass),sizeof(_mass));
		}

		inline Mass& operator=(const Mass& other)
		{
			memcpy(&_mass,&(other._mass),sizeof(_mass));
			return *this;
		}

		inline Mass& operator=(const dMass* other)
		{
			assert(other);
			memcpy(&_mass,other,sizeof(_mass));
			return *this;
		}

		void adjust(const f32& mass); 
		void translate(const Vector3& offset); 
		void rotate(const Ogre::Quaternion& orientation); 
		void add(const Mass& other); 
		
		// total mass of the rigid body
		const f32 getMassValue() const;
		// center of gravity position in body frame (x,y,z)
		Vector3 getCenterOfGravity() const;
		// 3x3 inertia tensor in body frame, about POR
		Ogre::Matrix3 getLocalInertiaTensor() const; 

	protected:
		const dMass* getMassPtr() const;
		dMass _mass;
	};

	class SphereMass:public Mass
	{
	public:
		SphereMass();
		SphereMass(const f32& mass, const f32& radius);
		~SphereMass();

		void setDensity(const f32& density, const f32& radius);
	};
	
	// To add
	// void dMassSetTrimesh(dMass *, dReal density, dGeomID g)

	class CapsuleMass:public Mass
	{
	public:
		CapsuleMass();
		CapsuleMass(const f32& mass, const f32& radius,const Vector3& direction, const f32& length);
		~CapsuleMass();

		void setDensity(const f32& density, const f32& radius,const Vector3& direction, const f32& length);
	};

	class CylinderMass:public Mass
	{
	public:
		CylinderMass();
		CylinderMass(const f32& mass,const Vector3& direction, const f32& radius, const f32& length);
		~CylinderMass();

		void setDensity(const f32& density,const Vector3& direction, const f32& radius, const f32& length);
	};

	class BoxMass:public Mass
	{
	public:
		BoxMass();
		BoxMass(const f32& mass,const Vector3& size);
		~BoxMass();

		void setDensity(const f32& density,const Vector3& size);
	};
}

#endif
