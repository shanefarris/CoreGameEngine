#ifndef __CGAMEOBJECTAK47_CLIP_H__
#define __CGAMEOBJECTAK47_CLIP_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAK47_clip : public CGameObject
	{
	public:
		CGameObjectAK47_clip(const char* Name, Vector3& Pos);
		~CGameObjectAK47_clip();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAK47_clipFactory : public IGameObjectFactory
	{
	public:
		CGameObjectAK47_clipFactory();
		~CGameObjectAK47_clipFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTAK47_CLIP_H__
