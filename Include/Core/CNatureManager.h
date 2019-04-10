#ifndef __CNATUREMANAGER_H__
#define __CNATUREMANAGER_H__

#include "Defines.h"
#include "OgreResourceGroupManager.h"

namespace Ogre
{
	class TerrainGroup;
}

namespace Core
{
	class CGameObject;
	struct CAELUM;
	struct HYDRAX;
	struct TERRAIN_TYPE;
	struct GEO_SET;

namespace Nature
{
	class CWorld;
	class CWaterSystem;

	#define PLANE_ENTITY_NAME "CTerrainSystem_PlaneEntity"
	#define DEFAULT_PLANE_TERRAIN_MATERIAL "Demo/Floor"

	class CORE_EXPORT CNatureManager
	{
	private:
		static CNatureManager*	NatureManager;

	 	SceneManager*		m_SceneManager;
		CWorld*				m_CurrWorld;
		String				m_ResourceGroupName;
		Vector<CWorld*>		m_Worlds;
		TerrainGroup*		m_TerrainGroup;
		CWaterSystem*		m_Water;

		bool Initialize();
		CNatureManager();

	public:
		static CNatureManager* Instance();
		
		~CNatureManager();

		CWorld*			GetWorld();
		String			GetResourceGroupName();
		TerrainGroup*   GetTerrainGroup();
		MovablePlane*	GetBottomPlane();
		f32				GetTerrainHeightAt(const Ray& MouseRay);
		f32				GetTerrainHeightAt(const f32 x, const f32 z);
		Vector3			GetTerrainPosition(const Ray& MouseRay);
		void			SetTerrainGroup(TerrainGroup* Terrain);
		void			SetWaterSystem(CWaterSystem* WaterSystem);
		CWaterSystem*	GetWaterSystem();

		bool CreateWorld(HYDRAX* HydraxSettings, 
						 CAELUM* CealumSettings, 
						 TERRAIN_TYPE* TerrainSettings,
						 String ResourceGroupName = ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
			
		bool DestroyWorld(CWorld* World);
		void Shutdown();

		void Update(const f32& elapsedTime);

		// Vegetation System
		void AddPagedGeometry(GEO_SET* TreeSet);
	};

}
}
#endif // __CGAMEMANAGER_H__
