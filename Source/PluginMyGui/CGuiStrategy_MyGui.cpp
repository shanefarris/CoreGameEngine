#include "CGuiStrategy_MyGui.h"
#include "CGameManager.h"
#include "CInputManager.h"
#include "CCameraManager.h"
#include "CGuiManager.h"
#include "CInputEvent.h"
#include "IO/CoreLogging.h"
#include "CMessageBox_MyGui.h"

#include "MyGui/MyGui.h"
#include "MyGui/MyGUI_OgrePlatform.h"

using namespace Core;
using namespace Core::GUI;
using namespace MyGUI;

CGuiStrategy_MyGui::CGuiStrategy_MyGui()
{
	isInitialized = false;
	isEnabled = false;
	m_GUI = nullptr;
	m_Platform = nullptr;
}

CGuiStrategy_MyGui::~CGuiStrategy_MyGui()
{
	Shutdown();
}

void CGuiStrategy_MyGui::Initialize()
{
	try
	{
		CORE_LOG("loading GUI...");

		m_Platform = new MyGUI::OgrePlatform();
		m_Platform->initialise(CGameManager::Instance()->GetRenderWindow(),
			CGameManager::Instance()->GetSceneManager());

		// Disable std output
		MyGUI::LogManager::getInstance().setSTDOutputEnabled(false);

		m_GUI = new MyGUI::Gui();
		m_GUI->initialise();
		isInitialized = true;
		isEnabled = true;

		MyGUI::ResourceManager::getInstance().load("MessageBoxResources.xml");

		// hide mouse
		MyGUI::PointerManager::getInstance().setVisible(false);
		CORE_LOG("GUI loaded!");
	}
	catch(MyGUI::Exception& e)
	{
		std::cout << e.getFullDescription() << std::endl;
	}
}

void CGuiStrategy_MyGui::LoadLayout(const char* name)
{
	MyGUI::LayoutManager::getInstance().loadLayout(String(name));
}

bool CGuiStrategy_MyGui::FrameStarted(const f32& LastTime)
{
	//if(m_GUI && isEnabled)
	//	m_GUI->injectFrameEntered(LastTime);
	return true;
}

bool CGuiStrategy_MyGui::FrameEnded(const f32& LastTime)
{
	return true;
}

void CGuiStrategy_MyGui::Shutdown()
{
	//for (auto iter = mListBase.cbegin(); iter!=mListBase.cend(); ++iter)
	//	delete (*iter);		// Use regular delete because it is a const.

	//mListBase.clear();

	//auto it = mListWindowRoot.begin();
	//while(it != mListWindowRoot.end())
	//{
	//	mListWindowRoot.erase(it++);
	//}
	mListWindowRoot.clear();

	if(m_GUI)
	{
		m_GUI->destroyAllChildWidget();
		m_GUI->shutdown();
		CORE_DELETE(m_GUI);
	}

	if(m_Platform)
	{
		m_Platform->shutdown();
		CORE_DELETE(m_Platform);
	}
}

void CGuiStrategy_MyGui::Activate()
{
	CORE_LOG("GUI activated");
	isEnabled = true;
}

void CGuiStrategy_MyGui::Desactivate()
{
	CORE_LOG("GUI desactivated");
	MyGUI::PointerManager::getInstance().setVisible(false);
	isEnabled = false;
}

void CGuiStrategy_MyGui::SetCursorPosition(float x, float y)
{
}

bool CGuiStrategy_MyGui::MouseMoved( const CInputMouseEvent &arg )
{
	if (isEnabled && m_GUI)
		MyGUI::InputManager::getInstancePtr()->injectMouseMove(arg.absX, arg.absY, arg.absZ);

	return true;
}

bool CGuiStrategy_MyGui::MousePressed( const CInputMouseEvent &arg, MouseButtonID id )
{
	if (isEnabled && m_GUI)
		MyGUI::InputManager::getInstancePtr()->injectMousePress(arg.absX, arg.absY, MouseButton::Enum(id));

	return true;
}

bool CGuiStrategy_MyGui::MouseReleased( const CInputMouseEvent &arg, MouseButtonID id )
{
	if (isEnabled && m_GUI)
		MyGUI::InputManager::getInstancePtr()->injectMouseRelease(arg.absX, arg.absY, MouseButton::Enum(id));
	return true;
}

bool CGuiStrategy_MyGui::KeyPressed( const CInputKeyEvent &arg )
{
	if (isEnabled && m_GUI)
		MyGUI::InputManager::getInstancePtr()->injectKeyPress(MyGUI::KeyCode::Enum((int)arg.KeyCode), arg.Text);

	return true;
}

bool CGuiStrategy_MyGui::KeyReleased( const CInputKeyEvent &arg )
{
	if (isEnabled && m_GUI)
		MyGUI::InputManager::getInstancePtr()->injectKeyRelease(MyGUI::KeyCode::Enum((int)arg.KeyCode));
	return true;
}

E_GUI_STRATEGY CGuiStrategy_MyGui::GetStrategyType() 
{ 
	return EGS_MYGUI; 
}

void CGuiStrategy_MyGui::ShowMessageBox(const char* Message, const char* Title)
{
	Message::createMessageBox("Message", Title, Message, MyGUI::MessageBoxStyle::IconWarning | MyGUI::MessageBoxStyle::Ok);
}

bool CGuiStrategy_MyGui::ShowMessageBoxYesNo(const char* Message, const char* Title)
{
	Message::createMessageBox("Message", Title, Message, MyGUI::MessageBoxStyle::IconWarning | MyGUI::MessageBoxStyle::Yes | MyGUI::MessageBoxStyle::No);
	return false;
}

void CGuiStrategy_MyGui::SetMousePosition(const Vector2& Position)
{
	CInputManager::Instance()->SetMousePosition((s32)Position.x, (s32)Position.y);
}

Vector2* CGuiStrategy_MyGui::GetMousePosition()
{
	auto point = MyGUI::InputManager::getInstance().getMousePosition();
	return new Vector2(point.left, point.top);
}

void CGuiStrategy_MyGui::Initialize(const String& _layout, MyGUI::Widget* _parent)
{
	const std::string MAIN_WINDOW = "_Main";
	mLayoutName = _layout;

	if (mLayoutName.empty())
	{
		mMainWidget = _parent;
	}
	else
	{
		mPrefix = MyGUI::utility::toString(this, "_");
		mListWindowRoot = MyGUI::LayoutManager::getInstance().loadLayout(mLayoutName, mPrefix, _parent);

		const std::string main_name = mPrefix + MAIN_WINDOW;
		for (auto iter = mListWindowRoot.cbegin(); iter!=mListWindowRoot.cend(); ++iter)
		{
			if ((*iter)->getName() == main_name)
			{
				mMainWidget = (*iter);
				break;
			}
		}
		MYGUI_ASSERT(mMainWidget, "root widget name '" << MAIN_WINDOW << "' in layout '" << mLayoutName << "' not found.");
	}
}

namespace Core
{
	namespace GUI
	{
		CGuiStrategyFactory_MyGui::CGuiStrategyFactory_MyGui()
		{
			GuiStrategyType = "MYGUI";
		}

		IGuiStrategy* CGuiStrategyFactory_MyGui::CreateStrategy()
		{
			return new CGuiStrategy_MyGui();
		}
	}
}