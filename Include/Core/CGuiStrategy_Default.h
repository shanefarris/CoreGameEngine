#ifndef __CGUISTRATEGY_GUI3D_H__
#define __CGUISTRATEGY_GUI3D_H__

#include "Defines.h"
#include "IGuiStrategy.h"

#include "Plugins/IGuiStrategyFactory.h"

#include <Ogre.h>

namespace Gui3D
{
	class Gui3D;
	class Panel;
	class Button;
	class Combobox;
	class Caption;
	class PanelElement;
}

namespace Core
{
	namespace GUI
	{
		enum E_GUI_STRATEGY;

		class CORE_EXPORT CGuiStrategy_Default : public IGuiStrategy, public Ogre::FrameListener
		{
		private:
			Gui3D::Gui3D*					m_Gui3D;
			Map<String, Gui3D::Panel*>		m_Panels;
			Map<String, Gui3D::Caption*>	m_Labels;
			Map<String, Gui3D::Button*>		m_Buttons;
			Map<String, Gui3D::Combobox*>	m_Comboboxes;

			// Events
			bool ButtonPressed(Gui3D::PanelElement* e);
			bool ComboboxPressed(Gui3D::PanelElement* e);

		public:
			CGuiStrategy_Default();
			~CGuiStrategy_Default();

			void Initialize();
			void Shutdown();
			void Activate();
			void Desactivate();

			void SetCursorPosition(float x, float y);
			void LoadLayout(const char* Name);

			// Engine/Input events
			bool FrameStarted(const f32& LastTime);
			bool FrameEnded(const f32& LastTime);
			bool MouseMoved(const CInputMouseEvent &arg);
			bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
			bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);
			bool KeyPressed(const CInputKeyEvent &arg);
			bool KeyReleased(const CInputKeyEvent &arg);

			E_GUI_STRATEGY GetStrategyType();

			// Common control methods
			bool CreateForm(const char* Name, const Vector3& Position, const Vector2& Size);
			bool CreateLabel(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text);
			bool CreateButton(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text);
			bool CreateComboBox(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, Vector<String>& Items, u32 IndexItem);
			void ShowMessageBox(const char* Message, const char* Title);
			bool ShowMessageBoxYesNo(const char* Message, const char* Title);

			// Mouse
			void SetMousePosition(const Vector2& Position);
			Vector2* GetMousePosition();

			bool frameStarted(const Ogre::FrameEvent& evt);

		};
	}
}

#endif //  __CGUISTRATEGY_GUI3D_H__

