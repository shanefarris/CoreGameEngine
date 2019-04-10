#ifndef __CGAMEOBJECTPLATEDEEP_H__
#define __CGAMEOBJECTPLATEDEEP_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectPlateDeep : public CGameObject
	{
	public:
		CGameObjectPlateDeep(const char* Name, Vector3& Pos);
		~CGameObjectPlateDeep();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectPlateDeepFactory : public IGameObjectFactory
	{
	public:
		CGameObjectPlateDeepFactory();
		~CGameObjectPlateDeepFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTPLATEDEEP_H__
