#ifndef __CCAMERA_CHASE_SPACESHIP_H__
#define __CCAMERA_CHASE_SPACESHIP_H__

#include "Defines.h"
#include "ICamera.h"

namespace Core
{
	class CCameraChaseSpaceShip : public ICamera
	{
	public:
		CCameraChaseSpaceShip(const char* Name);

		void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);
		void Update(const f32& elapsedTime);
	};
}

#endif // __CCAMERA_CHASE_SPACESHIP_H__
