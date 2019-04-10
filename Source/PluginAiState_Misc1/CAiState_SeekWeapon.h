#ifndef __CAI_STATE_FINDWEAPON_H__
#define __CAI_STATE_FINDWEAPON_H__

#include "Defines.h"
#include "Plugins/PluginTypes.h"
#include "Plugins/IAiStateFactory.h"
#include "CCharacterState.h"

#include "OgreVector3.h"

namespace Core
{
	class CPlayer;

	namespace Plugin
	{
		class CAiState_SeekWeapon : public Core::AI::CCharacterState
		{
		public:
			CAiState_SeekWeapon(CPlayer* Player);

			Core::AI::E_CHARACTER_STATE_OUTCOME Update(f32 elapsedTime);

		private:
			u32			m_CheckCount;
			Vector3 m_Target;
		};	

		class CAiState_SeekWeaponFactory : public IAiStateFactory
		{
		public:
			CAiState_SeekWeaponFactory();
			~CAiState_SeekWeaponFactory();

			Core::AI::CCharacterState* GetCharacterState(CPlayer* Player);
		};
	}
}

#endif // __CAI_STATE_FINDWEAPON_H__