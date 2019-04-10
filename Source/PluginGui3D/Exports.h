#ifndef __EXPORTS_HPP__
#define __EXPORTS_HPP__

#include "Plugins/IGuiStrategyFactory.h"
#include "Plugins/PluginTypes.h"

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
		DECLDIR void GetFactories(Vector<IGuiStrategyFactory*>& list);
		DECLDIR E_PLUGIN GetPluginType(void);
	}

}
}

#endif //__EXPORTS_HPP__