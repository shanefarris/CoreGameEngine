#ifndef __CGAMEOBJECTPOSTBOX_H__
#define __CGAMEOBJECTPOSTBOX_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectPostBox : public CGameObject
	{
	public:
		CGameObjectPostBox(const char* Name, Vector3& Pos);
		~CGameObjectPostBox();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectPostBoxFactory : public IGameObjectFactory
	{
	public:
		CGameObjectPostBoxFactory();
		~CGameObjectPostBoxFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTPOSTBOX_H__
