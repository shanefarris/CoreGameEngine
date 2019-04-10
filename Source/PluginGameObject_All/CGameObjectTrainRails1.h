#ifndef __CGAMEOBJECTTRAINRAILS1_H__
#define __CGAMEOBJECTTRAINRAILS1_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectTrainRails1 : public CGameObject
	{
	public:
		CGameObjectTrainRails1(const char* Name, Vector3& Pos);
		~CGameObjectTrainRails1();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectTrainRails1Factory : public IGameObjectFactory
	{
	public:
		CGameObjectTrainRails1Factory();
		~CGameObjectTrainRails1Factory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTTRAINRAILS1_H__
