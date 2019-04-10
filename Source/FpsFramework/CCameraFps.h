#if 1
#ifndef __CCAMERA_FPS_H__
#define __CCAMERA_FPS_H__

#include "Defines.h"
#include "ICamera.h"

namespace Ogre
{
	class Vector3;
}

namespace Core
{
	class CCameraFps : public ICamera
	{
	public:
		CCameraFps(const char* Name, SceneNode* Parent);

		void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);
		void Update(const f32& elapsedTime);
	};
}

#endif // __CCAMERA_FPS_H__

#endif