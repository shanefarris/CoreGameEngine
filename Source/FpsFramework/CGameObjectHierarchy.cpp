#if 0
#include "CGameObjectHierarchy.h"

using namespace Core;

CGameObjectHierarchy::CGameObjectHierarchy(const char* Name, const char* Type, const char* MeshName, const Vector3& Position, const Quaternion& Rotation)
	: m_Name(Name),
	m_Type(Type),
	m_MeshName(MeshName),
	m_Position(Position),
	m_Rotation(Rotation)
{
}

CGameObjectHierarchy::~CGameObjectHierarchy()
{
}

const char* CGameObjectHierarchy::GetName()
{
	return m_Name.c_str();
}

const char* CGameObjectHierarchy::GetType()
{
	return m_Type.c_str();
}

const char* CGameObjectHierarchy::GetMeshName()
{
	return m_MeshName.c_str();
}

Vector3& CGameObjectHierarchy::GetPosition()
{
	return m_Position;
}

Quaternion& CGameObjectHierarchy::GetRotation()
{
	return m_Rotation;
}

Vector<CGameObjectHierarchy*>& CGameObjectHierarchy::GetChildren()
{
	return m_Children;
}

void CGameObjectHierarchy::SetName(const char* Name)
{
	m_Name = Name;
}

void CGameObjectHierarchy::SetType(const char* Type)
{
	m_Type = Type;
}

void CGameObjectHierarchy::SetMeshName(const char* MeshName)
{
	m_MeshName = MeshName;
}

void CGameObjectHierarchy::SetPosition(const Vector3& Position)
{
	m_Position = Position;
}

void CGameObjectHierarchy::SetRotation(const Quaternion& Rotation)
{
	m_Rotation = Rotation;
}

void CGameObjectHierarchy::AddChild(CGameObjectHierarchy* Child)
{
	m_Children.push_back(Child);
}
#endif