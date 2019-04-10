#ifndef __CORE_STRUCTURES_H__
#define __CORE_STRUCTURES_H__

#include "Defines.h"

namespace Core
{
	class CPlayer;
	class CInventoryItem;
	enum E_PLAYER_TEAM;

	enum E_CAMERA_MODE
	{
		ECM_CHASE	 = 0,
		ECM_FIXED	 = 1,		// Stays in one place and looks at the same thing
		ECM_FPS		 = 2,
		ECM_TOP_DOWN = 3,
		ECM_SIDE	 = 4,
		ECM_FREE	 = 5,		// Will collide with the environment
		ECM_GOD		 = 6,		// Goes through anything
		ECM_RTS		 = 7,		// Different then top down because of mouse control
		ECM_SPRING	 = 8,
		ECM_CSS		 = 9,		// Chase space ship
		ECM_NONE	 = 10		// Used for returning errors
	};

	// An enum for all types of drivers
	enum E_DRIVER_TYPE
	{
		EDT_NULL		= 0,	// Null driver
		EDT_DIRECT3D9	= 1,	// Direct3D 9 device
		EDT_DIRECT3D10	= 2,	// Direct3D 10 device
		EDT_OPENGL		= 3,	// OpenGL device
		EDT_DIRECT3D11	= 4,	// Direct3D 11 device
	};

	enum SCENE_QUERY_FLAGS
	{
		SQF_NONE			= 0,
		SQF_TERRAIN			= 1<<0,
		SQF_PLAYER			= 1<<1,
		SQF_INVENTORY_ITEM	= 1<<2,
		SQF_EDITOR			= 1<<3,
		SQF_OBSTACLE		= 1<<4,
		SQF_BUILDING		= 1<<5,
		SQF_VEHICLE			= 1<<6,
		SQF_EFFECT			= 1<<7,
		SQF_NAVMESH			= 1<<8,
		SQF_GAMEOBJECT		= 1<<9,

		// Future possible queries
		// vegetation
		// water
		// editor objects
	};

	// Standard light found in every engine
	enum LIGHT_TYPE
	{
		LT_POINT = 0,
		LT_DIRECTIONAL,
		LT_SPOT
	};

	// Needs to be defined specifically for the physics strategy used
	struct CoreEntityObject
	{
		CoreEntityObject()
		{
			Player = nullptr;
			Item = nullptr;
		}

		SCENE_QUERY_FLAGS	 QueryType;
		CPlayer*			 Player;
		CInventoryItem*		 Item;
	};

	enum ENVIRONMENT_ATTRIBUTE_TYPE
	{
		EAT_NONE		= 0,			// There is no attribute assign (usually will have no AI interaction)
		EAT_PICKUP		= 1,			// Something that will enhance the player (food, health, ammo)
		EAT_DANGEROUS	= 2,			// Something that could be dealy to the player (trap, enemy)
		EAT_NEUTRAL		= 3,			// Neither good or bad (stupid things like in King's Quest)
		EAT_MISSION		= 4,			// Could be safe or dangerous, but it is needed for a mission
		EAT_UNKNOWN		= 5,			// Unknown to the player
		EAT_EDITOR		= 6,			// Used only in an editor and should not be saved
	};

	enum E_LOAD_TYPE
	{
		ELT_INSTANCE = 0,
		ELT_STATIC_GEO,
		ELT_NONE
	};
}

#endif // __CORE_STRUCTURES_H__