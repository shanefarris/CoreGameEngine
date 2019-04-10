#ifndef __CGAMEOBJECTFAB1_H__
#define __CGAMEOBJECTFAB1_H__

#include "Defines.h"
#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectFAB1 : public CGameObject
	{
	public:
		CGameObjectFAB1(const char* Name, Vector3& Pos);
		~CGameObjectFAB1();

		void Update(const f32& elapsedTime) { }

	};

	class CGameObjectFAB1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectFAB1Factory();
		~CGameObjectFAB1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);

	};
}
}

#endif //__CGAMEOBJECTFAB1_H__