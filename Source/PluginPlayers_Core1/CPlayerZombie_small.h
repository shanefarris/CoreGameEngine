#ifndef __CPLAYERZOMBIE_SMALL_H__
#define __CPLAYERZOMBIE_SMALL_H__

#include "Defines.h"
#include "CPlayer.h"
#include "Plugins/IPlayerFactory.h"

namespace Core
{
namespace Plugin
{
	class CPlayerZombie_small : public CPlayer
	{
	public:
		CPlayerZombie_small(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CPlayerZombie_small();

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

	class CPlayerZombie_smallFactory : public IPlayerFactory
	{
	public:
		CPlayerZombie_smallFactory();
		~CPlayerZombie_smallFactory();

		CPlayer* CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CPLAYERZOMBIE_SMALL_H__
