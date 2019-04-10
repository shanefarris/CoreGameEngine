#include "CPhysicsProfile.h"
#include "PhysicsStructures.h"

using namespace Core;
using namespace Core::Physics;

CPhysicsProfile::CPhysicsProfile() 
	: m_BodyType (Physics::NONE), 
	m_Friction(0.0f), 
	m_Mass(0.0f), 
	m_Density(0.0f), 
	m_Radius(DEFAULT_PROFILE_RADIUS), 
	m_Size(DEFAULT_PROFILE_SIZE),
	m_Direction(Vector3::UNIT_Y),
	m_LinearVelocity(INVALID_POS),
	m_AngularVelocity(INVALID_POS),
	m_PositionOffset(INVALID_POS),
	m_PhysicsBody(nullptr),
	m_IsStatic(false),
	m_Restitution(0.0f),
	m_AutoDisableLinearThreshold(0.0f),
	m_AutoDisableAngularThreshold(0.0f),
	m_AutoDisableTime(10.0f),
	m_AutoDisableSteps(0),
	m_LinearDamping(0.0f),
	m_AngularDamping(0.0f),
	m_LinearDampingThreshold(0.0f),
	m_AngularDampingThreshold(0.0f),
	m_MaxAngularSpeed(0.0f),
	m_Force(INVALID_POS),			
	m_ForceAtPosition(INVALID_POS),
	m_RelativeForce(INVALID_POS),	
	m_PositionForce(INVALID_POS),	
	m_Torque(INVALID_POS),			
	m_RelativeTorque(INVALID_POS)
{
	ResetDirty();
}

E_PHYSICS_SHAPE CPhysicsProfile::GetShape() 
{ 
	return m_Shape; 
}

E_BODY_TYPE	CPhysicsProfile::GetBodyType() 
{ 
	return m_BodyType; 
}

f32	CPhysicsProfile::GetFriction() 
{ 
	return m_Friction;
}

f32	CPhysicsProfile::GetMass() 
{ 
	return m_Mass; 
}

f32	CPhysicsProfile::GetDensity()
{ 
	return m_Density; 
}

f32	CPhysicsProfile::GetRadius()
{ 
	return m_Radius;
}

Vector3	CPhysicsProfile::GetSize()
{ 
	return m_Size;
}

Vector3	CPhysicsProfile::GetDirection() 
{ 
	return m_Direction;
}

Vector3	CPhysicsProfile::GetLinearVelocity() 
{ 
	return m_LinearVelocity; 
}

Vector3	CPhysicsProfile::GetAngularVelocity() 
{ 
	return m_AngularVelocity; 
}

Vector3	CPhysicsProfile::GetPositionOffset() 
{ 
	return m_PositionOffset; 
}

f32	CPhysicsProfile::GetRestitution() 
{ 
	return m_Restitution; 
}

f32	CPhysicsProfile::GetAutoDisableLinearThreshold() 
{ 
	return m_AutoDisableLinearThreshold; 
}

f32	CPhysicsProfile::GetAutoDisableAngularThreshold() 
{ 
	return m_AutoDisableAngularThreshold; 
}

f32	CPhysicsProfile::GetAutoDisableTime() 
{ 
	return m_AutoDisableTime; 
}

u32	CPhysicsProfile::GetAutoDisableSteps() 
{ 
	return m_AutoDisableSteps; 
}

f32	CPhysicsProfile::GetLinearDamping() 
{ 
	return m_LinearDamping; 
}

f32	CPhysicsProfile::GetAngularDamping() 
{ 
	return m_AngularDamping; 
}

f32	CPhysicsProfile::GetLinearDampingThreshold() 
{ 
	return m_LinearDampingThreshold; 
}

f32	CPhysicsProfile::GetAngularDampingThreshold() 
{ 
	return m_AngularDampingThreshold; 
}

f32	CPhysicsProfile::GetMaxAngularSpeed() 
{ 
	return m_MaxAngularSpeed; 
}

void CPhysicsProfile::GetForce(Vector3& Force)
{
	Force = m_Force;
}

void CPhysicsProfile::GetForceAtPosition(Vector3& Force, Vector3& Position)
{
	Force = m_ForceAtPosition;
	Position = m_PositionForce;
}

void CPhysicsProfile::GetRelativeForce(Vector3& Force)
{
	m_RelativeForce = m_Force;
}

void CPhysicsProfile::GetTorque(Vector3& Torque)
{
	Torque = m_Torque;
}

void CPhysicsProfile::GetRelativeTorque(Vector3& Torque)
{
	Torque = m_RelativeTorque;
}

bool CPhysicsProfile::GetIsStatic()
{
	return m_IsStatic;
}

void CPhysicsProfile::SetShape(E_PHYSICS_SHAPE Shape)
{ 
	m_Shape = Shape; 
	m_IsBasicDirty = true; 
}

void CPhysicsProfile::SetBodyType(E_BODY_TYPE BodyType)
{ 
	m_BodyType = BodyType; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetFriction(const f32& Friction)
{ 
	m_Friction = Friction; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetMass(const f32& Mass) 
{ 
	m_Mass = Mass; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetDensity(const f32& Density)
{ 
	m_Density = Density; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetRadius(const f32& Radius)
{ 
	m_Radius = Radius; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetSize(const Vector3& Size)
{ 
	m_Size = Size; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetDirection(const Vector3& Direction)
{ 
	m_Direction = Direction; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetLinearVelocity(const Vector3& LinearVelocity)
{ 
	m_LinearVelocity = LinearVelocity; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetAngularVelocity(const Vector3& AngularVelocity)
{ 
	m_AngularVelocity = AngularVelocity; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetPositionOffset(const Vector3& Position)
{ 
	m_PositionOffset = Position; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetRestitution(const f32& Restitution)
{ 
	m_Restitution = Restitution; 
	m_IsBasicDirty = true;
}

void CPhysicsProfile::SetAutoDisableLinearThreshold(const f32& Threshold)
{ 
	m_AutoDisableLinearThreshold = Threshold; 
	m_IsDisabledDirty = true;
}

void CPhysicsProfile::SetAutoDisableAngularThreshold(const f32& Threshold)
{ 
	m_AutoDisableAngularThreshold = Threshold; 
	m_IsDisabledDirty = true;
}

void CPhysicsProfile::SetAutoDisableTime(const f32& Time)
{ 
	m_AutoDisableTime = Time; 
	m_IsDisabledDirty = true;
}

void CPhysicsProfile::SetAutoDisableSteps(const u32& Steps)
{ 
	m_AutoDisableSteps = Steps; 
	m_IsDisabledDirty = true;
}

void CPhysicsProfile::SetLinearDamping(const f32& LinearDamping)
{ 
	m_LinearDamping = LinearDamping; 
	m_IsDampingDirty = true; 
}

void CPhysicsProfile::SetAngularDamping(const f32& AngularDamping)
{ 
	m_AngularDamping = AngularDamping; 
	m_IsDampingDirty = true;
}

void CPhysicsProfile::SetLinearDampingThreshold(const f32& Threshold) 
{ 
	m_LinearDampingThreshold = Threshold; 
	m_IsDampingDirty = true; 
}

void CPhysicsProfile::SetAngularDampingThreshold(const f32 Threshold) 
{ 
	m_AngularDampingThreshold = Threshold; 
	m_IsDampingDirty = true; 
}

void CPhysicsProfile::SetMaxAngularSpeed(const f32& Speed)
{ 
	m_MaxAngularSpeed = Speed; 
	m_IsDampingDirty = true;
}

void CPhysicsProfile::SetForce(const Vector3& Force)
{
	m_ForceAtPosition = Force;
	m_IsDynamicDirty = true;
}

void CPhysicsProfile::SetForceAtPosition(const Vector3& Force, const Vector3 Position)
{
	m_ForceAtPosition = Force;
	m_PositionForce = Position;
	m_IsDynamicDirty = true;
}

void CPhysicsProfile::SetRelativeForce(const Vector3& Force)
{
	m_RelativeForce = Force;
	m_IsDynamicDirty = true;
}

void CPhysicsProfile::SetTorque(const Vector3& Torque)
{
	m_Torque = Torque;
	m_IsDynamicDirty = true;
}

void CPhysicsProfile::SetRelativeTorque(const Vector3& Torque)
{
	m_RelativeTorque = Torque;
	m_IsDynamicDirty = true;
}

void CPhysicsProfile::SetIsStatic(bool IsStatic)
{
	m_IsStatic = IsStatic;
}

bool CPhysicsProfile::IsBasicDirty() 
{ 
	return m_IsBasicDirty;
}

bool CPhysicsProfile::IsDisabledDirty()
{
	return m_IsDisabledDirty;
}

bool CPhysicsProfile::IsDampingDirty()
{ 
	return m_IsDampingDirty;
}

bool CPhysicsProfile::IsDynamicDirty()
{
	return m_IsDynamicDirty;
}

void CPhysicsProfile::ResetDirty()
{
	m_IsBasicDirty = false;
	m_IsDisabledDirty = false;
	m_IsDampingDirty = false;
	m_IsDynamicDirty = false;
}