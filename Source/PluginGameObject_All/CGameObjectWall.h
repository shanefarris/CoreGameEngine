#ifndef __CGAMEOBJECTWALL_H__
#define __CGAMEOBJECTWALL_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectWall : public CGameObject
	{
	public:
		CGameObjectWall(const char* Name, Vector3& Pos);
		~CGameObjectWall();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectWallFactory : public IGameObjectFactory
	{
	public:
		CGameObjectWallFactory();
		~CGameObjectWallFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTWALL_H__
