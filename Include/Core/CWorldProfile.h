#ifndef __CWORLDPROFILE_H__
#define __CWORLDPROFILE_H__

#include "Defines.h"
#include "OgreAxisAlignedBox.h"

namespace Core
{
namespace Physics
{
	class CWorldProfile
	{
	public:
		CWorldProfile()
			: LinearDamping(0.0f),
			  AngularDamping(0.0f),
			  MaxAngularSpeed(0.0f),
			  ContactCorrectionVelocity(0.0f),
			  ContactSurfaceLayer(0.0f)
		{
			Gravity = Vector3(0.0f, -9.81f, 0.0f);
			Bounds = AxisAlignedBox(Vector3(-10000.0f, -10000.0f, -10000.0f), Vector3(10000.0f,  10000.0f,  10000.0f));
		}

		f32				LinearDamping;
		f32				AngularDamping;
		f32				MaxAngularSpeed;
		f32				ContactCorrectionVelocity;
		f32				ContactSurfaceLayer;
		Vector3			Gravity;
		AxisAlignedBox	Bounds;
	};
}
}

#endif // __CWORLDPROFILE_H__