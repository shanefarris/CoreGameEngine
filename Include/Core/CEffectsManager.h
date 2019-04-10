// Effects consist of particle effects, and post effects, this manages both of them.  The particles could have many instances of the same particle running, so they are
// loaded on demand.  The post effects can only have one instances, they are registered with the compositor manager, and enabled on demand.

#ifndef __CPOSTEFFECTSMANAGER_H__
#define __CPOSTEFFECTSMANAGER_H__

#include "Defines.h"

namespace Core
{
	class CGameObject;
	class CDummyGameObject;
	class CCameraManager;
	
	namespace Plugin
	{
		class IParticleFactory;
	}

	namespace Effects
	{
		class CParticleEffect;
		class CPostEffect;

		class CORE_EXPORT CEffectsManager
		{
		public:
			static CEffectsManager* Instance();

			~CEffectsManager();
			
			// Post effects
			void TogglePostEffects(const char* EffectName, bool flag);
			inline CPostEffect*	GetPostEffect(const char* EffectName);

			// Particle effects
			CParticleEffect* CreateParticle(const char* EffectName);
			CParticleEffect* GetParticle(const char* EffectName);

			// General
			void Update(const f32& elapsedTime);
			void ReInit();

		private:
			CEffectsManager();
			void Init();

			static CEffectsManager*	PostEffectsManager;

			Camera*			m_Camera;
			Viewport*		m_Viewport;
			CCameraManager* m_CameraManager;
			SceneManager*	m_SceneManager;

			// Post effects
			Map<String, CPostEffect*> m_PostEffects;

			// Particle effects
			Vector<CParticleEffect*>					 m_Particles;			// Active particles created from the template
			Map<String, Core::Plugin::IParticleFactory*> m_ParticleTemplate;	// Particles that can be created
			Map<CGameObject*, CDummyGameObject*>		 m_MaterialEffects;		// CGameObject is the origian obj, and the dummy is the material added to it
		};
	}
}

#endif // __CPOSTEFFECTSMANAGER_H__
