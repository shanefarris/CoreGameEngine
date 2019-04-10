// This is not using the scene node, instead you need to attach it to the bone on the tip of the weapon

#ifndef __CPARTICLEEFFECT_MUZZLE1_H__
#define __CPARTICLEEFFECT_MUZZLE1_H__

#include "Defines.h"
#include "CParticleEffect.h"

namespace Core
{
	namespace Plugin
	{
		class CParticleEffect_Muzzle1 : public Core::Effects::CParticleEffect
		{
		public:
			CParticleEffect_Muzzle1();
			~CParticleEffect_Muzzle1();

			void StartTimer();

		protected:
			void ResetTimer();

			BillboardSet* m_BillboardSet;
		};

	}
}

#endif // __CPARTICLEEFFECT_MUZZLE1_H__