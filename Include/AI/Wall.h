#ifndef __WALL_H__
#define __WALL_H__

#include "Defines.h"
#include "OgreVector3.h"

namespace Core
{
namespace AI
{
	class CORE_EXPORT Wall
	{
	public:
		Wall(const Vector3& From, const Vector3& To, bool LeftNormal);
		~Wall();

		Vector3& GetFrom();
		Vector3& GetTo();
		Vector3& GetNormal();

	private:
		Vector3 m_From;
		Vector3 m_To;
		Vector3 m_Normal;
	};

}
}

#endif // __WALL_H__