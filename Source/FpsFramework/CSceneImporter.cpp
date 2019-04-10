#include "CSceneImporter.h"
#include "Terrain/OgreTerrain.h"
#include "Terrain/OgreTerrainQuadTreeNode.h"
#include "Caelum/Caelum.h"
#include "Hydrax/MaterialManager.h"
#include "Hydrax/ProjectedGrid.h"
#include "CParserStrategies.h"
#include "CPlayer.h"
#include "CBuilding.h"
#include "CWorldProfile.h"
#include "AnimationMapping.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsProfile.h"
#include "CWorldProfile.h"
#include "CGameObject.h"

#include "CWeaponProfile.h"
#include "CItemProfile.h"

#include "CGameManager.h"
#include "Audio/CSoundManager.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "CItemsManager.h"
#include "CNatureManager.h"
#include "CPhysicsManager.h"
#include "CSpawnManager.h"
#include "CBillboardManager.h"
#include "CCharacterStateManager.h"

#include "IO/IReadFile.h"
#include "IO/IXMLReader.h"
#include "IO/CFileSystem.h"
#include "IO/CoreLogging.h"

using namespace Core;
using namespace Core::Physics;
using namespace Core::Nature;
using namespace Sound;

const String CSceneImporter::XML_EXT = "scx";
const String CSceneImporter::DB_EXT = "scd";

CSceneImporter::CSceneImporter()
	: m_IsPhysicStrategy(false),
	m_GameManager(nullptr),
	m_EngineDevice(nullptr),
	m_SceneManager(nullptr),
	m_RenderWindow(nullptr),
	m_PhysicsStrategy(nullptr),
	m_SoundManager(nullptr),
	m_ItemsManager(nullptr),
	m_GameObjectManager(nullptr),
	m_CameraManager(nullptr),
	m_NatureManager(nullptr)
{
}

CSceneImporter::~CSceneImporter()
{
	m_Projectiles.erase(m_Projectiles.begin(), m_Projectiles.end());
	m_Magazines.erase(m_Magazines.begin(), m_Magazines.end());
}

bool CSceneImporter::ParseScene(const String& FileName)
{
	IO::CFileSystem FileSystem;
	if(!IO::CFileSystem::IsFileExist(FileName.c_str()))
	{
		CORE_ERR("File does not exist. CSceneImporter::ParseScene");
		return false;
	}

	// Find out what file type this is first
	String ext = FileSystem.GetFileExtension(FileName);
	if(ext == XML_EXT)
	{
		CXmlParserStrategy xmlParser;
		return xmlParser.ParseScene(FileName, m_Parser);
	}
	else
	{
		CDbParserStrategy dbParser;
		return dbParser.ParseScene(FileName, m_Parser);
	}
	return false;
}

bool CSceneImporter::ImportScene(const String& file, const String& ResourceGroupName)
{
	m_SoundManager = Sound::CSoundManager::Instance();
	m_GameManager = CGameManager::Instance();
	m_CameraManager = CCameraManager::Instance();
	m_ItemsManager = CItemsManager::Instance();
	m_GameObjectManager = CGameObjectManager::Instance();
	m_NatureManager = CNatureManager::Instance();

	m_ResourceGroupName = ResourceGroupName;
	m_PhysicsStrategy = Physics::CPhysicsManager::Instance()->GetStrategy();
	m_EngineDevice = m_GameManager->GetEngineDevice();
	m_SceneManager = m_GameManager->GetSceneManager();
	m_RenderWindow = m_GameManager->GetRenderWindow();

	m_IsPhysicStrategy = m_PhysicsStrategy == nullptr ? false : true;

	// Clear all contrainers
	m_Parser.Reset();

	if(ParseScene(file))
	{
		// Save a copy of the static data to the game manager for saving a level later
		m_GameManager->SetStaticData(m_Parser.StaticData);

		// Static data first
		if(!LoadArchives())
		{
			CORE_THROW("Error loading archives.", "CSceneImporter::ImportScene");
		}

		if(!LoadSceneManager())
		{
			CORE_THROW("Error loading scene manager.", "CSceneImporter::ImportScene");
		}

		if(!LoadCameras())
		{
			CORE_THROW("Error loading camera.", "CSceneImporter::ImportScene");
		}

		if(!LoadPhysicProfiles())
		{
			CORE_THROW("Error loading physic nodes.", "CSceneImporter::ImportScene");
		}

		if(!LoadGameObjects())
		{
			CORE_THROW("Error loading game objects.", "CSceneImporter::ImportScene");
		}

		if(!LoadNatureWorld())
		{
			CORE_THROW("Error loading nature world.", "CSceneImporter::ImportScene");
		}

		if(!LoadBgSounds())
		{
			CORE_THROW("Error loading bg sounds.", "CSceneImporter::ImportScene");
		}

		if(!LoadSounds())
		{
			CORE_THROW("Error loading sounds.", "CSceneImporter::ImportScene");
		}

		if(!LoadWater())
		{
			CORE_THROW("Error loading water.", "CSceneImporter::ImportScene");
		}

 		if(!LoadLight())
		{
			CORE_THROW("Error loading lights.", "CSceneImporter::ImportScene");
		}

		if(!LoadProjectileProfiles())
		{
			CORE_THROW("Error loading projectiles.", "CSceneImporter::ImportScene");
		}

		if(!LoadMagazineProfiles())
		{
			CORE_THROW("Error loading magazines.", "CSceneImporter::ImportScene");
		}

		if(!LoadWeaponProfiles())
		{
			CORE_THROW("Error loading weapons.", "CSceneImporter::ImportScene");
		}

		if(!LoadMeleeProfiles())
		{
			CORE_THROW("Error loading melees.", "CSceneImporter::ImportScene");
		}

		if(!LoadSpawnPoints())
		{
			CORE_THROW("Error loading spawn points.", "CSceneImporter::ImportScene");
		}

		if(!LoadBillboards())
		{
			CORE_THROW("Error loading billboards.", "CSceneImporter::ImportScene");
		}

		// Dynamic data
		if(!LoadPlacedItems())
		{
			CORE_THROW("Error loading placed inventory.", "CSceneImporter::ImportScene");
		}
		
		if(!LoadAiPaths())
		{
			CORE_THROW("Error loading Ai paths.", "CSceneImporter::ImportScene");
		}

		if(!LoadPlayers())
		{
			CORE_THROW("Error loading players.", "CSceneImporter::ImportScene");
		}

		if(!LoadAnimationMapping())
		{
			CORE_THROW("Error loading animation mappings.", "CSceneImporter::ImportScene");
		}

		if(!LoadBuildings())
		{
			CORE_THROW("Error loading buildings.", "CSceneImporter::ImportScene");
		}
	}
	else
	{
		CORE_THROW("Error parsing data for scene importer.", "CSceneImporter::ImportScene");
	}

	return true;
}

bool CSceneImporter::LoadSceneManager()
{
	if(m_Parser.SceneManager.Type != "")
	{
		// Save physics strategy data if one is created.
		CWorldProfile* worldProfile = nullptr;
		bool isDebugSet = false;
		String type;
		if(m_IsPhysicStrategy)
		{
			if(m_PhysicsStrategy->GetWorldProfile())
			{
				worldProfile = new CWorldProfile(*m_PhysicsStrategy->GetWorldProfile());
			}

			isDebugSet = m_PhysicsStrategy->IsDebug();
			type = m_PhysicsStrategy->GetStrategyType();
		}

		m_SceneManager = m_GameManager->CreateScene(m_Parser.SceneManager.Type.c_str(), m_Parser.SceneManager.Name.c_str());

		// Reset our physics strategy because it could be using the last scene manager.
		if(m_IsPhysicStrategy && type.length() > 0)
		{
			if(worldProfile)
			{
				m_PhysicsStrategy = CPhysicsManager::Instance()->CreateStrategy(type.c_str());
				m_PhysicsStrategy->InitWorld(worldProfile);
				m_PhysicsStrategy->ShowDebug(isDebugSet);
			}
		}
		else
		{
			m_PhysicsStrategy = CPhysicsManager::Instance()->CreateStrategy(m_GameManager->GetDefaultPhysicsStrategy());
			m_PhysicsStrategy->InitWorld();
		}
		CORE_DELETE(worldProfile);
	}
	else 
	{
		return false;
	}

	if(m_SceneManager)
	{
		// Set ambient light
		m_SceneManager->setAmbientLight(m_Parser.SceneManager.Ambient);	

		// Set fog
		m_SceneManager->setFog(m_Parser.SceneManager.FogMode, 
			m_Parser.SceneManager.FogColor, 
			m_Parser.SceneManager.FogDensity, 
			m_Parser.SceneManager.FogStart, 
			m_Parser.SceneManager.FogEnd);

		// Setup skybox
		if(m_Parser.SceneManager.SkyBoxActive &&
			m_Parser.SceneManager.SkyBoxMaterial.length() > 0)
		{
			f32 distance = m_Parser.SceneManager.SkyBoxDistance;
			if(distance <= 0.0f)
			{
				// Set default to 5000
				distance = 5000.0f;
			}
			m_SceneManager->setSkyBox(true, m_Parser.SceneManager.SkyBoxMaterial, distance);
		}
	}
	else
	{
		return false;
	}
	m_SceneManager->setShadowTechnique(SHADOWTYPE_NONE);

	return true;
}

bool CSceneImporter::LoadCameras()
{
	for(auto it = m_Parser.Cameras.cbegin(); it != m_Parser.Cameras.cend(); it++)
	{
		// ECM_NONE means the type couldn't be found
		if((*it).Type != ECM_NONE)
		{
			Camera* camera = nullptr;
			String name = (*it).Name;
			SceneNode* parent = this->FindNode((*it).Parent);

			// Create the camera
			s32 index = m_CameraManager->CreateCamera((*it).Type, parent);

			if(index >= 0)
			{
				camera = m_CameraManager->GetCamera();
				if(camera)
				{
					camera->setPosition((*it).Position);
					camera->setOrientation((*it).Orientation);
					camera->lookAt((*it).LookAt);
					camera->setNearClipDistance((*it).ClipDistance.x);
					camera->setFarClipDistance((*it).ClipDistance.y);
				}
			}
		}
	}

	return true;
}

bool CSceneImporter::LoadGameObjects()
{
	if(!m_GameObjectManager)
		return false;

	for(auto it = m_Parser.GameObjects.cbegin(); it != m_Parser.GameObjects.cend(); it++)
	{
		GAMEOBJECT gameObject = (*it);
		CGameObject* obj = nullptr;

		// If the mesh name has a ".mesh" extension then load a custom object, else load the plugin
		String ext = CFileSystem::GetFileExtension(gameObject.MeshFile);
		if(ext == "mesh")
		{
			obj = m_GameObjectManager->CreateCustomObject(gameObject.MeshFile.c_str(), 
														  gameObject.Name.c_str(), 
														  gameObject.Position);
		}
		else
		{
			obj = m_GameObjectManager->CreateObject(gameObject.MeshFile.c_str(), 
													gameObject.Name.c_str(), 
													gameObject.Position);
		}

		// Game object settings
		if(obj)
		{
			obj->Node->setOrientation(gameObject.Orientation);
			obj->Node->setScale(gameObject.Scale);
			obj->Entity->setCastShadows(gameObject.Shadows);

			// Physics
			if(gameObject.PhysicsProfileName.length() > 0)
			{
				auto profile = Physics::CPhysicsManager::Instance()->GetPhysicsProfile(gameObject.PhysicsProfileName.c_str());
				if(profile)
				{
					obj->PhysicsProfile = profile;
					m_PhysicsStrategy->AddShape(obj);
				}
			}
		}
		else
		{
			CORE_ERR("Unable to load game object");
			return false;
		}
	}
	return true;
}

bool CSceneImporter::LoadPhysicProfiles()
{
	for(auto it = m_Parser.PhysicsProfiles.cbegin(); it != m_Parser.PhysicsProfiles.cend(); it++)
	{
		auto profile = new CPhysicsProfile();
		profile->SetBodyType((*it).BodyType);
		profile->SetMass((*it).Mass);
		profile->SetFriction((*it).Friction);
		profile->SetDensity((*it).Density);
		profile->SetShape((*it).Shape);
		CPhysicsManager::Instance()->AddPhysicsProfile((*it).Name.c_str(), profile);
	}
	return true;
}

bool CSceneImporter::LoadNatureWorld()
{

	HYDRAX* hydrax = nullptr;
	CAELUM* caelum = nullptr;
	TERRAIN_TYPE* terrain = nullptr;

	if(m_Parser.Hydrax.Name.length() > 0)
		hydrax = &m_Parser.Hydrax;
	
	// Caelum will not run properly if not using DX
	if(m_GameManager->GetVideoDeviceType() == EDT_DIRECT3D9 ||
		m_GameManager->GetVideoDeviceType() == EDT_DIRECT3D10)
	{
		if(m_Parser.Caelum.Name.length() > 0)
			caelum = &m_Parser.Caelum;
	}
	else
	{
		CORE_LOG("*** Not running directX, can't use Caelum.");
	}

	// Get the terrain type if any
	if(m_Parser.PagedTerrain.Name.length() > 0)
		terrain = &m_Parser.PagedTerrain;
	else if(m_Parser.PlaneTerrain.isUsed)
		terrain = &m_Parser.PlaneTerrain;
	else if(m_Parser.HeightTerrain.Name.length() > 0)
		terrain = &m_Parser.HeightTerrain;

	// Do we need to load a world at all?
	if(!hydrax && !caelum && !terrain && !m_Parser.PlaneTerrain.isUsed && m_Parser.GeoSets.size() == 0)
		return true;

	if(!m_NatureManager)
		m_NatureManager = CNatureManager::Instance();

	// Check to see if the world was created
	// If the terrain is null a plane terrain is created by default
	if(!m_NatureManager->CreateWorld(hydrax, caelum, terrain, m_ResourceGroupName))
		return false;
	
	// Turn SM sky box off just incase it's in the level 
	if(caelum)
		m_SceneManager->setSkyBox(false, m_Parser.SceneManager.SkyBoxMaterial);

	// Setup terrain Collision
	if(terrain)	
	{
		// Heightmap terrain
		if(m_Parser.HeightTerrain.Name.length() > 0)
		{
			// Setup terrain
			Vector3 v = Vector3::UNIT_SCALE;
			v.y = m_Parser.HeightTerrain.MaxHeight;
			v.x = m_Parser.HeightTerrain.PageWorldX;
			v.z = m_Parser.HeightTerrain.PageWorldZ;
			// Scale x/z relative to pagesize
			v.x /= m_Parser.HeightTerrain.PageSize - 1;
			v.z /= m_Parser.HeightTerrain.PageSize - 1;
		}
		// Paged terrain
		else if(m_Parser.PagedTerrain.Name.length() > 0)
		{
			// Render one frame to initialize the terrain group
			m_GameManager->GetEngineDevice()->renderOneFrame();
			if(m_PhysicsStrategy)
			{
				m_PhysicsStrategy->AddTerrain(CNatureManager::Instance()->GetTerrainGroup());
			}
		}
		// Plane terrain
		else if(m_NatureManager->GetBottomPlane() && m_PhysicsStrategy)
		{
			m_PhysicsStrategy->AddInfinitePlane(m_NatureManager->GetBottomPlane());
		}
	}
	
	// Add paged geometry any
	for(auto it = m_Parser.GeoSets.begin(); it != m_Parser.GeoSets.end(); it++)
	{
		GEO_SET* geoSet = &(*it);
		// If this is a game object plugin, or a custom mesh
		String ext = IO::CFileSystem::GetFileExtension(geoSet->MeshName);
		CGameObject* obj = nullptr;
		if(ext == "mesh")
			obj = CGameObjectManager::Instance()->CreateCustomObject(geoSet->MeshName.c_str(), "", INVALID_POS);
		else
			obj = CGameObjectManager::Instance()->CreateObject(geoSet->MeshName.c_str(), "", INVALID_POS);

		if(obj)
		{
			geoSet->Entity = obj->Entity;
			Nature::CNatureManager::Instance()->AddPagedGeometry(geoSet);
		}
	}

	return true;
}

bool CSceneImporter::LoadBgSounds()
{
	for(auto it = m_Parser.BgSounds.cbegin(); it != m_Parser.BgSounds.cend(); it++)
	{
		BGSOUND bgSound = (*it);
		if(bgSound.Name.length() > 0)
		{
			String name = bgSound.Name;
			String FileName = bgSound.FileName;
			bool loop = bgSound.Loop;
			bool stream = bgSound.Stream;
			f32 gain = bgSound.Gain;

			CSound* sound = m_SoundManager->CreateSound(name, FileName, loop, stream);

			sound->SetGain(gain);
			sound->SetRelativeToListener(true);
			sound->Play();
		}
	}
	return true;
}

bool CSceneImporter::LoadSounds()
{
	for(auto it = m_Parser.Sounds.cbegin(); it != m_Parser.Sounds.cend(); it++)
	{
		SOUND Sound = (*it);
		if(Sound.Name.length() > 0)
		{
			String name = Sound.Name;
			String FileName = Sound.FileName;
			bool loop = Sound.Loop;
			bool stream = Sound.Stream;

			CSound* sound = m_SoundManager->CreateSound(name, FileName, loop, stream);

			if(sound)
			{
				sound->SetRelativeToListener(Sound.RelativeToListener);
				sound->SetPriority((Sound::CSound::Priority)Sound.Priority);
				sound->SetGain(Sound.Gain);
				sound->SetMaxGain(Sound.MaxGain);
				sound->SetMinGain(Sound.MinGain);
				sound->FadeIn(Sound.FadeIn);
				sound->FadeOut(Sound.FadeOut);
				sound->SetPitch(Sound.Pitch);
				sound->SetMaxDistance(Sound.MaxDistance);
				sound->SetRolloffFactor(Sound.RollOffFactor);
				sound->SetReferenceDistance(Sound.RefDistance);
				sound->SetOuterConeGain(Sound.OuterConeGain);
				sound->SetInnerConeAngle(Sound.InnerConeAngle);
				sound->SetOuterConeAngle(Sound.OuterConeAngle);
				sound->SetSecondOffset(Sound.SecondOffset);
				if(Sound.Velocity != Vector3::ZERO)
					sound->SetVelocity(Sound.Velocity);
				if(Sound.Position != Vector3::ZERO)
					sound->SetPosition(Sound.Position);
				if(Sound.Direction != Vector3::ZERO)
					sound->SetDirection(Sound.Direction);
			}
		}
	}
	return true;
}

bool CSceneImporter::LoadWater()
{
	u32 count = 0;
	for(auto it = m_Parser.Waters.cbegin(); it != m_Parser.Waters.cend(); it++)
	{
		String num = StringConverter::toString(count++);
		Plane plane;
		plane.normal = Vector3::UNIT_Y;

		MeshManager::getSingleton().createPlane(
			"WaterPlane_" + num,
			ResourceGroupManager::AUTODETECT_RESOURCE_GROUP_NAME,
			plane,
			(*it).WaterWidthX, 
			(*it).WaterWidthZ,
			20, 20,
			true, 1,
			10, 10,
			Vector3::UNIT_Z);

		Entity* entity = m_SceneManager->createEntity("water_" + num, "WaterPlane_" + num);
		entity->setQueryFlags(0);
		// Set material
		if((*it).WaterMaterial != "")
			entity->setMaterialName((*it).WaterMaterial);

		SceneNode* node = m_SceneManager->getRootSceneNode()->createChildSceneNode("WaterNode_" + num);

		node->attachObject(entity);
		node->setPosition((*it).WaterXPos, (*it).WaterYPos, (*it).WaterZPos);
	}
	return true;
}

bool CSceneImporter::LoadLight()
{
	for(auto it = m_Parser.Lights.cbegin(); it != m_Parser.Lights.cend(); it++)
	{
		auto l = m_SceneManager->createLight((*it).Name);

		// Get light type from cores custom light type
		Light::LightTypes t;
		if((*it).LightType == LT_POINT)
			t = Light::LT_POINT;
		else if((*it).LightType == LT_DIRECTIONAL)
			t = Light::LT_DIRECTIONAL;
		else
			t = Light::LT_SPOTLIGHT;

		l->setType(t);
		l->setPosition((*it).Position);
		Vector3 dir((*it).Direction);
		dir.normalise();
		l->setDirection(dir);
		l->setDiffuseColour((*it).Diffuse.x, (*it).Diffuse.y, (*it).Diffuse.z);
		l->setSpecularColour((*it).Specular.x, (*it).Specular.y, (*it).Specular.z);
		l->setPowerScale((*it).Power);
		l->setCastShadows((*it).Shadows);
		l->setAttenuation((*it).Attenuation.x, (*it).Attenuation.y, (*it).Attenuation.z, (*it).Attenuation.w);
		l->setSpotlightInnerAngle((*it).SpotlightInnerAngle);
		l->setSpotlightOuterAngle((*it).SpotlightOuterAngle);
		l->setSpotlightFalloff((*it).SpotlightFalloff);
		l->setSpotlightNearClipDistance((*it).SpotlightNearClipDistance);
		l->setVisible((*it).Visible);
		l->setShadowFarDistance((*it).ShadowFarDistance);
		l->setShadowNearClipDistance((*it).ShadowNearClipDistance);
		l->setShadowFarClipDistance((*it).ShadowFarClipDistance);
	}
	
	return true;
}

bool CSceneImporter::LoadWeaponProfiles()
{
	if(!m_ItemsManager)
		return false;

	for(auto it = m_Parser.Weapons.cbegin(); it != m_Parser.Weapons.cend(); it++)
	{
		CWeaponProfile profile;
		profile.Name = (*it).Name.c_str();
		profile.Desc = (*it).Desc.c_str();
		profile.MeshName = (*it).MeshName.c_str();
		profile.isAuto = (*it).isAuto;
		profile.isSemi = (*it).isSemi;
		profile.isBurst = (*it).isBurst;
		profile.Accuracy = (*it).Accuracy;
		profile.OverlayName = (*it).OverlayName.c_str();
		profile.Power = (*it).Power;
		profile.Scale = (*it).Scale;
		profile.Range = (*it).Range;

		// Find magazine that goes with this weapon
		String MagName = (*it).MagType.c_str();
		for(auto magit = m_Magazines.cbegin(); magit != m_Magazines.cend(); magit++)
		{
			if((*magit).Name == MagName)
			{
				profile.MagazineProfile = (*magit);
				break;
			}
		}

		m_ItemsManager->AddProfile(profile);
	}
	return true;
}

bool CSceneImporter::LoadMeleeProfiles()
{
	for(auto it = m_Parser.Melees.cbegin(); it != m_Parser.Melees.cend(); it++)
	{
		CItemProfile profile(EIT_MELEE);
		profile.Name = (*it).Name;
		profile.Desc = (*it).Desc;
		profile.MeshName = (*it).MeshName;
		profile.Power = (*it).Power;
		profile.Range = (*it).Range;

		if(m_ItemsManager)
		{
			m_ItemsManager->AddProfile(profile);
		}
	}
	return true;
}

bool CSceneImporter::LoadMagazineProfiles()
{
	for(auto it = m_Parser.Magazines.cbegin(); it != m_Parser.Magazines.cend(); it++)
	{
		CMagazineProfile profile;
		profile.Name = (*it).Name;
		profile.Desc = (*it).Desc;
		profile.MeshName = (*it).MeshFileName;
		profile.Capacity = (*it).Capacity;
		
		// Find the projectile profile to go with the mag profile
		for(auto projit = m_Projectiles.cbegin(); projit != m_Projectiles.cend(); projit++)
		{
			if((*projit).Name == (*it).Projectile)
			{
				profile.ProjectileProfile = (*projit);
				break;
			}
		}
		m_Magazines.push_back(profile);
	}
	return true;
}

bool CSceneImporter::LoadProjectileProfiles()
{
	for(auto it = m_Parser.Projectiles.cbegin(); it != m_Parser.Projectiles.cend(); it++)
	{
		CProjectileProfile profile;
		profile.Name = (*it).Name;
		profile.Desc = (*it).Desc;
		profile.MeshName = (*it).MeshFileName;
		profile.Damage = (*it).Damage;
		profile.Speed = (*it).Speed;
		profile.isPenetrate = (*it).Penetrate;
		
		if((*it).BillboardBullet.length() > 0)
			profile.BillboardBullet = (*it).BillboardBullet;
			
		if((*it).BillboardFlash.length() > 0)
			profile.BillboardFlash = (*it).BillboardFlash;
		
		m_Projectiles.push_back(profile);
	}
	return true;
}

bool CSceneImporter::LoadArchives()
{
	for(auto it = m_Parser.Archives.cbegin(); it != m_Parser.Archives.cend(); it++)
	{
		String name = "level";
		if((*it).Name.length() > 0)
		{
			name = (*it).Name;
		}
		if(CFileSystem::IsFileExist((*it).FileName.c_str()))
		{
			m_GameManager->AddResourceArchive((*it).FileName.c_str(), name.c_str());
		}
		else
		{
			#ifdef _DEBUG
			String msg = "Unable to find archive: " + name;
			CORE_ERR(msg.c_str());
			#else
			return false;
			#endif
		}
	}

	return true;
}

bool CSceneImporter::LoadSpawnPoints()
{
	for(auto it = m_Parser.SpawnPoints.cbegin(); it != m_Parser.SpawnPoints.cend(); it++)
	{
		u32 id = (*it).Id;
		Vector3 pos = (*it).Position;
		E_PLAYER_TEAM team = (*it).Team;
		f32 coolDown = (*it).CoolDown;	
		if(CSpawnManager::Instance()->AddSpawnPoint(id, pos, team, coolDown) == 0)
		{
			CORE_ERR("Error loading spawn point");
		}
	}

	return true;
}

bool CSceneImporter::LoadBillboards()
{
	for(auto it = m_Parser.Billboards.cbegin(); it != m_Parser.Billboards.cend(); it++)
	{
		CBillboardManager::Instance()->CreateBillboard((*it).Name, (*it).Type, (*it).PoolSize, (*it).MaterialName, (*it).Width, (*it).Height);
	}
	return true;
}

bool CSceneImporter::LoadPlacedItems()
{
	if(!m_ItemsManager)
		return false;

	for(auto it = m_Parser.PlacedItems.cbegin(); it != m_Parser.PlacedItems.cend(); it++)
	{
		if(!m_ItemsManager->PlaceItem((*it).ProfileName.c_str(), (*it).Position, m_PhysicsStrategy))
			return false;
	}

	return true;
}

bool CSceneImporter::LoadAiPaths()
{
	for(auto it = m_Parser.AiPaths.cbegin(); it != m_Parser.AiPaths.cend(); it++)
	{
		AI::CCharacterStateManager::Instance()->AddPath((*it).Name.c_str(), (*it).Points);
	}

	return true;
}

bool CSceneImporter::LoadPlayers()
{
	for(auto it = m_Parser.Players.cbegin(); it != m_Parser.Players.cend(); it++)
	{
		// Create the player using GOM first 

		CPlayer* player = m_GameObjectManager->CreatePlayer((*it).PlayerType.c_str(), (*it).Team, (*it).Name.c_str(), m_PhysicsStrategy, (*it).IsHumanplayer);
		if(player == nullptr)
		{
			String msg = "Could not load player type: " + (*it).PlayerType;
			CORE_ERR(msg.c_str());
			return false;
		}

		// ****************** Player is loaded in the game, now set the attributes ******
		player->SetPlayerPosition((*it).Position);							// Position
		player->SetDirection((*it).Direction);								// Direction
		player->SetRunSpeed((*it).RunSpeed);								// Speeds
		player->SetSprintSpeed((*it).SprintSpeed);
		player->SetCrawlSpeed((*it).CrawlSpeed);
		player->SetViewRange((*it).ViewRange);								// View range
		player->SetDieTime((*it).DieingTime);								// Die time
		player->SetHealth((*it).Health);									// Health
		//player->SetRiflemarksman(0);
		//player->SetPhysicalstrength(0);
		player->SetExactCharacterState((*it).CharacterState.c_str());		// Character state

		// Movable text
		if((*it).MovableText.length() > 0)
		{
			player->SetTextLabelEnabled(true);
			player->SetTextLabelCaption((*it).MovableText.c_str());
		}

		// AI Paths assinged to the player
		for(u32 i = 0; i < (*it).PlayerPaths.size(); i++)
		{
			// TODO: Finish this, the player class needs updating, it should store a collection of ai path objects, not just a bunch of 3d vectors.
		}

		// Inventory items
		for(u32 i = 0; i < (*it).PlayerInventory.size(); i++)
		{
			auto item = m_ItemsManager->PickupUnplaced((*it).PlayerInventory[i].ProfileName.c_str());
			if(item)
			{
				player->AddItem(item);
			}
			else
			{
				String msg = "Unable to add inventory item: " + (*it).PlayerInventory[i].ProfileName + " to player: " + (*it).Name;
				CORE_ERR(msg.c_str());
			}
		}
	}
	return true;
}

bool CSceneImporter::LoadAnimationMapping()
{
	// Iterate through each set
	for(auto it = m_Parser.AnimationMapping.cbegin(); it != m_Parser.AnimationMapping.cend(); it++)
	{
		String meshName = (*it).MeshName;
		auto obj = m_GameObjectManager->GetGameObject(meshName.c_str());
		if(obj)
		{
			// Map sent to the game object
			Map<E_ANIM_STATE, SoundToAnimation*> animationMapping;

			auto animations = (*it).Animations;
			// Iterate through each animation/sound specified
			for(auto it2 = animations.cbegin(); it2 != animations.cend(); it2++)
			{
				String animationName = it2->AnimationName;
				String soundName = it2->SoundName;
				animationMapping[it2->AnimState] = new SoundToAnimation(animationName.c_str(), soundName.c_str());
			}
			
			// If there are any mappings then send it to the game object
			if(animationMapping.size() > 0)
			{
				obj->SetAnimationMappings(animationMapping, false);
			}
		}
		else
		{
			String msg = String("Unable to find mesh by name: ") + meshName + " in CSceneImporter::LoadAnimationMapping()";
			CORE_ERR(msg.c_str());
			return false;
		}
	}
	return true;
}

bool CSceneImporter::LoadBuildings()
{
	// Iterate through each set
	for(auto it = m_Parser.Buildings.cbegin(); it != m_Parser.Buildings.cend(); it++)
	{
		BUILDING b = (*it);
		auto building = m_GameObjectManager->CreateBuilding(b.BuildingType.c_str(), b.Team, b.Name.c_str(), m_PhysicsStrategy);
		if(!building)
		{
			CORE_ERR("Error loading building.");
			return false;
		}
		building->SetHealth(b.Health);
		building->SetPosition(b.Position);
	}
	return true;
}

SceneNode* CSceneImporter::FindNode(String Name)
{
	try
	{
		return m_SceneManager->getSceneNode(Name);
	}
	catch(...)
	{
		// couldn't find the node
		return nullptr;
	}
}
