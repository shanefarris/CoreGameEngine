#ifndef __CGAMEOBJECTASSAULTRIFLESIG_H__
#define __CGAMEOBJECTASSAULTRIFLESIG_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAssaultrifleSig : public CGameObject
	{
	public:
		CGameObjectAssaultrifleSig(const char* Name, Vector3& Pos);
		~CGameObjectAssaultrifleSig();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAssaultrifleSigFactory : public IGameObjectFactory
	{
	public:
		CGameObjectAssaultrifleSigFactory();
		~CGameObjectAssaultrifleSigFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTASSAULTRIFLESIG_H__
