#ifndef __CGAMEOBJECTBOWLSOUP_H__
#define __CGAMEOBJECTBOWLSOUP_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectBowlSoup : public CGameObject
	{
	public:
		CGameObjectBowlSoup(const char* Name, Vector3& Pos);
		~CGameObjectBowlSoup();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectBowlSoupFactory : public IGameObjectFactory
	{
	public:
		CGameObjectBowlSoupFactory();
		~CGameObjectBowlSoupFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTBOWLSOUP_H__
