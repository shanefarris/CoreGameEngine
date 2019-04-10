#ifndef __NATURE_TERRAINSYSTEM_H__
#define __NATURE_TERRAINSYSTEM_H__

#include "Defines.h"
#include "Core/Structures.h"

#ifdef PAGING
#include "Paging/OgrePageManager.h"
#endif

namespace Ogre
{
	class Camera;
	class SceneManager;
	class TerrainPaging;
	class PageManager;
	class TerrainGroup;
	class TerrainGlobalOptions;
}

namespace Core
{
	class CGameObject;
	struct HEIGHT_TERRAIN;
	struct PAGED_TERRAIN;
	struct PLANE_TERRAIN;
	struct TERRAIN_TYPE;

	namespace Nature
	{
		enum TERRAIN_TYPE
		{
			TT_HEIGHT  = 0,
			TT_PAGED   = 1,
			TT_PLANE   = 3,
		};

		class CPagedTerrain;
		class TerrainRaySceneQueryListener;

		class CTerrainSystem
		{
		public:
			CTerrainSystem();
			~CTerrainSystem();

			void Initialise();
			void Shutdown();

			inline bool IsInitialised() const { return mInitialised; }

			Vector3 GetExtents() const { return mExtents; }
			Vector3 GetScale() const { return mScaling; }
			s32 GetPageSize() const { return mPageSize; }
			s32 GetTileSize() const { return mTileSize; }
			MovablePlane* GetPlane() { return m_Plane; }
			f32 GetHeightAt(const f32& x, const f32& z);

			void Load(Core::TERRAIN_TYPE* TerrainInfo);

		private:
			void LoadHeightTerrain(Core::HEIGHT_TERRAIN* TerrainInfo);	// Load height map (removed) (kept in for future engines (ogre doesn't support this anymore))
			void LoadPagedTerrain(Core::PAGED_TERRAIN* TerrainInfo);	// Load paged terrain
			void LoadPlaneTerrain(Core::PLANE_TERRAIN* TerrainInfo);	// Load plane terrain

			// Flags
			bool mInitialised;

			// Terrain
			Vector3			mExtents;
			Vector3			mScaling;
			s32				mPageSize;
			s32				mTileSize;
			CPagedTerrain*	m_PagedTerrain;			// Only for paged terrain
			MovablePlane*	m_Plane;				// Only for plane
			TERRAIN_TYPE	TerrainType;
		};

		class CPagedTerrain
		{
		public:
			CPagedTerrain(const PAGED_TERRAIN& TerrainInfo);
			~CPagedTerrain();

			void SaveTerrains(bool onlyIfModified);
			void ConfigureTerrainDefaults();
			void SetupContent();

			TerrainGroup* GetTerrainGroup() { return m_TerrainGroup; }

		private:
			bool					mPaging;
			SceneManager*			mSceneMgr;
			TerrainPaging*			mTerrainPaging;
			PageManager*			mPageManager;
			Camera*					mCamera;
			PAGED_TERRAIN			m_TerrainInfo;
			TerrainGlobalOptions*	m_terrainGlobalOptions;
			TerrainGroup*			m_TerrainGroup;

			void DefineTerrain(long x, long y, bool flat = false);

		#ifdef PAGING
		// This class just pretends to provide prcedural page content to avoid page loading
		class DummyPageProvider : public PageProvider
		{
		public:
			bool prepareProceduralPage(Page* page, PagedWorldSection* section);
			bool loadProceduralPage(Page* page, PagedWorldSection* section);
			bool unloadProceduralPage(Page* page, PagedWorldSection* section);
			bool unprepareProceduralPage(Page* page, PagedWorldSection* section);
		};
		DummyPageProvider mDummyPageProvider;
		#endif
		};

	}
}

#endif // __NATURE_TERRAINSYSTEM_H__
