#ifndef __PLUGIN_IPOSTEFFECTFACTORY_H__
#define __PLUGIN_IPOSTEFFECTFACTORY_H__

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
		class CPostEffect;
	}

	namespace Plugin
	{
		class IPostEffectFactory
		{
		public:
			virtual Core::Effects::CPostEffect* GetPostEffect() = 0;

			String LabelName;
		};
	}
}

#endif // __PLUGIN_IPOSTEFFECTFACTORY_H__