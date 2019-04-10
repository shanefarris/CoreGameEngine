// Just a simple implementation of rendering bullet holes

#ifndef __CBULLETHOLES_H__
#define __CBULLETHOLES_H__

#include "Defines.h"

namespace Core
{
	class CBulletHoles
	{
	private:
		static CBulletHoles* BulletHoles;
		u32 m_BulletHoleCount;
	
		CBulletHoles();

	public:
		static CBulletHoles* Instance();

		void AddBulletHole(const Vector3& Normal, const Vector3& Position);
		void ResetBulletHoles(){ m_BulletHoleCount = 0; }
	};
}
#endif // __CBULLETHOLES_H__