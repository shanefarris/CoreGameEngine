#ifndef __CGAMEOBJECTTRAINRAILS1_LOD2_H__
#define __CGAMEOBJECTTRAINRAILS1_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTrainRails1_lod2 : public CGameObject
	{
	public:
		CGameObjectTrainRails1_lod2(const char* Name, Vector3& Pos);
		~CGameObjectTrainRails1_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTrainRails1_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTrainRails1_lod2Factory();
		~CGameObjectTrainRails1_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTRAINRAILS1_LOD2_H__
