#ifndef __TREELOADER3D_PHYSICS_H__
#define __TREELOADER3D_PHYSICS_H__

#include "PagedGeometry.h"
#include "PropertyMaps.h"

#include "Defines.h"

namespace Core
{
	namespace Physics
	{
		class IPhysicsStrategy;
	}
}

namespace Forests 
{
	class TreeIterator3D_Physics;
	class TreeIterator2D_Physics;

	class CORE_EXPORT TreeLoader3D_Physics: public PageLoader
	{
	public:

		TreeLoader3D_Physics(PagedGeometry *geom, const TBounds &bounds, Core::Physics::IPhysicsStrategy* PhysicsStrategy);
		~TreeLoader3D_Physics();

		void AddTree(Entity *entity, const Vector3& Position, Quaternion Orientation, f32 Scale = 1.0f);		
		void DeleteTrees(const Vector3 &Position, f32 radius, Entity *Type = nullptr);
		void DeleteTrees(TBounds Area, Entity *type = nullptr);
		TreeIterator3D_Physics GetTrees();
		void SetColorMap(const String& MapFile, MapChannel channel = CHANNEL_COLOR);
		void SetColorMap(TexturePtr TexMap, MapChannel channel = CHANNEL_COLOR);
		ColorMap* GetColorMap() { return colorMap; }
	
		void SetColorMapFilter(MapFilter filter)
		{
			colorMapFilter = filter;
			if (colorMap)
				colorMap->setFilter(colorMapFilter);
		}

		void SetMaximumScale(f32 maxScale)
		{
			maximumScale = maxScale;
		}

		f32 GetMaximumScale()
		{
			return maximumScale;
		}

		void SetMinimumScale(f32 minScale)
		{
			minimumScale = minScale;
		}

		f32 GetMinimumScale()
		{
			return minimumScale;
		}

		inline const TBounds& GetBounds()
		{
			return actualBounds;
		}

		void loadPage(PageInfo &Page);

	private:
		friend class TreeIterator3D_Physics;

		struct TreeDef
		{
			float yPos;
			u16 xPos, zPos;
			u8 scale, rotation;
		};

		//Information about the 2D grid of pages
		s32 pageGridX, pageGridZ;
		f32 pageSize;
		TBounds gridBounds, actualBounds;

		f32 maximumScale, minimumScale;

		//Colormap
		ColorMap *colorMap;
		MapFilter colorMapFilter;

		//Misc.
		PagedGeometry *geom;

		//A std::map of 2D grid arrays. Each array is the same size (pageGridX x pageGridZ), and
		//contains a std::vector list of trees. Each std::map entry corresponds to a single tree
		//type, and every tree defined in the std::map entry's grid should be of that tree type.
		Map<Entity*, Vector<TreeDef>*> pageGridList;
		typedef Map<Entity*, Vector<TreeDef>*>::iterator PageGridListIterator;
		typedef std::pair<Entity*, Vector<TreeDef>*> PageGridListValue;

		inline Vector<TreeDef> &_getGridPage(Vector<TreeDef> *grid, int x, int z)
		{
			#ifdef _DEBUG
			if(x >= pageGridX || z >= pageGridZ )
				OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS,
				"Grid dimension is out of bounds",
				"TreeLoader2D::_getGridPage()");
			#endif

			return grid[z * pageGridX + x];
		}

		inline void _setGridPage(Vector<TreeDef> *grid, int x, int z, const Vector<TreeDef> &page)
		{
			#ifdef _DEBUG
			if(x >= pageGridX || z >= pageGridZ )
				OGRE_EXCEPT(Ogre::Exception::ERR_INVALIDPARAMS,
				"Grid dimension is out of bounds",
				"TreeLoader2D::_getGridPage()");
			#endif

			grid[z * pageGridX + x] = page;
		}
	};

	#ifndef TreeRef_Physics_Declared
	#define TreeRef_Physics_Declared

	class TreeRef_Physics
	{
	public:
		/** Returns the tree's position */
		inline Ogre::Vector3 &getPosition() { return position; }

		/** Returns the tree's yaw as a degree value */
		inline Ogre::Degree &getYaw() { return yaw; }

		/** Returns the tree's uniform scale value */
		inline Ogre::Real &getScale() { return scale; }

		/** Returns the tree's orientation as a Quaternion */
		inline Ogre::Quaternion getOrientation() { return Ogre::Quaternion(yaw, Ogre::Vector3::UNIT_Y); }

		/** Returns the entity used to create the tree */
		inline Ogre::Entity *getEntity() { return entity; }

	private:
		friend class TreeIterator2D_Physics;
		friend class TreeIterator3D_Physics;
		Ogre::Vector3 position;
		Ogre::Degree yaw;
		Ogre::Real scale;
		Ogre::Entity *entity;
	};

	#endif


	class TreeIterator3D_Physics
	{
	public:
		TreeIterator3D_Physics(TreeLoader3D_Physics *trees);

		/** Returns true if there are more trees available to be read */
		inline bool hasMoreElements() const { return hasMore; }

		/** Returns the next tree, and advances to the next */
		TreeRef_Physics getNext();

		/** Returns the next tree, without advancing to the next */
		inline TreeRef_Physics &peekNext() { return prevTreeDat; }

		/** Returns a pointer to the next tree, without advancing to the next */
		inline TreeRef_Physics *peekNextPtr() { return &prevTreeDat; }

		/** Moves the iterator on to the next tree */
		void moveNext();

	private:
		void _readTree();

		TreeLoader3D_Physics *trees;
		TreeLoader3D_Physics::PageGridListIterator currentGrid;
		int currentX, currentZ;
		Vector<TreeLoader3D_Physics::TreeDef> *currentTreeList;
		Vector<TreeLoader3D_Physics::TreeDef>::iterator currentTree;

		TreeRef_Physics currentTreeDat, prevTreeDat;
		bool hasMore;
	};

}

#endif