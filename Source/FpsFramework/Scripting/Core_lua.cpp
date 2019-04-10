#ifdef COMPILE_SCRIPT
/*
** Lua binding: Core
** Generated automatically by tolua++-1.0.92 on 01/17/12 21:14:00.
*/
#pragma warning (disable : 4800)		// Converting int to bool

#ifndef __cplusplus
#include "stdlib.h"
#endif
#include "string.h"

#include "ToLua/tolua++.h"

#include "CCameraManager.h"
#include "CCharacterState.h"
#include "CCharacterStateManager.h"
#include "CEffectsManager.h"
#include "CEntityEffect.h"
#include "CGame.h"
#include "CGameManager.h"
#include "CGameObject.h"
#include "CGameObjectManager.h"
#include "CGameState.h"
#include "CGuiManager.h"
#include "CGuiStrategy_MyGui.h"
#include "CInputManager.h"
#include "CItemsManager.h"
#include "CLoadingScreen.h"
#include "CLuaConsole.h"
#include "CMagazine.h"
#include "CMagazineProfile.h"
#include "CMenuState.h"
#include "CMissionManager.h"
#include "CoreEngine.h"
#include "CoreStructures.h"
#include "CParticleEffect.h"
#include "CPhysicsManager.h"
#include "CPhysicsProfile.h"
#include "CPlayer.h"
#include "CPlayerSoundComponent.h"
#include "CPluginManager.h"
#include "CPostEffect.h"
#include "CProjectile.h"
#include "CProjectileProfile.h"
#include "CScrollingMessage.h"
#include "CSpawnManager.h"
#include "CTrainingManager.h"
#include "CVolumeObject.h"
#include "CVolumeObject_Cube.h"
#include "CWeapon.h"
#include "CWeaponFactory.h"
#include "CWeaponProfile.h"
#include "MissionEvents.h"
#include "MovableTextOverlay.h"
#include "PhysicsStructures.h"
#include "PlayerEnums.h"
#include "SceneImporterPackage.h"
#include "SPhysicsRayCastReport.h"
#include "IMission.h"

using namespace Core;
using namespace Core::GUI;
using namespace Core::Physics;
using namespace Core::AI;
using namespace Core::Mission;

/* Exported function */
TOLUA_API int  tolua_Core_open (lua_State* tolua_S);


/* function to release collected object via destructor */
#ifdef __cplusplus

static int tolua_collect_Core__CPlayerSoundComponent (lua_State* tolua_S)
{
 Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CWeaponProfile (lua_State* tolua_S)
{
 Core::CWeaponProfile* self = (Core::CWeaponProfile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CPlayer (lua_State* tolua_S)
{
 Core::CPlayer* self = (Core::CPlayer*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CWeapon (lua_State* tolua_S)
{
 Core::CWeapon* self = (Core::CWeapon*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CGameState (lua_State* tolua_S)
{
 Core::CGameState* self = (Core::CGameState*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CProjectileProfile (lua_State* tolua_S)
{
 Core::CProjectileProfile* self = (Core::CProjectileProfile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__AI__CCharacterState (lua_State* tolua_S)
{
 Core::AI::CCharacterState* self = (Core::AI::CCharacterState*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__GUI__CGuiManager (lua_State* tolua_S)
{
 Core::GUI::CGuiManager* self = (Core::GUI::CGuiManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CMagazineProfile (lua_State* tolua_S)
{
 Core::CMagazineProfile* self = (Core::CMagazineProfile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Effects__CPostEffect (lua_State* tolua_S)
{
 Core::Effects::CPostEffect* self = (Core::Effects::CPostEffect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Physics__CVolumeObject_Cube (lua_State* tolua_S)
{
 Core::Physics::CVolumeObject_Cube* self = (Core::Physics::CVolumeObject_Cube*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CInputManager (lua_State* tolua_S)
{
 Core::CInputManager* self = (Core::CInputManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CoreEntityObject (lua_State* tolua_S)
{
 Core::CoreEntityObject* self = (Core::CoreEntityObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CGame (lua_State* tolua_S)
{
 Core::CGame* self = (Core::CGame*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Physics__SPhysicsRayCastReport (lua_State* tolua_S)
{
 Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CItemsManager (lua_State* tolua_S)
{
 Core::CItemsManager* self = (Core::CItemsManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CCameraManager (lua_State* tolua_S)
{
 Core::CCameraManager* self = (Core::CCameraManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CMagazine (lua_State* tolua_S)
{
 Core::CMagazine* self = (Core::CMagazine*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CPluginManager (lua_State* tolua_S)
{
 Core::CPluginManager* self = (Core::CPluginManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Quaternion (lua_State* tolua_S)
{
 Quaternion* self = (Quaternion*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__OgreSpecific__MovableTextOverlayAttributes (lua_State* tolua_S)
{
 Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CWeaponFactory (lua_State* tolua_S)
{
 Core::CWeaponFactory* self = (Core::CWeaponFactory*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Physics__CVolumeObject (lua_State* tolua_S)
{
 Core::Physics::CVolumeObject* self = (Core::Physics::CVolumeObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Training__CTrainingManager (lua_State* tolua_S)
{
 Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CSpawnManager (lua_State* tolua_S)
{
 Core::CSpawnManager* self = (Core::CSpawnManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_reVector3Df (lua_State* tolua_S)
{
 Vector3* self = (Vector3*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__GUI__CGuiStrategy_MyGui (lua_State* tolua_S)
{
 Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Effects__CEffectsManager (lua_State* tolua_S)
{
 Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CGameManager (lua_State* tolua_S)
{
 Core::CGameManager* self = (Core::CGameManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Effects__CEntityEffect (lua_State* tolua_S)
{
 Core::Effects::CEntityEffect* self = (Core::Effects::CEntityEffect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__OgreSpecific__CScrollingMessage (lua_State* tolua_S)
{
 Core::OgreSpecific::CScrollingMessage* self = (Core::OgreSpecific::CScrollingMessage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CProjectile (lua_State* tolua_S)
{
 Core::CProjectile* self = (Core::CProjectile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__OgreSpecific__MovableTextOverlay (lua_State* tolua_S)
{
 Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Vector_Core__IInventoryItem__ (lua_State* tolua_S)
{
 Vector<Core::IInventoryItem*>* self = (Vector<Core::IInventoryItem*>*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__AI__CCharacterStateManager (lua_State* tolua_S)
{
 Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Mission__CMissionManager (lua_State* tolua_S)
{
 Core::Mission::CMissionManager* self = (Core::Mission::CMissionManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Mission__CMissionEvent (lua_State* tolua_S)
{
 Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_String (lua_State* tolua_S)
{
 String* self = (String*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Physics__VolumePackage (lua_State* tolua_S)
{
 Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_DataStreamPtr (lua_State* tolua_S)
{
 DataStreamPtr* self = (DataStreamPtr*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CLuaConsole (lua_State* tolua_S)
{
 Core::CLuaConsole* self = (Core::CLuaConsole*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__SoundToAnimation (lua_State* tolua_S)
{
 Core::SoundToAnimation* self = (Core::SoundToAnimation*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CGameObject (lua_State* tolua_S)
{
 Core::CGameObject* self = (Core::CGameObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__OgreSpecific__CLoadingScreen (lua_State* tolua_S)
{
 Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_E_GUI_STRATEGY (lua_State* tolua_S)
{
 E_GUI_STRATEGY* self = (E_GUI_STRATEGY*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Effects__CParticleEffect (lua_State* tolua_S)
{
 Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CDummyGameObject (lua_State* tolua_S)
{
 Core::CDummyGameObject* self = (Core::CDummyGameObject*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__CGameObjectManager (lua_State* tolua_S)
{
 Core::CGameObjectManager* self = (Core::CGameObjectManager*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__Physics__CPhysicsProfile (lua_State* tolua_S)
{
 Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}

static int tolua_collect_Core__SceneImporterPackage (lua_State* tolua_S)
{
 Core::SceneImporterPackage* self = (Core::SceneImporterPackage*) tolua_tousertype(tolua_S,1,0);
	Mtolua_delete(self);
	return 0;
}
#endif


/* function to register type */
static void tolua_reg_types (lua_State* tolua_S)
{
 tolua_usertype(tolua_S,"ColourValue");
 tolua_usertype(tolua_S,"Vector<const char*>");
 tolua_usertype(tolua_S,"Core::Mission::CMissionManager");
 tolua_usertype(tolua_S,"Vector<Core::AI::Obstacle*>");
 tolua_usertype(tolua_S,"Core::CGameState");
 tolua_usertype(tolua_S,"Core::CProjectileProfile");
 tolua_usertype(tolua_S,"OIS::JoyStick");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IPhysicsStrategyFactory*>");
 tolua_usertype(tolua_S,"Core::CMagazine");
 tolua_usertype(tolua_S,"Core::CInputManager");
 tolua_usertype(tolua_S,"Core::AI::SphereObstacle");
 tolua_usertype(tolua_S,"Core::Plugin::IGameObjectFactory");
 tolua_usertype(tolua_S,"Core::CoreEntityObject");
 tolua_usertype(tolua_S,"Core::OgreSpecific::CLoadingScreen");
 tolua_usertype(tolua_S,"Core::AI::Wall");
 tolua_usertype(tolua_S,"std::vector<Core::CPlayer*>");
 tolua_usertype(tolua_S,"Core::ICamera");
 tolua_usertype(tolua_S,"Core::GUI::CGuiStrategy_MyGui");
 tolua_usertype(tolua_S,"Core::CDummyGameObject");
 tolua_usertype(tolua_S,"Core::Physics::CPhysicsManager");
 tolua_usertype(tolua_S,"Core::Plugin::IConsoleParser");
 tolua_usertype(tolua_S,"SceneManager");
 tolua_usertype(tolua_S,"SceneNode");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IParticleFactory*>");
 tolua_usertype(tolua_S,"Core::CItemProfile");
 tolua_usertype(tolua_S,"Core::SoundToAnimation");
 tolua_usertype(tolua_S,"Font");
 tolua_usertype(tolua_S,"Timer");
 tolua_usertype(tolua_S,"SceneManager");
 tolua_usertype(tolua_S,"Core::Plugin::IAiStateFactory");
 tolua_usertype(tolua_S,"Core::ILineOfSightStrategy");
 tolua_usertype(tolua_S,"Core::CPlayer");
 tolua_usertype(tolua_S,"Vector<Vector3>");
 tolua_usertype(tolua_S,"Core::CFrameListenerFramework");
 tolua_usertype(tolua_S,"ResourceManager");
 tolua_usertype(tolua_S,"Core::Physics::SPhysicsRayCastReport");
 tolua_usertype(tolua_S,"Core::Mission::IMission");
 tolua_usertype(tolua_S,"Core::AI::BoxObstacle");
 tolua_usertype(tolua_S,"Ogre::FrameEvent");
 tolua_usertype(tolua_S,"Vector<Core::AI::Wall*>");
 tolua_usertype(tolua_S,"Viewport");
 tolua_usertype(tolua_S,"RenderWindow");
 tolua_usertype(tolua_S,"Quaternion");
 tolua_usertype(tolua_S,"MyGUI::Gui");
 tolua_usertype(tolua_S,"Ogre::FrameListener");
 tolua_usertype(tolua_S,"Core::Physics::CPhysXBody");
 tolua_usertype(tolua_S,"Core::CBillboardManager");
 tolua_usertype(tolua_S,"Core::CGameManager");
 tolua_usertype(tolua_S,"Core::Plugin::IPostEffectFactory");
 tolua_usertype(tolua_S,"Core::Physics::VolumePackage");
 tolua_usertype(tolua_S,"OIS::MouseEvent");
 tolua_usertype(tolua_S,"Ogre::Entity");
 tolua_usertype(tolua_S,"Core::Plugin::ICameraFactory");
 tolua_usertype(tolua_S,"Core::Physics::CPhysicsProfile");
 tolua_usertype(tolua_S,"Core::Plugin::IMissionFactory");
 tolua_usertype(tolua_S,"Core::CPlayerSoundComponent");
 tolua_usertype(tolua_S,"Vector<Core::CPlayer*>");
 tolua_usertype(tolua_S,"Core::CCameraManager");
 tolua_usertype(tolua_S,"Core::Physics::ICharacterController");
 tolua_usertype(tolua_S,"Core::AI::CCharacterState");
 tolua_usertype(tolua_S,"Core::AI::Obstacle");
 tolua_usertype(tolua_S,"Core::GUI::CGuiManager");
 tolua_usertype(tolua_S,"Core::CMagazineProfile");
 tolua_usertype(tolua_S,"Core::Effects::CPostEffect");
 tolua_usertype(tolua_S,"MovableObject");
 tolua_usertype(tolua_S,"Core::Plugin::IParticleFactory");
 tolua_usertype(tolua_S,"Core::CLuaConsole");
 tolua_usertype(tolua_S,"Core::SceneLoader::CSerializer");
 tolua_usertype(tolua_S,"size_t");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::ICameraFactory*>");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IGameObjectFactory*>");
 tolua_usertype(tolua_S,"Core::IInventoryItem");
 tolua_usertype(tolua_S,"Core::CItemsManager");
 tolua_usertype(tolua_S,"MyGUI::OgrePlatform");
 tolua_usertype(tolua_S,"String");
 tolua_usertype(tolua_S,"OIS::MouseButtonID");
 tolua_usertype(tolua_S,"WindowEventListener");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IMissionFactory*>");
 tolua_usertype(tolua_S,"IVolumeObject");
 tolua_usertype(tolua_S,"Core::Effects::CEntityEffect");
 tolua_usertype(tolua_S,"IItemFactory");
 tolua_usertype(tolua_S,"Core::CProjectile");
 tolua_usertype(tolua_S,"Core::GUI::CBaseLayout_MyGui");
 tolua_usertype(tolua_S,"OnEnterFunc");
 tolua_usertype(tolua_S,"Core::OgreSpecific::MovableTextOverlayAttributes");
 tolua_usertype(tolua_S,"Core::CWeaponFactory");
 tolua_usertype(tolua_S,"Core::CWeaponProfile");
 tolua_usertype(tolua_S,"Core::CMenuState");
 tolua_usertype(tolua_S,"Core::SPAWN_POINT");
 tolua_usertype(tolua_S,"OnExitFunc");
 tolua_usertype(tolua_S,"OgreOde::Geometry");
 tolua_usertype(tolua_S,"enum");
 tolua_usertype(tolua_S,"OIS::KeyListener");
 tolua_usertype(tolua_S,"Core::SceneImporterPackage");
 tolua_usertype(tolua_S,"Core::Physics::CVolumeObject");
 tolua_usertype(tolua_S,"Vector<unsigned int>");
 tolua_usertype(tolua_S,"ResourceGroupListener");
 tolua_usertype(tolua_S,"Vector<Core::CGameObject*>");
 tolua_usertype(tolua_S,"Core::Training::CTrainingManager");
 tolua_usertype(tolua_S,"Core::CSpawnManager");
 tolua_usertype(tolua_S,"Core::OgreSpecific::CScrollingMessage");
 tolua_usertype(tolua_S,"Core::CConfiguration");
 tolua_usertype(tolua_S,"Core::CLuaInterpreter");
 tolua_usertype(tolua_S,"Core::Plugin::IPlayerFactory");
 tolua_usertype(tolua_S,"Vector<Core::CProjectile*>");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IPostEffectFactory*>");
 tolua_usertype(tolua_S,"Entity");
 tolua_usertype(tolua_S,"Core::OgreSpecific::MovableTextOverlay");
 tolua_usertype(tolua_S,"ResourcePtr");
 tolua_usertype(tolua_S,"Core::Physics::IPhysicsRagdoll");
 tolua_usertype(tolua_S,"MISSION_TYPE");
 tolua_usertype(tolua_S,"IGuiStrategy");
 tolua_usertype(tolua_S,"Sound::CSound");
 tolua_usertype(tolua_S,"Core::CPlayerAttributesComponent");
 tolua_usertype(tolua_S,"Core::Physics::CVolumeObject_Cube");
 tolua_usertype(tolua_S,"PhysicsProfileList");
 tolua_usertype(tolua_S,"Vector<Core::IInventoryItem*>");
 tolua_usertype(tolua_S,"Core::CGameObjectManager");
 tolua_usertype(tolua_S,"Core::OgreSpecific::RectLayoutManager");
 tolua_usertype(tolua_S,"Core::Plugin::IPhysicsStrategyFactory");
 tolua_usertype(tolua_S,"Core::CEnvironmentObserver");
 tolua_usertype(tolua_S,"Core::CGame");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IPlayerFactory*>");
 tolua_usertype(tolua_S,"OIS::Keyboard");
 tolua_usertype(tolua_S,"EngineDevice");
 tolua_usertype(tolua_S,"Vector<Core::ICamera*>");
 tolua_usertype(tolua_S,"Core::CPluginManager");
 tolua_usertype(tolua_S,"OgreOde::Body");
 tolua_usertype(tolua_S,"PathDefinition");
 tolua_usertype(tolua_S,"Vector<Core::Mission::IMission*>");
 tolua_usertype(tolua_S,"Core::AI::IAiReactionComponent");
 tolua_usertype(tolua_S,"RenderWindow");
 tolua_usertype(tolua_S,"Core::Mission::CMissionEvent");
 tolua_usertype(tolua_S,"E_GUI_STRATEGY");
 tolua_usertype(tolua_S,"OIS::Mouse");
 tolua_usertype(tolua_S,"Core::Effects::CEffectsManager");
 tolua_usertype(tolua_S,"Core::Effects::CParticleEffect");
 tolua_usertype(tolua_S,"FrameListener");
 tolua_usertype(tolua_S,"Core::AI::CCharacterStateManager");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IConsoleParser*>");
 tolua_usertype(tolua_S,"DataStreamPtr");
 tolua_usertype(tolua_S,"Core::CWeapon");
 tolua_usertype(tolua_S,"Core::AI::CFpsVehicle");
 tolua_usertype(tolua_S,"Core::CEditString");
 tolua_usertype(tolua_S,"OIS::JoyStickListener");
 tolua_usertype(tolua_S,"OIS::KeyEvent");
 tolua_usertype(tolua_S,"FrameEvent");
 tolua_usertype(tolua_S,"Vector<String>");
 tolua_usertype(tolua_S,"Resource");
 tolua_usertype(tolua_S,"Vector<Core::Plugin::IAiStateFactory*>");
 tolua_usertype(tolua_S,"Core::Nature::CNatureManager");
 tolua_usertype(tolua_S,"Sound::CSoundManager");
 tolua_usertype(tolua_S,"Camera");
 tolua_usertype(tolua_S,"Core::CGameObject");
 tolua_usertype(tolua_S,"Vector3");
 tolua_usertype(tolua_S,"Core::Physics::IPhysicsStrategy");
 tolua_usertype(tolua_S,"Vector<Core::CItemProfile*>");
 tolua_usertype(tolua_S,"OIS::MouseListener");
}

/* method: Instance of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_Instance00
static int tolua_Core_Core_CPluginManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CPluginManager* tolua_ret = (Core::CPluginManager*)  Core::CPluginManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPluginManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_delete00
static int tolua_Core_Core_CPluginManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadPlugin of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_LoadPlugin00
static int tolua_Core_Core_CPluginManager_LoadPlugin00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadPlugin'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->LoadPlugin(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadPlugin'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGameObjectFactories of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetGameObjectFactories00
static int tolua_Core_Core_CPluginManager_GetGameObjectFactories00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGameObjectFactories'", NULL);
#endif
  {
   Vector<Core::Plugin::IGameObjectFactory*>& tolua_ret = (Vector<Core::Plugin::IGameObjectFactory*>&)  self->GetGameObjectFactories();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IGameObjectFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGameObjectFactories'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetConsoleParsers of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetConsoleParsers00
static int tolua_Core_Core_CPluginManager_GetConsoleParsers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetConsoleParsers'", NULL);
#endif
  {
   Vector<Core::Plugin::IConsoleParser*>& tolua_ret = (Vector<Core::Plugin::IConsoleParser*>&)  self->GetConsoleParsers();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IConsoleParser*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetConsoleParsers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMissionFactories of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetMissionFactories00
static int tolua_Core_Core_CPluginManager_GetMissionFactories00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMissionFactories'", NULL);
#endif
  {
   Vector<Core::Plugin::IMissionFactory*>& tolua_ret = (Vector<Core::Plugin::IMissionFactory*>&)  self->GetMissionFactories();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IMissionFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMissionFactories'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAiStateFactories of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetAiStateFactories00
static int tolua_Core_Core_CPluginManager_GetAiStateFactories00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAiStateFactories'", NULL);
#endif
  {
   Vector<Core::Plugin::IAiStateFactory*>& tolua_ret = (Vector<Core::Plugin::IAiStateFactory*>&)  self->GetAiStateFactories();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IAiStateFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAiStateFactories'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerFactories of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetPlayerFactories00
static int tolua_Core_Core_CPluginManager_GetPlayerFactories00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerFactories'", NULL);
#endif
  {
   Vector<Core::Plugin::IPlayerFactory*>& tolua_ret = (Vector<Core::Plugin::IPlayerFactory*>&)  self->GetPlayerFactories();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IPlayerFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerFactories'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParticleFactories of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetParticleFactories00
static int tolua_Core_Core_CPluginManager_GetParticleFactories00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParticleFactories'", NULL);
#endif
  {
   Vector<Core::Plugin::IParticleFactory*>& tolua_ret = (Vector<Core::Plugin::IParticleFactory*>&)  self->GetParticleFactories();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IParticleFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParticleFactories'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCameraFactories of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetCameraFactories00
static int tolua_Core_Core_CPluginManager_GetCameraFactories00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCameraFactories'", NULL);
#endif
  {
   Vector<Core::Plugin::ICameraFactory*>& tolua_ret = (Vector<Core::Plugin::ICameraFactory*>&)  self->GetCameraFactories();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::ICameraFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCameraFactories'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPostEffectFactories of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetPostEffectFactories00
static int tolua_Core_Core_CPluginManager_GetPostEffectFactories00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPostEffectFactories'", NULL);
#endif
  {
   Vector<Core::Plugin::IPostEffectFactory*>& tolua_ret = (Vector<Core::Plugin::IPostEffectFactory*>&)  self->GetPostEffectFactories();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IPostEffectFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPostEffectFactories'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicsStrategyFactoryies of class  Core::CPluginManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPluginManager_GetPhysicsStrategyFactoryies00
static int tolua_Core_Core_CPluginManager_GetPhysicsStrategyFactoryies00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPluginManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPluginManager* self = (Core::CPluginManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicsStrategyFactoryies'", NULL);
#endif
  {
   Vector<Core::Plugin::IPhysicsStrategyFactory*>& tolua_ret = (Vector<Core::Plugin::IPhysicsStrategyFactory*>&)  self->GetPhysicsStrategyFactoryies();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::Plugin::IPhysicsStrategyFactory*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicsStrategyFactoryies'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_Instance00
static int tolua_Core_Core_CCameraManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CCameraManager* tolua_ret = (Core::CCameraManager*)  Core::CCameraManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CCameraManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_delete00
static int tolua_Core_Core_CCameraManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMode of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetMode00
static int tolua_Core_Core_CCameraManager_GetMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMode'", NULL);
#endif
  {
   Core::E_CAMERA_MODE tolua_ret = (Core::E_CAMERA_MODE)  self->GetMode();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCamera of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetCamera00
static int tolua_Core_Core_CCameraManager_GetCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCamera'", NULL);
#endif
  {
   Camera* tolua_ret = (Camera*)  self->GetCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewport of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetViewport00
static int tolua_Core_Core_CCameraManager_GetViewport00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewport'", NULL);
#endif
  {
   Viewport* tolua_ret = (Viewport*)  self->GetViewport();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Viewport");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewport'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCameraPos of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetCameraPos00
static int tolua_Core_Core_CCameraManager_GetCameraPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCameraPos'", NULL);
#endif
  {
   const Vector3 tolua_ret = (const Vector3)  self->GetCameraPos();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"const Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(const Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"const Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCameraPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCameras of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetCameras00
static int tolua_Core_Core_CCameraManager_GetCameras00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCameras'", NULL);
#endif
  {
   Vector<Core::ICamera*>& tolua_ret = (Vector<Core::ICamera*>&)  self->GetCameras();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::ICamera*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCameras'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsPlayerFriendly of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetIsPlayerFriendly00
static int tolua_Core_Core_CCameraManager_GetIsPlayerFriendly00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsPlayerFriendly'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsPlayerFriendly();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsPlayerFriendly'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCameraNode of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetCameraNode00
static int tolua_Core_Core_CCameraManager_GetCameraNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCameraNode'", NULL);
#endif
  {
   SceneNode* tolua_ret = (SceneNode*)  self->GetCameraNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCameraNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTargetNode of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_GetTargetNode00
static int tolua_Core_Core_CCameraManager_GetTargetNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTargetNode'", NULL);
#endif
  {
   SceneNode* tolua_ret = (SceneNode*)  self->GetTargetNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTargetNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMoveSpeed of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_SetMoveSpeed00
static int tolua_Core_Core_CCameraManager_SetMoveSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  const float Speed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMoveSpeed'", NULL);
#endif
  {
   self->SetMoveSpeed(Speed);
   tolua_pushnumber(tolua_S,(lua_Number)Speed);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMoveSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabled of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_SetEnabled00
static int tolua_Core_Core_CCameraManager_SetEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  bool Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnabled'", NULL);
#endif
  {
   self->SetEnabled(Enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCameraPos of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_SetCameraPos00
static int tolua_Core_Core_CCameraManager_SetCameraPos00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  Vector3* Pos = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCameraPos'", NULL);
#endif
  {
   self->SetCameraPos(*Pos);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCameraPos'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCurrCamera of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_SetCurrCamera00
static int tolua_Core_Core_CCameraManager_SetCurrCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int Index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCurrCamera'", NULL);
#endif
  {
   self->SetCurrCamera(Index);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCurrCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsHaveMode of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_IsHaveMode00
static int tolua_Core_Core_CCameraManager_IsHaveMode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_CAMERA_MODE Mode = ((Core::E_CAMERA_MODE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsHaveMode'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsHaveMode(Mode);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsHaveMode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllCameras of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_RemoveAllCameras00
static int tolua_Core_Core_CCameraManager_RemoveAllCameras00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllCameras'", NULL);
#endif
  {
   self->RemoveAllCameras();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllCameras'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shutdown of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_Shutdown00
static int tolua_Core_Core_CCameraManager_Shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shutdown'", NULL);
#endif
  {
   self->Shutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Restart of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_Restart00
static int tolua_Core_Core_CCameraManager_Restart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Restart'", NULL);
#endif
  {
   self->Restart();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Restart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateCamera of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_CreateCamera00
static int tolua_Core_Core_CCameraManager_CreateCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"SceneNode",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_CAMERA_MODE Type = ((Core::E_CAMERA_MODE) (int)  tolua_tonumber(tolua_S,2,0));
  SceneNode* Parent = ((SceneNode*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateCamera'", NULL);
#endif
  {
   int tolua_ret = (int)  self->CreateCamera(Type,Parent);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreatePluginCamera of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_CreatePluginCamera00
static int tolua_Core_Core_CCameraManager_CreatePluginCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"SceneNode",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_CAMERA_MODE Type = ((Core::E_CAMERA_MODE) (int)  tolua_tonumber(tolua_S,2,0));
  SceneNode* Parent = ((SceneNode*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreatePluginCamera'", NULL);
#endif
  {
   int tolua_ret = (int)  self->CreatePluginCamera(Type,Parent);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreatePluginCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_Update00
static int tolua_Core_Core_CCameraManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CCameraManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CCameraManager_Update01
static int tolua_Core_Core_CCameraManager_Update01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CCameraManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CCameraManager* self = (Core::CCameraManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
  Core::E_CAMERA_MODE Mode = ((Core::E_CAMERA_MODE) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime,Mode);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_CCameraManager_Update00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_delete00
static int tolua_Core_Core_CPlayer_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_Update00
static int tolua_Core_Core_CPlayer_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"OIS::Keyboard",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"OIS::Mouse",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
  OIS::Keyboard* Keyboard = ((OIS::Keyboard*)  tolua_tousertype(tolua_S,3,0));
  OIS::Mouse* Mouse = ((OIS::Mouse*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime,Keyboard,Mouse);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerNode of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetPlayerNode00
static int tolua_Core_Core_CPlayer_GetPlayerNode00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerNode'", NULL);
#endif
  {
   SceneNode* tolua_ret = (SceneNode*)  self->GetPlayerNode();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneNode");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerNode'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerEntity of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetPlayerEntity00
static int tolua_Core_Core_CPlayer_GetPlayerEntity00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerEntity'", NULL);
#endif
  {
   Entity* tolua_ret = (Entity*)  self->GetPlayerEntity();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Entity");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerEntity'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHealth of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetHealth00
static int tolua_Core_Core_CPlayer_GetHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHealth'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetHealth();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHealth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetViewRange of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetViewRange00
static int tolua_Core_Core_CPlayer_GetViewRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetViewRange'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetViewRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetViewRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerState of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetPlayerState00
static int tolua_Core_Core_CPlayer_GetPlayerState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerState'", NULL);
#endif
  {
   Core::E_PLAYER_STATE tolua_ret = (Core::E_PLAYER_STATE)  self->GetPlayerState();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAiVehicle of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetAiVehicle00
static int tolua_Core_Core_CPlayer_GetAiVehicle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAiVehicle'", NULL);
#endif
  {
   Core::AI::CFpsVehicle* tolua_ret = (Core::AI::CFpsVehicle*)  self->GetAiVehicle();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::AI::CFpsVehicle");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAiVehicle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharacterState of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetCharacterState00
static int tolua_Core_Core_CPlayer_GetCharacterState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharacterState'", NULL);
#endif
  {
   Core::AI::CCharacterState* tolua_ret = (Core::AI::CCharacterState*)  self->GetCharacterState();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::AI::CCharacterState");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCharacterState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerTeam of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetPlayerTeam00
static int tolua_Core_Core_CPlayer_GetPlayerTeam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerTeam'", NULL);
#endif
  {
   Core::E_PLAYER_TEAM tolua_ret = (Core::E_PLAYER_TEAM)  self->GetPlayerTeam();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerTeam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPosition of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetPosition00
static int tolua_Core_Core_CPlayer_GetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPosition'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->GetPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetName00
static int tolua_Core_Core_CPlayer_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMeshName of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetMeshName00
static int tolua_Core_Core_CPlayer_GetMeshName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMeshName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetMeshName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMeshName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsVisible of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetIsVisible00
static int tolua_Core_Core_CPlayer_GetIsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetIsHumanPlayer of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetIsHumanPlayer00
static int tolua_Core_Core_CPlayer_GetIsHumanPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetIsHumanPlayer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetIsHumanPlayer();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetIsHumanPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDirection of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetDirection00
static int tolua_Core_Core_CPlayer_GetDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDirection'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->GetDirection();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItems of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetItems00
static int tolua_Core_Core_CPlayer_GetItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItems'", NULL);
#endif
  {
   Vector<Core::IInventoryItem*> tolua_ret = (Vector<Core::IInventoryItem*>)  self->GetItems();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector<Core::IInventoryItem*>)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector<Core::IInventoryItem*>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector<Core::IInventoryItem*>));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector<Core::IInventoryItem*>");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeadPosition of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetHeadPosition00
static int tolua_Core_Core_CPlayer_GetHeadPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeadPosition'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->GetHeadPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeadPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHeadRotation of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetHeadRotation00
static int tolua_Core_Core_CPlayer_GetHeadRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHeadRotation'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->GetHeadRotation();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHeadRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBodyPosition of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetBodyPosition00
static int tolua_Core_Core_CPlayer_GetBodyPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBodyPosition'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->GetBodyPosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBodyPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBodyRotation of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetBodyRotation00
static int tolua_Core_Core_CPlayer_GetBodyRotation00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBodyRotation'", NULL);
#endif
  {
   Quaternion tolua_ret = (Quaternion)  self->GetBodyRotation();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Quaternion)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Quaternion));
     tolua_pushusertype(tolua_S,tolua_obj,"Quaternion");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBodyRotation'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAiTarget of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetAiTarget00
static int tolua_Core_Core_CPlayer_GetAiTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAiTarget'", NULL);
#endif
  {
   Core::AI::CFpsVehicle* tolua_ret = (Core::AI::CFpsVehicle*)  self->GetAiTarget();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::AI::CFpsVehicle");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAiTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAiPathPoints of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetAiPathPoints00
static int tolua_Core_Core_CPlayer_GetAiPathPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Vector3>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Vector<Vector3>* Paths = ((Vector<Vector3>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAiPathPoints'", NULL);
#endif
  {
   self->GetAiPathPoints(*Paths);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAiPathPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurrentWeapon of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetCurrentWeapon00
static int tolua_Core_Core_CPlayer_GetCurrentWeapon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurrentWeapon'", NULL);
#endif
  {
   Core::IInventoryItem* tolua_ret = (Core::IInventoryItem*)  self->GetCurrentWeapon();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::IInventoryItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurrentWeapon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEyePosition of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetEyePosition00
static int tolua_Core_Core_CPlayer_GetEyePosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEyePosition'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->GetEyePosition();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEyePosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharacterControllerSize of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetCharacterControllerSize00
static int tolua_Core_Core_CPlayer_GetCharacterControllerSize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharacterControllerSize'", NULL);
#endif
  {
   Vector3 tolua_ret = (Vector3)  self->GetCharacterControllerSize();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((Vector3)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(Vector3));
     tolua_pushusertype(tolua_S,tolua_obj,"Vector3");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCharacterControllerSize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLoSType of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetLoSType00
static int tolua_Core_Core_CPlayer_GetLoSType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLoSType'", NULL);
#endif
  {
   Core::E_LOS_TYPE tolua_ret = (Core::E_LOS_TYPE)  self->GetLoSType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLoSType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerType of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetPlayerType00
static int tolua_Core_Core_CPlayer_GetPlayerType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerType'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetPlayerType();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicsStrategy of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetPhysicsStrategy00
static int tolua_Core_Core_CPlayer_GetPhysicsStrategy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicsStrategy'", NULL);
#endif
  {
   Core::Physics::IPhysicsStrategy* tolua_ret = (Core::Physics::IPhysicsStrategy*)  self->GetPhysicsStrategy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::IPhysicsStrategy");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicsStrategy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharacterController of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetCharacterController00
static int tolua_Core_Core_CPlayer_GetCharacterController00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharacterController'", NULL);
#endif
  {
   Core::Physics::ICharacterController* tolua_ret = (Core::Physics::ICharacterController*)  self->GetCharacterController();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::ICharacterController");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCharacterController'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRunSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetRunSpeed00
static int tolua_Core_Core_CPlayer_GetRunSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRunSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetRunSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRunSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWalkSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetWalkSpeed00
static int tolua_Core_Core_CPlayer_GetWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWalkSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetWalkSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSprintSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetSprintSpeed00
static int tolua_Core_Core_CPlayer_GetSprintSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSprintSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetSprintSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSprintSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCrawlSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetCrawlSpeed00
static int tolua_Core_Core_CPlayer_GetCrawlSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCrawlSpeed'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetCrawlSpeed();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCrawlSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDieTime of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetDieTime00
static int tolua_Core_Core_CPlayer_GetDieTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDieTime'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetDieTime();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDieTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMovableText of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_GetMovableText00
static int tolua_Core_Core_CPlayer_GetMovableText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMovableText'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetMovableText();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMovableText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRunSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetRunSpeed00
static int tolua_Core_Core_CPlayer_SetRunSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float Speed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRunSpeed'", NULL);
#endif
  {
   self->SetRunSpeed(Speed);
   tolua_pushnumber(tolua_S,(lua_Number)Speed);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRunSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWalkSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetWalkSpeed00
static int tolua_Core_Core_CPlayer_SetWalkSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float Speed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWalkSpeed'", NULL);
#endif
  {
   self->SetWalkSpeed(Speed);
   tolua_pushnumber(tolua_S,(lua_Number)Speed);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWalkSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSprintSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetSprintSpeed00
static int tolua_Core_Core_CPlayer_SetSprintSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float Speed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSprintSpeed'", NULL);
#endif
  {
   self->SetSprintSpeed(Speed);
   tolua_pushnumber(tolua_S,(lua_Number)Speed);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSprintSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCrawlSpeed of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetCrawlSpeed00
static int tolua_Core_Core_CPlayer_SetCrawlSpeed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float Speed = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCrawlSpeed'", NULL);
#endif
  {
   self->SetCrawlSpeed(Speed);
   tolua_pushnumber(tolua_S,(lua_Number)Speed);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCrawlSpeed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDieTime of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetDieTime00
static int tolua_Core_Core_CPlayer_SetDieTime00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float Time = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDieTime'", NULL);
#endif
  {
   self->SetDieTime(Time);
   tolua_pushnumber(tolua_S,(lua_Number)Time);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDieTime'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHealth of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetHealth00
static int tolua_Core_Core_CPlayer_SetHealth00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  unsigned int Health = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHealth'", NULL);
#endif
  {
   self->SetHealth(Health);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHealth'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetVisible00
static int tolua_Core_Core_CPlayer_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  bool Visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
  {
   self->SetVisible(Visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlayerState of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetPlayerState00
static int tolua_Core_Core_CPlayer_SetPlayerState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_STATE State = ((Core::E_PLAYER_STATE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlayerState'", NULL);
#endif
  {
   self->SetPlayerState(State);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlayerState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAiVehicle of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetAiVehicle00
static int tolua_Core_Core_CPlayer_SetAiVehicle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::AI::CFpsVehicle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::AI::CFpsVehicle* Vehicle = ((Core::AI::CFpsVehicle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAiVehicle'", NULL);
#endif
  {
   self->SetAiVehicle(Vehicle);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAiVehicle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCharacterState of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetCharacterState00
static int tolua_Core_Core_CPlayer_SetCharacterState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_STATE State = ((Core::E_PLAYER_STATE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCharacterState'", NULL);
#endif
  {
   self->SetCharacterState(State);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCharacterState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetExcactCharacterState of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetExcactCharacterState00
static int tolua_Core_Core_CPlayer_SetExcactCharacterState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const char* State = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetExcactCharacterState'", NULL);
#endif
  {
   self->SetExcactCharacterState(State);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetExcactCharacterState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlayerPosition of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetPlayerPosition00
static int tolua_Core_Core_CPlayer_SetPlayerPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* Position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlayerPosition'", NULL);
#endif
  {
   self->SetPlayerPosition(*Position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlayerPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlayerPosition of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetPlayerPosition01
static int tolua_Core_Core_CPlayer_SetPlayerPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float x = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float y = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float z = ((const float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlayerPosition'", NULL);
#endif
  {
   self->SetPlayerPosition(x,y,z);
   tolua_pushnumber(tolua_S,(lua_Number)x);
   tolua_pushnumber(tolua_S,(lua_Number)y);
   tolua_pushnumber(tolua_S,(lua_Number)z);
  }
 }
 return 3;
tolua_lerror:
 return tolua_Core_Core_CPlayer_SetPlayerPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPlayerTeam of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetPlayerTeam00
static int tolua_Core_Core_CPlayer_SetPlayerTeam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPlayerTeam'", NULL);
#endif
  {
   self->SetPlayerTeam(Team);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPlayerTeam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHumanPlayer of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetHumanPlayer00
static int tolua_Core_Core_CPlayer_SetHumanPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  bool isPlayer = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHumanPlayer'", NULL);
#endif
  {
   self->SetHumanPlayer(isPlayer);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHumanPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetViewRange of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetViewRange00
static int tolua_Core_Core_CPlayer_SetViewRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float Range = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetViewRange'", NULL);
#endif
  {
   self->SetViewRange(Range);
   tolua_pushnumber(tolua_S,(lua_Number)Range);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetViewRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextLabelCaption of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetTextLabelCaption00
static int tolua_Core_Core_CPlayer_SetTextLabelCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const char* Text = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextLabelCaption'", NULL);
#endif
  {
   self->SetTextLabelCaption(Text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextLabelCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTextLabelEnabled of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetTextLabelEnabled00
static int tolua_Core_Core_CPlayer_SetTextLabelEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  bool Enabled = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTextLabelEnabled'", NULL);
#endif
  {
   self->SetTextLabelEnabled(Enabled);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTextLabelEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAiTarget of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetAiTarget00
static int tolua_Core_Core_CPlayer_SetAiTarget00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::AI::CFpsVehicle",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::AI::CFpsVehicle* Target = ((Core::AI::CFpsVehicle*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAiTarget'", NULL);
#endif
  {
   self->SetAiTarget(Target);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAiTarget'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAiPathPoints of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetAiPathPoints00
static int tolua_Core_Core_CPlayer_SetAiPathPoints00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector<Vector3>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const Vector<Vector3>* PathPoints = ((const Vector<Vector3>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAiPathPoints'", NULL);
#endif
  {
   self->SetAiPathPoints(*PathPoints);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAiPathPoints'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetName00
static int tolua_Core_Core_CPlayer_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const char* LabelName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetName'", NULL);
#endif
  {
   self->SetName(LabelName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetDirection of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetDirection00
static int tolua_Core_Core_CPlayer_SetDirection00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* Direction = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetDirection'", NULL);
#endif
  {
   self->SetDirection(*Direction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetDirection'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetLoSType of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_SetLoSType00
static int tolua_Core_Core_CPlayer_SetLoSType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::E_LOS_TYPE Type = ((Core::E_LOS_TYPE) (int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetLoSType'", NULL);
#endif
  {
   self->SetLoSType(Type);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetLoSType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CanSee of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_CanSee00
static int tolua_Core_Core_CPlayer_CanSee00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* Position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CanSee'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CanSee(*Position);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CanSee'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CanSee of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_CanSee01
static int tolua_Core_Core_CPlayer_CanSee01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CanSee'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CanSee(Player);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_CPlayer_CanSee00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddItem of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_AddItem00
static int tolua_Core_Core_CPlayer_AddItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::IInventoryItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::IInventoryItem* Item = ((Core::IInventoryItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddItem'", NULL);
#endif
  {
   self->AddItem(Item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveItem of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_RemoveItem00
static int tolua_Core_Core_CPlayer_RemoveItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::IInventoryItem",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::IInventoryItem* Item = ((Core::IInventoryItem*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveItem'", NULL);
#endif
  {
   self->RemoveItem(Item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllItems of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_RemoveAllItems00
static int tolua_Core_Core_CPlayer_RemoveAllItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllItems'", NULL);
#endif
  {
   self->RemoveAllItems();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DebugLoS of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_DebugLoS00
static int tolua_Core_Core_CPlayer_DebugLoS00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  bool Show = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DebugLoS'", NULL);
#endif
  {
   self->DebugLoS(Show);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DebugLoS'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnHit of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_OnHit00
static int tolua_Core_Core_CPlayer_OnHit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CProjectile",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::CProjectile* Projectile = ((Core::CProjectile*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* Direction = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnHit'", NULL);
#endif
  {
   self->OnHit(Projectile,*Direction);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnHit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnShotFired of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_OnShotFired00
static int tolua_Core_Core_CPlayer_OnShotFired00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnShotFired'", NULL);
#endif
  {
   self->OnShotFired();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnShotFired'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnMove of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_OnMove00
static int tolua_Core_Core_CPlayer_OnMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"OIS::Keyboard",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
  OIS::Keyboard* Keyboard = ((OIS::Keyboard*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnMove'", NULL);
#endif
  {
   self->OnMove(elapsedTime,Keyboard);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnPickupItem of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_OnPickupItem00
static int tolua_Core_Core_CPlayer_OnPickupItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnPickupItem'", NULL);
#endif
  {
   self->OnPickupItem();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnPickupItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnKill of class  Core::CPlayer */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayer_OnKill00
static int tolua_Core_Core_CPlayer_OnKill00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayer* self = (Core::CPlayer*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
  Core::CProjectile* Projectile = ((Core::CProjectile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnKill'", NULL);
#endif
  {
   self->OnKill(Player,Projectile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnKill'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::AI::CCharacterState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterState_Update00
static int tolua_Core_Core_AI_CCharacterState_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterState* self = (Core::AI::CCharacterState*)  tolua_tousertype(tolua_S,1,0);
  float elapsedTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   Core::AI::E_CHARACTER_STATE_OUTCOME tolua_ret = (Core::AI::E_CHARACTER_STATE_OUTCOME)  self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOutcomeState of class  Core::AI::CCharacterState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterState_GetOutcomeState00
static int tolua_Core_Core_AI_CCharacterState_GetOutcomeState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterState* self = (Core::AI::CCharacterState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOutcomeState'", NULL);
#endif
  {
   Core::AI::E_CHARACTER_STATE_OUTCOME tolua_ret = (Core::AI::E_CHARACTER_STATE_OUTCOME)  self->GetOutcomeState();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOutcomeState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStateType of class  Core::AI::CCharacterState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterState_GetStateType00
static int tolua_Core_Core_AI_CCharacterState_GetStateType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterState* self = (Core::AI::CCharacterState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStateType'", NULL);
#endif
  {
   Core::E_PLAYER_STATE tolua_ret = (Core::E_PLAYER_STATE)  self->GetStateType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStateType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStateName of class  Core::AI::CCharacterState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterState_GetStateName00
static int tolua_Core_Core_AI_CCharacterState_GetStateName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterState* self = (Core::AI::CCharacterState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStateName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetStateName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStateName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLevel of class  Core::AI::CCharacterState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterState_GetLevel00
static int tolua_Core_Core_AI_CCharacterState_GetLevel00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterState* self = (Core::AI::CCharacterState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLevel'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetLevel();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLevel'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_Instance00
static int tolua_Core_Core_AI_CCharacterStateManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::AI::CCharacterStateManager* tolua_ret = (Core::AI::CCharacterStateManager*)  Core::AI::CCharacterStateManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::AI::CCharacterStateManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_delete00
static int tolua_Core_Core_AI_CCharacterStateManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetState of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_GetState00
static int tolua_Core_Core_AI_CCharacterStateManager_GetState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_STATE Type = ((Core::E_PLAYER_STATE) (int)  tolua_tonumber(tolua_S,2,0));
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,3,0));
  unsigned int Level = ((unsigned int)  tolua_tonumber(tolua_S,4,1));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetState'", NULL);
#endif
  {
   Core::AI::CCharacterState* tolua_ret = (Core::AI::CCharacterState*)  self->GetState(Type,Player,Level);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::AI::CCharacterState");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetState of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_GetState01
static int tolua_Core_Core_AI_CCharacterStateManager_GetState01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  const char* StateName = ((const char*)  tolua_tostring(tolua_S,2,0));
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetState'", NULL);
#endif
  {
   Core::AI::CCharacterState* tolua_ret = (Core::AI::CCharacterState*)  self->GetState(StateName,Player);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::AI::CCharacterState");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_AI_CCharacterStateManager_GetState00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllStates of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_GetAllStates00
static int tolua_Core_Core_AI_CCharacterStateManager_GetAllStates00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<const char*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<const char*>* States = ((Vector<const char*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllStates'", NULL);
#endif
  {
   self->GetAllStates(*States);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllStates'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetLoadedStates of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_GetLoadedStates00
static int tolua_Core_Core_AI_CCharacterStateManager_GetLoadedStates00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<String>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<String>* Names = ((Vector<String>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetLoadedStates'", NULL);
#endif
  {
   self->GetLoadedStates(*Names);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetLoadedStates'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddPath of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_AddPath00
static int tolua_Core_Core_AI_CCharacterStateManager_AddPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector<Vector3>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const Vector<Vector3>* Paths = ((const Vector<Vector3>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPath'", NULL);
#endif
  {
   self->AddPath(Name,*Paths);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPathCount of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_GetPathCount00
static int tolua_Core_Core_AI_CCharacterStateManager_GetPathCount00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPathCount'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetPathCount();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPathCount'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPathByName of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_GetPathByName00
static int tolua_Core_Core_AI_CCharacterStateManager_GetPathByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector<Vector3>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
  Vector<Vector3>* Path = ((Vector<Vector3>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPathByName'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetPathByName(Name,*Path);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPathByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllPaths of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_GetAllPaths00
static int tolua_Core_Core_AI_CCharacterStateManager_GetAllPaths00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PathDefinition",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  PathDefinition* Paths = ((PathDefinition*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllPaths'", NULL);
#endif
  {
   self->GetAllPaths(*Paths);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllPaths'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetName of class  Core::AI::CCharacterStateManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_AI_CCharacterStateManager_SetName00
static int tolua_Core_Core_AI_CCharacterStateManager_SetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::AI::CCharacterStateManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::AI::CCharacterStateManager* self = (Core::AI::CCharacterStateManager*)  tolua_tousertype(tolua_S,1,0);
  const char* OldName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* NewName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetName'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetName(OldName,NewName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetIsUpdatable of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObject_SetIsUpdatable00
static int tolua_Core_Core_CGameObject_SetIsUpdatable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
  bool Value = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetIsUpdatable'", NULL);
#endif
  {
   self->SetIsUpdatable(Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetIsUpdatable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObject_SetPosition00
static int tolua_Core_Core_CGameObject_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* Position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(*Position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObject_Update00
static int tolua_Core_Core_CGameObject_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Name of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CGameObject_Name
static int tolua_get_Core__CGameObject_Name(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Name'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Name,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Name of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CGameObject_Name
static int tolua_set_Core__CGameObject_Name(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Name'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Name = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GameObjectType of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CGameObject_GameObjectType
static int tolua_get_Core__CGameObject_GameObjectType(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameObjectType'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->GameObjectType,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GameObjectType of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CGameObject_GameObjectType
static int tolua_set_Core__CGameObject_GameObjectType(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameObjectType'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->GameObjectType = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Node of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CGameObject_Node_ptr
static int tolua_get_Core__CGameObject_Node_ptr(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Node'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Node,"SceneNode");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Node of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CGameObject_Node_ptr
static int tolua_set_Core__CGameObject_Node_ptr(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Node'",NULL);
  if (!tolua_isusertype(tolua_S,2,"SceneNode",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Node = ((SceneNode*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Entity of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CGameObject_Entity_ptr
static int tolua_get_Core__CGameObject_Entity_ptr(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Entity'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Entity,"Entity");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Entity of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CGameObject_Entity_ptr
static int tolua_set_Core__CGameObject_Entity_ptr(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Entity'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Entity = ((Entity*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: PhysicsProfile of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CGameObject_PhysicsProfile_ptr
static int tolua_get_Core__CGameObject_PhysicsProfile_ptr(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PhysicsProfile'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->PhysicsProfile,"Core::Physics::CPhysicsProfile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: PhysicsProfile of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CGameObject_PhysicsProfile_ptr
static int tolua_set_Core__CGameObject_PhysicsProfile_ptr(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PhysicsProfile'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::Physics::CPhysicsProfile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PhysicsProfile = ((Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: EnvironmentType of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CGameObject_EnvironmentType
static int tolua_get_Core__CGameObject_EnvironmentType(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EnvironmentType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->EnvironmentType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: EnvironmentType of class  Core::CGameObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CGameObject_EnvironmentType
static int tolua_set_Core__CGameObject_EnvironmentType(lua_State* tolua_S)
{
  Core::CGameObject* self = (Core::CGameObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EnvironmentType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->EnvironmentType = ((Core::ENVIRONMENT_ATTRIBUTE_TYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CDummyGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CDummyGameObject_new00
static int tolua_Core_Core_CDummyGameObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CDummyGameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CDummyGameObject* tolua_ret = (Core::CDummyGameObject*)  Mtolua_new((Core::CDummyGameObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CDummyGameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CDummyGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CDummyGameObject_new00_local
static int tolua_Core_Core_CDummyGameObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CDummyGameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CDummyGameObject* tolua_ret = (Core::CDummyGameObject*)  Mtolua_new((Core::CDummyGameObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CDummyGameObject");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CDummyGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CDummyGameObject_new01
static int tolua_Core_Core_CDummyGameObject_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CDummyGameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Ogre::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
  SceneNode* n = ((SceneNode*)  tolua_tousertype(tolua_S,3,0));
  Ogre::Entity* e = ((Ogre::Entity*)  tolua_tousertype(tolua_S,4,0));
  {
   Core::CDummyGameObject* tolua_ret = (Core::CDummyGameObject*)  Mtolua_new((Core::CDummyGameObject)(Name,n,e));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CDummyGameObject");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_CDummyGameObject_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CDummyGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CDummyGameObject_new01_local
static int tolua_Core_Core_CDummyGameObject_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CDummyGameObject",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"SceneNode",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"Ogre::Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
  SceneNode* n = ((SceneNode*)  tolua_tousertype(tolua_S,3,0));
  Ogre::Entity* e = ((Ogre::Entity*)  tolua_tousertype(tolua_S,4,0));
  {
   Core::CDummyGameObject* tolua_ret = (Core::CDummyGameObject*)  Mtolua_new((Core::CDummyGameObject)(Name,n,e));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CDummyGameObject");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_CDummyGameObject_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CDummyGameObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CDummyGameObject_Update00
static int tolua_Core_Core_CDummyGameObject_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CDummyGameObject",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CDummyGameObject* self = (Core::CDummyGameObject*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartTimer of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_StartTimer00
static int tolua_Core_Core_Effects_CParticleEffect_StartTimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartTimer'", NULL);
#endif
  {
   self->StartTimer();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_Update00
static int tolua_Core_Core_Effects_CParticleEffect_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
  const float timeSinceLastFrame = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(timeSinceLastFrame);
   tolua_pushnumber(tolua_S,(lua_Number)timeSinceLastFrame);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateAll of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_UpdateAll00
static int tolua_Core_Core_Effects_CParticleEffect_UpdateAll00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const float timeSinceLastFrame = ((const float)  tolua_tonumber(tolua_S,2,0));
  {
   Core::Effects::CParticleEffect::UpdateAll(timeSinceLastFrame);
   tolua_pushnumber(tolua_S,(lua_Number)timeSinceLastFrame);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateAll'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddDynamicEffect of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_AddDynamicEffect00
static int tolua_Core_Core_Effects_CParticleEffect_AddDynamicEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CParticleEffect* e = ((Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,2,0));
  {
   Core::Effects::CParticleEffect::AddDynamicEffect(e);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddDynamicEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimer of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_GetTimer00
static int tolua_Core_Core_Effects_CParticleEffect_GetTimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimer'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetTimer();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetTimer of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_SetTimer00
static int tolua_Core_Core_Effects_CParticleEffect_SetTimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
  const float Timer = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetTimer'", NULL);
#endif
  {
   self->SetTimer(Timer);
   tolua_pushnumber(tolua_S,(lua_Number)Timer);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_SetPosition00
static int tolua_Core_Core_Effects_CParticleEffect_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
  Vector3* Position = ((Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(*Position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CParticleEffect_SetPosition01
static int tolua_Core_Core_Effects_CParticleEffect_SetPosition01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CParticleEffect",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
  const float X = ((const float)  tolua_tonumber(tolua_S,2,0));
  const float Y = ((const float)  tolua_tonumber(tolua_S,3,0));
  const float Z = ((const float)  tolua_tonumber(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(X,Y,Z);
   tolua_pushnumber(tolua_S,(lua_Number)X);
   tolua_pushnumber(tolua_S,(lua_Number)Y);
   tolua_pushnumber(tolua_S,(lua_Number)Z);
  }
 }
 return 3;
tolua_lerror:
 return tolua_Core_Core_Effects_CParticleEffect_SetPosition00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* get function: LabelName of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_get_Core__Effects__CParticleEffect_LabelName
static int tolua_get_Core__Effects__CParticleEffect_LabelName(lua_State* tolua_S)
{
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LabelName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->LabelName,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: LabelName of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_set_Core__Effects__CParticleEffect_LabelName
static int tolua_set_Core__Effects__CParticleEffect_LabelName(lua_State* tolua_S)
{
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'LabelName'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->LabelName = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ParticleName of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_get_Core__Effects__CParticleEffect_ParticleName
static int tolua_get_Core__Effects__CParticleEffect_ParticleName(lua_State* tolua_S)
{
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ParticleName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->ParticleName,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ParticleName of class  Core::Effects::CParticleEffect */
#ifndef TOLUA_DISABLE_tolua_set_Core__Effects__CParticleEffect_ParticleName
static int tolua_set_Core__Effects__CParticleEffect_ParticleName(lua_State* tolua_S)
{
  Core::Effects::CParticleEffect* self = (Core::Effects::CParticleEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ParticleName'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ParticleName = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterPostEffect of class  Core::Effects::CPostEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CPostEffect_RegisterPostEffect00
static int tolua_Core_Core_Effects_CPostEffect_RegisterPostEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CPostEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CPostEffect* self = (Core::Effects::CPostEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterPostEffect'", NULL);
#endif
  {
   self->RegisterPostEffect();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterPostEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEnabled of class  Core::Effects::CPostEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CPostEffect_SetEnabled00
static int tolua_Core_Core_Effects_CPostEffect_SetEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CPostEffect",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CPostEffect* self = (Core::Effects::CPostEffect*)  tolua_tousertype(tolua_S,1,0);
  bool flag = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEnabled'", NULL);
#endif
  {
   self->SetEnabled(flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Core::Effects::CPostEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CPostEffect_GetName00
static int tolua_Core_Core_Effects_CPostEffect_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CPostEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CPostEffect* self = (Core::Effects::CPostEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_Instance00
static int tolua_Core_Core_Effects_CEffectsManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Effects::CEffectsManager* tolua_ret = (Core::Effects::CEffectsManager*)  Core::Effects::CEffectsManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Effects::CEffectsManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_delete00
static int tolua_Core_Core_Effects_CEffectsManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: TogglePostEffects of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_TogglePostEffects00
static int tolua_Core_Core_Effects_CEffectsManager_TogglePostEffects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* EffectName = ((const char*)  tolua_tostring(tolua_S,2,0));
  bool flag = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'TogglePostEffects'", NULL);
#endif
  {
   self->TogglePostEffects(EffectName,flag);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'TogglePostEffects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPostEffect of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_GetPostEffect00
static int tolua_Core_Core_Effects_CEffectsManager_GetPostEffect00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* EffectName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPostEffect'", NULL);
#endif
  {
   Core::Effects::CPostEffect* tolua_ret = (Core::Effects::CPostEffect*)  self->GetPostEffect(EffectName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Effects::CPostEffect");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPostEffect'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateParticle of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_CreateParticle00
static int tolua_Core_Core_Effects_CEffectsManager_CreateParticle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* EffectName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateParticle'", NULL);
#endif
  {
   Core::Effects::CParticleEffect* tolua_ret = (Core::Effects::CParticleEffect*)  self->CreateParticle(EffectName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Effects::CParticleEffect");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateParticle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetParticle of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_GetParticle00
static int tolua_Core_Core_Effects_CEffectsManager_GetParticle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* EffectName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetParticle'", NULL);
#endif
  {
   Core::Effects::CParticleEffect* tolua_ret = (Core::Effects::CParticleEffect*)  self->GetParticle(EffectName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Effects::CParticleEffect");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetParticle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_Update00
static int tolua_Core_Core_Effects_CEffectsManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ReInit of class  Core::Effects::CEffectsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEffectsManager_ReInit00
static int tolua_Core_Core_Effects_CEffectsManager_ReInit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEffectsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEffectsManager* self = (Core::Effects::CEffectsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ReInit'", NULL);
#endif
  {
   self->ReInit();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ReInit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddEffectToGameObject of class  Core::Effects::CEntityEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEntityEffect_AddEffectToGameObject00
static int tolua_Core_Core_Effects_CEntityEffect_AddEffectToGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEntityEffect",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEntityEffect* self = (Core::Effects::CEntityEffect*)  tolua_tousertype(tolua_S,1,0);
  Core::CGameObject* GameObject = ((Core::CGameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddEffectToGameObject'", NULL);
#endif
  {
   self->AddEffectToGameObject(GameObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddEffectToGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveEffectFromGameObject of class  Core::Effects::CEntityEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEntityEffect_RemoveEffectFromGameObject00
static int tolua_Core_Core_Effects_CEntityEffect_RemoveEffectFromGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEntityEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEntityEffect* self = (Core::Effects::CEntityEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveEffectFromGameObject'", NULL);
#endif
  {
   self->RemoveEffectFromGameObject();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveEffectFromGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Core::Effects::CEntityEffect */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Effects_CEntityEffect_GetName00
static int tolua_Core_Core_Effects_CEntityEffect_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Effects::CEntityEffect",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Effects::CEntityEffect* self = (Core::Effects::CEntityEffect*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetName();
   tolua_pushstring(tolua_S,(const char*)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isSupportShaders of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__CGameManager_isSupportShaders
static int tolua_get_Core__CGameManager_isSupportShaders(lua_State* tolua_S)
{
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isSupportShaders'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isSupportShaders);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isSupportShaders of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_set_Core__CGameManager_isSupportShaders
static int tolua_set_Core__CGameManager_isSupportShaders(lua_State* tolua_S)
{
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isSupportShaders'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isSupportShaders = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_Instance00
static int tolua_Core_Core_CGameManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CGameManager* tolua_ret = (Core::CGameManager*)  Core::CGameManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_delete00
static int tolua_Core_Core_CGameManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetEngineDevice of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetEngineDevice00
static int tolua_Core_Core_CGameManager_GetEngineDevice00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetEngineDevice'", NULL);
#endif
  {
   EngineDevice* tolua_ret = (EngineDevice*)  self->GetEngineDevice();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"EngineDevice");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetEngineDevice'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSceneManager of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetSceneManager00
static int tolua_Core_Core_CGameManager_GetSceneManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSceneManager'", NULL);
#endif
  {
   SceneManager* tolua_ret = (SceneManager*)  self->GetSceneManager();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSceneManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRenderWindow of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetRenderWindow00
static int tolua_Core_Core_CGameManager_GetRenderWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRenderWindow'", NULL);
#endif
  {
   RenderWindow* tolua_ret = (RenderWindow*)  self->GetRenderWindow();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"RenderWindow");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRenderWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTimer of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetTimer00
static int tolua_Core_Core_CGameManager_GetTimer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTimer'", NULL);
#endif
  {
   Timer* tolua_ret = (Timer*)  self->GetTimer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Timer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTimer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetVideoDeviceType of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetVideoDeviceType00
static int tolua_Core_Core_CGameManager_GetVideoDeviceType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetVideoDeviceType'", NULL);
#endif
  {
   Core::E_DRIVER_TYPE tolua_ret = (Core::E_DRIVER_TYPE)  self->GetVideoDeviceType();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetVideoDeviceType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetEngineDevice of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetEngineDevice00
static int tolua_Core_Core_CGameManager_SetEngineDevice00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"EngineDevice",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  EngineDevice* e = ((EngineDevice*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetEngineDevice'", NULL);
#endif
  {
   self->SetEngineDevice(e);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetEngineDevice'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetSceneManager of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetSceneManager00
static int tolua_Core_Core_CGameManager_SetSceneManager00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"SceneManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  SceneManager* s = ((SceneManager*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetSceneManager'", NULL);
#endif
  {
   self->SetSceneManager(s);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetSceneManager'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetRenderWindow of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetRenderWindow00
static int tolua_Core_Core_CGameManager_SetRenderWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  RenderWindow* r = ((RenderWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetRenderWindow'", NULL);
#endif
  {
   self->SetRenderWindow(r);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetRenderWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetQuit of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetQuit00
static int tolua_Core_Core_CGameManager_SetQuit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  bool quit = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetQuit'", NULL);
#endif
  {
   self->SetQuit(quit);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetQuit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetQuit of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetQuit00
static int tolua_Core_Core_CGameManager_GetQuit00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetQuit'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetQuit();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetQuit'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: UpdateGame of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_UpdateGame00
static int tolua_Core_Core_CGameManager_UpdateGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'UpdateGame'", NULL);
#endif
  {
   self->UpdateGame(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'UpdateGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shutdown of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_Shutdown00
static int tolua_Core_Core_CGameManager_Shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shutdown'", NULL);
#endif
  {
   self->Shutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetConsoleVisible of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetConsoleVisible00
static int tolua_Core_Core_CGameManager_GetConsoleVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetConsoleVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetConsoleVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetConsoleVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetConsoleVisible of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetConsoleVisible00
static int tolua_Core_Core_CGameManager_SetConsoleVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  bool Visible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetConsoleVisible'", NULL);
#endif
  {
   self->SetConsoleVisible(Visible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetConsoleVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddResourceArchive of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_AddResourceArchive00
static int tolua_Core_Core_CGameManager_AddResourceArchive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* GroupName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddResourceArchive'", NULL);
#endif
  {
   self->AddResourceArchive(FileName,GroupName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddResourceArchive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveResourceArchive of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_RemoveResourceArchive00
static int tolua_Core_Core_CGameManager_RemoveResourceArchive00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* GroupName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveResourceArchive'", NULL);
#endif
  {
   self->RemoveResourceArchive(FileName,GroupName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveResourceArchive'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SaveGame of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SaveGame00
static int tolua_Core_Core_CGameManager_SaveGame00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SaveGame'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SaveGame(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SaveGame'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetStaticData of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetStaticData00
static int tolua_Core_Core_CGameManager_SetStaticData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const String* StaticData = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetStaticData'", NULL);
#endif
  {
   self->SetStaticData(*StaticData);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetStaticData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStaticData of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetStaticData00
static int tolua_Core_Core_CGameManager_GetStaticData00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStaticData'", NULL);
#endif
  {
   String& tolua_ret = (String&)  self->GetStaticData();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"String");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStaticData'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseResourceName of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetBaseResourceName00
static int tolua_Core_Core_CGameManager_SetBaseResourceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const String* ResourceName = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseResourceName'", NULL);
#endif
  {
   self->SetBaseResourceName(*ResourceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseResourceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetBaseAudioResourceName of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_SetBaseAudioResourceName00
static int tolua_Core_Core_CGameManager_SetBaseAudioResourceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const String* ResourceName = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetBaseAudioResourceName'", NULL);
#endif
  {
   self->SetBaseAudioResourceName(*ResourceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetBaseAudioResourceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseResourceName of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetBaseResourceName00
static int tolua_Core_Core_CGameManager_GetBaseResourceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseResourceName'", NULL);
#endif
  {
   String tolua_ret = (String)  self->GetBaseResourceName();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((String)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(String));
     tolua_pushusertype(tolua_S,tolua_obj,"String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseResourceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseAudioResourceName of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetBaseAudioResourceName00
static int tolua_Core_Core_CGameManager_GetBaseAudioResourceName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseAudioResourceName'", NULL);
#endif
  {
   String tolua_ret = (String)  self->GetBaseAudioResourceName();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((String)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(String));
     tolua_pushusertype(tolua_S,tolua_obj,"String");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseAudioResourceName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetScriptPath of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_GetScriptPath00
static int tolua_Core_Core_CGameManager_GetScriptPath00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetScriptPath'", NULL);
#endif
  {
   const char* tolua_ret = (const char*)  self->GetScriptPath();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"String");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetScriptPath'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateScene of class  Core::CGameManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameManager_CreateScene00
static int tolua_Core_Core_CGameManager_CreateScene00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameManager* self = (Core::CGameManager*)  tolua_tousertype(tolua_S,1,0);
  const char* SceneType = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* SceneName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateScene'", NULL);
#endif
  {
   SceneManager* tolua_ret = (SceneManager*)  self->CreateScene(SceneType,SceneName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"SceneManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateScene'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_Instance00
static int tolua_Core_Core_CInputManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CInputManager* tolua_ret = (Core::CInputManager*)  Core::CInputManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CInputManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_delete00
static int tolua_Core_Core_CInputManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Initialise of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_Initialise00
static int tolua_Core_Core_CInputManager_Initialise00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Initialise'", NULL);
#endif
  {
   self->Initialise();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Initialise'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Capture of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_Capture00
static int tolua_Core_Core_CInputManager_Capture00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Capture'", NULL);
#endif
  {
   self->Capture();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Capture'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddKeyListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_AddKeyListener00
static int tolua_Core_Core_CInputManager_AddKeyListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OIS::KeyListener",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  OIS::KeyListener* KeyListener = ((OIS::KeyListener*)  tolua_tousertype(tolua_S,2,0));
  const char* instanceName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddKeyListener'", NULL);
#endif
  {
   self->AddKeyListener(KeyListener,instanceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddKeyListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddMouseListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_AddMouseListener00
static int tolua_Core_Core_CInputManager_AddMouseListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OIS::MouseListener",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  OIS::MouseListener* MouseListener = ((OIS::MouseListener*)  tolua_tousertype(tolua_S,2,0));
  const char* instanceName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddMouseListener'", NULL);
#endif
  {
   self->AddMouseListener(MouseListener,instanceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddMouseListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddJoystickListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_AddJoystickListener00
static int tolua_Core_Core_CInputManager_AddJoystickListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OIS::JoyStickListener",0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  OIS::JoyStickListener* joystickListener = ((OIS::JoyStickListener*)  tolua_tousertype(tolua_S,2,0));
  const char* instanceName = ((const char*)  tolua_tostring(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddJoystickListener'", NULL);
#endif
  {
   self->AddJoystickListener(joystickListener,instanceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddJoystickListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveKeyListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveKeyListener00
static int tolua_Core_Core_CInputManager_RemoveKeyListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  const char* instanceName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveKeyListener'", NULL);
#endif
  {
   self->RemoveKeyListener(instanceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveKeyListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveMouseListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveMouseListener00
static int tolua_Core_Core_CInputManager_RemoveMouseListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  const char* instanceName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveMouseListener'", NULL);
#endif
  {
   self->RemoveMouseListener(instanceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveMouseListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveJoystickListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveJoystickListener00
static int tolua_Core_Core_CInputManager_RemoveJoystickListener00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  const char* instanceName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveJoystickListener'", NULL);
#endif
  {
   self->RemoveJoystickListener(instanceName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveJoystickListener'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveKeyListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveKeyListener01
static int tolua_Core_Core_CInputManager_RemoveKeyListener01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OIS::KeyListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  OIS::KeyListener* KeyListener = ((OIS::KeyListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveKeyListener'", NULL);
#endif
  {
   self->RemoveKeyListener(KeyListener);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Core_Core_CInputManager_RemoveKeyListener00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveMouseListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveMouseListener01
static int tolua_Core_Core_CInputManager_RemoveMouseListener01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OIS::MouseListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  OIS::MouseListener* MouseListener = ((OIS::MouseListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveMouseListener'", NULL);
#endif
  {
   self->RemoveMouseListener(MouseListener);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Core_Core_CInputManager_RemoveMouseListener00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveJoystickListener of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveJoystickListener01
static int tolua_Core_Core_CInputManager_RemoveJoystickListener01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"OIS::JoyStickListener",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  OIS::JoyStickListener* joystickListener = ((OIS::JoyStickListener*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveJoystickListener'", NULL);
#endif
  {
   self->RemoveJoystickListener(joystickListener);
  }
 }
 return 0;
tolua_lerror:
 return tolua_Core_Core_CInputManager_RemoveJoystickListener00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllListeners of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveAllListeners00
static int tolua_Core_Core_CInputManager_RemoveAllListeners00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllListeners'", NULL);
#endif
  {
   self->RemoveAllListeners();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllListeners'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllKeyListeners of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveAllKeyListeners00
static int tolua_Core_Core_CInputManager_RemoveAllKeyListeners00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllKeyListeners'", NULL);
#endif
  {
   self->RemoveAllKeyListeners();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllKeyListeners'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllMouseListeners of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveAllMouseListeners00
static int tolua_Core_Core_CInputManager_RemoveAllMouseListeners00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllMouseListeners'", NULL);
#endif
  {
   self->RemoveAllMouseListeners();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllMouseListeners'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllJoystickListeners of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_RemoveAllJoystickListeners00
static int tolua_Core_Core_CInputManager_RemoveAllJoystickListeners00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllJoystickListeners'", NULL);
#endif
  {
   self->RemoveAllJoystickListeners();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllJoystickListeners'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shutdown of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_Shutdown00
static int tolua_Core_Core_CInputManager_Shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shutdown'", NULL);
#endif
  {
   self->Shutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResizeWindow of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_ResizeWindow00
static int tolua_Core_Core_CInputManager_ResizeWindow00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RenderWindow",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  RenderWindow* rw = ((RenderWindow*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResizeWindow'", NULL);
#endif
  {
   self->ResizeWindow(rw);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResizeWindow'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetWindowExtents of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_SetWindowExtents00
static int tolua_Core_Core_CInputManager_SetWindowExtents00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  int Width = ((int)  tolua_tonumber(tolua_S,2,0));
  int Height = ((int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetWindowExtents'", NULL);
#endif
  {
   self->SetWindowExtents(Width,Height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetWindowExtents'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMouse of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_GetMouse00
static int tolua_Core_Core_CInputManager_GetMouse00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMouse'", NULL);
#endif
  {
   OIS::Mouse* tolua_ret = (OIS::Mouse*)  self->GetMouse();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OIS::Mouse");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMouse'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetKeyboard of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_GetKeyboard00
static int tolua_Core_Core_CInputManager_GetKeyboard00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetKeyboard'", NULL);
#endif
  {
   OIS::Keyboard* tolua_ret = (OIS::Keyboard*)  self->GetKeyboard();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OIS::Keyboard");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetKeyboard'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetJoystick of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_GetJoystick00
static int tolua_Core_Core_CInputManager_GetJoystick00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
  unsigned int Index = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetJoystick'", NULL);
#endif
  {
   OIS::JoyStick* tolua_ret = (OIS::JoyStick*)  self->GetJoystick(Index);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"OIS::JoyStick");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetJoystick'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetNumOfJoysticks of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CInputManager_GetNumOfJoysticks00
static int tolua_Core_Core_CInputManager_GetNumOfJoysticks00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CInputManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetNumOfJoysticks'", NULL);
#endif
  {
   unsigned int tolua_ret = (unsigned int)  self->GetNumOfJoysticks();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetNumOfJoysticks'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __OIS of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__CInputManager___OIS__MouseListener__
static int tolua_get_Core__CInputManager___OIS__MouseListener__(lua_State* tolua_S)
{
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__OIS'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<OIS::MouseListener*>(self), "OIS::MouseListener");
#else
   tolua_pushusertype(tolua_S,(void*)((OIS::MouseListener*)self), "OIS::MouseListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __OIS of class  Core::CInputManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__CInputManager___OIS__JoyStickListener__
static int tolua_get_Core__CInputManager___OIS__JoyStickListener__(lua_State* tolua_S)
{
  Core::CInputManager* self = (Core::CInputManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__OIS'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<OIS::JoyStickListener*>(self), "OIS::JoyStickListener");
#else
   tolua_pushusertype(tolua_S,(void*)((OIS::JoyStickListener*)self), "OIS::JoyStickListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CGameState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameState_Update00
static int tolua_Core_Core_CGameState_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameState",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameState* self = (Core::CGameState*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Load of class  Core::CGameState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameState_Load00
static int tolua_Core_Core_CGameState_Load00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameState* self = (Core::CGameState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Load'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Load();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Load'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: End of class  Core::CGameState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameState_End00
static int tolua_Core_Core_CGameState_End00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameState* self = (Core::CGameState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'End'", NULL);
#endif
  {
   self->End();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'End'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CGame */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGame_new00
static int tolua_Core_Core_CGame_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CGame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CGame* tolua_ret = (Core::CGame*)  Mtolua_new((Core::CGame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGame");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CGame */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGame_new00_local
static int tolua_Core_Core_CGame_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CGame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CGame* tolua_ret = (Core::CGame*)  Mtolua_new((Core::CGame)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGame");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CGame */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGame_delete00
static int tolua_Core_Core_CGame_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGame* self = (Core::CGame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Run of class  Core::CGame */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGame_Run00
static int tolua_Core_Core_CGame_Run00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGame",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGame* self = (Core::CGame*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Run'", NULL);
#endif
  {
   self->Run();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Run'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddGameState of class  Core::CGame */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGame_AddGameState00
static int tolua_Core_Core_CGame_AddGameState00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGame",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CGameState",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGame* self = (Core::CGame*)  tolua_tousertype(tolua_S,1,0);
  Core::CGameState* GameState = ((Core::CGameState*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddGameState'", NULL);
#endif
  {
   self->AddGameState(GameState);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddGameState'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_Instance00
static int tolua_Core_Core_CGameObjectManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CGameObjectManager* tolua_ret = (Core::CGameObjectManager*)  Core::CGameObjectManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObjectManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_delete00
static int tolua_Core_Core_CGameObjectManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateObject of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_CreateObject00
static int tolua_Core_Core_CGameObjectManager_CreateObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* GameObjectType = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateObject'", NULL);
#endif
  {
   Core::CGameObject* tolua_ret = (Core::CGameObject*)  self->CreateObject(GameObjectType);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateObject of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_CreateObject01
static int tolua_Core_Core_CGameObjectManager_CreateObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* GameObjectType = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* Name = ((const char*)  tolua_tostring(tolua_S,3,0));
  Vector3* Pos = ((Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateObject'", NULL);
#endif
  {
   Core::CGameObject* tolua_ret = (Core::CGameObject*)  self->CreateObject(GameObjectType,Name,*Pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObject");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_CGameObjectManager_CreateObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateCustomObject of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_CreateCustomObject00
static int tolua_Core_Core_CGameObjectManager_CreateCustomObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* MeshName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateCustomObject'", NULL);
#endif
  {
   Core::CGameObject* tolua_ret = (Core::CGameObject*)  self->CreateCustomObject(MeshName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateCustomObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateCustomObject of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_CreateCustomObject01
static int tolua_Core_Core_CGameObjectManager_CreateCustomObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* MeshName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* Name = ((const char*)  tolua_tostring(tolua_S,3,0));
  Vector3* Pos = ((Vector3*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateCustomObject'", NULL);
#endif
  {
   Core::CGameObject* tolua_ret = (Core::CGameObject*)  self->CreateCustomObject(MeshName,Name,*Pos);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObject");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_CGameObjectManager_CreateCustomObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGameObject of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetGameObject00
static int tolua_Core_Core_CGameObjectManager_GetGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Entity",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Entity* entity = ((Entity*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGameObject'", NULL);
#endif
  {
   Core::CGameObject* tolua_ret = (Core::CGameObject*)  self->GetGameObject(entity);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGameObject of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetGameObject01
static int tolua_Core_Core_CGameObjectManager_GetGameObject01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGameObject'", NULL);
#endif
  {
   Core::CGameObject* tolua_ret = (Core::CGameObject*)  self->GetGameObject(Name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObject");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_CGameObjectManager_GetGameObject00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGameObjectByEntityName of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetGameObjectByEntityName00
static int tolua_Core_Core_CGameObjectManager_GetGameObjectByEntityName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGameObjectByEntityName'", NULL);
#endif
  {
   Core::CGameObject* tolua_ret = (Core::CGameObject*)  self->GetGameObjectByEntityName(Name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CGameObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGameObjectByEntityName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetGameObjectUpdatable of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_SetGameObjectUpdatable00
static int tolua_Core_Core_CGameObjectManager_SetGameObjectUpdatable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CGameObject* GameObject = ((Core::CGameObject*)  tolua_tousertype(tolua_S,2,0));
  bool Value = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetGameObjectUpdatable'", NULL);
#endif
  {
   self->SetGameObjectUpdatable(GameObject,Value);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetGameObjectUpdatable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGameObjects of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetGameObjects00
static int tolua_Core_Core_CGameObjectManager_GetGameObjects00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::CGameObject*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::CGameObject*>* GameObjects = ((Vector<Core::CGameObject*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGameObjects'", NULL);
#endif
  {
   self->GetGameObjects(*GameObjects);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGameObjects'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllObjectTypes of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetAllObjectTypes00
static int tolua_Core_Core_CGameObjectManager_GetAllObjectTypes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<const char*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<const char*>* ObjectTypes = ((Vector<const char*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllObjectTypes'", NULL);
#endif
  {
   self->GetAllObjectTypes(*ObjectTypes);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllObjectTypes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveGameObject of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_RemoveGameObject00
static int tolua_Core_Core_CGameObjectManager_RemoveGameObject00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CGameObject* GameObject = ((Core::CGameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveGameObject'", NULL);
#endif
  {
   self->RemoveGameObject(GameObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveGameObject'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreatePlayer of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_CreatePlayer00
static int tolua_Core_Core_CGameObjectManager_CreatePlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,1,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"Core::Physics::IPhysicsStrategy",1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Type = ((const char*)  tolua_tostring(tolua_S,2,0));
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,3,0));
  const char* LabelName = ((const char*)  tolua_tostring(tolua_S,4,""));
  Core::Physics::IPhysicsStrategy* PhysicsStrategy = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,5,nullptr));
  bool isPlayer = ((bool)  tolua_toboolean(tolua_S,6,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreatePlayer'", NULL);
#endif
  {
   Core::CPlayer* tolua_ret = (Core::CPlayer*)  self->CreatePlayer(Type,Team,LabelName,PhysicsStrategy,isPlayer);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreatePlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateCustomPlayer of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_CreateCustomPlayer00
static int tolua_Core_Core_CGameObjectManager_CreateCustomPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isstring(tolua_S,4,1,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"Core::Physics::IPhysicsStrategy",1,&tolua_err) ||
     !tolua_isboolean(tolua_S,6,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,3,0));
  const char* LabelName = ((const char*)  tolua_tostring(tolua_S,4,""));
  Core::Physics::IPhysicsStrategy* PhysicsStrategy = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,5,nullptr));
  bool isPlayer = ((bool)  tolua_toboolean(tolua_S,6,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateCustomPlayer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->CreateCustomPlayer(Player,Team,LabelName,PhysicsStrategy,isPlayer);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateCustomPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddCustomPlayer of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_AddCustomPlayer00
static int tolua_Core_Core_CGameObjectManager_AddCustomPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,3,0));
  bool isPlayer = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddCustomPlayer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddCustomPlayer(Player,Team,isPlayer);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddCustomPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemovePlayer of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_RemovePlayer00
static int tolua_Core_Core_CGameObjectManager_RemovePlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemovePlayer'", NULL);
#endif
  {
   self->RemovePlayer(Player);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemovePlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveAllPlayers of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_RemoveAllPlayers00
static int tolua_Core_Core_CGameObjectManager_RemoveAllPlayers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveAllPlayers'", NULL);
#endif
  {
   self->RemoveAllPlayers();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveAllPlayers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetTeam of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetTeam00
static int tolua_Core_Core_CGameObjectManager_GetTeam00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"std::vector<Core::CPlayer*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0));
  std::vector<Core::CPlayer*>* List = ((std::vector<Core::CPlayer*>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetTeam'", NULL);
#endif
  {
   self->GetTeam(Team,*List);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetTeam'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetAllPlayers of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetAllPlayers00
static int tolua_Core_Core_CGameObjectManager_GetAllPlayers00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::CPlayer*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::CPlayer*>* Players = ((Vector<Core::CPlayer*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetAllPlayers'", NULL);
#endif
  {
   self->GetAllPlayers(*Players);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetAllPlayers'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerTypes of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetPlayerTypes00
static int tolua_Core_Core_CGameObjectManager_GetPlayerTypes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<const char*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<const char*>* PlayerType = ((Vector<const char*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerTypes'", NULL);
#endif
  {
   self->GetPlayerTypes(*PlayerType);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerTypes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetHumanPlayer of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetHumanPlayer00
static int tolua_Core_Core_CGameObjectManager_GetHumanPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetHumanPlayer'", NULL);
#endif
  {
   Core::CPlayer* tolua_ret = (Core::CPlayer*)  self->GetHumanPlayer();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetHumanPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerByName of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetPlayerByName00
static int tolua_Core_Core_CGameObjectManager_GetPlayerByName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerByName'", NULL);
#endif
  {
   Core::CPlayer* tolua_ret = (Core::CPlayer*)  self->GetPlayerByName(Name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerByName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerByEntityName of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetPlayerByEntityName00
static int tolua_Core_Core_CGameObjectManager_GetPlayerByEntityName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const char* EntityName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerByEntityName'", NULL);
#endif
  {
   Core::CPlayer* tolua_ret = (Core::CPlayer*)  self->GetPlayerByEntityName(EntityName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerByEntityName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClosestVisibleEnemy of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetClosestVisibleEnemy00
static int tolua_Core_Core_CGameObjectManager_GetClosestVisibleEnemy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClosestVisibleEnemy'", NULL);
#endif
  {
   Core::CPlayer* tolua_ret = (Core::CPlayer*)  self->GetClosestVisibleEnemy(Player);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClosestVisibleEnemy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetClosestEnemy of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetClosestEnemy00
static int tolua_Core_Core_CGameObjectManager_GetClosestEnemy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetClosestEnemy'", NULL);
#endif
  {
   Core::CPlayer* tolua_ret = (Core::CPlayer*)  self->GetClosestEnemy(Player);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetClosestEnemy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHumanPlayer of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_SetHumanPlayer00
static int tolua_Core_Core_CGameObjectManager_SetHumanPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHumanPlayer'", NULL);
#endif
  {
   self->SetHumanPlayer(Player);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHumanPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_Update00
static int tolua_Core_Core_CGameObjectManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shutdown of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_Shutdown00
static int tolua_Core_Core_CGameObjectManager_Shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shutdown'", NULL);
#endif
  {
   self->Shutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Restart of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_Restart00
static int tolua_Core_Core_CGameObjectManager_Restart00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Restart'", NULL);
#endif
  {
   self->Restart();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Restart'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddSphereObstacle of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_AddSphereObstacle00
static int tolua_Core_Core_CGameObjectManager_AddSphereObstacle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CGameObject* GameObject = ((Core::CGameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddSphereObstacle'", NULL);
#endif
  {
   self->AddSphereObstacle(GameObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddSphereObstacle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddBoxObstacle of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_AddBoxObstacle00
static int tolua_Core_Core_CGameObjectManager_AddBoxObstacle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CGameObject* GameObject = ((Core::CGameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddBoxObstacle'", NULL);
#endif
  {
   self->AddBoxObstacle(GameObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddBoxObstacle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetObstacles of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetObstacles00
static int tolua_Core_Core_CGameObjectManager_GetObstacles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::AI::Obstacle*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::AI::Obstacle*>* list = ((Vector<Core::AI::Obstacle*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetObstacles'", NULL);
#endif
  {
   self->GetObstacles(*list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetObstacles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSphereObstacles of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetSphereObstacles00
static int tolua_Core_Core_CGameObjectManager_GetSphereObstacles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::AI::Obstacle*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::AI::Obstacle*>* list = ((Vector<Core::AI::Obstacle*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSphereObstacles'", NULL);
#endif
  {
   self->GetSphereObstacles(*list);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSphereObstacles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveObstacle of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_RemoveObstacle00
static int tolua_Core_Core_CGameObjectManager_RemoveObstacle00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CGameObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CGameObject* GameObject = ((Core::CGameObject*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveObstacle'", NULL);
#endif
  {
   self->RemoveObstacle(GameObject);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveObstacle'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddWall of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_AddWall00
static int tolua_Core_Core_CGameObjectManager_AddWall00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,4,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* From = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* To = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  bool LeftNormal = ((bool)  tolua_toboolean(tolua_S,4,false));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddWall'", NULL);
#endif
  {
   self->AddWall(*From,*To,LeftNormal);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddWall'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWalls of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_GetWalls00
static int tolua_Core_Core_CGameObjectManager_GetWalls00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::AI::Wall*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::AI::Wall*>* Walls = ((Vector<Core::AI::Wall*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWalls'", NULL);
#endif
  {
   self->GetWalls(*Walls);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWalls'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveWalls of class  Core::CGameObjectManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CGameObjectManager_RemoveWalls00
static int tolua_Core_Core_CGameObjectManager_RemoveWalls00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CGameObjectManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CGameObjectManager* self = (Core::CGameObjectManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveWalls'", NULL);
#endif
  {
   self->RemoveWalls();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveWalls'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_Instance00
static int tolua_Core_Core_CItemsManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CItemsManager* tolua_ret = (Core::CItemsManager*)  Core::CItemsManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CItemsManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_delete00
static int tolua_Core_Core_CItemsManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_Update00
static int tolua_Core_Core_CItemsManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Pickup of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_Pickup00
static int tolua_Core_Core_CItemsManager_Pickup00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* ItemName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Pickup'", NULL);
#endif
  {
   Core::IInventoryItem* tolua_ret = (Core::IInventoryItem*)  self->Pickup(ItemName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::IInventoryItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Pickup'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PickupUnplaced of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_PickupUnplaced00
static int tolua_Core_Core_CItemsManager_PickupUnplaced00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* ProfileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PickupUnplaced'", NULL);
#endif
  {
   Core::IInventoryItem* tolua_ret = (Core::IInventoryItem*)  self->PickupUnplaced(ProfileName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::IInventoryItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PickupUnplaced'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddProfile of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_AddProfile00
static int tolua_Core_Core_CItemsManager_AddProfile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CItemProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CItemProfile* Item = ((Core::CItemProfile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddProfile'", NULL);
#endif
  {
   self->AddProfile(Item);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddProfile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlaceItem of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_PlaceItem00
static int tolua_Core_Core_CItemsManager_PlaceItem00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"Core::Physics::IPhysicsStrategy",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* ProfileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  const Vector3* Position = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
  Core::Physics::IPhysicsStrategy* Physics = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,4,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlaceItem'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->PlaceItem(ProfileName,*Position,Physics);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlaceItem'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemProfiles of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_GetItemProfiles00
static int tolua_Core_Core_CItemsManager_GetItemProfiles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::CItemProfile*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::CItemProfile*>* List = ((Vector<Core::CItemProfile*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemProfiles'", NULL);
#endif
  {
   self->GetItemProfiles(*List);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemProfiles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetItemProfile of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_GetItemProfile00
static int tolua_Core_Core_CItemsManager_GetItemProfile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* ProfileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetItemProfile'", NULL);
#endif
  {
   Core::CItemProfile* tolua_ret = (Core::CItemProfile*)  self->GetItemProfile(ProfileName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CItemProfile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetItemProfile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlacedItems of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_GetPlacedItems00
static int tolua_Core_Core_CItemsManager_GetPlacedItems00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::IInventoryItem*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::IInventoryItem*>* List = ((Vector<Core::IInventoryItem*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlacedItems'", NULL);
#endif
  {
   self->GetPlacedItems(*List);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlacedItems'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shutdown of class  Core::CItemsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CItemsManager_Shutdown00
static int tolua_Core_Core_CItemsManager_Shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CItemsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CItemsManager* self = (Core::CItemsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shutdown'", NULL);
#endif
  {
   self->Shutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsProfile_new00
static int tolua_Core_Core_Physics_CPhysicsProfile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::CPhysicsProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::CPhysicsProfile* tolua_ret = (Core::Physics::CPhysicsProfile*)  Mtolua_new((Core::Physics::CPhysicsProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::CPhysicsProfile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsProfile_new00_local
static int tolua_Core_Core_Physics_CPhysicsProfile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::CPhysicsProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::CPhysicsProfile* tolua_ret = (Core::Physics::CPhysicsProfile*)  Mtolua_new((Core::Physics::CPhysicsProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::CPhysicsProfile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Shape of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_Shape
static int tolua_get_Core__Physics__CPhysicsProfile_Shape(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Shape'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GetShape());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Shape of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_Shape
static int tolua_set_Core__Physics__CPhysicsProfile_Shape(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Shape'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetShape(((Core::Physics::E_PHYSICS_SHAPE) (int)  tolua_tonumber(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BodyType of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_BodyType
static int tolua_get_Core__Physics__CPhysicsProfile_BodyType(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BodyType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GetBodyType());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: BodyType of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_BodyType
static int tolua_set_Core__Physics__CPhysicsProfile_BodyType(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BodyType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetBodyType(((Core::Physics::E_BODY_TYPE) (int)  tolua_tonumber(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Friction of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_Friction
static int tolua_get_Core__Physics__CPhysicsProfile_Friction(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Friction'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GetFriction());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Friction of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_Friction
static int tolua_set_Core__Physics__CPhysicsProfile_Friction(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Friction'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetFriction(((float)  tolua_tonumber(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Mass of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_Mass
static int tolua_get_Core__Physics__CPhysicsProfile_Mass(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mass'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GetMass());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Mass of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_Mass
static int tolua_set_Core__Physics__CPhysicsProfile_Mass(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Mass'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetMass(((float)  tolua_tonumber(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Density of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_Density
static int tolua_get_Core__Physics__CPhysicsProfile_Density(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Density'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GetDensity());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Density of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_Density
static int tolua_set_Core__Physics__CPhysicsProfile_Density(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Density'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDensity(((float)  tolua_tonumber(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Radius of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_Radius
static int tolua_get_Core__Physics__CPhysicsProfile_Radius(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Radius'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->GetRadius());
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Radius of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_Radius
static int tolua_set_Core__Physics__CPhysicsProfile_Radius(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Radius'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetRadius(((float)  tolua_tonumber(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Size of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_Size
static int tolua_get_Core__Physics__CPhysicsProfile_Size(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->GetSize(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Size of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_Size
static int tolua_set_Core__Physics__CPhysicsProfile_Size(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Size'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetSize(*((Vector3*)  tolua_tousertype(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Direction of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsProfile_Direction
static int tolua_get_Core__Physics__CPhysicsProfile_Direction(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Direction'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->GetDirection(),"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Direction of class  Core::Physics::CPhysicsProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__CPhysicsProfile_Direction
static int tolua_set_Core__Physics__CPhysicsProfile_Direction(lua_State* tolua_S)
{
  Core::Physics::CPhysicsProfile* self = (Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Direction'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SetDirection(*((Vector3*)  tolua_tousertype(tolua_S,2,0)))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::GUI::CGuiManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiManager_Instance00
static int tolua_Core_Core_GUI_CGuiManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::GUI::CGuiManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::GUI::CGuiManager* tolua_ret = (Core::GUI::CGuiManager*)  Core::GUI::CGuiManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::GUI::CGuiManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::GUI::CGuiManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiManager_delete00
static int tolua_Core_Core_GUI_CGuiManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiManager* self = (Core::GUI::CGuiManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStrategy of class  Core::GUI::CGuiManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiManager_GetStrategy00
static int tolua_Core_Core_GUI_CGuiManager_GetStrategy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiManager* self = (Core::GUI::CGuiManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStrategy'", NULL);
#endif
  {
   IGuiStrategy* tolua_ret = (IGuiStrategy*)  self->GetStrategy(Name);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"IGuiStrategy");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStrategy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteStrategy of class  Core::GUI::CGuiManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiManager_DeleteStrategy00
static int tolua_Core_Core_GUI_CGuiManager_DeleteStrategy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiManager* self = (Core::GUI::CGuiManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteStrategy'", NULL);
#endif
  {
   self->DeleteStrategy(Name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteStrategy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_new00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::GUI::CGuiStrategy_MyGui* tolua_ret = (Core::GUI::CGuiStrategy_MyGui*)  Mtolua_new((Core::GUI::CGuiStrategy_MyGui)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::GUI::CGuiStrategy_MyGui");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_new00_local
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::GUI::CGuiStrategy_MyGui* tolua_ret = (Core::GUI::CGuiStrategy_MyGui*)  Mtolua_new((Core::GUI::CGuiStrategy_MyGui)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::GUI::CGuiStrategy_MyGui");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_delete00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Initialize of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_Initialize00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_Initialize00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Initialize'", NULL);
#endif
  {
   self->Initialize();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Initialize'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shutdown of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_Shutdown00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_Shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shutdown'", NULL);
#endif
  {
   self->Shutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Activate of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_Activate00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_Activate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Activate'", NULL);
#endif
  {
   self->Activate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Activate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Desactivate of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_Desactivate00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_Desactivate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Desactivate'", NULL);
#endif
  {
   self->Desactivate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Desactivate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCursorPosition of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_SetCursorPosition00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_SetCursorPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  float x = ((float)  tolua_tonumber(tolua_S,2,0));
  float y = ((float)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCursorPosition'", NULL);
#endif
  {
   self->SetCursorPosition(x,y);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCursorPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: LoadLayout of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_LoadLayout00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_LoadLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  const char* Name = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'LoadLayout'", NULL);
#endif
  {
   self->LoadLayout(Name);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'LoadLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FrameStarted of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_FrameStarted00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_FrameStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  float LastTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FrameStarted'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->FrameStarted(LastTime);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FrameStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FrameEnded of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_FrameEnded00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_FrameEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  float LastTime = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FrameEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->FrameEnded(LastTime);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FrameEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MouseMoved of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_MouseMoved00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_MouseMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::MouseEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  const OIS::MouseEvent* arg = ((const OIS::MouseEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MouseMoved'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->MouseMoved(*arg);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MouseMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MousePressed of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_MousePressed00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_MousePressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::MouseEvent",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"OIS::MouseButtonID",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  const OIS::MouseEvent* arg = ((const OIS::MouseEvent*)  tolua_tousertype(tolua_S,2,0));
  OIS::MouseButtonID id = *((OIS::MouseButtonID*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MousePressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->MousePressed(*arg,id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MousePressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: MouseReleased of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_MouseReleased00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_MouseReleased00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::MouseEvent",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"OIS::MouseButtonID",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  const OIS::MouseEvent* arg = ((const OIS::MouseEvent*)  tolua_tousertype(tolua_S,2,0));
  OIS::MouseButtonID id = *((OIS::MouseButtonID*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'MouseReleased'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->MouseReleased(*arg,id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'MouseReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: KeyPressed of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_KeyPressed00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_KeyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::KeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  const OIS::KeyEvent* arg = ((const OIS::KeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KeyPressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->KeyPressed(*arg);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: KeyReleased of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_KeyReleased00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_KeyReleased00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::KeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
  const OIS::KeyEvent* arg = ((const OIS::KeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'KeyReleased'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->KeyReleased(*arg);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'KeyReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStrategyType of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetStrategyType00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetStrategyType00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStrategyType'", NULL);
#endif
  {
   E_GUI_STRATEGY tolua_ret = (E_GUI_STRATEGY)  self->GetStrategyType();
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((E_GUI_STRATEGY)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"E_GUI_STRATEGY");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(E_GUI_STRATEGY));
     tolua_pushusertype(tolua_S,tolua_obj,"E_GUI_STRATEGY");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStrategyType'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetGui of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetGui00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetGui00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetGui'", NULL);
#endif
  {
   MyGUI::Gui* tolua_ret = (MyGUI::Gui*)  self->GetGui();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"MyGUI::Gui");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetGui'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetBaseLayout of class  Core::GUI::CGuiStrategy_MyGui */
#ifndef TOLUA_DISABLE_tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetBaseLayout00
static int tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetBaseLayout00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::GUI::CGuiStrategy_MyGui",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::GUI::CGuiStrategy_MyGui* self = (Core::GUI::CGuiStrategy_MyGui*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetBaseLayout'", NULL);
#endif
  {
   Core::GUI::CBaseLayout_MyGui* tolua_ret = (Core::GUI::CBaseLayout_MyGui*)  self->GetBaseLayout();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::GUI::CBaseLayout_MyGui");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetBaseLayout'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_new00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::OgreSpecific::CLoadingScreen* tolua_ret = (Core::OgreSpecific::CLoadingScreen*)  Mtolua_new((Core::OgreSpecific::CLoadingScreen)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::CLoadingScreen");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_new00_local
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::OgreSpecific::CLoadingScreen* tolua_ret = (Core::OgreSpecific::CLoadingScreen*)  Mtolua_new((Core::OgreSpecific::CLoadingScreen)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::CLoadingScreen");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_delete00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Start of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_Start00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_Start00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"RenderWindow",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,4,1,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  RenderWindow* window = ((RenderWindow*)  tolua_tousertype(tolua_S,2,0));
  unsigned int numGroupsInit = ((unsigned int)  tolua_tonumber(tolua_S,3,1));
  unsigned int numGroupsLoad = ((unsigned int)  tolua_tonumber(tolua_S,4,1));
  float initProportion = ((float)  tolua_tonumber(tolua_S,5,0.70f));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Start'", NULL);
#endif
  {
   self->Start(window,numGroupsInit,numGroupsLoad,initProportion);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Start'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Finish of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_Finish00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_Finish00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Finish'", NULL);
#endif
  {
   self->Finish();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Finish'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resourceGroupScriptingStarted of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupScriptingStarted00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupScriptingStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* groupName = ((const String*)  tolua_tousertype(tolua_S,2,0));
  size_t scriptCount = *((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resourceGroupScriptingStarted'", NULL);
#endif
  {
   self->resourceGroupScriptingStarted(*groupName,scriptCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resourceGroupScriptingStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scriptParseStarted of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_scriptParseStarted00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_scriptParseStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* scriptName = ((const String*)  tolua_tousertype(tolua_S,2,0));
  bool skipThisScript = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scriptParseStarted'", NULL);
#endif
  {
   self->scriptParseStarted(*scriptName,skipThisScript);
   tolua_pushboolean(tolua_S,(bool)skipThisScript);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scriptParseStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: scriptParseEnded of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_scriptParseEnded00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_scriptParseEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isboolean(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* scriptName = ((const String*)  tolua_tousertype(tolua_S,2,0));
  bool skipped = ((bool)  tolua_toboolean(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'scriptParseEnded'", NULL);
#endif
  {
   self->scriptParseEnded(*scriptName,skipped);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'scriptParseEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resourceGroupScriptingEnded of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupScriptingEnded00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupScriptingEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* groupName = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resourceGroupScriptingEnded'", NULL);
#endif
  {
   self->resourceGroupScriptingEnded(*groupName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resourceGroupScriptingEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resourceGroupLoadStarted of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupLoadStarted00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupLoadStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"size_t",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* groupName = ((const String*)  tolua_tousertype(tolua_S,2,0));
  size_t resourceCount = *((size_t*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resourceGroupLoadStarted'", NULL);
#endif
  {
   self->resourceGroupLoadStarted(*groupName,resourceCount);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resourceGroupLoadStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resourceLoadStarted of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceLoadStarted00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceLoadStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ResourcePtr",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const ResourcePtr* resource = ((const ResourcePtr*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resourceLoadStarted'", NULL);
#endif
  {
   self->resourceLoadStarted(*resource);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resourceLoadStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resourceLoadEnded of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceLoadEnded00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceLoadEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resourceLoadEnded'", NULL);
#endif
  {
   self->resourceLoadEnded();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resourceLoadEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: worldGeometryStageStarted of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_worldGeometryStageStarted00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_worldGeometryStageStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* description = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'worldGeometryStageStarted'", NULL);
#endif
  {
   self->worldGeometryStageStarted(*description);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'worldGeometryStageStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: worldGeometryStageEnded of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_worldGeometryStageEnded00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_worldGeometryStageEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'worldGeometryStageEnded'", NULL);
#endif
  {
   self->worldGeometryStageEnded();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'worldGeometryStageEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: resourceGroupLoadEnded of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupLoadEnded00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupLoadEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* groupName = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'resourceGroupLoadEnded'", NULL);
#endif
  {
   self->resourceGroupLoadEnded(*groupName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'resourceGroupLoadEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResourceLoading of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_ResourceLoading00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_ResourceLoading00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,4,"Resource",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,5,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const String* group = ((const String*)  tolua_tousertype(tolua_S,3,0));
  Resource* resource = ((Resource*)  tolua_tousertype(tolua_S,4,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResourceLoading'", NULL);
#endif
  {
   DataStreamPtr tolua_ret = (DataStreamPtr)  self->ResourceLoading(*name,*group,resource);
   {
#ifdef __cplusplus
    void* tolua_obj = Mtolua_new((DataStreamPtr)(tolua_ret));
     tolua_pushusertype(tolua_S,tolua_obj,"DataStreamPtr");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#else
    void* tolua_obj = tolua_copy(tolua_S,(void*)&tolua_ret,sizeof(DataStreamPtr));
     tolua_pushusertype(tolua_S,tolua_obj,"DataStreamPtr");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
#endif
   }
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResourceLoading'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ResourceCollision of class  Core::OgreSpecific::CLoadingScreen */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CLoadingScreen_ResourceCollision00
static int tolua_Core_Core_OgreSpecific_CLoadingScreen_ResourceCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CLoadingScreen",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ResourcePtr",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"ResourceManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CLoadingScreen* self = (Core::OgreSpecific::CLoadingScreen*)  tolua_tousertype(tolua_S,1,0);
  ResourcePtr* resource = ((ResourcePtr*)  tolua_tousertype(tolua_S,2,0));
  ResourceManager* resourceManager = ((ResourceManager*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ResourceCollision'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->ResourceCollision(*resource,resourceManager);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ResourceCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_Instance00
static int tolua_Core_Core_CLuaConsole_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CLuaConsole* tolua_ret = (Core::CLuaConsole*)  Core::CLuaConsole::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CLuaConsole");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_delete00
static int tolua_Core_Core_CLuaConsole_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shutdown of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_Shutdown00
static int tolua_Core_Core_CLuaConsole_Shutdown00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shutdown'", NULL);
#endif
  {
   self->Shutdown();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shutdown'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetVisible of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_SetVisible00
static int tolua_Core_Core_CLuaConsole_SetVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
  bool fVisible = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetVisible'", NULL);
#endif
  {
   self->SetVisible(fVisible);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsVisible of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_IsVisible00
static int tolua_Core_Core_CLuaConsole_IsVisible00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsVisible'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsVisible();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsVisible'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Print of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_Print00
static int tolua_Core_Core_CLuaConsole_Print00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
  String text = *((String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Print'", NULL);
#endif
  {
   self->Print(text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Print'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnKeyPressed of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_OnKeyPressed00
static int tolua_Core_Core_CLuaConsole_OnKeyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::KeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
  const OIS::KeyEvent* evt = ((const OIS::KeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnKeyPressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->OnKeyPressed(*evt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnKeyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: frameStarted of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_frameStarted00
static int tolua_Core_Core_CLuaConsole_frameStarted00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::FrameEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::FrameEvent* evt = ((const Ogre::FrameEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'frameStarted'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->frameStarted(*evt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'frameStarted'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: frameEnded of class  Core::CLuaConsole */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CLuaConsole_frameEnded00
static int tolua_Core_Core_CLuaConsole_frameEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CLuaConsole",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Ogre::FrameEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CLuaConsole* self = (Core::CLuaConsole*)  tolua_tousertype(tolua_S,1,0);
  const Ogre::FrameEvent* evt = ((const Ogre::FrameEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'frameEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->frameEnded(*evt);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'frameEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_new00
static int tolua_Core_Core_CWeapon_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CWeaponProfile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::Physics::IPhysicsStrategy",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeaponProfile* Profile = ((Core::CWeaponProfile*)  tolua_tousertype(tolua_S,2,0));
  Core::Physics::IPhysicsStrategy* Physics = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,3,nullptr));
  {
   Core::CWeapon* tolua_ret = (Core::CWeapon*)  Mtolua_new((Core::CWeapon)(Profile,Physics));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CWeapon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_new00_local
static int tolua_Core_Core_CWeapon_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CWeaponProfile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::Physics::IPhysicsStrategy",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeaponProfile* Profile = ((Core::CWeaponProfile*)  tolua_tousertype(tolua_S,2,0));
  Core::Physics::IPhysicsStrategy* Physics = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,3,nullptr));
  {
   Core::CWeapon* tolua_ret = (Core::CWeapon*)  Mtolua_new((Core::CWeapon)(Profile,Physics));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CWeapon");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_delete00
static int tolua_Core_Core_CWeapon_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_Update00
static int tolua_Core_Core_CWeapon_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PickedUp of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_PickedUp00
static int tolua_Core_Core_CWeapon_PickedUp00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PickedUp'", NULL);
#endif
  {
   self->PickedUp(Player);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PickedUp'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ShowSight of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_ShowSight00
static int tolua_Core_Core_CWeapon_ShowSight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
  bool Show = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ShowSight'", NULL);
#endif
  {
   self->ShowSight(Show);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ShowSight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUsed of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_SetUsed00
static int tolua_Core_Core_CWeapon_SetUsed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
  bool Used = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUsed'", NULL);
#endif
  {
   self->SetUsed(Used);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUsed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Use of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_Use00
static int tolua_Core_Core_CWeapon_Use00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* Target = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Use'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Use(*Target);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Use'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetRange of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_GetRange00
static int tolua_Core_Core_CWeapon_GetRange00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetRange'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetRange();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetRange'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMagazine of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_GetMagazine00
static int tolua_Core_Core_CWeapon_GetMagazine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMagazine'", NULL);
#endif
  {
   Core::CMagazine* tolua_ret = (Core::CMagazine*)  self->GetMagazine();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CMagazine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMagazine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMagazine of class  Core::CWeapon */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeapon_SetMagazine00
static int tolua_Core_Core_CWeapon_SetMagazine00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CMagazine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeapon* self = (Core::CWeapon*)  tolua_tousertype(tolua_S,1,0);
  Core::CMagazine* m = ((Core::CMagazine*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMagazine'", NULL);
#endif
  {
   self->SetMagazine(m);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMagazine'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_new00
static int tolua_Core_Core_CProjectile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CProjectileProfile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectileProfile* Profile = ((Core::CProjectileProfile*)  tolua_tousertype(tolua_S,2,0));
  Core::CWeapon* Weapon = ((Core::CWeapon*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::CProjectile* tolua_ret = (Core::CProjectile*)  Mtolua_new((Core::CProjectile)(Profile,Weapon));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CProjectile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_new00_local
static int tolua_Core_Core_CProjectile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CProjectileProfile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectileProfile* Profile = ((Core::CProjectileProfile*)  tolua_tousertype(tolua_S,2,0));
  Core::CWeapon* Weapon = ((Core::CWeapon*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::CProjectile* tolua_ret = (Core::CProjectile*)  Mtolua_new((Core::CProjectile)(Profile,Weapon));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CProjectile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_delete00
static int tolua_Core_Core_CProjectile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Shoot of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_Shoot00
static int tolua_Core_Core_CProjectile_Shoot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* Direction = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Shoot'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Shoot(Player,*Direction);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Shoot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_Update00
static int tolua_Core_Core_CProjectile_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetDamage of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_GetDamage00
static int tolua_Core_Core_CProjectile_GetDamage00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetDamage'", NULL);
#endif
  {
   float tolua_ret = (float)  self->GetDamage();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetDamage'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetOwner of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_GetOwner00
static int tolua_Core_Core_CProjectile_GetOwner00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetOwner'", NULL);
#endif
  {
   Core::CPlayer* tolua_ret = (Core::CPlayer*)  self->GetOwner();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayer");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetOwner'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetWeapon of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectile_GetWeapon00
static int tolua_Core_Core_CProjectile_GetWeapon00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetWeapon'", NULL);
#endif
  {
   Core::CWeapon* tolua_ret = (Core::CWeapon*)  self->GetWeapon();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CWeapon");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetWeapon'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isAlive of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectile_isAlive
static int tolua_get_Core__CProjectile_isAlive(lua_State* tolua_S)
{
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAlive'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isAlive);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isAlive of class  Core::CProjectile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CProjectile_isAlive
static int tolua_set_Core__CProjectile_isAlive(lua_State* tolua_S)
{
  Core::CProjectile* self = (Core::CProjectile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAlive'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isAlive = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazineProfile_new00
static int tolua_Core_Core_CMagazineProfile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CMagazineProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CMagazineProfile* tolua_ret = (Core::CMagazineProfile*)  Mtolua_new((Core::CMagazineProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CMagazineProfile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazineProfile_new00_local
static int tolua_Core_Core_CMagazineProfile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CMagazineProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CMagazineProfile* tolua_ret = (Core::CMagazineProfile*)  Mtolua_new((Core::CMagazineProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CMagazineProfile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazineProfile_delete00
static int tolua_Core_Core_CMagazineProfile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMagazineProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMagazineProfile* self = (Core::CMagazineProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Capacity of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMagazineProfile_unsigned_Capacity
static int tolua_get_Core__CMagazineProfile_unsigned_Capacity(lua_State* tolua_S)
{
  Core::CMagazineProfile* self = (Core::CMagazineProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Capacity'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Capacity);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Capacity of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CMagazineProfile_unsigned_Capacity
static int tolua_set_Core__CMagazineProfile_unsigned_Capacity(lua_State* tolua_S)
{
  Core::CMagazineProfile* self = (Core::CMagazineProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Capacity'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Capacity = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Desc of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMagazineProfile_Desc
static int tolua_get_Core__CMagazineProfile_Desc(lua_State* tolua_S)
{
  Core::CMagazineProfile* self = (Core::CMagazineProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Desc'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->Desc);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MeshName of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMagazineProfile_MeshName
static int tolua_get_Core__CMagazineProfile_MeshName(lua_State* tolua_S)
{
  Core::CMagazineProfile* self = (Core::CMagazineProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MeshName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->MeshName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ProjectileProfile of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMagazineProfile_ProjectileProfile_ptr
static int tolua_get_Core__CMagazineProfile_ProjectileProfile_ptr(lua_State* tolua_S)
{
  Core::CMagazineProfile* self = (Core::CMagazineProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ProjectileProfile'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->ProjectileProfile,"Core::CProjectileProfile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ProjectileProfile of class  Core::CMagazineProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CMagazineProfile_ProjectileProfile_ptr
static int tolua_set_Core__CMagazineProfile_ProjectileProfile_ptr(lua_State* tolua_S)
{
  Core::CMagazineProfile* self = (Core::CMagazineProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ProjectileProfile'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CProjectileProfile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ProjectileProfile = ((Core::CProjectileProfile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CMagazine */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazine_new00
static int tolua_Core_Core_CMagazine_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CMagazine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CMagazineProfile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMagazineProfile* Profile = ((Core::CMagazineProfile*)  tolua_tousertype(tolua_S,2,0));
  Core::CWeapon* Weapon = ((Core::CWeapon*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::CMagazine* tolua_ret = (Core::CMagazine*)  Mtolua_new((Core::CMagazine)(Profile,Weapon));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CMagazine");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CMagazine */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazine_new00_local
static int tolua_Core_Core_CMagazine_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CMagazine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CMagazineProfile",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CWeapon",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMagazineProfile* Profile = ((Core::CMagazineProfile*)  tolua_tousertype(tolua_S,2,0));
  Core::CWeapon* Weapon = ((Core::CWeapon*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::CMagazine* tolua_ret = (Core::CMagazine*)  Mtolua_new((Core::CMagazine)(Profile,Weapon));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CMagazine");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CMagazine */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazine_delete00
static int tolua_Core_Core_CMagazine_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMagazine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMagazine* self = (Core::CMagazine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Fire of class  Core::CMagazine */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazine_Fire00
static int tolua_Core_Core_CMagazine_Fire00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMagazine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMagazine* self = (Core::CMagazine*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
  const Vector3* Direction = ((const Vector3*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Fire'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->Fire(Player,*Direction);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Fire'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveProjectile of class  Core::CMagazine */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazine_RemoveProjectile00
static int tolua_Core_Core_CMagazine_RemoveProjectile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMagazine",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CProjectile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMagazine* self = (Core::CMagazine*)  tolua_tousertype(tolua_S,1,0);
  Core::CProjectile* Projectile = ((Core::CProjectile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveProjectile'", NULL);
#endif
  {
   self->RemoveProjectile(Projectile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveProjectile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProjectiles of class  Core::CMagazine */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMagazine_GetProjectiles00
static int tolua_Core_Core_CMagazine_GetProjectiles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMagazine",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMagazine* self = (Core::CMagazine*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProjectiles'", NULL);
#endif
  {
   Vector<Core::CProjectile*>& tolua_ret = (Vector<Core::CProjectile*>&)  self->GetProjectiles();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"Vector<Core::CProjectile*>");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProjectiles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectileProfile_new00
static int tolua_Core_Core_CProjectileProfile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CProjectileProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CProjectileProfile* tolua_ret = (Core::CProjectileProfile*)  Mtolua_new((Core::CProjectileProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CProjectileProfile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectileProfile_new00_local
static int tolua_Core_Core_CProjectileProfile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CProjectileProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CProjectileProfile* tolua_ret = (Core::CProjectileProfile*)  Mtolua_new((Core::CProjectileProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CProjectileProfile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CProjectileProfile_delete00
static int tolua_Core_Core_CProjectileProfile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CProjectileProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Damage of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectileProfile_Damage
static int tolua_get_Core__CProjectileProfile_Damage(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Damage'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Damage);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Damage of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CProjectileProfile_Damage
static int tolua_set_Core__CProjectileProfile_Damage(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Damage'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Damage = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Speed of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectileProfile_Speed
static int tolua_get_Core__CProjectileProfile_Speed(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Speed'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Speed);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Speed of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CProjectileProfile_Speed
static int tolua_set_Core__CProjectileProfile_Speed(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Speed'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Speed = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Disc of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectileProfile_Disc
static int tolua_get_Core__CProjectileProfile_Disc(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Disc'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->Disc);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MeshName of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectileProfile_MeshName
static int tolua_get_Core__CProjectileProfile_MeshName(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MeshName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->MeshName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BillboardBullet of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectileProfile_BillboardBullet
static int tolua_get_Core__CProjectileProfile_BillboardBullet(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BillboardBullet'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->BillboardBullet);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BillboardFlash of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectileProfile_BillboardFlash
static int tolua_get_Core__CProjectileProfile_BillboardFlash(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BillboardFlash'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->BillboardFlash);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isPenetrate of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CProjectileProfile_isPenetrate
static int tolua_get_Core__CProjectileProfile_isPenetrate(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isPenetrate'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isPenetrate);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isPenetrate of class  Core::CProjectileProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CProjectileProfile_isPenetrate
static int tolua_set_Core__CProjectileProfile_isPenetrate(lua_State* tolua_S)
{
  Core::CProjectileProfile* self = (Core::CProjectileProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isPenetrate'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isPenetrate = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: keyPressed of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMenuState_keyPressed00
static int tolua_Core_Core_CMenuState_keyPressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMenuState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::KeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
  const OIS::KeyEvent* e = ((const OIS::KeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'keyPressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->keyPressed(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keyPressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: keyReleased of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMenuState_keyReleased00
static int tolua_Core_Core_CMenuState_keyReleased00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMenuState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::KeyEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
  const OIS::KeyEvent* e = ((const OIS::KeyEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'keyReleased'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->keyReleased(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'keyReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mouseMoved of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMenuState_mouseMoved00
static int tolua_Core_Core_CMenuState_mouseMoved00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMenuState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::MouseEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
  const OIS::MouseEvent* e = ((const OIS::MouseEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mouseMoved'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->mouseMoved(*e);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mouseMoved'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mousePressed of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMenuState_mousePressed00
static int tolua_Core_Core_CMenuState_mousePressed00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMenuState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::MouseEvent",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"OIS::MouseButtonID",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
  const OIS::MouseEvent* e = ((const OIS::MouseEvent*)  tolua_tousertype(tolua_S,2,0));
  OIS::MouseButtonID id = *((OIS::MouseButtonID*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mousePressed'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->mousePressed(*e,id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mousePressed'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: mouseReleased of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMenuState_mouseReleased00
static int tolua_Core_Core_CMenuState_mouseReleased00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMenuState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const OIS::MouseEvent",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"OIS::MouseButtonID",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
  const OIS::MouseEvent* e = ((const OIS::MouseEvent*)  tolua_tousertype(tolua_S,2,0));
  OIS::MouseButtonID id = *((OIS::MouseButtonID*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'mouseReleased'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->mouseReleased(*e,id);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'mouseReleased'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: frameRenderingQueued of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMenuState_frameRenderingQueued00
static int tolua_Core_Core_CMenuState_frameRenderingQueued00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMenuState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const FrameEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
  const FrameEvent* Event = ((const FrameEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'frameRenderingQueued'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->frameRenderingQueued(*Event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'frameRenderingQueued'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: frameEnded of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CMenuState_frameEnded00
static int tolua_Core_Core_CMenuState_frameEnded00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CMenuState",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const FrameEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
  const FrameEvent* Event = ((const FrameEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'frameEnded'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->frameEnded(*Event);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'frameEnded'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __FrameListener__ of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMenuState___FrameListener__
static int tolua_get_Core__CMenuState___FrameListener__(lua_State* tolua_S)
{
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__FrameListener__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<FrameListener*>(self), "FrameListener");
#else
   tolua_pushusertype(tolua_S,(void*)((FrameListener*)self), "FrameListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __WindowEventListener__ of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMenuState___WindowEventListener__
static int tolua_get_Core__CMenuState___WindowEventListener__(lua_State* tolua_S)
{
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__WindowEventListener__'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<WindowEventListener*>(self), "WindowEventListener");
#else
   tolua_pushusertype(tolua_S,(void*)((WindowEventListener*)self), "WindowEventListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __OIS of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMenuState___OIS__MouseListener__
static int tolua_get_Core__CMenuState___OIS__MouseListener__(lua_State* tolua_S)
{
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__OIS'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<OIS::MouseListener*>(self), "OIS::MouseListener");
#else
   tolua_pushusertype(tolua_S,(void*)((OIS::MouseListener*)self), "OIS::MouseListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: __OIS of class  Core::CMenuState */
#ifndef TOLUA_DISABLE_tolua_get_Core__CMenuState___OIS__KeyListener__
static int tolua_get_Core__CMenuState___OIS__KeyListener__(lua_State* tolua_S)
{
  Core::CMenuState* self = (Core::CMenuState*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable '__OIS'",NULL);
#endif
#ifdef __cplusplus
   tolua_pushusertype(tolua_S,(void*)static_cast<OIS::KeyListener*>(self), "OIS::KeyListener");
#else
   tolua_pushusertype(tolua_S,(void*)((OIS::KeyListener*)self), "OIS::KeyListener");
#endif
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionEvent_new00
static int tolua_Core_Core_Mission_CMissionEvent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Mission::CMissionEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Mission::CMissionEvent* tolua_ret = (Core::Mission::CMissionEvent*)  Mtolua_new((Core::Mission::CMissionEvent)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Mission::CMissionEvent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionEvent_new00_local
static int tolua_Core_Core_Mission_CMissionEvent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Mission::CMissionEvent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Mission::CMissionEvent* tolua_ret = (Core::Mission::CMissionEvent*)  Mtolua_new((Core::Mission::CMissionEvent)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Mission::CMissionEvent");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Owner of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_get_Core__Mission__CMissionEvent_Owner_ptr
static int tolua_get_Core__Mission__CMissionEvent_Owner_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Owner'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Owner,"Core::CPlayer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Owner of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_set_Core__Mission__CMissionEvent_Owner_ptr
static int tolua_set_Core__Mission__CMissionEvent_Owner_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Owner'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Owner = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Killed of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_get_Core__Mission__CMissionEvent_Killed_ptr
static int tolua_get_Core__Mission__CMissionEvent_Killed_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Killed'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Killed,"Core::CPlayer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Killed of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_set_Core__Mission__CMissionEvent_Killed_ptr
static int tolua_set_Core__Mission__CMissionEvent_Killed_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Killed'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Killed = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Weapon of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_get_Core__Mission__CMissionEvent_Weapon_ptr
static int tolua_get_Core__Mission__CMissionEvent_Weapon_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Weapon'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Weapon,"Core::CWeapon");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Weapon of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_set_Core__Mission__CMissionEvent_Weapon_ptr
static int tolua_set_Core__Mission__CMissionEvent_Weapon_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Weapon'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CWeapon",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Weapon = ((Core::CWeapon*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Projectile of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_get_Core__Mission__CMissionEvent_Projectile_ptr
static int tolua_get_Core__Mission__CMissionEvent_Projectile_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Projectile'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Projectile,"Core::CProjectile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Projectile of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_set_Core__Mission__CMissionEvent_Projectile_ptr
static int tolua_set_Core__Mission__CMissionEvent_Projectile_ptr(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Projectile'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CProjectile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Projectile = ((Core::CProjectile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: UserData of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_get_Core__Mission__CMissionEvent_UserData
static int tolua_get_Core__Mission__CMissionEvent_UserData(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UserData'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->UserData);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: UserData of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_set_Core__Mission__CMissionEvent_UserData
static int tolua_set_Core__Mission__CMissionEvent_UserData(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'UserData'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->UserData = ((void*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MissionType of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_get_Core__Mission__CMissionEvent_MissionType
static int tolua_get_Core__Mission__CMissionEvent_MissionType(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MissionType'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->MissionType,"MISSION_TYPE");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MissionType of class  Core::Mission::CMissionEvent */
#ifndef TOLUA_DISABLE_tolua_set_Core__Mission__CMissionEvent_MissionType
static int tolua_set_Core__Mission__CMissionEvent_MissionType(lua_State* tolua_S)
{
  Core::Mission::CMissionEvent* self = (Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MissionType'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"MISSION_TYPE",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MissionType = *((MISSION_TYPE*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::Mission::CMissionManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionManager_Instance00
static int tolua_Core_Core_Mission_CMissionManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Mission::CMissionManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Mission::CMissionManager* tolua_ret = (Core::Mission::CMissionManager*)  Core::Mission::CMissionManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Mission::CMissionManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Mission::CMissionManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionManager_delete00
static int tolua_Core_Core_Mission_CMissionManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Mission::CMissionManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Mission::CMissionManager* self = (Core::Mission::CMissionManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartMission of class  Core::Mission::CMissionManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionManager_StartMission00
static int tolua_Core_Core_Mission_CMissionManager_StartMission00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Mission::CMissionManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Mission::CMissionManager* self = (Core::Mission::CMissionManager*)  tolua_tousertype(tolua_S,1,0);
  const char* MissionLabel = ((const char*)  tolua_tostring(tolua_S,2,0));
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartMission'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->StartMission(MissionLabel,Player);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartMission'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: ListAllAvailableMissions of class  Core::Mission::CMissionManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionManager_ListAllAvailableMissions00
static int tolua_Core_Core_Mission_CMissionManager_ListAllAvailableMissions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Mission::CMissionManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<String>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Mission::CMissionManager* self = (Core::Mission::CMissionManager*)  tolua_tousertype(tolua_S,1,0);
  Vector<String>* List = ((Vector<String>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'ListAllAvailableMissions'", NULL);
#endif
  {
   self->ListAllAvailableMissions(*List);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'ListAllAvailableMissions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: FindActivePlayerMissions of class  Core::Mission::CMissionManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionManager_FindActivePlayerMissions00
static int tolua_Core_Core_Mission_CMissionManager_FindActivePlayerMissions00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Mission::CMissionManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector<Core::Mission::IMission*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Mission::CMissionManager* self = (Core::Mission::CMissionManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
  Vector<Core::Mission::IMission*>* Missions = ((Vector<Core::Mission::IMission*>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'FindActivePlayerMissions'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->FindActivePlayerMissions(Player,*Missions);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'FindActivePlayerMissions'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::Mission::CMissionManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionManager_Update00
static int tolua_Core_Core_Mission_CMissionManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Mission::CMissionManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Mission::CMissionManager* self = (Core::Mission::CMissionManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RegisterEvent of class  Core::Mission::CMissionManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Mission_CMissionManager_RegisterEvent00
static int tolua_Core_Core_Mission_CMissionManager_RegisterEvent00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Mission::CMissionManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Core::Mission::CMissionEvent",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Mission::CMissionManager* self = (Core::Mission::CMissionManager*)  tolua_tousertype(tolua_S,1,0);
  const Core::Mission::CMissionEvent* Event = ((const Core::Mission::CMissionEvent*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RegisterEvent'", NULL);
#endif
  {
   self->RegisterEvent(*Event);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RegisterEvent'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CoreEntityObject_new00
static int tolua_Core_Core_CoreEntityObject_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CoreEntityObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CoreEntityObject* tolua_ret = (Core::CoreEntityObject*)  Mtolua_new((Core::CoreEntityObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CoreEntityObject");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CoreEntityObject_new00_local
static int tolua_Core_Core_CoreEntityObject_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CoreEntityObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CoreEntityObject* tolua_ret = (Core::CoreEntityObject*)  Mtolua_new((Core::CoreEntityObject)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CoreEntityObject");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: QueryType of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CoreEntityObject_QueryType
static int tolua_get_Core__CoreEntityObject_QueryType(lua_State* tolua_S)
{
  Core::CoreEntityObject* self = (Core::CoreEntityObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'QueryType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->QueryType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: QueryType of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CoreEntityObject_QueryType
static int tolua_set_Core__CoreEntityObject_QueryType(lua_State* tolua_S)
{
  Core::CoreEntityObject* self = (Core::CoreEntityObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'QueryType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->QueryType = ((Core::SCENE_QUERY_FLAGS) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Player of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CoreEntityObject_Player_ptr
static int tolua_get_Core__CoreEntityObject_Player_ptr(lua_State* tolua_S)
{
  Core::CoreEntityObject* self = (Core::CoreEntityObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Player'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Player,"Core::CPlayer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Player of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CoreEntityObject_Player_ptr
static int tolua_set_Core__CoreEntityObject_Player_ptr(lua_State* tolua_S)
{
  Core::CoreEntityObject* self = (Core::CoreEntityObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Player'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Item of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_get_Core__CoreEntityObject_Item_ptr
static int tolua_get_Core__CoreEntityObject_Item_ptr(lua_State* tolua_S)
{
  Core::CoreEntityObject* self = (Core::CoreEntityObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Item'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Item,"Core::IInventoryItem");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Item of class  Core::CoreEntityObject */
#ifndef TOLUA_DISABLE_tolua_set_Core__CoreEntityObject_Item_ptr
static int tolua_set_Core__CoreEntityObject_Item_ptr(lua_State* tolua_S)
{
  Core::CoreEntityObject* self = (Core::CoreEntityObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Item'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::IInventoryItem",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Item = ((Core::IInventoryItem*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Name of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_get_Core__SPAWN_POINT_Name
static int tolua_get_Core__SPAWN_POINT_Name(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Name'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Name,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Name of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_set_Core__SPAWN_POINT_Name
static int tolua_set_Core__SPAWN_POINT_Name(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Name'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Name = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Team of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_get_Core__SPAWN_POINT_Team
static int tolua_get_Core__SPAWN_POINT_Team(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Team'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Team);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Team of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_set_Core__SPAWN_POINT_Team
static int tolua_set_Core__SPAWN_POINT_Team(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Team'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Position of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_get_Core__SPAWN_POINT_Position
static int tolua_get_Core__SPAWN_POINT_Position(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Position,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Position of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_set_Core__SPAWN_POINT_Position
static int tolua_set_Core__SPAWN_POINT_Position(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Position = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Priority of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_get_Core__SPAWN_POINT_Priority
static int tolua_get_Core__SPAWN_POINT_Priority(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Priority'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Priority);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Priority of class  Core::SPAWN_POINT */
#ifndef TOLUA_DISABLE_tolua_set_Core__SPAWN_POINT_Priority
static int tolua_set_Core__SPAWN_POINT_Priority(lua_State* tolua_S)
{
  Core::SPAWN_POINT* self = (Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Priority'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Priority = ((Core::SPAWN_POINT_PRIORITY) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_Instance00
static int tolua_Core_Core_Physics_CPhysicsManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::CPhysicsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::CPhysicsManager* tolua_ret = (Core::Physics::CPhysicsManager*)  Core::Physics::CPhysicsManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::CPhysicsManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: CreateStrategy of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_CreateStrategy00
static int tolua_Core_Core_Physics_CPhysicsManager_CreateStrategy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Physics::CPhysicsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Physics::CPhysicsManager* self = (Core::Physics::CPhysicsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* Label = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'CreateStrategy'", NULL);
#endif
  {
   Core::Physics::IPhysicsStrategy* tolua_ret = (Core::Physics::IPhysicsStrategy*)  self->CreateStrategy(Label);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::IPhysicsStrategy");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'CreateStrategy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetStrategy of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_GetStrategy00
static int tolua_Core_Core_Physics_CPhysicsManager_GetStrategy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::Physics::CPhysicsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::Physics::CPhysicsManager* self = (const Core::Physics::CPhysicsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetStrategy'", NULL);
#endif
  {
   Core::Physics::IPhysicsStrategy* tolua_ret = (Core::Physics::IPhysicsStrategy*)  self->GetStrategy();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::IPhysicsStrategy");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetStrategy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: DeleteStrategy of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_DeleteStrategy00
static int tolua_Core_Core_Physics_CPhysicsManager_DeleteStrategy00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Physics::CPhysicsManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Physics::CPhysicsManager* self = (Core::Physics::CPhysicsManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'DeleteStrategy'", NULL);
#endif
  {
   self->DeleteStrategy();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'DeleteStrategy'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddPhysicsProfile of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_AddPhysicsProfile00
static int tolua_Core_Core_Physics_CPhysicsManager_AddPhysicsProfile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Physics::CPhysicsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::Physics::CPhysicsProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Physics::CPhysicsManager* self = (Core::Physics::CPhysicsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* ProfileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  Core::Physics::CPhysicsProfile* Profile = ((Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddPhysicsProfile'", NULL);
#endif
  {
   self->AddPhysicsProfile(ProfileName,Profile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddPhysicsProfile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicsProfileList of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_GetPhysicsProfileList00
static int tolua_Core_Core_Physics_CPhysicsManager_GetPhysicsProfileList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::Physics::CPhysicsManager",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"PhysicsProfileList",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::Physics::CPhysicsManager* self = (const Core::Physics::CPhysicsManager*)  tolua_tousertype(tolua_S,1,0);
  PhysicsProfileList* ProfileList = ((PhysicsProfileList*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicsProfileList'", NULL);
#endif
  {
   self->GetPhysicsProfileList(*ProfileList);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicsProfileList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPhysicsProfile of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_GetPhysicsProfile00
static int tolua_Core_Core_Physics_CPhysicsManager_GetPhysicsProfile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::Physics::CPhysicsManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::Physics::CPhysicsManager* self = (const Core::Physics::CPhysicsManager*)  tolua_tousertype(tolua_S,1,0);
  const char* ProfileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPhysicsProfile'", NULL);
#endif
  {
   Core::Physics::CPhysicsProfile* tolua_ret = (Core::Physics::CPhysicsProfile*)  self->GetPhysicsProfile(ProfileName);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::CPhysicsProfile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPhysicsProfile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CPhysicsManager_Update00
static int tolua_Core_Core_Physics_CPhysicsManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::Physics::CPhysicsManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::Physics::CPhysicsManager* self = (const Core::Physics::CPhysicsManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_LIGHT_CUBE of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsManager_DEFAULT_LIGHT_CUBE
static int tolua_get_Core__Physics__CPhysicsManager_DEFAULT_LIGHT_CUBE(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)Core::Physics::CPhysicsManager::DEFAULT_LIGHT_CUBE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_MEDIUM_CUBE of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsManager_DEFAULT_MEDIUM_CUBE
static int tolua_get_Core__Physics__CPhysicsManager_DEFAULT_MEDIUM_CUBE(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)Core::Physics::CPhysicsManager::DEFAULT_MEDIUM_CUBE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_HEAVY_CUBE of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsManager_DEFAULT_HEAVY_CUBE
static int tolua_get_Core__Physics__CPhysicsManager_DEFAULT_HEAVY_CUBE(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)Core::Physics::CPhysicsManager::DEFAULT_HEAVY_CUBE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_LIGHT_SPHERE of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsManager_DEFAULT_LIGHT_SPHERE
static int tolua_get_Core__Physics__CPhysicsManager_DEFAULT_LIGHT_SPHERE(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)Core::Physics::CPhysicsManager::DEFAULT_LIGHT_SPHERE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_MEDIUM_SPHERE of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsManager_DEFAULT_MEDIUM_SPHERE
static int tolua_get_Core__Physics__CPhysicsManager_DEFAULT_MEDIUM_SPHERE(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)Core::Physics::CPhysicsManager::DEFAULT_MEDIUM_SPHERE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: DEFAULT_HEAVY_SPHERE of class  Core::Physics::CPhysicsManager */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__CPhysicsManager_DEFAULT_HEAVY_SPHERE
static int tolua_get_Core__Physics__CPhysicsManager_DEFAULT_HEAVY_SPHERE(lua_State* tolua_S)
{
  tolua_pushstring(tolua_S,(const char*)Core::Physics::CPhysicsManager::DEFAULT_HEAVY_SPHERE);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_new00
static int tolua_Core_Core_CPlayerSoundComponent_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CPlayerSoundComponent* tolua_ret = (Core::CPlayerSoundComponent*)  Mtolua_new((Core::CPlayerSoundComponent)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayerSoundComponent");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_new00_local
static int tolua_Core_Core_CPlayerSoundComponent_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CPlayerSoundComponent* tolua_ret = (Core::CPlayerSoundComponent*)  Mtolua_new((Core::CPlayerSoundComponent)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CPlayerSoundComponent");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_delete00
static int tolua_Core_Core_CPlayerSoundComponent_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMove of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_SetMove00
static int tolua_Core_Core_CPlayerSoundComponent_SetMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMove'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetMove(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetShot of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_SetShot00
static int tolua_Core_Core_CPlayerSoundComponent_SetShot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetShot'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetShot(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetShot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHolsterIn of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_SetHolsterIn00
static int tolua_Core_Core_CPlayerSoundComponent_SetHolsterIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHolsterIn'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetHolsterIn(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHolsterIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetHolsterOut of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_SetHolsterOut00
static int tolua_Core_Core_CPlayerSoundComponent_SetHolsterOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetHolsterOut'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetHolsterOut(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetHolsterOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetReload of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_SetReload00
static int tolua_Core_Core_CPlayerSoundComponent_SetReload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
  const char* FileName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetReload'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SetReload(FileName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetReload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayMove of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_PlayMove00
static int tolua_Core_Core_CPlayerSoundComponent_PlayMove00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayMove'", NULL);
#endif
  {
   self->PlayMove();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayMove'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayShot of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_PlayShot00
static int tolua_Core_Core_CPlayerSoundComponent_PlayShot00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayShot'", NULL);
#endif
  {
   self->PlayShot();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayShot'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayHolsterIn of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_PlayHolsterIn00
static int tolua_Core_Core_CPlayerSoundComponent_PlayHolsterIn00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayHolsterIn'", NULL);
#endif
  {
   self->PlayHolsterIn();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayHolsterIn'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayHolsterOut of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_PlayHolsterOut00
static int tolua_Core_Core_CPlayerSoundComponent_PlayHolsterOut00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayHolsterOut'", NULL);
#endif
  {
   self->PlayHolsterOut();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayHolsterOut'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: PlayReload of class  Core::CPlayerSoundComponent */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CPlayerSoundComponent_PlayReload00
static int tolua_Core_Core_CPlayerSoundComponent_PlayReload00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CPlayerSoundComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CPlayerSoundComponent* self = (Core::CPlayerSoundComponent*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'PlayReload'", NULL);
#endif
  {
   self->PlayReload();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'PlayReload'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::SoundToAnimation */
#ifndef TOLUA_DISABLE_tolua_Core_Core_SoundToAnimation_new00
static int tolua_Core_Core_SoundToAnimation_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::SoundToAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* Anim = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* Sound = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   Core::SoundToAnimation* tolua_ret = (Core::SoundToAnimation*)  Mtolua_new((Core::SoundToAnimation)(Anim,Sound));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::SoundToAnimation");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::SoundToAnimation */
#ifndef TOLUA_DISABLE_tolua_Core_Core_SoundToAnimation_new00_local
static int tolua_Core_Core_SoundToAnimation_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::SoundToAnimation",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* Anim = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* Sound = ((const char*)  tolua_tostring(tolua_S,3,0));
  {
   Core::SoundToAnimation* tolua_ret = (Core::SoundToAnimation*)  Mtolua_new((Core::SoundToAnimation)(Anim,Sound));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::SoundToAnimation");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Animation of class  Core::SoundToAnimation */
#ifndef TOLUA_DISABLE_tolua_get_Core__SoundToAnimation_Animation
static int tolua_get_Core__SoundToAnimation_Animation(lua_State* tolua_S)
{
  Core::SoundToAnimation* self = (Core::SoundToAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Animation'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->Animation);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: AnimSound of class  Core::SoundToAnimation */
#ifndef TOLUA_DISABLE_tolua_get_Core__SoundToAnimation_AnimSound
static int tolua_get_Core__SoundToAnimation_AnimSound(lua_State* tolua_S)
{
  Core::SoundToAnimation* self = (Core::SoundToAnimation*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'AnimSound'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->AnimSound);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_new00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const MovableObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* caption = ((const char*)  tolua_tostring(tolua_S,3,0));
  const MovableObject* mov = ((const MovableObject*)  tolua_tousertype(tolua_S,4,0));
  Core::OgreSpecific::MovableTextOverlayAttributes* attrs = ((Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,5,0));
  {
   Core::OgreSpecific::MovableTextOverlay* tolua_ret = (Core::OgreSpecific::MovableTextOverlay*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlay)(name,caption,mov,attrs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlay");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_new00_local
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isstring(tolua_S,3,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,4,"const MovableObject",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,5,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const char* name = ((const char*)  tolua_tostring(tolua_S,2,0));
  const char* caption = ((const char*)  tolua_tostring(tolua_S,3,0));
  const MovableObject* mov = ((const MovableObject*)  tolua_tousertype(tolua_S,4,0));
  Core::OgreSpecific::MovableTextOverlayAttributes* attrs = ((Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,5,0));
  {
   Core::OgreSpecific::MovableTextOverlay* tolua_ret = (Core::OgreSpecific::MovableTextOverlay*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlay)(name,caption,mov,attrs));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlay");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_delete00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCaption of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetCaption00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
  const char* caption = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCaption'", NULL);
#endif
  {
   self->SetCaption(caption);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetUpdateFrequency of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetUpdateFrequency00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetUpdateFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
  float updateFrequency = ((float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetUpdateFrequency'", NULL);
#endif
  {
   self->SetUpdateFrequency(updateFrequency);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetUpdateFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetAttributes of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetAttributes00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetAttributes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
  Core::OgreSpecific::MovableTextOverlayAttributes* attrs = ((Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetAttributes'", NULL);
#endif
  {
   self->SetAttributes(attrs);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetAttributes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetName00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlay* self = (const Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const String& tolua_ret = (const String&)  self->GetName();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const String");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCaption of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetCaption00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetCaption00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlay* self = (const Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCaption'", NULL);
#endif
  {
   const String& tolua_ret = (const String&)  self->GetCaption();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const String");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCaption'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetUpdateFrequency of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetUpdateFrequency00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetUpdateFrequency00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlay* self = (const Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetUpdateFrequency'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->GetUpdateFrequency();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetUpdateFrequency'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsOnScreen of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_IsOnScreen00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_IsOnScreen00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlay* self = (const Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsOnScreen'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->IsOnScreen();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsOnScreen'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsEnabled of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_IsEnabled00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_IsEnabled00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlay* self = (const Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsEnabled'", NULL);
#endif
  {
   const bool tolua_ret = (const bool)  self->IsEnabled();
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsEnabled'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: getAttributes of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_getAttributes00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_getAttributes00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlay* self = (const Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'getAttributes'", NULL);
#endif
  {
   const Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  self->getAttributes();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const Core::OgreSpecific::MovableTextOverlayAttributes");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'getAttributes'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Enable of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_Enable00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_Enable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isboolean(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
  bool Enable = ((bool)  tolua_toboolean(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Enable'", NULL);
#endif
  {
   self->Enable(Enable);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Enable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_Update00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelsTop of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsTop00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelsTop'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetPixelsTop();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPixelsTop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelsBottom of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsBottom00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsBottom00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelsBottom'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetPixelsBottom();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPixelsBottom'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelsLeft of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsLeft00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsLeft00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelsLeft'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetPixelsLeft();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPixelsLeft'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPixelsRight of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsRight00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsRight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPixelsRight'", NULL);
#endif
  {
   int tolua_ret = (int)  self->GetPixelsRight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPixelsRight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPixelsTop of class  Core::OgreSpecific::MovableTextOverlay */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetPixelsTop00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetPixelsTop00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlay",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlay* self = (Core::OgreSpecific::MovableTextOverlay*)  tolua_tousertype(tolua_S,1,0);
  int px = ((int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPixelsTop'", NULL);
#endif
  {
   self->SetPixelsTop(px);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPixelsTop'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::OgreSpecific::CScrollingMessage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CScrollingMessage_new00
static int tolua_Core_Core_OgreSpecific_CScrollingMessage_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::CScrollingMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::OgreSpecific::CScrollingMessage* tolua_ret = (Core::OgreSpecific::CScrollingMessage*)  Mtolua_new((Core::OgreSpecific::CScrollingMessage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::CScrollingMessage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::OgreSpecific::CScrollingMessage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CScrollingMessage_new00_local
static int tolua_Core_Core_OgreSpecific_CScrollingMessage_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::CScrollingMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::OgreSpecific::CScrollingMessage* tolua_ret = (Core::OgreSpecific::CScrollingMessage*)  Mtolua_new((Core::OgreSpecific::CScrollingMessage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::CScrollingMessage");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Init of class  Core::OgreSpecific::CScrollingMessage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CScrollingMessage_Init00
static int tolua_Core_Core_OgreSpecific_CScrollingMessage_Init00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CScrollingMessage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CScrollingMessage* self = (Core::OgreSpecific::CScrollingMessage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Init'", NULL);
#endif
  {
   self->Init();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Init'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddText of class  Core::OgreSpecific::CScrollingMessage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CScrollingMessage_AddText00
static int tolua_Core_Core_OgreSpecific_CScrollingMessage_AddText00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CScrollingMessage",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CScrollingMessage* self = (Core::OgreSpecific::CScrollingMessage*)  tolua_tousertype(tolua_S,1,0);
  const String* text = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddText'", NULL);
#endif
  {
   self->AddText(*text);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddText'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::OgreSpecific::CScrollingMessage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_CScrollingMessage_Update00
static int tolua_Core_Core_OgreSpecific_CScrollingMessage_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::CScrollingMessage",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::CScrollingMessage* self = (Core::OgreSpecific::CScrollingMessage*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CSpawnManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CSpawnManager_Instance00
static int tolua_Core_Core_CSpawnManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CSpawnManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CSpawnManager* tolua_ret = (Core::CSpawnManager*)  Core::CSpawnManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CSpawnManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CSpawnManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CSpawnManager_delete00
static int tolua_Core_Core_CSpawnManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CSpawnManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CSpawnManager* self = (Core::CSpawnManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddSpawnPoint of class  Core::CSpawnManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CSpawnManager_AddSpawnPoint00
static int tolua_Core_Core_CSpawnManager_AddSpawnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CSpawnManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector3",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,4,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CSpawnManager* self = (Core::CSpawnManager*)  tolua_tousertype(tolua_S,1,0);
  const char* SpawnName = ((const char*)  tolua_tostring(tolua_S,2,0));
  Vector3* Position = ((Vector3*)  tolua_tousertype(tolua_S,3,0));
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,4,0));
  Core::SPAWN_POINT_PRIORITY Priority = ((Core::SPAWN_POINT_PRIORITY) (int)  tolua_tonumber(tolua_S,5,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddSpawnPoint'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddSpawnPoint(SpawnName,*Position,Team,Priority);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddSpawnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveSpawnPoint of class  Core::CSpawnManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CSpawnManager_RemoveSpawnPoint00
static int tolua_Core_Core_CSpawnManager_RemoveSpawnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CSpawnManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CSpawnManager* self = (Core::CSpawnManager*)  tolua_tousertype(tolua_S,1,0);
  const char* SpawnName = ((const char*)  tolua_tostring(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveSpawnPoint'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RemoveSpawnPoint(SpawnName);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveSpawnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCurrentSpawnPoint of class  Core::CSpawnManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CSpawnManager_GetCurrentSpawnPoint00
static int tolua_Core_Core_CSpawnManager_GetCurrentSpawnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CSpawnManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Core::SPAWN_POINT",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CSpawnManager* self = (Core::CSpawnManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0));
  Core::SPAWN_POINT* SpawnPoint = ((Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCurrentSpawnPoint'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetCurrentSpawnPoint(Team,*SpawnPoint);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCurrentSpawnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetSpawnPoint of class  Core::CSpawnManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CSpawnManager_GetSpawnPoint00
static int tolua_Core_Core_CSpawnManager_GetSpawnPoint00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CSpawnManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Core::SPAWN_POINT",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CSpawnManager* self = (Core::CSpawnManager*)  tolua_tousertype(tolua_S,1,0);
  const char* SpawnName = ((const char*)  tolua_tostring(tolua_S,2,0));
  Core::SPAWN_POINT* SpawnPoint = ((Core::SPAWN_POINT*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetSpawnPoint'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->GetSpawnPoint(SpawnName,*SpawnPoint);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetSpawnPoint'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SpawnPlayer of class  Core::CSpawnManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CSpawnManager_SpawnPlayer00
static int tolua_Core_Core_CSpawnManager_SpawnPlayer00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CSpawnManager",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CSpawnManager* self = (Core::CSpawnManager*)  tolua_tousertype(tolua_S,1,0);
  const char* SpawnName = ((const char*)  tolua_tostring(tolua_S,2,0));
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SpawnPlayer'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->SpawnPlayer(SpawnName,Player);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SpawnPlayer'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_Instance00
static int tolua_Core_Core_Training_CTrainingManager_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Training::CTrainingManager* tolua_ret = (Core::Training::CTrainingManager*)  Core::Training::CTrainingManager::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Training::CTrainingManager");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_delete00
static int tolua_Core_Core_Training_CTrainingManager_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddFacility of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_AddFacility00
static int tolua_Core_Core_Training_CTrainingManager_AddFacility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0));
  unsigned int BuildingType = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddFacility'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->AddFacility(Team,BuildingType);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddFacility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveFacility of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_RemoveFacility00
static int tolua_Core_Core_Training_CTrainingManager_RemoveFacility00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0));
  unsigned int BuildingType = ((unsigned int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveFacility'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->RemoveFacility(Team,BuildingType);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveFacility'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsCapable of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_IsCapable00
static int tolua_Core_Core_Training_CTrainingManager_IsCapable00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnumber(tolua_S,3,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0));
  Core::Training::ET_CAPABILITIES Cap = ((Core::Training::ET_CAPABILITIES) (int)  tolua_tonumber(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsCapable'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsCapable(Team,Cap);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsCapable'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StartPlayerTraining of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_StartPlayerTraining00
static int tolua_Core_Core_Training_CTrainingManager_StartPlayerTraining00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::CPlayerAttributesComponent",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
  Core::CPlayerAttributesComponent* GoalAttributes = ((Core::CPlayerAttributesComponent*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StartPlayerTraining'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->StartPlayerTraining(Player,GoalAttributes);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StartPlayerTraining'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: StopPlayerTraining of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_StopPlayerTraining00
static int tolua_Core_Core_Training_CTrainingManager_StopPlayerTraining00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'StopPlayerTraining'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->StopPlayerTraining(Player);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'StopPlayerTraining'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: IsPlayerTraining of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_IsPlayerTraining00
static int tolua_Core_Core_Training_CTrainingManager_IsPlayerTraining00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  Core::CPlayer* Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'IsPlayerTraining'", NULL);
#endif
  {
   bool tolua_ret = (bool)  self->IsPlayerTraining(Player);
   tolua_pushboolean(tolua_S,(bool)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'IsPlayerTraining'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetPlayerTrainingList of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_GetPlayerTrainingList00
static int tolua_Core_Core_Training_CTrainingManager_GetPlayerTrainingList00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,3,&tolua_err) || !tolua_isusertype(tolua_S,3,"Vector<unsigned int>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  Core::E_PLAYER_TEAM Team = ((Core::E_PLAYER_TEAM) (int)  tolua_tonumber(tolua_S,2,0));
  Vector<unsigned int>* List = ((Vector<unsigned int>*)  tolua_tousertype(tolua_S,3,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetPlayerTrainingList'", NULL);
#endif
  {
   self->GetPlayerTrainingList(Team,*List);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetPlayerTrainingList'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnPlayerAttributeUpdate of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_OnPlayerAttributeUpdate00
static int tolua_Core_Core_Training_CTrainingManager_OnPlayerAttributeUpdate00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnPlayerAttributeUpdate'", NULL);
#endif
  {
   self->OnPlayerAttributeUpdate();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnPlayerAttributeUpdate'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Update of class  Core::Training::CTrainingManager */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Training_CTrainingManager_Update00
static int tolua_Core_Core_Training_CTrainingManager_Update00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Training::CTrainingManager",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Training::CTrainingManager* self = (Core::Training::CTrainingManager*)  tolua_tousertype(tolua_S,1,0);
  const float elapsedTime = ((const float)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Update'", NULL);
#endif
  {
   self->Update(elapsedTime);
   tolua_pushnumber(tolua_S,(lua_Number)elapsedTime);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Update'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetPosition of class  Core::Physics::CVolumeObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CVolumeObject_SetPosition00
static int tolua_Core_Core_Physics_CVolumeObject_SetPosition00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Physics::CVolumeObject",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const Vector3",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Physics::CVolumeObject* self = (Core::Physics::CVolumeObject*)  tolua_tousertype(tolua_S,1,0);
  const Vector3* Position = ((const Vector3*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetPosition'", NULL);
#endif
  {
   self->SetPosition(*Position);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetPosition'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: RemoveVolume of class  Core::Physics::CVolumeObject */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CVolumeObject_RemoveVolume00
static int tolua_Core_Core_Physics_CVolumeObject_RemoveVolume00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Physics::CVolumeObject",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Physics::CVolumeObject* self = (Core::Physics::CVolumeObject*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'RemoveVolume'", NULL);
#endif
  {
   self->RemoveVolume();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'RemoveVolume'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Physics::CVolumeObject_Cube */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CVolumeObject_Cube_new00
static int tolua_Core_Core_Physics_CVolumeObject_Cube_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::CVolumeObject_Cube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::CVolumeObject_Cube* tolua_ret = (Core::Physics::CVolumeObject_Cube*)  Mtolua_new((Core::Physics::CVolumeObject_Cube)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::CVolumeObject_Cube");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Physics::CVolumeObject_Cube */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CVolumeObject_Cube_new00_local
static int tolua_Core_Core_Physics_CVolumeObject_Cube_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::CVolumeObject_Cube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::CVolumeObject_Cube* tolua_ret = (Core::Physics::CVolumeObject_Cube*)  Mtolua_new((Core::Physics::CVolumeObject_Cube)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::CVolumeObject_Cube");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::Physics::CVolumeObject_Cube */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CVolumeObject_Cube_delete00
static int tolua_Core_Core_Physics_CVolumeObject_Cube_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Physics::CVolumeObject_Cube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Physics::CVolumeObject_Cube* self = (Core::Physics::CVolumeObject_Cube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: OnCollision of class  Core::Physics::CVolumeObject_Cube */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_CVolumeObject_Cube_OnCollision00
static int tolua_Core_Core_Physics_CVolumeObject_Cube_OnCollision00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::Physics::CVolumeObject_Cube",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::Physics::CVolumeObject_Cube* self = (Core::Physics::CVolumeObject_Cube*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'OnCollision'", NULL);
#endif
  {
   self->OnCollision();
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'OnCollision'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponProfile_new00
static int tolua_Core_Core_CWeaponProfile_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CWeaponProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CWeaponProfile* tolua_ret = (Core::CWeaponProfile*)  Mtolua_new((Core::CWeaponProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CWeaponProfile");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponProfile_new00_local
static int tolua_Core_Core_CWeaponProfile_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CWeaponProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CWeaponProfile* tolua_ret = (Core::CWeaponProfile*)  Mtolua_new((Core::CWeaponProfile)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CWeaponProfile");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponProfile_delete00
static int tolua_Core_Core_CWeaponProfile_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeaponProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isSemi of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_isSemi
static int tolua_get_Core__CWeaponProfile_isSemi(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isSemi'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isSemi);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isSemi of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_isSemi
static int tolua_set_Core__CWeaponProfile_isSemi(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isSemi'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isSemi = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isBurst of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_isBurst
static int tolua_get_Core__CWeaponProfile_isBurst(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isBurst'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isBurst);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isBurst of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_isBurst
static int tolua_set_Core__CWeaponProfile_isBurst(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isBurst'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isBurst = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isAuto of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_isAuto
static int tolua_get_Core__CWeaponProfile_isAuto(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAuto'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isAuto);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isAuto of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_isAuto
static int tolua_set_Core__CWeaponProfile_isAuto(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isAuto'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isAuto = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Capacity of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_unsigned_Capacity
static int tolua_get_Core__CWeaponProfile_unsigned_Capacity(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Capacity'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Capacity);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Capacity of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_unsigned_Capacity
static int tolua_set_Core__CWeaponProfile_unsigned_Capacity(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Capacity'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Capacity = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ROF of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_unsigned_ROF
static int tolua_get_Core__CWeaponProfile_unsigned_ROF(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ROF'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ROF);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ROF of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_unsigned_ROF
static int tolua_set_Core__CWeaponProfile_unsigned_ROF(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ROF'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ROF = ((unsigned int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Accuracy of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_Accuracy
static int tolua_get_Core__CWeaponProfile_Accuracy(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Accuracy'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Accuracy);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Accuracy of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_Accuracy
static int tolua_set_Core__CWeaponProfile_Accuracy(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Accuracy'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Accuracy = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Range of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_Range
static int tolua_get_Core__CWeaponProfile_Range(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Range'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Range);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Range of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_Range
static int tolua_set_Core__CWeaponProfile_Range(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Range'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Range = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ShotTime of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_ShotTime
static int tolua_get_Core__CWeaponProfile_ShotTime(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShotTime'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->ShotTime);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ShotTime of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_ShotTime
static int tolua_set_Core__CWeaponProfile_ShotTime(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ShotTime'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ShotTime = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Power of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_Power
static int tolua_get_Core__CWeaponProfile_Power(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Power'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Power);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Power of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_Power
static int tolua_set_Core__CWeaponProfile_Power(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Power'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Power = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MeshName of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_MeshName
static int tolua_get_Core__CWeaponProfile_MeshName(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MeshName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->MeshName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: OverlayName of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_OverlayName
static int tolua_get_Core__CWeaponProfile_OverlayName(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'OverlayName'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->OverlayName);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Desc of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_Desc
static int tolua_get_Core__CWeaponProfile_Desc(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Desc'",NULL);
#endif
  tolua_pushstring(tolua_S,(const char*)self->Desc);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Scale of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_Scale
static int tolua_get_Core__CWeaponProfile_Scale(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Scale,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Scale of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_Scale
static int tolua_set_Core__CWeaponProfile_Scale(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Scale = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: MagazineProfile of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_get_Core__CWeaponProfile_MagazineProfile_ptr
static int tolua_get_Core__CWeaponProfile_MagazineProfile_ptr(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MagazineProfile'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->MagazineProfile,"Core::CMagazineProfile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: MagazineProfile of class  Core::CWeaponProfile */
#ifndef TOLUA_DISABLE_tolua_set_Core__CWeaponProfile_MagazineProfile_ptr
static int tolua_set_Core__CWeaponProfile_MagazineProfile_ptr(lua_State* tolua_S)
{
  Core::CWeaponProfile* self = (Core::CWeaponProfile*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'MagazineProfile'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CMagazineProfile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->MagazineProfile = ((Core::CMagazineProfile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: Instance of class  Core::CWeaponFactory */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponFactory_Instance00
static int tolua_Core_Core_CWeaponFactory_Instance00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::CWeaponFactory",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::CWeaponFactory* tolua_ret = (Core::CWeaponFactory*)  Core::CWeaponFactory::Instance();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::CWeaponFactory");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Instance'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::CWeaponFactory */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponFactory_delete00
static int tolua_Core_Core_CWeaponFactory_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeaponFactory",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeaponFactory* self = (Core::CWeaponFactory*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: Create of class  Core::CWeaponFactory */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponFactory_Create00
static int tolua_Core_Core_CWeaponFactory_Create00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeaponFactory",0,&tolua_err) ||
     !tolua_isstring(tolua_S,2,0,&tolua_err) ||
     !tolua_isusertype(tolua_S,3,"Core::Physics::IPhysicsStrategy",1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeaponFactory* self = (Core::CWeaponFactory*)  tolua_tousertype(tolua_S,1,0);
  const char* ProfileName = ((const char*)  tolua_tostring(tolua_S,2,0));
  Core::Physics::IPhysicsStrategy* Physics = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,3,nullptr));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'Create'", NULL);
#endif
  {
   Core::IInventoryItem* tolua_ret = (Core::IInventoryItem*)  self->Create(ProfileName,Physics);
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::IInventoryItem");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'Create'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: AddProfile of class  Core::CWeaponFactory */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponFactory_AddProfile00
static int tolua_Core_Core_CWeaponFactory_AddProfile00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeaponFactory",0,&tolua_err) ||
     !tolua_isusertype(tolua_S,2,"Core::CItemProfile",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeaponFactory* self = (Core::CWeaponFactory*)  tolua_tousertype(tolua_S,1,0);
  Core::CItemProfile* Profile = ((Core::CItemProfile*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'AddProfile'", NULL);
#endif
  {
   self->AddProfile(Profile);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'AddProfile'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetProfiles of class  Core::CWeaponFactory */
#ifndef TOLUA_DISABLE_tolua_Core_Core_CWeaponFactory_GetProfiles00
static int tolua_Core_Core_CWeaponFactory_GetProfiles00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::CWeaponFactory",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector<Core::CItemProfile*>",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::CWeaponFactory* self = (Core::CWeaponFactory*)  tolua_tousertype(tolua_S,1,0);
  Vector<Core::CItemProfile*>* Profiles = ((Vector<Core::CItemProfile*>*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetProfiles'", NULL);
#endif
  {
   self->GetProfiles(*Profiles);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetProfiles'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00_local
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,4,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  const String* fontName = ((const String*)  tolua_tousertype(tolua_S,4,0));
  int charHeight = ((int)  tolua_tonumber(tolua_S,5,16));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam,*fontName,charHeight));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01_local
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,1,&tolua_err) ||
     !tolua_isnoobj(tolua_S,6,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  const String* fontName = ((const String*)  tolua_tousertype(tolua_S,4,0));
  int charHeight = ((int)  tolua_tonumber(tolua_S,5,16));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam,*fontName,charHeight));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  const String* fontName = ((const String*)  tolua_tousertype(tolua_S,4,0));
  int charHeight = ((int)  tolua_tonumber(tolua_S,5,0));
  const ColourValue* color = ((const ColourValue*)  tolua_tousertype(tolua_S,6,0));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam,*fontName,charHeight,*color));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02_local
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,7,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  const String* fontName = ((const String*)  tolua_tousertype(tolua_S,4,0));
  int charHeight = ((int)  tolua_tonumber(tolua_S,5,0));
  const ColourValue* color = ((const ColourValue*)  tolua_tousertype(tolua_S,6,0));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam,*fontName,charHeight,*color));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new03
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new03(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const ColourValue",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  const String* fontName = ((const String*)  tolua_tousertype(tolua_S,4,0));
  int charHeight = ((int)  tolua_tonumber(tolua_S,5,0));
  const ColourValue* color = ((const ColourValue*)  tolua_tousertype(tolua_S,6,0));
  const String* materialName = ((const String*)  tolua_tousertype(tolua_S,7,0));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam,*fontName,charHeight,*color,*materialName));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new03_local
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new03_local(lua_State* tolua_S)
{
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isusertype(tolua_S,3,"const Camera",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,4,&tolua_err) || !tolua_isusertype(tolua_S,4,"const String",0,&tolua_err)) ||
     !tolua_isnumber(tolua_S,5,0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,6,&tolua_err) || !tolua_isusertype(tolua_S,6,"const ColourValue",0,&tolua_err)) ||
     (tolua_isvaluenil(tolua_S,7,&tolua_err) || !tolua_isusertype(tolua_S,7,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,8,&tolua_err)
 )
  goto tolua_lerror;
 else
 {
  const String* name = ((const String*)  tolua_tousertype(tolua_S,2,0));
  const Camera* cam = ((const Camera*)  tolua_tousertype(tolua_S,3,0));
  const String* fontName = ((const String*)  tolua_tousertype(tolua_S,4,0));
  int charHeight = ((int)  tolua_tonumber(tolua_S,5,0));
  const ColourValue* color = ((const ColourValue*)  tolua_tousertype(tolua_S,6,0));
  const String* materialName = ((const String*)  tolua_tousertype(tolua_S,7,0));
  {
   Core::OgreSpecific::MovableTextOverlayAttributes* tolua_ret = (Core::OgreSpecific::MovableTextOverlayAttributes*)  Mtolua_new((Core::OgreSpecific::MovableTextOverlayAttributes)(*name,cam,*fontName,charHeight,*color,*materialName));
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::OgreSpecific::MovableTextOverlayAttributes");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
tolua_lerror:
 return tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02_local(tolua_S);
}
#endif //#ifndef TOLUA_DISABLE

/* method: delete of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_delete00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_delete00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'delete'", NULL);
#endif
  Mtolua_delete(self);
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'delete'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetFontName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetFontName00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
  const String* fontName = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetFontName'", NULL);
#endif
  {
   self->SetFontName(*fontName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetMaterialName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetMaterialName00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetMaterialName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const String",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
  const String* materialName = ((const String*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetMaterialName'", NULL);
#endif
  {
   self->SetMaterialName(*materialName);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetMaterialName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetColor of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetColor00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     (tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"const ColourValue",0,&tolua_err)) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
  const ColourValue* color = ((const ColourValue*)  tolua_tousertype(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetColor'", NULL);
#endif
  {
   self->SetColor(*color);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: SetCharacterHeight of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetCharacterHeight00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetCharacterHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnumber(tolua_S,2,0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,3,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
  unsigned int height = ((unsigned int)  tolua_tonumber(tolua_S,2,0));
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'SetCharacterHeight'", NULL);
#endif
  {
   self->SetCharacterHeight(height);
  }
 }
 return 0;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'SetCharacterHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetName00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlayAttributes* self = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetName'", NULL);
#endif
  {
   const String& tolua_ret = (const String&)  self->GetName();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const String");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCamera of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetCamera00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetCamera00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlayAttributes* self = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCamera'", NULL);
#endif
  {
   const Camera* tolua_ret = (const Camera*)  self->GetCamera();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const Camera");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCamera'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFont of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetFont00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetFont00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlayAttributes* self = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFont'", NULL);
#endif
  {
   const Font* tolua_ret = (const Font*)  self->GetFont();
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"const Font");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFont'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetFontName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetFontName00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetFontName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlayAttributes* self = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetFontName'", NULL);
#endif
  {
   const String& tolua_ret = (const String&)  self->GetFontName();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const String");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetFontName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetMaterialName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetMaterialName00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetMaterialName00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlayAttributes* self = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetMaterialName'", NULL);
#endif
  {
   const String& tolua_ret = (const String&)  self->GetMaterialName();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const String");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetMaterialName'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetColor of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetColor00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetColor00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlayAttributes* self = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetColor'", NULL);
#endif
  {
   const ColourValue& tolua_ret = (const ColourValue&)  self->GetColor();
    tolua_pushusertype(tolua_S,(void*)&tolua_ret,"const ColourValue");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetColor'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: GetCharacterHeight of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetCharacterHeight00
static int tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetCharacterHeight00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertype(tolua_S,1,"const Core::OgreSpecific::MovableTextOverlayAttributes",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  const Core::OgreSpecific::MovableTextOverlayAttributes* self = (const Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in function 'GetCharacterHeight'", NULL);
#endif
  {
   const float tolua_ret = (const float)  self->GetCharacterHeight();
   tolua_pushnumber(tolua_S,(lua_Number)tolua_ret);
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'GetCharacterHeight'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mName
static int tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mName(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mName,"const String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mpCam of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mpCam_ptr
static int tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mpCam_ptr(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mpCam'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->mpCam,"const Camera");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mpFont of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mpFont_ptr
static int tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mpFont_ptr(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mpFont'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->mpFont,"Font");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mpFont of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mpFont_ptr
static int tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mpFont_ptr(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mpFont'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Font",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mpFont = ((Font*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mFontName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mFontName
static int tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mFontName(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mFontName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mFontName,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mFontName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mFontName
static int tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mFontName(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mFontName'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mFontName = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mMaterialName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mMaterialName
static int tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mMaterialName(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMaterialName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mMaterialName,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mMaterialName of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mMaterialName
static int tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mMaterialName(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mMaterialName'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mMaterialName = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mColor of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mColor
static int tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mColor(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mColor'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->mColor,"ColourValue");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mColor of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mColor
static int tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mColor(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mColor'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"ColourValue",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mColor = *((ColourValue*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: mCharHeight of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mCharHeight
static int tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mCharHeight(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mCharHeight'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->mCharHeight);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: mCharHeight of class  Core::OgreSpecific::MovableTextOverlayAttributes */
#ifndef TOLUA_DISABLE_tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mCharHeight
static int tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mCharHeight(lua_State* tolua_S)
{
  Core::OgreSpecific::MovableTextOverlayAttributes* self = (Core::OgreSpecific::MovableTextOverlayAttributes*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'mCharHeight'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->mCharHeight = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_VolumePackage_new00
static int tolua_Core_Core_Physics_VolumePackage_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::VolumePackage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::VolumePackage* tolua_ret = (Core::Physics::VolumePackage*)  Mtolua_new((Core::Physics::VolumePackage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::VolumePackage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_VolumePackage_new00_local
static int tolua_Core_Core_Physics_VolumePackage_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::VolumePackage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::VolumePackage* tolua_ret = (Core::Physics::VolumePackage*)  Mtolua_new((Core::Physics::VolumePackage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::VolumePackage");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Profile of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__VolumePackage_Profile_ptr
static int tolua_get_Core__Physics__VolumePackage_Profile_ptr(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Profile'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Profile,"Core::Physics::CPhysicsProfile");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Profile of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__VolumePackage_Profile_ptr
static int tolua_set_Core__Physics__VolumePackage_Profile_ptr(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Profile'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::Physics::CPhysicsProfile",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Profile = ((Core::Physics::CPhysicsProfile*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Strategy of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__VolumePackage_Strategy_ptr
static int tolua_get_Core__Physics__VolumePackage_Strategy_ptr(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Strategy'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Strategy,"Core::Physics::IPhysicsStrategy");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Strategy of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__VolumePackage_Strategy_ptr
static int tolua_set_Core__Physics__VolumePackage_Strategy_ptr(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Strategy'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::Physics::IPhysicsStrategy",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Strategy = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Scale of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__VolumePackage_Scale
static int tolua_get_Core__Physics__VolumePackage_Scale(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->Scale);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Scale of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__VolumePackage_Scale
static int tolua_set_Core__Physics__VolumePackage_Scale(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Scale'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Scale = ((float)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: isRemoveCallback of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__VolumePackage_isRemoveCallback
static int tolua_get_Core__Physics__VolumePackage_isRemoveCallback(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isRemoveCallback'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->isRemoveCallback);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: isRemoveCallback of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__VolumePackage_isRemoveCallback
static int tolua_set_Core__Physics__VolumePackage_isRemoveCallback(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'isRemoveCallback'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->isRemoveCallback = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: EnableRaycast of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__VolumePackage_EnableRaycast
static int tolua_get_Core__Physics__VolumePackage_EnableRaycast(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EnableRaycast'",NULL);
#endif
  tolua_pushboolean(tolua_S,(bool)self->EnableRaycast);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: EnableRaycast of class  Core::Physics::VolumePackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__VolumePackage_EnableRaycast
static int tolua_set_Core__Physics__VolumePackage_EnableRaycast(lua_State* tolua_S)
{
  Core::Physics::VolumePackage* self = (Core::Physics::VolumePackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'EnableRaycast'",NULL);
  if (!tolua_isboolean(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->EnableRaycast = ((bool)  tolua_toboolean(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_SceneImporterPackage_new00
static int tolua_Core_Core_SceneImporterPackage_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::SceneImporterPackage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::SceneImporterPackage* tolua_ret = (Core::SceneImporterPackage*)  Mtolua_new((Core::SceneImporterPackage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::SceneImporterPackage");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_Core_Core_SceneImporterPackage_new00_local
static int tolua_Core_Core_SceneImporterPackage_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::SceneImporterPackage",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::SceneImporterPackage* tolua_ret = (Core::SceneImporterPackage*)  Mtolua_new((Core::SceneImporterPackage)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::SceneImporterPackage");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GameManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_GameManager_ptr
static int tolua_get_Core__SceneImporterPackage_GameManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameManager'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->GameManager,"Core::CGameManager");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GameManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_GameManager_ptr
static int tolua_set_Core__SceneImporterPackage_GameManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameManager'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CGameManager",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->GameManager = ((Core::CGameManager*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: PhysicsStrategy of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_PhysicsStrategy_ptr
static int tolua_get_Core__SceneImporterPackage_PhysicsStrategy_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PhysicsStrategy'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->PhysicsStrategy,"Core::Physics::IPhysicsStrategy");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: PhysicsStrategy of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_PhysicsStrategy_ptr
static int tolua_set_Core__SceneImporterPackage_PhysicsStrategy_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'PhysicsStrategy'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::Physics::IPhysicsStrategy",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->PhysicsStrategy = ((Core::Physics::IPhysicsStrategy*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: SoundManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_SoundManager_ptr
static int tolua_get_Core__SceneImporterPackage_SoundManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SoundManager'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->SoundManager,"Sound::CSoundManager");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: SoundManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_SoundManager_ptr
static int tolua_set_Core__SceneImporterPackage_SoundManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'SoundManager'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Sound::CSoundManager",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->SoundManager = ((Sound::CSoundManager*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ItemsManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_ItemsManager_ptr
static int tolua_get_Core__SceneImporterPackage_ItemsManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ItemsManager'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->ItemsManager,"Core::CItemsManager");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ItemsManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_ItemsManager_ptr
static int tolua_set_Core__SceneImporterPackage_ItemsManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ItemsManager'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CItemsManager",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ItemsManager = ((Core::CItemsManager*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GameObjectManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_GameObjectManager_ptr
static int tolua_get_Core__SceneImporterPackage_GameObjectManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameObjectManager'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->GameObjectManager,"Core::CGameObjectManager");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GameObjectManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_GameObjectManager_ptr
static int tolua_set_Core__SceneImporterPackage_GameObjectManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameObjectManager'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CGameObjectManager",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->GameObjectManager = ((Core::CGameObjectManager*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: NatureManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_NatureManager_ptr
static int tolua_get_Core__SceneImporterPackage_NatureManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NatureManager'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->NatureManager,"Core::Nature::CNatureManager");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: NatureManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_NatureManager_ptr
static int tolua_set_Core__SceneImporterPackage_NatureManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'NatureManager'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::Nature::CNatureManager",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->NatureManager = ((Core::Nature::CNatureManager*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: CameraManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_CameraManager_ptr
static int tolua_get_Core__SceneImporterPackage_CameraManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CameraManager'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->CameraManager,"Core::CCameraManager");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: CameraManager of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_CameraManager_ptr
static int tolua_set_Core__SceneImporterPackage_CameraManager_ptr(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'CameraManager'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CCameraManager",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->CameraManager = ((Core::CCameraManager*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: ResourceGroupName of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_get_Core__SceneImporterPackage_ResourceGroupName
static int tolua_get_Core__SceneImporterPackage_ResourceGroupName(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ResourceGroupName'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->ResourceGroupName,"String");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: ResourceGroupName of class  Core::SceneImporterPackage */
#ifndef TOLUA_DISABLE_tolua_set_Core__SceneImporterPackage_ResourceGroupName
static int tolua_set_Core__SceneImporterPackage_ResourceGroupName(lua_State* tolua_S)
{
  Core::SceneImporterPackage* self = (Core::SceneImporterPackage*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'ResourceGroupName'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"String",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->ResourceGroupName = *((String*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* method: new of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_SPhysicsRayCastReport_new00
static int tolua_Core_Core_Physics_SPhysicsRayCastReport_new00(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::SPhysicsRayCastReport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::SPhysicsRayCastReport* tolua_ret = (Core::Physics::SPhysicsRayCastReport*)  Mtolua_new((Core::Physics::SPhysicsRayCastReport)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::SPhysicsRayCastReport");
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* method: new_local of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_Core_Core_Physics_SPhysicsRayCastReport_new00_local
static int tolua_Core_Core_Physics_SPhysicsRayCastReport_new00_local(lua_State* tolua_S)
{
#ifndef TOLUA_RELEASE
 tolua_Error tolua_err;
 if (
     !tolua_isusertable(tolua_S,1,"Core::Physics::SPhysicsRayCastReport",0,&tolua_err) ||
     !tolua_isnoobj(tolua_S,2,&tolua_err)
 )
  goto tolua_lerror;
 else
#endif
 {
  {
   Core::Physics::SPhysicsRayCastReport* tolua_ret = (Core::Physics::SPhysicsRayCastReport*)  Mtolua_new((Core::Physics::SPhysicsRayCastReport)());
    tolua_pushusertype(tolua_S,(void*)tolua_ret,"Core::Physics::SPhysicsRayCastReport");
    tolua_register_gc(tolua_S,lua_gettop(tolua_S));
  }
 }
 return 1;
#ifndef TOLUA_RELEASE
 tolua_lerror:
 tolua_error(tolua_S,"#ferror in function 'new'.",&tolua_err);
 return 0;
#endif
}
#endif //#ifndef TOLUA_DISABLE

/* get function: GameObject of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__SPhysicsRayCastReport_GameObject_ptr
static int tolua_get_Core__Physics__SPhysicsRayCastReport_GameObject_ptr(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameObject'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->GameObject,"Core::CGameObject");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: GameObject of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__SPhysicsRayCastReport_GameObject_ptr
static int tolua_set_Core__Physics__SPhysicsRayCastReport_GameObject_ptr(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'GameObject'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CGameObject",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->GameObject = ((Core::CGameObject*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Player of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__SPhysicsRayCastReport_Player_ptr
static int tolua_get_Core__Physics__SPhysicsRayCastReport_Player_ptr(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Player'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)self->Player,"Core::CPlayer");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Player of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__SPhysicsRayCastReport_Player_ptr
static int tolua_set_Core__Physics__SPhysicsRayCastReport_Player_ptr(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Player'",NULL);
  if (!tolua_isusertype(tolua_S,2,"Core::CPlayer",0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Player = ((Core::CPlayer*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Custom of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__SPhysicsRayCastReport_Custom
static int tolua_get_Core__Physics__SPhysicsRayCastReport_Custom(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Custom'",NULL);
#endif
  tolua_pushuserdata(tolua_S,(void*)self->Custom);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Custom of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__SPhysicsRayCastReport_Custom
static int tolua_set_Core__Physics__SPhysicsRayCastReport_Custom(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Custom'",NULL);
  if (!tolua_isuserdata(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Custom = ((void*)  tolua_touserdata(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: BodyType of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__SPhysicsRayCastReport_BodyType
static int tolua_get_Core__Physics__SPhysicsRayCastReport_BodyType(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BodyType'",NULL);
#endif
  tolua_pushnumber(tolua_S,(lua_Number)self->BodyType);
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: BodyType of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__SPhysicsRayCastReport_BodyType
static int tolua_set_Core__Physics__SPhysicsRayCastReport_BodyType(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'BodyType'",NULL);
  if (!tolua_isnumber(tolua_S,2,0,&tolua_err))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->BodyType = ((Core::Physics::E_BODY_TYPE) (int)  tolua_tonumber(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* get function: Position of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_get_Core__Physics__SPhysicsRayCastReport_Position
static int tolua_get_Core__Physics__SPhysicsRayCastReport_Position(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
#endif
   tolua_pushusertype(tolua_S,(void*)&self->Position,"Vector3");
 return 1;
}
#endif //#ifndef TOLUA_DISABLE

/* set function: Position of class  Core::Physics::SPhysicsRayCastReport */
#ifndef TOLUA_DISABLE_tolua_set_Core__Physics__SPhysicsRayCastReport_Position
static int tolua_set_Core__Physics__SPhysicsRayCastReport_Position(lua_State* tolua_S)
{
  Core::Physics::SPhysicsRayCastReport* self = (Core::Physics::SPhysicsRayCastReport*)  tolua_tousertype(tolua_S,1,0);
#ifndef TOLUA_RELEASE
  tolua_Error tolua_err;
  if (!self) tolua_error(tolua_S,"invalid 'self' in accessing variable 'Position'",NULL);
  if ((tolua_isvaluenil(tolua_S,2,&tolua_err) || !tolua_isusertype(tolua_S,2,"Vector3",0,&tolua_err)))
   tolua_error(tolua_S,"#vinvalid type in variable assignment.",&tolua_err);
#endif
  self->Position = *((Vector3*)  tolua_tousertype(tolua_S,2,0))
;
 return 0;
}
#endif //#ifndef TOLUA_DISABLE

/* Open function */
TOLUA_API int tolua_Core_open (lua_State* tolua_S)
{
 tolua_open(tolua_S);
 tolua_reg_types(tolua_S);
 tolua_module(tolua_S,NULL,0);
 tolua_beginmodule(tolua_S,NULL);
  tolua_module(tolua_S,"Core",1);
  tolua_beginmodule(tolua_S,"Core");
   tolua_cclass(tolua_S,"ICamera","Core::ICamera","",NULL);
   tolua_beginmodule(tolua_S,"ICamera");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CPluginManager","Core::CPluginManager","",tolua_collect_Core__CPluginManager);
   #else
   tolua_cclass(tolua_S,"CPluginManager","Core::CPluginManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CPluginManager");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CPluginManager_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CPluginManager_delete00);
    tolua_function(tolua_S,"LoadPlugin",tolua_Core_Core_CPluginManager_LoadPlugin00);
    tolua_function(tolua_S,"GetGameObjectFactories",tolua_Core_Core_CPluginManager_GetGameObjectFactories00);
    tolua_function(tolua_S,"GetConsoleParsers",tolua_Core_Core_CPluginManager_GetConsoleParsers00);
    tolua_function(tolua_S,"GetMissionFactories",tolua_Core_Core_CPluginManager_GetMissionFactories00);
    tolua_function(tolua_S,"GetAiStateFactories",tolua_Core_Core_CPluginManager_GetAiStateFactories00);
    tolua_function(tolua_S,"GetPlayerFactories",tolua_Core_Core_CPluginManager_GetPlayerFactories00);
    tolua_function(tolua_S,"GetParticleFactories",tolua_Core_Core_CPluginManager_GetParticleFactories00);
    tolua_function(tolua_S,"GetCameraFactories",tolua_Core_Core_CPluginManager_GetCameraFactories00);
    tolua_function(tolua_S,"GetPostEffectFactories",tolua_Core_Core_CPluginManager_GetPostEffectFactories00);
    tolua_function(tolua_S,"GetPhysicsStrategyFactoryies",tolua_Core_Core_CPluginManager_GetPhysicsStrategyFactoryies00);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Plugin",0);
   tolua_beginmodule(tolua_S,"Plugin");
    tolua_cclass(tolua_S,"ICameraFactory","Core::Plugin::ICameraFactory","",NULL);
    tolua_beginmodule(tolua_S,"ICameraFactory");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CCameraManager","Core::CCameraManager","",tolua_collect_Core__CCameraManager);
   #else
   tolua_cclass(tolua_S,"CCameraManager","Core::CCameraManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CCameraManager");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CCameraManager_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CCameraManager_delete00);
    tolua_function(tolua_S,"GetMode",tolua_Core_Core_CCameraManager_GetMode00);
    tolua_function(tolua_S,"GetCamera",tolua_Core_Core_CCameraManager_GetCamera00);
    tolua_function(tolua_S,"GetViewport",tolua_Core_Core_CCameraManager_GetViewport00);
    tolua_function(tolua_S,"GetCameraPos",tolua_Core_Core_CCameraManager_GetCameraPos00);
    tolua_function(tolua_S,"GetCameras",tolua_Core_Core_CCameraManager_GetCameras00);
    tolua_function(tolua_S,"GetIsPlayerFriendly",tolua_Core_Core_CCameraManager_GetIsPlayerFriendly00);
    tolua_function(tolua_S,"GetCameraNode",tolua_Core_Core_CCameraManager_GetCameraNode00);
    tolua_function(tolua_S,"GetTargetNode",tolua_Core_Core_CCameraManager_GetTargetNode00);
    tolua_function(tolua_S,"SetMoveSpeed",tolua_Core_Core_CCameraManager_SetMoveSpeed00);
    tolua_function(tolua_S,"SetEnabled",tolua_Core_Core_CCameraManager_SetEnabled00);
    tolua_function(tolua_S,"SetCameraPos",tolua_Core_Core_CCameraManager_SetCameraPos00);
    tolua_function(tolua_S,"SetCurrCamera",tolua_Core_Core_CCameraManager_SetCurrCamera00);
    tolua_function(tolua_S,"IsHaveMode",tolua_Core_Core_CCameraManager_IsHaveMode00);
    tolua_function(tolua_S,"RemoveAllCameras",tolua_Core_Core_CCameraManager_RemoveAllCameras00);
    tolua_function(tolua_S,"Shutdown",tolua_Core_Core_CCameraManager_Shutdown00);
    tolua_function(tolua_S,"Restart",tolua_Core_Core_CCameraManager_Restart00);
    tolua_function(tolua_S,"CreateCamera",tolua_Core_Core_CCameraManager_CreateCamera00);
    tolua_function(tolua_S,"CreatePluginCamera",tolua_Core_Core_CCameraManager_CreatePluginCamera00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CCameraManager_Update00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CCameraManager_Update01);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",1);
  tolua_beginmodule(tolua_S,"Core");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CPlayer","Core::CPlayer","",tolua_collect_Core__CPlayer);
   #else
   tolua_cclass(tolua_S,"CPlayer","Core::CPlayer","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CPlayer");
    tolua_function(tolua_S,"delete",tolua_Core_Core_CPlayer_delete00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CPlayer_Update00);
    tolua_function(tolua_S,"GetPlayerNode",tolua_Core_Core_CPlayer_GetPlayerNode00);
    tolua_function(tolua_S,"GetPlayerEntity",tolua_Core_Core_CPlayer_GetPlayerEntity00);
    tolua_function(tolua_S,"GetHealth",tolua_Core_Core_CPlayer_GetHealth00);
    tolua_function(tolua_S,"GetViewRange",tolua_Core_Core_CPlayer_GetViewRange00);
    tolua_function(tolua_S,"GetPlayerState",tolua_Core_Core_CPlayer_GetPlayerState00);
    tolua_function(tolua_S,"GetAiVehicle",tolua_Core_Core_CPlayer_GetAiVehicle00);
    tolua_function(tolua_S,"GetCharacterState",tolua_Core_Core_CPlayer_GetCharacterState00);
    tolua_function(tolua_S,"GetPlayerTeam",tolua_Core_Core_CPlayer_GetPlayerTeam00);
    tolua_function(tolua_S,"GetPosition",tolua_Core_Core_CPlayer_GetPosition00);
    tolua_function(tolua_S,"GetName",tolua_Core_Core_CPlayer_GetName00);
    tolua_function(tolua_S,"GetMeshName",tolua_Core_Core_CPlayer_GetMeshName00);
    tolua_function(tolua_S,"GetIsVisible",tolua_Core_Core_CPlayer_GetIsVisible00);
    tolua_function(tolua_S,"GetIsHumanPlayer",tolua_Core_Core_CPlayer_GetIsHumanPlayer00);
    tolua_function(tolua_S,"GetDirection",tolua_Core_Core_CPlayer_GetDirection00);
    tolua_function(tolua_S,"GetItems",tolua_Core_Core_CPlayer_GetItems00);
    tolua_function(tolua_S,"GetHeadPosition",tolua_Core_Core_CPlayer_GetHeadPosition00);
    tolua_function(tolua_S,"GetHeadRotation",tolua_Core_Core_CPlayer_GetHeadRotation00);
    tolua_function(tolua_S,"GetBodyPosition",tolua_Core_Core_CPlayer_GetBodyPosition00);
    tolua_function(tolua_S,"GetBodyRotation",tolua_Core_Core_CPlayer_GetBodyRotation00);
    tolua_function(tolua_S,"GetAiTarget",tolua_Core_Core_CPlayer_GetAiTarget00);
    tolua_function(tolua_S,"GetAiPathPoints",tolua_Core_Core_CPlayer_GetAiPathPoints00);
    tolua_function(tolua_S,"GetCurrentWeapon",tolua_Core_Core_CPlayer_GetCurrentWeapon00);
    tolua_function(tolua_S,"GetEyePosition",tolua_Core_Core_CPlayer_GetEyePosition00);
    tolua_function(tolua_S,"GetCharacterControllerSize",tolua_Core_Core_CPlayer_GetCharacterControllerSize00);
    tolua_function(tolua_S,"GetLoSType",tolua_Core_Core_CPlayer_GetLoSType00);
    tolua_function(tolua_S,"GetPlayerType",tolua_Core_Core_CPlayer_GetPlayerType00);
    tolua_function(tolua_S,"GetPhysicsStrategy",tolua_Core_Core_CPlayer_GetPhysicsStrategy00);
    tolua_function(tolua_S,"GetCharacterController",tolua_Core_Core_CPlayer_GetCharacterController00);
    tolua_function(tolua_S,"GetRunSpeed",tolua_Core_Core_CPlayer_GetRunSpeed00);
    tolua_function(tolua_S,"GetWalkSpeed",tolua_Core_Core_CPlayer_GetWalkSpeed00);
    tolua_function(tolua_S,"GetSprintSpeed",tolua_Core_Core_CPlayer_GetSprintSpeed00);
    tolua_function(tolua_S,"GetCrawlSpeed",tolua_Core_Core_CPlayer_GetCrawlSpeed00);
    tolua_function(tolua_S,"GetDieTime",tolua_Core_Core_CPlayer_GetDieTime00);
    tolua_function(tolua_S,"GetMovableText",tolua_Core_Core_CPlayer_GetMovableText00);
    tolua_function(tolua_S,"SetRunSpeed",tolua_Core_Core_CPlayer_SetRunSpeed00);
    tolua_function(tolua_S,"SetWalkSpeed",tolua_Core_Core_CPlayer_SetWalkSpeed00);
    tolua_function(tolua_S,"SetSprintSpeed",tolua_Core_Core_CPlayer_SetSprintSpeed00);
    tolua_function(tolua_S,"SetCrawlSpeed",tolua_Core_Core_CPlayer_SetCrawlSpeed00);
    tolua_function(tolua_S,"SetDieTime",tolua_Core_Core_CPlayer_SetDieTime00);
    tolua_function(tolua_S,"SetHealth",tolua_Core_Core_CPlayer_SetHealth00);
    tolua_function(tolua_S,"SetVisible",tolua_Core_Core_CPlayer_SetVisible00);
    tolua_function(tolua_S,"SetPlayerState",tolua_Core_Core_CPlayer_SetPlayerState00);
    tolua_function(tolua_S,"SetAiVehicle",tolua_Core_Core_CPlayer_SetAiVehicle00);
    tolua_function(tolua_S,"SetCharacterState",tolua_Core_Core_CPlayer_SetCharacterState00);
    tolua_function(tolua_S,"SetExcactCharacterState",tolua_Core_Core_CPlayer_SetExcactCharacterState00);
    tolua_function(tolua_S,"SetPlayerPosition",tolua_Core_Core_CPlayer_SetPlayerPosition00);
    tolua_function(tolua_S,"SetPlayerPosition",tolua_Core_Core_CPlayer_SetPlayerPosition01);
    tolua_function(tolua_S,"SetPlayerTeam",tolua_Core_Core_CPlayer_SetPlayerTeam00);
    tolua_function(tolua_S,"SetHumanPlayer",tolua_Core_Core_CPlayer_SetHumanPlayer00);
    tolua_function(tolua_S,"SetViewRange",tolua_Core_Core_CPlayer_SetViewRange00);
    tolua_function(tolua_S,"SetTextLabelCaption",tolua_Core_Core_CPlayer_SetTextLabelCaption00);
    tolua_function(tolua_S,"SetTextLabelEnabled",tolua_Core_Core_CPlayer_SetTextLabelEnabled00);
    tolua_function(tolua_S,"SetAiTarget",tolua_Core_Core_CPlayer_SetAiTarget00);
    tolua_function(tolua_S,"SetAiPathPoints",tolua_Core_Core_CPlayer_SetAiPathPoints00);
    tolua_function(tolua_S,"SetName",tolua_Core_Core_CPlayer_SetName00);
    tolua_function(tolua_S,"SetDirection",tolua_Core_Core_CPlayer_SetDirection00);
    tolua_function(tolua_S,"SetLoSType",tolua_Core_Core_CPlayer_SetLoSType00);
    tolua_function(tolua_S,"CanSee",tolua_Core_Core_CPlayer_CanSee00);
    tolua_function(tolua_S,"CanSee",tolua_Core_Core_CPlayer_CanSee01);
    tolua_function(tolua_S,"AddItem",tolua_Core_Core_CPlayer_AddItem00);
    tolua_function(tolua_S,"RemoveItem",tolua_Core_Core_CPlayer_RemoveItem00);
    tolua_function(tolua_S,"RemoveAllItems",tolua_Core_Core_CPlayer_RemoveAllItems00);
    tolua_function(tolua_S,"DebugLoS",tolua_Core_Core_CPlayer_DebugLoS00);
    tolua_function(tolua_S,"OnHit",tolua_Core_Core_CPlayer_OnHit00);
    tolua_function(tolua_S,"OnShotFired",tolua_Core_Core_CPlayer_OnShotFired00);
    tolua_function(tolua_S,"OnMove",tolua_Core_Core_CPlayer_OnMove00);
    tolua_function(tolua_S,"OnPickupItem",tolua_Core_Core_CPlayer_OnPickupItem00);
    tolua_function(tolua_S,"OnKill",tolua_Core_Core_CPlayer_OnKill00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"AI",0);
   tolua_beginmodule(tolua_S,"AI");
    tolua_constant(tolua_S,"SUCCESS",Core::AI::SUCCESS);
    tolua_constant(tolua_S,"FAILED",Core::AI::FAILED);
    tolua_constant(tolua_S,"WORKING",Core::AI::WORKING);
    tolua_constant(tolua_S,"IMPOSSIBLE",Core::AI::IMPOSSIBLE);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CCharacterState","Core::AI::CCharacterState","",tolua_collect_Core__AI__CCharacterState);
    #else
    tolua_cclass(tolua_S,"CCharacterState","Core::AI::CCharacterState","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CCharacterState");
     tolua_function(tolua_S,"Update",tolua_Core_Core_AI_CCharacterState_Update00);
     tolua_function(tolua_S,"GetOutcomeState",tolua_Core_Core_AI_CCharacterState_GetOutcomeState00);
     tolua_function(tolua_S,"GetStateType",tolua_Core_Core_AI_CCharacterState_GetStateType00);
     tolua_function(tolua_S,"GetStateName",tolua_Core_Core_AI_CCharacterState_GetStateName00);
     tolua_function(tolua_S,"GetLevel",tolua_Core_Core_AI_CCharacterState_GetLevel00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",1);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Plugin",0);
   tolua_beginmodule(tolua_S,"Plugin");
    tolua_cclass(tolua_S,"IAiStateFactory","Core::Plugin::IAiStateFactory","",NULL);
    tolua_beginmodule(tolua_S,"IAiStateFactory");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"AI",0);
   tolua_beginmodule(tolua_S,"AI");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CCharacterStateManager","Core::AI::CCharacterStateManager","",tolua_collect_Core__AI__CCharacterStateManager);
    #else
    tolua_cclass(tolua_S,"CCharacterStateManager","Core::AI::CCharacterStateManager","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CCharacterStateManager");
     tolua_function(tolua_S,"Instance",tolua_Core_Core_AI_CCharacterStateManager_Instance00);
     tolua_function(tolua_S,"delete",tolua_Core_Core_AI_CCharacterStateManager_delete00);
     tolua_function(tolua_S,"GetState",tolua_Core_Core_AI_CCharacterStateManager_GetState00);
     tolua_function(tolua_S,"GetState",tolua_Core_Core_AI_CCharacterStateManager_GetState01);
     tolua_function(tolua_S,"GetAllStates",tolua_Core_Core_AI_CCharacterStateManager_GetAllStates00);
     tolua_function(tolua_S,"GetLoadedStates",tolua_Core_Core_AI_CCharacterStateManager_GetLoadedStates00);
     tolua_function(tolua_S,"AddPath",tolua_Core_Core_AI_CCharacterStateManager_AddPath00);
     tolua_function(tolua_S,"GetPathCount",tolua_Core_Core_AI_CCharacterStateManager_GetPathCount00);
     tolua_function(tolua_S,"GetPathByName",tolua_Core_Core_AI_CCharacterStateManager_GetPathByName00);
     tolua_function(tolua_S,"GetAllPaths",tolua_Core_Core_AI_CCharacterStateManager_GetAllPaths00);
     tolua_function(tolua_S,"SetName",tolua_Core_Core_AI_CCharacterStateManager_SetName00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CGameObject","Core::CGameObject","",tolua_collect_Core__CGameObject);
   #else
   tolua_cclass(tolua_S,"CGameObject","Core::CGameObject","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CGameObject");
    tolua_function(tolua_S,"SetIsUpdatable",tolua_Core_Core_CGameObject_SetIsUpdatable00);
    tolua_function(tolua_S,"SetPosition",tolua_Core_Core_CGameObject_SetPosition00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CGameObject_Update00);
    tolua_variable(tolua_S,"Name",tolua_get_Core__CGameObject_Name,tolua_set_Core__CGameObject_Name);
    tolua_variable(tolua_S,"GameObjectType",tolua_get_Core__CGameObject_GameObjectType,tolua_set_Core__CGameObject_GameObjectType);
    tolua_variable(tolua_S,"Node",tolua_get_Core__CGameObject_Node_ptr,tolua_set_Core__CGameObject_Node_ptr);
    tolua_variable(tolua_S,"Entity",tolua_get_Core__CGameObject_Entity_ptr,tolua_set_Core__CGameObject_Entity_ptr);
    tolua_variable(tolua_S,"PhysicsProfile",tolua_get_Core__CGameObject_PhysicsProfile_ptr,tolua_set_Core__CGameObject_PhysicsProfile_ptr);
    tolua_variable(tolua_S,"EnvironmentType",tolua_get_Core__CGameObject_EnvironmentType,tolua_set_Core__CGameObject_EnvironmentType);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CDummyGameObject","Core::CDummyGameObject","Core::CGameObject",tolua_collect_Core__CDummyGameObject);
   #else
   tolua_cclass(tolua_S,"CDummyGameObject","Core::CDummyGameObject","Core::CGameObject",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CDummyGameObject");
    tolua_function(tolua_S,"new",tolua_Core_Core_CDummyGameObject_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CDummyGameObject_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CDummyGameObject_new00_local);
    tolua_function(tolua_S,"new",tolua_Core_Core_CDummyGameObject_new01);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CDummyGameObject_new01_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CDummyGameObject_new01_local);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CDummyGameObject_Update00);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Plugin",0);
   tolua_beginmodule(tolua_S,"Plugin");
    tolua_cclass(tolua_S,"IParticleFactory","Core::Plugin::IParticleFactory","",NULL);
    tolua_beginmodule(tolua_S,"IParticleFactory");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Effects",0);
   tolua_beginmodule(tolua_S,"Effects");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CParticleEffect","Core::Effects::CParticleEffect","",tolua_collect_Core__Effects__CParticleEffect);
    #else
    tolua_cclass(tolua_S,"CParticleEffect","Core::Effects::CParticleEffect","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CParticleEffect");
     tolua_function(tolua_S,"StartTimer",tolua_Core_Core_Effects_CParticleEffect_StartTimer00);
     tolua_function(tolua_S,"Update",tolua_Core_Core_Effects_CParticleEffect_Update00);
     tolua_function(tolua_S,"UpdateAll",tolua_Core_Core_Effects_CParticleEffect_UpdateAll00);
     tolua_function(tolua_S,"AddDynamicEffect",tolua_Core_Core_Effects_CParticleEffect_AddDynamicEffect00);
     tolua_function(tolua_S,"GetTimer",tolua_Core_Core_Effects_CParticleEffect_GetTimer00);
     tolua_function(tolua_S,"SetTimer",tolua_Core_Core_Effects_CParticleEffect_SetTimer00);
     tolua_function(tolua_S,"SetPosition",tolua_Core_Core_Effects_CParticleEffect_SetPosition00);
     tolua_function(tolua_S,"SetPosition",tolua_Core_Core_Effects_CParticleEffect_SetPosition01);
     tolua_variable(tolua_S,"LabelName",tolua_get_Core__Effects__CParticleEffect_LabelName,tolua_set_Core__Effects__CParticleEffect_LabelName);
     tolua_variable(tolua_S,"ParticleName",tolua_get_Core__Effects__CParticleEffect_ParticleName,tolua_set_Core__Effects__CParticleEffect_ParticleName);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CPostEffect","Core::Effects::CPostEffect","",tolua_collect_Core__Effects__CPostEffect);
    #else
    tolua_cclass(tolua_S,"CPostEffect","Core::Effects::CPostEffect","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CPostEffect");
     tolua_function(tolua_S,"RegisterPostEffect",tolua_Core_Core_Effects_CPostEffect_RegisterPostEffect00);
     tolua_function(tolua_S,"SetEnabled",tolua_Core_Core_Effects_CPostEffect_SetEnabled00);
     tolua_function(tolua_S,"GetName",tolua_Core_Core_Effects_CPostEffect_GetName00);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CEffectsManager","Core::Effects::CEffectsManager","",tolua_collect_Core__Effects__CEffectsManager);
    #else
    tolua_cclass(tolua_S,"CEffectsManager","Core::Effects::CEffectsManager","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CEffectsManager");
     tolua_function(tolua_S,"Instance",tolua_Core_Core_Effects_CEffectsManager_Instance00);
     tolua_function(tolua_S,"delete",tolua_Core_Core_Effects_CEffectsManager_delete00);
     tolua_function(tolua_S,"TogglePostEffects",tolua_Core_Core_Effects_CEffectsManager_TogglePostEffects00);
     tolua_function(tolua_S,"GetPostEffect",tolua_Core_Core_Effects_CEffectsManager_GetPostEffect00);
     tolua_function(tolua_S,"CreateParticle",tolua_Core_Core_Effects_CEffectsManager_CreateParticle00);
     tolua_function(tolua_S,"GetParticle",tolua_Core_Core_Effects_CEffectsManager_GetParticle00);
     tolua_function(tolua_S,"Update",tolua_Core_Core_Effects_CEffectsManager_Update00);
     tolua_function(tolua_S,"ReInit",tolua_Core_Core_Effects_CEffectsManager_ReInit00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Effects",0);
   tolua_beginmodule(tolua_S,"Effects");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CEntityEffect","Core::Effects::CEntityEffect","",tolua_collect_Core__Effects__CEntityEffect);
    #else
    tolua_cclass(tolua_S,"CEntityEffect","Core::Effects::CEntityEffect","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CEntityEffect");
     tolua_function(tolua_S,"AddEffectToGameObject",tolua_Core_Core_Effects_CEntityEffect_AddEffectToGameObject00);
     tolua_function(tolua_S,"RemoveEffectFromGameObject",tolua_Core_Core_Effects_CEntityEffect_RemoveEffectFromGameObject00);
     tolua_function(tolua_S,"GetName",tolua_Core_Core_Effects_CEntityEffect_GetName00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CGameManager","Core::CGameManager","",tolua_collect_Core__CGameManager);
   #else
   tolua_cclass(tolua_S,"CGameManager","Core::CGameManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CGameManager");
    tolua_variable(tolua_S,"isSupportShaders",tolua_get_Core__CGameManager_isSupportShaders,tolua_set_Core__CGameManager_isSupportShaders);
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CGameManager_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CGameManager_delete00);
    tolua_function(tolua_S,"GetEngineDevice",tolua_Core_Core_CGameManager_GetEngineDevice00);
    tolua_function(tolua_S,"GetSceneManager",tolua_Core_Core_CGameManager_GetSceneManager00);
    tolua_function(tolua_S,"GetRenderWindow",tolua_Core_Core_CGameManager_GetRenderWindow00);
    tolua_function(tolua_S,"GetTimer",tolua_Core_Core_CGameManager_GetTimer00);
    tolua_function(tolua_S,"GetVideoDeviceType",tolua_Core_Core_CGameManager_GetVideoDeviceType00);
    tolua_function(tolua_S,"SetEngineDevice",tolua_Core_Core_CGameManager_SetEngineDevice00);
    tolua_function(tolua_S,"SetSceneManager",tolua_Core_Core_CGameManager_SetSceneManager00);
    tolua_function(tolua_S,"SetRenderWindow",tolua_Core_Core_CGameManager_SetRenderWindow00);
    tolua_function(tolua_S,"SetQuit",tolua_Core_Core_CGameManager_SetQuit00);
    tolua_function(tolua_S,"GetQuit",tolua_Core_Core_CGameManager_GetQuit00);
    tolua_function(tolua_S,"UpdateGame",tolua_Core_Core_CGameManager_UpdateGame00);
    tolua_function(tolua_S,"Shutdown",tolua_Core_Core_CGameManager_Shutdown00);
    tolua_function(tolua_S,"GetConsoleVisible",tolua_Core_Core_CGameManager_GetConsoleVisible00);
    tolua_function(tolua_S,"SetConsoleVisible",tolua_Core_Core_CGameManager_SetConsoleVisible00);
    tolua_function(tolua_S,"AddResourceArchive",tolua_Core_Core_CGameManager_AddResourceArchive00);
    tolua_function(tolua_S,"RemoveResourceArchive",tolua_Core_Core_CGameManager_RemoveResourceArchive00);
    tolua_function(tolua_S,"SaveGame",tolua_Core_Core_CGameManager_SaveGame00);
    tolua_function(tolua_S,"SetStaticData",tolua_Core_Core_CGameManager_SetStaticData00);
    tolua_function(tolua_S,"GetStaticData",tolua_Core_Core_CGameManager_GetStaticData00);
    tolua_function(tolua_S,"SetBaseResourceName",tolua_Core_Core_CGameManager_SetBaseResourceName00);
    tolua_function(tolua_S,"SetBaseAudioResourceName",tolua_Core_Core_CGameManager_SetBaseAudioResourceName00);
    tolua_function(tolua_S,"GetBaseResourceName",tolua_Core_Core_CGameManager_GetBaseResourceName00);
    tolua_function(tolua_S,"GetBaseAudioResourceName",tolua_Core_Core_CGameManager_GetBaseAudioResourceName00);
    tolua_function(tolua_S,"GetScriptPath",tolua_Core_Core_CGameManager_GetScriptPath00);
    tolua_function(tolua_S,"CreateScene",tolua_Core_Core_CGameManager_CreateScene00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CInputManager","Core::CInputManager","OIS::KeyListener",tolua_collect_Core__CInputManager);
   #else
   tolua_cclass(tolua_S,"CInputManager","Core::CInputManager","OIS::KeyListener",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CInputManager");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CInputManager_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CInputManager_delete00);
    tolua_function(tolua_S,"Initialise",tolua_Core_Core_CInputManager_Initialise00);
    tolua_function(tolua_S,"Capture",tolua_Core_Core_CInputManager_Capture00);
    tolua_function(tolua_S,"AddKeyListener",tolua_Core_Core_CInputManager_AddKeyListener00);
    tolua_function(tolua_S,"AddMouseListener",tolua_Core_Core_CInputManager_AddMouseListener00);
    tolua_function(tolua_S,"AddJoystickListener",tolua_Core_Core_CInputManager_AddJoystickListener00);
    tolua_function(tolua_S,"RemoveKeyListener",tolua_Core_Core_CInputManager_RemoveKeyListener00);
    tolua_function(tolua_S,"RemoveMouseListener",tolua_Core_Core_CInputManager_RemoveMouseListener00);
    tolua_function(tolua_S,"RemoveJoystickListener",tolua_Core_Core_CInputManager_RemoveJoystickListener00);
    tolua_function(tolua_S,"RemoveKeyListener",tolua_Core_Core_CInputManager_RemoveKeyListener01);
    tolua_function(tolua_S,"RemoveMouseListener",tolua_Core_Core_CInputManager_RemoveMouseListener01);
    tolua_function(tolua_S,"RemoveJoystickListener",tolua_Core_Core_CInputManager_RemoveJoystickListener01);
    tolua_function(tolua_S,"RemoveAllListeners",tolua_Core_Core_CInputManager_RemoveAllListeners00);
    tolua_function(tolua_S,"RemoveAllKeyListeners",tolua_Core_Core_CInputManager_RemoveAllKeyListeners00);
    tolua_function(tolua_S,"RemoveAllMouseListeners",tolua_Core_Core_CInputManager_RemoveAllMouseListeners00);
    tolua_function(tolua_S,"RemoveAllJoystickListeners",tolua_Core_Core_CInputManager_RemoveAllJoystickListeners00);
    tolua_function(tolua_S,"Shutdown",tolua_Core_Core_CInputManager_Shutdown00);
    tolua_function(tolua_S,"ResizeWindow",tolua_Core_Core_CInputManager_ResizeWindow00);
    tolua_function(tolua_S,"SetWindowExtents",tolua_Core_Core_CInputManager_SetWindowExtents00);
    tolua_function(tolua_S,"GetMouse",tolua_Core_Core_CInputManager_GetMouse00);
    tolua_function(tolua_S,"GetKeyboard",tolua_Core_Core_CInputManager_GetKeyboard00);
    tolua_function(tolua_S,"GetJoystick",tolua_Core_Core_CInputManager_GetJoystick00);
    tolua_function(tolua_S,"GetNumOfJoysticks",tolua_Core_Core_CInputManager_GetNumOfJoysticks00);
    tolua_variable(tolua_S,"__OIS__MouseListener__",tolua_get_Core__CInputManager___OIS__MouseListener__,NULL);
    tolua_variable(tolua_S,"__OIS__JoyStickListener__",tolua_get_Core__CInputManager___OIS__JoyStickListener__,NULL);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CGameState","Core::CGameState","",tolua_collect_Core__CGameState);
   #else
   tolua_cclass(tolua_S,"CGameState","Core::CGameState","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CGameState");
    tolua_function(tolua_S,"Update",tolua_Core_Core_CGameState_Update00);
    tolua_function(tolua_S,"Load",tolua_Core_Core_CGameState_Load00);
    tolua_function(tolua_S,"End",tolua_Core_Core_CGameState_End00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CGame","Core::CGame","",tolua_collect_Core__CGame);
   #else
   tolua_cclass(tolua_S,"CGame","Core::CGame","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CGame");
    tolua_function(tolua_S,"new",tolua_Core_Core_CGame_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CGame_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CGame_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CGame_delete00);
    tolua_function(tolua_S,"Run",tolua_Core_Core_CGame_Run00);
    tolua_function(tolua_S,"AddGameState",tolua_Core_Core_CGame_AddGameState00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_cclass(tolua_S,"CConfiguration","Core::CConfiguration","",NULL);
   tolua_beginmodule(tolua_S,"CConfiguration");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CGameObjectManager","Core::CGameObjectManager","",tolua_collect_Core__CGameObjectManager);
   #else
   tolua_cclass(tolua_S,"CGameObjectManager","Core::CGameObjectManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CGameObjectManager");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CGameObjectManager_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CGameObjectManager_delete00);
    tolua_function(tolua_S,"CreateObject",tolua_Core_Core_CGameObjectManager_CreateObject00);
    tolua_function(tolua_S,"CreateObject",tolua_Core_Core_CGameObjectManager_CreateObject01);
    tolua_function(tolua_S,"CreateCustomObject",tolua_Core_Core_CGameObjectManager_CreateCustomObject00);
    tolua_function(tolua_S,"CreateCustomObject",tolua_Core_Core_CGameObjectManager_CreateCustomObject01);
    tolua_function(tolua_S,"GetGameObject",tolua_Core_Core_CGameObjectManager_GetGameObject00);
    tolua_function(tolua_S,"GetGameObject",tolua_Core_Core_CGameObjectManager_GetGameObject01);
    tolua_function(tolua_S,"GetGameObjectByEntityName",tolua_Core_Core_CGameObjectManager_GetGameObjectByEntityName00);
    tolua_function(tolua_S,"SetGameObjectUpdatable",tolua_Core_Core_CGameObjectManager_SetGameObjectUpdatable00);
    tolua_function(tolua_S,"GetGameObjects",tolua_Core_Core_CGameObjectManager_GetGameObjects00);
    tolua_function(tolua_S,"GetAllObjectTypes",tolua_Core_Core_CGameObjectManager_GetAllObjectTypes00);
    tolua_function(tolua_S,"RemoveGameObject",tolua_Core_Core_CGameObjectManager_RemoveGameObject00);
    tolua_function(tolua_S,"CreatePlayer",tolua_Core_Core_CGameObjectManager_CreatePlayer00);
    tolua_function(tolua_S,"CreateCustomPlayer",tolua_Core_Core_CGameObjectManager_CreateCustomPlayer00);
    tolua_function(tolua_S,"AddCustomPlayer",tolua_Core_Core_CGameObjectManager_AddCustomPlayer00);
    tolua_function(tolua_S,"RemovePlayer",tolua_Core_Core_CGameObjectManager_RemovePlayer00);
    tolua_function(tolua_S,"RemoveAllPlayers",tolua_Core_Core_CGameObjectManager_RemoveAllPlayers00);
    tolua_function(tolua_S,"GetTeam",tolua_Core_Core_CGameObjectManager_GetTeam00);
    tolua_function(tolua_S,"GetAllPlayers",tolua_Core_Core_CGameObjectManager_GetAllPlayers00);
    tolua_function(tolua_S,"GetPlayerTypes",tolua_Core_Core_CGameObjectManager_GetPlayerTypes00);
    tolua_function(tolua_S,"GetHumanPlayer",tolua_Core_Core_CGameObjectManager_GetHumanPlayer00);
    tolua_function(tolua_S,"GetPlayerByName",tolua_Core_Core_CGameObjectManager_GetPlayerByName00);
    tolua_function(tolua_S,"GetPlayerByEntityName",tolua_Core_Core_CGameObjectManager_GetPlayerByEntityName00);
    tolua_function(tolua_S,"GetClosestVisibleEnemy",tolua_Core_Core_CGameObjectManager_GetClosestVisibleEnemy00);
    tolua_function(tolua_S,"GetClosestEnemy",tolua_Core_Core_CGameObjectManager_GetClosestEnemy00);
    tolua_function(tolua_S,"SetHumanPlayer",tolua_Core_Core_CGameObjectManager_SetHumanPlayer00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CGameObjectManager_Update00);
    tolua_function(tolua_S,"Shutdown",tolua_Core_Core_CGameObjectManager_Shutdown00);
    tolua_function(tolua_S,"Restart",tolua_Core_Core_CGameObjectManager_Restart00);
    tolua_function(tolua_S,"AddSphereObstacle",tolua_Core_Core_CGameObjectManager_AddSphereObstacle00);
    tolua_function(tolua_S,"AddBoxObstacle",tolua_Core_Core_CGameObjectManager_AddBoxObstacle00);
    tolua_function(tolua_S,"GetObstacles",tolua_Core_Core_CGameObjectManager_GetObstacles00);
    tolua_function(tolua_S,"GetSphereObstacles",tolua_Core_Core_CGameObjectManager_GetSphereObstacles00);
    tolua_function(tolua_S,"RemoveObstacle",tolua_Core_Core_CGameObjectManager_RemoveObstacle00);
    tolua_function(tolua_S,"AddWall",tolua_Core_Core_CGameObjectManager_AddWall00);
    tolua_function(tolua_S,"GetWalls",tolua_Core_Core_CGameObjectManager_GetWalls00);
    tolua_function(tolua_S,"RemoveWalls",tolua_Core_Core_CGameObjectManager_RemoveWalls00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CItemsManager","Core::CItemsManager","",tolua_collect_Core__CItemsManager);
   #else
   tolua_cclass(tolua_S,"CItemsManager","Core::CItemsManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CItemsManager");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CItemsManager_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CItemsManager_delete00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CItemsManager_Update00);
    tolua_function(tolua_S,"Pickup",tolua_Core_Core_CItemsManager_Pickup00);
    tolua_function(tolua_S,"PickupUnplaced",tolua_Core_Core_CItemsManager_PickupUnplaced00);
    tolua_function(tolua_S,"AddProfile",tolua_Core_Core_CItemsManager_AddProfile00);
    tolua_function(tolua_S,"PlaceItem",tolua_Core_Core_CItemsManager_PlaceItem00);
    tolua_function(tolua_S,"GetItemProfiles",tolua_Core_Core_CItemsManager_GetItemProfiles00);
    tolua_function(tolua_S,"GetItemProfile",tolua_Core_Core_CItemsManager_GetItemProfile00);
    tolua_function(tolua_S,"GetPlacedItems",tolua_Core_Core_CItemsManager_GetPlacedItems00);
    tolua_function(tolua_S,"Shutdown",tolua_Core_Core_CItemsManager_Shutdown00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CBillboardManager","Core::CBillboardManager","",NULL);
   tolua_beginmodule(tolua_S,"CBillboardManager");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CFrameListenerFramework","Core::CFrameListenerFramework","",NULL);
   tolua_beginmodule(tolua_S,"CFrameListenerFramework");
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Effects",0);
   tolua_beginmodule(tolua_S,"Effects");
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Nature",0);
   tolua_beginmodule(tolua_S,"Nature");
    tolua_cclass(tolua_S,"CNatureManager","Core::Nature::CNatureManager","",NULL);
    tolua_beginmodule(tolua_S,"CNatureManager");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    tolua_cclass(tolua_S,"IPhysicsStrategy","Core::Physics::IPhysicsStrategy","",NULL);
    tolua_beginmodule(tolua_S,"IPhysicsStrategy");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CPhysicsProfile","Core::Physics::CPhysicsProfile","",tolua_collect_Core__Physics__CPhysicsProfile);
    #else
    tolua_cclass(tolua_S,"CPhysicsProfile","Core::Physics::CPhysicsProfile","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CPhysicsProfile");
     tolua_function(tolua_S,"new",tolua_Core_Core_Physics_CPhysicsProfile_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_Physics_CPhysicsProfile_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_Physics_CPhysicsProfile_new00_local);
     tolua_variable(tolua_S,"Shape",tolua_get_Core__Physics__CPhysicsProfile_Shape,tolua_set_Core__Physics__CPhysicsProfile_Shape);
     tolua_variable(tolua_S,"BodyType",tolua_get_Core__Physics__CPhysicsProfile_BodyType,tolua_set_Core__Physics__CPhysicsProfile_BodyType);
     tolua_variable(tolua_S,"Friction",tolua_get_Core__Physics__CPhysicsProfile_Friction,tolua_set_Core__Physics__CPhysicsProfile_Friction);
     tolua_variable(tolua_S,"Mass",tolua_get_Core__Physics__CPhysicsProfile_Mass,tolua_set_Core__Physics__CPhysicsProfile_Mass);
     tolua_variable(tolua_S,"Density",tolua_get_Core__Physics__CPhysicsProfile_Density,tolua_set_Core__Physics__CPhysicsProfile_Density);
     tolua_variable(tolua_S,"Radius",tolua_get_Core__Physics__CPhysicsProfile_Radius,tolua_set_Core__Physics__CPhysicsProfile_Radius);
     tolua_variable(tolua_S,"Size",tolua_get_Core__Physics__CPhysicsProfile_Size,tolua_set_Core__Physics__CPhysicsProfile_Size);
     tolua_variable(tolua_S,"Direction",tolua_get_Core__Physics__CPhysicsProfile_Direction,tolua_set_Core__Physics__CPhysicsProfile_Direction);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"OIS",0);
  tolua_beginmodule(tolua_S,"OIS");
   tolua_cclass(tolua_S,"Mouse","OIS::Mouse","",NULL);
   tolua_beginmodule(tolua_S,"Mouse");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Keyboard","OIS::Keyboard","",NULL);
   tolua_beginmodule(tolua_S,"Keyboard");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"SceneLoader",0);
   tolua_beginmodule(tolua_S,"SceneLoader");
    tolua_cclass(tolua_S,"CSerializer","Core::SceneLoader::CSerializer","",NULL);
    tolua_beginmodule(tolua_S,"CSerializer");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"AI",0);
   tolua_beginmodule(tolua_S,"AI");
    tolua_cclass(tolua_S,"CFpsVehicle","Core::AI::CFpsVehicle","",NULL);
    tolua_beginmodule(tolua_S,"CFpsVehicle");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"Obstacle","Core::AI::Obstacle","",NULL);
    tolua_beginmodule(tolua_S,"Obstacle");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"SphereObstacle","Core::AI::SphereObstacle","",NULL);
    tolua_beginmodule(tolua_S,"SphereObstacle");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"BoxObstacle","Core::AI::BoxObstacle","",NULL);
    tolua_beginmodule(tolua_S,"BoxObstacle");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"Wall","Core::AI::Wall","",NULL);
    tolua_beginmodule(tolua_S,"Wall");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Plugin",0);
   tolua_beginmodule(tolua_S,"Plugin");
    tolua_cclass(tolua_S,"IGameObjectFactory","Core::Plugin::IGameObjectFactory","",NULL);
    tolua_beginmodule(tolua_S,"IGameObjectFactory");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Sound",0);
  tolua_beginmodule(tolua_S,"Sound");
   tolua_cclass(tolua_S,"CSoundManager","Sound::CSoundManager","",NULL);
   tolua_beginmodule(tolua_S,"CSoundManager");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"MyGUI",0);
  tolua_beginmodule(tolua_S,"MyGUI");
   tolua_cclass(tolua_S,"OgrePlatform","MyGUI::OgrePlatform","",NULL);
   tolua_beginmodule(tolua_S,"OgrePlatform");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"GUI",0);
   tolua_beginmodule(tolua_S,"GUI");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CGuiManager","Core::GUI::CGuiManager","",tolua_collect_Core__GUI__CGuiManager);
    #else
    tolua_cclass(tolua_S,"CGuiManager","Core::GUI::CGuiManager","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CGuiManager");
     tolua_function(tolua_S,"Instance",tolua_Core_Core_GUI_CGuiManager_Instance00);
     tolua_function(tolua_S,"delete",tolua_Core_Core_GUI_CGuiManager_delete00);
     tolua_function(tolua_S,"GetStrategy",tolua_Core_Core_GUI_CGuiManager_GetStrategy00);
     tolua_function(tolua_S,"DeleteStrategy",tolua_Core_Core_GUI_CGuiManager_DeleteStrategy00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"MyGUI",0);
  tolua_beginmodule(tolua_S,"MyGUI");
   tolua_cclass(tolua_S,"Gui","MyGUI::Gui","",NULL);
   tolua_beginmodule(tolua_S,"Gui");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"GUI",0);
   tolua_beginmodule(tolua_S,"GUI");
    tolua_cclass(tolua_S,"CBaseLayout_MyGui","Core::GUI::CBaseLayout_MyGui","",NULL);
    tolua_beginmodule(tolua_S,"CBaseLayout_MyGui");
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CGuiStrategy_MyGui","Core::GUI::CGuiStrategy_MyGui","IGuiStrategy",tolua_collect_Core__GUI__CGuiStrategy_MyGui);
    #else
    tolua_cclass(tolua_S,"CGuiStrategy_MyGui","Core::GUI::CGuiStrategy_MyGui","IGuiStrategy",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CGuiStrategy_MyGui");
     tolua_function(tolua_S,"new",tolua_Core_Core_GUI_CGuiStrategy_MyGui_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_GUI_CGuiStrategy_MyGui_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_GUI_CGuiStrategy_MyGui_new00_local);
     tolua_function(tolua_S,"delete",tolua_Core_Core_GUI_CGuiStrategy_MyGui_delete00);
     tolua_function(tolua_S,"Initialize",tolua_Core_Core_GUI_CGuiStrategy_MyGui_Initialize00);
     tolua_function(tolua_S,"Shutdown",tolua_Core_Core_GUI_CGuiStrategy_MyGui_Shutdown00);
     tolua_function(tolua_S,"Activate",tolua_Core_Core_GUI_CGuiStrategy_MyGui_Activate00);
     tolua_function(tolua_S,"Desactivate",tolua_Core_Core_GUI_CGuiStrategy_MyGui_Desactivate00);
     tolua_function(tolua_S,"SetCursorPosition",tolua_Core_Core_GUI_CGuiStrategy_MyGui_SetCursorPosition00);
     tolua_function(tolua_S,"LoadLayout",tolua_Core_Core_GUI_CGuiStrategy_MyGui_LoadLayout00);
     tolua_function(tolua_S,"FrameStarted",tolua_Core_Core_GUI_CGuiStrategy_MyGui_FrameStarted00);
     tolua_function(tolua_S,"FrameEnded",tolua_Core_Core_GUI_CGuiStrategy_MyGui_FrameEnded00);
     tolua_function(tolua_S,"MouseMoved",tolua_Core_Core_GUI_CGuiStrategy_MyGui_MouseMoved00);
     tolua_function(tolua_S,"MousePressed",tolua_Core_Core_GUI_CGuiStrategy_MyGui_MousePressed00);
     tolua_function(tolua_S,"MouseReleased",tolua_Core_Core_GUI_CGuiStrategy_MyGui_MouseReleased00);
     tolua_function(tolua_S,"KeyPressed",tolua_Core_Core_GUI_CGuiStrategy_MyGui_KeyPressed00);
     tolua_function(tolua_S,"KeyReleased",tolua_Core_Core_GUI_CGuiStrategy_MyGui_KeyReleased00);
     tolua_function(tolua_S,"GetStrategyType",tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetStrategyType00);
     tolua_function(tolua_S,"GetGui",tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetGui00);
     tolua_function(tolua_S,"GetBaseLayout",tolua_Core_Core_GUI_CGuiStrategy_MyGui_GetBaseLayout00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_cclass(tolua_S,"CItemProfile","Core::CItemProfile","",NULL);
   tolua_beginmodule(tolua_S,"CItemProfile");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"IInventoryItem","Core::IInventoryItem","",NULL);
   tolua_beginmodule(tolua_S,"IInventoryItem");
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"OgreSpecific",0);
   tolua_beginmodule(tolua_S,"OgreSpecific");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CLoadingScreen","Core::OgreSpecific::CLoadingScreen","ResourceGroupListener",tolua_collect_Core__OgreSpecific__CLoadingScreen);
    #else
    tolua_cclass(tolua_S,"CLoadingScreen","Core::OgreSpecific::CLoadingScreen","ResourceGroupListener",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CLoadingScreen");
     tolua_function(tolua_S,"new",tolua_Core_Core_OgreSpecific_CLoadingScreen_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_OgreSpecific_CLoadingScreen_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_OgreSpecific_CLoadingScreen_new00_local);
     tolua_function(tolua_S,"delete",tolua_Core_Core_OgreSpecific_CLoadingScreen_delete00);
     tolua_function(tolua_S,"Start",tolua_Core_Core_OgreSpecific_CLoadingScreen_Start00);
     tolua_function(tolua_S,"Finish",tolua_Core_Core_OgreSpecific_CLoadingScreen_Finish00);
     tolua_function(tolua_S,"resourceGroupScriptingStarted",tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupScriptingStarted00);
     tolua_function(tolua_S,"scriptParseStarted",tolua_Core_Core_OgreSpecific_CLoadingScreen_scriptParseStarted00);
     tolua_function(tolua_S,"scriptParseEnded",tolua_Core_Core_OgreSpecific_CLoadingScreen_scriptParseEnded00);
     tolua_function(tolua_S,"resourceGroupScriptingEnded",tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupScriptingEnded00);
     tolua_function(tolua_S,"resourceGroupLoadStarted",tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupLoadStarted00);
     tolua_function(tolua_S,"resourceLoadStarted",tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceLoadStarted00);
     tolua_function(tolua_S,"resourceLoadEnded",tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceLoadEnded00);
     tolua_function(tolua_S,"worldGeometryStageStarted",tolua_Core_Core_OgreSpecific_CLoadingScreen_worldGeometryStageStarted00);
     tolua_function(tolua_S,"worldGeometryStageEnded",tolua_Core_Core_OgreSpecific_CLoadingScreen_worldGeometryStageEnded00);
     tolua_function(tolua_S,"resourceGroupLoadEnded",tolua_Core_Core_OgreSpecific_CLoadingScreen_resourceGroupLoadEnded00);
     tolua_function(tolua_S,"ResourceLoading",tolua_Core_Core_OgreSpecific_CLoadingScreen_ResourceLoading00);
     tolua_function(tolua_S,"ResourceCollision",tolua_Core_Core_OgreSpecific_CLoadingScreen_ResourceCollision00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"OIS",0);
  tolua_beginmodule(tolua_S,"OIS");
   tolua_cclass(tolua_S,"KeyEvent","OIS::KeyEvent","",NULL);
   tolua_beginmodule(tolua_S,"KeyEvent");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_cclass(tolua_S,"CLuaInterpreter","Core::CLuaInterpreter","",NULL);
   tolua_beginmodule(tolua_S,"CLuaInterpreter");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CEditString","Core::CEditString","",NULL);
   tolua_beginmodule(tolua_S,"CEditString");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CLuaConsole","Core::CLuaConsole","Ogre::FrameListener",tolua_collect_Core__CLuaConsole);
   #else
   tolua_cclass(tolua_S,"CLuaConsole","Core::CLuaConsole","Ogre::FrameListener",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CLuaConsole");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CLuaConsole_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CLuaConsole_delete00);
    tolua_function(tolua_S,"Shutdown",tolua_Core_Core_CLuaConsole_Shutdown00);
    tolua_function(tolua_S,"SetVisible",tolua_Core_Core_CLuaConsole_SetVisible00);
    tolua_function(tolua_S,"IsVisible",tolua_Core_Core_CLuaConsole_IsVisible00);
    tolua_function(tolua_S,"Print",tolua_Core_Core_CLuaConsole_Print00);
    tolua_function(tolua_S,"OnKeyPressed",tolua_Core_Core_CLuaConsole_OnKeyPressed00);
    tolua_function(tolua_S,"frameStarted",tolua_Core_Core_CLuaConsole_frameStarted00);
    tolua_function(tolua_S,"frameEnded",tolua_Core_Core_CLuaConsole_frameEnded00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CWeapon","Core::CWeapon","Core::IInventoryItem",tolua_collect_Core__CWeapon);
   #else
   tolua_cclass(tolua_S,"CWeapon","Core::CWeapon","Core::IInventoryItem",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CWeapon");
    tolua_function(tolua_S,"new",tolua_Core_Core_CWeapon_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CWeapon_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CWeapon_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CWeapon_delete00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CWeapon_Update00);
    tolua_function(tolua_S,"PickedUp",tolua_Core_Core_CWeapon_PickedUp00);
    tolua_function(tolua_S,"ShowSight",tolua_Core_Core_CWeapon_ShowSight00);
    tolua_function(tolua_S,"SetUsed",tolua_Core_Core_CWeapon_SetUsed00);
    tolua_function(tolua_S,"Use",tolua_Core_Core_CWeapon_Use00);
    tolua_function(tolua_S,"GetRange",tolua_Core_Core_CWeapon_GetRange00);
    tolua_function(tolua_S,"GetMagazine",tolua_Core_Core_CWeapon_GetMagazine00);
    tolua_function(tolua_S,"SetMagazine",tolua_Core_Core_CWeapon_SetMagazine00);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CProjectile","Core::CProjectile","",tolua_collect_Core__CProjectile);
   #else
   tolua_cclass(tolua_S,"CProjectile","Core::CProjectile","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CProjectile");
    tolua_function(tolua_S,"new",tolua_Core_Core_CProjectile_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CProjectile_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CProjectile_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CProjectile_delete00);
    tolua_function(tolua_S,"Shoot",tolua_Core_Core_CProjectile_Shoot00);
    tolua_function(tolua_S,"Update",tolua_Core_Core_CProjectile_Update00);
    tolua_function(tolua_S,"GetDamage",tolua_Core_Core_CProjectile_GetDamage00);
    tolua_function(tolua_S,"GetOwner",tolua_Core_Core_CProjectile_GetOwner00);
    tolua_function(tolua_S,"GetWeapon",tolua_Core_Core_CProjectile_GetWeapon00);
    tolua_variable(tolua_S,"isAlive",tolua_get_Core__CProjectile_isAlive,tolua_set_Core__CProjectile_isAlive);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CMagazineProfile","Core::CMagazineProfile","Core::CItemProfile",tolua_collect_Core__CMagazineProfile);
   #else
   tolua_cclass(tolua_S,"CMagazineProfile","Core::CMagazineProfile","Core::CItemProfile",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CMagazineProfile");
    tolua_function(tolua_S,"new",tolua_Core_Core_CMagazineProfile_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CMagazineProfile_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CMagazineProfile_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CMagazineProfile_delete00);
    tolua_variable(tolua_S,"Capacity",tolua_get_Core__CMagazineProfile_unsigned_Capacity,tolua_set_Core__CMagazineProfile_unsigned_Capacity);
    tolua_variable(tolua_S,"Desc",tolua_get_Core__CMagazineProfile_Desc,NULL);
    tolua_variable(tolua_S,"MeshName",tolua_get_Core__CMagazineProfile_MeshName,NULL);
    tolua_variable(tolua_S,"ProjectileProfile",tolua_get_Core__CMagazineProfile_ProjectileProfile_ptr,tolua_set_Core__CMagazineProfile_ProjectileProfile_ptr);
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CMagazine","Core::CMagazine","",tolua_collect_Core__CMagazine);
   #else
   tolua_cclass(tolua_S,"CMagazine","Core::CMagazine","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CMagazine");
    tolua_function(tolua_S,"new",tolua_Core_Core_CMagazine_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CMagazine_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CMagazine_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CMagazine_delete00);
    tolua_function(tolua_S,"Fire",tolua_Core_Core_CMagazine_Fire00);
    tolua_function(tolua_S,"RemoveProjectile",tolua_Core_Core_CMagazine_RemoveProjectile00);
    tolua_function(tolua_S,"GetProjectiles",tolua_Core_Core_CMagazine_GetProjectiles00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CProjectileProfile","Core::CProjectileProfile","Core::CItemProfile",tolua_collect_Core__CProjectileProfile);
   #else
   tolua_cclass(tolua_S,"CProjectileProfile","Core::CProjectileProfile","Core::CItemProfile",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CProjectileProfile");
    tolua_function(tolua_S,"new",tolua_Core_Core_CProjectileProfile_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CProjectileProfile_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CProjectileProfile_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CProjectileProfile_delete00);
    tolua_variable(tolua_S,"Damage",tolua_get_Core__CProjectileProfile_Damage,tolua_set_Core__CProjectileProfile_Damage);
    tolua_variable(tolua_S,"Speed",tolua_get_Core__CProjectileProfile_Speed,tolua_set_Core__CProjectileProfile_Speed);
    tolua_variable(tolua_S,"Disc",tolua_get_Core__CProjectileProfile_Disc,NULL);
    tolua_variable(tolua_S,"MeshName",tolua_get_Core__CProjectileProfile_MeshName,NULL);
    tolua_variable(tolua_S,"BillboardBullet",tolua_get_Core__CProjectileProfile_BillboardBullet,NULL);
    tolua_variable(tolua_S,"BillboardFlash",tolua_get_Core__CProjectileProfile_BillboardFlash,NULL);
    tolua_variable(tolua_S,"isPenetrate",tolua_get_Core__CProjectileProfile_isPenetrate,tolua_set_Core__CProjectileProfile_isPenetrate);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_cclass(tolua_S,"CMenuState","Core::CMenuState","Core::CGameState",NULL);
   tolua_beginmodule(tolua_S,"CMenuState");
    tolua_function(tolua_S,"keyPressed",tolua_Core_Core_CMenuState_keyPressed00);
    tolua_function(tolua_S,"keyReleased",tolua_Core_Core_CMenuState_keyReleased00);
    tolua_function(tolua_S,"mouseMoved",tolua_Core_Core_CMenuState_mouseMoved00);
    tolua_function(tolua_S,"mousePressed",tolua_Core_Core_CMenuState_mousePressed00);
    tolua_function(tolua_S,"mouseReleased",tolua_Core_Core_CMenuState_mouseReleased00);
    tolua_function(tolua_S,"frameRenderingQueued",tolua_Core_Core_CMenuState_frameRenderingQueued00);
    tolua_function(tolua_S,"frameEnded",tolua_Core_Core_CMenuState_frameEnded00);
    tolua_variable(tolua_S,"__FrameListener__",tolua_get_Core__CMenuState___FrameListener__,NULL);
    tolua_variable(tolua_S,"__WindowEventListener__",tolua_get_Core__CMenuState___WindowEventListener__,NULL);
    tolua_variable(tolua_S,"__OIS__MouseListener__",tolua_get_Core__CMenuState___OIS__MouseListener__,NULL);
    tolua_variable(tolua_S,"__OIS__KeyListener__",tolua_get_Core__CMenuState___OIS__KeyListener__,NULL);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Mission",0);
   tolua_beginmodule(tolua_S,"Mission");
    tolua_cclass(tolua_S,"IMission","Core::Mission::IMission","",NULL);
    tolua_beginmodule(tolua_S,"IMission");
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CMissionEvent","Core::Mission::CMissionEvent","",tolua_collect_Core__Mission__CMissionEvent);
    #else
    tolua_cclass(tolua_S,"CMissionEvent","Core::Mission::CMissionEvent","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CMissionEvent");
     tolua_function(tolua_S,"new",tolua_Core_Core_Mission_CMissionEvent_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_Mission_CMissionEvent_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_Mission_CMissionEvent_new00_local);
     tolua_variable(tolua_S,"Owner",tolua_get_Core__Mission__CMissionEvent_Owner_ptr,tolua_set_Core__Mission__CMissionEvent_Owner_ptr);
     tolua_variable(tolua_S,"Killed",tolua_get_Core__Mission__CMissionEvent_Killed_ptr,tolua_set_Core__Mission__CMissionEvent_Killed_ptr);
     tolua_variable(tolua_S,"Weapon",tolua_get_Core__Mission__CMissionEvent_Weapon_ptr,tolua_set_Core__Mission__CMissionEvent_Weapon_ptr);
     tolua_variable(tolua_S,"Projectile",tolua_get_Core__Mission__CMissionEvent_Projectile_ptr,tolua_set_Core__Mission__CMissionEvent_Projectile_ptr);
     tolua_variable(tolua_S,"UserData",tolua_get_Core__Mission__CMissionEvent_UserData,tolua_set_Core__Mission__CMissionEvent_UserData);
     tolua_variable(tolua_S,"MissionType",tolua_get_Core__Mission__CMissionEvent_MissionType,tolua_set_Core__Mission__CMissionEvent_MissionType);
    tolua_endmodule(tolua_S);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CMissionManager","Core::Mission::CMissionManager","",tolua_collect_Core__Mission__CMissionManager);
    #else
    tolua_cclass(tolua_S,"CMissionManager","Core::Mission::CMissionManager","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CMissionManager");
     tolua_function(tolua_S,"Instance",tolua_Core_Core_Mission_CMissionManager_Instance00);
     tolua_function(tolua_S,"delete",tolua_Core_Core_Mission_CMissionManager_delete00);
     tolua_function(tolua_S,"StartMission",tolua_Core_Core_Mission_CMissionManager_StartMission00);
     tolua_function(tolua_S,"ListAllAvailableMissions",tolua_Core_Core_Mission_CMissionManager_ListAllAvailableMissions00);
     tolua_function(tolua_S,"FindActivePlayerMissions",tolua_Core_Core_Mission_CMissionManager_FindActivePlayerMissions00);
     tolua_function(tolua_S,"Update",tolua_Core_Core_Mission_CMissionManager_Update00);
     tolua_function(tolua_S,"RegisterEvent",tolua_Core_Core_Mission_CMissionManager_RegisterEvent00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"OgreOde",0);
  tolua_beginmodule(tolua_S,"OgreOde");
   tolua_cclass(tolua_S,"Geometry","OgreOde::Geometry","",NULL);
   tolua_beginmodule(tolua_S,"Geometry");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"Body","OgreOde::Body","",NULL);
   tolua_beginmodule(tolua_S,"Body");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    tolua_cclass(tolua_S,"CPhysXBody","Core::Physics::CPhysXBody","",NULL);
    tolua_beginmodule(tolua_S,"CPhysXBody");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",1);
  tolua_beginmodule(tolua_S,"Core");
   tolua_constant(tolua_S,"ECM_CHASE",Core::ECM_CHASE);
   tolua_constant(tolua_S,"ECM_FIXED",Core::ECM_FIXED);
   tolua_constant(tolua_S,"ECM_FPS",Core::ECM_FPS);
   tolua_constant(tolua_S,"ECM_TOP_DOWN",Core::ECM_TOP_DOWN);
   tolua_constant(tolua_S,"ECM_SIDE",Core::ECM_SIDE);
   tolua_constant(tolua_S,"ECM_FREE",Core::ECM_FREE);
   tolua_constant(tolua_S,"ECM_GOD",Core::ECM_GOD);
   tolua_constant(tolua_S,"ECM_RTS",Core::ECM_RTS);
   tolua_constant(tolua_S,"ECM_SPRING",Core::ECM_SPRING);
   tolua_constant(tolua_S,"ECM_CSS",Core::ECM_CSS);
   tolua_constant(tolua_S,"ECM_NONE",Core::ECM_NONE);
   tolua_constant(tolua_S,"SQF_TERRAIN",Core::SQF_TERRAIN);
   tolua_constant(tolua_S,"SQF_PLAYER",Core::SQF_PLAYER);
   tolua_constant(tolua_S,"SQF_WEAPON",Core::SQF_WEAPON);
   tolua_constant(tolua_S,"SQF_TOOL",Core::SQF_TOOL);
   tolua_constant(tolua_S,"SQF_OBSTACLE",Core::SQF_OBSTACLE);
   tolua_constant(tolua_S,"SQF_BUILDING",Core::SQF_BUILDING);
   tolua_constant(tolua_S,"SQF_VEHICLE",Core::SQF_VEHICLE);
   tolua_constant(tolua_S,"SQF_NONE",Core::SQF_NONE);
   tolua_constant(tolua_S,"EDT_NULL",Core::EDT_NULL);
   tolua_constant(tolua_S,"EDT_DIRECT3D9",Core::EDT_DIRECT3D9);
   tolua_constant(tolua_S,"EDT_DIRECT3D10",Core::EDT_DIRECT3D10);
   tolua_constant(tolua_S,"EDT_OPENGL",Core::EDT_OPENGL);
   tolua_constant(tolua_S,"LT_POINT",Core::LT_POINT);
   tolua_constant(tolua_S,"LT_DIRECTIONAL",Core::LT_DIRECTIONAL);
   tolua_constant(tolua_S,"LT_SPOT",Core::LT_SPOT);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CoreEntityObject","Core::CoreEntityObject","",tolua_collect_Core__CoreEntityObject);
   #else
   tolua_cclass(tolua_S,"CoreEntityObject","Core::CoreEntityObject","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CoreEntityObject");
    tolua_function(tolua_S,"new",tolua_Core_Core_CoreEntityObject_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CoreEntityObject_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CoreEntityObject_new00_local);
    tolua_variable(tolua_S,"QueryType",tolua_get_Core__CoreEntityObject_QueryType,tolua_set_Core__CoreEntityObject_QueryType);
    tolua_variable(tolua_S,"Player",tolua_get_Core__CoreEntityObject_Player_ptr,tolua_set_Core__CoreEntityObject_Player_ptr);
    tolua_variable(tolua_S,"Item",tolua_get_Core__CoreEntityObject_Item_ptr,tolua_set_Core__CoreEntityObject_Item_ptr);
   tolua_endmodule(tolua_S);
   tolua_constant(tolua_S,"EAT_NONE",Core::EAT_NONE);
   tolua_constant(tolua_S,"EAT_PICKUP",Core::EAT_PICKUP);
   tolua_constant(tolua_S,"EAT_DANGEROUS",Core::EAT_DANGEROUS);
   tolua_constant(tolua_S,"EAT_NEUTRAL",Core::EAT_NEUTRAL);
   tolua_constant(tolua_S,"EAT_MISSION",Core::EAT_MISSION);
   tolua_constant(tolua_S,"EAT_UNKNOWN",Core::EAT_UNKNOWN);
   tolua_constant(tolua_S,"EAT_EDITOR",Core::EAT_EDITOR);
   tolua_cclass(tolua_S,"SPAWN_POINT","Core::SPAWN_POINT","",NULL);
   tolua_beginmodule(tolua_S,"SPAWN_POINT");
    tolua_variable(tolua_S,"Name",tolua_get_Core__SPAWN_POINT_Name,tolua_set_Core__SPAWN_POINT_Name);
    tolua_variable(tolua_S,"Team",tolua_get_Core__SPAWN_POINT_Team,tolua_set_Core__SPAWN_POINT_Team);
    tolua_variable(tolua_S,"Position",tolua_get_Core__SPAWN_POINT_Position,tolua_set_Core__SPAWN_POINT_Position);
    tolua_variable(tolua_S,"Priority",tolua_get_Core__SPAWN_POINT_Priority,tolua_set_Core__SPAWN_POINT_Priority);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Effects",0);
   tolua_beginmodule(tolua_S,"Effects");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Plugin",0);
   tolua_beginmodule(tolua_S,"Plugin");
    tolua_cclass(tolua_S,"IPhysicsStrategyFactory","Core::Plugin::IPhysicsStrategyFactory","",NULL);
    tolua_beginmodule(tolua_S,"IPhysicsStrategyFactory");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    tolua_cclass(tolua_S,"CPhysicsManager","Core::Physics::CPhysicsManager","",NULL);
    tolua_beginmodule(tolua_S,"CPhysicsManager");
     tolua_function(tolua_S,"Instance",tolua_Core_Core_Physics_CPhysicsManager_Instance00);
     tolua_function(tolua_S,"CreateStrategy",tolua_Core_Core_Physics_CPhysicsManager_CreateStrategy00);
     tolua_function(tolua_S,"GetStrategy",tolua_Core_Core_Physics_CPhysicsManager_GetStrategy00);
     tolua_function(tolua_S,"DeleteStrategy",tolua_Core_Core_Physics_CPhysicsManager_DeleteStrategy00);
     tolua_function(tolua_S,"AddPhysicsProfile",tolua_Core_Core_Physics_CPhysicsManager_AddPhysicsProfile00);
     tolua_function(tolua_S,"GetPhysicsProfileList",tolua_Core_Core_Physics_CPhysicsManager_GetPhysicsProfileList00);
     tolua_function(tolua_S,"GetPhysicsProfile",tolua_Core_Core_Physics_CPhysicsManager_GetPhysicsProfile00);
     tolua_function(tolua_S,"Update",tolua_Core_Core_Physics_CPhysicsManager_Update00);
     tolua_variable(tolua_S,"DEFAULT_LIGHT_CUBE",tolua_get_Core__Physics__CPhysicsManager_DEFAULT_LIGHT_CUBE,NULL);
     tolua_variable(tolua_S,"DEFAULT_MEDIUM_CUBE",tolua_get_Core__Physics__CPhysicsManager_DEFAULT_MEDIUM_CUBE,NULL);
     tolua_variable(tolua_S,"DEFAULT_HEAVY_CUBE",tolua_get_Core__Physics__CPhysicsManager_DEFAULT_HEAVY_CUBE,NULL);
     tolua_variable(tolua_S,"DEFAULT_LIGHT_SPHERE",tolua_get_Core__Physics__CPhysicsManager_DEFAULT_LIGHT_SPHERE,NULL);
     tolua_variable(tolua_S,"DEFAULT_MEDIUM_SPHERE",tolua_get_Core__Physics__CPhysicsManager_DEFAULT_MEDIUM_SPHERE,NULL);
     tolua_variable(tolua_S,"DEFAULT_HEAVY_SPHERE",tolua_get_Core__Physics__CPhysicsManager_DEFAULT_HEAVY_SPHERE,NULL);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",1);
   tolua_beginmodule(tolua_S,"Physics");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"OIS",0);
  tolua_beginmodule(tolua_S,"OIS");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_cclass(tolua_S,"CEnvironmentObserver","Core::CEnvironmentObserver","",NULL);
   tolua_beginmodule(tolua_S,"CEnvironmentObserver");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CPlayerSoundComponent","Core::CPlayerSoundComponent","",tolua_collect_Core__CPlayerSoundComponent);
   #else
   tolua_cclass(tolua_S,"CPlayerSoundComponent","Core::CPlayerSoundComponent","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CPlayerSoundComponent");
    tolua_function(tolua_S,"new",tolua_Core_Core_CPlayerSoundComponent_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CPlayerSoundComponent_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CPlayerSoundComponent_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CPlayerSoundComponent_delete00);
    tolua_function(tolua_S,"SetMove",tolua_Core_Core_CPlayerSoundComponent_SetMove00);
    tolua_function(tolua_S,"SetShot",tolua_Core_Core_CPlayerSoundComponent_SetShot00);
    tolua_function(tolua_S,"SetHolsterIn",tolua_Core_Core_CPlayerSoundComponent_SetHolsterIn00);
    tolua_function(tolua_S,"SetHolsterOut",tolua_Core_Core_CPlayerSoundComponent_SetHolsterOut00);
    tolua_function(tolua_S,"SetReload",tolua_Core_Core_CPlayerSoundComponent_SetReload00);
    tolua_function(tolua_S,"PlayMove",tolua_Core_Core_CPlayerSoundComponent_PlayMove00);
    tolua_function(tolua_S,"PlayShot",tolua_Core_Core_CPlayerSoundComponent_PlayShot00);
    tolua_function(tolua_S,"PlayHolsterIn",tolua_Core_Core_CPlayerSoundComponent_PlayHolsterIn00);
    tolua_function(tolua_S,"PlayHolsterOut",tolua_Core_Core_CPlayerSoundComponent_PlayHolsterOut00);
    tolua_function(tolua_S,"PlayReload",tolua_Core_Core_CPlayerSoundComponent_PlayReload00);
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"CPlayerAttributesComponent","Core::CPlayerAttributesComponent","",NULL);
   tolua_beginmodule(tolua_S,"CPlayerAttributesComponent");
   tolua_endmodule(tolua_S);
   tolua_cclass(tolua_S,"ILineOfSightStrategy","Core::ILineOfSightStrategy","",NULL);
   tolua_beginmodule(tolua_S,"ILineOfSightStrategy");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"SoundToAnimation","Core::SoundToAnimation","",tolua_collect_Core__SoundToAnimation);
   #else
   tolua_cclass(tolua_S,"SoundToAnimation","Core::SoundToAnimation","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"SoundToAnimation");
    tolua_function(tolua_S,"new",tolua_Core_Core_SoundToAnimation_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_SoundToAnimation_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_SoundToAnimation_new00_local);
    tolua_variable(tolua_S,"Animation",tolua_get_Core__SoundToAnimation_Animation,NULL);
    tolua_variable(tolua_S,"AnimSound",tolua_get_Core__SoundToAnimation_AnimSound,NULL);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"AI",0);
   tolua_beginmodule(tolua_S,"AI");
    tolua_cclass(tolua_S,"IAiReactionComponent","Core::AI::IAiReactionComponent","",NULL);
    tolua_beginmodule(tolua_S,"IAiReactionComponent");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    tolua_cclass(tolua_S,"ICharacterController","Core::Physics::ICharacterController","",NULL);
    tolua_beginmodule(tolua_S,"ICharacterController");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"IPhysicsRagdoll","Core::Physics::IPhysicsRagdoll","",NULL);
    tolua_beginmodule(tolua_S,"IPhysicsRagdoll");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"OgreSpecific",0);
   tolua_beginmodule(tolua_S,"OgreSpecific");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"MovableTextOverlay","Core::OgreSpecific::MovableTextOverlay","",tolua_collect_Core__OgreSpecific__MovableTextOverlay);
    #else
    tolua_cclass(tolua_S,"MovableTextOverlay","Core::OgreSpecific::MovableTextOverlay","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"MovableTextOverlay");
     tolua_function(tolua_S,"new",tolua_Core_Core_OgreSpecific_MovableTextOverlay_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_OgreSpecific_MovableTextOverlay_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_OgreSpecific_MovableTextOverlay_new00_local);
     tolua_function(tolua_S,"delete",tolua_Core_Core_OgreSpecific_MovableTextOverlay_delete00);
     tolua_function(tolua_S,"SetCaption",tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetCaption00);
     tolua_function(tolua_S,"SetUpdateFrequency",tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetUpdateFrequency00);
     tolua_function(tolua_S,"SetAttributes",tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetAttributes00);
     tolua_function(tolua_S,"GetName",tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetName00);
     tolua_function(tolua_S,"GetCaption",tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetCaption00);
     tolua_function(tolua_S,"GetUpdateFrequency",tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetUpdateFrequency00);
     tolua_function(tolua_S,"IsOnScreen",tolua_Core_Core_OgreSpecific_MovableTextOverlay_IsOnScreen00);
     tolua_function(tolua_S,"IsEnabled",tolua_Core_Core_OgreSpecific_MovableTextOverlay_IsEnabled00);
     tolua_function(tolua_S,"getAttributes",tolua_Core_Core_OgreSpecific_MovableTextOverlay_getAttributes00);
     tolua_function(tolua_S,"Enable",tolua_Core_Core_OgreSpecific_MovableTextOverlay_Enable00);
     tolua_function(tolua_S,"Update",tolua_Core_Core_OgreSpecific_MovableTextOverlay_Update00);
     tolua_function(tolua_S,"GetPixelsTop",tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsTop00);
     tolua_function(tolua_S,"GetPixelsBottom",tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsBottom00);
     tolua_function(tolua_S,"GetPixelsLeft",tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsLeft00);
     tolua_function(tolua_S,"GetPixelsRight",tolua_Core_Core_OgreSpecific_MovableTextOverlay_GetPixelsRight00);
     tolua_function(tolua_S,"SetPixelsTop",tolua_Core_Core_OgreSpecific_MovableTextOverlay_SetPixelsTop00);
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"RectLayoutManager","Core::OgreSpecific::RectLayoutManager","",NULL);
    tolua_beginmodule(tolua_S,"RectLayoutManager");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Sound",0);
  tolua_beginmodule(tolua_S,"Sound");
   tolua_cclass(tolua_S,"CSound","Sound::CSound","",NULL);
   tolua_beginmodule(tolua_S,"CSound");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Plugin",0);
   tolua_beginmodule(tolua_S,"Plugin");
    tolua_cclass(tolua_S,"IConsoleParser","Core::Plugin::IConsoleParser","",NULL);
    tolua_beginmodule(tolua_S,"IConsoleParser");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"IMissionFactory","Core::Plugin::IMissionFactory","",NULL);
    tolua_beginmodule(tolua_S,"IMissionFactory");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"IPlayerFactory","Core::Plugin::IPlayerFactory","",NULL);
    tolua_beginmodule(tolua_S,"IPlayerFactory");
    tolua_endmodule(tolua_S);
    tolua_cclass(tolua_S,"IPostEffectFactory","Core::Plugin::IPostEffectFactory","",NULL);
    tolua_beginmodule(tolua_S,"IPostEffectFactory");
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Effects",0);
   tolua_beginmodule(tolua_S,"Effects");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"OgreSpecific",0);
   tolua_beginmodule(tolua_S,"OgreSpecific");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CScrollingMessage","Core::OgreSpecific::CScrollingMessage","",tolua_collect_Core__OgreSpecific__CScrollingMessage);
    #else
    tolua_cclass(tolua_S,"CScrollingMessage","Core::OgreSpecific::CScrollingMessage","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CScrollingMessage");
     tolua_function(tolua_S,"new",tolua_Core_Core_OgreSpecific_CScrollingMessage_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_OgreSpecific_CScrollingMessage_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_OgreSpecific_CScrollingMessage_new00_local);
     tolua_function(tolua_S,"Init",tolua_Core_Core_OgreSpecific_CScrollingMessage_Init00);
     tolua_function(tolua_S,"AddText",tolua_Core_Core_OgreSpecific_CScrollingMessage_AddText00);
     tolua_function(tolua_S,"Update",tolua_Core_Core_OgreSpecific_CScrollingMessage_Update00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",1);
  tolua_beginmodule(tolua_S,"Core");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CSpawnManager","Core::CSpawnManager","",tolua_collect_Core__CSpawnManager);
   #else
   tolua_cclass(tolua_S,"CSpawnManager","Core::CSpawnManager","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CSpawnManager");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CSpawnManager_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CSpawnManager_delete00);
    tolua_function(tolua_S,"AddSpawnPoint",tolua_Core_Core_CSpawnManager_AddSpawnPoint00);
    tolua_function(tolua_S,"RemoveSpawnPoint",tolua_Core_Core_CSpawnManager_RemoveSpawnPoint00);
    tolua_function(tolua_S,"GetCurrentSpawnPoint",tolua_Core_Core_CSpawnManager_GetCurrentSpawnPoint00);
    tolua_function(tolua_S,"GetSpawnPoint",tolua_Core_Core_CSpawnManager_GetSpawnPoint00);
    tolua_function(tolua_S,"SpawnPlayer",tolua_Core_Core_CSpawnManager_SpawnPlayer00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",1);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Training",0);
   tolua_beginmodule(tolua_S,"Training");
    tolua_constant(tolua_S,"ETC_BASIC_INFANTRY",Core::Training::ETC_BASIC_INFANTRY);
    tolua_constant(tolua_S,"ETC_BASIC_ENGINEER",Core::Training::ETC_BASIC_ENGINEER);
    tolua_constant(tolua_S,"ETC_BASIC_HTH_COMBAT",Core::Training::ETC_BASIC_HTH_COMBAT);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CTrainingManager","Core::Training::CTrainingManager","",tolua_collect_Core__Training__CTrainingManager);
    #else
    tolua_cclass(tolua_S,"CTrainingManager","Core::Training::CTrainingManager","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CTrainingManager");
     tolua_function(tolua_S,"Instance",tolua_Core_Core_Training_CTrainingManager_Instance00);
     tolua_function(tolua_S,"delete",tolua_Core_Core_Training_CTrainingManager_delete00);
     tolua_function(tolua_S,"AddFacility",tolua_Core_Core_Training_CTrainingManager_AddFacility00);
     tolua_function(tolua_S,"RemoveFacility",tolua_Core_Core_Training_CTrainingManager_RemoveFacility00);
     tolua_function(tolua_S,"IsCapable",tolua_Core_Core_Training_CTrainingManager_IsCapable00);
     tolua_function(tolua_S,"StartPlayerTraining",tolua_Core_Core_Training_CTrainingManager_StartPlayerTraining00);
     tolua_function(tolua_S,"StopPlayerTraining",tolua_Core_Core_Training_CTrainingManager_StopPlayerTraining00);
     tolua_function(tolua_S,"IsPlayerTraining",tolua_Core_Core_Training_CTrainingManager_IsPlayerTraining00);
     tolua_function(tolua_S,"GetPlayerTrainingList",tolua_Core_Core_Training_CTrainingManager_GetPlayerTrainingList00);
     tolua_function(tolua_S,"OnPlayerAttributeUpdate",tolua_Core_Core_Training_CTrainingManager_OnPlayerAttributeUpdate00);
     tolua_function(tolua_S,"Update",tolua_Core_Core_Training_CTrainingManager_Update00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CVolumeObject","Core::Physics::CVolumeObject","",tolua_collect_Core__Physics__CVolumeObject);
    #else
    tolua_cclass(tolua_S,"CVolumeObject","Core::Physics::CVolumeObject","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CVolumeObject");
     tolua_function(tolua_S,"SetPosition",tolua_Core_Core_Physics_CVolumeObject_SetPosition00);
     tolua_function(tolua_S,"RemoveVolume",tolua_Core_Core_Physics_CVolumeObject_RemoveVolume00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"CVolumeObject_Cube","Core::Physics::CVolumeObject_Cube","IVolumeObject",tolua_collect_Core__Physics__CVolumeObject_Cube);
    #else
    tolua_cclass(tolua_S,"CVolumeObject_Cube","Core::Physics::CVolumeObject_Cube","IVolumeObject",NULL);
    #endif
    tolua_beginmodule(tolua_S,"CVolumeObject_Cube");
     tolua_function(tolua_S,"new",tolua_Core_Core_Physics_CVolumeObject_Cube_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_Physics_CVolumeObject_Cube_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_Physics_CVolumeObject_Cube_new00_local);
     tolua_function(tolua_S,"delete",tolua_Core_Core_Physics_CVolumeObject_Cube_delete00);
     tolua_function(tolua_S,"OnCollision",tolua_Core_Core_Physics_CVolumeObject_Cube_OnCollision00);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CWeaponProfile","Core::CWeaponProfile","Core::CItemProfile",tolua_collect_Core__CWeaponProfile);
   #else
   tolua_cclass(tolua_S,"CWeaponProfile","Core::CWeaponProfile","Core::CItemProfile",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CWeaponProfile");
    tolua_function(tolua_S,"new",tolua_Core_Core_CWeaponProfile_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_CWeaponProfile_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_CWeaponProfile_new00_local);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CWeaponProfile_delete00);
    tolua_variable(tolua_S,"isSemi",tolua_get_Core__CWeaponProfile_isSemi,tolua_set_Core__CWeaponProfile_isSemi);
    tolua_variable(tolua_S,"isBurst",tolua_get_Core__CWeaponProfile_isBurst,tolua_set_Core__CWeaponProfile_isBurst);
    tolua_variable(tolua_S,"isAuto",tolua_get_Core__CWeaponProfile_isAuto,tolua_set_Core__CWeaponProfile_isAuto);
    tolua_variable(tolua_S,"Capacity",tolua_get_Core__CWeaponProfile_unsigned_Capacity,tolua_set_Core__CWeaponProfile_unsigned_Capacity);
    tolua_variable(tolua_S,"ROF",tolua_get_Core__CWeaponProfile_unsigned_ROF,tolua_set_Core__CWeaponProfile_unsigned_ROF);
    tolua_variable(tolua_S,"Accuracy",tolua_get_Core__CWeaponProfile_Accuracy,tolua_set_Core__CWeaponProfile_Accuracy);
    tolua_variable(tolua_S,"Range",tolua_get_Core__CWeaponProfile_Range,tolua_set_Core__CWeaponProfile_Range);
    tolua_variable(tolua_S,"ShotTime",tolua_get_Core__CWeaponProfile_ShotTime,tolua_set_Core__CWeaponProfile_ShotTime);
    tolua_variable(tolua_S,"Power",tolua_get_Core__CWeaponProfile_Power,tolua_set_Core__CWeaponProfile_Power);
    tolua_variable(tolua_S,"MeshName",tolua_get_Core__CWeaponProfile_MeshName,NULL);
    tolua_variable(tolua_S,"OverlayName",tolua_get_Core__CWeaponProfile_OverlayName,NULL);
    tolua_variable(tolua_S,"Desc",tolua_get_Core__CWeaponProfile_Desc,NULL);
    tolua_variable(tolua_S,"Scale",tolua_get_Core__CWeaponProfile_Scale,tolua_set_Core__CWeaponProfile_Scale);
    tolua_variable(tolua_S,"MagazineProfile",tolua_get_Core__CWeaponProfile_MagazineProfile_ptr,tolua_set_Core__CWeaponProfile_MagazineProfile_ptr);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"CWeaponFactory","Core::CWeaponFactory","IItemFactory",tolua_collect_Core__CWeaponFactory);
   #else
   tolua_cclass(tolua_S,"CWeaponFactory","Core::CWeaponFactory","IItemFactory",NULL);
   #endif
   tolua_beginmodule(tolua_S,"CWeaponFactory");
    tolua_function(tolua_S,"Instance",tolua_Core_Core_CWeaponFactory_Instance00);
    tolua_function(tolua_S,"delete",tolua_Core_Core_CWeaponFactory_delete00);
    tolua_function(tolua_S,"Create",tolua_Core_Core_CWeaponFactory_Create00);
    tolua_function(tolua_S,"AddProfile",tolua_Core_Core_CWeaponFactory_AddProfile00);
    tolua_function(tolua_S,"GetProfiles",tolua_Core_Core_CWeaponFactory_GetProfiles00);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Mission",1);
   tolua_beginmodule(tolua_S,"Mission");
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"OgreSpecific",0);
   tolua_beginmodule(tolua_S,"OgreSpecific");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"MovableTextOverlayAttributes","Core::OgreSpecific::MovableTextOverlayAttributes","",tolua_collect_Core__OgreSpecific__MovableTextOverlayAttributes);
    #else
    tolua_cclass(tolua_S,"MovableTextOverlayAttributes","Core::OgreSpecific::MovableTextOverlayAttributes","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"MovableTextOverlayAttributes");
     tolua_function(tolua_S,"new",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new00_local);
     tolua_function(tolua_S,"new",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new01_local);
     tolua_function(tolua_S,"new",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new02_local);
     tolua_function(tolua_S,"new",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new03);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new03_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_new03_local);
     tolua_function(tolua_S,"delete",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_delete00);
     tolua_function(tolua_S,"SetFontName",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetFontName00);
     tolua_function(tolua_S,"SetMaterialName",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetMaterialName00);
     tolua_function(tolua_S,"SetColor",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetColor00);
     tolua_function(tolua_S,"SetCharacterHeight",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_SetCharacterHeight00);
     tolua_function(tolua_S,"GetName",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetName00);
     tolua_function(tolua_S,"GetCamera",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetCamera00);
     tolua_function(tolua_S,"GetFont",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetFont00);
     tolua_function(tolua_S,"GetFontName",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetFontName00);
     tolua_function(tolua_S,"GetMaterialName",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetMaterialName00);
     tolua_function(tolua_S,"GetColor",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetColor00);
     tolua_function(tolua_S,"GetCharacterHeight",tolua_Core_Core_OgreSpecific_MovableTextOverlayAttributes_GetCharacterHeight00);
     tolua_variable(tolua_S,"mName",tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mName,NULL);
     tolua_variable(tolua_S,"mpCam",tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mpCam_ptr,NULL);
     tolua_variable(tolua_S,"mpFont",tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mpFont_ptr,tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mpFont_ptr);
     tolua_variable(tolua_S,"mFontName",tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mFontName,tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mFontName);
     tolua_variable(tolua_S,"mMaterialName",tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mMaterialName,tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mMaterialName);
     tolua_variable(tolua_S,"mColor",tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mColor,tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mColor);
     tolua_variable(tolua_S,"mCharHeight",tolua_get_Core__OgreSpecific__MovableTextOverlayAttributes_mCharHeight,tolua_set_Core__OgreSpecific__MovableTextOverlayAttributes_mCharHeight);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
    tolua_constant(tolua_S,"SHAPE_CUBE",Core::Physics::SHAPE_CUBE);
    tolua_constant(tolua_S,"SHAPE_SPHERE",Core::Physics::SHAPE_SPHERE);
    tolua_constant(tolua_S,"SHAPE_CAPSULE",Core::Physics::SHAPE_CAPSULE);
    tolua_constant(tolua_S,"SHAPE_CYLINDER",Core::Physics::SHAPE_CYLINDER);
    tolua_constant(tolua_S,"SHAPE_CONE",Core::Physics::SHAPE_CONE);
    tolua_constant(tolua_S,"SHAPE_STATIC_TRIMESH",Core::Physics::SHAPE_STATIC_TRIMESH);
    tolua_constant(tolua_S,"SHAPE_TRIMESH",Core::Physics::SHAPE_TRIMESH);
    tolua_constant(tolua_S,"SHAPE_PLANE",Core::Physics::SHAPE_PLANE);
    tolua_constant(tolua_S,"NONE_MASK",Core::Physics::NONE_MASK);
    tolua_constant(tolua_S,"ALL_MASK",Core::Physics::ALL_MASK);
    tolua_constant(tolua_S,"RAGDOLL_MASK",Core::Physics::RAGDOLL_MASK);
    tolua_constant(tolua_S,"GEOMETRY_MASK",Core::Physics::GEOMETRY_MASK);
    tolua_constant(tolua_S,"VEHICLE_MASK",Core::Physics::VEHICLE_MASK);
    tolua_constant(tolua_S,"STATIC_GEOMETRY_MASK",Core::Physics::STATIC_GEOMETRY_MASK);
    tolua_constant(tolua_S,"CHARACTER_CONTROLLER_MASK",Core::Physics::CHARACTER_CONTROLLER_MASK);
    tolua_constant(tolua_S,"VOLUME_MASK",Core::Physics::VOLUME_MASK);
    tolua_constant(tolua_S,"TERRAIN_MASK",Core::Physics::TERRAIN_MASK);
    tolua_constant(tolua_S,"EVT_CUBE",Core::Physics::EVT_CUBE);
    tolua_constant(tolua_S,"EVT_SPHERE",Core::Physics::EVT_SPHERE);
    tolua_constant(tolua_S,"EVT_CAPSULE",Core::Physics::EVT_CAPSULE);
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"VolumePackage","Core::Physics::VolumePackage","",tolua_collect_Core__Physics__VolumePackage);
    #else
    tolua_cclass(tolua_S,"VolumePackage","Core::Physics::VolumePackage","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"VolumePackage");
     tolua_function(tolua_S,"new",tolua_Core_Core_Physics_VolumePackage_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_Physics_VolumePackage_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_Physics_VolumePackage_new00_local);
     tolua_variable(tolua_S,"Profile",tolua_get_Core__Physics__VolumePackage_Profile_ptr,tolua_set_Core__Physics__VolumePackage_Profile_ptr);
     tolua_variable(tolua_S,"Strategy",tolua_get_Core__Physics__VolumePackage_Strategy_ptr,tolua_set_Core__Physics__VolumePackage_Strategy_ptr);
     tolua_variable(tolua_S,"Scale",tolua_get_Core__Physics__VolumePackage_Scale,tolua_set_Core__Physics__VolumePackage_Scale);
     tolua_variable(tolua_S,"isRemoveCallback",tolua_get_Core__Physics__VolumePackage_isRemoveCallback,tolua_set_Core__Physics__VolumePackage_isRemoveCallback);
     tolua_variable(tolua_S,"EnableRaycast",tolua_get_Core__Physics__VolumePackage_EnableRaycast,tolua_set_Core__Physics__VolumePackage_EnableRaycast);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_constant(tolua_S,"EPT_TEAM_1",Core::EPT_TEAM_1);
   tolua_constant(tolua_S,"EPT_TEAM_2",Core::EPT_TEAM_2);
   tolua_constant(tolua_S,"EPT_TEAM_3",Core::EPT_TEAM_3);
   tolua_constant(tolua_S,"EPT_TEAM_4",Core::EPT_TEAM_4);
   tolua_constant(tolua_S,"EPT_TEAM_5",Core::EPT_TEAM_5);
   tolua_constant(tolua_S,"EPT_TEAM_6",Core::EPT_TEAM_6);
   tolua_constant(tolua_S,"EPT_TEAM_7",Core::EPT_TEAM_7);
   tolua_constant(tolua_S,"EPT_TEAM_8",Core::EPT_TEAM_8);
   tolua_constant(tolua_S,"EPT_TEAM_9",Core::EPT_TEAM_9);
   tolua_constant(tolua_S,"EPT_TEAM_10",Core::EPT_TEAM_10);
   tolua_constant(tolua_S,"EPT_TEAM_COUNT",Core::EPT_TEAM_COUNT);
   tolua_constant(tolua_S,"EAS_IDLE",Core::EAS_IDLE);
   tolua_constant(tolua_S,"EAS_WALK",Core::EAS_WALK);
   tolua_constant(tolua_S,"EAS_RUN",Core::EAS_RUN);
   tolua_constant(tolua_S,"EAS_SPRINT",Core::EAS_SPRINT);
   tolua_constant(tolua_S,"EAS_DIEING",Core::EAS_DIEING);
   tolua_constant(tolua_S,"EAS_DEAD",Core::EAS_DEAD);
   tolua_constant(tolua_S,"EAS_CRAWL",Core::EAS_CRAWL);
   tolua_constant(tolua_S,"EAS_SHOOT",Core::EAS_SHOOT);
   tolua_constant(tolua_S,"EAS_RELOAD",Core::EAS_RELOAD);
   tolua_constant(tolua_S,"EAS_KNEEL",Core::EAS_KNEEL);
   tolua_constant(tolua_S,"EAS_PRONE",Core::EAS_PRONE);
   tolua_constant(tolua_S,"EAS_RUNSHOOT",Core::EAS_RUNSHOOT);
   tolua_constant(tolua_S,"EAS_HIT",Core::EAS_HIT);
   tolua_constant(tolua_S,"EAS_MELEE",Core::EAS_MELEE);
   tolua_constant(tolua_S,"EAS_JUMP",Core::EAS_JUMP);
   tolua_constant(tolua_S,"EAS_AIM_STAND",Core::EAS_AIM_STAND);
   tolua_constant(tolua_S,"EAS_NONE",Core::EAS_NONE);
   tolua_constant(tolua_S,"EPS_IDLE",Core::EPS_IDLE);
   tolua_constant(tolua_S,"EPS_DIEING",Core::EPS_DIEING);
   tolua_constant(tolua_S,"EPS_DEAD",Core::EPS_DEAD);
   tolua_constant(tolua_S,"EPS_RUNNING",Core::EPS_RUNNING);
   tolua_constant(tolua_S,"EPS_ATTACKING",Core::EPS_ATTACKING);
   tolua_constant(tolua_S,"EPS_WAITING",Core::EPS_WAITING);
   tolua_constant(tolua_S,"EPS_WALKING",Core::EPS_WALKING);
   tolua_constant(tolua_S,"EPS_WANDERING",Core::EPS_WANDERING);
   tolua_constant(tolua_S,"EPS_EVADING",Core::EPS_EVADING);
   tolua_constant(tolua_S,"EPS_SEEK_ENEMY",Core::EPS_SEEK_ENEMY);
   tolua_constant(tolua_S,"EPS_SEEK_OBS",Core::EPS_SEEK_OBS);
   tolua_constant(tolua_S,"EPS_SEEK_ITEM",Core::EPS_SEEK_ITEM);
   tolua_constant(tolua_S,"EPS_FIND_ENEMY",Core::EPS_FIND_ENEMY);
   tolua_constant(tolua_S,"EPS_NONE",Core::EPS_NONE);
   tolua_constant(tolua_S,"EPS_COUNT",Core::EPS_COUNT);
   tolua_constant(tolua_S,"SPP_LOW",Core::SPP_LOW);
   tolua_constant(tolua_S,"SPP_MED",Core::SPP_MED);
   tolua_constant(tolua_S,"SPP_HIGH",Core::SPP_HIGH);
   tolua_constant(tolua_S,"SPP_CURRENT",Core::SPP_CURRENT);
   tolua_constant(tolua_S,"ELT_BASIC",Core::ELT_BASIC);
   tolua_constant(tolua_S,"ELT_TRIANGLE",Core::ELT_TRIANGLE);
   tolua_constant(tolua_S,"ELT_RANGE_BASIC",Core::ELT_RANGE_BASIC);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Sound",0);
  tolua_beginmodule(tolua_S,"Sound");
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",0);
   tolua_beginmodule(tolua_S,"Physics");
   tolua_endmodule(tolua_S);
   tolua_module(tolua_S,"Nature",0);
   tolua_beginmodule(tolua_S,"Nature");
   tolua_endmodule(tolua_S);
   #ifdef __cplusplus
   tolua_cclass(tolua_S,"SceneImporterPackage","Core::SceneImporterPackage","",tolua_collect_Core__SceneImporterPackage);
   #else
   tolua_cclass(tolua_S,"SceneImporterPackage","Core::SceneImporterPackage","",NULL);
   #endif
   tolua_beginmodule(tolua_S,"SceneImporterPackage");
    tolua_function(tolua_S,"new",tolua_Core_Core_SceneImporterPackage_new00);
    tolua_function(tolua_S,"new_local",tolua_Core_Core_SceneImporterPackage_new00_local);
    tolua_function(tolua_S,".call",tolua_Core_Core_SceneImporterPackage_new00_local);
    tolua_variable(tolua_S,"GameManager",tolua_get_Core__SceneImporterPackage_GameManager_ptr,tolua_set_Core__SceneImporterPackage_GameManager_ptr);
    tolua_variable(tolua_S,"PhysicsStrategy",tolua_get_Core__SceneImporterPackage_PhysicsStrategy_ptr,tolua_set_Core__SceneImporterPackage_PhysicsStrategy_ptr);
    tolua_variable(tolua_S,"SoundManager",tolua_get_Core__SceneImporterPackage_SoundManager_ptr,tolua_set_Core__SceneImporterPackage_SoundManager_ptr);
    tolua_variable(tolua_S,"ItemsManager",tolua_get_Core__SceneImporterPackage_ItemsManager_ptr,tolua_set_Core__SceneImporterPackage_ItemsManager_ptr);
    tolua_variable(tolua_S,"GameObjectManager",tolua_get_Core__SceneImporterPackage_GameObjectManager_ptr,tolua_set_Core__SceneImporterPackage_GameObjectManager_ptr);
    tolua_variable(tolua_S,"NatureManager",tolua_get_Core__SceneImporterPackage_NatureManager_ptr,tolua_set_Core__SceneImporterPackage_NatureManager_ptr);
    tolua_variable(tolua_S,"CameraManager",tolua_get_Core__SceneImporterPackage_CameraManager_ptr,tolua_set_Core__SceneImporterPackage_CameraManager_ptr);
    tolua_variable(tolua_S,"ResourceGroupName",tolua_get_Core__SceneImporterPackage_ResourceGroupName,tolua_set_Core__SceneImporterPackage_ResourceGroupName);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
  tolua_module(tolua_S,"Core",0);
  tolua_beginmodule(tolua_S,"Core");
   tolua_module(tolua_S,"Physics",1);
   tolua_beginmodule(tolua_S,"Physics");
    #ifdef __cplusplus
    tolua_cclass(tolua_S,"SPhysicsRayCastReport","Core::Physics::SPhysicsRayCastReport","",tolua_collect_Core__Physics__SPhysicsRayCastReport);
    #else
    tolua_cclass(tolua_S,"SPhysicsRayCastReport","Core::Physics::SPhysicsRayCastReport","",NULL);
    #endif
    tolua_beginmodule(tolua_S,"SPhysicsRayCastReport");
     tolua_function(tolua_S,"new",tolua_Core_Core_Physics_SPhysicsRayCastReport_new00);
     tolua_function(tolua_S,"new_local",tolua_Core_Core_Physics_SPhysicsRayCastReport_new00_local);
     tolua_function(tolua_S,".call",tolua_Core_Core_Physics_SPhysicsRayCastReport_new00_local);
     tolua_variable(tolua_S,"GameObject",tolua_get_Core__Physics__SPhysicsRayCastReport_GameObject_ptr,tolua_set_Core__Physics__SPhysicsRayCastReport_GameObject_ptr);
     tolua_variable(tolua_S,"Player",tolua_get_Core__Physics__SPhysicsRayCastReport_Player_ptr,tolua_set_Core__Physics__SPhysicsRayCastReport_Player_ptr);
     tolua_variable(tolua_S,"Custom",tolua_get_Core__Physics__SPhysicsRayCastReport_Custom,tolua_set_Core__Physics__SPhysicsRayCastReport_Custom);
     tolua_variable(tolua_S,"BodyType",tolua_get_Core__Physics__SPhysicsRayCastReport_BodyType,tolua_set_Core__Physics__SPhysicsRayCastReport_BodyType);
     tolua_variable(tolua_S,"Position",tolua_get_Core__Physics__SPhysicsRayCastReport_Position,tolua_set_Core__Physics__SPhysicsRayCastReport_Position);
    tolua_endmodule(tolua_S);
   tolua_endmodule(tolua_S);
  tolua_endmodule(tolua_S);
 tolua_endmodule(tolua_S);
 return 1;
}


#if defined(LUA_VERSION_NUM) && LUA_VERSION_NUM >= 501
 TOLUA_API int luaopen_Core (lua_State* tolua_S) {
 return tolua_Core_open(tolua_S);
};
#endif

#endif