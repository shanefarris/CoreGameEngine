#ifndef __CGAMEOBJECTSPHERE_H__
#define __CGAMEOBJECTSPHERE_H__

#include "Defines.h"
#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectSphere : public CGameObject
	{
	public:
		CGameObjectSphere(const char* Name, Vector3& Pos);
		~CGameObjectSphere();

		void Update(const f32& elapsedTime) { }

	};

	class CGameObjectSphereFactory : public IGameObjectFactory
	{
	public:
		CGameObjectSphereFactory();
		~CGameObjectSphereFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);

	};

	class CGameObjectSpawnPoint : public CGameObject
	{
	public:
		CGameObjectSpawnPoint(const char* Name, Vector3& Pos);
		~CGameObjectSpawnPoint();

		void Update(const f32& elapsedTime) { }

	};

	class CGameObjectSpawnPointFactory : public IGameObjectFactory
	{
	public:
		CGameObjectSpawnPointFactory();
		~CGameObjectSpawnPointFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);

	};
}
}

#endif //__CGAMEOBJECTSPHERE_H__