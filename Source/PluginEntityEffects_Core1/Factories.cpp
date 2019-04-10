#define DLL_EXPORT

#include "Factories.h"
#include "CEntityEffect_FlashGlow.h"

using namespace Core::Plugin;

// CEntityEffectFactor_FlashGlow
CEntityEffectFactor_FlashGlow::CEntityEffectFactor_FlashGlow()
{
	LabelName = "FLASH_GLOW";
}

CEntityEffectFactor_FlashGlow::~CEntityEffectFactor_FlashGlow()
{
}

Core::Effects::CEntityEffect* CEntityEffectFactor_FlashGlow::GetEffect()
{
	return new CEntityEffect_FlashGlow();
}
