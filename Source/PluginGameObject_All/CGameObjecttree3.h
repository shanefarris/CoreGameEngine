#ifndef __CGAMEOBJECTTREE3_H__
#define __CGAMEOBJECTTREE3_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTree3 : public CGameObject
	{
	public:
		CGameObjectTree3(const char* Name, Vector3& Pos);
		~CGameObjectTree3();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTree3Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTree3Factory();
		~CGameObjectTree3Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTREE3_H__
