#ifndef __ICHARACTERCONTROL_H__
#define __ICHARACTERCONTROL_H__

#include "Defines.h"

namespace Core
{
	class CPlayer;

namespace Physics
{

	enum E_GAME_GROUP
	{
		GROUP_NON_COLLIDABLE,
		GROUP_COLLIDABLE_NON_PUSHABLE,
		GROUP_COLLIDABLE_PUSHABLE,
	};
		
	class ICharacterController
	{
	public:
		virtual ~ICharacterController() { }

		virtual void UpdateControllers() = 0;

		virtual bool InitCharacterControllers() = 0;
		virtual u32 MoveCharacter(const Vector3& dispVector, f32 elapsedTime, u32 collisionGroups, f32 heightDelta) = 0;
		virtual Vector3 GetCharacterPos() = 0;
		virtual void SetCharacterPos(const Vector3& pos) = 0;
		virtual bool ResetCharacterPos(const Vector3& pos) = 0;
		virtual bool UpdateCharacterExtents(bool& increase) = 0;
		virtual void SetEnabled(bool isEnabled) = 0;
	};
	
}
}


#endif // __ICHARACTERCONTROL_H__

