#ifndef __CPHYSICSRAGDOLL_ODE_H__
#define __CPHYSICSRAGDOLL_ODE_H__

#include "IPhysicsRagdoll.h"

namespace Ode
{
	class Ragdoll;
	class World;
	class DotLoader;
}

namespace Core
{
	class CPlayer;

namespace Physics
{
	class CPhysicsRagdoll_Ode : public IPhysicsRagdoll
	{	
	private:
		int				counter;
		Ode::World*		m_World;
		static u32		ragdoll_count;
		Ode::Ragdoll*	m_Ragdoll;

	public:
		CPhysicsRagdoll_Ode(CPlayer* Player, Ode::World* World, Ode::DotLoader* DotLoader, const CRagdollBoneInformation& RagdollBoneInformation);
		~CPhysicsRagdoll_Ode();
		
		bool Pick(CProjectile* Projectile);
		void TakePhysicalControl();

		void Update(const f32& elapsedTime);

		Ode::Ragdoll* GetOdeRagdoll() { return m_Ragdoll; }
	};
	
}
}

#endif // __CPHYSICSRAGDOLL_ODE_H__