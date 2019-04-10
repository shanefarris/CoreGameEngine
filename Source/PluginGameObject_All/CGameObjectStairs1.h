#ifndef __CGAMEOBJECTSTAIRS1_H__
#define __CGAMEOBJECTSTAIRS1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStairs1 : public CGameObject
	{
	public:
		CGameObjectStairs1(const char* Name, Vector3& Pos);
		~CGameObjectStairs1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStairs1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStairs1Factory();
		~CGameObjectStairs1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTAIRS1_H__
