#ifndef __CGAMEOBJECTRAZOR_H__
#define __CGAMEOBJECTRAZOR_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectRazor : public CGameObject
	{
	public:
		CGameObjectRazor(const char* Name, Vector3& Pos);
		~CGameObjectRazor();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectRazorFactory : public IGameObjectFactory
	{
	public:
		CGameObjectRazorFactory();
		~CGameObjectRazorFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTRAZOR_H__
