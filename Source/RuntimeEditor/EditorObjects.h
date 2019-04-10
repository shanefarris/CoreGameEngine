#ifndef __EDITOR_OBJECTS_H__
#define __EDITOR_OBJECTS_H__

#include "Structures.h"

namespace Core
{
namespace Editor
{
	// Used in the SELECTED structure for which type of thing has been clicked on
	enum SELECTE_TYPE
	{
		ST_PATH,
		ST_ASTAR,
		ST_OBJ,
		ST_PLAYER,
		ST_SOUND_ENTITY,
		ST_VOLUME,
		ST_SPAWN_POINT,
		ST_BUILDING,
		ST_LIGHT,
		ST_NONE,
	};

	// Used for finding out what the user clicked on and decides what actions need to be taken from there
	struct SELECTED
	{
		SELECTED()
		{
			Type = ST_NONE;
			Selected = nullptr;
		}

		SELECTE_TYPE Type;
		String		 Name;
		void*		 Selected;		// Used to save a custom void* object like a player, or game object, then cast it back to it's original type.
	};

	// Used to look up in the GOM
	struct GEN_PROPERTY
	{
		GEN_PROPERTY() : Entity(0) { }

		String	Name;
		Entity*	Entity;
	};

	// The sound manager keeps track of all the sounds but the editor needs to all a node, so this struct binds them together
	struct SOUND_OBJ
	{
		SOUND_OBJ() : Entity(0), Node(0) { }
		SOUND_OBJ(Entity* e, SceneNode* n, const char* Name)
		{
			Entity = e;
			Node = n;
			SoundName = String(Name);
		}

		String		SoundName;
		Entity*		Entity;
		SceneNode*	Node;
	};
	
	// Used to store all the paged geometry created for serialization later
	struct PAGED_GEO
	{
		String	ObjectType;
		GEO_SET GeoSet;
	};

}
}

#endif // __EDITOR_OBJECTS_H__