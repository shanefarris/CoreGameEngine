#include "CParticleEffect.h"

#include "OgreSceneNode.h"

using namespace Core;
using namespace Core::Effects;

Vector<CParticleEffect*> CParticleEffect::m_DynamicEffects;

CParticleEffect::CParticleEffect()
{
	m_Timer = 0.0;
	m_TimerReset = 0.0;
	m_SceneNode = nullptr;
}

void CParticleEffect::Update(const f32& timeSinceLastFrame)
{
	//Updates the timer
	m_Timer += timeSinceLastFrame;

	//If timer > the reset timer, call ResetTimer and reset the timer.
	if (m_Timer >= m_TimerReset)
	{
		ResetTimer();
		m_Timer = 0.0;
	}
}

void CParticleEffect::UpdateAll(const f32& timeSinceLastFrame)
{
	//Updates all effects in the static vector m_DynamicEffects
	for (auto it = m_DynamicEffects.cbegin(); it!= m_DynamicEffects.cend(); it++)
	{
		if ((*it)->m_Timer > 0)
			(*it)->Update(timeSinceLastFrame);
	}
}

void CParticleEffect::AddDynamicEffect(CParticleEffect* e)
{
	//Add to the dynamic effects
	m_DynamicEffects.push_back(e);
}

void CParticleEffect::SetPosition(Vector3& Position)
{
	m_SceneNode->setPosition(Position);
}
		
void CParticleEffect::SetPosition(const f32& X, const f32& Y, const f32& Z)
{
	m_SceneNode->setPosition(X, Y, Z);
}