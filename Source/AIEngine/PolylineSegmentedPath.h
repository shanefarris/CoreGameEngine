#ifndef OPENSTEER_POLYLINESEGMENTEDPATH_H
#define OPENSTEER_POLYLINESEGMENTEDPATH_H

#include <vector>
#include "SegmentedPath.h"
#include "QueryPathAlikeBaseDataExtractionPolicies.h"

#include "Defines.h"
#include "Vec3Utilities.h"

namespace Core 
{
namespace AI
{
    /**
     * Segmented path build by polylines. The last point of the path might be 
     * connected to the first point building a closed cycle.
     */
    class PolylineSegmentedPath : public SegmentedPath 
	{
    public:
        
        /**
         * Constructs an invalid path. Behavior of most member functions is
         * undefined if a path has less than two distinct points.
         */
        PolylineSegmentedPath();
        
        /**
         * Constructs a new path.
         *
         * @param numOfPoints Number of points. Must be at least two.
         * @param newPoints As many points as indicated by @a numOfPoints. Two
         *                  adjacent points mustn't be identical and the first
         *                  the last point mustn't be identical.
         * @param closedCycle If @c true the first point of @a newPoints is
         *                    copied to the end of the path to represent the 
         *                    cycle closing segment.
         */
        PolylineSegmentedPath( u32 numOfPoints,
                               Vector3 const newPoints[],
                               bool closedCycle );
        
        PolylineSegmentedPath( PolylineSegmentedPath const& other );
        
        virtual ~PolylineSegmentedPath();
        
        PolylineSegmentedPath& operator=( PolylineSegmentedPath other );
        
        void swap( PolylineSegmentedPath& other );
        
        
        /**
         * Replaces all path information by the given ones.
         *
         * @param numOfPoints Number of points. Must be at least two.
         * @param newPoints As many points as indicated by @a numOfPoints. Two
         *                  adjacent points mustn't be identical and the first
         *                  the last point mustn't be identical.
         * @param closedCycle If @c true the first point of @a newPoints is
         *                    copied to the end of the path to represent the 
         *                    cycle closing segment.
         */
        void setPath( u32 numOfPoints,
                      Vector3 const newPoints[],
                      bool closedCycle );
        
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
         * @param newPoints Moved points to replace the old ones.
         */
        void movePoints( u32 startIndex,
                         u32 numOfPoints,
                         Vector3 const newPoints[]);
        
        
        
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
        virtual float mapPointToSegmentDistance( u32 segmentIndex, 
                                                 Vector3 const& point ) const;
        virtual Vector3 mapSegmentDistanceToPoint( u32 segmentIndex, 
                                                float segmentDistance ) const;
        virtual Vector3 mapSegmentDistanceToTangent( u32 segmentIndex, 
                                                  float segmentDistance ) const;
        
        virtual void mapDistanceToSegmentPointAndTangent( u32 segmentIndex,
                                                          float distance,
                                                          Vector3& pointOnPath,
                                                          Vector3& tangent ) const;
        
        virtual void mapPointToSegmentDistanceAndPointAndTangent( u32 segmentIndex,
                                                                  Vector3 const& point,
                                                                  float& distance,
                                                                  Vector3& pointOnPath,
                                                                  Vector3& tangent ) const;
        
    private:
        std::vector< Vector3 > points_;
        std::vector< Vector3 > segmentTangents_;
        std::vector< float > segmentLengths_;
        bool closedCycle_;
    }; // class PolylineSegmentedPath
    
    
    /**
     * Swaps the content of @a lhs and @a rhs.
     */
    inline void swap( PolylineSegmentedPath& lhs, PolylineSegmentedPath& rhs ) 
	{
        lhs.swap( rhs );
    }
    
    
    /**
     * Extracts the base data of @c PolylineSegmentedPath.
     */
    template<> class PointToPathAlikeBaseDataExtractionPolicy< PolylineSegmentedPath > 
	{
    public:
        
        static void extract( PolylineSegmentedPath const& pathAlike,
                             u32 segmentIndex,
                             Vector3 const& point, 
                             float& segmentDistance, 
                             float&, 
                             float& distancePointToPath, 
                             Vector3& pointOnPathCenterLine, 
                             Vector3& tangent ) {
            pathAlike.mapPointToSegmentDistanceAndPointAndTangent( segmentIndex, point, segmentDistance, pointOnPathCenterLine, tangent );
			distancePointToPath = Vec3Utilities::distance( point, pointOnPathCenterLine );
        }
        
    }; // class PointToPathAlikeBaseDataExtractionPolicy
    
    /**
     * Extracts the base data of @c PolylineSegmentedPath.
     */
    template<> class CORE_EXPORT DistanceToPathAlikeBaseDataExtractionPolicy< PolylineSegmentedPath > 
	{
    public:
        static void extract( PolylineSegmentedPath const& pathAlike,
                             u32 segmentIndex,
                             float segmentDistance, 
                             Vector3& pointOnPathCenterLine, 
                             Vector3& tangent, 
                             float&  )  {
            pathAlike.mapDistanceToSegmentPointAndTangent( segmentIndex, segmentDistance, pointOnPathCenterLine, tangent );     
        }
        
        
    }; // DistanceToPathAlikeBaseDataExtractionPolicy   
    
}  
} 


#endif // OPENSTEER_POLYLINESEGMENTEDPATH_H
