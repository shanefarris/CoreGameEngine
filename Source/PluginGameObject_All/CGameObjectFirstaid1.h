#ifndef __CGAMEOBJECTFIRSTAID1_H__
#define __CGAMEOBJECTFIRSTAID1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFirstaid1 : public CGameObject
	{
	public:
		CGameObjectFirstaid1(const char* Name, Vector3& Pos);
		~CGameObjectFirstaid1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectFirstaid1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFirstaid1Factory();
		~CGameObjectFirstaid1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFIRSTAID1_H__
