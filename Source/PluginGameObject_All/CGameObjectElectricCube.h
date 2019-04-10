#ifndef __CGAMEOBJECTELECTRICCUBE_H__
#define __CGAMEOBJECTELECTRICCUBE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectElectricCube : public CGameObject
	{
	public:
		CGameObjectElectricCube(const char* Name, Vector3& Pos);
		~CGameObjectElectricCube();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectElectricCubeFactory : public IGameObjectFactory
	{
	public:
		CGameObjectElectricCubeFactory();
		~CGameObjectElectricCubeFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTELECTRICCUBE_H__
