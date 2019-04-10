#ifndef __PLUGIN_IAISTATEFACTORY_H__
#define __PLUGIN_IAISTATEFACTORY_H__

#include "Defines.h"
#include "PlayerEnums.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	class CPlayer;

	namespace AI
	{
		class CCharacterState;
	}

namespace Plugin
{
	class IAiStateFactory
	{
	public:
		virtual Core::AI::CCharacterState* GetCharacterState(CPlayer* Player) = 0;

		String			LabelName;
		E_PLAYER_STATE	Type;
		u32				Level;
	};
}
}

#endif // __PLUGIN_IAISTATEFACTORY_H__