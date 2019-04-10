#ifndef __CGAMEOBJECTTRAIN1_LOD2_H__
#define __CGAMEOBJECTTRAIN1_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTrain1_lod2 : public CGameObject
	{
	public:
		CGameObjectTrain1_lod2(const char* Name, Vector3& Pos);
		~CGameObjectTrain1_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTrain1_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTrain1_lod2Factory();
		~CGameObjectTrain1_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTRAIN1_LOD2_H__
