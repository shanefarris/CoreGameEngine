#ifndef __CINPUTMANAGERPIMPL_H__
#define __CINPUTMANAGERPIMPL_H__

#include "Defines.h"
#include "CInputEvent.h"

//Use this define to signify OIS will be used as a DLL(so that dll import/export macros are in effect)
#define OIS_DYNAMIC_LIB
#include <OIS/OIS.h>

namespace Core
{
	class CInputMouseEvent;
	class CInputKeyListener;
	class CInputMouseListener;
	class CInputJoyStickListener;
	enum  KeyCode;
	enum  MouseButtonID;

	class CORE_EXPORT CInputManagerPimpl : public OIS::KeyListener, public OIS::MouseListener, public OIS::JoyStickListener 
	{
	public:
		CInputManagerPimpl();
		virtual ~CInputManagerPimpl();

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
		// Keyboard virtuals
		bool keyPressed(const OIS::KeyEvent &e);
		bool keyReleased(const OIS::KeyEvent &e);

		// Mouse virtuals
		bool mouseMoved(const OIS::MouseEvent &e);
		bool mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id);
		bool mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id);

		// Joystick virtuals
		bool povMoved(const OIS::JoyStickEvent &e, int pov);
		bool axisMoved(const OIS::JoyStickEvent &e, int axis);
		bool sliderMoved(const OIS::JoyStickEvent &e, int sliderID);
		bool buttonPressed(const OIS::JoyStickEvent &e, int button);
		bool buttonReleased(const OIS::JoyStickEvent &e, int button);

		void ConvertMouseEventToCore(const OIS::MouseEvent& OisMouseEvent, CInputMouseEvent& MouseEvent); 
		void ConvertMouseStateToCore(const OIS::MouseState& OisMouseState, CInputMouseEvent& MouseEvent); 

		OIS::InputManager*	m_InputSystem;
		OIS::Mouse*			m_Mouse;
		OIS::Keyboard*		m_Keyboard;

		CInputMouseEvent	m_MouseEvent;

		Vector<OIS::JoyStick*> m_Joysticks;
		Vector<OIS::JoyStick*>::iterator itJoystick;
		Vector<OIS::JoyStick*>::iterator itJoystickEnd;

		Map<String, CInputKeyListener*> m_KeyListeners;
		Map<String, CInputMouseListener*> m_MouseListeners;
		Map<String, CInputJoyStickListener*> m_JoystickListeners;

		Map<String, CInputKeyListener*>::iterator itKeyListener;
		Map<String, CInputMouseListener*>::iterator itMouseListener;
		Map<String, CInputJoyStickListener*>::iterator itJoystickListener;

		Map<String, CInputKeyListener*>::iterator itKeyListenerEnd;
		Map<String, CInputMouseListener*>::iterator itMouseListenerEnd;
		Map<String, CInputJoyStickListener*>::iterator itJoystickListenerEnd;
	};
}

#endif // __CINPUTMANAGERPIMPL_H__
