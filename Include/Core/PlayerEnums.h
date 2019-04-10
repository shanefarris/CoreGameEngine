#ifndef __PLAYERENUMS_H__
#define __PLAYERENUMS_H__

namespace Core
{
	// Generic list of teams that can be assigned to a player
	// Note: When E_PLAYER_TEAM is passed as a parameter, there shouldn't be a check to see if the value is more then the number of teams, this
	// enum should be considered correct in a production environment
	enum E_PLAYER_TEAM
	{
		EPT_TEAM_1 = 0,		// Civilians
		EPT_TEAM_2 = 1,		// Default Human player
		EPT_TEAM_3 = 2,		// Default Computer
		EPT_TEAM_4 = 3,		// Other
		EPT_TEAM_5 = 4,		// Other
		EPT_TEAM_6 = 5,		// Other
		EPT_TEAM_7 = 6,		// Other
		EPT_TEAM_8 = 7,		// Other
		EPT_TEAM_9 = 8,		// Other
		EPT_TEAM_10= 9,		// Other
		EPT_TEAM_COUNT = 10,
		// This should match "NUM_TEAMS" in defines.h
	};

	// What the player is doing, different then the animations.  Might be combined with the character AI states
	enum E_PLAYER_STATE
	{	
		EPS_IDLE			 = 0,
		EPS_DIEING			 = 1,	// Health will still have to be more then 0.0f
		EPS_DEAD			 = 2,	// When health is <= 0.0f
		EPS_RUNNING			 = 3,
		EPS_ATTACKING		 = 4,
		EPS_WAITING			 = 5,
		EPS_WALKING			 = 6,
		EPS_WANDERING		 = 7,
		EPS_EVADING			 = 8,
		EPS_SEEK_ENEMY		 = 9,	// Seek an enemy
		EPS_SEEK_OBS		 = 10,	// Seek an obstacle
		EPS_SEEK_ITEM		 = 11,	// Seek an item
		EPS_FIND_ENEMY		 = 12,	// Find an enemy
		EPS_DEFEND			 = 13,	// Stand your ground
		EPS_NONE			 = 14,
		EPS_COUNT			 = 15
	};

	// Type of LoS strategy
	enum E_LOS_TYPE
	{
		ELT_BASIC		= 0,
		ELT_TRIANGLE	= 1,
		ELT_RANGE_BASIC	= 2
	};
}

#endif // __PLAYERENUMS_H__