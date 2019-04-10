#ifndef __CGAMEOBJECTVILLAGE_FENCE3_H__
#define __CGAMEOBJECTVILLAGE_FENCE3_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVillage_fence3 : public CGameObject
	{
	public:
		CGameObjectVillage_fence3(const char* Name, Vector3& Pos);
		~CGameObjectVillage_fence3();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVillage_fence3Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVillage_fence3Factory();
		~CGameObjectVillage_fence3Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVILLAGE_FENCE3_H__
