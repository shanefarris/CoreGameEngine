#include "CWorld.h"
#include "CTerrainSystem.h"
#include "CGameManager.h"
#include "CNatureManager.h"
#include "CCameraManager.h"
#include "Structures.h"
#include "IO/CoreLogging.h"

#include "OgreRay.h"
#include "OgreSceneManager.h"
#include "OgreStaticGeometry.h"
#include "OgreMeshManager.h"
#include "OgreEntity.h"

// Turned paging off for now because the physics needs the data to be loaded, this will need to be fixed.
//#define PAGING
#include "Terrain/OgreTerrain.h"
#include "Terrain/OgreTerrainGroup.h"
#include "Terrain/OgreTerrainQuadTreeNode.h"
#include "Terrain/OgreTerrainMaterialGeneratorA.h"
#include "Terrain/OgreTerrainPaging.h"
#include "Terrain/OgreTerrainPagedWorldSection.h"
#include "Paging/OgrePageManager.h"
#include "Paging/OgrePagedWorld.h"
#include "Paging/OgrePagedWorldSection.h"

#include "OgreMaterialManager.h"

#define COVERAGE_MAPS       2
#define SPLATTING_TEXTURES  8

namespace Core
{
	namespace Nature
	{
		class CORE_EXPORT TerrainRaySceneQueryListener : public RaySceneQueryListener
		{
		public:
			f32 resultDistance;

			inline bool queryResult(SceneQuery::WorldFragment* fragment, f32 distance)
			{
				resultDistance = distance;
				return false;
			}

			inline bool queryResult(MovableObject* obj, f32 distance)
			{
				resultDistance = distance;
				return false;
			}
		};
	}
}

using namespace Core::Nature;

CTerrainSystem::CTerrainSystem() 
	: mInitialised(false), 
	mExtents(Vector3::ZERO), 
	mScaling(Vector3::ZERO), 
	mPageSize(0), 
	mTileSize(0),
	m_PagedTerrain(nullptr),
	m_Plane(nullptr)
{
}

CTerrainSystem::~CTerrainSystem()
{
	// Always Shutdown
	Shutdown();
}

void CTerrainSystem::Initialise()
{
	CORE_LOG("*** Initialising terrain ***");

	SceneManager* sceneManager = CGameManager::Instance()->GetSceneManager();

	// We're initialised
	mInitialised = true;
}

void CTerrainSystem::Shutdown()
{
	try
	{
		CORE_LOG("*** Shutting down terrain ***");

		if(TerrainType == TT_PLANE)
		{
			CGameManager::Instance()->GetSceneManager()->destroyEntity(PLANE_ENTITY_NAME);
			CORE_DELETE(m_Plane);
			//CGameManager::Instance()->GetSceneManager()->destroySceneNode("PlaneNode");
		}
		else if(TerrainType == TT_PAGED)
		{
			CORE_DELETE(m_PagedTerrain);
		}
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CTerrainSystem::Shutdown()");
	}
}

f32 CTerrainSystem::GetHeightAt(const f32& x, const f32& z)
{
	f32 retHeight = 0;
	CORE_THROW("Not Implemented", "CTerrainSystem::GetHeightAt");

	return retHeight;
}

void CTerrainSystem::Load(Core::TERRAIN_TYPE* TerrainInfo)
{
	if(TerrainInfo->TerrainType == Core::TERRAIN_TYPE::ETT_PAGED)
	{
		PAGED_TERRAIN* terrainInfo = static_cast<PAGED_TERRAIN*>(TerrainInfo);
		LoadPagedTerrain(terrainInfo);
	}
	else if(TerrainInfo->TerrainType == Core::TERRAIN_TYPE::ETT_HEIGHT)
	{
		HEIGHT_TERRAIN* terrainInfo = static_cast<HEIGHT_TERRAIN*>(TerrainInfo);
		LoadHeightTerrain(terrainInfo);
	}
	else
	{
		PLANE_TERRAIN* terrainInfo = static_cast<PLANE_TERRAIN*>(TerrainInfo);
		LoadPlaneTerrain(terrainInfo);
	}
}

void CTerrainSystem::LoadPlaneTerrain(Core::PLANE_TERRAIN* TerrainInfo)
{
	// Create floor plane (Ogre)
	m_Plane = new MovablePlane("Plane");
	m_Plane->d = 0;
	m_Plane->normal = TerrainInfo->Normal;
	//Ogre::MeshManager::getSingleton().createPlane("PlaneMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *m_Plane, 1000, 1000, 1, 1, true, 1, 3, 3, Vector3::UNIT_Z);
	//Entity* entity = CGameManager::Instance()->GetSceneManager()->createEntity(PLANE_ENTITY_NAME, "PlaneMesh");
	//entity->setMaterialName(String(DEFAULT_PLANE_TERRAIN_MATERIAL));
	//SceneNode* node = CGameManager::Instance()->GetSceneManager()->getRootSceneNode()->createChildSceneNode("PlaneNode");
	//node->attachObject(entity);
	//node->setScale(5, 1, 5);

	// Use a load of meshes to represent the floor
    int i = 0;
    auto staticGeometry = CGameManager::Instance()->GetSceneManager()->createStaticGeometry(PLANE_ENTITY_NAME);
    staticGeometry->setRegionDimensions(Vector3(160.0, 100.0, 160.0));
    staticGeometry->setOrigin(Vector3::ZERO);

	Ogre::MeshManager::getSingleton().createPlane("PlaneMesh", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, *m_Plane, 200, 200, 1, 1, true, 1, 3, 3, Vector3::UNIT_Z);
	for (Real z = -800.0;z <= 3200.0;z += 200.0)
	{
		for (Real x = -800.0;x <= 3200.0;x += 200.0)
		{
			String name = String(PLANE_ENTITY_NAME) + "_" + StringConverter::toString(i++);
			
			Entity* entity = CGameManager::Instance()->GetSceneManager()->createEntity(name, "PlaneMesh");
			entity->setQueryFlags(SQF_TERRAIN);
            entity->setMaterialName(String(DEFAULT_PLANE_TERRAIN_MATERIAL));
			entity->setCastShadows(true);
            staticGeometry->addEntity(entity, Vector3(x, 0, z));
		}
    }
    staticGeometry->build();

	TerrainType = TT_PLANE;
}

void CTerrainSystem::LoadPagedTerrain(Core::PAGED_TERRAIN* TerrainInfo)
{
	m_PagedTerrain = new CPagedTerrain((*TerrainInfo));
	m_PagedTerrain->SetupContent();
	CNatureManager::Instance()->SetTerrainGroup(m_PagedTerrain->GetTerrainGroup());

	TerrainType = TT_PAGED;
}

void CTerrainSystem::LoadHeightTerrain(Core::HEIGHT_TERRAIN* TerrainInfo)
{
	throw "Height terrain is no longer supported.";

	//// Splatting
	//Image m_Coverage[3];
	//TexturePtr m_CoverageTex[3];
	//Image* m_Overlay;
	//TexturePtr m_OverlayTex;
	//Vector<Image*> m_Splatting;
	//Vector<TexturePtr> m_SplattingTex;

	//// Load world geometry
	//CORE_LOG("[CTerrainSystem] Loading world geometry...");

	//// Use detail map to see if heightmap has been declared
	//if(TerrainInfo->DetailTexture == "")
	//	return;

	//// Load the textures
	//for (int i = 0; i < 3; i++) 
	//{
	//	CORE_LOG("Creating ETSplatting");
	//	m_Coverage[i].load("ETcoverage." + StringConverter::toString(i) + ".png", ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
	//
	//	m_CoverageTex[i] = TextureManager::getSingleton().createManual(
	//		"ETSplatting" + StringConverter::toString(i), ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, 
	//		m_Coverage[i].getWidth(), m_Coverage[i].getHeight(), 1, m_Coverage[i].getFormat()
	//	);
	//	
	//	m_CoverageTex[i]->unload();
	//	m_CoverageTex[i]->loadImage(m_Coverage[i]);
	//}	

	//// Create color layer
	//m_Overlay = new Image();	
	//try 
	//{	
	//	//if (mZoneName!="") 
	//	//{
	//		m_Overlay->load("artifexterra3d_colourmap.png", ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);	  
	//	//}

	//	m_OverlayTex = TextureManager::getSingleton().createManual(
	//		"ArtifexTerra3D_ColourMap", ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME, Ogre::TEX_TYPE_2D, 2048, 2048, 1, 
	//		m_Overlay->getFormat());	

	//	m_OverlayTex->unload();
	//	m_OverlayTex->loadImage(*m_Overlay); 	
	//  
	//}
	//catch(...) 
	//{ 	
	//	uchar *pImage = new uchar[2048 * 2048 * 4];
 //       m_Overlay->loadDynamicImage(pImage, 2048, 2048, PF_A8R8G8B8);         
	//	
	//	m_OverlayTex = TextureManager::getSingleton().createManual(
	//		"ArtifexTerra3D_ColourMap", ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME, Ogre::TEX_TYPE_2D, 2048, 2048, 1, 
	//		m_Overlay->getFormat());	

	//	m_OverlayTex->unload();
	//	m_OverlayTex->loadImage(*m_Overlay); 	
	//}	

	//// Setup textures
	//// TODO: texture size is hardcoded
	//u32 TextureSize = 1024;
	//
	//// Load the splatting textures
	//for (u32 i = 0; i < TerrainInfo->Splatting.size(); i++) 
	//{
	//	Image* img = new Image();
	//	img->load(TerrainInfo->Splatting[i], ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME);
	//	m_Splatting.push_back(img);

	//	// create a manual texture	  
	//	TexturePtr tex = TextureManager::getSingleton().createManual(
	//		"Splatting" + i, ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, TextureSize, TextureSize, 1, img->getFormat());	

	//	// load the imagefile 
	//	tex->loadImage(*img);
	//	m_SplattingTex.push_back(tex);
	//}

	//// Load terrain
	//if(CGameManager::Instance()->GetSceneManager()->getTypeName() != "TerrainSceneManager")
	//	throw "LoadHeightTerrain: Wrong scene manager type";

	//TerrainSceneManager* tsm = (TerrainSceneManager*)CGameManager::Instance()->GetSceneManager();

	//tsm->destroyLevelIndexes();
	//tsm->mTerrainPages.clear();
	//
	//// loadConfig
	//tsm->setCustomMaterial(TerrainInfo.CustomMaterialName);
	//tsm->setDetailTexture(TerrainInfo.DetailTexture);
	//tsm->setDetailTextureRepeat(TerrainInfo.DetailTile);

	////TerrainInfo.HeightmapRawBpp;	// not used yet
	////TerrainInfo.HeightmapRawSize;	// not used yet
	//tsm->setLODMorphStart(TerrainInfo.LODMorphStart);

	//Vector3 v = Vector3::UNIT_SCALE;
	//v.y = TerrainInfo.MaxHeight;
	//v.x = TerrainInfo.PageWorldX;
	//v.z = TerrainInfo.PageWorldZ;
	//// Scale x/z relative to pagesize
 //   v.x /= TerrainInfo.PageSize - 1;
 //   v.z /= TerrainInfo.PageSize - 1;
 //   tsm->setScale(v);

	//tsm->setMaxGeoMipMapLevel(TerrainInfo.MaxMipMapLevel);
	//tsm->setMaxPixelError(TerrainInfo.MaxPixelError);
	//tsm->setCustomMaterialMorphFactorParam(TerrainInfo.MorphLODFactorParamIndex);
	//tsm->setCustomMaterialMorphFactorParam(TerrainInfo.MorphLODFactorParamName);
	//tsm->setPageSize(TerrainInfo.PageSize);
	//tsm->setTileSize(TerrainInfo.TileSize);
	//tsm->setUseTriStrips(TerrainInfo.UseTriStrips);
	//tsm->setUseVertexColours(TerrainInfo.VertexColors);
	//tsm->setUseVertexNormals(TerrainInfo.VertexNormals);
	//tsm->setUseLODMorph(TerrainInfo.VertexProgramMorph);
	//tsm->setWorldTexture(TerrainInfo.WorldTexture);

	//TerrainPageSourceOptionList optlist;
 //   optlist.push_back(TerrainPageSourceOption("Heightmap.image", TerrainInfo.HeightmapImage));

 //   // set the page source
 //   tsm->selectPageSource("Heightmap", optlist);

	//// setWorldGeometry
	//tsm->initLevelIndexes();

	//// Resize the octree, allow for 1 page for now
	//float max_x = tsm->mOptions.scale.x * tsm->mOptions.pageSize;
	//float max_y = tsm->mOptions.scale.y;
	//float max_z = tsm->mOptions.scale.z * tsm->mOptions.pageSize;
	//tsm->resize( AxisAlignedBox( 0, 0, 0, max_x, max_y, max_z ) );

	//tsm->setupTerrainMaterial();
	//tsm->setupTerrainPages();
	//TerrainType = TT_HEIGHT;
}

// Paged Terrain

#ifdef PAGING
bool DummyPageProvider::prepareProceduralPage(Page* page, PagedWorldSection* section) 
{
	return true;
}

bool DummyPageProvider::loadProceduralPage(Page* page, PagedWorldSection* section)
{
	return true;
}

bool DummyPageProvider::unloadProceduralPage(Page* page, PagedWorldSection* section)
{
	return true;
}

bool DummyPageProvider::unprepareProceduralPage(Page* page, PagedWorldSection* section)
{
	return true;
}

#endif

CPagedTerrain::CPagedTerrain(const PAGED_TERRAIN& TerrainInfo)
	: m_TerrainGroup(nullptr),
	mTerrainPaging(nullptr),
	mPageManager(nullptr),
	m_TerrainInfo(TerrainInfo),
	m_terrainGlobalOptions(nullptr)

{
	mSceneMgr = CGameManager::Instance()->GetSceneManager();
	mCamera = CCameraManager::Instance()->GetCamera();

	if(m_TerrainInfo.ResourceGroup.length() == 0)
		m_TerrainInfo.ResourceGroup = ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME;
}

CPagedTerrain::~CPagedTerrain()
{
	CORE_DELETE(mTerrainPaging);
	CORE_DELETE(mPageManager);
	CORE_DELETE(m_TerrainGroup);
	CORE_DELETE(m_terrainGlobalOptions);
}

void CPagedTerrain::SaveTerrains(bool onlyIfModified)
{
	m_TerrainGroup->saveAllTerrains(onlyIfModified);
}

void CPagedTerrain::DefineTerrain(long x, long y, bool flat)
{
	// if a file is available, use it if not, generate file from import
	if (flat)
	{
		m_TerrainGroup->defineTerrain(x, y, 0.0f);
	}
	else
	{
		String filename = m_TerrainGroup->generateFilename(x, y);
		if (ResourceGroupManager::getSingleton().resourceExists(m_TerrainGroup->getResourceGroup(), filename))
		{
			m_TerrainGroup->defineTerrain(x, y);
		}
	}
}

void CPagedTerrain::ConfigureTerrainDefaults()
{
	Vector3 lightdir(0.55f, -0.3f, 0.75f);
	lightdir.normalise();


	Light* l = mSceneMgr->createLight("tstLight");
	l->setType(Light::LT_DIRECTIONAL);
	l->setDirection(lightdir);
	l->setDiffuseColour(ColourValue::White);
	l->setSpecularColour(ColourValue(0.4f, 0.4f, 0.4f));

	//mSceneMgr->setAmbientLight(ColourValue(0.2f, 0.2f, 0.2f));

	// Configure global
	m_terrainGlobalOptions = OGRE_NEW TerrainGlobalOptions();
	m_terrainGlobalOptions->setMaxPixelError(3.0f);
	m_terrainGlobalOptions->setCompositeMapDistance(50000.0f /*CCameraManager::Instance()->GetFarClipDistance()*/);
	m_terrainGlobalOptions->setCompositeMapSize((uint16)1024 * (uint16)1024);
	//TerrainGlobalOptions::setUseRayBoxDistanceCalculation(true);
	//TerrainGlobalOptions::getDefaultMaterialGenerator()->setDebugLevel(1);
	//TerrainGlobalOptions::setLightMapSize(256);
	//static_cast<TerrainMaterialGeneratorA::SM2Profile*>(TerrainGlobalOptions::getDefaultMaterialGenerator()->getActiveProfile())
	//	->setLightmapEnabled(false);
	// Important to set these so that the terrain knows what to use for derived (non-realtime) data
	m_terrainGlobalOptions->setLightMapDirection(l->getDerivedDirection());
	m_terrainGlobalOptions->setCompositeMapAmbient(mSceneMgr->getAmbientLight());
	m_terrainGlobalOptions->setCompositeMapDiffuse(l->getDiffuseColour());

	// Configure default import settings for if we use imported image
	Terrain::ImportData& imp = m_TerrainGroup->getDefaultImportSettings();
	imp.terrainSize = m_TerrainInfo.MapSize;
	imp.worldSize = (f32)m_TerrainInfo.WorldSize;
	//imp.inputScale = 600; // TODO: don't know what this is
	imp.minBatchSize = m_TerrainInfo.MinBatchSize;
	imp.maxBatchSize = m_TerrainInfo.MaxBatchSize;
			
	// textures (layers)
	u32 size = (u32)m_TerrainInfo.Layers.size();
	imp.layerList.resize(size);
	for(u32 i = 0; i < size; i++)
	{
		imp.layerList[i].worldSize = (f32)m_TerrainInfo.Layers[i].WorldSize;
		// Diffuse map
		imp.layerList[i].textureNames.push_back(m_TerrainInfo.Layers[i].Diffuse);
		// Normal map
		imp.layerList[i].textureNames.push_back(m_TerrainInfo.Layers[i].Normal);
	}
}

void CPagedTerrain::SetupContent()
{
	bool blankTerrain = false;

	MaterialManager::getSingleton().setDefaultTextureFiltering(TFO_ANISOTROPIC);
	MaterialManager::getSingleton().setDefaultAnisotropy(7);

	//LogManager::getSingleton().setLogDetail(LL_BOREME);

	m_TerrainGroup = OGRE_NEW TerrainGroup(mSceneMgr, Terrain::ALIGN_X_Z, (u16)m_TerrainInfo.MapSize, (f32)m_TerrainInfo.WorldSize);
	m_TerrainGroup->setFilenameConvention(m_TerrainInfo.TerrainFile, "ogt");
	m_TerrainGroup->setOrigin(Vector3(0.0f, 0.0f, 0.0f));
	m_TerrainGroup->setResourceGroup(m_TerrainInfo.ResourceGroup);

	// TODO: need access to light
	ConfigureTerrainDefaults();

#ifdef PAGING
	// Paging setup
	mPageManager = OGRE_NEW PageManager();
	mPageManager->addCamera(mCamera);
	//mPageManager->setPageProvider(&mDummyPageProvider);
	mTerrainPaging = OGRE_NEW TerrainPaging(mPageManager);
	PagedWorld* world = mPageManager->createWorld();
	TerrainPagedWorldSection* section = mTerrainPaging->createWorldSection(world, m_TerrainGroup, 5000, 5000, m_TerrainInfo.MinX, m_TerrainInfo.MinY, m_TerrainInfo.MaxX, m_TerrainInfo.MaxY);
	//m_TerrainGroup->loadAllTerrains(true);
#else
	// TODO: data driven
	for (long x = m_TerrainInfo.MinX; x <= m_TerrainInfo.MaxX; ++x)
		for (long y = m_TerrainInfo.MinY; y <= m_TerrainInfo.MaxY; ++y)
			DefineTerrain(x, y, blankTerrain);

	// sync load since we want everything in place when we start
	m_TerrainGroup->loadAllTerrains(true);
#endif

	m_TerrainGroup->freeTemporaryResources();
}

