#ifndef __STRUCTURES_H__
#define __STRUCTURES_H__

#include "Defines.h"
#include "CoreStructures.h"
#include "PlayerEnums.h"
#include "PhysicsStructures.h"

#include "OgreColourValue.h"
#include "OgreCommon.h"
#include "OgreVector2.h"
#include "OgreVector4.h"

using namespace std;
using namespace Core;

namespace Core
{
	enum E_ANIM_STATE;
	enum E_BUILDING_STATE;
	enum E_BUILDING_CATEGORY;

	//***************************************** Static data ************************************************
	struct SCENEMANAGER
	{
		String		Name;
		String		Type;
		ColourValue Ambient;
		ColourValue FogColor;
		f32			FogDensity;
		f32			FogEnd;
		f32			FogStart;
		Ogre::FogMode FogMode;
		bool		SkyBoxActive;
		f32			SkyBoxDistance;
		String		SkyBoxMaterial;
	};

	struct CAMERA
	{
		String			Parent;
		String			Name;
		Vector2			ClipDistance;
		Vector3			LookAt;
		f32				Fov;
		Quaternion		Orientation;
		Vector3			Position;
		bool			Default;
		E_CAMERA_MODE	Type;
	};

	struct VIEWPORT
	{
		String			Parent;
		String			Name;
		ColourValue		Color;
		bool			Compositor0Enabled;
		String			Compositor0Name;
	};

	struct ARCHIVE
	{
		String			Name;
		String			FileName;
	};

	struct LIGHT
	{
		String		Parent;
		String		Name;
		Vector3		Position;
		Vector3		Diffuse;
		Vector3		Direction;
		LIGHT_TYPE	LightType;
		f32			Power;
		Vector3		Range;
		bool		Shadows;
		Vector3		Specular;
		Vector4		Attenuation;
		Degree		SpotlightInnerAngle;
		Degree		SpotlightOuterAngle;
		f32			SpotlightFalloff;
		f32			SpotlightNearClipDistance;
		bool		Visible;
		f32			ShadowFarDistance;
		f32			ShadowNearClipDistance;
		f32			ShadowFarClipDistance;
	};

	struct GAMEOBJECT
	{
		String		Parent;
		String		Name;
		String		MeshFile;
		Quaternion	Orientation;
		Vector3		Position;
		Vector3		Scale;
		bool		Shadows;
		String		ObstacleType;
		String		PhysicsProfileName;
	};

	struct PHYSICS_PROFILE
	{
		String	Name;
		f32		Restitution;
		f32		Friction;
		f32		Mass;
		f32		Density;
		Physics::E_PHYSICS_SHAPE Shape;
		Physics::E_BODY_TYPE	 BodyType;
	};

	struct CAELUM
	{
		String		Name;
		u32			TimeDay;
		u32			TimeHour;
		u32			TimeMinute;
		u32			TimeMonth;
		u32			TimeSec;
		u32			TimeSpeed;
		u32			TimeYear;
		bool		isClouds;
		u32			LayerOfClouds;
		u32			FogDenMultiplier;
		bool		isManageFog;
		u32			Layer;
		bool		isSingleLightSource;
		bool		isSingleShadowSource;
		bool		isManageAmbientLight;
		ColourValue	MinAmbientLight;
		ColourValue	MoonAmbientMultipler;
		u32			MoonAttMultipler;
		u32			MoonAttDistance;
		u32			MoonAttLinearMultipler;
		u32			MoonQuadMultipler;
		bool		isMoonAutoDisable;
		bool		isMoonCastShadow;
		ColourValue	MoonDiffuseMultipler;
		bool		isMoonEnabled;
		ColourValue	MoonSpecularMultipler;
		u32			ObserverLatitude;
		u32			ObserverLongitude;
		bool		isStarsEnabled;
		u32			StarsMag0PixelSize;
		f32			StarsMagScale;
		u32			StarsMaxPixelSize;
		u32			StarsMinPixelSize;
		ColourValue	SunAmbientMultipler;
		u32			SunAttMultipler;
		u32			SunDistance;
		u32			SunAttLinearMultipler;
		u32			SunQuadMultipler;
		bool		isSunAutoDisable;
		bool		isSunCastShadow;
		Vector3	SunColor;
		ColourValue	SunDiffuseMultipler;
		bool		isSunEnabled;
		Vector3	SunLightColor;
		Vector3	SunPosition;
		ColourValue	SunSpecularMultipler;

	};

	struct HYDRAX
	{
		String		Name;
		String		ConfigFile;
		bool		isCaelumItegrated;
		f32			CausticsEnd;
		u32			CausticsPower;
		u32			CausticsScale;
		bool		isComponentsCaustics;
		bool		isComponentsDepth;
		bool		isComponentsFoam;
		bool		isComponentsSmooth;
		bool		isComponentsSun;
		bool		isComponentsUnderwater;
		bool		isComponentsGodrays;
		bool		isComponentsReflections;
		f32			DepthLimit;
		f32			FoamMaxDistance;
		f32			FoamScale;
		f32			FoamStart;
		f32			FoamTransparency;
		f32			FullReflectionDistance;
		f32			GlobalTransparency;
		Vector3		GodraysExposure;
		f32			GodraysIntensity;
		bool		GodraysIntersections;
		u32			GodraysNumRays;
		f32			GodraysSize;
		f32			GodraysSpeed;
		u32			Layers;
		String		ModuleName;
		String		NoiseModuleName;
		f32			NormalDistortion;
		f32			PerlinAnimSpeed;
		f32			PerlinFalloff;
		Vector3		PerlinGpuLod;
		f32			PerlinGpuStrength;
		u32			PerlinOctaves;
		f32			PerlinScale;
		f32			PerlinTimeMulti;
		f32			PgmoduleChoppyStrength;
		bool		isPgmoduleChoppyWaves;
		u32			PgmoduleComplexity;
		u32			PgmoduleElevation;
		bool		isPgmoduleForceRecalculateGeometry;
		bool		isPgmoduleSmooth;
		u32			PgmoduleStrength;
		u32			PlanesError;
		Vector3		Position;
		u32			RttQualityDepth;
		u32			RttQualityDepthAip;
		u32			RttQualityDepthReflection;
		u32			RttQualityGpuNormalMap;
		u32			RttQualityReflection;
		u32			RttQualityRefraction;
		u32			ShaderMode;
		f32			SmoothPower;
		f32			SunArea;
		Vector3		SunColour;
		Vector3		SunPosition;
		f32			SunStrength;
		String		TechniqueAdd;
		String		TechniqueRemove;
		String		UpdateScript;
		Vector3		WaterColour;
	};

	struct BGSOUND
	{
		String		FileName;
		String		Name;
		bool		Loop;
		bool		Stream;
		f32			Gain;
	};

	struct SOUND
	{
		String		FileName;
		String		Name;
		bool		Loop;
		bool		Stream;
		bool		RelativeToListener;
		u32			Priority;
		f32			Gain;
		f32			MaxGain;
		f32			MinGain;
		f32			FadeIn;
		f32			FadeOut;
		f32			Pitch;
		f32			MaxDistance;
		f32			RollOffFactor;
		f32			RefDistance;
		f32			OuterConeGain;
		f32			InnerConeAngle;
		f32			OuterConeAngle;
		f32			SecondOffset;
		Vector3		Velocity;
		Vector3		Position;
		Vector3		Direction;
	};

	struct TERRAIN_TYPE
	{
		enum E_TERRAIN_TYPE
		{
			ETT_HEIGHT	 = 0,
			ETT_PAGED	 = 1,
			ETT_PLANE	 = 2
		};

		E_TERRAIN_TYPE TerrainType;
	};

	struct HEIGHT_TERRAIN : TERRAIN_TYPE
	{
		String		Name; 
		String		HeightmapImage;
		String		WorldTexture;
		String		DetailTexture;
		s32			DetailTile;
		u32			HeightmapRawSize;
		String		HeightmapRawBpp;
		s32			PageSize;
		u32			TileSize;
		u32			MaxPixelError;
		f32			PageWorldX;
		f32			PageWorldZ;
		f32			MaxHeight;
		s32			MaxMipMapLevel;
		bool		VertexNormals;
		bool		VertexColors;
		bool		UseTriStrips;
		bool		VertexProgramMorph;
		f32			LODMorphStart;
		String		MorphLODFactorParamName;
		u32			MorphLODFactorParamIndex;
		String		CustomMaterialName;
		Vector<String> Splatting;

		HEIGHT_TERRAIN() { TerrainType = TERRAIN_TYPE::ETT_HEIGHT; }
	};

	struct TERRAIN_LAYER
	{
		String	Diffuse;
		String	Normal;
		u32		WorldSize;
	};

	struct PAGED_TERRAIN : TERRAIN_TYPE
	{
		String		Name;
		String		TerrainFile;			// Defaults to "Page"
		bool		isColorMap;
		u32			TextureSize; 
		u32			ColorMapTextureSize;
		u32			LightMapTextureSize;
		u16			MapSize;
		s32			MinX;
		s32			MaxX;
		s32			MinY;
		s32			MaxY;
		u32			WorldSize;
		u32			PageDesityMapSize;
		u32			DetailDistance;
		u32			PageSize;
		u32			MaxPixelError;
		u16			MaxBatchSize;
		u16			MinBatchSize;
		String		ResourceGroup;
		Vector3		Position;				// Defaults to 0,0,0
		Vector<TERRAIN_LAYER> Layers;

		PAGED_TERRAIN() { TerrainType = TERRAIN_TYPE::ETT_PAGED; }
	};

	struct PLANE_TERRAIN : TERRAIN_TYPE
	{
		bool		isUsed;		// Are we using a plane terrain
		Vector3		Normal;		// Default is 0, 1, 0

		PLANE_TERRAIN() : isUsed(false) { TerrainType = TERRAIN_TYPE::ETT_PLANE; }
	};

	struct WATER
	{
		bool WaterVisible;
		f32 WaterWidthX;
		f32 WaterWidthZ;
		f32 WaterXPos;
		f32 WaterYPos;
		f32 WaterZPos;
		String WaterMaterial;
	};

	struct PROJECTILES
	{
		String		Name;
		String		Desc;
		f32			Damage;
		bool		Penetrate;
		f32			Speed;
		String		MeshFileName;
		String		BillboardBullet;
		String		BillboardFlash;
	};

	struct MAGAZINE
	{
		String		Name;
		String		Desc;
		String		Projectile;
		s32			Capacity;
		String		MeshFileName;
	};

	struct WEAPON
	{
		String		Name;			// Internal name
		String		Desc;			// Descriptional name
		bool		isSemi;			// Semi-auto
		bool		isBurst;		// Burst rounds
		bool		isAuto;			// Automatic
		u32			ROF;			// Rate of Fire
		String		MeshName;		// File name of the mesh to use
		String		OverlayName;	// Name to locate the overlay
		f32			Power;			// Power of the tool
		f32			Accuracy;
		String		MagType;		// Type of mag it will support (only one type for now)
		Vector3		Scale;			// Mesh scale (because its not a game object it has to be set manually)
		f32			Range;			// Range of the weapon
	};

	struct MELEE
	{
		String		Name;
		String		MeshName;
		String		Desc;
		f32			Power;
		f32			Range;
	};

	struct GEO_SET_SUBSET
	{
		Vector3		Position;
		Radian		Yaw;
		f32			Scale;
		void*		Data;

		GEO_SET_SUBSET() : Yaw(Degree(0)), Scale(1.0f), Data(0) { }
		GEO_SET_SUBSET(const Vector3& pos, const Radian& yaw, const f32& scale, void* data = nullptr)
			: Position(pos), Yaw(yaw), Scale(scale), Data(data) { }
	};

	// Passed to the veg system for every type of set of trees loaded
	struct GEO_SET
	{
		f32		BatchMax;
		f32		BatchStart;
		f32		ImposterMax;
		f32		ImposterStart;
		f32		PageSize;
		f32		HeightMin;
		f32		WidthMin;
		f32		HeightMax;
		f32		WidthMax;
		bool	isInfinte;
		Entity* Entity;					// Entity of the mesh name
		String	MeshName;				// Used for serializing.  If it has a .mesh then a custom mesh will be loaded
		String  MaterialName;
		String  DensityMap;
		String	PhysicsProfile;			// Only 3DP uses this

		enum GEO_LOAD_TYPE
		{
			GLT_TREE_3D		= 0,
			GLT_TREE_2D		= 1,
			GLT_GRASS		= 2,
			GLT_BUSH		= 3,
			GLT_TREE_3DP	= 4,
		} GeoType;

		Vector<GEO_SET_SUBSET> Objects;

		GEO_SET()
		{
			BatchMax = 200;
			BatchStart = 30;
			ImposterMax = 1000;
			ImposterStart = 50;
			PageSize = 50;
			HeightMin = -10000;
			WidthMin = -10000;
			HeightMax = 10000;
			WidthMax = 10000;
			isInfinte = true;
			Entity = nullptr;
			GeoType = GLT_TREE_3D;
		}
	};
	
	struct BILLBOARD
	{
		String	Name;
		u32		Type;
		u32		PoolSize;
		String	MaterialName;
		f32		Width;
		f32		Height;
	};

	struct ANIMATION_MAPPING
	{
		String	MeshName;
		
		struct SOUND_ANIMATION
		{
			E_ANIM_STATE AnimState;
			String		 AnimationName;
			String		 SoundName;
		};

		Vector<SOUND_ANIMATION> Animations;
	};

	// ************************************************* Dynamic Data **************************************
	struct AI_PATH
	{
		u32					PathId;			// Used to look up the path Id and the player Id relationship
		String				Name;			// Unique label name of the path points
		Vector<Vector3>		Points;			// Container of path points
	};

	struct PLACED_ITEM
	{
		String				ProfileName;
		Vector3				Position;
	};

	struct PLAYER_INVENTORY
	{
		String				ProfileName;
		bool				IsActive;		// Is it being used in the players hand
	};

	struct PLAYER
	{
		String				Name;
		Vector3				Position;
		f32					CrawlSpeed;
		f32					SprintSpeed;
		bool				IsHumanplayer;
		f32					ViewRange;
		f32					DieingTime;
		String				MovableText;
		String				PhysicsName;
		String				CharacterState;
		Vector3				Direction;
		String				PlayerType;
		f32					Health;
		E_PLAYER_TEAM		Team;
		f32					RunSpeed;
		f32					ReloadSpeed;
		f32					RifleMarksman;
		f32					PhysicalStrength;
		Vector<AI_PATH>		PlayerPaths;
		Vector<PLAYER_INVENTORY> PlayerInventory;
	};

	struct ASTAR_NODE
	{
		Vector3		Position;
		f32			Cost;
		s32			NodeId;
		Vector<s32> Neighbors;
	};

	struct ASTAR_GRID
	{
		Vector<ASTAR_NODE> Nodes;
	};

	struct SPAWN_POINT
	{
		SPAWN_POINT() : CoolDown(0.0f), Id(0) { }
		u32				Id;
		E_PLAYER_TEAM	Team;				// The team that owns the point
		Vector3			Position;
		f32				CoolDown;			// Countdown to be used again
	};

	struct BUILDING
	{
		BUILDING() : Health(0.0f) { }
		String				Name;
		String				BuildingType;
		Vector3				Position;
		E_BUILDING_CATEGORY	Category;
		E_BUILDING_STATE	State;
		f32					Health;
		E_PLAYER_TEAM		Team;
	};

	// ***************************************** Container for all the parsed data **************************** 
	struct DATA_CONTAINER
	{
		// Static data
		SCENEMANAGER				SceneManager;
		VIEWPORT					Viewport;
		CAELUM						Caelum;
		HYDRAX						Hydrax;
		HEIGHT_TERRAIN				HeightTerrain;
		PAGED_TERRAIN				PagedTerrain;
		PLANE_TERRAIN				PlaneTerrain;
		ASTAR_GRID					AStarGrid;
		Vector<LIGHT>				Lights;
		Vector<CAMERA>				Cameras;
		Vector<GAMEOBJECT>			GameObjects;
		Vector<WEAPON>				Weapons;
		Vector<MAGAZINE>			Magazines;
		Vector<PROJECTILES>			Projectiles;
		Vector<MELEE>				Melees;
		Vector<PHYSICS_PROFILE>		PhysicsProfiles;
		Vector<ARCHIVE>				Archives;
		Vector<WATER>				Waters;
		Vector<BGSOUND>				BgSounds;
		Vector<SOUND>				Sounds;
		Vector<BILLBOARD>			Billboards;
		Vector<GEO_SET>				GeoSets;
		Vector<ANIMATION_MAPPING>	AnimationMapping;
		String						StaticData;

		// Dynamic data
		Vector<AI_PATH>				AiPaths;
		Vector<PLACED_ITEM>			PlacedItems;
		Vector<PLAYER>				Players;
		Vector<SPAWN_POINT>			SpawnPoints;
		Vector<BUILDING>			Buildings;

		void Reset()
		{
			Lights.erase(Lights.begin(), Lights.end());
			Cameras.erase(Cameras.begin(), Cameras.end());
			GameObjects.erase(GameObjects.begin(), GameObjects.end());
			Weapons.erase(Weapons.begin(), Weapons.end());
			Magazines.erase(Magazines.begin(), Magazines.end());
			Projectiles.erase(Projectiles.begin(), Projectiles.end());
			PhysicsProfiles.erase(PhysicsProfiles.begin(), PhysicsProfiles.end());
			Archives.erase(Archives.begin(), Archives.end());
			Waters.erase(Waters.begin(), Waters.end());
			BgSounds.erase(BgSounds.begin(), BgSounds.end());
			Sounds.erase(Sounds.begin(), Sounds.end());
			Billboards.erase(Billboards.begin(), Billboards.end());
			GeoSets.erase(GeoSets.begin(), GeoSets.end());
			AnimationMapping.erase(AnimationMapping.begin(), AnimationMapping.end());
			AiPaths.erase(AiPaths.begin(), AiPaths.end());
			PlacedItems.erase(PlacedItems.begin(), PlacedItems.end());
			Players.erase(Players.begin(), Players.end());
			SpawnPoints.erase(SpawnPoints.begin(), SpawnPoints.end());
			Buildings.erase(Buildings.begin(), Buildings.end());
		}
	};
}

#endif // __STRUCTURES_H__