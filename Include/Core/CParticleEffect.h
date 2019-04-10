// Superclass for all effects in the game with a timer. 
#ifndef __CPARTICALEFFECT_H__
#define __CPARTICALEFFECT_H__

#include "Defines.h"

namespace Core
{
namespace Effects
{
	class CORE_EXPORT CParticleEffect
	{
	public:
		CParticleEffect();

		virtual void StartTimer() = 0;							// Every effect has its own way of starting. Particle Systems start emitting, Billboards->setVisible etc etc
		virtual void Update(const f32& timeSinceLastFrame);		// Updates the timer of the effect. If the timer is bigger or equal with the m_tTimerReset, then the reset function will be called.

		static void UpdateAll(const f32& timeSinceLastFrame);	// Static function that updates all dynamic effects
		static void AddDynamicEffect(CParticleEffect* e);		// Adds an effect to the m_DynamicEffects vector. 

		inline f32  GetTimer() { return m_Timer; }
		inline void SetTimer(const f32& Timer) { m_Timer = Timer; }

		inline void SetPosition(Vector3& Position);
		inline void SetPosition(const f32& X, const f32& Y, const f32& Z);

		String LabelName;		// Particle type name
		String ParticleName;	// Unquie name of the particle

	protected:
		SceneNode*		 m_SceneNode;

		f32 m_Timer;
		f32 m_TimerReset;
		static Vector<CParticleEffect*> m_DynamicEffects;		// See UpdateAll. 

		virtual void ResetTimer() = 0;							// Every effect has its own way of resetting the effect. 
	};
}
}

#endif // __CPARTICALEFFECT_H__