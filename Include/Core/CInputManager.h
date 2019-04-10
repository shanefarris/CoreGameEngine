// Contains any events you would like to register for input.  It is a listner it's self so you can add
// the method you want executed and it will execute in order.
// The manager needs to be called at the "game" level so it can be updated in the main loop.

#ifndef __CINPUTMANAGER_H__
#define __CINPUTMANAGER_H__

#include "Defines.h"

namespace Core
{
	class CInputManagerPimpl;
	class CInputMouseEvent;
	class CInputKeyListener;
	class CInputMouseListener;
	class CInputJoyStickListener;
	enum  KeyCode;
	enum  MouseButtonID;

	class CORE_EXPORT CInputManager
	{
	public:
		static CInputManager* Instance();

		virtual ~CInputManager();

		void Initialise();
		void Capture();

		void AddKeyListener(CInputKeyListener *KeyListener, const char* instanceName);
		void AddMouseListener(CInputMouseListener *MouseListener, const char* instanceName);
		void AddJoystickListener(CInputJoyStickListener *joystickListener, const char* instanceName);

		void RemoveKeyListener(const char* instanceName);
		void RemoveMouseListener(const char* instanceName);
		void RemoveJoystickListener(const char* instanceName);

		void RemoveKeyListener(CInputKeyListener *KeyListener);
		void RemoveMouseListener(CInputMouseListener *MouseListener);
		void RemoveJoystickListener(CInputJoyStickListener *joystickListener);

		void RemoveAllListeners();
		void RemoveAllKeyListeners();
		void RemoveAllMouseListeners();
		void RemoveAllJoystickListeners();

		void Shutdown();

		bool IsKeyDown(KeyCode Key);
		bool IsMouseDown(MouseButtonID Button);

		void ResizeWindow(RenderWindow* rw);
		void SetWindowExtents(s32 Width, s32 Height);
		void SetMousePosition(s32 X, s32 Y);

		void GetMouseRay(Ray& ray);
		u32  GetNumOfJoysticks();
		void GetMouseEvent(CInputMouseEvent& MouseEvent);

	private:
		CInputManager();
		static CInputManager* InputManager;
		CInputManagerPimpl*	  m_InputManagerPimpl;

	};
}

#endif // __CINPUTMANAGER_H__
