#ifndef __CGAMEOBJECTASTARNODE_H__
#define __CGAMEOBJECTASTARNODE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectAStarNode : public CGameObject
	{
	public:
		CGameObjectAStarNode(const char* Name, Vector3& Pos);
		~CGameObjectAStarNode();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectAStarNodeFactory : public IGameObjectFactory
	{
	public:
		CGameObjectAStarNodeFactory();
		~CGameObjectAStarNodeFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTASTARNODE_H__
