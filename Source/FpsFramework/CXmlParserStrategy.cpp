#include "CParserStrategies.h"
#include "IO/CoreLogging.h"
#include "IO/CFileSystem.h"
#include "Structures.h"
#include "AnimationMapping.h"

#include "OgreStringConverter.h"

using namespace Core;

CXmlParserStrategy::CXmlParserStrategy()
{
	PopulateAnimationMappingList();
}

CXmlParserStrategy::~CXmlParserStrategy()
{
	for(auto it = AnimationMappingList.begin(); it != AnimationMappingList.end(); it++)
	{
		CORE_DELETE((*it));
	}
	AnimationMappingList.clear();
}

bool CXmlParserStrategy::ParseScene(const String& FileName, DATA_CONTAINER& DataContainer)
{
	CFileSystem FileSystem;

	// Save the entire static data
	auto reader = FileSystem.CreateAndOpenFile(FileName.c_str());
	char* buffer = new char[reader->GetSize()];
	reader->Read(buffer);
	DataContainer.StaticData = String(buffer);

	CORE_DELETE(buffer);
	CORE_DELETE(reader);
	
	auto xml = FileSystem.CreateXMLReader(FileName.c_str());

	bool ret = ParseScene(*xml, DataContainer);
	CORE_DELETE(xml);
	assert(_CrtCheckMemory());
	return ret;
}

bool CXmlParserStrategy::ParseScene(IXMLReader& Xml, DATA_CONTAINER& DataContainer)
{
	while(Xml.Read())
    {
		if(XML_NODE_ELEMENT_END != Xml.GetNodeType())
		{
			String nodeName = String(Xml.GetNodeName());
			if (String("SceneManager") == nodeName)
			{
				LoadSceneManager(Xml, DataContainer);
			}
			else if (String("Viewport") == nodeName)
			{
				LoadViewport(Xml, DataContainer);
			}
			else if (String("Light") == nodeName)
			{
				LoadLight(Xml, DataContainer);
			}
			else if (String("Camera") == nodeName)
			{
				LoadCamera(Xml, DataContainer);
			}
			else if (String("GameObject") == nodeName)
			{
				LoadGameObject(Xml, DataContainer);
			}
			else if (String("PhysicsProfile") == nodeName)
			{
				LoadPhysicsProfile(Xml, DataContainer);
			}
			else if (String("Caelum") == nodeName)
			{
				LoadCaelum(Xml, DataContainer);
			}
			else if (String("Hydrax") == nodeName)
			{
				LoadHydrax(Xml, DataContainer);
			}
			else if (String("BgSound") == nodeName)
			{
				LoadBgSound(Xml, DataContainer);
			}
			else if(String("Sound") == nodeName)
			{
				LoadSound(Xml, DataContainer);
			}
			else if (String("Water") == nodeName)
			{
				LoadWater(Xml, DataContainer);
			}
			else if (String("Weapon") == nodeName)
			{
				LoadWeapon(Xml, DataContainer);
			}
			else if (String("Magazine") == nodeName)
			{
				LoadMagazine(Xml, DataContainer);
			}
			else if (String("Projectile") == nodeName)
			{
				LoadProjectile(Xml, DataContainer);
			}
			else if (String("Melee") == nodeName)
			{
				LoadMelee(Xml, DataContainer);
			}
			else if (String("PagedTerrain") == nodeName)
			{
				LoadPagedTerrain(Xml, DataContainer);
			}
			else if (String("HeightTerrain") == nodeName)
			{
				LoadHeightTerrain(Xml, DataContainer);
			}
			else if (String("PlaneTerrain") == nodeName)
			{
				LoadPlaneTerrain(Xml, DataContainer);
			}
			else if (String("Archive") == nodeName)
			{
				LoadArchive(Xml, DataContainer);
			}
			else if (String("BillBoard") == nodeName)
			{
				LoadBillboard(Xml, DataContainer);
			}
			else if (String("PagedGeometry") == nodeName)
			{
				LoadPagedGeometry(Xml, DataContainer);
			}
			else if(String("AnimationMapping") == nodeName)
			{
				LoadAnimationMapping(Xml, DataContainer);
			}
			else
			{
				if(nodeName.length() > 0)
				{
					String msg = "Unknown xml tag: " + nodeName;
					CORE_ERR(msg.c_str());
				}
			}

		} // XML_NODE_ELEMENT_END
    } // while

	return true;
}

void CXmlParserStrategy::LoadSceneManager(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	u32 Count = 0;
	while(Count < xml.GetAttributeCount())
	{
		if (String("ambient") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.Ambient = StringConverter::parseColourValue(xml.GetAttributeValue("ambient"));
		}
		else if (String("fogcolour") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.FogColor = StringConverter::parseColourValue(xml.GetAttributeValue("fogcolour"));
		}
		else if (String("fogdensity") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.FogDensity = StringConverter::parseReal(xml.GetAttributeValue("fogdensity"));
		}
		else if (String("fogend") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.FogEnd = StringConverter::parseReal(xml.GetAttributeValue("fogend"));
		}
		else if (String("fogmode") == xml.GetAttributeName(Count))
		{
			if(xml.GetAttributeValue("fogmode") == String("FOG_EXP"))
				DataContainer.SceneManager.FogMode = FOG_EXP;
			else if(xml.GetAttributeValue("fogmode") == String("FOG_EXP2"))
				DataContainer.SceneManager.FogMode = FOG_EXP2;
			else if(xml.GetAttributeValue("fogmode") == String("FOG_LINEAR"))
				DataContainer.SceneManager.FogMode = FOG_LINEAR;
			else
				DataContainer.SceneManager.FogMode = FOG_NONE;
		}
		else if (String("fogstart") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.FogStart = StringConverter::parseReal(xml.GetAttributeValue("fogstart"));
		}
		else if (String("name") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.Name = xml.GetAttributeValueSafe("name");
		}
		else if (String("scenemanagertype") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.Type = xml.GetAttributeValueSafe("scenemanagertype");
		}
		else if (String("skyboxactive") == xml.GetAttributeName(Count))
		{
			if(xml.GetAttributeValue("skyboxactive") == String("true"))
				DataContainer.SceneManager.SkyBoxActive = true;
			else
				DataContainer.SceneManager.SkyBoxActive = false;
		}
		else if (String("skyboxdistance") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.SkyBoxDistance = StringConverter::parseReal(xml.GetAttributeValue("skyboxdistance"));
		}
		else if (String("skyboxmaterial") == xml.GetAttributeName(Count))
		{
			DataContainer.SceneManager.SkyBoxMaterial = xml.GetAttributeValueSafe("skyboxmaterial");
		}
		Count++;
	}
}

void CXmlParserStrategy::LoadViewport(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	u32 Count = 0;
	while(Count < xml.GetAttributeCount())
	{
		if (String("parentnode") == xml.GetAttributeName(Count))
		{
			DataContainer.Viewport.Parent = xml.GetAttributeValueSafe("parentnode");
		}
		else if (String("colour") == xml.GetAttributeName(Count))
		{
			DataContainer.Viewport.Color = StringConverter::parseColourValue(xml.GetAttributeValue("colour"));
		}
		else if (String("compositor0enabled") == xml.GetAttributeName(Count))
		{
			if(xml.GetAttributeValue("compositor0enabled") == String("false"))
				DataContainer.Viewport.Compositor0Enabled = false;
			else
				DataContainer.Viewport.Compositor0Enabled = true;
		}
		else if (String("compositor0name") == xml.GetAttributeName(Count))
		{
			DataContainer.Viewport.Compositor0Name = xml.GetAttributeValueSafe("compositor0name");
		}
		else if (String("name") == xml.GetAttributeName(Count))
		{
			DataContainer.Viewport.Name = xml.GetAttributeValueSafe("name");;
		}
		Count++;
	}
}

void CXmlParserStrategy::LoadLight(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	LIGHT light;
	u32 Count = 0;
	while(Count < xml.GetAttributeCount())
	{
		if (String("parentnode") == xml.GetAttributeName(Count))
		{
			char str[MAX_NAME];
			strncpy(str, xml.GetAttributeValue("parentnode"), MAX_NAME);
			light.Parent = str;
		}
		else if (String("attenuation") == xml.GetAttributeName(Count))
		{
			light.Attenuation = StringConverter::parseVector4(xml.GetAttributeValue("attenuation"));
		}
		else if (String("diffuse") == xml.GetAttributeName(Count))
		{
			light.Diffuse = StringConverter::parseVector3(xml.GetAttributeValue("diffuse"));
		}
		else if (String("direction") == xml.GetAttributeName(Count))
		{
			light.Direction = StringConverter::parseVector3(xml.GetAttributeValue("direction"));
		}
		else if (String("lighttype") == xml.GetAttributeName(Count))
		{
			if( xml.GetAttributeValue("lighttype") == String("point"))
				light.LightType = LT_POINT;
			else if( xml.GetAttributeValue("lighttype") == String("directional"))
				light.LightType = LT_DIRECTIONAL;
			else
				light.LightType = LT_SPOT;
		}
		else if (String("name") == xml.GetAttributeName(Count))
		{
			char str[MAX_NAME];
			strncpy(str, xml.GetAttributeValue("name"), MAX_NAME);
			light.Name = str;
		}
		else if (String("position") == xml.GetAttributeName(Count))
		{
			light.Position = StringConverter::parseVector3(xml.GetAttributeValue("position"));
		}
		else if (String("power") == xml.GetAttributeName(Count))
		{
			light.Power = StringConverter::parseReal(xml.GetAttributeValue("power"));
		}
		else if (String("range") == xml.GetAttributeName(Count))
		{
			light.Range = StringConverter::parseVector3(xml.GetAttributeValue("range"));
		}
		else if (String("shadows") == xml.GetAttributeName(Count))
		{
			light.Shadows = StringConverter::parseBool(xml.GetAttributeValue("shadows"));
		}
		else if (String("specular") == xml.GetAttributeName(Count))
		{
			light.Specular = StringConverter::parseVector3(xml.GetAttributeValue("specular"));
		}
		else if (String("attrang") == xml.GetAttributeName(Count))
		{
			light.Attenuation.x = StringConverter::parseReal(xml.GetAttributeValue("attrang"));
		}
		else if (String("attconst") == xml.GetAttributeName(Count))
		{
			light.Attenuation.y = StringConverter::parseReal(xml.GetAttributeValue("attconst"));
		}
		else if (String("attlin") == xml.GetAttributeName(Count))
		{
			light.Attenuation.z = StringConverter::parseReal(xml.GetAttributeValue("attlin"));
		}
		else if (String("attquad") == xml.GetAttributeName(Count))
		{
			light.Attenuation.w = StringConverter::parseReal(xml.GetAttributeValue("attquad"));
		}
		else if (String("spotinner") == xml.GetAttributeName(Count))
		{
			light.SpotlightInnerAngle = Degree(StringConverter::parseInt(xml.GetAttributeValue("spotinner")));
		}
		else if (String("spotoutter") == xml.GetAttributeName(Count))
		{
			light.SpotlightOuterAngle = Degree(StringConverter::parseInt(xml.GetAttributeValue("spotoutter")));
		}
		else if (String("spotfalloff") == xml.GetAttributeName(Count))
		{
			light.SpotlightFalloff = StringConverter::parseReal(xml.GetAttributeValue("spotfalloff"));
		}
		else if (String("spotnearclip") == xml.GetAttributeName(Count))
		{
			light.SpotlightNearClipDistance = StringConverter::parseReal(xml.GetAttributeValue("spotnearclip"));
		}
		else if (String("visible") == xml.GetAttributeName(Count))
		{
			light.Visible = StringConverter::parseBool(xml.GetAttributeValue("visible"));
		}
		else if (String("shadfardis") == xml.GetAttributeName(Count))
		{
			light.ShadowFarDistance = StringConverter::parseReal(xml.GetAttributeValue("shadfardis"));
		}
		else if (String("shadnearclipdis") == xml.GetAttributeName(Count))
		{
			light.ShadowNearClipDistance = StringConverter::parseReal(xml.GetAttributeValue("shadnearclipdis"));
		}
		else if (String("shadnfarclipdis") == xml.GetAttributeName(Count))
		{
			light.ShadowFarClipDistance = StringConverter::parseReal(xml.GetAttributeValue("shadnfarclipdis"));
		}
		Count++;
	}
	DataContainer.Lights.push_back(light);
}

void CXmlParserStrategy::LoadCamera(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	CAMERA camera;
	camera.Type = ECM_NONE;

	u32 Count = 0;
	while(Count < xml.GetAttributeCount())
	{
		if (String("parentnode") == xml.GetAttributeName(Count))
		{
			camera.Parent = xml.GetAttributeValueSafe("parentnode");
		}
		else if (String("clipdistance") == xml.GetAttributeName(Count))
		{
			camera.ClipDistance = StringConverter::parseVector2(xml.GetAttributeValue("clipdistance"));
		}
		else if (String("fov") == xml.GetAttributeName(Count))
		{
			camera.Fov = StringConverter::parseReal(xml.GetAttributeValue("fov"));
		}
		else if (String("name") == xml.GetAttributeName(Count))
		{
			camera.Name = xml.GetAttributeValueSafe("name");
		}
		else if (String("orientation") == xml.GetAttributeName(Count))
		{
			camera.Orientation = StringConverter::parseQuaternion(xml.GetAttributeValue("orientation"));
		}
		else if (String("position") == xml.GetAttributeName(Count))
		{
			camera.Position = StringConverter::parseVector3(xml.GetAttributeValue("position"));
		}
		else if (String("lookat") == xml.GetAttributeName(Count))
		{
			camera.LookAt = StringConverter::parseVector3(xml.GetAttributeValue("lookat"));
		}
		else if (String("default") == xml.GetAttributeName(Count))
		{
			if(xml.GetAttributeValue("default") == String("true"))
				camera.Default = true;
			else
				camera.Default = false;
		}
		else if (String("type") == xml.GetAttributeName(Count))
		{
			if(xml.GetAttributeValueSafe("type") == String("chase"))
				camera.Type = ECM_CHASE;
			else if(xml.GetAttributeValueSafe("type") == String("fixed"))
				camera.Type = ECM_FIXED;
			else if(xml.GetAttributeValueSafe("type") == String("fps"))
				camera.Type = ECM_FPS;
			else if(xml.GetAttributeValueSafe("type") == String("topdown"))
				camera.Type = ECM_TOP_DOWN;
			else if(xml.GetAttributeValueSafe("type") == String("side"))
				camera.Type = ECM_SIDE;
			else if(xml.GetAttributeValueSafe("type") == String("free"))
				camera.Type = ECM_FREE;
			else if(xml.GetAttributeValueSafe("type") == String("god"))
				camera.Type = ECM_GOD;
			else if(xml.GetAttributeValueSafe("type") == String("rts"))
				camera.Type = ECM_RTS;
			else if(xml.GetAttributeValueSafe("type") == String("spring"))
				camera.Type = ECM_SPRING;
		}
		Count++;
	}
	DataContainer.Cameras.push_back(camera);
}

void CXmlParserStrategy::LoadGameObject(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	GAMEOBJECT gameObject;
	u32 Count = 0;
	while(Count < xml.GetAttributeCount())
	{
		if (String("parent") == xml.GetAttributeName(Count))
		{
			gameObject.Parent = xml.GetAttributeValueSafe("parent");
		}
		else if (String("meshfile") == xml.GetAttributeName(Count))
		{
			gameObject.MeshFile = xml.GetAttributeValueSafe("meshfile");
		}
		else if (String("shadows") == xml.GetAttributeName(Count))
		{
			if( xml.GetAttributeValue("shadows") == String("true"))
				gameObject.Shadows = true;
			else
				gameObject.Shadows = false;
		}
		else if (String("name") == xml.GetAttributeName(Count))
		{
			gameObject.Name = xml.GetAttributeValueSafe("name");
		}
		else if (String("orientation") == xml.GetAttributeName(Count))
		{
			gameObject.Orientation = StringConverter::parseQuaternion(xml.GetAttributeValue("orientation"));
		}
		else if (String("position") == xml.GetAttributeName(Count))
		{
			gameObject.Position = StringConverter::parseVector3(xml.GetAttributeValue("position"));
		}
		else if (String("scale") == xml.GetAttributeName(Count))
		{
			gameObject.Scale = StringConverter::parseVector3(xml.GetAttributeValue("scale"));
		}
		else if (String("obstacletype") == xml.GetAttributeName(Count))
		{
			gameObject.ObstacleType = xml.GetAttributeValueSafe("obstacletype");
		}
		else if (String("physicsprofilename") == xml.GetAttributeName(Count))
		{
			gameObject.PhysicsProfileName = xml.GetAttributeValueSafe("physicsprofilename");
		}

		Count++;
	}
	DataContainer.GameObjects.push_back(gameObject);
}

void CXmlParserStrategy::LoadPhysicsProfile(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	PHYSICS_PROFILE profile;
	profile.Restitution = 0;
	profile.Friction = 0;
	profile.Mass = 0;
	profile.BodyType = Physics::NONE;
	profile.Shape = Physics::SHAPE_CUBE;

	String str;

	// Name
	profile.Name = xml.GetAttributeValueSafe("name");

	// Shape
	str = xml.GetAttributeValueSafe("shape");
	if(str == "cube")
		profile.Shape = Physics::SHAPE_CUBE;
	else if(str == "sphere")
		profile.Shape = Physics::SHAPE_SPHERE;
	else if(str == "capsule")
		profile.Shape = Physics::SHAPE_CAPSULE;

	// Body type
	str = xml.GetAttributeValueSafe("bodytype");
	if(str.length() > 0)
		profile.BodyType = (Physics::E_BODY_TYPE)StringConverter::parseUnsignedInt(str);

	// Restitution
	str = xml.GetAttributeValueSafe("restitution");
	if(str.length() > 0)
		profile.Restitution = StringConverter::parseReal(str);

	// Friction
	str = xml.GetAttributeValueSafe("friction");
	if(str.length() > 0)
		profile.Friction = StringConverter::parseReal(str);

	// Mass
	str = xml.GetAttributeValueSafe("mass");
	if(str.length() > 0)
		profile.Mass = StringConverter::parseReal(str);

	// Density
	str = xml.GetAttributeValueSafe("density");
	if(str.length() > 0)
		profile.Density = StringConverter::parseReal(str);

	DataContainer.PhysicsProfiles.push_back(profile);
}

void CXmlParserStrategy::LoadCaelum(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	String str;

	DataContainer.Caelum.Name = xml.GetAttributeValueSafe("name");

	// TimeDay
	str = xml.GetAttributeValueSafe("timeday");
	if(str.length() > 0)
		DataContainer.Caelum.TimeDay = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.TimeDay = 1;

	// TimeHour
	str = xml.GetAttributeValueSafe("timehour");
	if(str.length() > 0)
		DataContainer.Caelum.TimeHour = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.TimeHour = 12;

	// TimeMinute
	str = xml.GetAttributeValueSafe("timeminute");
	if(str.length() > 0)
		DataContainer.Caelum.TimeMinute = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.TimeMinute = 0;

	// TimeMonth
	str = xml.GetAttributeValueSafe("timemonth");
	if(str.length() > 0)
		DataContainer.Caelum.TimeMonth = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.TimeMonth = 1;

	// TimeSec
	str = xml.GetAttributeValueSafe("timesec");
	if(str.length() > 0)
		DataContainer.Caelum.TimeSec = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.TimeSec = 0;

	// TimeSpeed
	str = xml.GetAttributeValueSafe("timespeed");
	if(str.length() > 0)
		DataContainer.Caelum.TimeSpeed = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.TimeSpeed = 1;

	// TimeYear
	str = xml.GetAttributeValueSafe("timeyear");
	if(str.length() > 0)
		DataContainer.Caelum.TimeYear = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.TimeYear = 2000;

	// isClouds
	str = xml.GetAttributeValueSafe("isclouds");
	if(str.length() > 0)
		DataContainer.Caelum.isClouds = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isClouds = false;

	// LayerOfClouds
	str = xml.GetAttributeValueSafe("layerofclouds");
	if(str.length() > 0)
		DataContainer.Caelum.LayerOfClouds = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.LayerOfClouds = 1;

	// FogDenMultiplier
	str = xml.GetAttributeValueSafe("fogdenmultiplier");
	if(str.length() > 0)
		DataContainer.Caelum.FogDenMultiplier = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.FogDenMultiplier = 0;

	// isManageFog
	str = xml.GetAttributeValueSafe("ismanagefog");
	if(str.length() > 0)
		DataContainer.Caelum.isManageFog = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isManageFog = false;

	// Layer
	str = xml.GetAttributeValueSafe("layer");
	if(str.length() > 0)
		DataContainer.Caelum.Layer = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.Layer = 0;

	// isSingleLightSource
	str = xml.GetAttributeValueSafe("issinglelightsource");
	if(str.length() > 0)
		DataContainer.Caelum.isSingleLightSource = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isSingleLightSource = false;

	// isSingleShadowSource
	str = xml.GetAttributeValueSafe("issingleshadowsource");
	if(str.length() > 0)
		DataContainer.Caelum.isSingleShadowSource = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isSingleShadowSource = false;

	// isManageAmbientLight
	str = xml.GetAttributeValueSafe("ismanageambientlight");
	if(str.length() > 0)
		DataContainer.Caelum.isManageAmbientLight = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isManageAmbientLight = false;

	// MinAmbientLight
	str = xml.GetAttributeValueSafe("minambientlight");
	if(str.length() > 0)
		DataContainer.Caelum.MinAmbientLight = StringConverter::parseColourValue(str);
	else
		DataContainer.Caelum.MinAmbientLight = ColourValue(0, 0, 0);

	// MoonAmbientMultipler
	str = xml.GetAttributeValueSafe("moonambientmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.MoonAmbientMultipler = StringConverter::parseColourValue(str);
	else
		DataContainer.Caelum.MoonAmbientMultipler = ColourValue(0, 0, 0);

	// MoonAttMultipler
	str = xml.GetAttributeValueSafe("moonattmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.MoonAttMultipler = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.MoonAttMultipler = 0;

	// MoonAttDistance
	str = xml.GetAttributeValueSafe("moonattdistance");
	if(str.length() > 0)
		DataContainer.Caelum.MoonAttDistance = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.MoonAttDistance = 0;

	// MoonAttLinearMultipler
	str = xml.GetAttributeValueSafe("moonattlinearmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.MoonAttLinearMultipler = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.MoonAttLinearMultipler = 0;

	// MoonQuadMultipler
	str = xml.GetAttributeValueSafe("moonquadmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.MoonQuadMultipler = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.MoonQuadMultipler = 0;

	// isMoonAutoDisable
	str = xml.GetAttributeValueSafe("ismoonautodisable");
	if(str.length() > 0)
		DataContainer.Caelum.isMoonAutoDisable = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isMoonAutoDisable = false;

	// isMoonCastShadow
	str = xml.GetAttributeValueSafe("ismooncastshadow");
	if(str.length() > 0)
		DataContainer.Caelum.isMoonCastShadow = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isMoonCastShadow = false;

	// MoonDiffuseMultipler
	str = xml.GetAttributeValueSafe("moondiffusemultipler");
	if(str.length() > 0)
		DataContainer.Caelum.MoonDiffuseMultipler = StringConverter::parseColourValue(str);
	else
		DataContainer.Caelum.MoonDiffuseMultipler = ColourValue(0, 0, 0);

	// isMoonEnabled
	str = xml.GetAttributeValueSafe("ismoonenabled");
	if(str.length() > 0)
		DataContainer.Caelum.isMoonEnabled = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isMoonEnabled = false;

	// MoonSpecularMultipler
	str = xml.GetAttributeValueSafe("moonspecularmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.MoonSpecularMultipler = StringConverter::parseColourValue(str);
	else
		DataContainer.Caelum.MoonSpecularMultipler = ColourValue(0, 0, 0);

	// ObserverLatitude
	str = xml.GetAttributeValueSafe("observerlatitude");
	if(str.length() > 0)
		DataContainer.Caelum.ObserverLatitude = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.ObserverLatitude = 0;

	// ObserverLongitude
	str = xml.GetAttributeValueSafe("observerlongitude");
	if(str.length() > 0)
		DataContainer.Caelum.ObserverLongitude = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.ObserverLongitude = 0;

	// isStarsEnabled
	str = xml.GetAttributeValueSafe("isstarsenabled");
	if(str.length() > 0)
		DataContainer.Caelum.isStarsEnabled = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isStarsEnabled = false;

	// StarsMag0PixelSize
	str = xml.GetAttributeValueSafe("starsmag0pixelsize");
	if(str.length() > 0)
		DataContainer.Caelum.StarsMag0PixelSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.StarsMag0PixelSize = 0;

	// StarsMagScale
	str = xml.GetAttributeValueSafe("starsmagscale");
	if(str.length() > 0)
		DataContainer.Caelum.StarsMagScale = StringConverter::parseReal(str);
	else
		DataContainer.Caelum.StarsMagScale = 0.0f;

	// StarsMaxPixelSize
	str = xml.GetAttributeValueSafe("starsmaxpixelsize");
	if(str.length() > 0)
		DataContainer.Caelum.StarsMaxPixelSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.StarsMaxPixelSize = 0;

	// StarsMinPixelSize
	str = xml.GetAttributeValueSafe("starsminpixelsize");
	if(str.length() > 0)
		DataContainer.Caelum.StarsMinPixelSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.StarsMinPixelSize = 0;

	// SunAmbientMultipler
	str = xml.GetAttributeValueSafe("sunambientmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.SunAmbientMultipler = StringConverter::parseColourValue(str);
	else
		DataContainer.Caelum.SunAmbientMultipler = ColourValue(0, 0, 0);

	// SunAttMultipler
	str = xml.GetAttributeValueSafe("sunattmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.SunAttMultipler = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.SunAttMultipler = 0;

	// SunDistance
	str = xml.GetAttributeValueSafe("sundistance");
	if(str.length() > 0)
		DataContainer.Caelum.SunDistance = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.SunDistance = 0;

	// SunAttLinearMultipler
	str = xml.GetAttributeValueSafe("sunattlinearmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.SunAttLinearMultipler = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.SunAttLinearMultipler = 0;

	// SunQuadMultipler
	str = xml.GetAttributeValueSafe("sunquadmultipler");
	if(str.length() > 0)
		DataContainer.Caelum.SunQuadMultipler = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Caelum.SunQuadMultipler = 0;

	// isSunAutoDisable
	str = xml.GetAttributeValueSafe("issunautodisable");
	if(str.length() > 0)
		DataContainer.Caelum.isSunAutoDisable = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isSunAutoDisable = false;

	// isSunCastShadow
	str = xml.GetAttributeValueSafe("issuncastshadow");
	if(str.length() > 0)
		DataContainer.Caelum.isSunCastShadow = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isSunCastShadow = false;

	// SunColor
	str = xml.GetAttributeValueSafe("suncolor");
	if(str.length() > 0)
		DataContainer.Caelum.SunColor = StringConverter::parseVector3(str);
	else
		DataContainer.Caelum.SunColor = Vector3(0, 0, 0);

	// SunDiffuseMultipler
	str = xml.GetAttributeValueSafe("sundiffusemultipler");
	if(str.length() > 0)
		DataContainer.Caelum.SunDiffuseMultipler = StringConverter::parseColourValue(str);
	else
		DataContainer.Caelum.SunDiffuseMultipler = ColourValue(0, 0, 0);

	// isSunEnabled
	str = xml.GetAttributeValueSafe("issunenabled");
	if(str.length() > 0)
		DataContainer.Caelum.isSunEnabled = StringConverter::parseBool(str);
	else
		DataContainer.Caelum.isSunEnabled = false;

	// SunLightColor
	str = xml.GetAttributeValueSafe("sunlightcolor");
	if(str.length() > 0)
		DataContainer.Caelum.SunLightColor = StringConverter::parseVector3(str);
	else
		DataContainer.Caelum.SunLightColor = Vector3(0, 0, 0);

	// SunPosition
	str = xml.GetAttributeValueSafe("sunposition");
	if(str.length() > 0)
		DataContainer.Caelum.SunPosition = StringConverter::parseVector3(str);
	else
		DataContainer.Caelum.SunPosition = Vector3(0, 5000, 0);

	// SunSpecularMultipler
	str = xml.GetAttributeValueSafe("sundiffusemultipler");
	if(str.length() > 0)
		DataContainer.Caelum.SunSpecularMultipler = StringConverter::parseColourValue(str);
	else
		DataContainer.Caelum.SunSpecularMultipler = ColourValue(0, 0, 0);

}

void CXmlParserStrategy::LoadHydrax(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	String str;		// temp var

	DataContainer.Hydrax.Name = xml.GetAttributeValueSafe("name");
	DataContainer.Hydrax.ConfigFile = xml.GetAttributeValueSafe("configfile");
	DataContainer.Hydrax.ModuleName = xml.GetAttributeValueSafe("modulename");
	DataContainer.Hydrax.NoiseModuleName = xml.GetAttributeValueSafe("noisemodulename");
	DataContainer.Hydrax.TechniqueAdd = xml.GetAttributeValueSafe("techniqueadd");
	DataContainer.Hydrax.TechniqueRemove = xml.GetAttributeValueSafe("techniqueremove");
	DataContainer.Hydrax.UpdateScript = xml.GetAttributeValueSafe("updatescript");

#pragma region bools

	// isCaelumItegrated
	str = xml.GetAttributeValueSafe("iscaelumitegrated");
	if(str == "true")
		DataContainer.Hydrax.isCaelumItegrated = true;
	else
		DataContainer.Hydrax.isCaelumItegrated = false;

	// isComponentsCaustics
	str = xml.GetAttributeValueSafe("iscomponentscaustics");
	if(str == "true")
		DataContainer.Hydrax.isComponentsCaustics = true;
	else
		DataContainer.Hydrax.isComponentsCaustics = false;

	// isComponentsDepth
	str = xml.GetAttributeValueSafe("iscomponentsdepth");
	if(str == "true")
		DataContainer.Hydrax.isComponentsDepth = true;
	else
		DataContainer.Hydrax.isComponentsDepth = false;

	// isComponentsFoam
	str = xml.GetAttributeValueSafe("iscomponentsfoam");
	if(str == "true")
		DataContainer.Hydrax.isComponentsFoam = true;
	else
		DataContainer.Hydrax.isComponentsFoam = false;

	// isComponentsSmooth
	str = xml.GetAttributeValueSafe("iscomponentssmooth");
	if(str == "true")
		DataContainer.Hydrax.isComponentsSmooth = true;
	else
		DataContainer.Hydrax.isComponentsSmooth = false;

	// isComponentsSun
	str = xml.GetAttributeValueSafe("iscomponentssun");
	if(str == "true")
		DataContainer.Hydrax.isComponentsSun = true;
	else
		DataContainer.Hydrax.isComponentsSun = false;

	// isComponentsUnderwater
	str = xml.GetAttributeValueSafe("iscomponentsunderwater");
	if(str == "true")
		DataContainer.Hydrax.isComponentsUnderwater = true;
	else
		DataContainer.Hydrax.isComponentsUnderwater = false;

	// isComponentsGodrays
	str = xml.GetAttributeValueSafe("iscomponentsgodrays");
	if(str == "true")
		DataContainer.Hydrax.isComponentsGodrays = true;
	else
		DataContainer.Hydrax.isComponentsGodrays = false;

	// isComponentsReflections
	str = xml.GetAttributeValueSafe("iscomponentsreflections");
	if(str == "true")
		DataContainer.Hydrax.isComponentsReflections = true;
	else
		DataContainer.Hydrax.isComponentsReflections = false;

	// GodraysIntersections
	str = xml.GetAttributeValueSafe("godraysintersections");
	if(str == "true")
		DataContainer.Hydrax.GodraysIntersections = true;
	else
		DataContainer.Hydrax.GodraysIntersections = false;

	// isPgmoduleChoppyWaves
	str = xml.GetAttributeValueSafe("ispgmodulechoppywaves");
	if(str == "true")
		DataContainer.Hydrax.isPgmoduleChoppyWaves = true;
	else
		DataContainer.Hydrax.isPgmoduleChoppyWaves = false;

	// isPgmoduleForceRecalculateGeometry
	str = xml.GetAttributeValueSafe("ispgmoduleFforcerecalculategeometry");
	if(str == "true")
		DataContainer.Hydrax.isPgmoduleForceRecalculateGeometry = true;
	else
		DataContainer.Hydrax.isPgmoduleForceRecalculateGeometry = false;

	// isPgmoduleSmooth
	str = xml.GetAttributeValueSafe("ispgmodulesmooth");
	if(str == "true")
		DataContainer.Hydrax.isPgmoduleSmooth = true;
	else
		DataContainer.Hydrax.isPgmoduleSmooth = false;

#pragma endregion

#pragma region floats

	// CausticsEnd
	str = xml.GetAttributeValueSafe("causticsend");
	if(str.length() > 0)
		DataContainer.Hydrax.CausticsEnd = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.CausticsEnd = 0.0;

	// DepthLimit
	str = xml.GetAttributeValueSafe("depthlimit");
	if(str.length() > 0)
		DataContainer.Hydrax.DepthLimit = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.DepthLimit = 0.0;

	// FoamMaxDistance
	str = xml.GetAttributeValueSafe("foammaxdistance");
	if(str.length() > 0)
		DataContainer.Hydrax.FoamMaxDistance = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.FoamMaxDistance = 0.0;

	// FoamScale
	str = xml.GetAttributeValueSafe("foamscale");
	if(str.length() > 0)
		DataContainer.Hydrax.FoamScale = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.FoamScale = 0.0;

	// FoamStart
	str = xml.GetAttributeValueSafe("foamstart");
	if(str.length() > 0)
		DataContainer.Hydrax.FoamStart = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.FoamStart = 0.0;

	// FoamTransparency
	str = xml.GetAttributeValueSafe("foamtransparency");
	if(str.length() > 0)
		DataContainer.Hydrax.FoamTransparency = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.FoamTransparency = 0.0;

	// FullReflectionDistance
	str = xml.GetAttributeValueSafe("fullreflectiondistance");
	if(str.length() > 0)
		DataContainer.Hydrax.FullReflectionDistance = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.FullReflectionDistance = 0.0;

	// GlobalTransparency
	str = xml.GetAttributeValueSafe("globaltransparency");
	if(str.length() > 0)
		DataContainer.Hydrax.GlobalTransparency = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.GlobalTransparency = 0.0;

	// GodraysIntensity
	str = xml.GetAttributeValueSafe("godraysintensity");
	if(str.length() > 0)
		DataContainer.Hydrax.GodraysIntensity = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.GodraysIntensity = 0.0;

	// GodraysNumRays
	str = xml.GetAttributeValueSafe("godraysnumrays");
	if(str.length() > 0)
		DataContainer.Hydrax.GodraysNumRays = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.GodraysNumRays = 0;

	// GodraysSpeed
	str = xml.GetAttributeValueSafe("godraysspeed");
	if(str.length() > 0)
		DataContainer.Hydrax.GodraysSpeed = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.GodraysSpeed = 0.0;

	// GodraysSize
	str = xml.GetAttributeValueSafe("godrayssize");
	if(str.length() > 0)
		DataContainer.Hydrax.GodraysSize = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.GodraysSize = 1.0;

	// NormalDistortion
	str = xml.GetAttributeValueSafe("normaldistortion");
	if(str.length() > 0)
		DataContainer.Hydrax.NormalDistortion = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.NormalDistortion = 0.0;

	// PerlinAnimSpeed
	str = xml.GetAttributeValueSafe("perlinanimspeed");
	if(str.length() > 0)
		DataContainer.Hydrax.PerlinAnimSpeed = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.PerlinAnimSpeed = 0.0;

	// PerlinFalloff
	str = xml.GetAttributeValueSafe("perlinfalloff");
	if(str.length() > 0)
		DataContainer.Hydrax.PerlinFalloff = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.PerlinFalloff = 0.0;

	// PerlinGpuStrength
	str = xml.GetAttributeValueSafe("perlingpustrength");
	if(str.length() > 0)
		DataContainer.Hydrax.PerlinGpuStrength = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.PerlinGpuStrength = 0.0;

	// PerlinScale
	str = xml.GetAttributeValueSafe("perlinscale");
	if(str.length() > 0)
		DataContainer.Hydrax.PerlinScale = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.PerlinScale = 0.0;

	// PerlinTimeMulti
	str = xml.GetAttributeValueSafe("perlintimemulti");
	if(str.length() > 0)
		DataContainer.Hydrax.PerlinTimeMulti = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.PerlinTimeMulti = 0.0;

	// PgmoduleChoppyStrength
	str = xml.GetAttributeValueSafe("pgmodulechoppystrength");
	if(str.length() > 0)
		DataContainer.Hydrax.PgmoduleChoppyStrength = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.PgmoduleChoppyStrength = 0.0;

	// SmoothPower
	str = xml.GetAttributeValueSafe("smoothpower");
	if(str.length() > 0)
		DataContainer.Hydrax.SmoothPower = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.SmoothPower = 0.0;

	// SunArea
	str = xml.GetAttributeValueSafe("sunarea");
	if(str.length() > 0)
		DataContainer.Hydrax.SunArea = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.SunArea = 0.0;

	// SunStrength
	str = xml.GetAttributeValueSafe("sunstrength");
	if(str.length() > 0)
		DataContainer.Hydrax.SunStrength = StringConverter::parseReal(str);
	else
		DataContainer.Hydrax.SunStrength = 0.0;

#pragma endregion

#pragma region U32

	// CausticsPower
	str = xml.GetAttributeValueSafe("causticspower");
	if(str.length() > 0)
		DataContainer.Hydrax.CausticsPower = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.CausticsPower = 0;

	// CausticsScale
	str = xml.GetAttributeValueSafe("causticsscale");
	if(str.length() > 0)
		DataContainer.Hydrax.CausticsScale = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.CausticsScale = 0;

	// GodraysNumRays
	str = xml.GetAttributeValueSafe("godraysnumrays");
	if(str.length() > 0)
		DataContainer.Hydrax.GodraysNumRays = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.GodraysNumRays = 0;

	// Layers
	str = xml.GetAttributeValueSafe("layers");
	if(str.length() > 0)
		DataContainer.Hydrax.Layers = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.Layers = 0;

	// PerlinOctaves
	str = xml.GetAttributeValueSafe("perlinoctaves");
	if(str.length() > 0)
		DataContainer.Hydrax.PerlinOctaves = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.PerlinOctaves = 0;

	// PgmoduleComplexity
	str = xml.GetAttributeValueSafe("pgmodulecomplexity");
	if(str.length() > 0)
		DataContainer.Hydrax.PgmoduleComplexity = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.PgmoduleComplexity = 0;

	// PgmoduleElevation
	str = xml.GetAttributeValueSafe("pgmoduleelevation");
	if(str.length() > 0)
		DataContainer.Hydrax.PgmoduleElevation = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.PgmoduleElevation = 0;

	// PgmoduleStrength
	str = xml.GetAttributeValueSafe("pgmodulestrength");
	if(str.length() > 0)
		DataContainer.Hydrax.PgmoduleStrength = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.PgmoduleStrength = 0;

	// PlanesError
	str = xml.GetAttributeValueSafe("planeserror");
	if(str.length() > 0)
		DataContainer.Hydrax.PlanesError = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.PlanesError = 0;

	// RttQualityDepth
	str = xml.GetAttributeValueSafe("rttqualitydepth");
	if(str.length() > 0)
		DataContainer.Hydrax.RttQualityDepth = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.RttQualityDepth = 0;

	// RttQualityDepthAip
	str = xml.GetAttributeValueSafe("rttqualitydepthaip");
	if(str.length() > 0)
		DataContainer.Hydrax.RttQualityDepthAip = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.RttQualityDepthAip = 0;

	// RttQualityDepthReflection
	str = xml.GetAttributeValueSafe("rttqualitydepthreflection");
	if(str.length() > 0)
		DataContainer.Hydrax.RttQualityDepthReflection = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.RttQualityDepthReflection = 0;

	// RttQualityGpuNormalMap
	str = xml.GetAttributeValueSafe("rttqualitygpunormalmap");
	if(str.length() > 0)
		DataContainer.Hydrax.RttQualityGpuNormalMap = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.RttQualityGpuNormalMap = 0;

	// RttQualityRefraction
	str = xml.GetAttributeValueSafe("rttqualityrefraction");
	if(str.length() > 0)
		DataContainer.Hydrax.RttQualityRefraction = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.RttQualityRefraction = 0;

	// ShaderMode
	str = xml.GetAttributeValueSafe("shadermode");
	if(str.length() > 0)
		DataContainer.Hydrax.ShaderMode = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.Hydrax.ShaderMode = 0;

#pragma endregion

#pragma region vectors

	// GodraysExposure
	str = xml.GetAttributeValueSafe("godraysexposure");
	if(str.length() > 0)
		DataContainer.Hydrax.GodraysExposure = StringConverter::parseVector3(str);
	else
		DataContainer.Hydrax.GodraysExposure = Vector3(0, 0, 0);

	// PerlinGpuLod
	str = xml.GetAttributeValueSafe("perlingpulod");
	if(str.length() > 0)
		DataContainer.Hydrax.PerlinGpuLod = StringConverter::parseVector3(str);
	else
		DataContainer.Hydrax.PerlinGpuLod = Vector3(0, 0, 0);

	// Position
	str = xml.GetAttributeValueSafe("position");
	if(str.length() > 0)
		DataContainer.Hydrax.Position = StringConverter::parseVector3(str);
	else
		DataContainer.Hydrax.Position = Vector3(0, 0, 0);

	// SunPosition
	str = xml.GetAttributeValueSafe("sunposition");
	if(str.length() > 0)
		DataContainer.Hydrax.SunPosition = StringConverter::parseVector3(str);
	else
		DataContainer.Hydrax.SunPosition = Vector3(0, 0, 0);

#pragma endregion

	// SunColour
	str = xml.GetAttributeValueSafe("suncolour");
	if(str.length() > 0)
		DataContainer.Hydrax.SunColour = StringConverter::parseVector3(str);
	else
		DataContainer.Hydrax.SunColour = Vector3(0, 0, 0);

	// WaterColour
	str = xml.GetAttributeValueSafe("watercolour");
	if(str.length() > 0)
		DataContainer.Hydrax.WaterColour = StringConverter::parseVector3(str);
	else
		DataContainer.Hydrax.WaterColour = Vector3(0, 0, 0);
}

void CXmlParserStrategy::LoadBgSound(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	BGSOUND bgSound;

	u32 Count = 0;
	while(Count < xml.GetAttributeCount())
	{
		if (String("filename") == xml.GetAttributeName(Count))
		{
			bgSound.FileName = xml.GetAttributeValueSafe("filename");
		}
		else if (String("name") == xml.GetAttributeName(Count))
		{
			bgSound.Name = xml.GetAttributeValueSafe("name");
		}
		else if (String("loop") == xml.GetAttributeName(Count))
		{
			bgSound.Loop = StringConverter::parseBool(xml.GetAttributeValue("loop"));
		}
		else if (String("stream") == xml.GetAttributeName(Count))
		{
			bgSound.Stream = StringConverter::parseBool(xml.GetAttributeValue("stream"));
		}
		else if (String("gain") == xml.GetAttributeName(Count))
		{
			bgSound.Gain = StringConverter::parseReal(xml.GetAttributeValue("gain"));
		}
		Count++;
	}
	DataContainer.BgSounds.push_back(bgSound);
}

void CXmlParserStrategy::LoadSound(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	std::string str;	// temp val

	SOUND sound;
	sound.Name = xml.GetAttributeValueSafe("name");
	sound.FileName = xml.GetAttributeValueSafe("filename");

	// Loop
	str = xml.GetAttributeValueSafe("loop");
	if(str == "true")
		sound.Loop = true;
	else
		sound.Loop = false;

	// Stream
	str = xml.GetAttributeValueSafe("stream");
	if(str == "true")
		sound.Stream = true;
	else
		sound.Stream = false;

	// RelativeToListener
	str = xml.GetAttributeValueSafe("relativetoListener");
	if(str == "true")
		sound.RelativeToListener = true;
	else
		sound.RelativeToListener = false;

	// Priority
	str = xml.GetAttributeValueSafe("priority");
	if(StringConverter::isNumber(str))
		sound.Priority = StringConverter::parseUnsignedInt(str);
	else
		sound.Priority = 0;  // LOW

	// Gain
	str = xml.GetAttributeValueSafe("gain");
	if(StringConverter::isNumber(str))
		sound.Gain = StringConverter::parseReal(str);
	else
		sound.Gain = -1.0f;

	// MaxGain
	str = xml.GetAttributeValueSafe("maxgain");
	if(StringConverter::isNumber(str))
		sound.MaxGain = StringConverter::parseReal(str);
	else
		sound.MaxGain = -1.0f;

	// MinGain
	str = xml.GetAttributeValueSafe("mingain");
	if(StringConverter::isNumber(str))
		sound.MinGain = StringConverter::parseReal(str);
	else
		sound.MinGain = -1.0f;

	// FadeIn
	str = xml.GetAttributeValueSafe("fadein");
	if(StringConverter::isNumber(str))
		sound.FadeIn = StringConverter::parseReal(str);
	else
		sound.FadeIn = -1.0f;

	// FadeOut
	str = xml.GetAttributeValueSafe("fadeout");
	if(StringConverter::isNumber(str))
		sound.FadeOut = StringConverter::parseReal(str);
	else
		sound.FadeOut = -1.0f;

	// Pitch
	str = xml.GetAttributeValueSafe("pitch");
	if(StringConverter::isNumber(str))
		sound.Pitch = StringConverter::parseReal(str);
	else
		sound.Pitch = -1.0f;

	// MaxDistance
	str = xml.GetAttributeValueSafe("maxdistance");
	if(StringConverter::isNumber(str))
		sound.MaxDistance = StringConverter::parseReal(str);
	else
		sound.MaxDistance = -1.0f;

	// RollOffFactor
	str = xml.GetAttributeValueSafe("rollofffactor");
	if(StringConverter::isNumber(str))
		sound.RollOffFactor = StringConverter::parseReal(str);
	else
		sound.RollOffFactor = -1.0f;

	// RefDistance
	str = xml.GetAttributeValueSafe("refdistance");
	if(StringConverter::isNumber(str))
		sound.RefDistance = StringConverter::parseReal(str);
	else
		sound.RefDistance = -1.0f;

	// OuterConeGain
	str = xml.GetAttributeValueSafe("outerconegain");
	if(StringConverter::isNumber(str))
		sound.OuterConeGain = StringConverter::parseReal(str);
	else
		sound.OuterConeGain = -1.0f;

	// InnerConeAngle
	str = xml.GetAttributeValueSafe("innerconeangle");
	if(StringConverter::isNumber(str))
		sound.InnerConeAngle = StringConverter::parseReal(str);
	else
		sound.InnerConeAngle = -1.0f;

	// OuterConeAngle
	str = xml.GetAttributeValueSafe("outerconeangle");
	if(StringConverter::isNumber(str))
		sound.OuterConeAngle = StringConverter::parseReal(str);
	else
		sound.OuterConeAngle = -1.0f;

	// SecondOffset
	str = xml.GetAttributeValueSafe("secondoffset");
	if(StringConverter::isNumber(str))
		sound.SecondOffset = StringConverter::parseReal(str);
	else
		sound.SecondOffset = -1.0f;

	// Velocity
	str = xml.GetAttributeValueSafe("velocity");
	if(StringConverter::isNumber(str))
		sound.Velocity = StringConverter::parseVector3(str);
	else
		sound.Velocity = Vector3::ZERO;

	// Position
	str = xml.GetAttributeValueSafe("position");
	if(StringConverter::isNumber(str))
		sound.Position = StringConverter::parseVector3(str);
	else
		sound.Position = Vector3::ZERO;

	// Direction
	str = xml.GetAttributeValueSafe("direction");
	if(StringConverter::isNumber(str))
		sound.Direction = StringConverter::parseVector3(str);
	else
		sound.Direction = Vector3::ZERO;

	DataContainer.Sounds.push_back(sound);
}

void CXmlParserStrategy::LoadHeightTerrain(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	String str;		// temp var

	DataContainer.HeightTerrain.CustomMaterialName = xml.GetAttributeValueSafe("custommaterialname");
	DataContainer.HeightTerrain.DetailTexture = xml.GetAttributeValueSafe("detailtexture");

	// DetailTile
	str = xml.GetAttributeValueSafe("detailtile");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.DetailTile = StringConverter::parseUnsignedInt(str);
	}

	DataContainer.HeightTerrain.HeightmapImage = xml.GetAttributeValueSafe("heightmap.image");
	//DataContainer.HeightTerrain.HeightmapRawBpp = xml.GetAttributeValueSafe("Heightmap.raw.bpp");		// not used yet
	//DataContainer.HeightTerrain.HeightmapRawSize = xml.GetAttributeValueSafe("Heightmap.raw.size");	// not used yet

	// LODMorphStart
	str = xml.GetAttributeValueSafe("lodmorphstart");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.LODMorphStart = StringConverter::parseReal(str);
	}

	// MaxHeight
	str = xml.GetAttributeValueSafe("maxheight");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.MaxHeight = StringConverter::parseReal(str);
	}

	// MaxMipMapLevel
	str = xml.GetAttributeValueSafe("maxmipmaplevel");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.MaxMipMapLevel = StringConverter::parseInt(str);
	}

	// MaxPixelError
	str = xml.GetAttributeValueSafe("maxpixelerror");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.MaxPixelError = StringConverter::parseUnsignedInt(str);
	}

	// MorphLODFactorParamIndex
	str = xml.GetAttributeValueSafe("morphlodfactorparamindex");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.MorphLODFactorParamIndex = StringConverter::parseUnsignedInt(str);
	}

	DataContainer.HeightTerrain.MorphLODFactorParamName = xml.GetAttributeValueSafe("morphlodfactorparamname");
	DataContainer.HeightTerrain.Name = xml.GetAttributeValueSafe("name");

	// PageSize
	str = xml.GetAttributeValueSafe("pagesize");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.PageSize = StringConverter::parseInt(str);
	}

	// PageWorldX
	str = xml.GetAttributeValueSafe("pageworldx");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.PageWorldX = StringConverter::parseReal(str);
	}

	// PageWorldZ
	str = xml.GetAttributeValueSafe("pageworldz");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.PageWorldZ = StringConverter::parseReal(str);
	}

	// Splatting
	str = xml.GetAttributeValueSafe("splatting");
	std::vector<String> list;
	Tokenize(str, list);
	for(u32 i = 0; i < list.size(); i++)
	{
		DataContainer.HeightTerrain.Splatting.push_back(list[i]);
	}

	// TileSize
	str = xml.GetAttributeValueSafe("tilesize");
	if(StringConverter::isNumber(str))
	{
		DataContainer.HeightTerrain.TileSize = StringConverter::parseUnsignedInt(str);
	}

	// UseTriStrips
	str = xml.GetAttributeValueSafe("usetristrips");
	if(str == "")
	{
		DataContainer.HeightTerrain.UseTriStrips = false;
	}
	else
	{
		DataContainer.HeightTerrain.UseTriStrips = StringConverter::parseBool(str);
	}

	// VertexColors
	str = xml.GetAttributeValueSafe("vertexcolors");
	if(str == "")
	{
		DataContainer.HeightTerrain.VertexColors = false;
	}
	else
	{
		DataContainer.HeightTerrain.VertexColors = StringConverter::parseBool(str);
	}

	// VertexNormals
	str = xml.GetAttributeValueSafe("vertexnormals");
	if(str == "")
	{
		DataContainer.HeightTerrain.VertexNormals = false;
	}
	else
	{
		DataContainer.HeightTerrain.VertexNormals = StringConverter::parseBool(str);
	}

	// VertexProgramMorph
	str = xml.GetAttributeValueSafe("vertexprogrammorph");
	if(str == "")
	{
		DataContainer.HeightTerrain.VertexProgramMorph = false;
	}
	else
	{
		DataContainer.HeightTerrain.VertexProgramMorph = StringConverter::parseBool(str);
	}

	DataContainer.HeightTerrain.WorldTexture = xml.GetAttributeValueSafe("worldtexture");

}

void CXmlParserStrategy::LoadPlaneTerrain(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	DataContainer.PlaneTerrain.isUsed = true;
	String str = xml.GetAttributeValueSafe("normal");
	if(str == "")
	{
		DataContainer.PlaneTerrain.Normal = Vector3(0, 1, 0);
	}
	else
	{
		DataContainer.PlaneTerrain.Normal = StringConverter::parseVector3(str);
	}
}

void CXmlParserStrategy::LoadWater(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	std::string str;	// temp val

	WATER water;
	water.WaterMaterial = xml.GetAttributeValueSafe("watermaterial");

	// WaterVisible
	str = xml.GetAttributeValueSafe("watervisible");
	if(str == "")
	{
		water.WaterVisible = false;
	}
	else
	{
		water.WaterVisible = StringConverter::parseBool(str);
	}

	// WaterWidthX
	str = xml.GetAttributeValueSafe("waterwidthx");
	if(StringConverter::isNumber(str))
	{
		water.WaterWidthX = StringConverter::parseReal(str);
	}

	// WaterWidthZ
	str = xml.GetAttributeValueSafe("waterwidthz");
	if(StringConverter::isNumber(str))
	{
		water.WaterWidthZ = StringConverter::parseReal(str);
	}

	// WaterXPos
	str = xml.GetAttributeValueSafe("waterxpos");
	if(StringConverter::isNumber(str))
	{
		water.WaterXPos = StringConverter::parseReal(str);
	}

	// WaterYPos
	str = xml.GetAttributeValueSafe("waterypos");
	if(StringConverter::isNumber(str))
	{
		water.WaterYPos = StringConverter::parseReal(str);
	}

	// WaterZPos
	str = xml.GetAttributeValueSafe("waterzpos");
	if(StringConverter::isNumber(str))
	{
		water.WaterZPos = StringConverter::parseReal(str);
	}
	DataContainer.Waters.push_back(water);
}

void CXmlParserStrategy::LoadWeapon(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	std::string str;
	WEAPON weapon;
	weapon.Name = xml.GetAttributeValueSafe("name");
	weapon.Desc = xml.GetAttributeValueSafe("disp_name");
	weapon.MeshName = xml.GetAttributeValueSafe("mesh");
	weapon.OverlayName = xml.GetAttributeValueSafe("overlay");

	// Can be semi
	str = xml.GetAttributeValueSafe("semi");
	if(str == "")
	{
		weapon.isSemi = false;
	}
	else
	{
		weapon.isSemi = StringConverter::parseBool(str);
	}

	// Can be burst
	str = xml.GetAttributeValueSafe("burst");
	if(str == "")
	{
		weapon.isBurst = false;
	}
	else
	{
		weapon.isBurst = StringConverter::parseBool(str);
	}

	// Can be automatic
	str = xml.GetAttributeValueSafe("auto");
	if(str == "")
	{
		weapon.isAuto = false;
	}
	else
	{
		weapon.isAuto = StringConverter::parseBool(str);
	}

	weapon.MagType = xml.GetAttributeValueSafe("mag");

	// Rate of Fire
	str = xml.GetAttributeValueSafe("rof");
	if(StringConverter::isNumber(str))
	{
		weapon.ROF = StringConverter::parseUnsignedInt(str);
	}

	// Accuracy
	str = xml.GetAttributeValueSafe("accuracy");
	if(StringConverter::isNumber(str))
	{
		weapon.Accuracy = StringConverter::parseReal(str);
	}

	// Power
	str = xml.GetAttributeValueSafe("power");
	if(StringConverter::isNumber(str))
	{
		weapon.Power = StringConverter::parseReal(str);
	}
	
	// Range
	str = xml.GetAttributeValueSafe("range");
	if(StringConverter::isNumber(str))
	{
		weapon.Range = StringConverter::parseReal(str);
	}
	
	// Scale
	str = xml.GetAttributeValueSafe("scale");
	if(str.length() >0)
		weapon.Scale = StringConverter::parseVector3(str);
	else
		weapon.Scale = Vector3::UNIT_SCALE;

	DataContainer.Weapons.push_back(weapon);
}

void CXmlParserStrategy::LoadMagazine(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	std::string str;
	MAGAZINE mag;

	mag.Name = xml.GetAttributeValueSafe("name");
	mag.Desc = xml.GetAttributeValueSafe("disp_name");
	mag.MeshFileName = xml.GetAttributeValueSafe("mesh");
	mag.Projectile = xml.GetAttributeValueSafe("projectiles");

	str = xml.GetAttributeValueSafe("capacity");
	if(StringConverter::isNumber(str))
	{
		mag.Capacity = StringConverter::parseInt(str);
	}

	DataContainer.Magazines.push_back(mag);
}

void CXmlParserStrategy::LoadProjectile(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	std::string str;
	PROJECTILES pro;

	pro.Name = xml.GetAttributeValueSafe("name");
	pro.Desc = xml.GetAttributeValueSafe("disp_name");
	pro.MeshFileName = xml.GetAttributeValueSafe("mesh");
	pro.BillboardBullet = xml.GetAttributeValueSafe("bbbullet");
	pro.BillboardFlash = xml.GetAttributeValueSafe("bbflash");

	// is this a penetrating round (may need more data on this attribute)
	str = xml.GetAttributeValueSafe("penetrating");
	if(str == "")
		pro.Penetrate = false;
	else
		pro.Penetrate = StringConverter::parseBool(str);

	// Speed
	str = xml.GetAttributeValueSafe("speed");
	if(StringConverter::isNumber(str))
		pro.Speed = StringConverter::parseReal(str);
	else
		pro.Speed = 100.0f;

	// Damage
	str = xml.GetAttributeValueSafe("damage");
	if(StringConverter::isNumber(str))
		pro.Damage = StringConverter::parseReal(str);
	else
		pro.Damage = 100.0f;

	DataContainer.Projectiles.push_back(pro);
}

void CXmlParserStrategy::LoadMelee(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	std::string str;
	MELEE melee;

	melee.Name = xml.GetAttributeValueSafe("name");
	melee.MeshName = xml.GetAttributeValueSafe("meshname");
	melee.Desc = xml.GetAttributeValueSafe("disp_name");

	// is this a penetrating round (may need more data on this attribute)
	str = xml.GetAttributeValueSafe("range");
	if(StringConverter::isNumber(str))
		melee.Range = StringConverter::parseReal(str);
	else
		melee.Range = 1.8f;

	// Speed
	str = xml.GetAttributeValueSafe("power");
	if(StringConverter::isNumber(str))
		melee.Power = StringConverter::parseReal(str);
	else
		melee.Power = 33.4f;

	DataContainer.Melees.push_back(melee);
}

void CXmlParserStrategy::LoadPagedTerrain(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	String str;
	DataContainer.PagedTerrain.Name = xml.GetAttributeValueSafe("name");
	DataContainer.PagedTerrain.TerrainFile = xml.GetAttributeValueSafe("terrainfile");
	DataContainer.PagedTerrain.ResourceGroup = xml.GetAttributeValueSafe("resourcegroup");
	
	// isColorMap
	str = xml.GetAttributeValueSafe("colourmap_enabled");
	if(str != "")
		DataContainer.PagedTerrain.isColorMap = StringConverter::parseBool(str);
	else
		DataContainer.PagedTerrain.isColorMap = false;

	// TextureSize
	str = xml.GetAttributeValueSafe("colourmap_texturesize");
	if(str != "")
		DataContainer.PagedTerrain.TextureSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.TextureSize = 0;

	// MapSize
	str = xml.GetAttributeValueSafe("mapsize");
	if(str != "")
		DataContainer.PagedTerrain.MapSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MapSize = 0;

	// MaxX
	str = xml.GetAttributeValueSafe("maxx");
	if(str != "")
		DataContainer.PagedTerrain.MaxX = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MaxX = 0;

	// MinX
	str = xml.GetAttributeValueSafe("minx");
	if(str != "")
		DataContainer.PagedTerrain.MinX = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MinX = 0;

	// MaxX
	str = xml.GetAttributeValueSafe("maxy");
	if(str != "")
		DataContainer.PagedTerrain.MaxY = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MaxY = 0;

	// MinY
	str = xml.GetAttributeValueSafe("miny");
	if(str != "")
		DataContainer.PagedTerrain.MinY = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MinY = 0;

	// Position
	str = xml.GetAttributeValueSafe("position");
	if(str != "")
		DataContainer.PagedTerrain.Position = StringConverter::parseVector3(str);

	// WorldSize
	str = xml.GetAttributeValueSafe("worldsize");
	if(str != "")
		DataContainer.PagedTerrain.WorldSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.WorldSize = 0;

	// ColorMapTextureSize
	str = xml.GetAttributeValueSafe("colormaptexturesize");
	if(str != "")
		DataContainer.PagedTerrain.ColorMapTextureSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.ColorMapTextureSize = 0;

	// LightMapTextureSize
	str = xml.GetAttributeValueSafe("lightmaptexturesize");
	if(str != "")
		DataContainer.PagedTerrain.LightMapTextureSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.LightMapTextureSize = 0;

	// PageDesityMapSize
	str = xml.GetAttributeValueSafe("pagedesitymapsize");
	if(str != "")
		DataContainer.PagedTerrain.PageDesityMapSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.PageDesityMapSize = 0;

	// DetailDistance
	str = xml.GetAttributeValueSafe("detaildistance");
	if(str != "")
		DataContainer.PagedTerrain.DetailDistance = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.DetailDistance = 0;

	// PageSize
	str = xml.GetAttributeValueSafe("pagesize");
	if(str != "")
		DataContainer.PagedTerrain.PageSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.PageSize = 0;

	// MaxBatchSize
	str = xml.GetAttributeValueSafe("maxbatchsize");
	if(str != "")
		DataContainer.PagedTerrain.MaxBatchSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MaxBatchSize = 0;

	// MaxPixelError
	str = xml.GetAttributeValueSafe("maxpixelerror");
	if(str != "")
		DataContainer.PagedTerrain.MaxPixelError = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MaxPixelError = 0;

	// MinBatchSize
	str = xml.GetAttributeValueSafe("minbatchsize");
	if(str != "")
		DataContainer.PagedTerrain.MinBatchSize = StringConverter::parseUnsignedInt(str);
	else
		DataContainer.PagedTerrain.MinBatchSize = 0;

	while((xml.GetNodeType() != XML_NODE_ELEMENT_END) && xml.GetNodeName() != String("PagedTerrain"))
	{	
		if (String("Layer") == String(xml.GetNodeName()))
		{
			TERRAIN_LAYER layer;
			layer.Diffuse = xml.GetAttributeValueSafe("diffuse");
			layer.Normal = xml.GetAttributeValueSafe("normal");
			String str = xml.GetAttributeValueSafe("worldsize");
			if(str != "")
				layer.WorldSize = StringConverter::parseUnsignedInt(str);
			else
				layer.WorldSize = 0;

			DataContainer.PagedTerrain.Layers.push_back(layer);
		}
		xml.Read();
	}
}

void CXmlParserStrategy::LoadArchive(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	ARCHIVE archive;

	archive.Name = xml.GetAttributeValueSafe("name");		// Not required
	
	archive.FileName = xml.GetAttributeValueSafe("filename");
	if(archive.FileName.length() == 0)
	{
		// not valid
		// TODO: add logging to errors
	}
	else
	{
		DataContainer.Archives.push_back(archive);
	}
}

void CXmlParserStrategy::LoadBillboard(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	BILLBOARD bb;

	bb.Name = xml.GetAttributeValueSafe("name");
	if(bb.Name.length() == 0)
		return;
	
	bb.MaterialName = xml.GetAttributeValueSafe("material");
	if(bb.MaterialName.length() == 0)
		return;
		
	bb.PoolSize = StringConverter::parseUnsignedInt(xml.GetAttributeValueSafe("poolsize"));
	if(bb.PoolSize == 0)
		bb.PoolSize = 100;
		
	bb.Width = StringConverter::parseReal(xml.GetAttributeValueSafe("width"));
	if(bb.Width == 0)
		return;
		
	bb.Height = StringConverter::parseReal(xml.GetAttributeValueSafe("height"));
	if(bb.Height == 0)
		return;
		
	bb.Type = StringConverter::parseUnsignedInt(xml.GetAttributeValueSafe("type"));
	
	DataContainer.Billboards.push_back(bb);
}

void CXmlParserStrategy::LoadPagedGeometry(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	GEO_SET geoSet;
	String str;

	// Mesh
	geoSet.MeshName = xml.GetAttributeValueSafe("meshfile");
	if(geoSet.MeshName.length() == 0)
	{
		CORE_ERR("Could not find geo set value: mesh");
		return;
	}

	// GeoType
	str = xml.GetAttributeValueSafe("loadtype");
	if(str == "2d")
		geoSet.GeoType = GEO_SET::GLT_TREE_2D;
	else if(str == "grass")
		geoSet.GeoType = GEO_SET::GLT_GRASS;
	else if(str == "bush")
		geoSet.GeoType = GEO_SET::GLT_BUSH;
	else if(str == "3dp")
		geoSet.GeoType = GEO_SET::GLT_TREE_3DP;
	else
		geoSet.GeoType = GEO_SET::GLT_TREE_3D;// Default

	// Get physics profile if one is there.  If 3DP and no profile, then set it to just 3D.
	geoSet.PhysicsProfile = xml.GetAttributeValueSafe("physicsprofile");
	if(geoSet.PhysicsProfile.length() == 0 && geoSet.GeoType == GEO_SET::GLT_TREE_3DP)
		geoSet.GeoType = GEO_SET::GLT_TREE_3D;

	while((xml.GetNodeType() != XML_NODE_ELEMENT_END) && xml.GetNodeName() != String("PagedGeometry"))
	{	
		if (String("Geometry") == String(xml.GetNodeName()))
		{
			GEO_SET_SUBSET subSet;

			// Position
			str = xml.GetAttributeValueSafe("position");
			if(str.length() > 0)
				subSet.Position = StringConverter::parseVector3(str);
			else
			{
				CORE_ERR("Unable to find geo subset value: position");
				return;
			}

			// Scale (not required)
			str = xml.GetAttributeValueSafe("scale");
			if(str.length() > 0)
				subSet.Scale = StringConverter::parseReal(str);

			geoSet.Objects.push_back(subSet);
		}
		xml.Read();
	}
	DataContainer.GeoSets.push_back(geoSet);
}

void CXmlParserStrategy::LoadAnimationMapping(IXMLReader& xml, DATA_CONTAINER& DataContainer)
{
	String value;
	ANIMATION_MAPPING am;

	am.MeshName = xml.GetAttributeValueSafe("meshname");
	if(am.MeshName.length() == 0)
		return;

	for(auto it = AnimationMappingList.cbegin(); it != AnimationMappingList.cend(); it++)
	{
		value = xml.GetAttributeValueSafe((*it)->XmlAttribute.c_str());
		if(value.length() == 0)
		{
			ANIMATION_MAPPING::SOUND_ANIMATION sa;
			sa.AnimationName = value;
			sa.AnimState = (*it)->State;
			String soundName = (*it)->XmlAttribute.c_str() + String("_sound");
			sa.SoundName = xml.GetAttributeValueSafe(soundName.c_str());
			am.Animations.push_back(sa);
		}
	}
	
	if(am.Animations.size() > 0)
		DataContainer.AnimationMapping.push_back(am);
}

void CXmlParserStrategy::PopulateAnimationMappingList()
{
	AnimationMappingList.push_back(new AnimationMapping("idle", EAS_IDLE));
	AnimationMappingList.push_back(new AnimationMapping("walk", EAS_WALK));
	AnimationMappingList.push_back(new AnimationMapping("run", EAS_RUN));
	AnimationMappingList.push_back(new AnimationMapping("sprint", EAS_SPRINT));
	AnimationMappingList.push_back(new AnimationMapping("dieing", EAS_DIEING));
	AnimationMappingList.push_back(new AnimationMapping("dead", EAS_DEAD));
	AnimationMappingList.push_back(new AnimationMapping("crawl", EAS_CRAWL));
	AnimationMappingList.push_back(new AnimationMapping("shoot", EAS_SHOOT));
	AnimationMappingList.push_back(new AnimationMapping("reload", EAS_RELOAD));
	AnimationMappingList.push_back(new AnimationMapping("kneel", EAS_KNEEL));
	AnimationMappingList.push_back(new AnimationMapping("prone", EAS_PRONE));
	AnimationMappingList.push_back(new AnimationMapping("runshoot", EAS_RUNSHOOT));
	AnimationMappingList.push_back(new AnimationMapping("hit", EAS_HIT));
	AnimationMappingList.push_back(new AnimationMapping("melee", EAS_MELEE));
	AnimationMappingList.push_back(new AnimationMapping("jump", EAS_JUMP));
	AnimationMappingList.push_back(new AnimationMapping("aimstand", EAS_AIM_STAND));
}

void CXmlParserStrategy::Tokenize(const String& str, Vector<String>& tokens, const String& delimiters)
{
    // Skip delimiters at beginning.
    string::size_type lastPos = str.find_first_not_of(delimiters, 0);
    // Find first "non-delimiter".
    string::size_type pos     = str.find_first_of(delimiters, lastPos);

    while (string::npos != pos || string::npos != lastPos)
    {
        // Found a token, add it to the vector.
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        // Skip delimiters.  Note the "not_of"
        lastPos = str.find_first_not_of(delimiters, pos);
        // Find next "non-delimiter"
        pos = str.find_first_of(delimiters, lastPos);
    }
}
