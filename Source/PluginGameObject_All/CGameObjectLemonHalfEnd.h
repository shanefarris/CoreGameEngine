#ifndef __CGAMEOBJECTLEMONHALFEND_H__
#define __CGAMEOBJECTLEMONHALFEND_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectLemonHalfEnd : public CGameObject
	{
	public:
		CGameObjectLemonHalfEnd(const char* Name, Vector3& Pos);
		~CGameObjectLemonHalfEnd();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectLemonHalfEndFactory : public IGameObjectFactory
	{
	public:
		CGameObjectLemonHalfEndFactory();
		~CGameObjectLemonHalfEndFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTLEMONHALFEND_H__
