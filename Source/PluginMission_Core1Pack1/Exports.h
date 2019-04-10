#ifndef __EXPORTS_H__
#define __EXPORTS_H__

#include "Defines.h"
#include "PluginTypes.h"
#include "IMissionFactory.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
namespace Plugin
{
	extern "C"
	{
		DECLDIR void GetFactories(Vector<Core::Plugin::IMissionFactory*>& list)
		DECLDIR E_PLUGIN GetPluginType(void);
	}
	}
}
}

#endif // __EXPORTS_H__
