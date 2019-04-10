#include "CEffectsManager.h"
#include "CCameraManager.h"
#include "CPluginManager.h"
#include "CGameManager.h"
#include "CPostEffect.h"
#include "CParticleEffect.h"
#include "CDeferredShading.h"
#include "CGameObject.h"
#include "IO/CoreLogging.h"

#include "Plugins\IParticleFactory.h"
#include "Plugins\IPostEffectFactory.h"

using namespace Core;
using namespace Core::Plugin;
using namespace Core::Effects;

CEffectsManager* CEffectsManager::PostEffectsManager = nullptr;

CEffectsManager* CEffectsManager::Instance()
{
	if(PostEffectsManager == nullptr)
		PostEffectsManager = new CEffectsManager();
	return PostEffectsManager;
}

CEffectsManager::CEffectsManager() : m_CameraManager(0), m_Camera(0), m_Viewport(0)
{
	Init();
	m_SceneManager = CGameManager::Instance()->GetSceneManager();
}

CEffectsManager::~CEffectsManager()
{
	try
	{
		// Remove all post effects
		for(auto it = m_PostEffects.begin(); it != m_PostEffects.end(); it++)
		{
			if((*it).second)
				CORE_DELETE((*it).second);
		}

		// Remove all particles
		for(auto it = m_Particles.begin(); it != m_Particles.end(); it++)
			CORE_DELETE((*it));

		m_Camera = nullptr;
		m_Viewport = nullptr;
		m_CameraManager = nullptr;
		m_SceneManager = nullptr;
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CEffectManager()");
	}
}

void CEffectsManager::ReInit()
{
	// This needs to be called when using a new camera
	Init();
}

void CEffectsManager::Init()
{
	m_CameraManager = CCameraManager::Instance();
	m_Camera = m_CameraManager->GetCamera();
	m_Viewport = m_CameraManager->GetViewport();

	if(!m_Camera || !m_Viewport)
	{
		CORE_ERR("Camera and viewport required for the effects manager in CEffectsManager::Init()");
		return;
	}

	// Basically getting a copy of the plugin list, except in a map using the lable name as the key for lookups
	CORE_LOG("*** Registering particles ***");
	Vector<IParticleFactory*> particles = CPluginManager::Instance()->GetParticleFactories();
	for(u32 i = 0; i < particles.size(); i++)
	{
		if(m_ParticleTemplate.find(particles[i]->LabelName) == m_ParticleTemplate.end())
			m_ParticleTemplate[particles[i]->LabelName] = particles[i];
	}

	CORE_LOG("*** Registering post effects ***");
	Vector<IPostEffectFactory*> postEffects = CPluginManager::Instance()->GetPostEffectFactories();
	for(u32 i = 0; i < postEffects.size(); i++)
	{
		if(m_PostEffects.find(postEffects[i]->LabelName) == m_PostEffects.end())
		{
			CPostEffect* pe = postEffects[i]->GetPostEffect();
			if(pe)
			{
				pe->RegisterPostEffect();
				m_PostEffects[postEffects[i]->LabelName] = pe;
			}
		}
	}
}

void CEffectsManager::TogglePostEffects(const char* EffectName, bool flag)
{
	String name = EffectName;
	auto it = m_PostEffects.find(name);
	if(it != m_PostEffects.end())
	{
		(*it).second->SetEnabled(flag);
	}
}

CPostEffect* CEffectsManager::GetPostEffect(const char* EffectName)
{
	String name = EffectName;
	auto it = m_PostEffects.find(name);
	if(it != m_PostEffects.end())
	{
		return (*it).second;
	}

	return nullptr;
}

CParticleEffect* CEffectsManager::CreateParticle(const char* EffectName)
{
	auto it = m_ParticleTemplate.find(String(EffectName));
	if(it != m_ParticleTemplate.end())
	{
		CParticleEffect* pe = (it)->second->GetParticle();
		m_Particles.push_back(pe);
		return pe;
	}
	return nullptr;
}

CParticleEffect* CEffectsManager::GetParticle(const char* EffectName)
{
	String name = EffectName;
	for(auto it = m_Particles.cbegin(); it != m_Particles.cend(); it++)
	{
		if(name == (*it)->ParticleName)
			return (*it);
	}

	return nullptr;
}

void CEffectsManager::Update(const f32& elapsedTime)
{
	// Update particles
	CParticleEffect::UpdateAll(elapsedTime);
}
