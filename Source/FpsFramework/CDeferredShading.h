#if 0
#ifndef __CDEFERREDSHADING_H__
#define __CDEFERREDSHADING_H__

#include "Defines.h"
#include "CPostEffect.h"

namespace Core
{
namespace Effects
{
	class CMiniLight;
	class CRayLight;
	class CMaterialGenerator;

	class CDeferredShading: public CPostEffect, public CompositorInstance::Listener
	{
	public:
		CDeferredShading();
		~CDeferredShading();

		enum DSMode
		{
			DSM_SINGLEPASS	= 0,					// Single pass + two lights
			DSM_MULTIPASS	= 1,					// Multi pass
			DSM_SHOWCOLOUR	= 2,					// Show diffuse (for debugging)
			DSM_SHOWNORMALS = 3,					// Show normals (for debugging)
			DSM_SHOWDSP		= 4,					// Show depth and specular channel (for debugging)
			DSM_COUNT		= 5
		};

		void SetMode(DSMode mode);					// Set rendering mode (one of DSMode)
		CMiniLight* CreateMLight();					// Create a new MiniLight 
		CRayLight *CreateRayLight();				// Create a new CRayLight
		void DestroydeferredLight(CMiniLight *m);	// Destroy a MiniLight

		void Update(const Vector3& camPos);		// Update fat (origin) render target

		virtual void notifyMaterialSetup(u32 pass_id, MaterialPtr &mat);

		void RegisterPostEffect();

	protected:
		/// Visibility mask for scene
		static const u32 SceneVisibilityMask = 1 << 0;		//0x00000001;

		/// Visibility mask for post-processing geometry (lights, unlit particles)
		static const u32 PostVisibilityMask = 1 << 1;		//0x00000002;
		static const u32 AlphaVisibilityMask = 1 << 2;		//0x00000003;
		static const u32 EffectVisibilityMask = 1 << 3;		//0x00000004;
		
		SceneManager*		mSceneMgr;
		MultiRenderTarget*	rttTex;							// Fat render target
		CompositorInstance*	mInstance[DSM_COUNT];			// Filters

		DSMode m_CurrentMode;

		std::set<CMiniLight*> m_Lights;
		TexturePtr m_Texture0;
		TexturePtr m_Texture1;
		TexturePtr m_Texture2;
		TexturePtr m_Texture3;

		CMaterialGenerator* m_LightMaterialGenerator;

		void SetupMaterial(const MaterialPtr &mat);
	};
}
}

#endif // __CDEFERREDSHADING_H__

#endif