#define DLL_EXPORT

#include "Exports.h"
#include "CGuiStrategy_Gui3D.h"
#include "Plugins/IGuiStrategyFactory.h"

namespace Core
{
namespace Plugin
{
	Core::GUI::CGuiStrategyFactory_Gui3D*	GuiStrategyFactory_Gui3D = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IGuiStrategyFactory*>& list)
		{
			GuiStrategyFactory_Gui3D = new Core::GUI::CGuiStrategyFactory_Gui3D();

			if(GuiStrategyFactory_Gui3D)
				list.push_back(GuiStrategyFactory_Gui3D);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_GUISTRATEGY;
		}
	}

}
}