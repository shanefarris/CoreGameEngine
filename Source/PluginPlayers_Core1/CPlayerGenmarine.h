#ifndef __CPLAYERGENMARINE_H__
#define __CPLAYERGENMARINE_H__

#include "Defines.h"
#include "CPlayer.h"
#include "Plugins/IPlayerFactory.h"

namespace Core
{
namespace Plugin
{
	class CPlayerGenmarine : public CPlayer
	{
	public:
		CPlayerGenmarine(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CPlayerGenmarine();

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

	class CPlayerGenmarineFactory : public IPlayerFactory
	{
	public:
		CPlayerGenmarineFactory();
		~CPlayerGenmarineFactory();

		CPlayer* CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CPLAYERGENMARINE_H__
