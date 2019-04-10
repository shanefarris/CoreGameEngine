// DECLDIR will perform an export for us
#define DLL_EXPORT

#include "CParticleEffect_Muzzle1.h"
#include "CGameManager.h"

#include "OgreSceneNode.h"
#include "OgreBillboard.h"
#include "OgreBillboardSet.h"
#include "OgreStringConverter.h"
#include "OgreSceneManager.h"

using namespace Core;
using namespace Core::Plugin;
using namespace Core::Effects;

CParticleEffect_Muzzle1::CParticleEffect_Muzzle1()
{
	LabelName = "MUZZLE1";

	//Creates the particle system.
	String count = StringConverter::toString(m_DynamicEffects.size());
	String ParticleName = String("ParticleEffect_Muzzle1_") + count;

	//Creates the needed billboardset and billboards.
	//Billboard = Sprite = 2D image that is always oriented towards the viewer.
	m_BillboardSet = CGameManager::Instance()->GetSceneManager()->createBillboardSet(ParticleName);
	Billboard* m_Billboard = m_BillboardSet->createBillboard(Vector3(0, 0, 0));
	m_Billboard->setDimensions(1.0, 1.0);
	m_BillboardSet->setMaterialName("muzze");
	m_BillboardSet->setVisible(false);

	m_TimerReset = 200.00;
}

CParticleEffect_Muzzle1::~CParticleEffect_Muzzle1()
{
}

void CParticleEffect_Muzzle1::StartTimer()
{
	m_BillboardSet->setVisible(true);
	m_Timer += 0.001f;
}

void CParticleEffect_Muzzle1::ResetTimer() 
{ 
	//Stops emitting particles
	m_BillboardSet->setVisible(false);
}
