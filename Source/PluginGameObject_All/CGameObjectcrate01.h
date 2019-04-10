#ifndef __CGAMEOBJECTCRATE01_H__
#define __CGAMEOBJECTCRATE01_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectCrate01 : public CGameObject
	{
	public:
		CGameObjectCrate01(const char* Name, Vector3& Pos);
		~CGameObjectCrate01();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectCrate01Factory : public IGameObjectFactory
	{
	public:
		CGameObjectCrate01Factory();
		~CGameObjectCrate01Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCRATE01_H__
