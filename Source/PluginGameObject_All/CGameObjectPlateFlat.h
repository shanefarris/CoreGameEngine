#ifndef __CGAMEOBJECTPLATEFLAT_H__
#define __CGAMEOBJECTPLATEFLAT_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectPlateFlat : public CGameObject
	{
	public:
		CGameObjectPlateFlat(const char* Name, Vector3& Pos);
		~CGameObjectPlateFlat();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectPlateFlatFactory : public IGameObjectFactory
	{
	public:
		CGameObjectPlateFlatFactory();
		~CGameObjectPlateFlatFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTPLATEFLAT_H__
