#ifndef __CPLAYERPIMPL_H__
#define __CPLAYERPIMPL_H__

#include "Defines.h"
#include "OgreVector3.h"

namespace Core
{
	class CPlayer;
	class CWeapon;
	class CGameObject;
	class CProjectile;
	class CGameManager;
	class CItemsManager;
	class CCameraManager;
	class CInventoryItem;
	class CGameObjectManager;
	class CEnvironmentObserver;
	class CPlayerSoundComponent;
	class CPlayerAttributesComponent;
	class ILineOfSightStrategy;
	struct CoreEntityObject;
	struct SoundToAnimation;
	enum E_LOS_TYPE;
	enum E_ANIM_STATE;
	enum E_PLAYER_TEAM;
	enum E_PLAYER_STATE;

	namespace AI
	{
		class CCharacterStateManager;
		class CCharacterState;
		class CFpsVehicle;
		class IAiReactionComponent;
	}

	namespace Physics
	{
		class IPhysicsStrategy;
		class ICharacterController;
		class IPhysicsRagdoll;
	}

	namespace OgreSpecific
	{
		class MovableTextOverlay;
		class RectLayoutManager;
	}

	typedef Map<E_ANIM_STATE, SoundToAnimation*> AnimationMap;

	class CORE_EXPORT CPlayerPimpl
	{
		friend class CPlayer;

	public:
		CPlayerPimpl(const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CPlayerPimpl();

		void SetDirection(const Vector3& Direction);			// Points the player in a specific direction
		void SetLoSType(E_LOS_TYPE Type);						// Sets the current LoS strategy

		// Line of Sight
		bool CanSee(const Vector3& Position);
		bool CanSee(CPlayer* Player);

		CPlayer* Duplicate(const char* PlayerType);

		void PostInit(CPlayer* Player);							// Boilerplate code that is called after the specific player code is called
		void CheckForObjects();									// Check to see if there's anything in front of us
		void TextLabelSetup();									// Sets up the movable text overlay

		// Items
		void AddItem(CInventoryItem* Item);
		void RemoveItem(CInventoryItem* Item);
		void DropAllItems();
		void RemoveAllItems();
		void UseItem(CPlayer* Player, CInventoryItem* Item);
		void UseItem(CGameObject* GameObject, CInventoryItem* Item = nullptr);

		// Events
		void OnPickupItem();
		void OnKill(CPlayer* PlayerKilled, CProjectile* Projectile);
		void OnKill(CPlayer* PlayerKilled, CInventoryItem* InventoryItem);
		void OnShotFired();
		void OnHit(CProjectile* Projectile, const Vector3& Direction);
		void OnHit(CInventoryItem* InventoryItem, CPlayer* Owner, const Vector3& Direction);

		// Debug
		void DebugLoS(bool Show);

		// Updates
		void UpdateDefault(const f32& elapsedTime);
		void UpdateTextLabel(const f32& elapsedTime);			// Updates just the text label (movable text overlay)
		void UpdateMovement(const f32& elapsedTime);
		void UpdateAnimationState(const f32& elapsedTime);
		void UpdateAnimation(const f32& elapsedTime);
		void UpdatePhysics(const f32& elapsedTime);

		// GET/SET
		Vector3 GetPosition();
		Vector3 GetHeadPosition();
		Quaternion GetHeadRotation();
		Vector3 GetBodyPosition();
		Quaternion GetBodyRotation();
		void SetYAxisFromTerrain_Paged(f32 elapsedTime);
		void SetYAxisFromTerrain_Height(f32 elapsedTime);
		void SetCharacterState(E_PLAYER_STATE PlayerState);
		void SetExactCharacterState(const char* State);
		void SetHumanPlayer(bool isPlayer);
		void SetPlayerPosition(const Vector3& Position);
		void SetPlayerPosition(const f32& x, const f32& y, const f32& z);
		void SetVisible(bool Visible);
		const char* GetMovableText();
		void SetPlayerState(E_PLAYER_STATE State);
		Vector3 GetEyePosition();
		void SetTextLabelEnabled(bool Enabled);
		void SetPlayerTeam(E_PLAYER_TEAM Team);
		void SetTextLabelCaption(const char* Text);

		CPlayer*			m_Player;
		String				Name;								// Label for the player object
		String				m_MeshName;							// Name of the mesh file
		f32					m_WalkSpeed;						// Walk movement speed
		f32					m_RunSpeed;							// Run movement speed
		f32					m_SprintSpeed;						// Sprint movement speed
		f32					m_CrawlSpeed;						// Crawl movement speed
		f32					m_ReloadSpeed;						// Reload movement speed
		f32					m_Health;							// Current health
		f32					m_PickupRadius;						// How far away can you pick up an item? 
		f32					m_DestinationRadius;				// How far away can you be before you reach your destination
		f32					m_FallVelocity;						// How fast do we fall
		f32					m_DieingTime;						// Timer to set for how long to die
		f32					m_ViewRange;						// How far the player can see
		f32					m_AnimationSpeed;					// Scalar for animation speeds (default 1.0)
		SceneNode*			m_SightNode;						// "Sight" node - The character is supposed to be looking here
		Entity*				m_PlayerEntity;						// The entity of the character
		SceneNode*			m_PlayerNode;						// Main character node
		bool				isKilled;							// Set once the player is dead 
		bool				isVisible;							// Is the player visible (default true)
		bool				isMovableText;						// Is the movable text overlay implement (default false)
		bool				isHumanPlayer;						// Is this the current human player
		bool				isCharacterController;				// Do we use a character controller for this player (default true)
		bool				isFpsView;							// Is this a FPS view like arms.
		Vector3				m_Movement;							// The translation for the player node
		Vector3				m_Direction;						// Where the player node is facing and moving towards
		Vector3				m_CCSize;							// Optional size for the character controller to use
		CInventoryItem*		m_CurrItem;							// The current (if any) tool/weapon the player is using
		CItemsManager*		m_ItemsManager;
		RaySceneQuery*		m_ObjectQuery;						// Query objects in front of player (query for items)
		RaySceneQuery*		m_PlayerQuery;						// Query for other players
		RaySceneQuery*		m_TerrainRaySceneQuery;				// Ray query for Y axis from terrain
		E_PLAYER_TEAM		m_PlayerTeam;						// Which team is the player assigned to
		const char*			m_PlayerType;						// A unique string that identifies the type of player
		ManualObject*		m_Lineofsight;						// Used for debugging LoS
		String				m_RootBoneName;						// Name of the root bone in the skeleton
		String				m_HeadBoneName;						// Name of the head bone in the skeleton
		AI::CFpsVehicle*	m_Target;							// Target to seek, used for character states
		Vector<Vector3>		m_PathPoints;						// Series of points to follow, used for character states
		E_LOS_TYPE			m_LosType;							// Current LoS strategy being used

		AI::CFpsVehicle*				m_AbstractVehicle;		// The AI vehicle to use
		AI::CCharacterStateManager*		m_CharacterStateManager;
		AI::IAiReactionComponent*		m_AiReactionComponent;  // Used to reaction during environmental, or character state changes
		AI::CCharacterState*			m_CharacterState;		// Current characater state active
		ILineOfSightStrategy*			m_LineOfSightStrategy;	// Currently used strategy for LoS
		Physics::IPhysicsStrategy*		m_PhysicsStrategy;		// Our default strategy
		Physics::ICharacterController*	m_CharacterController;	// NPC
		Physics::IPhysicsRagdoll*		m_PhysicsRagdoll;		// Interface to the ragdoll if one is setup
		AnimationState*					m_AnimationState;		// Used for animation states with Ogre
		Vector<CInventoryItem*>			m_Items;				// List of tools the user has
		CoreEntityObject*				m_Ceo;					// Object we attach to the entity
		CGameManager*					m_GameManager;
		CCameraManager*					m_CameraManager;		
		CGameObjectManager*				m_GameObjectManager;
		CEnvironmentObserver*			m_EnvironmentObserver;	// Our AI update object
		AnimationMap					m_AnimationMaps;		// Maps the animaiton from ogre to the state and the sound for the animation
		OgreSpecific::MovableTextOverlay* m_MovableTextOverlay; // Text label
		CPlayerSoundComponent*			m_PlayerSoundComponent; // Helper class for our sound events
		CPlayerAttributesComponent*		m_AttributesComponent;	// Helper class for the attributes

		// States
		E_ANIM_STATE	m_AnimState;							// What the state should be
		E_ANIM_STATE	m_CurrAnimState;						// The current state, if diff then anim state, update it
		E_PLAYER_STATE	m_PlayerState;							// Links to AI, and the animations, the state we already are

		
	};
}

#endif // __CPLAYERPIMPL_H__