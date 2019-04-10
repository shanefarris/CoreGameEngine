#include "CSoundProperties.h"
#include "CItemsManager.h"
#include "CInventoryItem.h"
#include "SceneImporterPackage.h"
#include "EditorObjects.h"
#include "CEditorHelper.h"
#include "CMenuDirector.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

using namespace Core;
using namespace Core::AI;
using namespace Core::GUI;
using namespace Core::Editor;
using namespace Core::Physics;
using namespace Core::Effects;

CSoundProperties::CSoundProperties(CGuiStrategy_MyGui* Strategy)
{
	Strategy->AssignWidget(frmSoundProp, "frmSoundProp");
	Strategy->AssignWidget(sldGain, "sldGain");
	Strategy->AssignWidget(sldPitch, "sldPitch");
	Strategy->AssignWidget(sldMaxDistance, "sldMaxDistance");
	Strategy->AssignWidget(sldOuterConeGain, "sldOuterConeGain");
	Strategy->AssignWidget(sldInnerConeAngle, "sldInnerConeAngle");
	Strategy->AssignWidget(sldOuterConeAngle, "sldOuterConeAngle");
	Strategy->AssignWidget(sldMaxGain, "sldMaxGain");
	Strategy->AssignWidget(sldMinGain, "sldMinGain");
	Strategy->AssignWidget(sldRollOff, "sldRollOff");
	Strategy->AssignWidget(sldRefDistance, "sldRefDistance");
	Strategy->AssignWidget(txtSoundPositionX, "txtSoundPositionX");
	Strategy->AssignWidget(txtSoundPositionY, "txtSoundPositionY");
	Strategy->AssignWidget(txtSoundPositionZ, "txtSoundPositionZ");
	Strategy->AssignWidget(txtSoundVelocityX, "txtSoundVelocityX");
	Strategy->AssignWidget(txtSoundVelocityY, "txtSoundVelocityY");
	Strategy->AssignWidget(txtSoundVelocityZ, "txtSoundVelocityZ");
	Strategy->AssignWidget(txtSoundDirectionX, "txtSoundDirectionX");
	Strategy->AssignWidget(txtSoundDirectionY, "txtSoundDirectionY");
	Strategy->AssignWidget(txtSoundDirectionZ, "txtSoundDirectionZ");
	Strategy->AssignWidget(chkSoundRelative, "chkSoundRelative");
	Strategy->AssignWidget(btnSoundCancel, "btnSoundCancel");
	Strategy->AssignWidget(btnSoundSave, "btnSoundSave");
	Strategy->AssignWidget(btnSoundPlay, "btnSoundPlay");
	Strategy->AssignWidget(btnSoundPause, "btnSoundPause");
	Strategy->AssignWidget(btnSoundStop, "btnSoundStop");

	sldGain->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldGain_Click);
	sldPitch->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldPitch_Click);
	sldMaxDistance->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldMaxDistance_Click);
	sldOuterConeGain->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldOuterConeGain_Click);
	sldInnerConeAngle->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldInnerConeAngle_Click);
	sldOuterConeAngle->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldOuterConeAngle_Click);
	sldMaxGain->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldMaxGain_Click);
	sldMinGain->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldMinGain_Click);
	sldRollOff->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldRollOff_Click);
	sldRefDistance->eventScrollChangePosition = MyGUI::newDelegate(this, &CSoundProperties::sldRefDistance_Click);
	chkSoundRelative->eventMouseButtonClick = MyGUI::newDelegate(this, &CSoundProperties::chkSoundRelative_Click);
	btnSoundCancel->eventMouseButtonClick = MyGUI::newDelegate(this, &CSoundProperties::btnSoundCancel_Click);
	btnSoundSave->eventMouseButtonClick = MyGUI::newDelegate(this, &CSoundProperties::btnSoundSave_Click);
	btnSoundPlay->eventMouseButtonClick = MyGUI::newDelegate(this, &CSoundProperties::btnSoundPlay_Click);
	btnSoundPause->eventMouseButtonClick = MyGUI::newDelegate(this, &CSoundProperties::btnSoundPause_Click);
	btnSoundStop->eventMouseButtonClick = MyGUI::newDelegate(this, &CSoundProperties::btnSoundStop_Click);
}

CSoundProperties::~CSoundProperties()
{
}

void CSoundProperties::SetVisible(bool Visible, SOUND_OBJ* SoundObject)
{
	using namespace Sound;

	if(SoundObject && Visible)
	{
		CSound* sound = CSoundManager::Instance()->GetSound(SoundObject->SoundName.c_str());
		if(sound)
		{
			curr_sound = sound;
			sound->Play();
			sound->SetLoop(true);
			sldPitch->setScrollPosition((size_t)sound->GetPitch() * 100);
			sldMaxDistance->setScrollPosition((size_t)sound->GetMaxDistance());
			sldOuterConeGain->setScrollPosition((size_t)sound->GetOuterConeGain());
			sldInnerConeAngle->setScrollPosition((size_t)sound->GetInnerConeAngle());
			sldOuterConeAngle->setScrollPosition((size_t)sound->GetOuterConeAngle());
			sldMaxGain->setScrollPosition((size_t)sound->GetMaxGain());
			sldMinGain->setScrollPosition((size_t)sound->GetMinGain());
			sldRollOff->setScrollPosition((size_t)sound->GetRolloffFactor());
			sldRefDistance->setScrollPosition((size_t)sound->GetReferenceDistance());
			txtSoundPositionX->setCaption(StringConverter::toString(SoundObject->Node->getPosition().x));
			txtSoundPositionY->setCaption(StringConverter::toString(SoundObject->Node->getPosition().y));
			txtSoundPositionZ->setCaption(StringConverter::toString(SoundObject->Node->getPosition().z));

			frmSoundProp->setVisible(true);
			return;
		}
	}
	frmSoundProp->setVisible(false);
}

void CSoundProperties::sldGain_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldGain->getScrollPosition() / 100.0f;
	if(curr_sound)
	{
		curr_sound->SetGain(value);
	}
}

void CSoundProperties::sldPitch_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldPitch->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetPitch(value);
	}
}

void CSoundProperties::sldMaxDistance_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldMaxDistance->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetMaxDistance(value);
	}
}

void CSoundProperties::sldOuterConeGain_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldOuterConeGain->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetOuterConeGain(value);
	}
}

void CSoundProperties::sldInnerConeAngle_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldInnerConeAngle->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetInnerConeAngle(value);
	}
}

void CSoundProperties::sldOuterConeAngle_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldOuterConeAngle->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetOuterConeAngle(value);
	}
}

void CSoundProperties::sldMaxGain_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldMaxGain->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetMaxGain(value);
	}
}

void CSoundProperties::sldMinGain_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldMinGain->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetMinGain(value);
	}
}

void CSoundProperties::sldRollOff_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldRollOff->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetRolloffFactor(value);
	}
}

void CSoundProperties::sldRefDistance_Click(MyGUI::ScrollBar* _sender, size_t _position)
{
	f32 value = (f32)sldRefDistance->getScrollPosition();
	if(curr_sound)
	{
		curr_sound->SetReferenceDistance(value);
	}
}

void CSoundProperties::chkSoundRelative_Click(MyGUI::Widget* _sender)
{	
	if(curr_sound)
	{
		curr_sound->SetRelativeToListener(chkSoundRelative->getStateSelected());
		chkSoundRelative->setStateSelected(!chkSoundRelative->getStateSelected());
	}
}

void CSoundProperties::btnSoundCancel_Click(MyGUI::Widget* _sender)
{
	CMenuDirector::Instance()->SetSoundPropMenuView(false);
}

void CSoundProperties::btnSoundSave_Click(MyGUI::Widget* _sender)
{
	CMenuDirector::Instance()->SetSoundPropMenuView(false);
}

void CSoundProperties::btnSoundPlay_Click(MyGUI::Widget* _sender)
{
	if(curr_sound)
		curr_sound->Play();
}

void CSoundProperties::btnSoundPause_Click(MyGUI::Widget* _sender)
{
	if(curr_sound)
		curr_sound->Pause();
}

void CSoundProperties::btnSoundStop_Click(MyGUI::Widget* _sender)
{
	if(curr_sound)
		curr_sound->Stop();
}
