#ifndef __CGAMEOBJECTGLASSSHOT_H__
#define __CGAMEOBJECTGLASSSHOT_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectGlassShot : public CGameObject
	{
	public:
		CGameObjectGlassShot(const char* Name, Vector3& Pos);
		~CGameObjectGlassShot();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectGlassShotFactory : public IGameObjectFactory
	{
	public:
		CGameObjectGlassShotFactory();
		~CGameObjectGlassShotFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTGLASSSHOT_H__
