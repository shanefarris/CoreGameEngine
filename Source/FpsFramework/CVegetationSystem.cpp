#include "CWorld.h"
#include "CVegetationSystem.h"
#include "CTerrainSystem.h"
#include "CCameraManager.h"
#include "CNatureManager.h"
#include "Structures.h"
#include "IPhysicsStrategy.h"
#include "CGameObject.h"
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "IO/CoreLogging.h"

// PagedGeometry
#include "Forest/PagedGeometry.h"
#include "Forest/GrassLoader.h"
#include "Forest/BatchPage.h"
#include "Forest/ImpostorPage.h"
#include "Forest/TreeLoader2D.h"
#include "Forest/TreeLoader3D.h"
#include "Forest/TreeLoader3D_Physics.h"

using namespace Core::Nature;

f32 GetHeightAt(f32 x, f32 z, void* data)
{
	return CNatureManager::Instance()->GetTerrainHeightAt(x, x);
}

// Used to convert fade technique from stage files
static Forests::FadeTechnique stringToFadeTechnique(const String& string)
{
	if (string == "FADETECH_ALPHA")
		return Forests::FADETECH_ALPHA;
	else if (string == "FADETECH_ALPHAGROW")
		return Forests::FADETECH_ALPHAGROW;
	else if (string == "FADETECH_GROW")
		return Forests::FADETECH_GROW;

	return Forests::FADETECH_ALPHAGROW;
}

// Used to convert grass technique from stage files
static Forests::GrassTechnique stringToRenderTechnique(const String& string)
{
	if (string == "GRASSTECH_CROSSQUADS")
		return Forests::GRASSTECH_CROSSQUADS;
	else if (string == "GRASSTECH_QUAD")
		return Forests::GRASSTECH_QUAD;
	else if (string == "GRASSTECH_SPRITE")
		return Forests::GRASSTECH_SPRITE;

	return Forests::GRASSTECH_QUAD;
}

CVegetationSystem::CVegetationSystem(CTerrainSystem* terrain) : m_TerrainSystem(terrain)
{
	CORE_LOG("*** Initialising vegetation ***");
	EnvironmentType = EET_VEG;
}

CVegetationSystem::~CVegetationSystem()
{
	Shutdown();
}

void CVegetationSystem::Shutdown()
{
	try
	{
		CORE_LOG("*** Shutting down vegetation ***");

		auto it = m_Geometry.begin(); 
		while(it != m_Geometry.end())
		{
			if((*it).second)
				CORE_DELETE((*it).second);
			if((*it).first)
				delete (*it).first;		// Use regular delete because we can't set it to nullptr.
		}

		m_Geometry.clear();
	}
	catch(std::exception& e)
	{
		CORE_ASSERT(false);
		throw(e);
	}
	catch(...)
	{
		throw("Error in CVegtationSystem::Shutdown()");
	}
}

void CVegetationSystem::Pause()
{
}

void CVegetationSystem::Resume()
{
}

void CVegetationSystem::Update(const f32& elapsed)
{
	for(auto it = m_Geometry.begin(); it != m_Geometry.end(); it++)
	{
		(*it).first->update();
	}
}

void CVegetationSystem::AddPagedGeometry(Core::GEO_SET* GeoSet, Core::Physics::IPhysicsStrategy* PhysicsStrategy)
{
	CORE_LOG("[Vegetation System] Loading Trees...");

	Forests::PagedGeometry* geo = new Forests::PagedGeometry();
	Forests::PageLoader* geoLoader = nullptr;

	geo->setCamera(CCameraManager::Instance()->GetCamera());	// Set the camera so PagedGeometry knows how to calculate LODs
	geo->setPageSize(GeoSet->PageSize);							// Set the size of each page of geometry
	geo->setInfinite();											// Use infinite paging mode

	switch(GeoSet->GeoType)
	{
	case Core::GEO_SET::GLT_GRASS: 
			{
				if(GeoSet->MaterialName.length() == 0 || GeoSet->DensityMap.length() == 0)
					return;

				geo->addDetailLevel<Forests::GrassPage>(150);

				geoLoader = new Forests::GrassLoader(geo);
				if(m_TerrainSystem)
					((Forests::GrassLoader*)geoLoader)->setHeightFunction(&GetHeightAt, m_TerrainSystem);

				//Add some grass to the scene with GrassLoader::addLayer()
				Forests::GrassLayer *l = ((Forests::GrassLoader*)geoLoader)->addLayer(GeoSet->MaterialName);

				//Configure the grass layer properties (size, density, animation properties, fade settings, etc.)
				l->setMinimumSize(2.0f, 2.0f);
				l->setMaximumSize(2.5f, 2.5f);
				l->setAnimationEnabled(true);					//Enable animations
				l->setSwayDistribution(10.0f);					//Sway fairly unsynchronized
				l->setSwayLength(0.5f);                         //Sway back and forth 0.5 units in length
				l->setSwaySpeed(0.5f);                          //Sway 1/2 a cycle every second
				l->setDensity(1.5f);                            //Relatively dense grass
				l->setFadeTechnique(Forests::FADETECH_GROW);     //Distant grass should slowly raise out of the ground when coming in range
				l->setRenderTechnique(Forests::GRASSTECH_QUAD);  //Draw grass as scattered quads

				//This sets a color map to be used when determining the color of each grass quad. setMapBounds()
				//is used to set the area which is affected by the color map. Here, "terrain_texture.jpg" is used
				//to color the grass to match the terrain under it.
				l->setColorMap(GeoSet->DensityMap);
				l->setMapBounds(Forests::TBounds(GeoSet->HeightMin, GeoSet->WidthMin, GeoSet->HeightMax, GeoSet->WidthMax));
				l->setDensityMap("grassdensity1.png");

				break;
			}

	case Core::GEO_SET::GLT_BUSH:
			{
				geoLoader = new Forests::TreeLoader2D(geo, Forests::TBounds(GeoSet->HeightMin, GeoSet->WidthMin, GeoSet->HeightMax, GeoSet->WidthMax));
				geo->addDetailLevel<Forests::BatchPage>(GeoSet->BatchMax, GeoSet->BatchStart);
				if(m_TerrainSystem)
					((Forests::TreeLoader2D*)geoLoader)->setHeightFunction(&GetHeightAt, m_TerrainSystem);

				geo->setPageLoader(geoLoader);
				if(GeoSet->Entity)
				{
					//Load a tree entity
					for (auto it = GeoSet->Objects.cbegin(); it != GeoSet->Objects.cend(); it++)
					{
						//(*it).Position.y = m_TerrainSystem->GetHeightAt((*it).Position.x, (*it).Position.z);
						((Forests::TreeLoader2D*)geoLoader)->addTree(GeoSet->Entity, (*it).Position, (*it).Yaw, (*it).Scale);
					}
				}
				break;
			}
		case Core::GEO_SET::GLT_TREE_3DP:
		case Core::GEO_SET::GLT_TREE_3D:
			{
				geo->addDetailLevel<Forests::BatchPage>(GeoSet->BatchMax, GeoSet->BatchStart);
				geo->addDetailLevel<Forests::ImpostorPage>(GeoSet->ImposterMax, GeoSet->ImposterStart);

				geoLoader = new Forests::TreeLoader3D(geo, Forests::TBounds(GeoSet->HeightMin, GeoSet->WidthMin, GeoSet->HeightMax, GeoSet->WidthMax));
				//treeLoader->setColorMap("terrain_lightmap.jpg");
				geo->setPageLoader(geoLoader);
				if(GeoSet->Entity)
				{
					//Load a tree entity
					for (auto it = GeoSet->Objects.cbegin(); it != GeoSet->Objects.cend(); it++)
					{
						//(*it).Position.y = m_TerrainSystem->GetHeightAt((*it).Position.x, (*it).Position.z);
						((Forests::TreeLoader3D*)geoLoader)->addTree(GeoSet->Entity, (*it).Position, (*it).Yaw, (*it).Scale);
					}
				}
				break;
			}
		case Core::GEO_SET::GLT_TREE_2D:
			{
				geo->addDetailLevel<Forests::BatchPage>(GeoSet->BatchMax, GeoSet->BatchStart);
				geo->addDetailLevel<Forests::ImpostorPage>(GeoSet->ImposterMax, GeoSet->ImposterStart);

				geoLoader = new Forests::TreeLoader2D(geo, Forests::TBounds(GeoSet->HeightMin, GeoSet->WidthMin, GeoSet->HeightMax, GeoSet->WidthMax));
				if(m_TerrainSystem)
					((Forests::TreeLoader2D*)geoLoader)->setHeightFunction(&GetHeightAt, m_TerrainSystem);

				geo->setPageLoader(geoLoader);
				if(GeoSet->Entity)
				{
					//Load a tree entity
					for (auto it = GeoSet->Objects.cbegin(); it != GeoSet->Objects.cend(); it++)
					{
						//(*it).Position.y = m_TerrainSystem->GetHeightAt((*it).Position.x, (*it).Position.z);
						((Forests::TreeLoader2D*)geoLoader)->addTree(GeoSet->Entity, (*it).Position, (*it).Yaw, (*it).Scale);
					}
				}
				break;
			}
	}

	//// Check for physics.  TODO: this logic could probably be placed somewhere better.
	//if(GeoSet->GeoType == GEO_SET::GLT_TREE_3DP)
	//{
	//	u32 count = 0;
	//	auto loader = static_cast<Forests::TreeLoader3D*>(geoLoader);
	//	auto trees = loader->getTrees();
	//	while(trees.hasMoreElements())
	//	{
	//		auto tree = trees.getNext();
	//		auto obj = new CDummyGameObject();
	//		obj->Entity = tree.getEntity();
	//		obj->Node = obj->Entity->getParentSceneNode();
	//		obj->PhysicsProfile = Core::Physics::CPhysicsManager::Instance()->GetPhysicsProfile(GeoSet->PhysicsProfile.c_str());
	//		Core::Physics::CPhysicsManager::Instance()->GetStrategy()->AddShape(obj);
	//		count++;
	//	}
	//}

	m_Geometry[geo] = geoLoader;
}

//void CVegetationSystem::AddGrass()
//{

	// Grass
	//mGrass = new Forests::PagedGeometry(CNatureManager::Instance()->GetCamera(), 30);
	//mGrass->addDetailLevel<Forests::GrassPage>(60);

//	CORE_LOG("[Vegetation System] Loading grass...");
//
//	ConfigFile file;
////	file.loadFromResourceSystem(WORLD_CONFIG_FILE, stage);
//
//	// Grass loader
//	mGrassLoader = new Forests::GrassLoader(mGrass);
//	mGrass->setPageLoader(mGrassLoader);
//	mGrassLoader->setHeightFunction(&GetHeightAt_Paged, m_TerrainSystem);
//
//	using namespace Forests;
//
//	//TAKEN DIRECTLY FROM Paged geo demos!
//	//Add some grass to the scene with GrassLoader::addLayer()
//	GrassLayer *l = mGrassLoader->addLayer("3D-Diggers/plant1sprite");
//
//	//Configure the grass layer properties (size, density, animation properties, fade settings, etc.)
//	l->setMinimumSize(0.7f, 0.7f);
//	l->setMaximumSize(0.9f, 0.9f);
//	l->setAnimationEnabled(true);		//Enable animations
//	l->setSwayDistribution(7.0f);		//Sway fairly unsynchronized
//	l->setSwayLength(0.1f);				//Sway back and forth 0.5 units in length
//	l->setSwaySpeed(0.4f);				//Sway 1/2 a cycle every second
//	l->setDensity(5.0f);				//Relatively dense grass
//	l->setRenderTechnique(GRASSTECH_SPRITE);
//	l->setFadeTechnique(FADETECH_GROW);	//Distant grass should slowly raise out of the ground when coming in range
//
//	//[NOTE] This sets the color map, or lightmap to be used for grass. All grass will be colored according
//	//to this texture. In this case, the colors of the terrain is used so grass will be shadowed/colored
//	//just as the terrain is (this usually makes the grass fit in very well).
//	l->setColorMap("terrain_texture2.jpg");
//
//	//This sets the density map that will be used to determine the density levels of grass all over the
//	//terrain. This can be used to make grass grow anywhere you want to; in this case it's used to make
//	//grass grow only on fairly level ground (see densitymap.png to see how this works).
//	l->setDensityMap("densitymap.png");
//
//	//setMapBounds() must be called for the density and color maps to work (otherwise GrassLoader wouldn't
//	//have any knowledge of where you want the maps to be applied). In this case, the maps are applied
//	//to the same boundaries as the terrain.
//	l->setMapBounds(Forests::TBounds(0, 0, 1500, 1500));	//(0,0)-(1500,1500) is the full boundaries of the terrain


	/** TODO make this work from a config file
	// Load layers
	s32 numLayers = StringConverter::parseInt(file.getSetting("Layers", "Grass", "0"));
	for (s32 i = 0; i < numLayers; i++)
	{
		const String& section = "GrassLayer" + StringConverter::toString(i);

		Forests::GrassLayer* grassLayer = mGrassLoader->addLayer(file.getSetting("Material", section));
		grassLayer->setMinimumSize(
			StringConverter::parseReal(file.getSetting("MinimumWidth", section, "0.7")),
			StringConverter::parseReal(file.getSetting("MinimumHeight", section, "0.7"))
		);
		grassLayer->setMaximumSize(
			StringConverter::parseReal(file.getSetting("MaximumWidth", section, "2.9")),
			StringConverter::parseReal(file.getSetting("MaximumHeight", section, "2.9"))
		);
		grassLayer->setAnimationEnabled(
			StringConverter::parseBool(file.getSetting("Animate", section, "true"))
		);
		grassLayer->setSwayDistribution(
			StringConverter::parseReal(file.getSetting("SwayDistribution", section, "7.0"))
		);
		grassLayer->setSwayLength(
			StringConverter::parseReal(file.getSetting("SwayLength", section, "0.1"))
		);
		grassLayer->setSwaySpeed(
			StringConverter::parseReal(file.getSetting("SwaySpeed", section, "0.4"))
		);
		grassLayer->setDensity(
			StringConverter::parseReal(file.getSetting("Density", section, "1.5"))
		);
		//grassLayer->setLightingEnabled(true);

		const String& fadeTechStr = file.getSetting("FadeTechnique", section);
		if (fadeTechStr != "")
			grassLayer->setFadeTechnique(stringToFadeTechnique(fadeTechStr));

		const String& renderTechStr = file.getSetting("RenderTechnique", section);
		grassLayer->setRenderTechnique(stringToRenderTechnique(renderTechStr));

		// This sets the color map, or lightmap to be used for grass. All grass will be colored according
		// to this texture. In this case, the colors of the terrain is used so grass will be shadowed/colored
		// just as the terrain is (this usually makes the grass fit in very well).
		grassLayer->setColorMap("world.dds");

		// This sets the density map that will be used to determine the density levels of grass all over the
		// terrain. This can be used to make grass grow anywhere you want to; in this case it's used to make
		// grass grow only on fairly level ground.
		grassLayer->setDensityMap("grasscoverage.dds");

		// Set map bounds
		Vector3 extents = m_TerrainSystem->GetExtents();
		grassLayer->setMapBounds(Forests::TBounds(0, 0, extents.x, extents.z));
	}
	**/

//}