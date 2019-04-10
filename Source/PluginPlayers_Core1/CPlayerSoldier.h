#ifndef __CPLAYERSOLDIER_H__
#define __CPLAYERSOLDIER_H__

#include "Defines.h"
#include "CPlayer.h"
#include "Plugins/IPlayerFactory.h"

namespace Core
{
namespace Plugin
{
	class CPlayerSoldier : public CPlayer
	{
	public:
		CPlayerSoldier(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CPlayerSoldier();

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

	class CPlayerSoldierFactory : public IPlayerFactory
	{
	public:
		CPlayerSoldierFactory();
		~CPlayerSoldierFactory();

		CPlayer* CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CPLAYERSOLDIER_H__
