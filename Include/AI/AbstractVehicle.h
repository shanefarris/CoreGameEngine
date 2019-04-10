// AbstractVehicle: pure virtual base class for generic steerable vehicles
#ifndef OPENSTEER_ABSTRACTVEHICLE_H
#define OPENSTEER_ABSTRACTVEHICLE_H

#include "Defines.h"
#include "LocalSpace.h"

namespace Core 
{
namespace AI
{
    class AbstractVehicle : public AbstractLocalSpace 
    {
    public:
        virtual ~AbstractVehicle() { }
        
        // mass (defaults to unity so acceleration=force)
        virtual float Mass (void) const = 0;
        virtual float SetMass (float) = 0;

        // size of bounding sphere, for obstacle avoidance, etc.
        virtual float Radius (void) const = 0;
        virtual float SetRadius (float) = 0;

        // velocity of vehicle
        virtual Vector3 Velocity (void) const = 0;

        // speed of vehicle  (may be faster than taking magnitude of velocity)
        virtual float Speed (void) const = 0;
        virtual float SetSpeed (float) = 0;

        // groups of (pointers to) abstract vehicles, and iterators over them
        typedef std::vector<AbstractVehicle*> group;
        typedef group::const_iterator iterator;    

        // predict position of this vehicle at some time in the future
        // (assumes velocity remains constant)
        virtual Vector3 PredictFuturePosition (const float predictionTime) const = 0;

        // ----------------------------------------------------------------------
        // XXX this vehicle-model-specific functionality functionality seems out
        // XXX of place on the abstract base class, but for now it is expedient

        // the maximum steering force this vehicle can apply
        virtual float MaxForce (void) const = 0;
        virtual float SetMaxForce (float) = 0;

        // the maximum speed this vehicle is allowed to move
        virtual float MaxSpeed (void) const = 0;
        virtual float SetMaxSpeed (float) = 0;

		// dp - added to support heterogeneous flocks
		virtual void Update(const float currentTime, const float elapsedTime) = 0;
    };


    // more convenient short names for AbstractVehicle group and iterator
    typedef AbstractVehicle::group AVGroup;
    typedef AbstractVehicle::iterator AVIterator;
}
}

#endif // OPENSTEER_ABSTRACTVEHICLE_H
