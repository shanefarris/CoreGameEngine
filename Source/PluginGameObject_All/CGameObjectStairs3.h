#ifndef __CGAMEOBJECTSTAIRS3_H__
#define __CGAMEOBJECTSTAIRS3_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStairs3 : public CGameObject
	{
	public:
		CGameObjectStairs3(const char* Name, Vector3& Pos);
		~CGameObjectStairs3();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStairs3Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStairs3Factory();
		~CGameObjectStairs3Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTAIRS3_H__
