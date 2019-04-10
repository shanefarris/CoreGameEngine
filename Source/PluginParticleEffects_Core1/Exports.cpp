#define DLL_EXPORT

#include "Exports.h"
#include "Plugins/IParticleFactory.h"
#include "Factories.h"

namespace Core
{
namespace Plugin
{
	CParticleFactory_Blood1* Blood1 = nullptr;
	CParticleFactory_Muzzle1* Muzzle1 = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IParticleFactory*>& list)
		{
			Blood1 = new CParticleFactory_Blood1();
			if(Blood1)
				list.push_back(Blood1);

			Muzzle1 = new CParticleFactory_Muzzle1();
			if(Muzzle1)
				list.push_back(Muzzle1);

		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_PARTICLE;
		}
	}

}
}