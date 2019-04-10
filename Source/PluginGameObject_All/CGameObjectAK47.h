#ifndef __CGAMEOBJECTAK47_H__
#define __CGAMEOBJECTAK47_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAK47 : public CGameObject
	{
	public:
		CGameObjectAK47(const char* Name, Vector3& Pos);
		~CGameObjectAK47();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAK47Factory : public IGameObjectFactory
	{
	public:
		CGameObjectAK47Factory();
		~CGameObjectAK47Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTAK47_H__
