#ifndef __NATURE_WORLD_H__
#define __NATURE_WORLD_H__

#include "Defines.h"
#include "OgreVector3.h"

namespace Core
{
	class CGameObject;
	struct HYDRAX;
	struct CAELUM;
	struct TERRAIN_TYPE;
	struct GEO_SET;

namespace Nature
{
	class CSkySystem;
	class CRainSystem;
	class CVegetationSystem;
	class CTerrainSystem;
	class IEnvironment;
	struct TREE_SET;

	class CWorld
	{
	public:
		enum QueryFlags
		{
			ENTITY_MASK       = 1 << 8,
			ROAD_MASK         = 1 << 9,
			INDIFFERENT_MASK  = 1 << 10,
			WATER_MASK        = 1 << 11,
			ENEMY_MASK        = 1 << 12,
		};

		CWorld(Core::HYDRAX* HydraxSettings, Core::CAELUM* CealumSettings, Core::TERRAIN_TYPE* TerrainSettings);
		~CWorld();

		void Shutdown();
		void Pause();
		void Resume();
		void Update(const f32& elapsed);

		inline CSkySystem* GetSkySystem() { return m_Sky; }
		inline CVegetationSystem* GetVegetationSystem() { return m_Vegetation; }
		inline CRainSystem* GetWeatherSystem() { return m_Rain; }
		inline CTerrainSystem* GetTerrainSystem() { return m_Terrain; }

		// Vegetation System
		void AddPagedGeometry(Core::GEO_SET* GeoSet);

		// Optional label name
		String Name;

	private:
		// Systems
		CSkySystem*			m_Sky;
		CVegetationSystem*	m_Vegetation;
		CRainSystem*		m_Rain;
		CTerrainSystem*		m_Terrain;
		Vector3				m_CamPosition;			// Scene stuff
		bool				isPaused;				// Flags

		std::vector<IEnvironment*>	m_Environments;	// List of environmental objects
	};
}
}

#endif // __NATURE_WORLD_H__
