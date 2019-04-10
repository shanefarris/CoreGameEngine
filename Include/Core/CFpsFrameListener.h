#ifndef __CFPS_FRAMELISTENER_H__
#define __CFPS_FRAMELISTENER_H__

#include "CFrameListenerFramework.h"
#include "CInputListener.h"
#include "CInputEvent.h"

namespace Core
{
	namespace GUI
	{
		class IGuiStrategy;
	}

	class CORE_EXPORT CFpsFrameListener : public CFrameListenerFramework 
	{
	 public:
		CFpsFrameListener(RenderWindow* win);
		~CFpsFrameListener();

		bool frameRenderingQueued(const FrameEvent& evt);

	private:
		class CFpsMouseListener: public CInputMouseListener
		{
		private:
			CFpsFrameListener* m_FrameListener;

		public:
			friend CFpsFrameListener;

			CFpsMouseListener(CFpsFrameListener* FrameListener) : m_FrameListener(FrameListener) { }
			~CFpsMouseListener() {}

			bool MouseMoved(const CInputMouseEvent &arg);
			bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
			bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);
		};

		class CFpsKeyListener : public CInputKeyListener
		{
		private:
			CFpsFrameListener* m_FrameListener;

		public:
			friend CFpsFrameListener;

			CFpsKeyListener(CFpsFrameListener* FrameListener) : m_FrameListener(FrameListener) { }
			~CFpsKeyListener() {}

			bool KeyPressed(const CInputKeyEvent &arg);
			bool KeyReleased(const CInputKeyEvent &arg);		
		};

		CFpsMouseListener*	m_MouseListener;
		CFpsKeyListener*	m_KeyListener;
	};
}


#endif // __CFPS_FRAMELISTENER_H__
