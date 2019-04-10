#ifndef __CCAMERAGOD_H__
#define __CCAMERAGOD_H__

#include "Defines.h"
#include "ICamera.h"
#include "OgreMath.h"

namespace Ogre
{
	class Vector3;
}

namespace Core
{
	class CCameraGod : public ICamera
	{
	private:
		Radian		m_RotX;
		Radian		m_RotY;

		f32 MoveScale;
		f32 TimeUntilNextToggle;			// just to stop toggles flipping too fast
		s32 SceneDetailIndex;

	public:
		CCameraGod(const char* Name, SceneNode* Parent);

		void InstantUpdate(const Vector3& cameraPosition, const Vector3& targetPosition);
		void Update(const f32& elapsedTime);
	};
}

#endif // __CCAMERAGOD_H__