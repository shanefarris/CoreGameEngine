#ifndef __CGAMEOBJECTSHOOTINGPLACE_H__
#define __CGAMEOBJECTSHOOTINGPLACE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectShootingPlace : public CGameObject
	{
	public:
		CGameObjectShootingPlace(const char* Name, Vector3& Pos);
		~CGameObjectShootingPlace();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectShootingPlaceFactory : public IGameObjectFactory
	{
	public:
		CGameObjectShootingPlaceFactory();
		~CGameObjectShootingPlaceFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSHOOTINGPLACE_H__
