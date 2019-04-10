#ifndef __CBUILDING__
#define __CBUILDING__

#include "Defines.h"

namespace Core
{
	class CPlayer;
	class CGameObject;
	class CProjectile;
	class CInventoryItem;
	enum  E_PLAYER_TEAM;
	enum  E_LOS_TYPE;
	enum  E_LOAD_TYPE;

	namespace AI
	{
		class CFpsVehicle;
	}

	namespace Physics
	{
		class IPhysicsStrategy;
	}

	enum E_BUILDING_STATE
	{
		EBS_IDLE,				// Not in use, and not doing anything
		EBS_RUNNING,
		EBS_DEFENDING,			// Fighting enemies in range
		EBS_DISABLED			// Not funcitonal
	};

	enum E_BUILDING_CATEGORY
	{
		EBC_SUPPLY = 0,			// Used to supply or maintain a military
		EBC_TRAINING = 1,		// Used to train military units
		EBC_PROP = 2,			// Prop building
		EBC_DEFENCE = 3,		// Defend an area, and/or attack enemies
		EBC_OTHER = 4			// Has special logic
	};

	class CORE_EXPORT CBuilding
	{
	public:
		CBuilding(const char* LabelName, Physics::IPhysicsStrategy* PhysicsStrategy);
		~CBuilding();

		virtual void Update(const f32& elapsedTime) = 0;

		// Gets
		inline SceneNode*			GetNode();						// Returns the node for the building's mesh
		inline Entity*				GetEntity();					// Returns the entity for the building's mesh (primary entity)
		inline f32					GetHealth();
		inline f32					GetViewRange();					// How far the building can see
		inline E_BUILDING_STATE		GetState();
		inline AI::CFpsVehicle*		GetAiVehicle();
		inline E_PLAYER_TEAM		GetTeam();
		inline Vector3				GetPosition();					// Just the parent node's position
		inline const char*			GetName() { return Name.c_str(); }
		inline const char*			GetBuildingType() { return m_BuildingType; }
		inline bool					GetIsVisible() { return isVisible; }
		inline Vector<CInventoryItem*> GetItems() { return m_Items; }
		inline AI::CFpsVehicle*		GetAiTarget();					// Used for character states for seeking a target
		inline E_LOS_TYPE			GetLoSType() { return m_LosType; }
		inline E_BUILDING_CATEGORY	GetCategory() { return m_BuildingCategory; }
		inline E_LOAD_TYPE			GetLoadType() { return m_LoadType; }

		// Sets
		inline void					SetHealth(const f32& Health) { m_Health = Health; }
		inline void					SetViewRange(const f32& ViewRange) { m_ViewRange = ViewRange; }
		inline void					SetTeam(E_PLAYER_TEAM Team) { m_Team = Team; }
		inline void					SetAiTarget(AI::CFpsVehicle* Target) { m_Target = Target; }
		inline void					SetPosition(const Vector3& Position);
		inline void					SetCategory(E_BUILDING_CATEGORY Catetory) { m_BuildingCategory = Catetory; }
		inline void					SetLoadType(E_LOAD_TYPE LoadType) { m_LoadType = LoadType; }

		// Line of Sight
		bool CanSee(const Vector3& Position);

		// Items inventory
		void AddItem(CInventoryItem* Item);							// Adding an item via code, and not using the OnPickupItem event
		void RemoveItem(CInventoryItem* Item);						// Removes the item from the users inventory
		void RemoveAllItems();										// Removes all items from the inventory

		// Attacking or using inventory
		void UseItem(CPlayer* Player, CInventoryItem* Item = nullptr);
		void UseItem(CGameObject* GameObject, CInventoryItem* Item = nullptr) { }

		// Events
		virtual void OnHit(CProjectile* Projectile, const Vector3& Direction);		// Used when hit, and calcs the damage internally
		virtual void OnHit(CInventoryItem* InventoryItem, CPlayer* Owner, const Vector3& Direction);
		virtual void OnKill(CPlayer* PlayerKilled, CProjectile* Projectile);		// When this building has a new kill
		virtual void OnKill(CPlayer* PlayerKilled, CInventoryItem* InventoryItem);

	protected:
		String				Name;								// Label for the building object
		SceneNode*			m_BuildingNode;						// Main node
		Entity*				m_BuildingEntity;					// Main Entity
		String				m_MeshName;							// Name of the mesh file
		f32					m_Health;
		f32					m_ViewRange;						// How far the bui8lding can see
		bool				isVisible;							// Is the building visible (default true)
		bool				isDestroyed;						// Is the building destroyed/killed
		E_PLAYER_TEAM		m_Team;								// Which team is the building assigned to
		AI::CFpsVehicle*	m_Target;							// Target to seek, used for character states
		AI::CFpsVehicle*	m_AbstractVehicle;					// The AI vehicle to use
		E_LOS_TYPE			m_LosType;							// Current LoS strategy being used
		E_BUILDING_STATE	m_BuildingState;					// Current state of the building
		E_BUILDING_CATEGORY m_BuildingCategory;					// What the category (function) of the building is
		const char*			m_BuildingType;						// A unique string that identifies the type of building (used for plugins and loading by type name)
		E_LOAD_TYPE			m_LoadType;							// Defermines if we use static geometry, an instance manager, or a plain entity, NONE by default.
		
		Vector<CGameObject*>		m_GameObjects;				// Composite list of game objects, used for physics shapes, and events when working with different parts of a building
		Vector<CInventoryItem*>		m_Items;					// List of items the building has
		Physics::IPhysicsStrategy*	m_PhysicsStrategy;

		void UpdateDefault(const f32& elapsedTime);
		void PostInit();
	};
}

#endif // __CBUILDING__