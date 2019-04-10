// Predefined mappings used by @c OpenSteer::mapPointToPathAlike and 
// @c OpenSteer::mapDistanceToPathAlike used by implementations of segmented paths and pathways.
#ifndef OPENSTEER_QUERYPATHALIKEMAPPINGS_H
#define OPENSTEER_QUERYPATHALIKEMAPPINGS_H

#include "QueryPathAlikeUtilities.h"
#include "Defines.h"

namespace Core 
{
namespace AI
{   
    /**
     * Stores the point on a pathway boundary, the tangent at the associated
     * path center line and the distance of a query point to the point on the 
     * path boundary - used by @c OpenSteer::mapPointToPathAlike.
     */
    class PointToPathMapping : public DontExtractPathDistance 
	{
    public:
        PointToPathMapping() : pointOnPathCenterLine( 0.0f, 0.0f, 0.0f ), tangent( 0.0f, 0.0f, 0.0f ), distancePointToPath( 0.0f ) {}
            
        void setPointOnPathCenterLine( Vector3 const& point ) 
		{
            pointOnPathCenterLine = point;
        }
        void setPointOnPathBoundary( Vector3 const& ) 
		{
            // pointOnPathBoundary = point;
        }
        void setRadius( float ) {}
        void setTangent( Vector3 const& t) 
		{
            tangent = t;
        }
        void setSegmentIndex( u32 ) {}
        void setDistancePointToPath( float distance ) 
		{
            distancePointToPath = distance;
        }
        void setDistancePointToPathCenterLine( float ) {}
        void setDistanceOnPath( float ) {}
        void setDistanceOnSegment( float ) {}
            
        Vector3 pointOnPathCenterLine;
        // Vector3 pointOnPathBoundary; 
        Vector3 tangent;
        float distancePointToPath;
            
    }; // class PointToPathMapping
    
    
    /**
     * Stores the point on a path center line for a given distance from the
     * start of the path - used by @c OpenSteer::mapDistanceToPathAlike.
     */
    class CORE_EXPORT PathDistanceToPointMapping :  public DontExtractPathDistance 
	{
    public:
        
        void setPointOnPathCenterLine( Vector3 const& vec )
		{
            pointOnPathCenterLine = vec;
        }
        void setRadius( float ) {}
        void setTangent( Vector3 const& ){}
        void setSegmentIndex( u32 ){}
        void setDistanceOnPath( float ){}
        void setDistanceOnSegment( float ){}
            
        Vector3 pointOnPathCenterLine; 
            
            
    }; // class PathDistanceToPointMapping
    
    
    /**
     * Stores the distance of from the start of a path to a point on the 
     * center line of the path - used by @c OpenSteer::mapPointToPathAlike.
     */
    class CORE_EXPORT PointToPathDistanceMapping : public ExtractPathDistance 
	{
    public:
        PointToPathDistanceMapping() : distanceOnPath( 0.0f ) {}
            
        void setPointOnPathCenterLine( Vector3 const& ) {}
        void setPointOnPathBoundary( Vector3 const&  ) {}
        void setRadius( float ) {}
        void setTangent( Vector3 const& ) {}
        void setSegmentIndex( u32 ) {}
        void setDistancePointToPath( float  ) {}
        void setDistancePointToPathCenterLine( float ) {}
        void setDistanceOnPath( float distance ) 
		{
            distanceOnPath = distance;
        }
        void setDistanceOnSegment( float ) {}
            
        float distanceOnPath;
    }; // class PointToPathDistanceMapping
    
    
}
}

#endif // OPENSTEER_QUERYPATHALIKEMAPPINGS_H
