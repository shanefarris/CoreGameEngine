#ifndef __CGAMEOBJECTSTEAKBURNT_H__
#define __CGAMEOBJECTSTEAKBURNT_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectSteakBurnt : public CGameObject
	{
	public:
		CGameObjectSteakBurnt(const char* Name, Vector3& Pos);
		~CGameObjectSteakBurnt();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectSteakBurntFactory : public IGameObjectFactory
	{
	public:
		CGameObjectSteakBurntFactory();
		~CGameObjectSteakBurntFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTEAKBURNT_H__
