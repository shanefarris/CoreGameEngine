#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/IEntityEffectFactory.h"
#include "Factories.h"

namespace Core
{
namespace Plugin
{
	CEntityEffectFactor_FlashGlow* FlashGlow = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IEntityEffectFactory*>& list)
		{
			FlashGlow = new CEntityEffectFactor_FlashGlow();
			if(FlashGlow)
				list.push_back(FlashGlow);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_ENTITYEFFECT;
		}
	}

}
}