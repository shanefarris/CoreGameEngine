#ifndef __CGAMEOBJECTSTAIRS2_H__
#define __CGAMEOBJECTSTAIRS2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStairs2 : public CGameObject
	{
	public:
		CGameObjectStairs2(const char* Name, Vector3& Pos);
		~CGameObjectStairs2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStairs2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStairs2Factory();
		~CGameObjectStairs2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTAIRS2_H__
