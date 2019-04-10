#ifndef __CGAMEOBJECTROOF_H__
#define __CGAMEOBJECTROOF_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectRoof : public CGameObject
	{
	public:
		CGameObjectRoof(const char* Name, Vector3& Pos);
		~CGameObjectRoof();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectRoofFactory : public IGameObjectFactory
	{
	public:
		CGameObjectRoofFactory();
		~CGameObjectRoofFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTROOF_H__
