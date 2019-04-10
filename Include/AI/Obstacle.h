// Obstacles for use with obstacle avoidance
#ifndef OPENSTEER_OBSTACLE_H
#define OPENSTEER_OBSTACLE_H

#include "Defines.h"
#include "LocalSpace.h"
#include "AbstractVehicle.h"

namespace Core 
{
namespace AI
{
    // Forward declaration.
    class Color;

    class CORE_EXPORT AbstractObstacle
    {
    public:

        virtual ~AbstractObstacle() { }

        // compute steering for a vehicle to avoid this obstacle, if needed
        virtual Vector3 steerToAvoid (const AbstractVehicle& v, const float minTimeToCollision) const = 0;

        // PathIntersection object: used internally to analyze and store
        // information about intersections of vehicle paths and obstacles.
        class PathIntersection
        {
        public:
            bool intersect; // was an intersection found?
            float distance; // how far was intersection point from vehicle?
            Vector3 surfacePoint; // position of intersection
            Vector3 surfaceNormal; // unit normal at point of intersection
            Vector3 steerHint; // where to steer away from intersection
            bool vehicleOutside; // is the vehicle outside the obstacle?
            const AbstractObstacle* obstacle; // obstacle the path intersects

            // determine steering based on path intersection tests
            Vector3 steerToAvoidIfNeeded (const AbstractVehicle& vehicle,
                                       const float minTimeToCollision) const;

        };

        // find first intersection of a vehicle's path with this obstacle
        // (this must be specialized for each new obstacle shape class)
        virtual void findIntersectionWithVehiclePath (const AbstractVehicle& vehicle, PathIntersection& pi) const = 0 ;

        // seenFrom (eversion): does this obstacle contrain vehicle to stay
        // inside it or outside it (or both)?  "Inside" describes a clear space
        // within a solid (for example, the interior of a room inside its
        // walls). "Ouitside" describes a solid chunk in the midst of clear
        // space.
        enum seenFromState {outside, inside, both};
        virtual seenFromState seenFrom (void) const = 0;
        virtual void setSeenFrom (seenFromState s) = 0;

		// Obstacle Type
		enum OBSTACLE_TYPE
		{
			OT_SPHERE	 = 0,
			OT_BOX		 = 1,
		};

	protected:
		OBSTACLE_TYPE m_ObstacleType;
    };


	class Obstacle;

    // an STL vector of AbstractObstacle pointers and an iterator for it:
    typedef std::vector<Obstacle*> ObstacleGroup;
    typedef ObstacleGroup::const_iterator ObstacleIterator;


    // ----------------------------------------------------------------------------
    // Obstacle is a utility base class providing some shared functionality
    class CORE_EXPORT Obstacle : public AbstractObstacle
    {
    public:

        Obstacle (void) : _seenFrom (outside), radius(0) {}

        virtual ~Obstacle() { }
        
		virtual Vector3 getPosition() = 0;

        // compute steering for a vehicle to avoid this obstacle, if needed 
        Vector3 steerToAvoid (const AbstractVehicle& v, const float minTimeToCollision) const;

        // static method to apply steerToAvoid to nearest obstacle in an ObstacleGroup
        static Vector3 steerToAvoidObstacles(const AbstractVehicle& vehicle, const float minTimeToCollision, const ObstacleGroup& obstacles);

        // static method to find first vehicle path intersection in an ObstacleGroup
        static void FirstPathIntersectionWithObstacleGroup(const AbstractVehicle& vehicle, const ObstacleGroup& obstacles, PathIntersection& nearest, PathIntersection& next);

		// Find the closest obstacle to the vehicle
		static Obstacle* closestObstacle(AbstractVehicle* vehicle, const ObstacleGroup& obstacles);

        seenFromState seenFrom (void) const { return _seenFrom; }
        void setSeenFrom (seenFromState s) { _seenFrom = s; }

		OBSTACLE_TYPE getObstacleType() { return m_ObstacleType; }

		float radius;

    private:
        seenFromState _seenFrom;
    };


    // ----------------------------------------------------------------------------
    // SphereObstacle a simple ball-shaped obstacle
    class CORE_EXPORT SphereObstacle : public Obstacle
    {
    public:
        Vector3 center;

        // constructors
		SphereObstacle (float r, Vector3 c) : center (c) 
		{ 
			m_ObstacleType = AbstractObstacle::OT_SPHERE;
			radius = r;
		}

		Vector3 getPosition() { return center; }

        virtual ~SphereObstacle() { }
        
        // find first intersection of a vehicle's path with this obstacle
        void findIntersectionWithVehiclePath (const AbstractVehicle& vehicle, PathIntersection& pi) const;
    };


    // ----------------------------------------------------------------------------
    // LocalSpaceObstacle: a mixture of LocalSpace and Obstacle methods
     typedef LocalSpaceMixin<Obstacle> LocalSpaceObstacle;


    // ----------------------------------------------------------------------------
    // BoxObstacle: a box-shaped (cuboid) obstacle of a given height, width,
    // depth, position and orientation.  The box is centered on and aligned
    // with a local space.
    class CORE_EXPORT BoxObstacle : public LocalSpaceObstacle
    {
    public:
        float width;  // width  of box centered on local X (side)    axis
        float height; // height of box centered on local Y (up)      axis
        float depth;  // depth  of box centered on local Z (forward) axis

        // constructors
		BoxObstacle (float w, float h, float d) : width(w), height(h), depth(d) { m_ObstacleType = AbstractObstacle::OT_BOX; }
		BoxObstacle (void) :  width(1.0f), height(1.0f), depth(1.0f) { m_ObstacleType = AbstractObstacle::OT_BOX; }

        virtual ~BoxObstacle() { }

		Vector3 getPosition() { return Position(); }
        
        
        // find first intersection of a vehicle's path with this obstacle
        void findIntersectionWithVehiclePath (const AbstractVehicle& vehicle, PathIntersection& pi) const;
    };


    // ----------------------------------------------------------------------------
    // PlaneObstacle: a planar obstacle of a given position and orientation.
    // The plane is defined as the XY (aka side/up) plane of a local space.
    // The +Z (forward) half-space is considered "outside" the obstacle.  
    //
    // This is also the base class for several other obstacles which represent
    // 2d shapes (rectangle, triangle, ...) arbitarily oriented and positioned
    // in 2d space.  They specialize this class via xyPointInsideShape which
    // tests if a given point on the XZ plane is inside the obstacle's shape.
    class CORE_EXPORT PlaneObstacle : public LocalSpaceObstacle
    {
    public:
        // constructors
        PlaneObstacle (void) { }
        PlaneObstacle (const Vector3& s,
                       const Vector3& u,
                       const Vector3& f,
                       const Vector3& p) : LocalSpaceObstacle( s, u, f, p ) { }

		Vector3 getPosition() { return Position(); }

        // find first intersection of a vehicle's path with this obstacle
        void findIntersectionWithVehiclePath (const AbstractVehicle& vehicle, PathIntersection& pi) const;

        // determines if a given point on XY plane is inside obstacle shape
        virtual bool xyPointInsideShape (const Vector3& /*point*/, float /*radius*/) const
        {
            return true; // always true for PlaneObstacle
        }
    };


    // ----------------------------------------------------------------------------
    // RectangleObstacle: a rectangular obstacle of a given height, width,
    // position and orientation.  It is a rectangle centered on the XY (aka
    // side/up) plane of a local space.
    class CORE_EXPORT RectangleObstacle : public PlaneObstacle
    {
    public:
        float width;  // width  of rectangle centered on local X (side) axis
        float height; // height of rectangle centered on local Y (up)   axis

        // constructors
        RectangleObstacle (float w, float h) : width(w), height(h) {}
        RectangleObstacle (void) :  width(1.0f), height(1.0f) {}
        RectangleObstacle (float w, float h, const Vector3& s,
                           const Vector3& u, const Vector3& f, const Vector3& p,
                           seenFromState sf) : PlaneObstacle( s, u, f, p ), width(w), height(h) { setSeenFrom (sf); }

		Vector3 getPosition() { return Position(); }
        
        virtual ~RectangleObstacle() { /* Nothing to do. */ }

        // determines if a given point on XY plane is inside obstacle shape
        bool xyPointInsideShape (const Vector3& point, float radius) const;
    };


}
}   

#endif // OPENSTEER_OBSTACLE_H
