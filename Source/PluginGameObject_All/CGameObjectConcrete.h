#ifndef __CGAMEOBJECTCONCRETE_H__
#define __CGAMEOBJECTCONCRETE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectConcrete : public CGameObject
	{
	public:
		CGameObjectConcrete(const char* Name, Vector3& Pos);
		~CGameObjectConcrete();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectConcreteFactory : public IGameObjectFactory
	{
	public:
		CGameObjectConcreteFactory();
		~CGameObjectConcreteFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCONCRETE_H__
