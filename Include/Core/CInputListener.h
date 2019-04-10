#ifndef __CINPUTLISTENER_H__
#define __CINPUTLISTENER_H__

namespace Core
{
	class CInputKeyEvent;
	class CInputMouseEvent;
	class CInputJoyStickEvent;

	enum MouseButtonID
	{
		MB_Left = 0, 
		MB_Right, 
		MB_Middle,
		MB_Button3, 
		MB_Button4,	
		MB_Button5, 
		MB_Button6,	
		MB_Button7
	};

	class CInputMouseListener
	{
	public:
		virtual ~CInputMouseListener() { };

		virtual bool MouseMoved(const CInputMouseEvent &arg) = 0;
		virtual bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id) = 0;
		virtual bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id) = 0;
	};

	class CInputKeyListener
	{
	public:
		virtual ~CInputKeyListener() { }

		virtual bool KeyPressed(const CInputKeyEvent &arg) = 0;
		virtual bool KeyReleased(const CInputKeyEvent &arg) = 0;
	};

	class CInputJoyStickListener
	{
	public:
		virtual ~CInputJoyStickListener() { }

		virtual bool ButtonPressed(const CInputJoyStickEvent &arg, int button) = 0;
		virtual bool ButtonReleased(const CInputJoyStickEvent &arg, int button) = 0;
		virtual bool AxisMoved(const CInputJoyStickEvent &arg, int axis) = 0;
		virtual bool SliderMoved(const CInputJoyStickEvent &, int index) { return true; }
		virtual bool PovMoved(const CInputJoyStickEvent &arg, int index) { return true; }
		virtual bool Vector3Moved(const CInputJoyStickEvent &arg, int index) { return true; }
	};
}

#endif // __CINPUTKEYLISTENER_H__