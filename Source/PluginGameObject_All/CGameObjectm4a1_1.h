#ifndef __CGAMEOBJECTM4A1_1_H__
#define __CGAMEOBJECTM4A1_1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectM4a1_1 : public CGameObject
	{
	public:
		CGameObjectM4a1_1(const char* Name, Vector3& Pos);
		~CGameObjectM4a1_1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectM4a1_1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectM4a1_1Factory();
		~CGameObjectM4a1_1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTM4A1_1_H__
