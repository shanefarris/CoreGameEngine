#ifndef __CGAMEOBJECTSPAWN_POINT_H__
#define __CGAMEOBJECTSPAWN_POINT_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectSpawn_point : public CGameObject
	{
	public:
		CGameObjectSpawn_point(const char* Name, Vector3& Pos);
		~CGameObjectSpawn_point();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectSpawn_pointFactory : public IGameObjectFactory
	{
	public:
		CGameObjectSpawn_pointFactory();
		~CGameObjectSpawn_pointFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSPAWN_POINT_H__
