#ifndef __CGAMEOBJECTSTONE1_H__
#define __CGAMEOBJECTSTONE1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone1 : public CGameObject
	{
	public:
		CGameObjectStone1(const char* Name, Vector3& Pos);
		~CGameObjectStone1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone1Factory();
		~CGameObjectStone1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE1_H__
