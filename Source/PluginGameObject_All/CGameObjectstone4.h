#ifndef __CGAMEOBJECTSTONE4_H__
#define __CGAMEOBJECTSTONE4_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectStone4 : public CGameObject
	{
	public:
		CGameObjectStone4(const char* Name, Vector3& Pos);
		~CGameObjectStone4();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectStone4Factory : public IGameObjectFactory
	{
	public:
		CGameObjectStone4Factory();
		~CGameObjectStone4Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSTONE4_H__
