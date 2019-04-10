#ifndef __CCHARACTERSTATEMANAGER_H__
#define __CCHARACTERSTATEMANAGER_H__

#include "Defines.h"

namespace Core
{
	class CPlayer;
	class CPluginManager;
	enum E_PLAYER_STATE;

	namespace Plugin
	{
		class IAiStateFactory;
	}

	namespace AI
	{
		class CCharacterState;
		enum E_CHARACTER_STATE_OUTCOME;

		typedef Map<String, Vector<Vector3>> PathDefinition;

		class CORE_EXPORT CCharacterStateManager
		{
		public:
			static CCharacterStateManager* Instance();

			~CCharacterStateManager();

			// Use this overloaded method to let the manager determine the correct exact state based on the player,
			// the attributes of the player, and the "level" of complexity
			CCharacterState* GetState(E_PLAYER_STATE Type, CPlayer* Player, u32 Level = 1);

			// Use this overloaded method to set the exact state, and don't let the manager decide the state for you.
			CCharacterState* GetState(const char* StateName, CPlayer* Player);

			void GetAllStates(Vector<const char*>& States);
			void GetLoadedStates(Vector<String>& Names);

			// Path Methods
			void AddPath(const char* Name, const Vector<Vector3>& Paths);
			u32  GetPathCount();
			bool GetPathByName(const char* Name, Vector<Vector3>& Path);
			bool GetPathByIndex(u32 Index, Vector<Vector3>& Path, char** Name = nullptr);
			bool GetPathByPoint(const Vector3& Point, Vector<Vector3>& Path, char** Name = nullptr);
			void GetAllPaths(PathDefinition& Paths);
			bool SetName(const char* OldName, const char* NewName);

			// Movement
			E_CHARACTER_STATE_OUTCOME SeekVehicle(CPlayer* Player, const f32& elapsedTime);
			E_CHARACTER_STATE_OUTCOME SeekVehicle(CPlayer* Player, const f32& elapsedTime, const f32& Radius);
			E_CHARACTER_STATE_OUTCOME SeekPosition(CPlayer* Player, const Vector3& Position, const f32& elapsedTime);
			E_CHARACTER_STATE_OUTCOME Wander(CPlayer* Player, const f32& elapsedTime);
			E_CHARACTER_STATE_OUTCOME Search(CPlayer* Player, const f32& elapsedTime);
			E_CHARACTER_STATE_OUTCOME CenterOfMass(const Vector<CPlayer*> Group, CPlayer* Player, const f32& elapsedTime, const f32& MaxDistance, 
				const f32& CosMaxAngle = -0.15f);
			E_CHARACTER_STATE_OUTCOME AlignWithGroup(const Vector<CPlayer*> Group, CPlayer* Player, const f32& elapsedTime, const f32& MaxDistance, 
				const f32& CosMaxAngle = -0.15f);
			E_CHARACTER_STATE_OUTCOME SeparateFromGroup(const Vector<CPlayer*> Group, CPlayer* Player, const f32& elapsedTime, const f32& MaxDistance, 
				const f32& CosMaxAngle = -0.15f);
			E_CHARACTER_STATE_OUTCOME EvadeVehicle(CPlayer* Player, CPlayer* Menace, const f32& elapsedTime, const f32& MaxPredictionTime);

		private:
			CCharacterStateManager();
			void Init();
			void MoveVehicle(CPlayer* Player);
			void Avoidance(CPlayer* Player, Vector3& SteeringAvoidance);

			static CCharacterStateManager*		CharacterStateManager;
			CPluginManager*						m_PluginManager;
			PathDefinition						m_Paths;				// All the paths in the game are stored here
			Vector<Plugin::IAiStateFactory*>	m_States;

		};
	}
}

#endif // __CCHARACTERSTATEMANAGER_H__
