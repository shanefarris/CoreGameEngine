#ifndef __CGAMEOBJECTOLDVILLAGEROCK_H__
#define __CGAMEOBJECTOLDVILLAGEROCK_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectOldVillageRock : public CGameObject
	{
	public:
		CGameObjectOldVillageRock(const char* Name, Vector3& Pos);
		~CGameObjectOldVillageRock();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectOldVillageRockFactory : public IGameObjectFactory
	{
	public:
		CGameObjectOldVillageRockFactory();
		~CGameObjectOldVillageRockFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTOLDVILLAGEROCK_H__
