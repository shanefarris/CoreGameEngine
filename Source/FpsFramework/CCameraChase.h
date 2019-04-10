#if 1
#ifndef __CCAMERA_CHASE_H__
#define __CCAMERA_CHASE_H__

#include "Defines.h"
#include "ICamera.h"

namespace Ogre
{
	class Vector3;
}

namespace Core
{
	class CCameraChase : public ICamera
	{
	public:
		CCameraChase(const char* Name, SceneNode* Parent);

		void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);
		void Update(const f32& elapsedTime);
	};
}

#endif // __CCAMERA_CHASE_H__

#endif