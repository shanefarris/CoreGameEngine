// TODO: add collision to the camera
#ifndef __CCAMERAFREE_H__
#define __CCAMERAFREE_H__

#include "Defines.h"
#include "ICamera.h"

#include "OgreMath.h"

namespace Ogre
{
	class Vector3;
}

namespace Core
{
	class CCameraFree : public ICamera
	{
	private:
		Radian		m_RotX;
		Radian		m_RotY;

		f32 MoveScale;
		f32 TimeUntilNextToggle;			// just to stop toggles flipping too fast
		s32 SceneDetailIndex;

	public:
		CCameraFree(const char* Name, SceneNode* Parent = nullptr);

		void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);
		void Update(const f32& elapsedTime);
	};
}

#endif // __CCAMERAFREE_H__