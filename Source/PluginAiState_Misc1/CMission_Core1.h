// Kill 5 enemy with any weapon
#ifndef __CMISSION_CORE1_H__
#define __CMISSION_CORE1_H__

#include "Defines.h"
#include "PluginTypes.h"
#include "IMissionFactory.h"
#include "IMission.h"

namespace Core
{
	namespace Plugin
	{
		class CMission_Core1 : public Core::Mission::IMission
		{
		public:
			CMission_Core1();
			~CMission_Core1();

			void OnStart();
			void OnFail();
			void OnComplete();
		};

		class CMissionFactory_Core1 : public IMissionFactory
		{
		public:
			CMissionFactory_Core1();
			~CMissionFactory_Core1();

			Core::Mission::IMission* GetMission();
		};

	}
}

#endif // __CMISSION_CORE1_H__