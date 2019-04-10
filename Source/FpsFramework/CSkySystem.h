#ifndef __NATURE_SKYSYSTEM_H__
#define __NATURE_SKYSYSTEM_H__

#include "Defines.h"
#include "IEnvironment.h"

namespace Caelum
{
	class CaelumSystem;
	class PrecipitationController;
}

namespace Core
{
	struct CAELUM;

namespace Nature
{
	class CWorld;

	class CSkySystem : public IEnvironment
	{
	public:
		CSkySystem();
		~CSkySystem();

		void Initialise();
		void Initialise(Core::CAELUM* CealumSettings);
		void Shutdown();
		bool IsInitialised() const;
		void Pause();
		void Resume();
		void Update(const f32& elapsed);
		void CameraChanged();
		bool IsNight() const;

		Vector3		GetSunDirection() const;
		Vector3		GetMoonDirection() const;
		ColourValue GetSunColour() const;
		ColourValue GetSunLightColour() const;
		ColourValue GetMoonColour() const;
		ColourValue GetMoonLightColour() const;

		Caelum::CaelumSystem* GetCaelum() { return m_CaelumSystem; }

	private:
		friend class RainSystem;

		Caelum::CaelumSystem*	m_CaelumSystem;
		Core::Nature::CWorld*	m_World;
		f32						mSpeedFactor;
		bool					mPaused;
	};
}
}

#endif // __NATURE_SKYSYSTEM_H__
