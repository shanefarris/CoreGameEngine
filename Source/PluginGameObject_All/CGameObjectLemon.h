#ifndef __CGAMEOBJECTLEMON_H__
#define __CGAMEOBJECTLEMON_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLemon : public CGameObject
	{
	public:
		CGameObjectLemon(const char* Name, Vector3& Pos);
		~CGameObjectLemon();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLemonFactory : public IGameObjectFactory
	{
	public:
		CGameObjectLemonFactory();
		~CGameObjectLemonFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLEMON_H__
