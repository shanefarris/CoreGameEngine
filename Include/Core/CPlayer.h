// Generic player, could be human player, or AI controlled, the logic should be the same.  CPlayer should be blind to the physics
// implementation, only the game driver should have strategy specific logic.
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "Defines.h"

namespace Core
{
	class CProjectile;
	class CGameObject;
	class CPlayerPimpl;
	class CInventoryItem;
	enum E_PLAYER_STATE;
	enum E_PLAYER_TEAM;
	enum E_LOS_TYPE;
  
	namespace Physics
	{
		class IPhysicsStrategy;
		class ICharacterController;
	}

	namespace AI
	{
		class CCharacterState;
		class CFpsVehicle;
	}

	class CORE_EXPORT CPlayer
	{
		friend class CPlayerPimpl;
	public:
		CPlayer(const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CPlayer();
		    
		virtual void Update(const f32& elapsedTime) = 0;

		// Gets
		inline SceneNode*			GetPlayerNode();			// Returns the node for the player mesh
		inline Entity*				GetPlayerEntity();			// Returns the entity for the player mesh (primary entity)
		inline f32					GetHealth();
		inline f32					GetViewRange();				// How far the player can see
		inline E_PLAYER_STATE		GetPlayerState();
		inline AI::CFpsVehicle*		GetAiVehicle();
		inline AI::CFpsVehicle*		GetAiTarget();				// Used for character states for seeking a target
		inline AI::CCharacterState* GetCharacterState();
		inline E_PLAYER_TEAM		GetPlayerTeam();
		inline Vector3				GetPosition();				// Just the parent node's position
		inline const char*			GetName();
		inline const char*			GetMeshName();				// Used in ragdoll physics
		inline bool					GetIsVisible();
		inline bool					GetIsHumanPlayer();
		inline Vector3				GetDirection();
		inline Vector<CInventoryItem*> GetItems();
		inline Vector3				GetHeadPosition();
		inline Quaternion			GetHeadRotation();
		inline Vector3				GetBodyPosition();
		inline Quaternion			GetBodyRotation();
		inline void					GetAiPathPoints(Vector<Vector3>& Paths); // Used for characater states for path following
		inline CInventoryItem*		GetCurrentInventoryItem();
		inline Vector3				GetEyePosition();			// Where the player's eyes are (used for LoS)
		inline Vector3				GetCharacterControllerSize();
		inline E_LOS_TYPE			GetLoSType();
		inline bool					GetIsFps();

		// Gets Used for serialization and other things
		inline const char*					  GetPlayerType();
		inline Physics::IPhysicsStrategy*	  GetPhysicsStrategy();
		inline Physics::ICharacterController* GetCharacterController();
		inline f32							  GetRunSpeed();
		inline f32							  GetWalkSpeed();
		inline f32							  GetSprintSpeed();
		inline f32							  GetCrawlSpeed();
		inline f32							  GetDieTime();
		inline const char*					  GetMovableText();

		void SetRunSpeed(const f32& Speed);
		void SetWalkSpeed(const f32& Speed);
		void SetSprintSpeed(const f32& Speed);
		void SetCrawlSpeed(const f32& Speed);
		void SetDieTime(const f32& Time);

		// Sets
		void SetHealth(f32 Health);
		void SetVisible(bool Visible);
		void SetPlayerState(E_PLAYER_STATE State);
		void SetAiVehicle(AI::CFpsVehicle* Vehicle);
		void SetAiTarget(AI::CFpsVehicle* Target);				// Characater state's target
		void SetCharacterState(E_PLAYER_STATE State);			// Set the state by type, so it is not exact.
		void SetExactCharacterState(const char* State);			// Set exact state (don't let the manager decide with state is appropriate 
		void SetPlayerPosition(const Vector3& Position);		// Used this because the Ai needs updated too.
		void SetPlayerPosition(const f32& x, const f32& y, const f32& z);
		void SetPlayerTeam(E_PLAYER_TEAM Team);
		void SetHumanPlayer(bool isPlayer);
		void SetViewRange(const f32& Range);
		void SetTextLabelCaption(const char* Text);				// Set the text of the movable text overlay (must be enabled for it to render)
		void SetTextLabelEnabled(bool Enabled);					// If the movable text overlay is visible
		void SetAiPathPoints(const Vector<Vector3>& PathPoints); // Path to follow for characater states
		void SetName(const char* LabelName);					// Changes the users name and resets the movable text overlay
		void SetDirection(const Vector3& Direction);			// Points the player in a specific direction
		void SetLoSType(E_LOS_TYPE Type);						// Sets the current LoS strategy

		// Line of Sight
		bool CanSee(const Vector3& Position);
		bool CanSee(CPlayer* Player);

		virtual CPlayer* Duplicate(const char* PlayerType);		// Copies the player information and returns the duplicated player class
		
		// Items inventory
		void AddItem(CInventoryItem* Item);						// Adding an item via code, and not using the OnPickupItem event
		void RemoveItem(CInventoryItem* Item);					// Removes the item from the users inventory
		void RemoveAllItems();									// Removes all items from the inventory
		void DropAllItems();									// Removes all items from the inventory, and drops them on the ground
		
		// Attacking or using inventory
		void UseItem(CPlayer* Player, CInventoryItem* Item = nullptr);
		void UseItem(CGameObject* GameObject, CInventoryItem* Item = nullptr);

		// Debug
		void DebugLoS(bool Show);

		// Events	
		virtual void OnHit(CProjectile* Projectile, const Vector3& Direction);		// Used when hit, and calcs the damage internally
		virtual void OnHit(CInventoryItem* InventoryItem, CPlayer* Owner, const Vector3& Direction);
		virtual void OnShotFired() = 0;												// Player shot a weapon, or used a tool
		virtual void OnMove(const f32& elapsedTime) = 0;	// Player moves there physical location
		void OnPickupItem();														// Pickup an object
		virtual void OnKill(CPlayer* PlayerKilled, CProjectile* Projectile);		// When this player has a new kill
		virtual void OnKill(CPlayer* PlayerKilled, CInventoryItem* InventoryItem);

	protected:
		void SetYAxisFromTerrain();								// Sets the player's Y axis based on the terrain
		void SetYAxisFromTerrain(f32 elapsedTime);

		virtual void SetupMapping() = 0;						// Force all player classes to map there animations (used in the update methods)
		
		// Updates
		void UpdateDefault(const f32& elapsedTime);
		void UpdateTextLabel(const f32& elapsedTime);			// Updates just the text label (movable text overlay)
		void UpdateMovement(const f32& elapsedTime);
		void UpdateAnimationState(const f32& elapsedTime);
		void UpdateAnimation(const f32& elapsedTime);
		void UpdatePhysics(const f32& elapsedTime);

		CPlayerPimpl*		m_PlayerPimpl;

	private:
		// Dynamic terrain height methods based on if its paged or height map
		void (CPlayer::*SetYAxisFromTerrain_Ptr)(f32);
		void SetYAxisFromTerrain_Paged(f32 elapsedTime);
		void SetYAxisFromTerrain_Height(f32 elapsedTime);
	};
}
#endif
