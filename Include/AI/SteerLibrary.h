#ifndef OPENSTEER_STEERLIBRARY_H
#define OPENSTEER_STEERLIBRARY_H

#include "AbstractVehicle.h"
#include "Pathway.h"
#include "Obstacle.h"
#include "Utilities.h"
#include "Defines.h"
#include "Wall.h"

#include "OgreRay.h"

using namespace Core::AI;

namespace Core 
{
namespace AI
{
    template <class Super> class SteerLibraryMixin : public Super
    {
    public:
        using Super::Velocity;
        using Super::MaxSpeed;
        using Super::Speed;
        using Super::Radius;
        using Super::MaxForce;
        using Super::Forward;
        using Super::Position;
        using Super::Side;
        using Super::Up;
        using Super::PredictFuturePosition;
        
    public:

        // Constructor: initializes state
        SteerLibraryMixin ()
        {
            // set inital state
            reset ();
        }

        // reset state
        void reset (void)
        {
            // initial state of wander behavior
            WanderSide = 0;
            WanderUp = 0;

            // default to non-gaudyPursuitAnnotation
            gaudyPursuitAnnotation = false;
        }

        // Wander behavior
        float WanderSide;
        float WanderUp;
        Vector3 steerForWander (float dt);

        // Seek behavior
        Vector3 steerForSeek (const Vector3& target);

        // Flee behavior
        Vector3 steerForFlee (const Vector3& target);

        // xxx proposed, experimental new seek/flee [cwr 9-16-02]
        Vector3 xxxsteerForFlee (const Vector3& target);
        Vector3 xxxsteerForSeek (const Vector3& target);

        // Path Following behaviors
        Vector3 steerToFollowPath (const int direction, const float predictionTime, Pathway& path);
        Vector3 steerToStayOnPath (const float predictionTime, Pathway& path);

		// Walls
		Vector3 steerForWallAvoidance(const Vector<Wall*>& Walls);

		// Quick sphere obstacle avoidance
		Vector3 steerToAvoidOabstacles_QuickSphere(const Vector<Obstacle*>& Obstacles);

        // ------------------------------------------------------------------------
        // Obstacle Avoidance behavior
        //
        // Returns a steering force to avoid a given obstacle.  The purely
        // lateral steering force will turn our vehicle towards a silhouette edge
        // of the obstacle.  Avoidance is required when (1) the obstacle
        // intersects the vehicle's current path, (2) it is in front of the
        // vehicle, and (3) is within minTimeToCollision seconds of travel at the
        // vehicle's current velocity.  Returns a zero vector value (Vector3::ZERO)
        // when no avoidance is required.
        Vector3 steerToAvoidObstacle (const float minTimeToCollision, const Obstacle& obstacle);

        // avoids all obstacles in an ObstacleGroup
        Vector3 steerToAvoidObstacles (const float minTimeToCollision, const ObstacleGroup& obstacles);

        // Unaligned collision avoidance behavior: avoid colliding with other
        // nearby vehicles moving in unconstrained directions.  Determine which
        // (if any) other other vehicle we would collide with first, then steers
        // to avoid the site of that potential collision.  Returns a steering
        // force vector, which is zero length if there is no impending collision.
        Vector3 steerToAvoidNeighbors (const float minTimeToCollision, const AVGroup& others);


        // Given two vehicles, based on their current positions and velocities,
        // determine the time until nearest approach
        float predictNearestApproachTime (AbstractVehicle& otherVehicle);

        // Given the time until nearest approach (predictNearestApproachTime)
        // determine position of each vehicle at that time, and the distance
        // between them
        float computeNearestApproachPositions (AbstractVehicle& otherVehicle, float time);

        /// XXX globals only for the sake of graphical annotation
        Vector3 hisPositionAtNearestApproach;
        Vector3 ourPositionAtNearestApproach;

        // avoidance of "close neighbors" -- used only by steerToAvoidNeighbors
        //
        // XXX  Does a hard steer away from any other agent who comes withing a
        // XXX  critical distance.  Ideally this should be replaced with a call
        // XXX  to steerForSeparation.
        Vector3 steerToAvoidCloseNeighbors (const float minSeparationDistance, const AVGroup& others);

        // used by boid behaviors
        bool inBoidNeighborhood (const AbstractVehicle& otherVehicle,
                                 const float minDistance,
                                 const float maxDistance,
                                 const float cosMaxAngle);

        // Separation behavior -- determines the direction away from nearby boids
        Vector3 steerForSeparation (const float maxDistance,
                                 const float cosMaxAngle,
                                 const AVGroup& flock);

        // Alignment behavior
        Vector3 steerForAlignment (const float maxDistance,
                                const float cosMaxAngle,
                                const AVGroup& flock);

        // Cohesion behavior
        Vector3 steerForCohesion (const float maxDistance,
                               const float cosMaxAngle,
                               const AVGroup& flock);

        // pursuit of another vehicle (& version with ceiling on prediction time)
        Vector3 steerForPursuit (const AbstractVehicle& quarry);
        Vector3 steerForPursuit (const AbstractVehicle& quarry, const float maxPredictionTime);

        // for annotation
        bool gaudyPursuitAnnotation;

        // evasion of another vehicle
        Vector3 steerForEvasion (const AbstractVehicle& menace, const float maxPredictionTime);

        // tries to maintain a given speed, returns a maxForce-clipped steering
        // force along the forward/backward axis
        Vector3 steerForTargetSpeed (const float targetSpeed);

        // ----------------------------------------------------------- utilities
        // XXX these belong somewhere besides the steering library
        // XXX above AbstractVehicle, below SimpleVehicle
        // XXX ("utility vehicle"?)

        // xxx cwr experimental 9-9-02 -- names OK?
        bool isAhead (const Vector3& target) const {return isAhead (target, 0.707f);};
        bool isASide(const Vector3& target) const {return isASide(target, 0.707f);};
        bool isBehind (const Vector3& target) const {return isBehind (target, -0.707f);};

        bool isAhead (const Vector3& target, float cosThreshold) const
        {
            const Vector3 targetDirection = Vec3Utilities::normalise(target - Position());
            return Forward().dotProduct(targetDirection) > cosThreshold;
        };

        bool isASide(const Vector3& target, float cosThreshold) const
        {
            const Vector3 targetDirection = (Vec3Utilities::normalise(target - Position()));
            const float dp = Forward().dotProduct(targetDirection);
            return (dp < cosThreshold) && (dp > -cosThreshold);
        };

        bool isBehind (const Vector3& target, float cosThreshold) const
        {
			const Vector3 targetDirection = Vec3Utilities::normalise(target - Position());
            return Forward().dotProduct(targetDirection) < cosThreshold;
        };


        // ------------------------------------------------ graphical annotation
        // (parameter names commented out to prevent compiler warning from "-W")


        // called when steerToAvoidObstacles decides steering is required
        // (default action is to do nothing, layered classes can overload it)
        virtual void annotateAvoidObstacle (const float /*minDistanceToCollision*/) { }

        // called when steerToFollowPath decides steering is required
        // (default action is to do nothing, layered classes can overload it)
        virtual void annotatePathFollowing (const Vector3& /*future*/,
                                            const Vector3& /*onPath*/,
                                            const Vector3& /*target*/,
                                            const float /*outside*/) { }

        // called when steerToAvoidCloseNeighbors decides steering is required
        // (default action is to do nothing, layered classes can overload it)
        virtual void annotateAvoidCloseNeighbor (const AbstractVehicle& /*other*/,
                                                 const float /*additionalDistance*/) { }

        // called when steerToAvoidNeighbors decides steering is required
        // (default action is to do nothing, layered classes can overload it)
        virtual void annotateAvoidNeighbor (const AbstractVehicle& /*threat*/,
                                            const float /*steer*/,
                                            const Vector3& /*ourFuture*/,
                                            const Vector3& /*threatFuture*/) { }
    };

}    
}

template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForWander (float dt)
{
    // random walk WanderSide and WanderUp between -1 and +1
    const float speed = 12.0f * dt; // maybe this (12) should be an argument?
    WanderSide = scalarRandomWalk (WanderSide, speed, -1, +1);
    WanderUp   = scalarRandomWalk (WanderUp,   speed, -1, +1);

    // return a pure lateral steering vector: (+/-Side) + (+/-Up)
    return (Side() * WanderSide) + (Up() * WanderUp);
}

// Seek behavior
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForSeek (const Vector3& target)
{
    const Vector3 desiredVelocity = target - Position();
    return desiredVelocity - Velocity();
}

// Flee behavior
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForFlee (const Vector3& target)
{
    const Vector3 desiredVelocity = Position() - target;
    return desiredVelocity - Velocity();
}

// ----------------------------------------------------------------------------
// xxx proposed, experimental new seek/flee [cwr 9-16-02]
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::xxxsteerForFlee (const Vector3& target)
{
//  const Vector3 offset = position - target;
    const Vector3 offset = Position() - target;
    const Vector3 desiredVelocity = offset.truncateLength (MaxSpeed()); //xxxnew
    return desiredVelocity - Velocity();
}


template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::xxxsteerForSeek (const Vector3& target)
{
//  const Vector3 offset = target - position;
    const Vector3 offset = target - Position();
    const Vector3 desiredVelocity = offset.truncateLength (MaxSpeed()); //xxxnew
    return desiredVelocity - Velocity();
}


// ----------------------------------------------------------------------------
// Path Following behaviors
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerToStayOnPath (const float predictionTime, Pathway& path)
{
    // predict our future position
    const Vector3 futurePosition = PredictFuturePosition (predictionTime);

    // find the point on the path nearest the predicted future position
    Vector3 tangent;
    float outside;
    const Vector3 onPath = path.mapPointToPath (futurePosition,
                                             tangent,     // output argument
                                             outside);    // output argument

    if (outside < 0)
    {
        // our predicted future position was in the path,
        // return zero steering.
        return Vector3::ZERO;
    }
    else
    {
        // our predicted future position was outside the path, need to
        // steer towards it.  Use onPath projection of futurePosition
        // as seek target
        annotatePathFollowing (futurePosition, onPath, onPath, outside);
        return steerForSeek (onPath);
    }
}

// Walls
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForWallAvoidance(const Vector<Wall*>& Walls)
{
	Vector3 ret = Vector3::ZERO;

	//for each wall
	for (u32 i = 0; i < Walls.size(); i++)
	{
		//test intersection
		Vector3 player_pos = Position();
		player_pos.y = 0;
		Vector3 line1start = player_pos;
		Vector3 line1end = player_pos + (Velocity() * 5);

		Vector3 line2start = Walls[i]->GetFrom();
		Vector3 line2end = Walls[i]->GetTo();
		line2start.y = 0;
		line2end.y = 0;

		Vector3 d1 = line1end - line1start;
		Vector3 d2 = line2end - line2start;
		float mangle = d1.getRotationTo(d2).getYaw().valueDegrees();

		//test intersection only if angle between velocity and wall normal is positive
		if (mangle > 0)
		{
			Vector3 result = Utility::LineIntersect(line1start, line1end, line2start, line2end);
			float dist = result.distance(player_pos);
			float mindist = 5 * Radius();

			if (result != Vector3(-1,-1,-1) && dist < mindist)
			{
				Vector3 v1 = result - Position();			//find if we need to turn left or right to avoid from agent to intersection
				Vector3 v2 = Walls[i]->GetNormal();			//wall normal
				float angle = v1.getRotationTo(v2).getYaw().valueDegrees();	//find angle between v1 & v2
				
				if (angle > 0)	//left
				{
					Quaternion q;
					q.FromAngleAxis(Radian(Math::fDeg2Rad * 90), Vector3::UNIT_Y);
					ret = q * d2;
				}
				else	//right
				{
					Quaternion q;
					q.FromAngleAxis(Radian(Math::fDeg2Rad * 90), Vector3::UNIT_Y);
					ret = q * d2;
				}
				break;
			}
		}
	}

	return ret.normalisedCopy() * MaxSpeed();
}

template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerToAvoidOabstacles_QuickSphere(const Vector<Obstacle*>& Obstacles)
{
	Vector3 ret = Vector3::ZERO;

	//prepare ray
	Ogre::Ray r;
	Vector3 tpos = Position();
	r.setDirection(Velocity().normalisedCopy());

	//for each obstacle
	for (u32 i = 0; i < Obstacles.size(); i++)
	{
		//if close enough
		float dist = Position().distance(Obstacles[i]->getPosition());
		float mindist = Radius() + Obstacles[i]->radius;

		if (dist < mindist)
		{
			tpos.y = Obstacles[i]->getPosition().y;
			r.setOrigin(tpos);
			Vector3 intersection;
			bool result = Utility::IntersectLineCircle(
				Obstacles[i]->getPosition(), Obstacles[i]->radius, r.getOrigin(), r.getOrigin() + dist * r.getDirection(), intersection);
			if (result)
			{
				Vector3 v1 = Obstacles[i]->getPosition() - r.getOrigin();	//find if we need to turn left or right to avoid from agent to obstacle center
				Vector3 v2 = Obstacles[i]->getPosition() - intersection;	//from collision point to obstacle center
				float angle = v1.getRotationTo(v2).getYaw().valueDegrees();		//find angle between v1 & v2
				
				if (angle <= 0)	//left
				{
					Quaternion q;
					q.FromAngleAxis(Radian(Math::fDeg2Rad * 90), Vector3::UNIT_Y);
					ret = q * r.getDirection();
				}
				
				else if (angle > 0)	//right
				{
					Quaternion q;
					q.FromAngleAxis(Radian(Math::fDeg2Rad * -90), Vector3::UNIT_Y);
					ret = q * r.getDirection();
				}
				break;
			}
		}
	}

	return ret.normalisedCopy() * MaxSpeed();
}

template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerToFollowPath(const int direction, const float predictionTime, Pathway& path)
{
    // our goal will be offset from our path distance by this amount
    const float pathDistanceOffset = direction * predictionTime * Speed();

    // predict our future position
    const Vector3 futurePosition = PredictFuturePosition (predictionTime);

    // measure distance along path of our current and predicted positions
    const float nowPathDistance =
        path.mapPointToPathDistance (Position());
    const float futurePathDistance =
        path.mapPointToPathDistance (futurePosition);

    // are we facing in the correction direction?
    const bool rightway = ((pathDistanceOffset > 0) ?
                           (nowPathDistance < futurePathDistance) :
                           (nowPathDistance > futurePathDistance));

    // find the point on the path nearest the predicted future position
    // XXX need to improve calling sequence, maybe change to return a
    // XXX special path-defined object which includes two Vec3s and a 
    // XXX bool (onPath,tangent (ignored), withinPath)
    Vector3 tangent;
    float outside;
    const Vector3 onPath = path.mapPointToPath (futurePosition,
                                             // output arguments:
                                             tangent,
                                             outside);

    // no steering is required if (a) our future position is inside
    // the path tube and (b) we are facing in the correct direction
    if ((outside < 0) && rightway)
    {
        // all is well, return zero steering
        return Vector3::ZERO;
    }
    else
    {
        // otherwise we need to steer towards a target point obtained
        // by adding pathDistanceOffset to our current path position

        float const targetPathDistance = nowPathDistance + pathDistanceOffset;
        Vector3 const target = path.mapPathDistanceToPoint (targetPathDistance);

        annotatePathFollowing (futurePosition, onPath, target, outside);

        // return steering to seek target on path
        return steerForSeek (target);
    }
}


// ----------------------------------------------------------------------------
// Obstacle Avoidance behavior
//
// Returns a steering force to avoid a given obstacle.  The purely lateral
// steering force will turn our vehicle towards a silhouette edge of the
// obstacle.  Avoidance is required when (1) the obstacle intersects the
// vehicle's current path, (2) it is in front of the vehicle, and (3) is
// within minTimeToCollision seconds of travel at the vehicle's current
// velocity.  Returns a zero vector value (Vector3::ZERO) when no avoidance is
// required.
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerToAvoidObstacle(const float minTimeToCollision, const Obstacle& obstacle)
{
    const Vector3 avoidance = obstacle.steerToAvoid (*this, minTimeToCollision);

    // XXX more annotation modularity problems (assumes spherical obstacle)
    if (avoidance != Vector3::ZERO)
        annotateAvoidObstacle (minTimeToCollision * Speed());

    return avoidance;
}


// this version avoids all of the obstacles in an ObstacleGroup
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerToAvoidObstacles(const float minTimeToCollision, const ObstacleGroup& obstacles)
{
    const Vector3 avoidance = Obstacle::steerToAvoidObstacles (*this, minTimeToCollision, obstacles);

    // XXX more annotation modularity problems (assumes spherical obstacle)
    if (avoidance != Vector3::ZERO)
        annotateAvoidObstacle (minTimeToCollision * Speed());

    return avoidance;
}


// ----------------------------------------------------------------------------
// Unaligned collision avoidance behavior: avoid colliding with other nearby
// vehicles moving in unconstrained directions.  Determine which (if any)
// other other vehicle we would collide with first, then steers to avoid the
// site of that potential collision.  Returns a steering force vector, which
// is zero length if there is no impending collision.
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerToAvoidNeighbors(const float minTimeToCollision, const AVGroup& others)
{
    // first priority is to prevent immediate interpenetration
    const Vector3 separation = steerToAvoidCloseNeighbors (0, others);
    if (separation != Vector3::ZERO) return separation;

    // otherwise, go on to consider potential future collisions
    float steer = 0;
    AbstractVehicle* threat = nullptr;

    // Time (in seconds) until the most immediate collision threat found
    // so far.  Initial value is a threshold: don't look more than this
    // many frames into the future.
    float minTime = minTimeToCollision;

    // xxx solely for annotation
    Vector3 xxxThreatPositionAtNearestApproach;
    Vector3 xxxOurPositionAtNearestApproach;

    // for each of the other vehicles, determine which (if any)
    // pose the most immediate threat of collision.
    for (AVIterator i = others.begin(); i != others.end(); i++)
    {
        AbstractVehicle& other = **i;
        if (&other != this)
        {	
            // avoid when future positions are this close (or less)
            const float collisionDangerThreshold = Radius() * 2;

            // predicted time until nearest approach of "this" and "other"
            const float time = predictNearestApproachTime (other);

            // If the time is in the future, sooner than any other
            // threatened collision...
            if ((time >= 0) && (time < minTime))
            {
                // if the two will be close enough to collide,
                // make a note of it
                if (computeNearestApproachPositions (other, time)
                    < collisionDangerThreshold)
                {
                    minTime = time;
                    threat = &other;
                    xxxThreatPositionAtNearestApproach
                        = hisPositionAtNearestApproach;
                    xxxOurPositionAtNearestApproach
                        = ourPositionAtNearestApproach;
                }
            }
        }
    }

    // if a potential collision was found, compute steering to avoid
    if (threat != nullptr)
    {
        // parallel: +1, perpendicular: 0, anti-parallel: -1
        float parallelness = Forward().dotProduct(threat->Forward());
        float angle = 0.707f;

        if (parallelness < -angle)
        {
            // anti-parallel "head on" paths:
            // steer away from future threat position
            Vector3 offset = xxxThreatPositionAtNearestApproach - Position();
            float sideDot = offset.dotProduct(Side());
            steer = (sideDot > 0) ? -1.0f : 1.0f;
        }
        else
        {
            if (parallelness > angle)
            {
                // parallel paths: steer away from threat
                Vector3 offset = threat->Position() - Position();
                float sideDot = offset.dotProduct(Side());
                steer = (sideDot > 0) ? -1.0f : 1.0f;
            }
            else
            {
                // perpendicular paths: steer behind threat
                // (only the slower of the two does this)
                if (threat->Speed() <= Speed())
                {
                    float sideDot = Side().dotProduct(threat->Velocity());
                    steer = (sideDot > 0) ? -1.0f : 1.0f;
                }
            }
        }

        annotateAvoidNeighbor (*threat, steer, xxxOurPositionAtNearestApproach, xxxThreatPositionAtNearestApproach);
    }

    return Side() * steer;
}

// Given two vehicles, based on their current positions and velocities,
// determine the time until nearest approach
//
// XXX should this return zero if they are already in contact?
template<class Super> float Core::AI::SteerLibraryMixin<Super>::predictNearestApproachTime (AbstractVehicle& otherVehicle)
{
    // imagine we are at the origin with no velocity,
    // compute the relative velocity of the other vehicle
    const Vector3 myVelocity = Velocity();
    const Vector3 otherVelocity = otherVehicle.Velocity();
    const Vector3 relVelocity = otherVelocity - myVelocity;
    const float relSpeed = relVelocity.length();

    // for parallel paths, the vehicles will always be at the same distance,
    // so return 0 (aka "now") since "there is no time like the present"
    if (relSpeed == 0) return 0;

    // Now consider the path of the other vehicle in this relative
    // space, a line defined by the relative position and velocity.
    // The distance from the origin (our vehicle) to that line is
    // the nearest approach.

    // Take the unit tangent along the other vehicle's path
    const Vector3 relTangent = relVelocity / relSpeed;

    // find distance from its path to origin (compute offset from
    // other to us, find length of projection onto path)
    const Vector3 relPosition = Position() - otherVehicle.Position();
    const float projection = relTangent.dotProduct(relPosition);

    return projection / relSpeed;
}

// Given the time until nearest approach (predictNearestApproachTime)
// determine position of each vehicle at that time, and the distance
// between them
template<class Super> float Core::AI::SteerLibraryMixin<Super>::computeNearestApproachPositions(AbstractVehicle& otherVehicle, float time)
{
    const Vector3    myTravel =       Forward() *       Speed() * time;
    const Vector3 otherTravel = otherVehicle.Forward() * otherVehicle.Speed() * time;

    const Vector3    myFinal =       Position() +    myTravel;
    const Vector3 otherFinal = otherVehicle.Position() + otherTravel;

    // xxx for annotation
    ourPositionAtNearestApproach = myFinal;
    hisPositionAtNearestApproach = otherFinal;

    return Vec3Utilities::distance (myFinal, otherFinal);
}

// ----------------------------------------------------------------------------
// avoidance of "close neighbors" -- used only by steerToAvoidNeighbors
//
// XXX  Does a hard steer away from any other agent who comes withing a
// XXX  critical distance.  Ideally this should be replaced with a call
// XXX  to steerForSeparation.
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerToAvoidCloseNeighbors(const float minSeparationDistance, const AVGroup& others)
{
    // for each of the other vehicles...
    for (AVIterator i = others.begin(); i != others.end(); i++)    
    {
        AbstractVehicle& other = **i;
        if (&other != this)
        {
            const float sumOfRadii = Radius() + other.Radius();
            const float minCenterToCenter = minSeparationDistance + sumOfRadii;
            const Vector3 offset = other.Position() - Position();
            const float currentDistance = offset.length();

            if (currentDistance < minCenterToCenter)
            {
                annotateAvoidCloseNeighbor (other, minSeparationDistance);
                return (-offset).perpendicularComponent (Forward());
            }
        }
    }

    // otherwise return zero
    return Vector3::ZERO;
}


// ----------------------------------------------------------------------------
// used by boid behaviors: is a given vehicle within this boid's neighborhood?
template<class Super> bool Core::AI::SteerLibraryMixin<Super>::inBoidNeighborhood(const AbstractVehicle& otherVehicle, const float minDistance, const float maxDistance, const float cosMaxAngle)
{
    if (&otherVehicle == this)
    {
        return false;
    }
    else
    {
        const Vector3 offset = otherVehicle.Position() - Position();
        const float distanceSquared = offset.dotProduct (offset);

        // definitely in neighborhood if inside minDistance sphere
        if (distanceSquared < (minDistance * minDistance))
        {
            return true;
        }
        else
        {
            // definitely not in neighborhood if outside maxDistance sphere
            if (distanceSquared > (maxDistance * maxDistance))
            {
                return false;
            }
            else
            {
                // otherwise, test angular offset from forward axis
                const Vector3 unitOffset = offset / sqrt (distanceSquared);
                const float forwardness = Forward().dotProduct(unitOffset);
                return forwardness > cosMaxAngle;
            }
        }
    }
}


// ----------------------------------------------------------------------------
// Separation behavior: steer away from neighbors
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForSeparation(const float maxDistance, const float cosMaxAngle, const AVGroup& flock)
{
    // steering accumulator and count of neighbors, both initially zero
    Vector3 steering;
    int neighbors = 0;

    // for each of the other vehicles...
    AVIterator flockEndIter = flock.end();
    for (AVIterator otherVehicle = flock.begin(); otherVehicle != flockEndIter; ++otherVehicle )
    {
        if (inBoidNeighborhood (**otherVehicle, Radius()*3, maxDistance, cosMaxAngle))
        {
            // add in steering contribution
            // (opposite of the offset direction, divided once by distance
            // to normalise, divided another time to get 1/d falloff)
            const Vector3 offset = (**otherVehicle).Position() - Position();
            const float distanceSquared = offset.dotProduct(offset);
            steering += (offset / -distanceSquared);

            // count neighbors
            ++neighbors;
        }
    }
    
    return Vec3Utilities::normalise(steering);
}


// ----------------------------------------------------------------------------
// Alignment behavior: steer to head in same direction as neighbors
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForAlignment(const float maxDistance, const float cosMaxAngle, const AVGroup& flock)
{
    // steering accumulator and count of neighbors, both initially zero
    Vector3 steering;
    int neighbors = 0;

    // for each of the other vehicles...
    for (AVIterator otherVehicle = flock.begin(); otherVehicle != flock.end(); otherVehicle++)
    {
        if (inBoidNeighborhood (**otherVehicle, Radius()*3, maxDistance, cosMaxAngle))
        {
            // accumulate sum of neighbor's heading
            steering += (**otherVehicle).Forward();

            // count neighbors
            neighbors++;
        }
    }

    // divide by neighbors, subtract off current heading to get error-
    // correcting direction, then normalise to pure direction
    if (neighbors > 0) 
	{
		steering = ((steering / (float)neighbors) - Forward());
		steering.normalise();
	}

    return steering;
}

// ----------------------------------------------------------------------------
// Cohesion behavior: to to move toward center of neighbors
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForCohesion(const float maxDistance, const float cosMaxAngle, const AVGroup& flock)
{
    // steering accumulator and count of neighbors, both initially zero
    Vector3 steering;
    int neighbors = 0;

    // for each of the other vehicles...
    for (AVIterator otherVehicle = flock.begin(); otherVehicle != flock.end(); otherVehicle++)
    {
        if (inBoidNeighborhood (**otherVehicle, Radius()*3, maxDistance, cosMaxAngle))
        {
            // accumulate sum of neighbor's positions
            steering += (**otherVehicle).Position();

            // count neighbors
            neighbors++;
        }
    }

    // divide by neighbors, subtract off current position to get error-
    // correcting direction, then normalise to pure direction
    if (neighbors > 0) 
		steering = ((steering / (float)neighbors) - Position()).normalise();

    return steering;
}

// ----------------------------------------------------------------------------
// pursuit of another vehicle (& version with ceiling on prediction time)
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForPursuit(const AbstractVehicle& quarry)
{
    return steerForPursuit (quarry, FLT_MAX);
}


template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForPursuit(const AbstractVehicle& quarry, const float maxPredictionTime)
{
    // offset from this to quarry, that distance, unit vector toward quarry
    const Vector3 offset = quarry.Position() - Position();
    const float distance = offset.length ();
    const Vector3 unitOffset = offset / distance;

    // how parallel are the paths of "this" and the quarry
    // (1 means parallel, 0 is pependicular, -1 is anti-parallel)
    const float parallelness = Forward().dotProduct (quarry.Forward());

    // how "forward" is the direction to the quarry
    // (1 means dead ahead, 0 is directly to the side, -1 is straight back)
    const float forwardness = Forward().dotProduct (unitOffset);

    const float directTravelTime = distance / Speed ();
    const int f = intervalComparison (forwardness,  -0.707f, 0.707f);
    const int p = intervalComparison (parallelness, -0.707f, 0.707f);

    float timeFactor = 0; // to be filled in below

    // Break the pursuit into nine cases, the cross product of the
    // quarry being [ahead, aside, or behind] us and heading
    // [parallel, perpendicular, or anti-parallel] to us.
	switch (f)
    {
    case +1:
        switch (p)
        {
        case +1:          // ahead, parallel
            timeFactor = 4;
            break;
        case 0:           // ahead, perpendicular
            timeFactor = 1.8f;
            break;
        case -1:          // ahead, anti-parallel
            timeFactor = 0.85f;
            break;
        }
        break;
    case 0:
        switch (p)
        {
        case +1:          // aside, parallel
            timeFactor = 1;
            break;
        case 0:           // aside, perpendicular
            timeFactor = 0.8f;
            break;
        case -1:          // aside, anti-parallel
            timeFactor = 4;
            break;
        }
        break;
    case -1:
        switch (p)
        {
        case +1:          // behind, parallel
            timeFactor = 0.5f;
            break;
        case 0:           // behind, perpendicular
            timeFactor = 2;
            break;
        case -1:          // behind, anti-parallel
            timeFactor = 2;
            break;
        }
        break;
    }

    // estimated time until intercept of quarry
    const float et = directTravelTime * timeFactor;

    // xxx experiment, if kept, this limit should be an argument
    const float etl = (et > maxPredictionTime) ? maxPredictionTime : et;

    // estimated position of quarry at intercept
    const Vector3 target = quarry.PredictFuturePosition (etl);

    return steerForSeek (target);
}

// ----------------------------------------------------------------------------
// evasion of another vehicle
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForEvasion(const AbstractVehicle& menace, const float maxPredictionTime)
{
    // offset from this to menace, that distance, unit vector toward menace
    const Vector3 offset = menace.Position() - Position();
    const float distance = offset.length ();

    const float roughTime = distance / menace.Speed();
    const float predictionTime = ((roughTime > maxPredictionTime) ?
                                  maxPredictionTime :
                                  roughTime);

    const Vector3 target = menace.PredictFuturePosition (predictionTime);

    return steerForFlee (target);
}


// ----------------------------------------------------------------------------
// tries to maintain a given speed, returns a maxForce-clipped steering
// force along the forward/backward axis
template<class Super> Vector3 Core::AI::SteerLibraryMixin<Super>::steerForTargetSpeed (const float targetSpeed)
{
    const float mf = MaxForce();
    const float speedError = targetSpeed - Speed();
    return Forward() * clip (speedError, -mf, +mf);
}


#endif // OPENSTEER_STEERLIBRARY_H
