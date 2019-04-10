#ifndef __CPOSTEFFECT_FACTORIES_H__
#define __CPOSTEFFECT_FACTORIES_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/IPostEffectFactory.h"
#include "CParticleEffect.h"

namespace Core
{
	namespace Plugin
	{
		class CPostEffectFactory_Bloom : public Core::Plugin::IPostEffectFactory
		{
		public:
			CPostEffectFactory_Bloom();
			~CPostEffectFactory_Bloom();

			Core::Effects::CPostEffect* GetPostEffect();
		};

		class CPostEffectFactory_Hdr : public Core::Plugin::IPostEffectFactory
		{
		public:
			CPostEffectFactory_Hdr();
			~CPostEffectFactory_Hdr();

			Core::Effects::CPostEffect* GetPostEffect();
		};

		class CPostEffectFactory_MotionBlur : public Core::Plugin::IPostEffectFactory
		{
		public:
			CPostEffectFactory_MotionBlur();
			~CPostEffectFactory_MotionBlur();

			Core::Effects::CPostEffect* GetPostEffect();
		};

		class CPostEffectFactory_SSAO : public Core::Plugin::IPostEffectFactory
		{
		public:
			CPostEffectFactory_SSAO();
			~CPostEffectFactory_SSAO();

			Core::Effects::CPostEffect* GetPostEffect();
		};

	}
}

#endif // __CPOSTEFFECT_FACTORIES_H__