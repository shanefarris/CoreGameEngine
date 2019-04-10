#ifndef _OGREODESPACE_H_
#define _OGREODESPACE_H_

#include "PreReqs.h"
#include "OgreAxisAlignedBox.h"

namespace Ode 
{
	class Space
	{
        friend class Geometry;
		friend class World;
	
	public:
		enum Class
		{
			Class_SimpleSpace		= dSimpleSpaceClass,
			Class_HashSpace			= dHashSpaceClass,
			Class_SweepAndPrune		= dSweepAndPruneSpaceClass,
			Class_QuadTree			= dQuadTreeSpaceClass,
			Class_FirstUser			= dFirstUserClass,
			Class_LastUser			= dLastUserClass
		};

	public:
		Space(World *world, const Space* space = 0);
		virtual ~Space();

		Space::Class getClass(); 

		void registerSpace();

		void setAutoCleanup(bool on); 
		bool getAutoCleanup(); 

		void addGeometry(const Geometry& geometry); 
		void removeGeometry(const Geometry& geometry); 
		bool containsGeometry(const Geometry& geometry); 
		int getGeometryCount(); 
		Geometry* getGeometry(int index);

		virtual void collide(void* data = 0);
		virtual void collide(Space* space,void* data = 0);
		virtual void collide(Geometry* geometry,void* data = 0);
		
		
		virtual void collide(CollisionCallback* colCallback, bool useInternalCollisionFlag = true);
		virtual void collide(CollisionCallback* colCallback, Space* space);
		virtual void collide(CollisionCallback* colCallback, Geometry* geometry, bool useInternalCollisionFlag = true);
		
		
		void setInternalCollisions(bool collide);
		bool getInternalCollisions();

		virtual const Ogre::AxisAlignedBox& getAxisAlignedBox(); 

		virtual size_t getID();

		World* getWorld(){ return _world; }

		dSpaceID getSpaceID() const;
		dSpaceID getSpaceID(const Space* space) const;

	protected:
		dSpaceID                _space;
		bool                    _internal_collisions;
		Ogre::AxisAlignedBox    _bounding_box;
        World                   *_world;
	};

	class SimpleSpace:public Space
	{
	public:
		SimpleSpace(World *world, const Space* space = 0);
		~SimpleSpace();
	};

	class HashTableSpace:public Space
	{
	public:
		HashTableSpace(World *world, const Space* space = 0);
		~HashTableSpace();

		void setLevels(int min_level,int max_level);
		int getMinimumLevel();
		int getMaximumLevel();
	};

	class QuadTreeSpace:public Space
	{
	public:
		QuadTreeSpace(const Vector3& center, const Vector3& extents, int depth,World *world, const Space* space = 0);
		~QuadTreeSpace();
    };
	
	class SweepAndPruneSpace : public Space
	{
	public:
		enum AxisOrder
		{
			AxisOrder_XYZ = dSAP_AXES_XYZ,
			AxisOrder_XZY = dSAP_AXES_XZY,
			AxisOrder_YXZ = dSAP_AXES_YXZ,
			AxisOrder_YZX = dSAP_AXES_YZX,
			AxisOrder_ZXY = dSAP_AXES_ZXY,
			AxisOrder_ZYX = dSAP_AXES_ZYX
		};
		
		// "Order XZY or ZXY usually works best, if your Y is up."
		SweepAndPruneSpace(AxisOrder axisOrder, World *world, const Space* space = 0);
	};
	
    /*
    * use Scene manager specialized scene partition algo to find collision
    * 
    */
    class OgreSceneManagerSpace:public Space
    {
    public:
        OgreSceneManagerSpace(const Vector3& center, const Vector3& extents, int depth, SceneManager *scn_mgr, World *world, const Space* space = 0);
        ~OgreSceneManagerSpace();

        void collide(void* data = 0);

    private:
        SceneManager*					_scn_mgr;
        Ogre::IntersectionSceneQuery*	_intersection_query;

        // does scene manager has plane collision geometry support BSP scene manager has that.
        bool                            _scene_geometry;
    };

	
}

#endif

