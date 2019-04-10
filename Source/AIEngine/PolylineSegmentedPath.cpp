#include "PolylineSegmentedPath.h"
#include <numeric>
#include <algorithm>
#include <cassert>

#include "Defines.h"
#include "QueryPathAlike.h"
#include "QueryPathAlikeMappings.h"
#include "QueryPathAlikeUtilities.h"
#include "Utilities.h"

namespace 
{    
    typedef std::vector< Vector3 > Vec3Container;
    typedef std::vector< float > FloatContainer;
    
    /**
     * Recalculates the segment tangent and length for segment @a segmentIndex.
     *
     * @attention @a segmentTangents and @a segmentLengths must have the right
     *            size.
     */
    void
    updateSegmentTangentAndLength( u32 segmentIndex,
                                   Vec3Container const& points , 
                                   Vec3Container& segmentTangents, 
                                   FloatContainer& segmentLengths ) 
    {
        assert( ( ( segmentIndex + 1 ) < points.size() ) && 
                "Not enough points for segment segmentIndex." );
        assert( segmentIndex < segmentTangents.size() &&
                "segmentIndex out of range." );
        assert( segmentTangents.size() == segmentLengths.size() && "segmentTangents and segmentLengths must have the same size." );
        
        Vector3 tangent = points[ segmentIndex + 1 ] - points[ segmentIndex ];
        float const length = tangent.length();
        assert( ! Core::AI::isZero( length ) && 
                "Segments must have lengths greater than 0." );
        
        tangent /= length;
        
        segmentTangents[ segmentIndex ] = tangent;
        segmentLengths[ segmentIndex] = length;        
    }
    
    
    /**
     * Helper function to calucate the segment tangent and lengths
     * in the given range.
     *
     * @param points points defining the path.
     * @param segmentTangents container to store the calculated segment 
     *                        tangents. Must have the right size.
     * @param segmentLengths container to store the calculated segment lengths.
     *                       Must have the right size.
     * @param firstChangedPointIndex the first point that changed. Segments have 
     *        to be updated starting with it.
     * @param numOfPoints number of points that changed beginning with 
     *        @a startIndex.
     * @param isCyclic Is the path cyclic or not.
     *
     */
    void 
    updateTangentsAndLengths( Vec3Container const& points , 
                              Vec3Container& segmentTangents, 
                              FloatContainer& segmentLengths, 
                              u32 firstChangedPointIndex, 
                              u32 numOfPoints,
                              bool isCyclic )
    {
        assert( 0 < numOfPoints && "Only call if points have really changed." );
        assert( 1 < points.size() && "Two points are needed for a segment." );
        assert( points.size() == segmentTangents.size() + 1 && 
                "Two points are needed for one segment, therefore there must be one segment less than points." );
        assert( segmentTangents.size() == segmentLengths.size() && "segmentTangents and segmentLengths must have the same size." );
        // Other assertions aren't tested because the function should only be
        // called by other functions that guarantee correctness of the 
        // parameters.
        
        
        // The segment with end point @a firstChangedPointIndex has also 
        // changed. Beware from range underflow by subtraction.      
        u32 firstSegmentIndex = firstChangedPointIndex;
        if ( 0 < firstSegmentIndex ) 
		{
            firstSegmentIndex -= 1;
        }
        
        // The last segment to update has the last changed point as its start
        // point. This only holds true if the last changed point isn't the last
        // point.
        // lastSegmentIndex is one greater than the real last segment to update
        // like the last iterators in the stl.
        u32 lastSegmentIndex = firstChangedPointIndex + numOfPoints;
        lastSegmentIndex = Core::AI::clamp( lastSegmentIndex, (u32)0, (u32)segmentTangents.size() );
        
        for ( u32 i = firstSegmentIndex; i < lastSegmentIndex; ++i ) 
		{
            updateSegmentTangentAndLength( i, points, segmentTangents, segmentLengths );
        }
        
        // If path is cyclic and the first point changed and the cycle closing
        // segment hasn't been updated update it now.
        if ( isCyclic && 
             ( 0 == firstSegmentIndex ) && 
             ! ( lastSegmentIndex == segmentTangents.size() ) ) 
		{
            updateSegmentTangentAndLength((u32)segmentTangents.size() - 1, points, segmentTangents, segmentLengths );
        }
        
    }
    
    
    /**
     * Checks that no adjacent points are equal. Checks the first and last
     * point if the path is cyclic, too.
     */
    template< typename Iterator > bool adjacentPathPointsDifferent( Iterator first, Iterator last, bool closedCycle  ) 
	{
        
        assert( last - first > 1 && "A path needs at least two waypoints." );
        
        if ( last != std::adjacent_find( first, last ) ) 
		{
            return false;
        }
    
        if ( closedCycle ) 
		{
            Iterator before_last( first );
            std::advance( before_last, last - first - 1  );
            
            return *first == *before_last;
        }
        
        return true;
    }
    
    
        
} // anonymous namespace


Core::AI::PolylineSegmentedPath::PolylineSegmentedPath() : points_( 0 ), segmentTangents_( 0 ), segmentLengths_( 0 ), closedCycle_( false )
{
    
}

Core::AI::PolylineSegmentedPath::PolylineSegmentedPath( u32 numOfPoints, Vector3 const newPoints[], bool closedCycle )
    : points_( 0 ), segmentTangents_( 0 ), segmentLengths_( 0 ), closedCycle_( closedCycle )
{
        setPath( numOfPoints, newPoints, closedCycle );
}

Core::AI::PolylineSegmentedPath::PolylineSegmentedPath( PolylineSegmentedPath const& other )
    : SegmentedPath( other ), points_( other.points_ ), segmentTangents_( other.segmentTangents_ ), segmentLengths_( other.segmentLengths_ ), closedCycle_( other.closedCycle_ )
{
    // Nothing to do.
}

Core::AI::PolylineSegmentedPath::~PolylineSegmentedPath()
{
    // Nothing to do.
}

Core::AI::PolylineSegmentedPath& Core::AI::PolylineSegmentedPath::operator=( PolylineSegmentedPath other )
{
    swap( other ); 
    return *this;
}

void Core::AI::PolylineSegmentedPath::swap( PolylineSegmentedPath& other )
{
    points_.swap( other.points_ );
    segmentTangents_.swap( other.segmentTangents_ );
    segmentLengths_.swap( other.segmentLengths_ );
    std::swap( closedCycle_, other.closedCycle_ );
}

void Core::AI::PolylineSegmentedPath::setPath( u32 numOfPoints, Vector3 const newPoints[], bool closedCycle )
{
    assert( 1 < numOfPoints && "Path must have at least two distinct points." );
    // While testing say that no cyclus is used because the first point hasn't 
    // been copied to the back.
    assert( adjacentPathPointsDifferent( newPoints, newPoints + numOfPoints, false ) && "Adjacent path points must be different." );
    
    closedCycle_ = closedCycle;
    
    u32 numberOfPoints = numOfPoints;
    if ( closedCycle_ ) {
        ++numberOfPoints;
    }
    
    points_.reserve( numberOfPoints );
    segmentTangents_.resize( numberOfPoints - 1 );
    segmentLengths_.resize( numberOfPoints - 1 );
    
    points_.assign( newPoints, newPoints + numOfPoints );
    
    if ( closedCycle_ ) {
        points_.push_back( points_[ 0 ] );
    }
    
    updateTangentsAndLengths( points_ , segmentTangents_, segmentLengths_, 0, numOfPoints, closedCycle_ );
    
    shrinkToFit( points_ );
    shrinkToFit( segmentTangents_ );
    shrinkToFit( segmentLengths_ );
}

void Core::AI::PolylineSegmentedPath::movePoints( u32 startIndex,
                                              u32 numOfPoints,
                                              Vector3 const newPoints[] )
{
    assert( ( startIndex < ( pointCount() - ( isCyclic() ? 1 : 0 ) ) ) && "startIndex must be inside index range." );
    assert( ( ( startIndex + numOfPoints ) <= ( pointCount() - ( isCyclic() ? 1 : 0 ) ) ) && "The max. index of a point to set must be inside the index range." ); 
    
    // Update the point positions.
    // @todo Remove this line u32 const pathPointCount = pointCount();
    for ( u32 i = 0; i < numOfPoints; ++i ) 
	{
        points_[ startIndex + i ] = newPoints[ i ];
    }
    
    // If the first point is changed and the path is cyclic also change the
    // last point, which is just a copy of the first point.
    if ( isCyclic() && ( 0 == startIndex ) ) 
	{
        points_.back() = points_.front();
    }
    
    // Recalculate the tangents and lengths.
    updateTangentsAndLengths( points_, segmentTangents_, segmentLengths_, startIndex, numOfPoints, isCyclic() );    
    assert( adjacentPathPointsDifferent( points_.begin(), points_.end(), isCyclic() ) && "Adjacent path points must be different." );
}

bool Core::AI::PolylineSegmentedPath::isValid() const 
{
    return pointCount() > 1;
}

Vector3 Core::AI::PolylineSegmentedPath::mapPointToPath (const Vector3& point, Vector3& tangent, float& outside) const
{
    PointToPathMapping mapping;
    mapPointToPathAlike( *this, point, mapping );
    tangent = mapping.tangent;
    outside = mapping.distancePointToPath;
    return mapping.pointOnPathCenterLine;
}

Vector3 Core::AI::PolylineSegmentedPath::mapPathDistanceToPoint (float pathDistance) const
{
    PathDistanceToPointMapping mapping;
    mapDistanceToPathAlike( *this, pathDistance, mapping );
    return mapping.pointOnPathCenterLine;
}

float Core::AI::PolylineSegmentedPath::mapPointToPathDistance (const Vector3& point) const
{
    PointToPathDistanceMapping mapping;
    mapPointToPathAlike( *this, point, mapping );
    return mapping.distanceOnPath;
}

bool Core::AI::PolylineSegmentedPath::isCyclic() const
{
    return closedCycle_;
}

float Core::AI::PolylineSegmentedPath::length() const
{
    return std::accumulate( segmentLengths_.begin(), segmentLengths_.end(), 0.0f );
}

u32 Core::AI::PolylineSegmentedPath::pointCount() const
{
    return (u32)points_.size();
}

Vector3 Core::AI::PolylineSegmentedPath::point( u32 pointIndex ) const
{
    assert( pointIndex < pointCount() && "pointIndex out of range." );
    return points_[ pointIndex ];
}

u32 Core::AI::PolylineSegmentedPath::segmentCount() const
{
    return (u32)segmentTangents_.size();
}

float Core::AI::PolylineSegmentedPath::segmentLength( u32 segmentIndex ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex out of range." );
    return segmentLengths_[ segmentIndex ];
}

Vector3 Core::AI::PolylineSegmentedPath::segmentStart( u32 segmentIndex ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex out of range." );
    assert( segmentIndex < pointCount() && "The max. index of a point must be inside range." );
    return points_[ segmentIndex ];
}

Vector3 Core::AI::PolylineSegmentedPath::segmentEnd( u32 segmentIndex ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex out of range." );
    assert( segmentIndex + 1< pointCount() && "The max. index of a point must be inside range." );

    return points_[ segmentIndex + 1 ];
}

float Core::AI::PolylineSegmentedPath::mapPointToSegmentDistance( u32 segmentIndex, Vector3 const& point ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex is out of range." );
    
    Vector3 const segmentStartToPoint( point - points_[ segmentIndex ] );
    float const distance = segmentStartToPoint.dotProduct( segmentTangents_[ segmentIndex ] );
    
    return clamp( distance, 0.0f, segmentLengths_[ segmentIndex ] );
}

Vector3 Core::AI::PolylineSegmentedPath::mapSegmentDistanceToPoint( u32 segmentIndex, float segmentDistance ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex is out of range." );
    
    float const segmentLength = segmentLengths_[ segmentIndex ];
    /*
     * bk: remove behavior that treats negative numbers as distances beginning 
     * from the end of the segment
    if ( 0.0f > segmentDistance ) {
        segmentDistance += segmentLength;
    }
    */
    segmentDistance = clamp( segmentDistance, 0.0f, segmentLength );
    
    return segmentTangents_[ segmentIndex ] * segmentDistance + points_[ segmentIndex ];
}

Vector3 Core::AI::PolylineSegmentedPath::mapSegmentDistanceToTangent( u32 segmentIndex, 
                                                               float ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex is out of range." );
    return segmentTangents_[ segmentIndex ];
}

void Core::AI::PolylineSegmentedPath::mapDistanceToSegmentPointAndTangent( u32 segmentIndex,
                                                                       float segmentDistance,
                                                                       Vector3& pointOnPath,
                                                                       Vector3& tangent ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex is out of range." );
    
    float const segmentLength = segmentLengths_[ segmentIndex ];
    
    /* 
     * bk: remove behavior that treats negative numbers as distances beginning 
     * from the end of the segment
    if ( 0.0f > segmentDistance ) {
        segmentDistance += segmentLength;
    }
    */
    segmentDistance = clamp( segmentDistance, 0.0f, segmentLength );
    
    pointOnPath = segmentTangents_[ segmentIndex ] * segmentDistance + points_[ segmentIndex ];
    tangent = segmentTangents_[ segmentIndex ];
}

void Core::AI::PolylineSegmentedPath::mapPointToSegmentDistanceAndPointAndTangent( u32 segmentIndex,
                                                                               Vector3 const& point,
                                                                               float& distance,
                                                                               Vector3& pointOnPath,
                                                                               Vector3& tangent ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex is out of range." );
    
    Vector3 const segmentStartPoint = points_[ segmentIndex ];
    Vector3 const segmentStartToPoint( point - segmentStartPoint );
    tangent = segmentTangents_[ segmentIndex ];
    distance = segmentStartToPoint.dotProduct( tangent );
    distance =  clamp( distance, 0.0f, segmentLengths_[ segmentIndex ] );
    pointOnPath = tangent * distance + segmentStartPoint;
}
