#ifndef __CGAMEOBJECTLEMONSLICE_H__
#define __CGAMEOBJECTLEMONSLICE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLemonSlice : public CGameObject
	{
	public:
		CGameObjectLemonSlice(const char* Name, Vector3& Pos);
		~CGameObjectLemonSlice();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLemonSliceFactory : public IGameObjectFactory
	{
	public:
		CGameObjectLemonSliceFactory();
		~CGameObjectLemonSliceFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLEMONSLICE_H__
