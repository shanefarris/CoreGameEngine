#ifndef __CGAMEOBJECTBUSH2_H__
#define __CGAMEOBJECTBUSH2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBush2 : public CGameObject
	{
	public:
		CGameObjectBush2(const char* Name, Vector3& Pos);
		~CGameObjectBush2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBush2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectBush2Factory();
		~CGameObjectBush2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBUSH2_H__
