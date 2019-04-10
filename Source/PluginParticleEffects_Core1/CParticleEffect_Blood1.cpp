// DECLDIR will perform an export for us
#define DLL_EXPORT

#include "CParticleEffect_Blood1.h"
#include "CGameManager.h"

#include "OgreSceneNode.h"
#include "OgreParticleSystem.h"
#include "OgreStringConverter.h"
#include "OgreSceneManager.h"

using namespace Core;
using namespace Core::Plugin;
using namespace Core::Effects;

CParticleEffect_Blood1::CParticleEffect_Blood1()
{
	LabelName = "BLOOD1";

	//Creates the particle system.
	String count = StringConverter::toString(m_DynamicEffects.size());
	String ParticleName = String("ParticleEffect_Blood1_") + count;
	m_ParticleSystem = CGameManager::Instance()->GetSceneManager()->createParticleSystem(ParticleName, "blood1");

	//Not using world coordinates.
	m_ParticleSystem->setKeepParticlesInLocalSpace(true);
	m_ParticleSystem->setVisible(false);

	//Attach it to a node.
	m_SceneNode = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode(ParticleName + String("_Node"));
	m_SceneNode->attachObject(m_ParticleSystem);

	m_TimerReset = 200.00;
}

CParticleEffect_Blood1::~CParticleEffect_Blood1()
{
}

void CParticleEffect_Blood1::StartTimer()
{
	//Clear all existing particles
	m_ParticleSystem->clear();

	//Starts emitting
	m_ParticleSystem->setEmitting(true);
	m_ParticleSystem->setVisible(true);
	m_Timer += 0.001f;
}

void CParticleEffect_Blood1::ResetTimer() 
{ 
	//Stops emitting particles
	m_ParticleSystem->setEmitting(false);
}
