/*
 * This will be the state of every character in a level.  The state can have 1 to many actions to react to 
 * the state (I am hungry so I need to 1. stand up, 2 walk to food, 3 eat, new state is full).  The running
 * state will dictate the actions and if they need to be interupted for any reason, and moved to a new state.
 * A character can only have one state at a time.
 * State = Goal, Action = steps to complete the goal
 */

#ifndef __ICHARACTERSTATE_H__
#define __ICHARACTERSTATE_H__

#include "Defines.h"

namespace Core
{
	class CPlayer;
	enum E_PLAYER_STATE;
}

namespace Core
{
namespace AI
{
	// Outcome or current status of the state.
	enum E_CHARACTER_STATE_OUTCOME
	{
		SUCCESS = 0,		// State is done and should be replaced with a new state
		FAILED,				// State is still done and needs to be replaced
		WORKING,			// Still working at completing our goal
		IMPOSSIBLE,			// Failed, but we can look into seeing why it is impossible
	};

	class CCharacterState
	{
	public:
		CCharacterState(CPlayer* Player) : m_Player(Player), m_Level(0), m_StateLabel(0) { }

		virtual E_CHARACTER_STATE_OUTCOME	Update(f32 elapsedTime) = 0;
		E_CHARACTER_STATE_OUTCOME			GetOutcomeState() { return m_State; }
		E_PLAYER_STATE						GetStateType() { return m_StateType; }
		const char*							GetStateName() { return m_StateLabel; }
		u32									GetLevel() { return m_Level; }

	protected:
		E_CHARACTER_STATE_OUTCOME  m_State;			// The current state of this state
		E_PLAYER_STATE			   m_StateType;		// High level category of the state
		const char*				   m_StateLabel;	// Name of the state
		u32						   m_Level;			// Level of complexity, higher the level, more complex and intelligent 
		CPlayer*				   m_Player;		// Player this state is for
	};	
}
}

#endif