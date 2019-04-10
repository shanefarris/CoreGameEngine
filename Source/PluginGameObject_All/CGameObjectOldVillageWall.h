#ifndef __CGAMEOBJECTOLDVILLAGEWALL_H__
#define __CGAMEOBJECTOLDVILLAGEWALL_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectOldVillageWall : public CGameObject
	{
	public:
		CGameObjectOldVillageWall(const char* Name, Vector3& Pos);
		~CGameObjectOldVillageWall();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectOldVillageWallFactory : public IGameObjectFactory
	{
	public:
		CGameObjectOldVillageWallFactory();
		~CGameObjectOldVillageWallFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTOLDVILLAGEWALL_H__
