#include "PolylineSegmentedPathwaySegmentRadii.h"
#include <algorithm>
#include <functional>
#include "QueryPathAlike.h"
#include "QueryPathAlikeMappings.h"
#include "QueryPathAlikeUtilities.h"
#include "Utilities.h"

namespace 
{
    /**
     * Calculates the number of radii needed for the given path alike.
     * Comparable to calculating the number of segments based on the number
     * of points and if the pathway is closed or not.
     */
    u32 radiiCount( u32 numOfPoints, bool closedCycle )
	{
        return numOfPoints - ( closedCycle ? 0 : 1 );
    }
    
    /**
     * Returns @c true if all radii in the range @a first to @a last (excluding
     * @a last) are greater or equal to @c 0, @c false otherwise.
     */
    template< typename Iterator > bool allRadiiNonNegative( Iterator first, Iterator last ) 
	{
        return std::find_if( first, last, std::bind2nd( std::less< float >(), 0.0f ) ) == last;
    }
    
    /**
     * Returns @c true if all radii are greater or equal to @c 0, @c false
     * otherwise.
     */
    bool allRadiiNonNegative( std::vector< float > const& radii ) 
	{
        return allRadiiNonNegative( radii.begin(), radii.end() );
    }
    
} // namespace anonymous 


Core::AI::PolylineSegmentedPathwaySegmentRadii::PolylineSegmentedPathwaySegmentRadii() : path_(), segmentRadii_( 0 )
{
    
}

Core::AI::PolylineSegmentedPathwaySegmentRadii::PolylineSegmentedPathwaySegmentRadii( 
	u32 numOfPoints, Vector3 const points[], float const radii[], bool closedCycle )
    : path_( numOfPoints, points, closedCycle ), segmentRadii_( radii, radii + radiiCount( numOfPoints, closedCycle ) )
{
    assert( allRadiiNonNegative( segmentRadii_ ) && "All radii must be positive or zero." );
}

Core::AI::PolylineSegmentedPathwaySegmentRadii::PolylineSegmentedPathwaySegmentRadii( PolylineSegmentedPathwaySegmentRadii const& other )
    : SegmentedPathway( other ), path_( other.path_ ), segmentRadii_( other.segmentRadii_ )
{
    assert( allRadiiNonNegative( segmentRadii_ ) && "All radii must be positive or zero." );    
}

Core::AI::PolylineSegmentedPathwaySegmentRadii::~PolylineSegmentedPathwaySegmentRadii()
{

}

Core::AI::PolylineSegmentedPathwaySegmentRadii& 
Core::AI::PolylineSegmentedPathwaySegmentRadii::operator=( PolylineSegmentedPathwaySegmentRadii other )
{
    swap( other );
    return *this;
}

void Core::AI::PolylineSegmentedPathwaySegmentRadii::swap( PolylineSegmentedPathwaySegmentRadii& other )
{
    path_.swap( other.path_ );
    segmentRadii_.swap( other.segmentRadii_ );
}

void Core::AI::PolylineSegmentedPathwaySegmentRadii::movePoints( u32 startIndex, u32 numOfPoints, Vector3 const points[] )
{
    path_.movePoints( startIndex, numOfPoints, points );
}

void Core::AI::PolylineSegmentedPathwaySegmentRadii::setPathway( 
	u32 numOfPoints, Vector3 const points[], float const radii[], bool closedCycle )
{
    assert( allRadiiNonNegative( radii, radii + radiiCount( numOfPoints, closedCycle ) ) && "All radii must be positive or zero." );
    path_.setPath( numOfPoints, points, closedCycle );
    segmentRadii_.assign( radii, radii + radiiCount( numOfPoints, closedCycle ) );
    shrinkToFit( segmentRadii_ );
    
}

float Core::AI::PolylineSegmentedPathwaySegmentRadii::segmentRadius( u32 segmentIndex ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex out of range." );
    return segmentRadii_[ segmentIndex ];
}

void Core::AI::PolylineSegmentedPathwaySegmentRadii::setSegmentRadius( u32 segmentIndex, float r )
{
    assert( segmentIndex < segmentCount() && "segmentIndex out of range." );
    assert( 0.0f <= r && "No negative radii allowed." );
    
    segmentRadii_[ segmentIndex ] = r;
}

void Core::AI::PolylineSegmentedPathwaySegmentRadii::setSegmentRadii( u32 startIndex, u32 numOfRadii, float const radii[] )
{
    assert( startIndex < segmentCount() && "startIndex out of range." );
    assert( startIndex + numOfRadii <= segmentCount() && "Too many radii to set." );
    assert( allRadiiNonNegative( radii, radii + numOfRadii ) && "All radii must be positive or zero." );
    
    std::copy( radii, radii + numOfRadii, segmentRadii_.begin() + startIndex );
}

bool Core::AI::PolylineSegmentedPathwaySegmentRadii::isValid() const 
{
    return pointCount() > 1;
}

Vector3 Core::AI::PolylineSegmentedPathwaySegmentRadii::mapPointToPath (
	const Vector3& point, Vector3& tangent, float& outside) const
{
    PointToPathMapping mapping;
    mapPointToPathAlike( *this, point, mapping );
    tangent = mapping.tangent;
    outside = mapping.distancePointToPath;
    return mapping.pointOnPathCenterLine;    
}

Vector3 Core::AI::PolylineSegmentedPathwaySegmentRadii::mapPathDistanceToPoint (float pathDistance) const
{
    PathDistanceToPointMapping mapping;
    mapDistanceToPathAlike( *this, pathDistance, mapping );
    return mapping.pointOnPathCenterLine;    
}

float Core::AI::PolylineSegmentedPathwaySegmentRadii::mapPointToPathDistance (const Vector3& point) const
{
    PointToPathDistanceMapping mapping;
    mapPointToPathAlike( *this, point, mapping );
    return mapping.distanceOnPath;    
}

bool Core::AI::PolylineSegmentedPathwaySegmentRadii::isCyclic() const
{
    return path_.isCyclic();
}

float Core::AI::PolylineSegmentedPathwaySegmentRadii::length() const
{
    return path_.length();
}

u32 Core::AI::PolylineSegmentedPathwaySegmentRadii::pointCount() const 
{
    return path_.pointCount();
}

Vector3 Core::AI::PolylineSegmentedPathwaySegmentRadii::point( u32 pointIndex ) const
{
    return path_.point( pointIndex );
}

u32 Core::AI::PolylineSegmentedPathwaySegmentRadii::segmentCount() const
{
    return path_.segmentCount();
}

float Core::AI::PolylineSegmentedPathwaySegmentRadii::segmentLength( u32 segmentIndex ) const
{
    return path_.segmentLength( segmentIndex );
}

Vector3 Core::AI::PolylineSegmentedPathwaySegmentRadii::segmentStart( u32 segmentIndex ) const
{
    return path_.segmentStart( segmentIndex );
}

Vector3 Core::AI::PolylineSegmentedPathwaySegmentRadii::segmentEnd( u32 segmentIndex ) const
{
    return path_.segmentEnd( segmentIndex );
}

float Core::AI::PolylineSegmentedPathwaySegmentRadii::mapPointToSegmentDistance( u32 segmentIndex, Vector3 const& point ) const
{
    return path_.mapPointToSegmentDistance( segmentIndex, point );
}

Vector3 Core::AI::PolylineSegmentedPathwaySegmentRadii::mapSegmentDistanceToPoint( u32 segmentIndex, float segmentDistance ) const
{
    return path_.mapSegmentDistanceToPoint( segmentIndex, segmentDistance );
}

float Core::AI::PolylineSegmentedPathwaySegmentRadii::mapSegmentDistanceToRadius( u32 segmentIndex, float distanceOnSegment ) const
{
    UNUSED_PARAMETER(distanceOnSegment);
    assert( segmentIndex < segmentCount() && "segmentIndex out of range." );
    return segmentRadii_[ segmentIndex ];
}

Vector3 Core::AI::PolylineSegmentedPathwaySegmentRadii::mapSegmentDistanceToTangent( u32 segmentIndex, float segmentDistance ) const
{
    return path_.mapSegmentDistanceToTangent( segmentIndex, segmentDistance );
}

void Core::AI::PolylineSegmentedPathwaySegmentRadii::mapDistanceToSegmentPointAndTangentAndRadius( 
	u32 segmentIndex, float distance, Vector3& pointOnPath, Vector3& tangent, float& radius ) const
{
    assert( segmentIndex < segmentCount() && "segmentIndex out of range." );
    path_.mapDistanceToSegmentPointAndTangent( segmentIndex, distance, pointOnPath, tangent );
    radius = segmentRadii_[ segmentIndex ];
}

void Core::AI::PolylineSegmentedPathwaySegmentRadii::mapPointToSegmentDistanceAndPointAndTangentAndRadius( 
	u32 segmentIndex, Vector3 const& point, float& distance, Vector3& pointOnPath, Vector3& tangent, float& radius) const
{
    path_.mapPointToSegmentDistanceAndPointAndTangent( segmentIndex, point, distance, pointOnPath, tangent );
    radius = segmentRadii_[ segmentIndex ];
}


