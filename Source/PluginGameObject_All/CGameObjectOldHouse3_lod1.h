#ifndef __CGAMEOBJECTOLDHOUSE3_LOD1_H__
#define __CGAMEOBJECTOLDHOUSE3_LOD1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectOldHouse3_lod1 : public CGameObject
	{
	public:
		CGameObjectOldHouse3_lod1(const char* Name, Vector3& Pos);
		~CGameObjectOldHouse3_lod1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectOldHouse3_lod1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectOldHouse3_lod1Factory();
		~CGameObjectOldHouse3_lod1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTOLDHOUSE3_LOD1_H__
