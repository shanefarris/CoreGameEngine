#include "Defines.h"
#include "CGameState.h"
#include "CFpsFrameListener.h"
#include "CLoadingScreen.h"
#include "CTextOutput.h"
#include "CUtility.h"
#include "SceneImporterPackage.h"
#include "CGameObject.h"
#include "Audio/CSound.h"
#include "MissionEvents.h"

// Physics
#include "IPhysicsStrategy.h"
#include "CVolumeObject.h"
#include "CPhysicsProfile.h"
#include "PhysicsStructures.h"

// Gui
#include "IGuiStrategy.h"

// Player
#include "CPlayer.h"
#include "Ai/CFpsVehicle.h"
#include "CCharacterState.h"

// Items
#include "CWeapon.h"
#include "CMagazine.h"
#include "CWeaponProfile.h"
#include "CItemProfile.h"
#include "CProjectile.h"

// Managers
#include "CGameManager.h"
#include "CPhysicsManager.h"
#include "CGuiManager.h"
#include "CPluginManager.h"
#include "CTrainingManager.h"
#include "CInputManager.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "Audio/CSoundManager.h"
#include "CMissionManager.h"
#include "CEffectsManager.h"
#include "CPhysicsManager.h"
#include "CItemsManager.h"
#include "CSpawnManager.h"
#include "CNatureManager.h"
#include "CCharacterStateManager.h"
#include "CBillboardManager.h"

// Consoles
#include "OgreConsole.h"
#include "CLuaConsole.h"

// Terrain
#include "Terrain/OgreTerrainGroup.h"
