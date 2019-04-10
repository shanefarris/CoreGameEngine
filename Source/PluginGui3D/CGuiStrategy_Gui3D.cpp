#include "CGuiStrategy_Gui3D.h"
#include "CGameManager.h"
#include "CInputManager.h"
#include "CCameraManager.h"
#include "CGuiManager.h"
#include "CInputEvent.h"
#include "IO/CoreLogging.h"

#include "Gui3D/Gui3D.h"
#include "Gui3D/Gui3DPanel.h"

#include "OgreVector2.h"

#include <OIS/OISMouse.h>
#include <OIS/OISKeyboard.h>

using namespace Core;
using namespace Core::GUI;

struct DefaultPanelColors : public Gui3D::PanelColors
{
	DefaultPanelColors::DefaultPanelColors()
		: Gui3D::PanelColors()
	{
		// General
		transparent = Gorilla::rgb(0, 0, 0, 0);

		// Panel
		panelBackgroundSpriteName = "panelBackground";
		panelCursorSpriteName = "mousepointer";
		panelCursorSpriteSizeX = 12;
		panelCursorSpriteSizeY = 18;

		// Button
		// In the demo, sprites are used for the "click me!" button
		buttonInactiveSpriteName = "buttonInactive";
		buttonOveredSpriteName = "buttonOvered";
		buttonNotOveredSpriteName = "buttonNotOvered";
		buttonClickedSpriteName = "buttonClicked";

		// In the demo, those are used by the combobox previous and next buttons
		buttonBackgroundClickedGradientType = Gorilla::Gradient_NorthSouth;
		buttonBackgroundClickedGradientStart = Gorilla::rgb(255, 255, 255, 200);
		buttonBackgroundClickedGradientEnd = Gorilla::rgb(255, 255, 255, 170);

		buttonBackgroundOveredGradientType = Gorilla::Gradient_NorthSouth;
		buttonBackgroundOveredGradientStart = Gorilla::rgb(255, 255, 255, 128);
		buttonBackgroundOveredGradientEnd = Gorilla::rgb(255, 255, 255, 100);

		buttonBackgroundNotOveredGradientType = Gorilla::Gradient_NorthSouth;
		buttonBackgroundNotOveredGradientStart = Gorilla::rgb(255, 255, 255, 80);
		buttonBackgroundNotOveredGradientEnd = Gorilla::rgb(255, 255, 255, 50);

		buttonBackgroundInactiveGradientType = Gorilla::Gradient_NorthSouth;
		buttonBackgroundInactiveGradientStart = Gorilla::rgb(255, 255, 255, 15);
		buttonBackgroundInactiveGradientEnd = Gorilla::rgb(255, 255, 255, 5);

		buttonText = Gorilla::rgb(255, 255, 255, 255);
		buttonTextInactive = Gorilla::rgb(255, 255, 255, 70);
		buttonTextSize = 14;

		buttonBorder = Gorilla::rgb(70, 70, 70, 50);
		buttonBorderHighlight = Gorilla::rgb(255, 100, 100, 170);
		buttonBorderInactive = Gorilla::rgb(70, 70, 70, 15);
		buttonBorderSize = 1;

		// Checkbox
		checkboxOveredBackgroundSpriteName = "checkboxOvered";
		checkboxNotOveredBackgroundSpriteName = "checkboxNotOvered";
		checkboxCheckedNotOveredBackgroundSpriteName = "checkboxCheckedNotOvered";
		checkboxCheckedOveredBackgroundSpriteName = "checkboxCheckedOvered"; 

		// Combobox
		comboboxButtonPreviousOveredSpriteName = "comboboxpreviouselementbuttonovered";
		comboboxButtonPreviousNotOveredSpriteName = "comboboxpreviouselementbuttonnotovered";
		comboboxButtonPreviousInactiveSpriteName = "comboboxpreviouselementbuttoninactive";

		comboboxButtonNextOveredSpriteName = "comboboxnextelementbuttonovered";
		comboboxButtonNextNotOveredSpriteName = "comboboxnextelementbuttonnotovered";
		comboboxButtonNextInactiveSpriteName = "comboboxnextelementbuttoninactive";

		comboboxBackgroundGradientType = Gorilla::Gradient_NorthSouth;
		comboboxBackgroundGradientStart = Gorilla::rgb(255, 255, 255, 0);
		comboboxBackgroundGradientEnd = Gorilla::rgb(255, 255, 255, 0);

		comboboxOveredElement = Gorilla::rgb(255, 255, 255, 100);
		comboboxNotOveredElement = Gorilla::rgb(255, 255, 255, 30);
		comboboxSelectedElement = Gorilla::rgb(120, 20, 120, 200);

		comboboxText = Ogre::ColourValue::White;
		comboboxTextSize = 14;

		comboboxBorder = Gorilla::rgb(70, 70, 70, 50);
		comboboxBorderHighlight = Gorilla::rgb(255, 100, 100, 170);
		comboboxBorderSize = 0;

		// Caption
		captionBackgroundGradientType = Gorilla::Gradient_NorthSouth;
		captionBackgroundGradientStart = transparent;
		captionBackgroundGradientEnd = transparent;

		captionBorder = transparent;
		captionText = Ogre::ColourValue::White;
		captionTextSize = 14;
		captionBorderSize = 0;
	}
};

CGuiStrategy_Gui3D::CGuiStrategy_Gui3D() : m_Gui3D(nullptr)
{
	isEnabled = false;
}

CGuiStrategy_Gui3D::~CGuiStrategy_Gui3D()
{
	Shutdown();
}

void CGuiStrategy_Gui3D::Initialize()
{
	DefaultPanelColors defaultPanelColors;
	m_Gui3D = new Gui3D::Gui3D(&defaultPanelColors);
	m_Gui3D->createScreen(CCameraManager::Instance()->GetViewport(), "simpleDemo", "mainScreen");

	// Create a layer for the mousePointer
	auto mNormalizedMousePosition = Ogre::Vector2(0.5, 0.5);
	auto mMousePointerLayer = m_Gui3D->getScreen("mainScreen")->createLayer();
	auto mMousePointer = mMousePointerLayer->createRectangle(
		CCameraManager::Instance()->GetViewport()->getActualWidth()/2, 
		CCameraManager::Instance()->GetViewport()->getActualHeight()/2, 12, 18);
	mMousePointer->background_image("mousepointer");

	auto panel = new Gui3D::Panel(m_Gui3D, CGameManager::Instance()->GetSceneManager(), Ogre::Vector2(400, 400), 10, "simpleDemo", "test_panel");

	panel->makeCaption(5, -30, 390, 30, "Simple Demo Panel");

	//panel->makeButton(100, 10, 200, 30, "click me!")->setPressedCallback(this, &SimpleDemo::buttonPressed);
	//panel->makeCaption(10, 60, 100, 30, "check it ! ");
	//panel->makeCheckbox(110, 60, 30, 30)->setSelecteStateChangedCallback(this, &SimpleDemo::checkboxChecked);

	std::vector<Ogre::String> items;
	items.push_back("item1");
	items.push_back("item2");
	items.push_back("item3");
	items.push_back("item4");
	items.push_back("item5");
	items.push_back("item6");
	//panel->makeCombobox(10, 110, 380, 100, items, 4)->setValueChangedCallback(this, &SimpleDemo::comboboxValueChanged);

	auto captionButton = panel->makeCaption(10, 250, 380, 30, "The button hasn't been clicked yet");
	auto captionChecked = panel->makeCaption(10, 300, 380, 30, "The checkbox hasn't been checked");
	auto captionCombobox = panel->makeCaption(10, 350, 380, 30, "No selected values yet");

	panel->mNode->setPosition(0, 2.1, -8);
	m_Panels.push_back(panel);
	CGameManager::Instance()->GetEngineDevice()->addFrameListener(this);
}

bool CGuiStrategy_Gui3D::frameStarted(const Ogre::FrameEvent& evt)
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it)->injectTime(evt.timeSinceLastFrame);
	}

	return true;
}

void CGuiStrategy_Gui3D::LoadLayout(const char* name)
{
}

bool CGuiStrategy_Gui3D::FrameStarted(const f32& LastTime)
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it)->injectTime(LastTime);
	}

	return true;
}

bool CGuiStrategy_Gui3D::FrameEnded(const f32& LastTime)
{
	return true;
}

void CGuiStrategy_Gui3D::Shutdown()
{
}

void CGuiStrategy_Gui3D::Activate()
{
	CORE_LOG("GUI activated");
	isEnabled = true;
}

void CGuiStrategy_Gui3D::Desactivate()
{
	CORE_LOG("GUI desactivated");
	isEnabled = false;
}

void CGuiStrategy_Gui3D::SetCursorPosition(float x, float y)
{
}

bool CGuiStrategy_Gui3D::MouseMoved( const CInputMouseEvent &arg )
{
	return true;
}

bool CGuiStrategy_Gui3D::MousePressed( const CInputMouseEvent &arg, MouseButtonID id )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it)->injectMousePressed(arg, id);
	}

	return true;
}

bool CGuiStrategy_Gui3D::MouseReleased( const CInputMouseEvent &arg, MouseButtonID id )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it)->injectMouseReleased(arg, id);
	}

	return true;
}

bool CGuiStrategy_Gui3D::KeyPressed( const CInputKeyEvent &arg )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it)->injectKeyPressed(arg);
	}

	return true;
}

bool CGuiStrategy_Gui3D::KeyReleased( const CInputKeyEvent &arg )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it)->injectKeyReleased(arg);
	}

	return true;
}

E_GUI_STRATEGY CGuiStrategy_Gui3D::GetStrategyType() 
{ 
	return EGS_GUI3D; 
}

bool CGuiStrategy_Gui3D::CreateForm(const char* Name, const Vector3& Position, const Vector2& Size)
{
	return false;
}

bool CGuiStrategy_Gui3D::CreateLabel(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text)
{
	return false;
}

bool CGuiStrategy_Gui3D::CreateButton(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text)
{
	return false;
}

bool CGuiStrategy_Gui3D::CreateComboBox(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, Vector<String>& Items, u32 IndexItem)
{
	return false;
}

void CGuiStrategy_Gui3D::ShowMessageBox(const char* Message, const char* Title)
{
}

bool CGuiStrategy_Gui3D::ShowMessageBoxYesNo(const char* Message, const char* Title)
{
	return false;
}

void CGuiStrategy_Gui3D::SetMousePosition(const Vector2& Position)
{

}

Vector2* CGuiStrategy_Gui3D::GetMousePosition()
{
	//auto point = MyGUI::InputManager::getInstance().getMousePosition();
	return new Vector2(0, 0);
}

namespace Core
{
	namespace GUI
	{
		CGuiStrategyFactory_Gui3D::CGuiStrategyFactory_Gui3D()
		{
			GuiStrategyType = "GUI3D";
		}

		IGuiStrategy* CGuiStrategyFactory_Gui3D::CreateStrategy()
		{
			return new CGuiStrategy_Gui3D();
		}
	}
}