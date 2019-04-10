#ifndef __CGAMEOBJECTTARGET2_H__
#define __CGAMEOBJECTTARGET2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTarget2 : public CGameObject
	{
	public:
		CGameObjectTarget2(const char* Name, Vector3& Pos);
		~CGameObjectTarget2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTarget2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTarget2Factory();
		~CGameObjectTarget2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTARGET2_H__
