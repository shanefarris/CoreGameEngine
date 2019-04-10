#ifndef __CGAMEOBJECTBARREL2_H__
#define __CGAMEOBJECTBARREL2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBarrel2 : public CGameObject
	{
	public:
		CGameObjectBarrel2(const char* Name, Vector3& Pos);
		~CGameObjectBarrel2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBarrel2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectBarrel2Factory();
		~CGameObjectBarrel2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBARREL2_H__
