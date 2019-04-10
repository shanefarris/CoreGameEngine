#ifndef __CGAMEOBJECTVILLAGE_FENCE2_H__
#define __CGAMEOBJECTVILLAGE_FENCE2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVillage_fence2 : public CGameObject
	{
	public:
		CGameObjectVillage_fence2(const char* Name, Vector3& Pos);
		~CGameObjectVillage_fence2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVillage_fence2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVillage_fence2Factory();
		~CGameObjectVillage_fence2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVILLAGE_FENCE2_H__
