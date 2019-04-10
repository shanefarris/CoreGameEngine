#ifndef __CGAMEOBJECTFORKBIG_H__
#define __CGAMEOBJECTFORKBIG_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectForkBig : public CGameObject
	{
	public:
		CGameObjectForkBig(const char* Name, Vector3& Pos);
		~CGameObjectForkBig();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectForkBigFactory : public IGameObjectFactory
	{
	public:
		CGameObjectForkBigFactory();
		~CGameObjectForkBigFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTFORKBIG_H__
