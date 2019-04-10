#ifndef __CENTITY_EFFECT_H__
#define __CENTITY_EFFECT_H__

#include "Defines.h"

namespace Core
{
	class CGameObject;
	class CDummyGameObject;

	namespace Effects
	{
		class CORE_EXPORT CEntityEffect
		{
		public:
			CEntityEffect()
			{
				m_GameObject = nullptr;
			}

			virtual void AddEffectToGameObject(CGameObject* GameObject) = 0;
			virtual void RemoveEffectFromGameObject() = 0;

			const char* GetName() { return Name.c_str(); }

		protected:
			String				Name;
			CDummyGameObject*	m_GameObject;
		};
	}
}

#endif // __CENTITY_EFFECT_H__
