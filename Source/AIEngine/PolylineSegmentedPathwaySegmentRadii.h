// Segmented pathway build of polylines. Every segmented is associated with its own radius.
#ifndef OPENSTEER_POLYLINESEGMENTEDPATHWAYSEGMENTRADII_H
#define OPENSTEER_POLYLINESEGMENTEDPATHWAYSEGMENTRADII_H

#include <vector>

#include "SegmentedPathway.h"
#include "PolylineSegmentedPath.h"
#include "QueryPathAlikeBaseDataExtractionPolicies.h"
#include "Defines.h"
#include "Vec3Utilities.h"

namespace Core 
{
namespace AI
{ 
    /**
     * Segmented pathway build by polylines that associates every segment with 
     * its own radius.
     */
    class PolylineSegmentedPathwaySegmentRadii : public SegmentedPathway 
	{
    public:
        PolylineSegmentedPathwaySegmentRadii();
        
        /**
         * Constructs a segmented pathway consisting of @a numOfPoints @a points
         * associating every segment with its own radius @a radii.
         *
         * If @a closedCycle is @c false @a radii must have 
         * <code>numOfPoints - 1</code> elements, for every segment one. If
         * @a closedCycle is @c true <code>numOfPoints</code> @a radii
         * elements are needed.
         *
         * There mustn't be two adjacent points that are equal. The first and 
         * last point mustn't be identical, too.
         */
        PolylineSegmentedPathwaySegmentRadii( u32 numOfPoints,
                                              Vector3 const points[],
                                              float const radii[],
                                              bool closedCycle );
        PolylineSegmentedPathwaySegmentRadii( PolylineSegmentedPathwaySegmentRadii const& other );
        virtual ~PolylineSegmentedPathwaySegmentRadii();
        
        PolylineSegmentedPathwaySegmentRadii& operator=( PolylineSegmentedPathwaySegmentRadii other );
        
        /**
         * Swaps the content with @a other.
         */
        void swap( PolylineSegmentedPathwaySegmentRadii& other );
        
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
         * @param points Moved points to replace the old ones.
         */
        void movePoints( u32 startIndex,
                         u32 numOfPoints,
                         Vector3 const points[] );
        /**
         * Replaces the pathway information completely.
         *
         * If @a closedCycle is @c true then the pathway has @a numOfPoints
         * segments and the first point is duplicated and added as the last
         * point to represent the end point of the segment closing the pathway
         * cycle. If @a closedCycle is false the pathway has 
         * <code>numOfPoints - 1</code> segments.
         * 
         * If @a closedCycle is @c false @a radii must have 
         * <code>numOfPoints - 1</code> elements, for every segment one. If
         * @a closedCycle is @c true provide <code>numOfPoints</code> @a radii
         * elements.
         *
         * @param numOfPoints Number of points defining the pathway.
         * @param points The actual points.
         * @param radii Radii of the segments.
         * @param closedCycle @c true if the pathway is cyclic, @a false 
         *        otherwise.
         */
        void setPathway( u32 numOfPoints,
                         Vector3 const points[],
                         float const radii[],
                         bool closedCycle );
        
        /**
         * Returns the radius of the segment @a segmentIndex.
         */
        float segmentRadius( u32 segmentIndex ) const;
        
        /**
         * Sets the radius @a r of the segment @a segmentIndex.
         */
        void setSegmentRadius( u32 segmentIndex, float r );
        
        /**
         * Replace @a numOfRadii segment radii starting with segment 
         * @a startIndex with the elements of @a radii.
         *
         * <code>startIndex + numOfRadii</code> must be lesser or equal to 
         * @c segmentCount.
         *
         * @todo Write unit test.
         */
        void setSegmentRadii( u32 startIndex, u32 numOfRadii, float const radii[] );
        
        virtual bool isValid() const;
        virtual Vector3 mapPointToPath (const Vector3& point,
                                     Vector3& tangent,
                                     float& outside) const;
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
        PolylineSegmentedPath path_;
        std::vector< float > segmentRadii_; 
    }; // class PolylineSegmentedPathwaySegmentRadii
    
    /**
     * Swaps the content of @a lhs and @a rhs.
     */
    inline void swap( PolylineSegmentedPathwaySegmentRadii& lhs, PolylineSegmentedPathwaySegmentRadii& rhs ) 
	{
        lhs.swap( rhs );
    }
    
    /**
     * Extracts the base data of @c PolylineSegmentedPathwaySegmentRadii.
     */
    template<> class PointToPathAlikeBaseDataExtractionPolicy< PolylineSegmentedPathwaySegmentRadii > 
	{
    public:
            
        static void extract( PolylineSegmentedPathwaySegmentRadii const& pathAlike,
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
        * Extracts the base data of @c PolylineSegmentedPathwaySegmentRadii.
     */
    template<> class CORE_EXPORT DistanceToPathAlikeBaseDataExtractionPolicy< PolylineSegmentedPathwaySegmentRadii > 
	{
    public:
        static void extract( PolylineSegmentedPathwaySegmentRadii const& pathAlike,
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


#endif // OPENSTEER_POLYLINESEGMENTEDPATHWAYSEGMENTRADII_H
