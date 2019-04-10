#ifndef __CGAMEOBJECTBUSH_1_H__
#define __CGAMEOBJECTBUSH_1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBush_1 : public CGameObject
	{
	public:
		CGameObjectBush_1(const char* Name, Vector3& Pos);
		~CGameObjectBush_1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBush_1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectBush_1Factory();
		~CGameObjectBush_1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBUSH_1_H__
