#ifndef __CGAMEOBJECTBOX1_H__
#define __CGAMEOBJECTBOX1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBox1 : public CGameObject
	{
	public:
		CGameObjectBox1(const char* Name, Vector3& Pos);
		~CGameObjectBox1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBox1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectBox1Factory();
		~CGameObjectBox1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBOX1_H__
