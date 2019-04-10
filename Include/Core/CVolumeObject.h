// Interface for any object in a scene that needs a specific event triggered when its collision shape is penetrated.

#ifndef __CVOLUMEOBJECT_H__
#define __CVOLUMEOBJECT_H__

#include "IPhysicsStrategy.h"

namespace Core
{
namespace Physics
{
	class CPhysicsProfile;
	
	class CVolumeObject
	{
	public:
		CVolumeObject(VolumePackage* Package)
		{
			OnEnter = nullptr;
			OnExit = nullptr;
			m_Package = Package;
		}

		typedef void (*OnEnterFunc)(const CPhysicsProfile*);
		typedef void (*OnExitFunc)(const CPhysicsProfile*);
		
		void SetEnterFunc(OnEnterFunc* Func) { OnEnter = Func; }
		void SetExitFunc(OnExitFunc* Func) { OnExit = Func; }
		
		virtual void SetPosition(const Vector3& Position) = 0;
		
		virtual void RemoveVolume() = 0;

	protected:
		OnEnterFunc*	OnEnter;
		OnExitFunc*		OnExit;
		
		VolumePackage*	m_Package;
	};
}
}

#endif // __CVOLUMEOBJECT_H__