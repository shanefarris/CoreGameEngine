#ifndef __CGUIMANAGER_H__
#define __CGUIMANAGER_H__

#include "Defines.h"

namespace MyGUI 
{ 
	class OgrePlatform; 
}

namespace Gorilla
{
	class Silverback;
}

namespace Core
{
	namespace Plugin
	{
		class IGuiStrategyFactory;
	}

	namespace GUI
	{
		class IGuiStrategy;

		enum E_GUI_STRATEGY
		{
			EGS_MYGUI = 0,
			EGS_CEGUI,
			EGS_QUICKGUI,
			EGS_GUI3D,
		};

		enum E_GORILLA_ATLAS
		{
			EGA_DEFAULT = 0,
		};

		class CORE_EXPORT CGuiManager
		{
		private:
			static CGuiManager*					 GuiManager;
			IGuiStrategy*						 m_DefaultStrategy;
			Map<String, IGuiStrategy*>			 m_Strategies;
			Map<E_GORILLA_ATLAS, String>		 m_GorillaAtlases;
			Vector<Plugin::IGuiStrategyFactory*> m_Factories;

		protected:
			CGuiManager();

		public:
			static CGuiManager* Instance();
			~CGuiManager();

			IGuiStrategy*	CreateStrategy(const char* Name);
			IGuiStrategy*	GetStrategy();
			IGuiStrategy*	GetStrategy(const char* Name);
			void			SetDefaultStrategy(const char* Name);
			void			DeleteStrategy(const char* Name);

			// Gorilla
			Gorilla::Silverback* GetSilverback();
			void LoadAtlas(E_GORILLA_ATLAS Atlas);
		};
	}
}
#endif // __CGUIMANAGER_H__
