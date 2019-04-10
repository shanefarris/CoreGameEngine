#ifndef __CFRAMELISTENERFRAMEWORK_H__
#define __CFRAMELISTENERFRAMEWORK_H__

#include "Defines.h"
#include "OgreFrameListener.h"
#include "OgreWindowEventUtilities.h"

namespace Ogre
{
	enum TextureFilterOptions;
}

namespace Core
{
	namespace GUI
	{
		class IGuiStrategy;
	}

	class CLuaConsole;
	class OgreConsole;

	class CORE_EXPORT CFrameListenerFramework: public FrameListener, public WindowEventListener
	{
	public:
		// Constructor takes a RenderWindow because it uses that to determine input context
		CFrameListenerFramework(RenderWindow* Window, bool bufferedKeys = false, bool bufferedMouse = false, bool bufferedJoy = false);
		virtual ~CFrameListenerFramework();

		//Adjust mouse clipping area
		virtual void windowResized(RenderWindow* Window);
	  
		//Unattach OIS before window shutdown (very important under Linux)
		virtual void windowClosed(RenderWindow* Window);

		// Override frameRenderingQueued event to process that (don't care about frameEnded)
		virtual bool frameRenderingQueued(const FrameEvent& Event);
		virtual bool frameEnded(const FrameEvent& Event);

		void AddGuiStrategy(GUI::IGuiStrategy* Strategy);
		void RemoveGuiStrategy();

		// Provide a pointer to a static or global function 
		typedef bool (*TimerCallback)( int TimerId ); 

		// AddTimer() adds a timer to be called back after a given period 
		// Timer_ID is an optional identifier for later removal 
		// Repeat is a boolean flag, if true the timer handler will be called 
		// every Period untill stopped.  if false, timer handler will be called only once. 
		// Play_Catchup is a boolean flag, if true the timer handler will be called multiple times 
		// if TimerManager is unable to call at the requested rate due to low frame rate.    
		// the only difference between these two add functions is one uses member function callback 
		// the other uses a global callback. 
		void AddTimer( unsigned long Period, TimerCallback callback, int TimerId = -1, bool Repeat = false, bool PlayCatchup = true );
		//void AddTimer( unsigned long Period, MemberTimerHandler callback, callbackClass* callbackObject, 
		// int Timer_ID = -1, bool Repeat = false, bool Play_Catchup = true );

		// process next timer (if applicable) 
		bool Next();

		// searches for and removes all timers with given timer_ID 
		void StopTimer(s32 Timer_ID);

	protected:
		RenderWindow*			m_Window;
		Timer*					m_Timer; 
		TextureFilterOptions	m_Filtering;
		GUI::IGuiStrategy*		m_GuiStrategy;
		Core::OgreConsole*		m_Console;
		Core::CLuaConsole*		m_LuaConsole;

		u32						NumScreenShots;
		f32						TimeUntilNextToggle;			// just to stop toggles flipping too fast
		s32						Aniso;
		bool					isStatsOn;

		class TimerInstance 
		{ 
		public: 
			TimerCallback		tcb; 
			unsigned long		Period; 
			int					Timer_ID; 
			bool				Repeat; 
			bool				Play_Catchup; 

			unsigned long Trigger(unsigned long behind) 
			{ 
				bool callback_return = false; 
				long temp_behind = (long)behind; 
				while( temp_behind >= 0 ) 
				{ 
					temp_behind -= Period; 
					callback_return = Callback(); 
					if( !Repeat ) 
						return 0; 
					if( !callback_return ) 
						return 0; 
					if( Period == 0 ) 
						return 0; 
					if( !Play_Catchup ) 
						continue; 
				} 

				return (Period - (behind % Period)); 
			} 

			bool Callback() 
			{ 
				if ( tcb != nullptr ) 
				{ 
					return tcb(Timer_ID); 
				} 
				return false; 
			} 
		}; // TimerInstance

		// container for all our timer instances. 
		typedef std::multimap< int, TimerInstance > TimerMap; 
		TimerMap timers; 

	}; // CFrameListenerFramework
}

#endif
