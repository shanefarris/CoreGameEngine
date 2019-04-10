#ifndef __CGAMEOBJECTVILLAGE_FENCE1_H__
#define __CGAMEOBJECTVILLAGE_FENCE1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVillage_fence1 : public CGameObject
	{
	public:
		CGameObjectVillage_fence1(const char* Name, Vector3& Pos);
		~CGameObjectVillage_fence1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVillage_fence1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVillage_fence1Factory();
		~CGameObjectVillage_fence1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVILLAGE_FENCE1_H__
