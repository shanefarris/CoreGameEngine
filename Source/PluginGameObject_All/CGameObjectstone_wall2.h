#ifndef __CGAMEOBJECTSTONE_WALL2_H__
#define __CGAMEOBJECTSTONE_WALL2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone_wall2 : public CGameObject
	{
	public:
		CGameObjectStone_wall2(const char* Name, Vector3& Pos);
		~CGameObjectStone_wall2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone_wall2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone_wall2Factory();
		~CGameObjectStone_wall2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE_WALL2_H__
