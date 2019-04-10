#ifndef __CGAMEOBJECTCONSTRUCT_H__
#define __CGAMEOBJECTCONSTRUCT_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectConstruct : public CGameObject
	{
	public:
		CGameObjectConstruct(const char* Name, Vector3& Pos);
		~CGameObjectConstruct();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectConstructFactory : public IGameObjectFactory
	{
	public:
		CGameObjectConstructFactory();
		~CGameObjectConstructFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCONSTRUCT_H__
