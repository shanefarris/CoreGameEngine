#include "RuntimeEditor/CRuntimeEditorManager.h"
#include "SceneImporterPackage.h"
#include "Structures.h"
#include "CCustomFrameListener.h"
#include "CMenuDirector.h"
#include "IO/IXMLWriter.h"
#include "IO/CFileSystem.h"
#include "CItemsManager.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "CGameObjectManager.h"
#include "CNatureManager.h"
#include "IPhysicsStrategy.h"
#include "Audio/CSoundManager.h"
#include "CPhysicsManager.h"
#include "CWeaponProfile.h"
#include "CBillboardManager.h"
#include "IO/CoreLogging.h"
#include "time.h"

// MyGUI specific plugin
#include "../PluginMyGui/CGuiStrategy_MyGui.h"

// Ogre
#include "OgreRoot.h"
#include "OgreEntity.h"
#include "OgreResourceManager.h"

using namespace Core;
using namespace Core::Editor;

CRuntimeEditorManager* CRuntimeEditorManager::RuntimeEditorManager = nullptr;

CRuntimeEditorManager* CRuntimeEditorManager::Instance()
{
	if(!RuntimeEditorManager)
		RuntimeEditorManager = new CRuntimeEditorManager();
	return RuntimeEditorManager;
}

CRuntimeEditorManager::CRuntimeEditorManager() : m_CurrWorld(nullptr), m_MenuDirector(nullptr), m_CustomFrameListener(nullptr)
{
	m_CustomFrameListener = nullptr;
	m_GameManager = nullptr;
	isRunning = false;

	//Sound::CSoundManager::Instance()->LoadAllSounds(CGameManager::Instance()->GetBaseAudioResourceName());
}

CRuntimeEditorManager::~CRuntimeEditorManager()
{
	Shutdown();
	if(m_CustomFrameListener)
	{
		m_GameManager->GetEngineDevice()->removeFrameListener(m_CustomFrameListener);
		CORE_DELETE(m_CustomFrameListener);
	}

	CORE_DELETE(m_MenuDirector);
}

bool CRuntimeEditorManager::InitEditor(SceneImporterPackage& SIP)
{
	if(!HaveRequiredResources())
	{
		CORE_ERR("Unable to find the path point and/or A* mesh for the runtime editor.");
		return false;
	}

	if(SIP.SoundManager)
		m_SoundManager = SIP.SoundManager;
	else
		m_SoundManager = Sound::CSoundManager::Instance();

	if(SIP.GameManager)
		m_GameManager = SIP.GameManager;
	else
		m_GameManager = CGameManager::Instance();

	if(SIP.CameraManager)
		m_CameraManager = SIP.CameraManager;
	else
		m_CameraManager = CCameraManager::Instance();

	if(SIP.ItemsManager)
		m_ItemsManager = SIP.ItemsManager;
	else
		m_ItemsManager = CItemsManager::Instance();

	if(SIP.GameObjectManager)
		m_GameObjectManager = SIP.GameObjectManager;
	else
		m_GameObjectManager = CGameObjectManager::Instance();

	if(SIP.NatureManager)
		m_NatureManager = SIP.NatureManager;
	else
		m_NatureManager = Nature::CNatureManager::Instance();

	// If we have a "player friendly" camera in use, add an "unfriendly" camera instead
	if(m_CameraManager->GetIsPlayerFriendly())
		m_CameraManager->CreateCamera(ECM_GOD);

	// Create a physics strategy if one doesn't exist
	m_PhysicsStrategy = SIP.PhysicsStrategy;
	if(!m_PhysicsStrategy)
	{
		m_PhysicsStrategy = Physics::CPhysicsManager::Instance()->CreateStrategy(CGameManager::Instance()->GetDefaultPhysicsStrategy());
		if(m_PhysicsStrategy)
			m_PhysicsStrategy->InitWorld();
	}

	if(m_GameManager)
	{
		if(!m_CustomFrameListener)
		{
			m_CustomFrameListener = new CCustomFrameListener(m_GameManager->GetRenderWindow());
			m_GameManager->GetEngineDevice()->addFrameListener(m_CustomFrameListener);
		}
		
		m_MenuDirector = CMenuDirector::Instance();
		m_MenuDirector->Start();
		m_MenuDirector->SetVisible(false);

		m_CustomFrameListener->AddGuiStrategy(m_MenuDirector->GetGuiStrategy());
		
		isRunning = true;
	}
	else
		return false;

	// Add a test weapon if one doesn't exists
	InitializeTestInventory();

	return true;
}

bool CRuntimeEditorManager::HaveRequiredResources()
{
	// Checks to see if the basic meshes used for the editor are loaded.
	if(!ResourceGroupManager::getSingleton().resourceExists("General", "PathPoint.mesh"))
		return false;

	if(!ResourceGroupManager::getSingleton().resourceExists("General", "AStarNode.mesh"))
		return false;
	
	return true;
}

void CRuntimeEditorManager::InitializeTestInventory()
{
	// Create a default test weapon
	Vector<CItemProfile*> itemProfiles;
	m_ItemsManager->GetItemProfiles(itemProfiles);
	if(itemProfiles.size() == 0)
	{
		// Projectile profile
		CProjectileProfile projectileProfile;
		projectileProfile.Name = "TestProjectile";
		projectileProfile.Desc = "Default test projectile.";
		projectileProfile.Damage = 100;
		projectileProfile.Speed = 300;
		projectileProfile.BillboardBullet = "Bullet";

		// Magazine profile
		CMagazineProfile magazineProfile;
		magazineProfile.Name = "TestMag";
		magazineProfile.Desc = "Default test mag.";
		magazineProfile.Capacity = 3000;
		magazineProfile.ProjectileProfile = projectileProfile;
		
		// Weapon profile
		CWeaponProfile weaponProfile;
		weaponProfile.Name = "TestWeapon";
		weaponProfile.Desc = "Default test weapon.";
		weaponProfile.MeshName = "m4a1_1.mesh";
		weaponProfile.Accuracy = 100;
		weaponProfile.OverlayName = "Soldier/Target";
		weaponProfile.Power = 100;
		weaponProfile.Range = 300;
		weaponProfile.MagazineProfile = magazineProfile;

		// Add the profile to the inventory
		m_ItemsManager->AddProfile(weaponProfile);

		// Add the billboard for the projectile
		CBillboardManager::Instance()->CreateBillboard("Bullet", 0, 100, "blue_bullet", 0.5f, 0.5f);
	}
}

bool CRuntimeEditorManager::StartEditor()
{
	m_MenuDirector->SetVisible(true);
	return true;
}

bool CRuntimeEditorManager::StopEditor()
{
	m_MenuDirector->SetVisible(false);
	return true;
}

bool CRuntimeEditorManager::Shutdown()
{
	if(m_CustomFrameListener)
	{
		m_CustomFrameListener->RemoveGuiStrategy();
	}

	if(Nature::CNatureManager::Instance()->GetWorld())
	{
		if(m_CurrWorld == Nature::CNatureManager::Instance()->GetWorld())
		{
			Nature::CNatureManager::Instance()->DestroyWorld(m_CurrWorld);
			m_CurrWorld = nullptr;
		}
	}
	
	if(m_MenuDirector)
		m_MenuDirector->Shutdown();

	isRunning = false;
	return true;
}

bool CRuntimeEditorManager::CreatePlane()
{
	using namespace Core::Physics;
	IPhysicsStrategy* physics = nullptr;
	if(!CPhysicsManager::Instance()->GetStrategy())
	{
		physics = CPhysicsManager::Instance()->CreateStrategy(m_GameManager->GetDefaultPhysicsStrategy());
		physics->InitWorld();
	}

	physics = CPhysicsManager::Instance()->GetStrategy();
	if(physics)
	{
		physics->AddInfinitePlane(nullptr);
		if(!Nature::CNatureManager::Instance()->GetWorld())
		{
			auto terrain = new Core::PLANE_TERRAIN();
			terrain->Normal = Vector3::UNIT_Y;
			Nature::CNatureManager::Instance()->CreateWorld(nullptr, nullptr, terrain);
		}
	}
	else
	{
		return false;
	}

	return true;
}

bool CRuntimeEditorManager::IsRunning()
{
	return isRunning;
}

void CRuntimeEditorManager::GetSoundObjects(Vector<SOUND_OBJ*>& SoundObjects) 
{ 
	SoundObjects = m_EditorSounds; 
}

SOUND_OBJ* CRuntimeEditorManager::GetSoundObject(const char* EntityName)
{
	for(u32 i = 0; i < m_EditorSounds.size(); i++)
	{
		if(String(EntityName) == m_EditorSounds[i]->Entity->getName())
		{
			return m_EditorSounds[i];
		}
	}
	return nullptr;
}

void CRuntimeEditorManager::AddSoundObject(const SOUND_OBJ& SoundObject) 
{ 
	m_EditorSounds.push_back(new SOUND_OBJ(SoundObject.Entity, SoundObject.Node, SoundObject.SoundName.c_str())); 
}

void CRuntimeEditorManager::RemoveSoundObject(SOUND_OBJ* SoundObject)
{
	using namespace Sound;

	for(u32 i = 0; i < m_EditorSounds.size(); i++)
	{
		if(SoundObject->Entity->getName() == m_EditorSounds[i]->Entity->getName())
		{
			CSoundManager::Instance()->DestroySound(m_EditorSounds[i]->Entity->getName().c_str());
			m_EditorSounds.erase(m_EditorSounds.begin() + i);
			return;
		}
	}
}

void CRuntimeEditorManager::WritePagedGeometry(const PAGED_GEO& PagedGeo)
{
	// Create the file
	using namespace IO;
	unsigned long stamp = (unsigned long)time(nullptr) / 3600;
	auto fileName = "paged_geometry_" + StringConverter::toString(stamp);
	auto FileSystem = new CFileSystem();
	auto writer = FileSystem->CreateXMLWriter(fileName.c_str());
	if(!writer)
		return;
	
	Vector<String> names;
	Vector<String> values;
	String name;
	String value;
	
	names.push_back("batchmax");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.BatchMax));
	names.push_back("batchstart");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.BatchStart));
	names.push_back("densitymap");
	values.push_back(PagedGeo.GeoSet.DensityMap);
	names.push_back("heightmax");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.HeightMax));
	names.push_back("heightmin");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.HeightMin));
	names.push_back("impostermax");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.ImposterMax));
	names.push_back("batchstart");
	values.push_back(PagedGeo.GeoSet.MaterialName);
	names.push_back("pagesize");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.PageSize));
	names.push_back("widthmax");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.WidthMax));
	names.push_back("widthmin");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.WidthMin));
	names.push_back("geotype");
	values.push_back(StringConverter::toString(PagedGeo.GeoSet.GeoType));
	names.push_back("objecttype");
	values.push_back(PagedGeo.ObjectType);
	
	writer->WriteElement("PagedGeometry", false, names, values);
	writer->WriteLineBreak();
	
	for(u32 i = 0; i < PagedGeo.GeoSet.Objects.size(); i++)
	{
		names.clear();
		values.clear();
	
		names.push_back("position");
		values.push_back(StringConverter::toString(PagedGeo.GeoSet.Objects[i].Position));
		names.push_back("scale");
		values.push_back(StringConverter::toString(PagedGeo.GeoSet.Objects[i].Scale));
		names.push_back("yaw");
		values.push_back(StringConverter::toString(PagedGeo.GeoSet.Objects[i].Yaw));
		
		writer->WriteElement("PGSubSet", true, names, values);
		writer->WriteLineBreak();
	}
	
	writer->WriteClosingTag("PagedGeometry");
	writer->WriteLineBreak();
	
	CORE_DELETE(writer);
}