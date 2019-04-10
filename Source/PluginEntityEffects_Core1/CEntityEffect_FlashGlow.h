#ifndef __CENTITYEFFECT_FLASHGLOW_H__
#define __CENTITYEFFECT_FLASHGLOW_H__

#include "Defines.h"
#include "CEntityEffect.h"

namespace Core
{
	class CGameObject;

	namespace Plugin
	{
		class CEntityEffect_FlashGlow : public Core::Effects::CEntityEffect
		{
		public:
			CEntityEffect_FlashGlow();
			~CEntityEffect_FlashGlow();

			void AddEffectToGameObject(CGameObject* GameObject);
			void RemoveEffectFromGameObject();
		};
	}
}

#endif // __CENTITYEFFECT_FLASHGLOW_H__
