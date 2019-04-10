#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/IPostEffectFactory.h"
#include "Factories.h"

namespace Core
{
namespace Plugin
{
	CPostEffectFactory_Bloom*		Bloom = nullptr;
	CPostEffectFactory_Hdr*			Hdr = nullptr;
	CPostEffectFactory_MotionBlur*	MotionBlur = nullptr;
	CPostEffectFactory_SSAO*		Ssao = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IPostEffectFactory*>& list)
		{
			Bloom = new CPostEffectFactory_Bloom();
			if(Bloom)
				list.push_back(Bloom);

			Hdr = new CPostEffectFactory_Hdr();
			if(Hdr)
				list.push_back(Hdr);

			MotionBlur = new CPostEffectFactory_MotionBlur();
			if(MotionBlur)
				list.push_back(MotionBlur);

			Ssao = new CPostEffectFactory_SSAO();
			if(Ssao)
				list.push_back(Ssao);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_POSTEFFECT;
		}
	}

}
}