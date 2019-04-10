#ifndef __CGAMEOBJECTKNIFEBIG_H__
#define __CGAMEOBJECTKNIFEBIG_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectKnifeBig : public CGameObject
	{
	public:
		CGameObjectKnifeBig(const char* Name, Vector3& Pos);
		~CGameObjectKnifeBig();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectKnifeBigFactory : public IGameObjectFactory
	{
	public:
		CGameObjectKnifeBigFactory();
		~CGameObjectKnifeBigFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTKNIFEBIG_H__
