// Abstract segmented path class for paths build of segments between waypoints.
#ifndef OPENSTEER_SEGMENTEDPATH_H
#define OPENSTEER_SEGMENTEDPATH_H

#include "Path.h"

namespace Core 
{
namespace AI
{
    /**
     * Path build by segments between points on the path.
     */
    class SegmentedPath : public Path 
	{
    public:       
		virtual ~SegmentedPath() { }
        
        /**
         * Returns the number of points defining the segments.
         *
         * This also includes the duplicated first point if the path is cyclic.
         */
        virtual u32 pointCount() const = 0;
        
        /**
         * Returns the point @a pointIndex.
         *
         * If the path is cyclic also the last point that is the duplicated
         * first one is accessible.
         */
        virtual Vector3 point( u32 pointIndex ) const = 0;
        
        
        /**
         * Returns the number of segments that build the pathway.
         */
        virtual u32 segmentCount() const = 0;
        
        /**
         * Returns the length of segment @a segmentIndex.
         */
        virtual float segmentLength( u32 segmentIndex ) const = 0;
        
        /**
         * Returns the start point of the segment @a segmentIndex.
         */
        virtual Vector3 segmentStart( u32 segmentIndex ) const = 0;
        
        /**
         * Returns the end point of segment @a segmentIndex.
         */
        virtual Vector3 segmentEnd( u32 segmentIndex ) const = 0;
        
        
        /**
         * Maps @a point to the nearest point on the center line of segment
         * @a segmentIndex and returns the distance from the segment start to 
         * this point.
         */
        virtual float mapPointToSegmentDistance( u32 segmentIndex, Vector3 const& point ) const = 0;
        
        
        /**
         * Maps @a segmentDistance to the center line of segment @a segmentIndex
         * and returns the reached point.
         *
         * If @a segmentDistance is greater or smaller than the segment length
         * is is clamped to @c 0.0f or @c segmentLength().
         */
        virtual Vector3 mapSegmentDistanceToPoint( u32 segmentIndex, float segmentDistance ) const = 0;
        
        /**
         * Maps @a segmentDistance to the centerline of the segment 
         * @a segmentIndex and returns the tangent of the pathway at the reached
         * point.
         *
         * If @a segmentDistance is greater or smaller than the segment length
         * is is clamped to @c 0.0f or @c segmentLength().
         */
        virtual Vector3 mapSegmentDistanceToTangent( u32 segmentIndex, float segmentDistance ) const = 0;
        
        
        /**
         * Combines @c mapSegmentDistanceToPoint and 
         * @c mapSegmentDistanceToTangent.
         */
        virtual void mapDistanceToSegmentPointAndTangent( u32 segmentIndex,
                                                          float distance,
                                                          Vector3& pointOnPath,
                                                          Vector3& tangent ) const = 0;
        
        
        /**
         * Combines @c mapPointToSegmentDistance, @c mapSegmentDistanceToPoint, 
         * and @c mapSegmentDistanceToTangent.
         */
        virtual void mapPointToSegmentDistanceAndPointAndTangent( u32 segmentIndex,
                                                                  Vector3 const& point,
                                                                  float& distance,
                                                                  Vector3& pointOnPath,
                                                                  Vector3& tangent ) const = 0;
        
    }; // class SegmentedPath
    
}   
}


#endif // OPENSTEER_SEGMENTEDPATH_H
