// Utilitites to get the next or previous segment of a segmented path alike.
#ifndef OPENSTEER_SEGMENTEDPATHALIKEUTILITIES_H
#define OPENSTEER_SEGMENTEDPATHALIKEUTILITIES_H

#include <cassert>

namespace Core 
{
namespace AI
{
    /**
     * Returns the next Segment after @a segmentIndex for @a pathAlike.
     * 
     * If @a segmentIndex is the last valid index and @a pathAlike is cylic the
     * first segment index is returned. If @a pathAlike isn't cyclic the last 
     * valid segment index is returned.
     *
     * @c SegmentedPathAlike must provide the following member functions:
     * <code>u32  segmentCount() const</code>
     * <code>bool isValid() const </code>
     * <code>bool isCyclic() const </code>
     */
    template< typename SegmentedPathAlike > u32 nextSegment( SegmentedPathAlike const& pathAlike, u32 segmentIndex ) 
	{
        assert( pathAlike.isValid() && "pathAlike isn't valid." );
        assert( segmentIndex < pathAlike.segmentCount() && "segmentIndex out of range." );
        
        ++segmentIndex;
        
        if ( segmentIndex == pathAlike.segmentCount() ) 
		{
            if ( pathAlike.isCyclic() ) 
			{
                segmentIndex = 0;
            } 
			else 
			{
                --segmentIndex;
            }
        } 
        
        return segmentIndex;
    }
    
    /**
     * Returns the previous Segment before @a segmentIndex for @a pathAlike.
     * 
     * If @a segmentIndex is the first valid index and @a pathAlike is cylic the
     * last segment index is returned. If @a pathAlike isn't cyclic the first 
     * valid segment index is returned.
     *
     * @c SegmentedPathAlike must provide the following member functions:
     * <code>u32  segmentCount() const</code>
     * <code>bool isValid() const </code>
     * <code>bool isCyclic() const </code>
     */
    template< typename SegmentedPathAlike > u32 previousSegment( SegmentedPathAlike const& pathAlike, u32 segmentIndex ) 
	{
        assert( pathAlike.isValid() && "pathAlike isn't valid." );
        assert( segmentIndex < pathAlike.segmentCount() && "segmentIndex out of range." );

        if ( 0 != segmentIndex ) 
		{
            --segmentIndex;

        } else if ( pathAlike.isCyclic() ) 
		{
            segmentIndex = pathAlike.segmentCount() - 1;
        }
        
        return segmentIndex;
    }  
    
}
}


#endif // OPENSTEER_SEGMENTEDPATHALIKEUTILITIES_H
