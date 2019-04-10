#ifndef __PLUGIN_IMISSIONFACTORY_H__
#define __PLUGIN_IMISSIONFACTORY_H__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	namespace Mission
	{
		class IMission;
	}

namespace Plugin
{
	class IMissionFactory
	{
	public:
		virtual Core::Mission::IMission* GetMission() = 0;

		String LabelName;
	};
}
}

#endif // __PLUGIN_IMISSIONFACTORY_H__