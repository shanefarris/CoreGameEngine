#ifndef __CGAMEOBJECTSTONE_WALL3_H__
#define __CGAMEOBJECTSTONE_WALL3_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone_wall3 : public CGameObject
	{
	public:
		CGameObjectStone_wall3(const char* Name, Vector3& Pos);
		~CGameObjectStone_wall3();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone_wall3Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone_wall3Factory();
		~CGameObjectStone_wall3Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE_WALL3_H__
