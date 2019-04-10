#ifndef __CGAMEOBJECTAPPLERED_H__
#define __CGAMEOBJECTAPPLERED_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAppleRed : public CGameObject
	{
	public:
		CGameObjectAppleRed(const char* Name, Vector3& Pos);
		~CGameObjectAppleRed();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAppleRedFactory : public IGameObjectFactory
	{
	public:
		CGameObjectAppleRedFactory();
		~CGameObjectAppleRedFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTAPPLERED_H__
