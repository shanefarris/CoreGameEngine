#include "CCustomFrameListener.h"
#include "CoreEngine.h"
#include "Terrain/OgreTerrainGroup.h"
#include "CItemsManager.h"
#include "CInputManager.h"
#include "RuntimeEditor/CRuntimeEditorManager.h"
#include "CMenuDirector.h"
#include "IO/CoreLogging.h"
#include "IGuiStrategy.h"
#include "CEditorHelper.h"
#include "CObjectsMenu.h"
#include "CInputEvent.h"

#include <OgreOverlay.h>
#include <OgreRenderWindow.h>
#include <OgreOverlayManager.h>

using namespace Core;
using namespace Core::Editor;
using namespace Core::Nature;

CCustomFrameListener::CCustomFrameListener(RenderWindow* win) : CFrameListenerFramework(win) 
{ 
	m_RayTestSight = nullptr;
	CInputManager::Instance()->AddMouseListener(this, "CCustomFrameListener");
	CInputManager::Instance()->AddKeyListener(this, "CCustomFrameListener");
}

bool CCustomFrameListener::frameRenderingQueued(const FrameEvent& evt)
{
	//CFrameListenerFramework::frameRenderingQueued(evt);
	TimeUntilNextToggle -= evt.timeSinceLastFrame;

	if(m_Window->isClosed())	
		return false;

	// Should we start/stop the runtime editor
	auto inputManager = CInputManager::Instance();
	if(inputManager->IsKeyDown(KC_F6) && TimeUntilNextToggle <=0 && !CGameManager::Instance()->GetConsoleVisible())
	{
		TimeUntilNextToggle = 0.5;

		// Start/Stop editor
		if(!CMenuDirector::Instance()->isVisible)
			CRuntimeEditorManager::Instance()->StartEditor();
		else
			CRuntimeEditorManager::Instance()->StopEditor();

		if(CMenuDirector::Instance()->isVisible || CGameManager::Instance()->GetConsoleVisible())
			CCameraManager::Instance()->SetEnabled(false);
		else
			CCameraManager::Instance()->SetEnabled(true);

		// If we have a camera attached to a player and we are in "play" mode (not paused), end play mode.
		if(CGameObjectManager::Instance()->GetHumanPlayer() && 
			CMenuDirector::Instance()->isVisible && 
			!CMenuDirector::Instance()->isPaused)
		{
			CMenuDirector::Instance()->Pause();
			CCameraManager::Instance()->SetEnabled(false);
		}
	}
	// Should we start the Ray test
	else if(inputManager->IsKeyDown(KC_F8) && TimeUntilNextToggle <=0 && !CGameManager::Instance()->GetConsoleVisible())
	{
		TimeUntilNextToggle = 0.5;

		if(CMenuDirector::Instance()->isRayTest)
		{
			// Hide sight and turn ray test off
			if(m_RayTestSight)
			{
				m_RayTestSight->hide();
				CMenuDirector::Instance()->isRayTest = false;
			}
		}
		else
		{
			// Show sight and turn ray test on
			m_RayTestSight = (Overlay*)OverlayManager::getSingleton().getByName("Soldier/Target"); 
			if(m_RayTestSight)
			{
				m_RayTestSight->show();
				CMenuDirector::Instance()->isRayTest = true;
			}
			else
			{
				String msg = "Error loading profile overlay: " + String("Soldier/Target");
				CORE_ERR(msg.c_str());
			}
		}
	}

	return true;
}

bool CCustomFrameListener::frameEnded(const FrameEvent& Event)
{
	// Check for play/pause changes
	CMenuDirector::Instance()->Update(Event.timeSinceLastFrame);
	
	return true;
}

bool CCustomFrameListener::MouseMoved(const CInputMouseEvent &arg)
{
	if(m_GuiStrategy)
		return m_GuiStrategy->MouseMoved(arg);
	return true;
}	

bool CCustomFrameListener::MousePressed(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(m_GuiStrategy)
		return m_GuiStrategy->MousePressed(arg, id);
	return true;
}

bool CCustomFrameListener::MouseReleased(const CInputMouseEvent &arg, MouseButtonID id)
{
	if(m_GuiStrategy)
		return m_GuiStrategy->MouseReleased(arg, id);
	return true;
}

bool CCustomFrameListener::KeyPressed(const CInputKeyEvent &arg)
{
	if(arg.KeyCode == KC_F12)
	{
		//m_Console->SetVisible(!m_Console->GetVisible());
		//CCameraManager::Instance()->SetEnabled(!m_Console->GetVisible());
		//CGameManager::Instance()->SetConsoleVisible(m_Console->GetVisible() || m_LuaConsole->getVisible());
		//return true;
	}
	else if(arg.KeyCode == KC_GRAVE)
	{
		//m_LuaConsole->SetVisible(!m_LuaConsole->getVisible());
		//CCameraManager::Instance()->SetEnabled(!m_Console->GetVisible());
		//CGameManager::Instance()->SetConsoleVisible(m_Console->GetVisible() || m_LuaConsole->getVisible());
		//return true;
	}
	else if(arg.KeyCode == KC_ESCAPE)
	{
		CGameManager::Instance()->AdvanceGameState();
		return true;
	}
	else if(m_GuiStrategy && !CGameManager::Instance()->GetConsoleVisible())
	{
		return m_GuiStrategy->KeyPressed(arg);
	}
	// A key was pressed, pass to the consoles
	else
	{
		if(m_Console->GetVisible() == true)
		{
			//m_Console->OnKeyPressed(arg);
			return true;
		}
		else if(m_LuaConsole->IsVisible())
		{
			//m_LuaConsole->OnKeyPressed(arg);
			return true;
		}
	}

	return true;
}

bool CCustomFrameListener::KeyReleased(const CInputKeyEvent &arg)
{
	if(m_GuiStrategy)
		return m_GuiStrategy->KeyReleased(arg);
	return true;
}

