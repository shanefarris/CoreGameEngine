#ifndef __CGUISTRATEGY_MYGUI_H__
#define __CGUISTRATEGY_MYGUI_H__

#include "Defines.h"
#include "IGuiStrategy.h"

#include "Plugins/IGuiStrategyFactory.h"

namespace MyGUI
{
	class Gui;
	class Widget;
	class OgrePlatform;
}

namespace Core
{
namespace GUI
{
	class CGuiStrategyFactory_MyGui : public Plugin::IGuiStrategyFactory
	{
	public:
		CGuiStrategyFactory_MyGui();
		~CGuiStrategyFactory_MyGui() { }

		Core::GUI::IGuiStrategy* CreateStrategy();
	};

	enum E_GUI_STRATEGY;

	class CORE_EXPORT CGuiStrategy_MyGui : public IGuiStrategy
	{
	private:
		MyGUI::Gui*				m_GUI;
		MyGUI::OgrePlatform*	m_Platform;

		MyGUI::Widget* mMainWidget;
		String mPrefix;
		String mLayoutName;
		Vector<MyGUI::Widget*> mListWindowRoot;
		//Vector<CBaseLayout_MyGui*> mListBase;

	public:
		CGuiStrategy_MyGui();
		~CGuiStrategy_MyGui();

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
		bool CreateForm(const char* Name, const Vector3& Position, const Vector2& Size) { return false; }
		bool CreateLabel(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text) { return false; }
		bool CreateButton(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text) { return false; }
		bool CreateComboBox(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, Vector<String>& Items, u32 IndexItem) { return false; }
		void ShowMessageBox(const char* Message, const char* Title);
		bool ShowMessageBoxYesNo(const char* Message, const char* Title);

		// Mouse
		void SetMousePosition(const Vector2& Position);
		Vector2* GetMousePosition();

		MyGUI::Gui* GetGui() { return m_GUI; }

		void Initialize(const String& _layout, MyGUI::Widget* _parent = nullptr);

		template <typename T> void AssignWidget(T * & _widget, const std::string& _name, bool _throw = true)
		{
			_widget = nullptr;
			for (auto iter = mListWindowRoot.cbegin(); iter!=mListWindowRoot.cend(); ++iter)
			{
				MyGUI::WidgetPtr find = (*iter)->findWidget(mPrefix + _name);
				if (nullptr != find)
				{
					T * cast = find->castType<T>(false);
					if (nullptr != cast)
					{
						_widget = cast;
					}
					else if (_throw)
					{
							MYGUI_EXCEPT("Error cast : dest type = '" << T::getClassTypeName()
							<< "' source name = '" << find->getName()
							<< "' source type = '" << find->getTypeName() << "' in layout '" << mLayoutName << "'");
					}
					return;

				}
			}
			MYGUI_ASSERT( ! _throw, "widget name '" << _name << "' in layout '" << mLayoutName << "' not found.");
		}

		template <typename T> void AssignBase(T * & _widget, const std::string& _name, bool _throw = true)
		{
			_widget = nullptr;
			for (auto iter = mListWindowRoot.cbegin(); iter!=mListWindowRoot.cend(); ++iter)
			{
				MyGUI::WidgetPtr find = (*iter)->findWidget(mPrefix + _name);
				if (nullptr != find)
				{
					_widget = new T(find);
					mListBase.push_back(_widget);
					return;
				}
			}
			MYGUI_ASSERT( ! _throw, "widget name '" << _name << "' in layout '" << mLayoutName << "' not found.");
		}
	};
}
}

#endif //  __CGUISTRATEGY_MYGUI_H__

