// All menus that are apart of the game state needs to inherit this class.
// menuPage<--CMenuStat<--CGameState

#ifndef __CMENUSTATE_H__
#define __CMENUSTATE_H__

#include "CGameState.h"
#include "CInputListener.h"
#include "OgreFrameListener.h"
#include "OgreWindowEventUtilities.h"

namespace Core
{
	class CInputKeyEvent;
	class CInputMouseEvent;
	enum MouseButtonID;

	class CMenuState : public CGameState, public FrameListener, public WindowEventListener, public CInputMouseListener, public CInputKeyListener
	{
	public:
		virtual bool MouseMoved(const CInputMouseEvent &arg) = 0;
		virtual bool MousePressed(const CInputMouseEvent &arg, MouseButtonID id) = 0;
		virtual bool MouseReleased(const CInputMouseEvent &arg, MouseButtonID id) = 0;

		virtual bool KeyPressed(const CInputKeyEvent &arg) = 0;
		virtual bool KeyReleased(const CInputKeyEvent &arg) = 0;

		virtual bool frameRenderingQueued(const FrameEvent& Event) = 0;
		virtual bool frameEnded(const FrameEvent& Event) = 0;
	};
}

#endif // __CMENUSTATE_H__