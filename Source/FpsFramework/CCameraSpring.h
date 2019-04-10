#if 1
#ifndef __CCAMERA_SPRING_H__
#define __CCAMERA_SPRING_H__

#include "Defines.h"
#include "ICamera.h"
#include "OgreVector3.h"

namespace Core
{
	class CCameraSpring : public ICamera
	{
	private:
		f32 m_Stiffness;						// Spring Stiffness
		f32 m_Dampening;						// Spring Dampening
		f32 m_Mass;								// Spring Mass

		Vector3 m_Direction;				// Direction of the camera
		Vector3 m_DesiredPosition;			// Position we want to be at, idealy somewhere behind the player e.g.(0,50,-100);
		Vector3 m_Stretch;					// Amount Camera Strecthed
		Vector3 m_Velocity;					// Cameras Velocity
		Vector3 m_Acceleration;				// Cameras Acceleration
		Vector3 m_DampenedVelocity;			// Cameras Velocity after dampening
		Vector3 m_Force;					// Force applied to the camera

	public:
		CCameraSpring(const char* Name, SceneNode* Parent);

		// Settings
		f32 GetMass() { return m_Mass; }
		f32 GetDampening() { return m_Dampening; }
		f32 GetStiffness() { return m_Stiffness; }

		void SetMass(float mass) { m_Mass = mass; }
		void SetDampening(float dampening) { m_Dampening = dampening; }
		void SetStiffness(float stiffness) { m_Stiffness = stiffness; }

		void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);
		void Update(const f32& elapsedTime);
	};
}

#endif // __CCAMERA_SPRING_H__

#endif