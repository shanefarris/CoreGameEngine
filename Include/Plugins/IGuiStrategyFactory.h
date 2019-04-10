#ifndef __IGUISTRATEGYFACTORY_H__
#define __IGUISTRATEGYFACTORY_H__

#include "Defines.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	namespace GUI
	{
		class IGuiStrategy;
	}

namespace Plugin
{
	class IGuiStrategyFactory
	{
	public:
		virtual Core::GUI::IGuiStrategy* CreateStrategy() = 0;

		String GuiStrategyType;
	};
}
}

#endif //__IGUISTRATEGYFACTORY_H__