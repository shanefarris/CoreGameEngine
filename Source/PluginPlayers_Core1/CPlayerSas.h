#ifndef __CPLAYERSAS_H__
#define __CPLAYERSAS_H__

#include "Defines.h"
#include "CPlayer.h"
#include "Plugins/IPlayerFactory.h"

namespace Core
{
namespace Plugin
{
	class CPlayerSas : public CPlayer
	{
	public:
		CPlayerSas(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CPlayerSas();

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

	class CPlayerSasFactory : public IPlayerFactory
	{
	public:
		CPlayerSasFactory();
		~CPlayerSasFactory();

		CPlayer* CreatePlayer(const char* Name, Physics::IPhysicsStrategy* PhysicsStrategy);
	};
}
}
#endif // __CPLAYERSAS_H__
