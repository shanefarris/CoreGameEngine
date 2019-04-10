#ifndef __CGAMEOBJECTLAMPPOST_H__
#define __CGAMEOBJECTLAMPPOST_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLampPost : public CGameObject
	{
	public:
		CGameObjectLampPost(const char* Name, Vector3& Pos);
		~CGameObjectLampPost();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLampPostFactory : public IGameObjectFactory
	{
	public:
		CGameObjectLampPostFactory();
		~CGameObjectLampPostFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLAMPPOST_H__
