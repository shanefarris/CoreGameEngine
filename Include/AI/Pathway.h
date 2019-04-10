// Abstract base class for pathways - paths with associated radii.
#ifndef OPENSTEER_PATHWAY_H
#define OPENSTEER_PATHWAY_H

#include "Defines.h"

namespace Core 
{
namespace AI
{
    /**
     * Pure virtual base class representing an abstract pathway in space.
     * Could be used for example in path following.
     */
    class Pathway 
	{
    public:
		virtual ~Pathway() { }
        
        /**
         * Returns @c true if the path is valid, @c false otherwise.
         */
        virtual bool isValid() const = 0;
        
        /**
         * Given an arbitrary point ("A"), returns the nearest point ("P") on
		 * this path center line.  Also returns, via output arguments, the path
         * tangent at P and a measure of how far A is outside the Pathway's 
         * "tube".  Note that a negative distance indicates A is inside the 
         * Pathway.
         *
         * If @c isValid is @c false the behavior is undefined.
         */
		virtual Vector3 mapPointToPath (const Vector3& point,
                                     Vector3& tangent,
                                     float& outside) const = 0;
        
		/**
         * Given a distance along the path, convert it to a point on the path.
         * If @c isValid is @c false the behavior is undefined.
         */
		virtual Vector3 mapPathDistanceToPoint (float pathDistance) const = 0;
        
		/**
         * Given an arbitrary point, convert it to a distance along the path.
         * If @c isValid is @c false the behavior is undefined.
         */
		virtual float mapPointToPathDistance (const Vector3& point) const = 0;
        
        /**
         * Returns @c true f the path is closed, otherwise @c false.
         */
        virtual bool isCyclic() const = 0;
        
        /**
         * Returns the length of the path.
         */
        virtual float length() const = 0;
        
    }; // class Pathway
    
}
}


#endif // OPENSTEER_PATHWAY_H
