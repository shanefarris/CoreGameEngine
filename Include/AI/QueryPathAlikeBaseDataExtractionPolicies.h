// Declarations of policies used by @c OpenSteer::mapPointToPathAlike and
// @c OpenSteer::mapDistanceToPathAlike to extract informations of path alikes.
#ifndef OPENSTEER_QUERYPATHALIKEBASEDATAEXTRACTIONPOLICY_H
#define OPENSTEER_QUERYPATHALIKEBASEDATAEXTRACTIONPOLICY_H

namespace Core 
{
namespace AI
{
    
    /**
     * Extracts the base data like the segment distance, the radius, the
     * distance of the query point to the path alike, the point on the path
     * alike center line and the tangent at that point.
     *
     * Specialize it for the path alike to use and provide a static member
     * function with the following signature:
     *
     * <code>static void extract( PathAlike const& pathAlike, typename PathAlike::u32 segmentIndex, Vector3 const& point, float& segmentDistance, float& radius, float& distancePointToPath, Vector3& pointOnPathCenterLine, Vector3& tangent )</code>
     *
     * @attention Be aware of the references that are passed in.
     */
    template< class PathAlike > class CORE_EXPORT PointToPathAlikeBaseDataExtractionPolicy;
    
    
    /**
     * Extracts the base data like the radius, the point on the path
     * alike center line and the tangent at that point.
     *
     * Specialize it for the path alike to use and provide a static member
     * function with the following signature:
     *
     * <code>static void extract( PathAlike const& pathAlike, typename PathAlike::u32 segmentIndex, float segmentDistance, Vector3& pointOnPathCenterLine, Vector3& tangent, float& radius )</code>
     *
     * @attention Be aware of the references that are passed in.
     */    
    template< class PathAlike >
    class DistanceToPathAlikeBaseDataExtractionPolicy;
    
}
}


#endif // OPENSTEER_QUERYPATHALIKEBASEDATAEXTRACTIONPOLICY_H
