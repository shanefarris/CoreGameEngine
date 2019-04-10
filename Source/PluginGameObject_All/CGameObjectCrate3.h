#ifndef __CGAMEOBJECTCRATE3_H__
#define __CGAMEOBJECTCRATE3_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectCrate3 : public CGameObject
	{
	public:
		CGameObjectCrate3(const char* Name, Vector3& Pos);
		~CGameObjectCrate3();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectCrate3Factory : public IGameObjectFactory
	{
	public:
		CGameObjectCrate3Factory();
		~CGameObjectCrate3Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCRATE3_H__
