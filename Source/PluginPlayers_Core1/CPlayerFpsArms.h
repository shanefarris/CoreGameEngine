#ifndef __CPLAYERFPSARMS_H__
#define __CPLAYERFPSARMS_H__


#include "Defines.h"
#include "CPlayer.h"
#include "Plugins/IPlayerFactory.h"

namespace Core
{
namespace Plugin
{
	class CPlayerFpsArms : public CPlayer
	{
	public:
		CPlayerFpsArms(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CPlayerFpsArms();

		void Update(const f32& elapsedTime);

		// Events
		void OnShotFired();
		void OnMove(const f32& elapsedTime) { }

	private:
		void SetupMapping();

		void UpdatePhysics(const f32& elapsedTime);
		void UpdateMovement();
		void UpdateAnimationState(const f32& elapsedTime);
		void UpdateAnimation(const f32& elapsedTime);
	};

	class CPlayerFpsArmsFactory : public IPlayerFactory
	{
	public:
		CPlayerFpsArmsFactory();
		~CPlayerFpsArmsFactory();

		CPlayer* CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}

#endif // __CPLAYERFPSARMS_H__