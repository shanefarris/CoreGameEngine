#include "CInputManagerPimpl.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "CGuiManager.h"
#include "IGuiStrategy.h"
#include "IO/CoreLogging.h"
#include "CInputListener.h"

// Ogre
#include "OgreCamera.h"
#include "OgreRenderWindow.h"
#include "OgreSceneNode.h"

using namespace Core;

CInputManagerPimpl::CInputManagerPimpl() 
	: m_Mouse(nullptr), 
	m_Keyboard(nullptr), 
	m_InputSystem(nullptr) 
{
	Initialise();
}

CInputManagerPimpl::~CInputManagerPimpl() 
{
	try
	{
		if(m_InputSystem) 
		{
			if(m_Mouse) 
			{
				m_InputSystem->destroyInputObject(m_Mouse);
				m_Mouse = nullptr;
			}

			if(m_Keyboard) 
			{
				m_InputSystem->destroyInputObject(m_Keyboard);
				m_Keyboard = nullptr;
			}

			if(m_Joysticks.size() > 0) 
			{
				itJoystick    = m_Joysticks.begin();
				itJoystickEnd = m_Joysticks.end();
				for(; itJoystick != itJoystickEnd; ++itJoystick) 
				{
					m_InputSystem->destroyInputObject(*itJoystick);
				}

				m_Joysticks.clear();
			}
			m_InputSystem->destroyInputSystem(m_InputSystem);
			m_InputSystem = nullptr;
		}

		// Clear Listeners
		auto kl = m_KeyListeners.begin();
		while (kl != m_KeyListeners.end()) 
			m_KeyListeners.erase(kl++);

		auto ml = m_MouseListeners.begin();
		while (ml != m_MouseListeners.end()) 
			m_MouseListeners.erase(ml++);

		auto jl = m_JoystickListeners.begin();
		while (jl != m_JoystickListeners.end()) 
			m_JoystickListeners.erase(jl++);

		m_KeyListeners.clear();
		m_MouseListeners.clear();
		m_JoystickListeners.clear();
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CInputManager()");
	}
}

void CInputManagerPimpl::Initialise() 
{
	auto GameManager = CGameManager::Instance();
	auto renderWindow = GameManager->GetRenderWindow();

    if(!m_InputSystem) 
	{
		CORE_LOG("*** Initializing OIS ***");

        // Setup basic variables
        OIS::ParamList paramList;
        size_t windowHnd = 0;
        std::ostringstream windowHndStr;

        // Get window handle
        renderWindow->getCustomAttribute("WINDOW", &windowHnd);

        // Fill parameter list
        windowHndStr << (u32)windowHnd;
        paramList.insert(std::make_pair(String("WINDOW"), windowHndStr.str()));
		paramList.insert(std::make_pair(String("w32_Mouse"), String("DISCL_FOREGROUND")));
		paramList.insert(std::make_pair(String("w32_Mouse"), String("DISCL_NONEXCLUSIVE")));
		paramList.insert(std::make_pair(String("w32_Keyboard"), String("DISCL_FOREGROUND")));
		paramList.insert(std::make_pair(String("w32_Keyboard"), String("DISCL_NONEXCLUSIVE")));
        // Create inputsystem
        m_InputSystem = OIS::InputManager::createInputSystem(paramList);

        // If possible create a buffered Keyboard
		if(m_InputSystem->getNumberOfDevices(OIS::OISKeyboard) > 0) 
		{
            m_Keyboard = static_cast<OIS::Keyboard*>(m_InputSystem->createInputObject(OIS::OISKeyboard, true));
            m_Keyboard->setEventCallback(this);
        }

        // If possible create a buffered Mouse
		if(m_InputSystem->getNumberOfDevices(OIS::OISMouse) > 0) 
		{
            m_Mouse = static_cast<OIS::Mouse*>(m_InputSystem->createInputObject(OIS::OISMouse, true));
            m_Mouse->setEventCallback(this);

            // Get window size
            u32 width, height, depth;
            s32 left, top;
            renderWindow->getMetrics(width, height, depth, left, top);

            // Set Mouse region
            this->SetWindowExtents(width, height);
        }
        /*
        // If possible create all joysticks in buffered mode
        if(m_InputSystem->numJoySticks() > 0) 
		{
            m_Joysticks.resize(m_InputSystem->numJoySticks());

            itJoystick    = m_Joysticks.begin();
            itJoystickEnd = m_Joysticks.end();
            for(; itJoystick != itJoystickEnd; ++itJoystick) 
			{
                (*itJoystick) = static_cast<OIS::JoyStick*>(m_InputSystem->createInputObject(OIS::OISJoyStick, true));
                (*itJoystick)->setEventCallback(this);
            }
        }
        */
    }
}

void CInputManagerPimpl::Capture(void) 
{
    // Need to capture / update each device every frame
    if(m_Mouse) 
        m_Mouse->capture();

	ConvertMouseStateToCore(m_Mouse->getMouseState(), m_MouseEvent);

    if(m_Keyboard)
        m_Keyboard->capture();

    if(m_Joysticks.size() > 0) 
	{
        itJoystick    = m_Joysticks.begin();
        itJoystickEnd = m_Joysticks.end();
        for(; itJoystick != itJoystickEnd; ++itJoystick) 
		{
            (*itJoystick)->capture();
        }
    }
}

void CInputManagerPimpl::Shutdown()
{
	if(m_InputSystem)
	{
		m_InputSystem->destroyInputObject( m_Mouse );
		m_InputSystem->destroyInputObject( m_Keyboard );
		//m_InputSystem->destroyInputObject( m_Joy );

		OIS::InputManager::destroyInputSystem(m_InputSystem);
		m_InputSystem = nullptr;
	}
}

void CInputManagerPimpl::ResizeWindow(RenderWindow* rw)
{
	unsigned int width, height, depth;
	int left, top;
	rw->getMetrics(width, height, depth, left, top);

	const OIS::MouseState &ms = m_Mouse->getMouseState();
	ms.width = width;
	ms.height = height;
}

void CInputManagerPimpl::AddKeyListener(CInputKeyListener *KeyListener, const char* instanceName) 
{
    if(m_Keyboard)
	{
        // Check for duplicate items
		String name = instanceName;
        itKeyListener = m_KeyListeners.find(name);
        if(itKeyListener == m_KeyListeners.end()) 
		{
            m_KeyListeners[ name ] = KeyListener;
        }
    }
}

void CInputManagerPimpl::AddMouseListener(CInputMouseListener *MouseListener, const char* instanceName) 
{
    if(m_Mouse) 
	{
        // Check for duplicate items
        itMouseListener = m_MouseListeners.find(instanceName);
        if(itMouseListener == m_MouseListeners.end())
		{
            m_MouseListeners[ instanceName ] = MouseListener;
        }
    }
}

void CInputManagerPimpl::AddJoystickListener(CInputJoyStickListener *joystickListener, const char* instanceName)
{
    if(m_Joysticks.size() > 0) 
	{
        // Check for duplicate items
        itJoystickListener = m_JoystickListeners.find(instanceName);
        if(itJoystickListener == m_JoystickListeners.end()) 
		{
            m_JoystickListeners[ instanceName ] = joystickListener;
        }
    }
}

void CInputManagerPimpl::RemoveKeyListener(const char* instanceName) 
{
    // Check if item exists
    itKeyListener = m_KeyListeners.find(instanceName);
    if(itKeyListener != m_KeyListeners.end()) 
	{
        m_KeyListeners.erase(itKeyListener);
    }
}

void CInputManagerPimpl::RemoveMouseListener(const char* instanceName) 
{
    // Check if item exists
    itMouseListener = m_MouseListeners.find(instanceName);
    if(itMouseListener != m_MouseListeners.end()) 
	{
        m_MouseListeners.erase(itMouseListener);
    }
}

void CInputManagerPimpl::RemoveJoystickListener(const char* instanceName) 
{
    // Check if item exists
    itJoystickListener = m_JoystickListeners.find(instanceName);
    if(itJoystickListener != m_JoystickListeners.end()) 
	{
        m_JoystickListeners.erase(itJoystickListener);
    }
}

void CInputManagerPimpl::RemoveKeyListener(CInputKeyListener *KeyListener) 
{
	if(!KeyListener)
		return;

    itKeyListener    = m_KeyListeners.begin();
    itKeyListenerEnd = m_KeyListeners.end();
    for(; itKeyListener != itKeyListenerEnd; ++itKeyListener) 
	{
        if(itKeyListener->second == KeyListener) 
		{
            m_KeyListeners.erase(itKeyListener);
            break;
        }
    }
}

void CInputManagerPimpl::RemoveMouseListener(CInputMouseListener *MouseListener) 
{
	if(!MouseListener)
		return;

    itMouseListener    = m_MouseListeners.begin();
    itMouseListenerEnd = m_MouseListeners.end();
    for(; itMouseListener != itMouseListenerEnd; ++itMouseListener)
	{
        if(itMouseListener->second == MouseListener) 
		{
            m_MouseListeners.erase(itMouseListener);
            break;
        }
    }
}

void CInputManagerPimpl::RemoveJoystickListener(CInputJoyStickListener *joystickListener) 
{
	if(!joystickListener)
		return;

    itJoystickListener    = m_JoystickListeners.begin();
    itJoystickListenerEnd = m_JoystickListeners.end();
    for(; itJoystickListener != itJoystickListenerEnd; ++itJoystickListener) 
	{
        if(itJoystickListener->second == joystickListener) 
		{
            m_JoystickListeners.erase(itJoystickListener);
            break;
        }
    }
}

void CInputManagerPimpl::RemoveAllListeners()
{
    m_KeyListeners.clear();
    m_MouseListeners.clear();
    m_JoystickListeners.clear();
}

void CInputManagerPimpl::RemoveAllKeyListeners() 
{
    m_KeyListeners.clear();
}

void CInputManagerPimpl::RemoveAllMouseListeners() 
{
    m_MouseListeners.clear();
}

void CInputManagerPimpl::RemoveAllJoystickListeners() 
{
    m_JoystickListeners.clear();
}

void CInputManagerPimpl::SetWindowExtents(int width, int height) 
{
    // Set Mouse region (if window resizes, we should alter this to reflect as well)
    const OIS::MouseState& MouseState = m_Mouse->getMouseState();
    MouseState.width  = width;
    MouseState.height = height;
}

void CInputManagerPimpl::SetMousePosition(s32 X, s32 Y)
{
	auto& mouseState = const_cast<OIS::MouseState &>(m_Mouse->getMouseState());
	mouseState.X.abs = X;
	mouseState.Y.abs = Y;
}

void CInputManagerPimpl::GetMouseRay(Ray& ray)
{
	using namespace Core::GUI;

	auto width = CGameManager::Instance()->GetRenderWindow()->getWidth();
	auto height = CGameManager::Instance()->GetRenderWindow()->getHeight();

	auto strategy = CGuiManager::Instance()->GetStrategy();
	auto point = new Vector2(0, 0);
	if(strategy)
	{
		point = strategy->GetMousePosition();
	}

	ray = CCameraManager::Instance()->GetCamera()->getCameraToViewportRay(point->x / width, point->y / height);
}

bool CInputManagerPimpl::IsKeyDown(KeyCode Key)
{
	return m_Keyboard->isKeyDown((OIS::KeyCode)Key);
}

bool CInputManagerPimpl::IsMouseDown(MouseButtonID Button)
{
	return m_Mouse->getMouseState().buttonDown((OIS::MouseButtonID)Button);
}

void CInputManagerPimpl::GetMouseEvent(CInputMouseEvent& MouseEvent)
{
	MouseEvent = m_MouseEvent;
}

u32 CInputManagerPimpl::GetNumOfJoysticks(void)
{
    return (u32)m_Joysticks.size();
}

bool CInputManagerPimpl::keyPressed(const OIS::KeyEvent &e) 
{
	CInputKeyEvent event;
	event.Text = e.text;
	event.KeyCode = (Core::KeyCode)e.key;

    itKeyListener    = m_KeyListeners.begin();
    itKeyListenerEnd = m_KeyListeners.end();
    for(; itKeyListener != itKeyListenerEnd; ++itKeyListener) 
	{
        if(!itKeyListener->second->KeyPressed(event))
			break;
    }
    return true;
}

bool CInputManagerPimpl::keyReleased(const OIS::KeyEvent &e) 
{
	CInputKeyEvent event;
	event.Text = e.text;
	event.KeyCode = (Core::KeyCode)e.key;

    itKeyListener    = m_KeyListeners.begin();
    itKeyListenerEnd = m_KeyListeners.end();
    for(; itKeyListener != itKeyListenerEnd; ++itKeyListener) 
	{
        if(!itKeyListener->second->KeyReleased(event))
			break;
    }
    return true;
}

bool CInputManagerPimpl::mouseMoved(const OIS::MouseEvent &e) 
{
	CInputMouseEvent event;
	ConvertMouseEventToCore(e, event);

    itMouseListener    = m_MouseListeners.begin();
    itMouseListenerEnd = m_MouseListeners.end();
    for(; itMouseListener != itMouseListenerEnd; ++itMouseListener) 
	{
        if(!itMouseListener->second->MouseMoved(event))
			break;
    }
    return true;
}

bool CInputManagerPimpl::mousePressed(const OIS::MouseEvent &e, OIS::MouseButtonID id) 
{
	CInputMouseEvent event;
	ConvertMouseEventToCore(e, event);

    itMouseListener    = m_MouseListeners.begin();
    itMouseListenerEnd = m_MouseListeners.end();
    for(; itMouseListener != itMouseListenerEnd; ++itMouseListener) 
	{
		if(!itMouseListener->second->MousePressed(event, (Core::MouseButtonID)id))
			break;
    }
    return true;
}

bool CInputManagerPimpl::mouseReleased(const OIS::MouseEvent &e, OIS::MouseButtonID id) 
{
	CInputMouseEvent event;
	ConvertMouseEventToCore(e, event);

    itMouseListener    = m_MouseListeners.begin();
    itMouseListenerEnd = m_MouseListeners.end();
    for(; itMouseListener != itMouseListenerEnd; ++itMouseListener) 
	{
        if(!itMouseListener->second->MouseReleased(event, (Core::MouseButtonID)id))
			break;
    }
    return true;
}

bool CInputManagerPimpl::povMoved(const OIS::JoyStickEvent &e, int pov) 
{
	CInputJoyStickEvent event;

    itJoystickListener    = m_JoystickListeners.begin();
    itJoystickListenerEnd = m_JoystickListeners.end();
    for(; itJoystickListener != itJoystickListenerEnd; ++itJoystickListener) 
	{
        if(!itJoystickListener->second->PovMoved(event, pov))
			break;
    }
    return true;
}

bool CInputManagerPimpl::axisMoved(const OIS::JoyStickEvent &e, int axis) 
{
	CInputJoyStickEvent event;

    itJoystickListener    = m_JoystickListeners.begin();
    itJoystickListenerEnd = m_JoystickListeners.end();
    for(; itJoystickListener != itJoystickListenerEnd; ++itJoystickListener)
	{
        if(!itJoystickListener->second->AxisMoved(event, axis))
			break;
    }
    return true;
}

bool CInputManagerPimpl::sliderMoved(const OIS::JoyStickEvent &e, int sliderID) 
{
	CInputJoyStickEvent event;

    itJoystickListener    = m_JoystickListeners.begin();
    itJoystickListenerEnd = m_JoystickListeners.end();
    for(; itJoystickListener != itJoystickListenerEnd; ++itJoystickListener) 
	{
        if(!itJoystickListener->second->SliderMoved(event, sliderID))
			break;
    }
    return true;
}

bool CInputManagerPimpl::buttonPressed(const OIS::JoyStickEvent &e, int button) 
{
	CInputJoyStickEvent event;

    itJoystickListener    = m_JoystickListeners.begin();
    itJoystickListenerEnd = m_JoystickListeners.end();
    for(; itJoystickListener != itJoystickListenerEnd; ++itJoystickListener) 
	{
        if(!itJoystickListener->second->ButtonPressed(event, button))
			break;
    }
    return true;
}

bool CInputManagerPimpl::buttonReleased(const OIS::JoyStickEvent &e, int button) 
{
	CInputJoyStickEvent event;

    itJoystickListener    = m_JoystickListeners.begin();
    itJoystickListenerEnd = m_JoystickListeners.end();
    for(; itJoystickListener != itJoystickListenerEnd; ++itJoystickListener) 
	{
        if(!itJoystickListener->second->ButtonReleased(event, button))
			break;
    }
    return true;
}

void CInputManagerPimpl::ConvertMouseEventToCore(const OIS::MouseEvent& OisMouseEvent, CInputMouseEvent& MouseEvent)
{
	ConvertMouseStateToCore(OisMouseEvent.state, MouseEvent);
}

void CInputManagerPimpl::ConvertMouseStateToCore(const OIS::MouseState& OisMouseState, CInputMouseEvent& MouseEvent)
{
	MouseEvent.absX = OisMouseState.X.abs;
	MouseEvent.absY = OisMouseState.Y.abs;
	MouseEvent.absZ = OisMouseState.Z.abs;
	MouseEvent.absOnlyX = OisMouseState.X.absOnly;
	MouseEvent.absOnlyY = OisMouseState.Y.absOnly;
	MouseEvent.absOnlyZ = OisMouseState.Z.absOnly;
	MouseEvent.relX = OisMouseState.X.rel;
	MouseEvent.relY = OisMouseState.Y.rel;
	MouseEvent.relZ = OisMouseState.Z.rel;
	MouseEvent.height = OisMouseState.height;
	MouseEvent.width = OisMouseState.width;
	MouseEvent.buttons = OisMouseState.buttons;
}