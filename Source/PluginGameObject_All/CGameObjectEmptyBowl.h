#ifndef __CGAMEOBJECTEMPTYBOWL_H__
#define __CGAMEOBJECTEMPTYBOWL_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectEmptyBowl : public CGameObject
	{
	public:
		CGameObjectEmptyBowl(const char* Name, Vector3& Pos);
		~CGameObjectEmptyBowl();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectEmptyBowlFactory : public IGameObjectFactory
	{
	public:
		CGameObjectEmptyBowlFactory();
		~CGameObjectEmptyBowlFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTEMPTYBOWL_H__
