#ifndef __CGAMEOBJECTSPOONBIG_H__
#define __CGAMEOBJECTSPOONBIG_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectSpoonBig : public CGameObject
	{
	public:
		CGameObjectSpoonBig(const char* Name, Vector3& Pos);
		~CGameObjectSpoonBig();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectSpoonBigFactory : public IGameObjectFactory
	{
	public:
		CGameObjectSpoonBigFactory();
		~CGameObjectSpoonBigFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSPOONBIG_H__
