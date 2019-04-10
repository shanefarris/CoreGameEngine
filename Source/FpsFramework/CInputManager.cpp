#include "CInputManager.h"
#include "IO/CoreLogging.h"
#include "CInputListener.h"
#include "CInputManagerPimpl.h"

using namespace Core;

CInputManager *CInputManager::InputManager = nullptr;

CInputManager* CInputManager::Instance() 
{
    if(InputManager == nullptr)
		InputManager = new CInputManager();
	return InputManager;
}

CInputManager::CInputManager() 
{
	Initialise();
}

CInputManager::~CInputManager() 
{
	try
	{
		CORE_DELETE(m_InputManagerPimpl);
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

void CInputManager::Initialise() 
{
	m_InputManagerPimpl = new CInputManagerPimpl();
}

void CInputManager::Capture() 
{
    m_InputManagerPimpl->Capture();
}

void CInputManager::Shutdown() 
{
    m_InputManagerPimpl->Shutdown();
}

void CInputManager::ResizeWindow(RenderWindow* rw)
{
	m_InputManagerPimpl->ResizeWindow(rw);
}

void CInputManager::AddKeyListener(CInputKeyListener *KeyListener, const char* instanceName) 
{
	m_InputManagerPimpl->AddKeyListener(KeyListener, instanceName);
}

void CInputManager::AddMouseListener(CInputMouseListener *MouseListener, const char* instanceName) 
{
    m_InputManagerPimpl->AddMouseListener(MouseListener, instanceName);
}

void CInputManager::AddJoystickListener(CInputJoyStickListener *joystickListener, const char* instanceName)
{
    m_InputManagerPimpl->AddJoystickListener(joystickListener, instanceName);
}

void CInputManager::RemoveKeyListener(const char* instanceName) 
{
	m_InputManagerPimpl->RemoveKeyListener(instanceName);
}

void CInputManager::RemoveMouseListener(const char* instanceName) 
{
	m_InputManagerPimpl->RemoveMouseListener(instanceName);
}

void CInputManager::RemoveJoystickListener(const char* instanceName) 
{
	m_InputManagerPimpl->RemoveJoystickListener(instanceName);
}

void CInputManager::RemoveKeyListener(CInputKeyListener *KeyListener) 
{
	m_InputManagerPimpl->RemoveKeyListener(KeyListener);
}

void CInputManager::RemoveMouseListener(CInputMouseListener *MouseListener) 
{
	m_InputManagerPimpl->RemoveMouseListener(MouseListener);
}

void CInputManager::RemoveJoystickListener(CInputJoyStickListener *joystickListener) 
{
	m_InputManagerPimpl->RemoveJoystickListener(joystickListener);
}

void CInputManager::RemoveAllListeners()
{
    m_InputManagerPimpl->RemoveAllListeners();
}

void CInputManager::RemoveAllKeyListeners() 
{
    m_InputManagerPimpl->RemoveAllKeyListeners();
}

void CInputManager::RemoveAllMouseListeners() 
{
	m_InputManagerPimpl->RemoveAllMouseListeners();
}

void CInputManager::RemoveAllJoystickListeners() 
{
	m_InputManagerPimpl->RemoveAllJoystickListeners();
}

void CInputManager::SetWindowExtents(int width, int height) 
{
	m_InputManagerPimpl->SetWindowExtents(width, height);
}

void CInputManager::SetMousePosition(s32 X, s32 Y)
{
	m_InputManagerPimpl->SetMousePosition(X, Y);
}

void CInputManager::GetMouseRay(Ray& ray)
{
	m_InputManagerPimpl->GetMouseRay(ray);
}

bool CInputManager::IsKeyDown(KeyCode Key)
{
	return m_InputManagerPimpl->IsKeyDown(Key);
}

bool CInputManager::IsMouseDown(MouseButtonID Button)
{
	return m_InputManagerPimpl->IsMouseDown(Button);
}

void CInputManager::GetMouseEvent(CInputMouseEvent& MouseEvent)
{
	m_InputManagerPimpl->GetMouseEvent(MouseEvent);
}

u32 CInputManager::GetNumOfJoysticks()
{
    return m_InputManagerPimpl->GetNumOfJoysticks();
}
