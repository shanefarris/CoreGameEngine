#ifndef __CGAMEOBJECTELECTRICPOLE_LOD2_H__
#define __CGAMEOBJECTELECTRICPOLE_LOD2_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectElectricPole_lod2 : public CGameObject
	{
	public:
		CGameObjectElectricPole_lod2(const char* Name, Vector3& Pos);
		~CGameObjectElectricPole_lod2();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectElectricPole_lod2Factory : public IGameObjectFactory
	{
	public:
		CGameObjectElectricPole_lod2Factory();
		~CGameObjectElectricPole_lod2Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTELECTRICPOLE_LOD2_H__
