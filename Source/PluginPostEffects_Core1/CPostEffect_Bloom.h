#ifndef __CPOSTEFFECT_BLOOM_H__
#define __CPOSTEFFECT_BLOOM_H__

#include "Defines.h"
#include "CPostEffect.h"

namespace Core
{
	namespace Plugin
	{
		class CPostEffect_Bloom : public Core::Effects::CPostEffect
		{
		public:
			CPostEffect_Bloom();
			~CPostEffect_Bloom();

			void StartTimer();

			void RegisterPostEffect();
		};
	}
}

#endif // __CPOSTEFFECT_BLOOM_H__
