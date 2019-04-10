#define DLL_EXPORT

#include "Exports.h"
#include "CGuiStrategy_MyGui.h"
#include "Plugins/IGuiStrategyFactory.h"

namespace Core
{
namespace Plugin
{
	Core::GUI::CGuiStrategyFactory_MyGui*	GuiStrategyFactory_MyGui = nullptr;

	extern "C"
	{
		DECLDIR void GetFactories(Vector<IGuiStrategyFactory*>& list)
		{
			GuiStrategyFactory_MyGui = new Core::GUI::CGuiStrategyFactory_MyGui();

			if(GuiStrategyFactory_MyGui)
				list.push_back(GuiStrategyFactory_MyGui);
		}

		DECLDIR E_PLUGIN GetPluginType(void)
		{
			return Core::Plugin::EP_GUISTRATEGY;
		}
	}

}
}