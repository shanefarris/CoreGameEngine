#ifndef __CGAMEOBJECTBARREL01_H__
#define __CGAMEOBJECTBARREL01_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBarrel01 : public CGameObject
	{
	public:
		CGameObjectBarrel01(const char* Name, Vector3& Pos);
		~CGameObjectBarrel01();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBarrel01Factory : public IGameObjectFactory
	{
	public:
		CGameObjectBarrel01Factory();
		~CGameObjectBarrel01Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBARREL01_H__
