// Collection of helper classes to inherit from to create mappings as used by  
// @c OpenSteer::mapDistanceToPathAlike and 
// @c OpenSteer::mapPointToPathAlike.
#ifndef OPENSTEER_QUERYPATHALIKEUTILITIES_H
#define OPENSTEER_QUERYPATHALIKEUTILITIES_H

namespace Core 
{
namespace AI
{
    /**
     * Inherit from it to create a mapping class used by 
     * @c OpenSteer::mapDistanceToPathAlike and 
     * @c OpenSteer::mapPointToPathAlike that calculates and extracts the
     * distance along the path alike.
     */    
    class ExtractPathDistance 
	{
    public:
        void setDistanceOnPathFlag( float distance ) 
		{
            distanceOnPathFlag_ = distance;
        }
        
        float distanceOnPathFlag() const 
		{
            return distanceOnPathFlag_;
        }
        
    protected:
        ExtractPathDistance() : distanceOnPathFlag_( 0.0f ) { }
        
        explicit ExtractPathDistance( float distance ) : distanceOnPathFlag_( distance ) { }
        
        ~ExtractPathDistance() { }
        
    private:
        float distanceOnPathFlag_;
    }; // class ExtractPathDistance
    
    
    /**
     * Inherit from it to create a mapping class used by 
     * @c OpenSteer::mapDistanceToPathAlike and 
     * @c OpenSteer::mapPointToPathAlike that shouldn't calculate and extract the
     * distance along the path alike.
     */
    class DontExtractPathDistance 
	{
    public:
        void setDistanceOnPathFlag( float ) { }
        
        float distanceOnPathFlag() const 
		{
            return 0.0f;
        };
        
    protected:
        ~DontExtractPathDistance() { }

    }; // class DontExtractPathDistance
    
}   
}


#endif // OPENSTEER_QUERYPATHALIKEUTILITIES_H
