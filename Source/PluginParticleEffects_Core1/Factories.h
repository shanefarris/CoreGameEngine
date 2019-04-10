#ifndef __CPARTICLEEFFECT_FACTORIES_H__
#define __CPARTICLEEFFECT_FACTORIES_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/IParticleFactory.h"
#include "CParticleEffect.h"

namespace Core
{
	namespace Plugin
	{
		class CParticleFactory_Blood1 : public Core::Plugin::IParticleFactory
		{
		public:
			CParticleFactory_Blood1();
			~CParticleFactory_Blood1();

			Core::Effects::CParticleEffect* GetParticle();
		};

		class CParticleFactory_Muzzle1 : public Core::Plugin::IParticleFactory
		{
		public:
			CParticleFactory_Muzzle1();
			~CParticleFactory_Muzzle1();

			Core::Effects::CParticleEffect* GetParticle();
		};

	}
}

#endif // __CPARTICLEEFFECT_FACTORIES_H__