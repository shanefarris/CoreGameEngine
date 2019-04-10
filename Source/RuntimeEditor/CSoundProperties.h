#ifndef __CSOUND_PROPERTIES_MENU_H__
#define __CSOUND_PROPERTIES_MENU_H__

#include "CoreEngine.h"
#include "MyGui/MyGUI.h"

namespace Core
{
	namespace GUI
	{
		class CGuiStrategy_MyGui;
	}

namespace Editor
{
	struct SOUND_OBJ;

	class CSoundProperties
	{
	public:
		CSoundProperties(GUI::CGuiStrategy_MyGui* Strategy);
		~CSoundProperties();

		void SetVisible(bool Visible, SOUND_OBJ* SoundObject = nullptr);
		MyGUI::Widget* GetForm() { return frmSoundProp; }

	private:
		void sldGain_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldPitch_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldMaxDistance_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldOuterConeGain_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldInnerConeAngle_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldOuterConeAngle_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldMaxGain_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldMinGain_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldRollOff_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void sldRefDistance_Click(MyGUI::ScrollBar* _sender, size_t _position);
		void chkSoundRelative_Click(MyGUI::Widget* _sender);
		void btnSoundCancel_Click(MyGUI::Widget* _sender);
		void btnSoundSave_Click(MyGUI::Widget* _sender);
		void btnSoundPlay_Click(MyGUI::Widget* _sender);
		void btnSoundPause_Click(MyGUI::Widget* _sender);
		void btnSoundStop_Click(MyGUI::Widget* _sender);

		Sound::CSound*	curr_sound;

		MyGUI::ScrollBar*	sldGain;
		MyGUI::ScrollBar*	sldPitch;
		MyGUI::ScrollBar*	sldMaxDistance;
		MyGUI::ScrollBar*	sldOuterConeGain;
		MyGUI::ScrollBar*	sldInnerConeAngle;
		MyGUI::ScrollBar*	sldOuterConeAngle;
		MyGUI::ScrollBar*	sldMaxGain;
		MyGUI::ScrollBar*	sldMinGain;
		MyGUI::ScrollBar*	sldRollOff;
		MyGUI::ScrollBar*	sldRefDistance;
		MyGUI::EditPtr		txtSoundPositionX;
		MyGUI::EditPtr		txtSoundPositionY;
		MyGUI::EditPtr		txtSoundPositionZ;
		MyGUI::EditPtr		txtSoundVelocityX;
		MyGUI::EditPtr		txtSoundVelocityY;
		MyGUI::EditPtr		txtSoundVelocityZ;
		MyGUI::EditPtr		txtSoundDirectionX;
		MyGUI::EditPtr		txtSoundDirectionY;
		MyGUI::EditPtr		txtSoundDirectionZ;
		MyGUI::Button*	chkSoundRelative;
		MyGUI::Button*	btnSoundCancel;
		MyGUI::Button*	btnSoundSave;
		MyGUI::Button*	btnSoundPlay;
		MyGUI::Button*	btnSoundPause;
		MyGUI::Button*	btnSoundStop;

		MyGUI::Widget*		frmSoundProp;
	};
}
}
#endif // __CSOUND_PROPERTIES_MENU_H__