#include "CFpsFrameListener.h"
#include "CGameManager.h"
#include "CInputManager.h"
#include "CCameraManager.h"
#include "OgreConsole.h"
#include "CLuaConsole.h"
#include "CTextOutput.h"
#include "IGuiStrategy.h"
#include "CInputEvent.h"

#include "OgreRenderWindow.h"

using namespace Core;

CFpsFrameListener::CFpsFrameListener(RenderWindow* win) : CFrameListenerFramework(win) 
{ 
	m_MouseListener = new CFpsMouseListener(this);
	m_KeyListener = new CFpsKeyListener(this);
	CInputManager::Instance()->AddMouseListener(m_MouseListener, "CFpsFrameListener");
	CInputManager::Instance()->AddKeyListener(m_KeyListener, "CFpsFrameListener");
}

CFpsFrameListener::~CFpsFrameListener()
{
	try
	{
		CInputManager::Instance()->RemoveMouseListener("CFpsFrameListener");
		CInputManager::Instance()->RemoveKeyListener("CFpsFrameListener");
		CORE_DELETE(m_MouseListener);
		CORE_DELETE(m_KeyListener);
	}
	catch(std::exception& e)
	{
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CFpsFrameListener()");
	}
}

bool CFpsFrameListener::frameRenderingQueued(const FrameEvent& evt)
{
	//CFrameListenerFramework::frameRenderingQueued(evt);
	TimeUntilNextToggle -= evt.timeSinceLastFrame;

	if(m_Window->isClosed())	
		return false;

	auto inputManager = CInputManager::Instance();
	if(inputManager->IsKeyDown(KC_SYSRQ) && TimeUntilNextToggle <= 0)
	{
		std::ostringstream ss;
		ss << "screenshot_" << ++NumScreenShots << ".png";
		m_Window->writeContentsToFile(ss.str());
		TimeUntilNextToggle = 0.5;
	}

	// Exit if we press Esc
	if(inputManager->IsKeyDown(KC_ESCAPE))
		return false;

	return true;
}

bool CFpsFrameListener::CFpsMouseListener::MouseMoved(const CInputMouseEvent &arg)
{
	if(m_FrameListener->m_GuiStrategy)
		return m_FrameListener->m_GuiStrategy->MouseMoved(arg);
	return true;
}

bool CFpsFrameListener::CFpsMouseListener::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(m_FrameListener->m_GuiStrategy)
		return m_FrameListener->m_GuiStrategy->MousePressed(arg, id);
	return true;
}

bool CFpsFrameListener::CFpsMouseListener::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(m_FrameListener->m_GuiStrategy)
		return m_FrameListener->m_GuiStrategy->MouseReleased(arg, id);
	return true;
}

bool CFpsFrameListener::CFpsKeyListener::KeyPressed(const CInputKeyEvent &arg)
{
	if(arg.KeyCode == KC_F12)
	{
		m_FrameListener->m_Console->SetVisible(!m_FrameListener->m_Console->GetVisible());
		CGameManager::Instance()->SetConsoleVisible(m_FrameListener->m_Console->GetVisible() || m_FrameListener->m_LuaConsole->IsVisible());
		CCameraManager::Instance()->SetEnabled(!CGameManager::Instance()->GetConsoleVisible());
		return true;
	}
	else if(arg.KeyCode == KC_GRAVE)
	{
		m_FrameListener->m_LuaConsole->SetVisible(!m_FrameListener->m_LuaConsole->IsVisible());
		CGameManager::Instance()->SetConsoleVisible(m_FrameListener->m_Console->GetVisible() || m_FrameListener->m_LuaConsole->IsVisible());
		CCameraManager::Instance()->SetEnabled(!CGameManager::Instance()->GetConsoleVisible());
		return true;
	}
	else if(arg.KeyCode == KC_ESCAPE)
	{
		CGameManager::Instance()->AdvanceGameState();
		return true;
	}
	else if(m_FrameListener->m_GuiStrategy && !CGameManager::Instance()->GetConsoleVisible())
	{
		return m_FrameListener->m_GuiStrategy->KeyPressed(arg);
	}
	// A key was pressed, pass to the consoles
	else
	{
		if(m_FrameListener->m_Console->GetVisible() == true)
		{
			m_FrameListener->m_Console->OnKeyPressed(arg);
		}
		else if(m_FrameListener->m_LuaConsole->IsVisible())
		{
			m_FrameListener->m_LuaConsole->OnKeyPressed(arg);
		}
	}

	return true;
}

bool CFpsFrameListener::CFpsKeyListener::KeyReleased(const CInputKeyEvent &arg)
{
	if(m_FrameListener->m_GuiStrategy)
		return m_FrameListener->m_GuiStrategy->KeyReleased(arg);
	return true;
}