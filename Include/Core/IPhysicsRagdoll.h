#ifndef __IPHYSICSRAGDOLL_H__
#define __IPHYSICSRAGDOLL_H__

#include "defines.h"
#include "CRagdollBoneInformation.h"

namespace Core
{
	class CProjectile;

namespace Physics
{
	class IPhysicsRagdoll
	{
	protected:
		CRagdollBoneInformation boneInformation;
		SceneManager*			sceneManager;
		Skeleton*				skeleton;
		Entity*					entity;	
		
	public:
		IPhysicsRagdoll() : entity(nullptr), skeleton(nullptr), isActive(false) { }
		virtual ~IPhysicsRagdoll() { }
		
		virtual bool Pick(CProjectile* Projectile) = 0;
		virtual void TakePhysicalControl() = 0;

		virtual void Update(const f32& elapsedTime) = 0;
		
		Entity* GetEntity() { return entity; }

		bool isActive;			// Is the ragdoll being updates now
	};
	
}
}

#endif // __IPHYSICSRAGDOLL_H__