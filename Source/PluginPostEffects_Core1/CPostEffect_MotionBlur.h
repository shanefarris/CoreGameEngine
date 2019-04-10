#ifndef __CPOSTEFFECT_MOTIONBLUR_H__
#define __CPOSTEFFECT_MOTIONBLUR_H__

#include "Defines.h"
#include "CPostEffect.h"
#include "OgreCompositorInstance.h"

namespace Core
{
	namespace Plugin
	{
		class CPostEffect_MotionBlur : public Core::Effects::CPostEffect, public CompositorInstance::Listener
		{
		public:
			CPostEffect_MotionBlur();
			
			void RegisterPostEffect();
			void notifyMaterialRender(u32 pass_id, MaterialPtr& mat);
		};
	}
}

#endif // __CPOSTEFFECT_MOTIONBLUR_H__
