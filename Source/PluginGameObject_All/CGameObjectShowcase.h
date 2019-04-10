#ifndef __CGAMEOBJECTSHOWCASE_H__
#define __CGAMEOBJECTSHOWCASE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectShowcase : public CGameObject
	{
	public:
		CGameObjectShowcase(const char* Name, Vector3& Pos);
		~CGameObjectShowcase();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectShowcaseFactory : public IGameObjectFactory
	{
	public:
		CGameObjectShowcaseFactory();
		~CGameObjectShowcaseFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTSHOWCASE_H__
