#ifndef __CPOSTEFFECT_HDR_H__
#define __CPOSTEFFECT_HDR_H__

#include "Defines.h"
#include "CPostEffect.h"
#include "OgreCompositorInstance.h"

namespace Core
{
	namespace Plugin
	{
		class CPostEffect_Hdr : public Core::Effects::CPostEffect, public CompositorInstance::Listener
		{
		public:
			CPostEffect_Hdr();

			void RegisterPostEffect();

			void notifyViewportSize(int width, int height);
			void notifyCompositor(CompositorInstance* instance);
			void notifyMaterialSetup(u32 pass_id, MaterialPtr& mat);
			void notifyMaterialRender(u32 pass_id, MaterialPtr& mat);

		protected:
			int mVpWidth, mVpHeight;
			int mBloomSize;

			// Array params - have to pack in groups of 4 since this is how Cg generates them
			// also prevents dependent texture read problems if ops don't require swizzle
			float mBloomTexWeights[15][4];
			float mBloomTexOffsetsHorz[15][4];
			float mBloomTexOffsetsVert[15][4];
		};
	}
}

#endif // __CPOSTEFFECT_HDR_H__