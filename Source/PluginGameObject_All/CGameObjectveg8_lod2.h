#ifndef __CGAMEOBJECTVEG8_LOD2_H__
#define __CGAMEOBJECTVEG8_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectVeg8_lod2 : public CGameObject
	{
	public:
		CGameObjectVeg8_lod2(const char* Name, Vector3& Pos);
		~CGameObjectVeg8_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectVeg8_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectVeg8_lod2Factory();
		~CGameObjectVeg8_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTVEG8_LOD2_H__
