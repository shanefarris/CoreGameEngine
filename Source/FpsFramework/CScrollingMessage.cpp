#include "CScrollingMessage.h"
#include "CGameManager.h"
 
#include "OgreOverlayManager.h"
#include "OgreOverlayContainer.h"
#include "OgreRenderWindow.h"
#include "OgreStringConverter.h"
#include "OgreOverlayElement.h"
#include "OgreOverlay.h"

using namespace Core;
using namespace Core::OgreSpecific;
 
CScrollingMessage::CScrollingMessage()
{
	m_GameManager = CGameManager::Instance();
    mTimeToGo = 0.0;
    mJustAdded = false;
	PosX = 5;
	PosY = 250;
	Spacing = 20;

	Init();
}
 
void CScrollingMessage::Init()
{
    mOverlay = OverlayManager::getSingleton().create("ScrollingOverlay");
 
    mPanel = static_cast<OverlayContainer*>(OverlayManager::getSingleton().createOverlayElement("Panel", "container1"));
    mPanel->setMetricsMode(GMM_PIXELS);
    mPanel->setDimensions((f32)m_GameManager->GetRenderWindow()->getWidth(), (f32)m_GameManager->GetRenderWindow()->getHeight());
    mPanel->setPosition(PosX, PosY);
 
    // now create the text...
    String name;
    for (u32 i = 0; i < 5; ++i) 
	{
        name = "CScrollingMessage"+StringConverter::toString(i);
        mTextBox[i] = OverlayManager::getSingleton().createOverlayElement("TextArea", name);
        mTextBox[i]->setMetricsMode(GMM_PIXELS);
        mTextBox[i]->setDimensions(20, 5);        
        mTextBox[i]->setWidth(20);
        mTextBox[i]->setHeight(5);
 
        mTextBox[i]->setPosition(PosX, PosY + i * Spacing);
        mTextBox[i]->setParameter("font_name", "BlueHigh");
        mTextBox[i]->setParameter("char_height", "16");
		mTextBox[i]->setColour(ColourValue(.5, .5, .5, 0));
        mTextBox[i]->setCaption(" ");
        mPanel->addChild(mTextBox[i]);
    }
    mOverlay->add2D(mPanel);
 
    mOverlay->show();
}
 
void CScrollingMessage::AddText(const String& text) 
{
    // first swap the content...
	mTextBox[4]->setCaption(mTextBox[3]->getCaption());
	mTextBox[3]->setCaption(mTextBox[2]->getCaption());
    mTextBox[2]->setCaption(mTextBox[1]->getCaption());
    mTextBox[1]->setCaption(mTextBox[0]->getCaption());
    mTextBox[0]->setCaption(text);

    // but hide the first textbox first...
    mTextBox[0]->hide();

    // and move the others to upper coordinate...
    mTextBox[1]->setPosition(PosX, PosY);
    mTextBox[2]->setPosition(PosX, PosY + Spacing);
	mTextBox[2]->setPosition(PosX, PosY + Spacing * 2);
	mTextBox[2]->setPosition(PosX, PosY + Spacing * 3);
    mTimeToGo = 1.0;
    mJustAdded = true;
}
 
void CScrollingMessage::Update(const f32& elapsedTime)
{
    if (mJustAdded) 
	{
        mTimeToGo -= elapsedTime;
        if (mTimeToGo <= 1.0)
            mTextBox[0]->show();

        if (mTimeToGo < 1e-3) 
		{
            mTimeToGo = 0.0;
            mJustAdded = false;
        }

        // scroll the textbox by this much..
        f32 progress = (1.0f - mTimeToGo) / 1.5f;
        f32 y = PosY + Spacing * progress;

        mTextBox[1]->setPosition(PosX, y);
        mTextBox[1]->setColour(ColourValue(1.0f, 1.0f, 1.0f, 1.0f - progress / 4.0f));

        mTextBox[2]->setPosition(PosX, y + Spacing);
        mTextBox[2]->setColour(ColourValue(1.0f, 1.0f, 1.0f, 1.0f - progress * progress));

		mTextBox[3]->setPosition(PosX, y + Spacing * 2.0f);
        mTextBox[3]->setColour(ColourValue(1.0f, 1.0f, 1.0f, 1.0f - progress * progress));

		mTextBox[4]->setPosition(PosX, y + Spacing * 3.0f);
        mTextBox[4]->setColour(ColourValue(1.0f, 1.0f, 1.0f, 1.0f - progress * progress));
    }
}