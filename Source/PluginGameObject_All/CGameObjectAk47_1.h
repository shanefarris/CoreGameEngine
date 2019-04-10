#ifndef __CGAMEOBJECTAK47_1_H__
#define __CGAMEOBJECTAK47_1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAk47_1 : public CGameObject
	{
	public:
		CGameObjectAk47_1(const char* Name, Vector3& Pos);
		~CGameObjectAk47_1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAk47_1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectAk47_1Factory();
		~CGameObjectAk47_1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTAK47_1_H__
