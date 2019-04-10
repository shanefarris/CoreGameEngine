#ifndef __PLUGIN_ICAMERAFACTORY_H__
#define __PLUGIN_ICAMERAFACTORY_H__

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
		class CEntityEffect;
	}

	namespace Plugin
	{
		class IEntityEffectFactory
		{
		public:
			virtual Core::Effects::CEntityEffect* GetEffect() = 0;

			String LabelName;
		};
	}
}

#endif // __PLUGIN_ICAMERAFACTORY_H__