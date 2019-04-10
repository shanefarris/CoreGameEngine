#ifndef __CMISSION_CORE1_ACHEIVEMENT3_H__
#define __CMISSION_CORE1_ACHEIVEMENT3_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/IMissionFactory.h"
#include "IMission.h"

namespace Core
{
	namespace Mission
	{
		class CMissionEvent;
	}

	namespace Plugin
	{
		class CMission_Core1Acheivment3 : public Core::Mission::IMission
		{
		public:
			CMission_Core1Acheivment3();
			~CMission_Core1Acheivment3();

			void OnStart();
			void OnFail();
			void OnComplete();
			
			Core::Mission::MISSION_STATUS Update();
			void RegisterEvent(Core::Mission::CMissionEvent* Event);
		};

		class CMissionFactory_Core1_Acheivment3 : public IMissionFactory
		{
		public:
			CMissionFactory_Core1_Acheivment3();
			~CMissionFactory_Core1_Acheivment3();

			Core::Mission::IMission* GetMission();
		};
	}
}

#endif // __CMISSION_CORE1_ACHEIVEMENT3_H__