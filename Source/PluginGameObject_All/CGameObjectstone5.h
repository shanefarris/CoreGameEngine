#ifndef __CGAMEOBJECTSTONE5_H__
#define __CGAMEOBJECTSTONE5_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone5 : public CGameObject
	{
	public:
		CGameObjectStone5(const char* Name, Vector3& Pos);
		~CGameObjectStone5();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone5Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone5Factory();
		~CGameObjectStone5Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE5_H__
