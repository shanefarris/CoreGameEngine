#ifndef __EXPORTS_HPP__
#define __EXPORTS_HPP__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
namespace Plugin
{
	class IEntityEffectFactory;
	enum E_PLUGIN;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IEntityEffectFactory*>& list);
		DECLDIR E_PLUGIN GetPluginType(void);
	}

}
}

#endif //__EXPORTS_HPP__