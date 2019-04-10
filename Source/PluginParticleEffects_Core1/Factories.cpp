#define DLL_EXPORT

#include "Factories.h"
#include "CParticleEffect_Blood1.h"
#include "CParticleEffect_Muzzle1.h"

using namespace Core::Plugin;

// CParticleFactory_Blood1
CParticleFactory_Blood1::CParticleFactory_Blood1()
{
	LabelName = "BLOOD1";
}

CParticleFactory_Blood1::~CParticleFactory_Blood1()
{
}

Core::Effects::CParticleEffect* CParticleFactory_Blood1::GetParticle()
{
	return new CParticleEffect_Blood1();
}

// CParticleFactory_Muzzle1
CParticleFactory_Muzzle1::CParticleFactory_Muzzle1()
{
	LabelName = "MUZZLE1";
}

CParticleFactory_Muzzle1::~CParticleFactory_Muzzle1()
{
}

Core::Effects::CParticleEffect* CParticleFactory_Muzzle1::GetParticle()
{
	return new CParticleEffect_Muzzle1();
}
