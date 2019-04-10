#ifndef __CGAMEOBJECTSTONE_WALL4_H__
#define __CGAMEOBJECTSTONE_WALL4_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone_wall4 : public CGameObject
	{
	public:
		CGameObjectStone_wall4(const char* Name, Vector3& Pos);
		~CGameObjectStone_wall4();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone_wall4Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone_wall4Factory();
		~CGameObjectStone_wall4Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE_WALL4_H__
