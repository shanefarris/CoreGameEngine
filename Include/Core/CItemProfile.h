#ifndef __IITEMPROFILE_H__
#define __IITEMPROFILE_H__

#include "Defines.h"
#include "CoreStructures.h"
#include "OgreVector3.h"

namespace Core
{
	class IItemFactory;
	
	enum INVENTORY_TYPE
	{
		EIT_WEAPON,
		EIT_MAGAZINE,
		EIT_PROJECTILE,
		EIT_MELEE,
		EIT_TOOL
	};

	class CItemProfile
	{
	public:
		CItemProfile(INVENTORY_TYPE Type) 
			: InventoryType(Type), 
			Capacity(0), 
			UseTime(1.0f), 
			Range(0.0f), 
			Power(0.0f),
			Scale(Vector3::UNIT_SCALE) 
		{ 
		}

		virtual ~CItemProfile() { }

		String			Name;			// Name used to look up this profile
		INVENTORY_TYPE	InventoryType;

		u32			Capacity;			// Max number of times it can be used
		f32			Range;				// Range of the weapon
		f32			UseTime;			// Reset time for the player to use again
		f32			Power;
		String		MeshName;			// File name of the mesh to use
		String		OverlayName;		// Name to locate the overlay
		String		Desc;
		Vector3		Scale;				// Scale of the mesh

	};
}

#endif // __IITEMPROFILE_H__