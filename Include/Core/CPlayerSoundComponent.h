#ifndef __CPLAYERSOUNDCOMPONENT_H__
#define __CPLAYERSOUNDCOMPONENT_H__

#include "Defines.h"

namespace Sound
{
	class CSound;
	class CSoundManager;
}

namespace Core
{
	class CORE_EXPORT CPlayerSoundComponent
	{
	public:
		CPlayerSoundComponent();
		~CPlayerSoundComponent();

		// Set the current sounds
		bool SetMove(const char* FileName);
		bool SetShot(const char* FileName);
		bool SetHolsterIn(const char* FileName);
		bool SetHolsterOut(const char* FileName);
		bool SetReload(const char* FileName);

		// Play sounds
		void PlayMove();
		void PlayShot();
		void PlayHolsterIn();
		void PlayHolsterOut();
		void PlayReload();

	private:
		// Methods
		Sound::CSound* SetSound(const char* FileName);

		// Quick reference to the current sounds being used
		Sound::CSound* m_Move;
		Sound::CSound* m_Shot;
		Sound::CSound* m_HolsterIn;
		Sound::CSound* m_HolsterOut;
		Sound::CSound* m_Reload;

		Sound::CSoundManager* m_SoundManager;
	};
}

#endif // __CPLAYERSOUNDCOMPONENT_H__