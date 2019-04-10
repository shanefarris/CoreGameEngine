#ifndef __CGAMEOBJECTAPPLEGREEN_H__
#define __CGAMEOBJECTAPPLEGREEN_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAppleGreen : public CGameObject
	{
	public:
		CGameObjectAppleGreen(const char* Name, Vector3& Pos);
		~CGameObjectAppleGreen();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAppleGreenFactory : public IGameObjectFactory
	{
	public:
		CGameObjectAppleGreenFactory();
		~CGameObjectAppleGreenFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTAPPLEGREEN_H__
