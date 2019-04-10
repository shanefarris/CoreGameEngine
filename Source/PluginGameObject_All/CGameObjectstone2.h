#ifndef __CGAMEOBJECTSTONE2_H__
#define __CGAMEOBJECTSTONE2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone2 : public CGameObject
	{
	public:
		CGameObjectStone2(const char* Name, Vector3& Pos);
		~CGameObjectStone2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone2Factory();
		~CGameObjectStone2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE2_H__
