#define DLL_EXPORT

#include "CMission_Core1.h"
#include "CMission_Core1Acheivment3.h"
#include "IMission.h"

using namespace Core;
using namespace Core::Plugin;

namespace Core
{
namespace Plugin
{
	CMissionFactory_Core1*			    MissionFactory_Core1 = nullptr;
	CMissionFactory_Core1_Acheivment3*  MissionFactory_Core1_Acheivment3 = nullptr;
	extern "C"
	{
		DECLDIR void GetFactories(Vector<Core::Plugin::IMissionFactory*>& list)
		{
			MissionFactory_Core1 = new CMissionFactory_Core1();
			if(MissionFactory_Core1)
				list.push_back(MissionFactory_Core1);

			MissionFactory_Core1_Acheivment3 = new CMissionFactory_Core1_Acheivment3();
			if(MissionFactory_Core1_Acheivment3)
				list.push_back(MissionFactory_Core1_Acheivment3);
		}

		DECLDIR Core::Plugin::E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_MISSION;
		}
	}
}
}