#ifndef __CGAMEOBJECTSTONE6_H__
#define __CGAMEOBJECTSTONE6_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone6 : public CGameObject
	{
	public:
		CGameObjectStone6(const char* Name, Vector3& Pos);
		~CGameObjectStone6();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone6Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone6Factory();
		~CGameObjectStone6Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE6_H__
