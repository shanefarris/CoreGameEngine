#ifndef __CGAMEOBJECTSTONE3_H__
#define __CGAMEOBJECTSTONE3_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone3 : public CGameObject
	{
	public:
		CGameObjectStone3(const char* Name, Vector3& Pos);
		~CGameObjectStone3();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone3Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone3Factory();
		~CGameObjectStone3Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE3_H__
