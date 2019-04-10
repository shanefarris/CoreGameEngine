#ifndef __CGAMEOBJECTSTEAKCOOKED_H__
#define __CGAMEOBJECTSTEAKCOOKED_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectSteakCooked : public CGameObject
	{
	public:
		CGameObjectSteakCooked(const char* Name, Vector3& Pos);
		~CGameObjectSteakCooked();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectSteakCookedFactory : public IGameObjectFactory
	{
	public:
		CGameObjectSteakCookedFactory();
		~CGameObjectSteakCookedFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTEAKCOOKED_H__
