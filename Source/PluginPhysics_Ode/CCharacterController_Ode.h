#ifndef __CCHARACTERCONTROL_ODE_H__
#define __CCHARACTERCONTROL_ODE_H__

#include "Defines.h"
#include "ICharacterController.h"

namespace Ode
{
	class Space;
	class Body;
	class CapsuleGeometry;
	class TransformGeometry;
}

namespace Core
{
	class CGameObject;

namespace Physics
{	
	class CPhysicsStrategy_Ode;
	
	class CCharacterController_Ode : public ICharacterController
	{
	public:
		CCharacterController_Ode(CPlayer* Player, Ode::Space* Space);
		~CCharacterController_Ode();

		bool InitCharacterControllers();
		void UpdateControllers();
		u32 MoveCharacter(const Vector3& dispVector, f32 elapsedTime, u32 collisionGroups, f32 heightDelta);
		Vector3 GetCharacterPos();
		void SetCharacterPos(const Vector3& pos);
		bool ResetCharacterPos(const Vector3& pos);
		bool UpdateCharacterExtents(bool& increase);
		void SetEnabled(bool isEnabled);
		
	private:
		bool InitCharacterControllers(const Vector3& Size);

		CPhysicsStrategy_Ode*	m_Physics;
		CPlayer*				m_Player;
		Ode::Space*			m_Space;
		Ode::Body*			m_Body;
		Ode::Body*			m_FeetBody;
		Ode::Body*			m_TorsoBody;

		Ode::TransformGeometry* m_TorsoTrans;
		Ode::CapsuleGeometry*	m_TorsoGeom;
	};
	
}
}


#endif // __CCHARACTERCONTROL_ODE_H__
