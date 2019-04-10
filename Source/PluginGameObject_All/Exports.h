#ifndef __EXPORTS_HPP__
#define __EXPORTS_HPP__

#include "Defines.h"
#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"
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
		DECLDIR void GetFactories(Vector<IGameObjectFactory*>& list);
		DECLDIR E_PLUGIN GetPluginType(void);
	}

}
}

#endif //__EXPORTS_HPP__
