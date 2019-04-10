#include "CGameState.h"
#include "CGameManager.h"

using namespace Core;

CGameState::CGameState()
{
	m_GameManager = CGameManager::Instance();
}
