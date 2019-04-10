#ifndef __IGUISTRATEGY_H__
#define __IGUISTRATEGY_H__

#include "CInputListener.h"

namespace Ogre
{
	class Vector2;
}

namespace Core
{
	class CInputKeyEvent;
	class CInputMouseEvent;

namespace GUI
{
	enum E_GUI_STRATEGY;

	class IGuiStrategy : public CInputMouseListener, CInputKeyListener
	{
	protected: 
		bool isInitialized;
		bool isEnabled;

	public:
		virtual ~IGuiStrategy() { };
		virtual void Initialize() = 0;
		virtual void Shutdown() = 0;
		virtual void Activate() = 0;
		virtual void Desactivate() = 0;
		
		virtual void SetCursorPosition(float x, float y) = 0;
		virtual void LoadLayout(const char* Name) = 0;

		// Engine/Input events
		virtual bool FrameStarted(const float& LastTime) = 0;
		virtual bool FrameEnded(const float& LastTime) = 0;
		virtual bool MouseMoved(const CInputMouseEvent &arg) = 0;
		virtual bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id) = 0;
		virtual bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id) = 0;
		virtual bool KeyPressed(const CInputKeyEvent &arg) = 0;
		virtual bool KeyReleased(const CInputKeyEvent &arg) = 0;

		// Common control methods
		virtual bool CreateForm(const char* Name, const Vector3& Position, const Vector2& Size) = 0;
		virtual bool CreateLabel(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text) = 0;
		virtual bool CreateButton(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text) = 0;
		virtual bool CreateComboBox(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, Vector<String>& Items, u32 IndexItem) = 0;
		virtual void ShowMessageBox(const char* Message, const char* Title) = 0;
		virtual bool ShowMessageBoxYesNo(const char* Message, const char* Title) = 0;

		// Mouse
		virtual void SetMousePosition(const Ogre::Vector2& Position) = 0;
		virtual Ogre::Vector2* GetMousePosition() = 0;

		virtual E_GUI_STRATEGY GetStrategyType() = 0;
	};
}
}

#endif //  __IGUISTRATEGY_H__
