#ifndef __CGAMEOBJECTTREE1_H__
#define __CGAMEOBJECTTREE1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTree1 : public CGameObject
	{
	public:
		CGameObjectTree1(const char* Name, Vector3& Pos);
		~CGameObjectTree1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTree1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTree1Factory();
		~CGameObjectTree1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTREE1_H__
