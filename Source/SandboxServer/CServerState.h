#ifndef __CSERVER_STATE_H__
#define __CLEVELGENERIC_H__

#include "CGameState.h"
#include "CFpsFrameListener.h"

namespace Core
{
	class CServerState: public CGameState
	{
	private:
		CFpsFrameListener* m_FrameListenerFramework;

	public:
		CServerState(){}
		~CServerState();

		void Update(const f32& deltaTime);
		bool Load();
		void End(){}
	};
}

#endif // __CLEVELGENERIC_H__
