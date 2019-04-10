#ifndef __CGAMEOBJECTELECTRICPOLE_H__
#define __CGAMEOBJECTELECTRICPOLE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectElectricPole : public CGameObject
	{
	public:
		CGameObjectElectricPole(const char* Name, Vector3& Pos);
		~CGameObjectElectricPole();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectElectricPoleFactory : public IGameObjectFactory
	{
	public:
		CGameObjectElectricPoleFactory();
		~CGameObjectElectricPoleFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTELECTRICPOLE_H__
