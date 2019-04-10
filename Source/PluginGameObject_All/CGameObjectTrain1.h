#ifndef __CGAMEOBJECTTRAIN1_H__
#define __CGAMEOBJECTTRAIN1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTrain1 : public CGameObject
	{
	public:
		CGameObjectTrain1(const char* Name, Vector3& Pos);
		~CGameObjectTrain1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTrain1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTrain1Factory();
		~CGameObjectTrain1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTRAIN1_H__
