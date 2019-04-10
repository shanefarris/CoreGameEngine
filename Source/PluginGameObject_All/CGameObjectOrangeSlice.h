#ifndef __CGAMEOBJECTORANGESLICE_H__
#define __CGAMEOBJECTORANGESLICE_H__

#include "CGameObject.h"
#include "Plugins/IGameObjectFactory.h"

namespace Core
{
namespace Plugin
{
	class CGameObjectOrangeSlice : public CGameObject
	{
	public:
		CGameObjectOrangeSlice(const char* Name, Vector3& Pos);
		~CGameObjectOrangeSlice();

		void Update(const f32& elapsedTime);

	};

	class CGameObjectOrangeSliceFactory : public IGameObjectFactory
	{
	public:
		CGameObjectOrangeSliceFactory();
		~CGameObjectOrangeSliceFactory();

		CGameObject* CreateObject(const char* Name, Vector3& Pos);
	};
}
}

#endif // __CGAMEOBJECTORANGESLICE_H__
