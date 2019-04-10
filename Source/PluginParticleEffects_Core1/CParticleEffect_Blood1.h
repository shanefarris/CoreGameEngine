#ifndef __CPARTICLEEFFECT_BLOOD1_H__
#define __CPARTICLEEFFECT_BLOOD1_H__

#include "Defines.h"
#include "CParticleEffect.h"

namespace Ogre
{
	class ParticleSystem;
}

namespace Core
{
	namespace Plugin
	{
		class CParticleEffect_Blood1 : public Core::Effects::CParticleEffect
		{
		public:
			CParticleEffect_Blood1();
			~CParticleEffect_Blood1();

			void StartTimer();

		protected:
			void ResetTimer();

			ParticleSystem*	 m_ParticleSystem;
		};

	}
}

#endif // __CPARTICLEEFFECT_BLOOD1_H__