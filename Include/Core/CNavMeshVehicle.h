#ifndef __CNAVMESHVEHICLE_H__
#define __CNAVMESHVEHICLE_H__

#include "Defines.h"
#include "OgreVector3.h"

namespace Ogre
{
	class TerrainGroup;
}

namespace Core 
{
	class CPlayer;

	namespace AI
	{
	namespace NavMesh
	{
		struct dtCrowdAgent;
		class OgreDetourCrowd;
		class OgreDetourTileCache;

		class CORE_EXPORT CNavMeshVehicle
		{
		public:
			/**
			* Create a character with specified name, for which entities will be drawn on the specified scene manager. detourCrowd specifies the detour crowd manager on which 
			* an agent for this character will be created (make sure you don't create more characters than MAX_AGENTS). Position defines initial position the character has to be 
			* placed on (should be a valid position on the navmesh).
			**/
			CNavMeshVehicle(CPlayer* Player, OgreDetourCrowd* detourCrowd);

			~CNavMeshVehicle();

			CPlayer* GetPlayer() { return m_Player; }

			void Update(const f32& elapsedTime);

			/**
			* Update the destination for this agent. If updatePreviousPath is set to true the previous path will be reused instead
			* of calculating a completely new path, but this can only be used if the new destination is close to the previous (eg. when chasing a moving entity).
			**/
			void UpdateDestination(Vector3& Destination, bool UpdatePreviousPath = false);

			/**
			* The destination set for this character.
			**/
			void GetDestination(Vector3& Destination) const;

			/**
			* Place character at new position. The character will start following the globally set destination in the detourCrowd,
			* unless you give it an individual destination using updateDestination().
			**/
			void SetPosition(Vector3& Position);

			/**
			* Set destination member variable directly without updating the agent state. Usually you should call updateDestination() externally, unless you are controlling
			* the agents directly and need to update the corresponding character class to reflect the change in state (see OgreRecastApplication friendship).
			**/
			void SetDestination(const Vector3& Destination);

			/**
			* Index ID identifying the agent of this character in the crowd
			**/
			int GetAgentId() { return m_AgentId; }

			/**
			* The agent that steers this character within the crowd
			**/
			const dtCrowdAgent* GetAgent() { return m_Agent; }

			/**
			* Returns true when this character has reached its set destination.
			**/
			bool DestinationReached() const;

			/**
			* Request to set a manual velocity for this character, to control it manually. The set velocity will stay active, meaning that the character will
			* keep moving in the set direction, until you stop() it. Manually controlling a character offers no absolute control as the
			* laws of acceleration and max speed still apply to an agent, as well as the fact that it cannot steer off the navmesh or into other agents.
			* You will notice small corrections to steering when walking into objects or the border of the navmesh (which is usually a wall or object).
			**/
			void SetVelocity(const Vector3& Velocity);

			/**
			* Manually control the character moving it forward.
			**/
			void MoveForward();

			/**
			* Stop any movement this character is currently doing. This means losing the requested velocity or target destination.
			**/
			void Stop();

			/**
			* The current velocity (speed and direction) this character is traveling at.
			**/
			void GetVelocity(Vector3& Velocity);

			/**
			* The maximum speed this character can attain. This parameter is configured for the agent controlling this character.
			**/
			f32 GetMaxSpeed();

			/**
			* The maximum acceleration this character has towards its maximum speed. This parameter is configured for the agent controlling this character.
			**/
			f32 GetMaxAcceleration();

			/**
			* Returns true if this character is moving.
			**/
			bool IsMoving();

			/**
			* Set to true to show visual recast debugging geometry to represent the agent of this character..
			* Will be initialized to OgreRecastApplication::getDebugDrawing() at character construction.
			**/
			void SetDebugVisibility(bool Visible);

			/**
			* Set whether this character is controlled by an agent or whether it will position itself independently based on the requested velocity.
			* Set to true to let the character be controlled by an agent. Set to false to manually control it without agent, you need to set detourTileCache first.
			**/
			void SetAgentControlled(bool AgentControlled);

			/**
			* Determines whether this character is controlled by an agent.
			**/
			bool IsAgentControlled() { return isAgentControlled; }

			/**
			* Set detour tile cache component. This is needed for controlling the agent manually without agent,
			* as it will use dtTileCache to add a temporary obstacle at its current position to make other characters in the crowd avoid it.
			**/
			void SetDetourTileCache(OgreDetourTileCache* dtTileCache);

			/**
			* Makes the character clip to the terrain height of the specified terrain set. Specify NULL as terrainGroup to disable.
			* Height clipping only happens for the visiual character entity, the position of the detour crowd agent that controls it is not changed.
			**/
			void ClipToTerrain(TerrainGroup* terrainGroup);

			bool IsLoaded() const { return m_AgentId >= 0; }
			void Load();
			void Load(Vector3& Position);
			void Unload();

		protected:
			CPlayer*			m_Player;
			f32					m_DestinationRadius;
			SceneNode*			m_DebugNode;
			OgreDetourCrowd*	m_DetourCrowd;
			const dtCrowdAgent*	m_Agent;
			s32					m_AgentId;
			Vector3				m_Destination;
			Vector3				m_ManualVelocity;
			bool				isStopped;
			bool				isAgentControlled;
			OgreDetourTileCache* m_DetourTileCache;
			u32					m_TempObstacle;
			TerrainGroup*		m_ClipTo;
			RaySceneQuery*		m_RaySceneQuery;

			/**
			* Update current position of this character to the current position of its agent.
			**/
			void UpdatePosition(const f32& ElapsedTime);

			/**
			* Helper to fix the height of the character to the terrain height after a position update. Only the visual character entity's height will be
			* altered, not that of the detour crowd agent that controls it.
			**/
			void ClipToTerrainHeight();

		};

	}
}
}
#endif // __CNAVMESHVEHICLE_H__
