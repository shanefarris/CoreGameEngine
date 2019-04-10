#ifndef __PHYSICS_STRUCTURES_H__
#define __PHYSICS_STRUCTURES_H__

#include "OgreVector3.h"

namespace Core
{
namespace Physics
{
	class IPhysicsStrategy;
	class CPhysicsProfile;

	enum E_PHYSICS_SHAPE
	{
		SHAPE_CUBE				= 0,
		SHAPE_SPHERE			= 1,
		SHAPE_CAPSULE			= 2,
		SHAPE_CYLINDER			= 3,
		SHAPE_CONE				= 4,
		SHAPE_STATIC_TRIMESH	= 5,
		SHAPE_TRIMESH			= 6,
		SHAPE_PLANE				= 7,
	};

	enum E_BODY_TYPE
	{
		NONE				= 0,
		BUILDING			= 1 << 0,
		PLAYER				= 1 << 1,
		GAME_OBJECT			= 1 << 2,
		VEHICLE				= 1 << 3,
		STATIC_GEOMETRY		= 1 << 4,
		VOLUME				= 1 << 5,
		TERRAIN				= 1 << 6,
	};

	enum E_VOLUME_TYPE
	{
		EVT_CUBE	= 0,
		EVT_SPHERE	= 1,
		EVT_CAPSULE = 2,
	};

	struct VolumePackage
	{
		VolumePackage() : Profile(nullptr), Strategy(nullptr), Scale(1.0f), isRemoveCallback(true), EnableRaycast(false) { }

		CPhysicsProfile*	Profile;				// Standard phyiscs information
		IPhysicsStrategy*	Strategy;				// Used to created the volume
		f32					Scale;					// Scale the size of the volume
		bool				isRemoveCallback;		// If the callback should be called again (usually not)
		bool				EnableRaycast;			// Can ray casts be used on this volume
	};

	struct SPhysicsRayCastReport
	{
		SPhysicsRayCastReport() : Data(nullptr), Position(INVALID_POS) { }

		void*		Data;
		E_BODY_TYPE	BodyType;
		Vector3		Position;		// Point of contact
	};

}
}

#endif // __PHYSICS_STRUCTURES_H__