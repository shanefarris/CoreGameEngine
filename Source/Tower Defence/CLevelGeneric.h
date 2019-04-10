#ifndef __CLEVELGENERIC_H__
#define __CLEVELGENERIC_H__

#include "CGameState.h"
#include "CFpsFrameListener.h"

namespace Core
{
	class CFpsFrameListener;
}

class CHud;

class CLevelGeneric: public Core::CGameState
{
public:
	CLevelGeneric() : m_Hud(nullptr) { }
	~CLevelGeneric();

	void Update(const f32& deltaTime);
	bool Load();
	void End(){}

private:
	CHud*						m_Hud;
	Core::CFpsFrameListener*	m_FrameListener;
};

#endif // __CLEVELGENERIC_H__
