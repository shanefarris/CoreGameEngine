#include "PolylineSegmentedPathwaySingleRadius.h"
#include <algorithm>
#include "QueryPathAlike.h"
#include "QueryPathAlikeMappings.h"
#include "QueryPathAlikeUtilities.h"
#include "PolylineSegmentedPath.h"

Core::AI::PolylineSegmentedPathwaySingleRadius::PolylineSegmentedPathwaySingleRadius() : radius_ ( 0.0f )
{
    path_ = new PolylineSegmentedPath();
}

Core::AI::PolylineSegmentedPathwaySingleRadius::PolylineSegmentedPathwaySingleRadius( float r ) : radius_( r )
{
    path_ = new PolylineSegmentedPath();
}

Core::AI::PolylineSegmentedPathwaySingleRadius::PolylineSegmentedPathwaySingleRadius(u32 numOfPoints, Vector3 const points[], float r, bool closeCycle ) : radius_( r )
{
    path_ = new PolylineSegmentedPath( numOfPoints, points, closeCycle );
}

Core::AI::PolylineSegmentedPathwaySingleRadius::PolylineSegmentedPathwaySingleRadius( PolylineSegmentedPathwaySingleRadius const& other )
    : SegmentedPathway( other ), radius_( other.radius_ ), path_(other.path_)
{
}

Core::AI::PolylineSegmentedPathwaySingleRadius::~PolylineSegmentedPathwaySingleRadius()
{

}

Core::AI::PolylineSegmentedPathwaySingleRadius& Core::AI::PolylineSegmentedPathwaySingleRadius::operator=( 
	PolylineSegmentedPathwaySingleRadius other )
{
    swap( other );
    return *this;
}

void Core::AI::PolylineSegmentedPathwaySingleRadius::swap( PolylineSegmentedPathwaySingleRadius& other )
{
    path_->swap( *other.path_ );
    std::swap( radius_, other.radius_ );
}

void Core::AI::PolylineSegmentedPathwaySingleRadius::movePoints( u32 startIndex,
                                                             u32 numOfPoints,
                                                             Vector3 const newPointValues[] )
{
    path_->movePoints( startIndex, numOfPoints, newPointValues );
}

void Core::AI::PolylineSegmentedPathwaySingleRadius::setPathway( u32 numOfPoints, Vector3 const points[], float r, bool closedCycle )
{
    path_->setPath( numOfPoints, points, closedCycle );
    setRadius( r );
}

void Core::AI::PolylineSegmentedPathwaySingleRadius::setRadius( float r )
{
    radius_ = r;
}

float Core::AI::PolylineSegmentedPathwaySingleRadius::Radius() const
{
    return radius_;
}

bool Core::AI::PolylineSegmentedPathwaySingleRadius::isValid() const 
{
    return pointCount() > 1;
}

Vector3 Core::AI::PolylineSegmentedPathwaySingleRadius::mapPointToPath (
	const Vector3& point, Vector3& tangent, float& outside) const
{
    PointToPathMapping mapping;
    mapPointToPathAlike( *this, point, mapping );
    tangent = mapping.tangent;
    outside = mapping.distancePointToPath;
    return mapping.pointOnPathCenterLine;
}

Vector3 Core::AI::PolylineSegmentedPathwaySingleRadius::mapPathDistanceToPoint (float pathDistance) const
{
    PathDistanceToPointMapping mapping;
    mapDistanceToPathAlike( *this, pathDistance, mapping );
    return mapping.pointOnPathCenterLine;
}

float Core::AI::PolylineSegmentedPathwaySingleRadius::mapPointToPathDistance (const Vector3& point) const
{
    PointToPathDistanceMapping mapping;
    mapPointToPathAlike( *this, point, mapping );
    return mapping.distanceOnPath;
}

bool Core::AI::PolylineSegmentedPathwaySingleRadius::isCyclic() const
{
    return path_->isCyclic();
}

float Core::AI::PolylineSegmentedPathwaySingleRadius::length() const
{
    return path_->length();
}

u32 Core::AI::PolylineSegmentedPathwaySingleRadius::pointCount() const 
{
    return path_->pointCount();
}

Vector3 Core::AI::PolylineSegmentedPathwaySingleRadius::point( u32 pointIndex ) const
{
    return path_->point( pointIndex );
}

u32 Core::AI::PolylineSegmentedPathwaySingleRadius::segmentCount() const
{
    return path_->segmentCount();
}

float Core::AI::PolylineSegmentedPathwaySingleRadius::segmentLength( u32 segmentIndex ) const
{
    return path_->segmentLength( segmentIndex );
}

Vector3 Core::AI::PolylineSegmentedPathwaySingleRadius::segmentStart( u32 segmentIndex ) const
{
    return path_->segmentStart( segmentIndex );
}

Vector3 Core::AI::PolylineSegmentedPathwaySingleRadius::segmentEnd( u32 segmentIndex ) const
{
    return path_->segmentEnd( segmentIndex );
}

float Core::AI::PolylineSegmentedPathwaySingleRadius::mapPointToSegmentDistance( u32 segmentIndex, Vector3 const& point ) const
{
    return path_->mapPointToSegmentDistance( segmentIndex, point );
}

Vector3 Core::AI::PolylineSegmentedPathwaySingleRadius::mapSegmentDistanceToPoint( u32 segmentIndex, float segmentDistance ) const
{
    return path_->mapSegmentDistanceToPoint( segmentIndex, segmentDistance );
}

float Core::AI::PolylineSegmentedPathwaySingleRadius::mapSegmentDistanceToRadius( u32 segmentIndex, float distanceOnSegment ) const
{
    UNUSED_PARAMETER(segmentIndex);
    UNUSED_PARAMETER(distanceOnSegment);
    return radius_;
}

Vector3 Core::AI::PolylineSegmentedPathwaySingleRadius::mapSegmentDistanceToTangent( u32 segmentIndex, float segmentDistance ) const
{
    return path_->mapSegmentDistanceToTangent( segmentIndex, segmentDistance );
}

void Core::AI::PolylineSegmentedPathwaySingleRadius::mapDistanceToSegmentPointAndTangentAndRadius( 
	u32 segmentIndex, float distance, Vector3& pointOnPath, Vector3& tangent, float& radius ) const
{
    path_->mapDistanceToSegmentPointAndTangent( segmentIndex, distance, pointOnPath, tangent );
    radius = radius_;
}

void Core::AI::PolylineSegmentedPathwaySingleRadius::mapPointToSegmentDistanceAndPointAndTangentAndRadius( 
	u32 segmentIndex, Vector3 const& point, float& distance, Vector3& pointOnPath, Vector3& tangent, float& radius) const
{
    path_->mapPointToSegmentDistanceAndPointAndTangent( segmentIndex, point, distance, pointOnPath, tangent );
    radius = radius_;
}


