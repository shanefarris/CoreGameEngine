#ifndef __CENTITYEFFECT_FACTORIES_H__
#define __CENTITYEFFECT_FACTORIES_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/IEntityEffectFactory.h"

namespace Core
{
	namespace Plugin
	{
		class CEntityEffectFactor_FlashGlow : public Core::Plugin::IEntityEffectFactory
		{
		public:
			CEntityEffectFactor_FlashGlow();
			~CEntityEffectFactor_FlashGlow();

			Core::Effects::CEntityEffect* GetEffect();
		};

	}
}

#endif // __CENTITYEFFECT_FACTORIES_H__