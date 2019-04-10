#include "CFrameListenerFramework.h"
#include "CGameManager.h"
#include "CInputManager.h"
#include "OgreConsole.h"
#include "CLuaConsole.h"
#include "IGuiStrategy.h"
#include "CInputEvent.h"

#include "OgreCommon.h"
#include "OgreRenderWindow.h"
#include "OgreMaterialManager.h"

using namespace Core;
		
CFrameListenerFramework::CFrameListenerFramework(RenderWindow* win, bool bufferedKeys, bool bufferedMouse, bool bufferedJoy ) 
	: m_Window(win), 
	isStatsOn(true), 
	NumScreenShots(0), 
	TimeUntilNextToggle(0),
	m_Filtering(TFO_BILINEAR),
	Aniso(1),
	m_GuiStrategy(0),
	m_Timer(nullptr)
{
	//Set initial mouse clipping size
	windowResized(m_Window);

	//Register as a Window listener
	WindowEventUtilities::addWindowEventListener(m_Window, this);

	// Debug console
	m_Console = Core::OgreConsole::Instance();

	// Lua console
	m_LuaConsole = CLuaConsole::Instance();

	// Set timer
	m_Timer = new Timer();
}

//Adjust mouse clipping area
void CFrameListenerFramework::windowResized(RenderWindow* rw)
{
	CInputManager::Instance()->ResizeWindow(rw);
}

//Unattach OIS before window shutdown (very important under Linux)
void CFrameListenerFramework::windowClosed(RenderWindow* rw)
{
	//Only close for window that created OIS (the main window in these demos)
	if( rw == m_Window )
	{
		CInputManager::Instance()->Shutdown();
	}
}

CFrameListenerFramework::~CFrameListenerFramework()
{
	try
	{
		//Remove ourself as a Window listener
		WindowEventUtilities::removeWindowEventListener(m_Window, this);
		windowClosed(m_Window);

		CORE_DELETE(m_Timer);
	}
	catch(std::exception& e)
	{
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CFrameListenerFramework()");
	}
}

// Override frameRenderingQueued event to process that (don't care about frameEnded)
bool CFrameListenerFramework::frameRenderingQueued(const FrameEvent& evt)
{
	if(m_Window->isClosed())	
		return false;

	auto inputManager = CInputManager::Instance();
	if(inputManager->IsKeyDown(KC_ESCAPE) || inputManager->IsKeyDown(KC_Q))
		CGameManager::Instance()->AdvanceGameState();

	if(inputManager->IsKeyDown(KC_SYSRQ) && TimeUntilNextToggle <= 0)
	{
		std::ostringstream ss;
		ss << "screenshot_" << ++NumScreenShots << ".png";
		m_Window->writeContentsToFile(ss.str());
		TimeUntilNextToggle = 0.5;
	}

	if(inputManager->IsKeyDown(KC_T) && TimeUntilNextToggle <= 0)
	{
		switch(m_Filtering)
		{
		case TFO_BILINEAR:
			m_Filtering = TFO_TRILINEAR;
			Aniso = 1;
			break;
		case TFO_TRILINEAR:
			m_Filtering = TFO_ANISOTROPIC;
			Aniso = 8;
			break;
		case TFO_ANISOTROPIC:
			m_Filtering = TFO_BILINEAR;
			Aniso = 1;
			break;
		default: break;
		}
		MaterialManager::getSingleton().setDefaultTextureFiltering(m_Filtering);
		MaterialManager::getSingleton().setDefaultAnisotropy(Aniso);

		TimeUntilNextToggle = 1;
	}

	// Update our timer events
	while(Next()); 

	return true;
}

bool CFrameListenerFramework::frameEnded(const FrameEvent& evt)
{
	return true;
}

void CFrameListenerFramework::AddGuiStrategy(GUI::IGuiStrategy* Strategy)
{
	m_GuiStrategy = Strategy;
}

void CFrameListenerFramework::RemoveGuiStrategy()
{
	m_GuiStrategy = nullptr;
}

void CFrameListenerFramework::AddTimer(unsigned long Period, TimerCallback callback, int TimerId, bool Repeat, bool PlayCatchup) 
{ 
	TimerInstance t; 
	//t.mtH = nullptr; 
	//t.thC = nullptr; 
	t.tcb = callback; 
	t.Period = Period; 
	t.Timer_ID = TimerId; 
	t.Repeat = Repeat; 
	t.Play_Catchup = PlayCatchup; 
	unsigned long now = m_Timer->getMilliseconds(); 
	timers.insert( std::make_pair(now + Period, t) ); 
} 

void CFrameListenerFramework::StopTimer(s32 TimerId) 
{ 
	// searches for and removes all timers with given timer_ID 
	for(auto i = timers.begin(); i != timers.end(); ++i ) 
	{ 
		if(i->second.Timer_ID == TimerId) 
		{ 
			timers.erase(i); 
			// we have to start our search over since erase invalidates our iterator 
			i = timers.begin(); 
		} 
	} 
} 

bool CFrameListenerFramework::Next() 
{ 
	// process next timer (if applicable) 
	if (timers.empty()) 
		return false; 

	auto now = m_Timer->getMilliseconds(); 
	auto then = (ul32)timers.begin()->first; 
	//std::cout << " now >= then " << now << " >= " << then << std::endl; 
	if( now >= then) 
	{ 
		auto currentTimer = timers.begin()->second; // get a copy of the timer instance 
		timers.erase(timers.begin()); // pop the sucker off the map. 
		auto next_trigger = currentTimer.Trigger( now - then ); // trigger it 
		if( next_trigger > 0 ) 
		{ 
			// if it returns non-zero, put it back in the map. 
			timers.insert(std::make_pair( now + next_trigger, currentTimer )); 
		} 
		return true; 
	} 
	return false; 
} 
