#ifndef __NATURE_WATERSYSTEM_H__
#define __NATURE_WATERSYSTEM_H__

#include "Defines.h"
#include "IEnvironment.h"

namespace Hydrax
{
	class Hydrax;

	namespace Module
	{
		class ProjectedGrid;
	}

	namespace Noise
	{
		class Perlin;
	}
}

namespace Core
{
	struct HYDRAX;

	namespace Nature
	{
		class CSkySystem;

		class CWaterSystem : public IEnvironment
		{
		public:
			CWaterSystem();
			~CWaterSystem();

			void Initialise();
			void Initialise(Core::HYDRAX* Settings);
			void Shutdown();
			bool IsInitialised() const { return mInitialised; }
			void Pause();
			void Resume();
			void Update(const f32& elapsed);
			void Save(const String& stage);

			Hydrax::Hydrax* GetHydrax() { return mHydrax; }

		private:
			bool			mInitialised;
			bool			mPaused;
			Entity*			mEntity;
			SceneNode*		mNode;
			Hydrax::Hydrax* mHydrax;
			CSkySystem*		mSky;

			Hydrax::Noise::Perlin*			m_Perlin;
			Hydrax::Module::ProjectedGrid*  m_Module;
		};
	}
}

#endif // __NATURE_WATERSYSTEM_H__
