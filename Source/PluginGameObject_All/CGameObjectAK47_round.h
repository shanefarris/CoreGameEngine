#ifndef __CGAMEOBJECTAK47_ROUND_H__
#define __CGAMEOBJECTAK47_ROUND_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAK47_round : public CGameObject
	{
	public:
		CGameObjectAK47_round(const char* Name, Vector3& Pos);
		~CGameObjectAK47_round();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAK47_roundFactory : public IGameObjectFactory
	{
	public:
		CGameObjectAK47_roundFactory();
		~CGameObjectAK47_roundFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTAK47_ROUND_H__
