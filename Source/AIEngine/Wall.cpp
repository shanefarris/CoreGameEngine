#include "Wall.h"

using namespace Core;
using namespace Core::AI;

Wall::Wall(const Vector3& From, const Vector3& To, bool LeftNormal)
{
	// Explicit copy
	m_From = Vector3(From.x, From.y, From.z);
	m_To = Vector3(To.x, To.y, To.z);
	m_Normal = (m_To - m_From);

	Quaternion q;
	if (LeftNormal)
		q.FromAngleAxis(Radian(Math::fDeg2Rad * 90), Vector3::UNIT_Y);
	else
		q.FromAngleAxis(Radian(Math::fDeg2Rad * -90), Vector3::UNIT_Y);

	m_Normal = q * m_Normal;
	m_Normal.y = 0;
	m_Normal.normalise();
}

Wall::~Wall()
{
}

Vector3& Wall::GetFrom()
{
	return m_From;
}

Vector3& Wall::GetTo()
{
	return m_To;
}

Vector3& Wall::GetNormal()
{
	return m_Normal;
}