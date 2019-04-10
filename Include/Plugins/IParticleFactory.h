#ifndef __PLUGIN_IPARTICLEFACTORY_H__
#define __PLUGIN_IPARTICLEFACTORY_H__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	namespace Effects
	{
		class CParticleEffect;
	}

	namespace Plugin
	{
		class IParticleFactory
		{
		public:
			virtual Core::Effects::CParticleEffect* GetParticle() = 0;

			String LabelName;
		};
	}
}

#endif // __PLUGIN_IPARTICLEFACTORY_H__