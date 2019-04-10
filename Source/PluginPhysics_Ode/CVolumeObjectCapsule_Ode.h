// Interface for any object in a scene that needs a specific event triggered when its collision shape is penetrated.

#ifndef __CVOLUMEOBJECTCAPSULE_ODE_H__
#define __CVOLUMEOBJECTCAPSULE_ODE_H__

#include "CVolumeObject.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsStrategy_Ode.h"
#include "CPhysicsProfile.h"

namespace Core
{
namespace Physics
{
	class CVolumeObjectCapsule_Ode : public CVolumeObject
	{
		friend IPhysicsStrategy;

	public:
		CVolumeObjectCapsule_Ode(VolumePackage* Package) : CVolumeObject(Package)
		{
			if(!Package)
				return;

		}

		~CVolumeObjectCapsule_Ode() {}

		void onVolumeEvent()
		{

		}
		
		void SetPosition(const Vector3& Position)
		{
		}
		
		void RemoveVolume()
		{
		}
	};
}
}

#endif // __CVOLUMEOBJECTCAPSULE_ODE_H__