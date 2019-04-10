#ifndef __CGAMEOBJECTTREE2_H__
#define __CGAMEOBJECTTREE2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTree2 : public CGameObject
	{
	public:
		CGameObjectTree2(const char* Name, Vector3& Pos);
		~CGameObjectTree2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTree2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTree2Factory();
		~CGameObjectTree2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTREE2_H__
