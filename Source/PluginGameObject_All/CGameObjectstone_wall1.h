#ifndef __CGAMEOBJECTSTONE_WALL1_H__
#define __CGAMEOBJECTSTONE_WALL1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone_wall1 : public CGameObject
	{
	public:
		CGameObjectStone_wall1(const char* Name, Vector3& Pos);
		~CGameObjectStone_wall1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone_wall1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone_wall1Factory();
		~CGameObjectStone_wall1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE_WALL1_H__
