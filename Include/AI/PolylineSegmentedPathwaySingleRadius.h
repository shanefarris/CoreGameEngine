// Segmented pathway build of polylines. The whole path has one associated radius.
#ifndef OPENSTEER_POLYLINESEGMENTEDPATHWAYSINGLERADIUS_H
#define OPENSTEER_POLYLINESEGMENTEDPATHWAYSINGLERADIUS_H

#include "SegmentedPathway.h"
#include "QueryPathAlikeBaseDataExtractionPolicies.h"
#include "Defines.h"
#include "Vec3Utilities.h"

namespace Core 
{
namespace AI
{ 
	class PolylineSegmentedPath;

    /**
     * Segmented pathway build by polylines with a single radius for the whole
     * pathway.
     */
    class CORE_EXPORT PolylineSegmentedPathwaySingleRadius : public SegmentedPathway 
	{
    public:
        PolylineSegmentedPathwaySingleRadius();
        explicit PolylineSegmentedPathwaySingleRadius( float r );
        PolylineSegmentedPathwaySingleRadius( u32 numOfPoints,
                                              Vector3 const points[],
                                              float r,
                                              bool closeCycle );
        PolylineSegmentedPathwaySingleRadius( PolylineSegmentedPathwaySingleRadius const& other );
        virtual ~PolylineSegmentedPathwaySingleRadius();
        PolylineSegmentedPathwaySingleRadius& operator=( PolylineSegmentedPathwaySingleRadius other );
        
        /**
         * Swaps the content with @a other.
         */
        void swap( PolylineSegmentedPathwaySingleRadius& other );
        
        /**
         * Replaces @a numOfPoints points starting at @a startIndex.
         *
         * In the resulting sequence of points there mustn't be two adjacent 
         * ones that are equal. The first and last point mustn't be identical,
         * too.
         *
         * If the first point is changed and the path is cyclic the duplication
         * of the first point at the end of the sequence representing the
         * path closing segment is updated automatically.
         *
         * @param startIndex First point to be moved or replaced.
         * @param numOfPoints Number of points to move or replace. 
         *                    <code> numOfPoints + startIndex </code> must be
         *                    lesser or equal to @c pointCount.
         * @param newPointValues Moved points to replace the old ones.
         */
        void movePoints( u32 startIndex, u32 numOfPoints, Vector3 const newPointValues[] );

        /**
         * Replaces the pathway information completely.
         *
         * If @a closedCycle is @c true then the pathway has @a numOfPoints
         * segments and the first point is duplicated and added as the last
         * point to represent the end point of the segment closing the pathway
         * cycle. If @a closedCycle is false the pathway has 
         * <code>numOfPoints - 1</code> segments.
         *
         * @param numOfPoints Number of points defining the pathway.
         * @param points The actual points.
         * @param r Radius of the whole pathway.
         * @param closedCycle @c true if the pathway is cyclic, @a false 
         *        otherwise.
         */
        void setPathway( u32 numOfPoints, Vector3 const points[], float r, bool closedCycle );
        
        /**
         * Sets the radius of the whole pathway to @a r.
         */
        void setRadius( float r );
        
        /**
         * Returns the pathway radius.
         */
        float Radius() const;
        
        
        virtual bool isValid() const;
		virtual Vector3 mapPointToPath (const Vector3& point, Vector3& tangent, float& outside) const;
		virtual Vector3 mapPathDistanceToPoint (float pathDistance) const;
		virtual float mapPointToPathDistance (const Vector3& point) const;
        virtual bool isCyclic() const;
        virtual float length() const;
        
        virtual u32 pointCount() const;
        virtual Vector3 point( u32 pointIndex ) const;
        
        virtual u32 segmentCount() const;
        virtual float segmentLength( u32 segmentIndex ) const;
        virtual Vector3 segmentStart( u32 segmentIndex ) const;
        virtual Vector3 segmentEnd( u32 segmentIndex ) const;
        virtual float mapPointToSegmentDistance( u32 segmentIndex, Vector3 const& point ) const;
        virtual Vector3 mapSegmentDistanceToPoint( u32 segmentIndex, float segmentDistance ) const;
        virtual float mapSegmentDistanceToRadius( u32 segmentIndex, float distanceOnSegment ) const;
        virtual Vector3 mapSegmentDistanceToTangent( u32 segmentIndex, float segmentDistance ) const;
        virtual void mapDistanceToSegmentPointAndTangentAndRadius( u32 segmentIndex,
                                                                   float segmentDistance,
                                                                   Vector3& pointOnPath,
                                                                   Vector3& tangent,
                                                                   float& radius ) const;
        virtual void mapPointToSegmentDistanceAndPointAndTangentAndRadius( u32 segmentIndex,
                                                                           Vector3 const& point,
                                                                           float& distance,
                                                                           Vector3& pointOnPath,
                                                                           Vector3& tangent,
                                                                           float& radius) const;
         
    private:
        PolylineSegmentedPath* path_;
        float radius_;
    }; // class PolylineSegmentedPathwaySingleRadius
    
    
    /**
     * Swaps the content of @a lhs and @a rhs.
     */
    inline void swap( PolylineSegmentedPathwaySingleRadius& lhs, 
               PolylineSegmentedPathwaySingleRadius& rhs ) 
	{
        lhs.swap( rhs );
    }
    
    
    /**
     * Extracts the base data of @c PolylineSegmentedPathwaySingleRadius.
     */
    template<> class PointToPathAlikeBaseDataExtractionPolicy< PolylineSegmentedPathwaySingleRadius > 
	{
    public:
        static void extract( PolylineSegmentedPathwaySingleRadius const& pathAlike,
                             u32 segmentIndex,
                             Vector3 const& point, 
                             float& segmentDistance, 
                             float& radius, 
                             float& distancePointToPath, 
                             Vector3& pointOnPathCenterLine, 
                             Vector3& tangent ) 
		{
            pathAlike.mapPointToSegmentDistanceAndPointAndTangentAndRadius( segmentIndex, point, segmentDistance, pointOnPathCenterLine, tangent, radius );
			distancePointToPath = Vec3Utilities::distance( point, pointOnPathCenterLine ) - radius;
        }
            
    }; // class PointToPathAlikeBaseDataExtractionPolicy
    
    
    /**
     * Extracts the base data of @c PolylineSegmentedPathwaySingleRadius.
     */
    template<> class CORE_EXPORT DistanceToPathAlikeBaseDataExtractionPolicy< PolylineSegmentedPathwaySingleRadius > 
	{
    public:
        static void extract( PolylineSegmentedPathwaySingleRadius const& pathAlike,
                             u32 segmentIndex,
                             float segmentDistance, 
                             Vector3& pointOnPathCenterLine, 
                             Vector3& tangent, 
                             float& radius )  
		{
            pathAlike.mapDistanceToSegmentPointAndTangentAndRadius( segmentIndex, segmentDistance, pointOnPathCenterLine, tangent, radius );     
        }
        
        
    }; // DistanceToPathAlikeBaseDataExtractionPolicy 
    
} 
}


#endif // OPENSTEER_POLYLINESEGMENTEDPATHWAYSINGLERADIUS_H
