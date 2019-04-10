#ifndef __CGAMEOBJECTCHIMNEY_H__
#define __CGAMEOBJECTCHIMNEY_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectChimney : public CGameObject
	{
	public:
		CGameObjectChimney(const char* Name, Vector3& Pos);
		~CGameObjectChimney();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectChimneyFactory : public IGameObjectFactory
	{
	public:
		CGameObjectChimneyFactory();
		~CGameObjectChimneyFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTCHIMNEY_H__
