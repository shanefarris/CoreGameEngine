#ifndef __CCUSTOM_FRAMELISTENER_H__
#define __CCUSTOM_FRAMELISTENER_H__

#include "Defines.h"
#include "CInputListener.h"
#include "CFrameListenerFramework.h"

namespace Ogre
{
	class Overlay;
}

namespace Core
{
	class CInputKeyEvent;
	class CInputMouseEvent;
	enum MouseButtonID;

namespace Editor
{
	class CMenuDirector;

	class CCustomFrameListener : public CFrameListenerFramework, public CInputKeyListener, public CInputMouseListener
	{
	public:
		CCustomFrameListener(RenderWindow* win);
		bool frameRenderingQueued(const FrameEvent& evt);
		bool frameEnded(const FrameEvent& Event);
		
		bool MouseMoved(const CInputMouseEvent &arg);
		bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id);
		bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id);

		bool KeyPressed(const CInputKeyEvent &arg);
		bool KeyReleased(const CInputKeyEvent &arg);

	private:
		Overlay* m_RayTestSight;
	};
}
}


#endif // __CCUSTOM_FRAMELISTENER_H__
