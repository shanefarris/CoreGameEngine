#include "CTextOutput.h"
#include "CGuiManager.h"
#include "CCameraManager.h"

#include <stdarg.h>
#include <stdio.h>

#include "Gui3D/Gorilla.h"

#include "OgreColourValue.h"

using namespace Core;
using namespace Core::OgreSpecific;

CTextOutput* CTextOutput::TextOutput = nullptr;

#define CONSOLE_FONT_INDEX 9
#define CONSOLE_LINE_LENGTH 85
#define CONSOLE_LINE_COUNT 20
CTextOutput* CTextOutput::Instance()
{
	if(TextOutput == nullptr)
		TextOutput = new CTextOutput();
	return TextOutput;
}

CTextOutput::CTextOutput()
{
	NumOfBoxes = 0;

	//_overlay = OverlayManager::getSingletonPtr()->create("overlay1");
	//_panel = static_cast<OverlayContainer*>(OverlayManager::getSingletonPtr()->createOverlayElement("Panel", "container1"));
	//_panel->setDimensions(1, 1);
	//_panel->setPosition(0, 0);
	//_overlay->setZOrder(650);
	//_overlay->add2D(_panel);

	//_overlay->show();

	// Create gorilla things here.
	auto gorilla = GUI::CGuiManager::Instance()->GetSilverback();
	GUI::CGuiManager::Instance()->LoadAtlas(GUI::E_GORILLA_ATLAS::EGA_DEFAULT);
	m_Screen = gorilla->createScreen(CCameraManager::Instance()->GetViewport(), "dejavu");
	m_Layer = m_Screen->createLayer(15);

	m_ConsoleText = m_Layer->createMarkupText(CONSOLE_FONT_INDEX,  5, 5, StringUtil::BLANK);
	m_ConsoleText->width(m_Screen->getWidth() - 5);
	m_Layer->setVisible(true);
}

void CTextOutput::AddTextBox(const String& ID, const String& text, f32 x, f32 y, f32 width, f32 height)
{
	AddTextBox(ID, text, x, y, width, height, ColourValue(1.0, 1.0, 1.0, 1.0));
}

void CTextOutput::AddTextBox(const String& ID, const String& text, f32 x, f32 y, f32 width, f32 height, const ColourValue& color)
{
	//OverlayElement* textBox = OverlayManager::getSingletonPtr()->createOverlayElement("TextArea", ID);
	//textBox->setDimensions(width, height);
	//textBox->setMetricsMode(GMM_PIXELS);
	//textBox->setPosition(x, y * NumOfBoxes);
	//textBox->setWidth(width);
	//textBox->setHeight(height);
	////textBox->setParameter("font_name", "BlueHigh");
	//textBox->setParameter("char_height", "16");
	//textBox->setColour(color);
	//textBox->setCaption(text);
	//_panel->addChild(textBox);
	auto textBox = m_Layer->createCaption(CONSOLE_FONT_INDEX,  x, y, text);

	// save our text box
	TEXTBOX t(ID, NumOfBoxes, textBox);
	m_Textboxes[ID] = t;
	NumOfBoxes++;
}

CTextOutput::~CTextOutput()
{
	auto it = m_Textboxes.begin();
	while(it != m_Textboxes.end())
	{
		m_Textboxes.erase(it++);
	}
	m_Textboxes.clear();
}

void CTextOutput::RemoveTextBox(const String& ID)
{
	//_panel->removeChild(ID);
	//OverlayManager::getSingletonPtr()->destroyOverlayElement(ID);
	//
	//if(m_Textboxes.find(ID) != m_Textboxes.end())
	//{
	//	m_Textboxes.erase(ID);
	//	NumOfBoxes--;
	//}
}

void CTextOutput::SetText(const String& ID, const String& Text)
{
	s32 order = FindTextBox(ID);
	// does the overlay exist yet, if not create it
	if(order < 0)
	{
		AddTextBox(ID, Text, 10, 10, 100, 20, ColourValue::Green);
	}
	else
	{
		auto textBox = m_Textboxes[ID].TextBox;
		textBox->text(Text);
	}
	
}

s32 CTextOutput::FindTextBox(String Name)
{
	if(m_Textboxes.find(Name) != m_Textboxes.end())
	{
		// found it, return the id
		TEXTBOX t = m_Textboxes[Name];
		return t.Order;
	}

	// isn't created
	return -1;
}

void CTextOutput::Printf(const String& ID,  const char *fmt, /* args*/ ...)
{	
	char text[256];
	va_list ap;

	if (fmt == nullptr)
		*text=0;
	else 
	{
		va_start(ap, fmt);
	    vsprintf(text, fmt, ap);
		va_end(ap);
	}

	//auto textBox = OverlayManager::getSingletonPtr()->getOverlayElement(ID);
	//textBox->setCaption(text);
	auto textBox = m_Layer->createMarkupText(CONSOLE_FONT_INDEX,  5, 5, StringUtil::BLANK);
}

void CTextOutput::SetVisible(bool Visible)
{
	//if(_overlay)
	//{
	//	if(Visible)
	//		_overlay->show();
	//	else
	//		_overlay->hide();
	//}
}

bool CTextOutput::IsVisible()
{
	return true; //_overlay->isVisible();
}