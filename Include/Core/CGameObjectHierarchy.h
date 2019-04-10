#if 0
#ifndef __CGAMEOBJECT_HIERARCHY_H__
#define __CGAMEOBJECT_HIERARCHY_H__

#include "Defines.h"

namespace Core
{
	class CORE_EXPORT CGameObjectHierarchy
	{
	public:
		CGameObjectHierarchy(const char* Name, const char* Type, const char* MeshName, const Vector3& Position, const Quaternion& Rotation);
		~CGameObjectHierarchy();

		const char* GetName();
		const char* GetType();
		const char* GetMeshName();
		Vector3&	GetPosition();
		Quaternion& GetRotation();
		Vector<CGameObjectHierarchy*>& GetChildren();

		void SetName(const char* Name);
		void SetType(const char* Type);
		void SetMeshName(const char* MeshName);
		void SetPosition(const Vector3& Position);
		void SetRotation(const Quaternion& Rotation);
		void AddChild(CGameObjectHierarchy* Child);

	private:
		String		m_Name;
		String		m_Type;
		String		m_MeshName;
		Vector3		m_Position;
		Quaternion	m_Rotation;
		Vector<CGameObjectHierarchy*> m_Children;
	};
}


#endif // __CGAMEOBJECT_HIERARCHY_H__
#endif