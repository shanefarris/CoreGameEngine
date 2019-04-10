#ifndef __CPOSTEFFECT_SSAO_H__
#define __CPOSTEFFECT_SSAO_H__

#include "Defines.h"
#include "CPostEffect.h"
#include "OgreCompositorInstance.h"

namespace Core
{
	namespace Plugin
	{
		class CPostEffect_SSAO : public Core::Effects::CPostEffect, public CompositorInstance::Listener
		{
		public:
			CPostEffect_SSAO();

			void RegisterPostEffect();
			void notifyMaterialRender(u32 pass_id, MaterialPtr& mat);
		};
	}
}

#endif // __CPOSTEFFECT_SSAO_H__
