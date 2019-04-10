// Used for levels and menus.  Is ment to be placed in a list and executed in order until there
// are not more states to execute.  Should be executed at the "game" level.  Each level has its own
// frame listener, each menu state is going to typically be its own frame listener.

#ifndef __CGAMESTATE_H__
#define __CGAMESTATE_H__

#include "Defines.h"

namespace Core
{
	class CGameManager;

	class CORE_EXPORT CGameState
	{
	public:
		CGameState();
		virtual ~CGameState() { }

		virtual void Update(const f32& elapsedTime) = 0;
		virtual bool Load() = 0;
		virtual void End() = 0;

	protected:
		CGameManager*	m_GameManager;
	};
}

#endif // __CGAMESTATE_H__