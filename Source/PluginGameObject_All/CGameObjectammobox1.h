#ifndef __CGAMEOBJECTAMMOBOX1_H__
#define __CGAMEOBJECTAMMOBOX1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAmmobox1 : public CGameObject
	{
	public:
		CGameObjectAmmobox1(const char* Name, Vector3& Pos);
		~CGameObjectAmmobox1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAmmobox1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectAmmobox1Factory();
		~CGameObjectAmmobox1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTAMMOBOX1_H__
