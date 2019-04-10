#include "CGuiStrategy_Default.h"
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

#define DEFAULT_ATLAS "simpleDemo"
#define DEFAULT_DIS_FROM_PANEL 10

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

CGuiStrategy_Default::CGuiStrategy_Default() : m_Gui3D(nullptr)
{
	isEnabled = false;
}

CGuiStrategy_Default::~CGuiStrategy_Default()
{
	Shutdown();
}

bool CGuiStrategy_Default::CreateForm(const char* Name, const Vector3& Position, const Vector2& Size)
{
	auto panel = new Gui3D::Panel(m_Gui3D, CGameManager::Instance()->GetSceneManager(), Size, DEFAULT_DIS_FROM_PANEL, DEFAULT_ATLAS, Name);
	if(panel)
	{
		panel->mNode->setPosition(Position);
		m_Panels[Name] = panel;
		return true;
	}
	return false;
}

bool CGuiStrategy_Default::CreateLabel(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text)
{
	auto panel = m_Panels[FormName];
	if(panel)
	{
		m_Labels[Name] = panel->makeCaption(Position.x, Position.y, SizeX, SizeY, Text);
		return true;
	}
	return false;
}

bool CGuiStrategy_Default::CreateButton(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, const char* Text)
{
	auto panel = m_Panels[FormName];
	if(panel)
	{
		auto button = panel->makeButton(Position.x, Position.y, SizeX, SizeY, Text);
		button->setPressedCallback(this, &CGuiStrategy_Default::ButtonPressed);
		m_Buttons[Name] = button;
		return true;
	}
	return false;
}

bool CGuiStrategy_Default::CreateComboBox(const char* Name, const char* FormName, const Vector2& Position, u32 SizeX, u32 SizeY, Vector<String>& Items, u32 IndexItem)
{
	auto panel = m_Panels[FormName];
	if(panel)
	{
		auto comboBox = panel->makeCombobox(Position.x, Position.y, SizeX, SizeY, Items, IndexItem);
		comboBox->setValueChangedCallback(this, &CGuiStrategy_Default::ComboboxPressed);
		m_Comboboxes[Name] = comboBox;
		return true;
	}
	return false;
}

bool CGuiStrategy_Default::ComboboxPressed(Gui3D::PanelElement* e)
{
	// TODO: need to wire in events that are not aware of Gui3D controls
	auto combobox = static_cast<Gui3D::Combobox*>(e);
	return true;
}

bool CGuiStrategy_Default::ButtonPressed(Gui3D::PanelElement* e)
{
	// TODO: need to wire in events that are not aware of Gui3D controls
	auto button = static_cast<Gui3D::Button*>(e);
	return true;
}

void CGuiStrategy_Default::Initialize()
{
	DefaultPanelColors defaultPanelColors;
	m_Gui3D = new Gui3D::Gui3D(&defaultPanelColors);
	m_Gui3D->createScreen(CCameraManager::Instance()->GetViewport(), DEFAULT_ATLAS, "mainScreen");

	CGameManager::Instance()->GetEngineDevice()->addFrameListener(this);
}

bool CGuiStrategy_Default::frameStarted(const Ogre::FrameEvent& evt)
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it).second->injectTime(evt.timeSinceLastFrame);
	}

	return true;
}

void CGuiStrategy_Default::LoadLayout(const char* name)
{
}

bool CGuiStrategy_Default::FrameStarted(const f32& LastTime)
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it).second->injectTime(LastTime);
	}

	return true;
}

bool CGuiStrategy_Default::FrameEnded(const f32& LastTime)
{
	return true;
}

void CGuiStrategy_Default::Shutdown()
{
}

void CGuiStrategy_Default::Activate()
{
	CORE_LOG("GUI activated");
	isEnabled = true;
}

void CGuiStrategy_Default::Desactivate()
{
	CORE_LOG("GUI desactivated");
	isEnabled = false;
}

void CGuiStrategy_Default::SetCursorPosition(float x, float y)
{
}

bool CGuiStrategy_Default::MouseMoved( const CInputMouseEvent &arg )
{
	return true;
}

bool CGuiStrategy_Default::MousePressed( const CInputMouseEvent &arg, MouseButtonID id )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it).second->injectMousePressed(arg, id);
	}

	return true;
}

bool CGuiStrategy_Default::MouseReleased( const CInputMouseEvent &arg, MouseButtonID id )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it).second->injectMouseReleased(arg, id);
	}

	return true;
}

bool CGuiStrategy_Default::KeyPressed( const CInputKeyEvent &arg )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it).second->injectKeyPressed(arg);
	}

	return true;
}

bool CGuiStrategy_Default::KeyReleased( const CInputKeyEvent &arg )
{
	for(auto it = m_Panels.cbegin(); it != m_Panels.cend(); it++)
	{
		(*it).second->injectKeyReleased(arg);
	}

	return true;
}

E_GUI_STRATEGY CGuiStrategy_Default::GetStrategyType() 
{ 
	return EGS_GUI3D; 
}

void CGuiStrategy_Default::ShowMessageBox(const char* Message, const char* Title)
{
}

bool CGuiStrategy_Default::ShowMessageBoxYesNo(const char* Message, const char* Title)
{
	return false;
}

void CGuiStrategy_Default::SetMousePosition(const Vector2& Position)
{

}

Vector2* CGuiStrategy_Default::GetMousePosition()
{
	//auto point = MyGUI::InputManager::getInstance().getMousePosition();
	return new Vector2(0, 0);
}
