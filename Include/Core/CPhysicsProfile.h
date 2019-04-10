/*
 *  Three types of settings: basic, disabled, damping.  Using three boolean values, you can check to see if any of those setting types have been changed.
 */

#ifndef __CPHYSICS_PROFILE_H__
#define __CPHYSICS_PROFILE_H__

#include "Defines.h"
#include "OgreVector3.h"

namespace Core
{	
namespace Physics
{
	enum E_BODY_TYPE;
	enum E_PHYSICS_SHAPE;
	
	class CORE_EXPORT CPhysicsProfile
	{
	public:
		CPhysicsProfile();

		// Get methods
		inline E_PHYSICS_SHAPE  GetShape();
		inline E_BODY_TYPE		GetBodyType();
		inline f32				GetFriction();
		inline f32				GetMass();
		inline f32				GetDensity();
		inline f32				GetRadius();
		inline Vector3			GetSize();
		inline Vector3			GetDirection();
		inline Vector3			GetLinearVelocity();
		inline Vector3			GetAngularVelocity();
		inline Vector3			GetPositionOffset();
		inline f32				GetRestitution();
		inline f32				GetAutoDisableLinearThreshold();
		inline f32				GetAutoDisableAngularThreshold();
		inline f32				GetAutoDisableTime();
		inline u32				GetAutoDisableSteps();
		inline f32				GetLinearDamping();
		inline f32				GetAngularDamping();
		inline f32				GetLinearDampingThreshold();
		inline f32				GetAngularDampingThreshold();
		inline f32				GetMaxAngularSpeed();
		inline void				GetForce(Vector3& Force);
		inline void				GetForceAtPosition(Vector3& Force, Vector3& Position);
		inline void				GetRelativeForce(Vector3& Force);
		inline void				GetTorque(Vector3& Torque);
		inline void				GetRelativeTorque(Vector3& Torque);
		inline bool				GetIsStatic();

		// Set methods
		inline void SetShape(E_PHYSICS_SHAPE Shape);
		inline void	SetBodyType(E_BODY_TYPE BodyType);
		inline void	SetFriction(const f32& Friction);
		inline void SetMass(const f32& Mass);
		inline void SetDensity(const f32& Density);
		inline void SetRadius(const f32& Radius);
		inline void SetSize(const Vector3& Size);
		inline void	SetDirection(const Vector3& Direction);
		inline void SetLinearVelocity(const Vector3& LinearVelocity);
		inline void SetAngularVelocity(const Vector3& AngularVelocity);
		inline void SetPositionOffset(const Vector3& Position);
		inline void SetRestitution(const f32& Restitution);
		inline void SetAutoDisableLinearThreshold(const f32& Threshold);
		inline void SetAutoDisableAngularThreshold(const f32& Threshold);
		inline void SetAutoDisableTime(const f32& Time);
		inline void SetAutoDisableSteps(const u32& Steps);
		inline void SetLinearDamping(const f32& LinearDamping);
		inline void SetAngularDamping(const f32& AngularDamping);
		inline void SetLinearDampingThreshold(const f32& Threshold);
		inline void SetAngularDampingThreshold(const f32 Threshold);
		inline void SetMaxAngularSpeed(const f32& Speed);
		inline void SetForce(const Vector3& Force);
		inline void SetForceAtPosition(const Vector3& Force, const Vector3 Position);
		inline void SetRelativeForce(const Vector3& Force);
		inline void SetTorque(const Vector3& Torque);
		inline void SetRelativeTorque(const Vector3& Torque);
		inline void SetIsStatic(bool IsStatic);

		// Settings type
		inline bool IsBasicDirty();
		inline bool IsDisabledDirty();
		inline bool IsDampingDirty();
		inline bool IsDynamicDirty();
		inline void ResetDirty();
		
	private:
		E_PHYSICS_SHAPE m_Shape;
		E_BODY_TYPE		m_BodyType;
		f32				m_Friction;
		f32				m_Mass;
		f32				m_Density;			// Not used in every strategy, in PhysX this will error, in ODE it is required
		f32				m_Radius;			// Used for spheres, capsules, etc
		Vector3			m_Size;				// Y axis is used for a single f32 size, example capsule or cylinder
		Vector3			m_Direction;		// Used to face shapes like cylinders and capsules
		Vector3			m_LinearVelocity;
		Vector3			m_AngularVelocity;
		Vector3			m_PositionOffset;	// The position on the mesh
		void*			m_PhysicsBody;		// Used for custom data for any strategy used.
		bool			m_IsStatic;			// Does the object move (default is false).

		// Values tested for Ode, can be used with other engines but haven't yet
		f32	m_Restitution;					// Not used very often
		f32	m_AutoDisableLinearThreshold;	// Auto Disable Linear Threshold
		f32	m_AutoDisableAngularThreshold;	// Auto Disable Angular Threshold (zero to disable consideration)
		f32 m_AutoDisableTime;			    //  the amount of simulation time that a body must be idle before it is automatically disabled
		u32	m_AutoDisableSteps;				// Set and get the number of simulation steps that a body must be idle before it is automatically disabled
		f32 m_LinearDamping;
		f32 m_AngularDamping;
		f32 m_LinearDampingThreshold;
		f32 m_AngularDampingThreshold;
		f32 m_MaxAngularSpeed;				// Limit the maximum angular speed

		// Dynamice values
		Vector3		m_Force;			// Add force in a direction
		Vector3		m_ForceAtPosition;	// A force at a specific position
		Vector3		m_RelativeForce;	// Add relative force in a direction
		Vector3		m_PositionForce;	// Position of the force
		Vector3		m_Torque;			// Add torque in a direction
		Vector3		m_RelativeTorque;

		// Settings type
		bool m_IsBasicDirty;				// Any basic physics settings changed
		bool m_IsDisabledDirty;				// Any disabled settings changed
		bool m_IsDampingDirty;				// Any damping settings changed
		bool m_IsDynamicDirty;				// Any dynamic settings (attributes that will change often)
	};
}
}

#endif // __CPHYSICS_PROFILE_H__

/*
 * ODE:
 * Damping serves two purposes: reduce simulation instability, and to allow the bodies to come to rest (and possibly auto-disabling them).
 * Bodies are constructed using the world's current damping parameters. Setting the scales to 0 disables the damping.
 * Here is how it is done: after every time step linear and angular velocities are tested against the corresponding thresholds. 
 * If they are above, they are multiplied by (1 - scale). So a negative scale value will actually increase the speed, 
 * and values greater than one will make the object oscillate every step; both can make the simulation unstable.
 * To disable damping just set the damping scale to zero.
 */