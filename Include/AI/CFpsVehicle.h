#ifndef __CFPSVEHICLE_H__
#define __CFPSVEHICLE_H__

#include "AbstractVehicle.h"
#include "SteerLibrary.h"
#include "Vec3Utilities.h"

namespace Core
{
	class CPlayer;
	
namespace AI
{
    typedef LocalSpaceMixin<AbstractVehicle> SimpleVehicle_1;
    typedef SteerLibraryMixin<SimpleVehicle_1> SimpleVehicle_2;

    class CORE_EXPORT CFpsVehicle : public SimpleVehicle_2
    {
    public:
        CFpsVehicle(CPlayer* Player);
        ~CFpsVehicle();
        
        CPlayer* GetPlayer() { return m_Player; }

        // Reset vehicle state
        void Reset (void)
        {
            // Reset LocalSpace state
            resetLocalSpace ();

            // Reset SteerLibraryMixin state
            // (XXX this seems really fragile, needs to be redesigned XXX)
            SimpleVehicle_2::reset();

            SetMass (1);          // mass (defaults to 1 so acceleration=force)
            SetSpeed (0);         // speed along Forward direction.

            SetRadius (0.5f);     // size of bounding sphere

            SetMaxForce (0.1f);   // steering force is clipped to this magnitude
            SetMaxSpeed (1.0f);   // velocity is clipped to this magnitude

			SetUp(Vector3::UNIT_Y);

            // Reset bookkeeping to do running averages of these quanities
            ResetSmoothedPosition ();
            ResetSmoothedCurvature ();
            ResetSmoothedAcceleration ();
        }

        // get/set mass
        float Mass (void) const {return _mass;}
        float SetMass (float m) {return _mass = m;}

        // get velocity of vehicle
        Vector3 Velocity (void) const {return Forward() * _speed;}

        // get/set speed of vehicle  (may be faster than taking mag of velocity)
        float Speed (void) const {return _speed;}
        float SetSpeed (float s) {return _speed = s;}

        // size of bounding sphere, for obstacle avoidance, etc.
        float Radius (void) const {return _radius;}
        float SetRadius (float m) {return _radius = m;}

        // get/set maxForce
        float MaxForce (void) const {return _maxForce;}
        float SetMaxForce (float mf) {return _maxForce = mf;}

        // get/set maxSpeed
        float MaxSpeed (void) const {return _maxSpeed;}
        float SetMaxSpeed (float ms) {return _maxSpeed = ms;}

        // ratio of speed to max possible speed (0 slowest, 1 fastest)
        float GetRelativeSpeed (void) const {return Speed() / MaxSpeed();}

        // apply a given steering force to our momentum, adjusting our orientation to maintain velocity-alignment.
        void ApplySteeringForce (const Vector3& force, const float deltaTime);

        // the default version: keep FORWARD parallel to velocity, change
        // UP as little as possible.
        virtual void RegenerateLocalSpace (const Vector3& newVelocity, const float elapsedTime);

        // alternate version: keep FORWARD parallel to velocity, adjust UP
        // according to a no-basis-in-reality "banking" behavior, something
        // like what birds and airplanes do. 
        void RegenerateLocalSpaceForBanking (const Vector3& newVelocity, const float elapsedTime);

        // adjust the steering force passed to ApplySteeringForce.
        // allows a specific vehicle class to redefine this adjustment.
        // default is to disallow backward-facing steering at low speed.
        virtual Vector3 AdjustRawSteeringForce (const Vector3& force, const float deltaTime);

        // apply a given braking force (for a given dt) to our momentum.
        void ApplyBrakingForce (const float rate, const float deltaTime);

        // predict position of this vehicle at some time in the future (assumes velocity remains constant)
        Vector3 PredictFuturePosition (const float predictionTime) const;

        // get instantaneous GetCurvature (since last update)
        float GetCurvature (void) const {return _curvature;}

        // get/Reset GetSmoothedCurvature, GetSmoothedAcceleration and GetSmoothedPosition
        float GetSmoothedCurvature (void) {return _smoothedCurvature;}
        float ResetSmoothedCurvature (float value = 0)
        {
            _lastForward = Vector3::ZERO;
            _lastPosition = Vector3::ZERO;
            return _smoothedCurvature = _curvature = value;
        }

        Vector3 GetSmoothedAcceleration (void) {return _smoothedAcceleration;}
        Vector3 ResetSmoothedAcceleration (const Vector3& value = Vector3::ZERO) { return _smoothedAcceleration = value; }
        Vector3 GetSmoothedPosition (void) {return _smoothedPosition;}
        Vector3 ResetSmoothedPosition (const Vector3& value = Vector3::ZERO) { return _smoothedPosition = value; }

        // give each vehicle a unique number
        int SerialNumber;
        static int SerialNumberCounter;

        // set a random "2D" heading: set local Up to global Y, then effectively
        // rotate about it by a random angle (pick random forward, derive side).
        void RandomizeHeadingOnXZPlane (void)
        {
			SetUp(Vector3::UNIT_Y);
            SetForward(Vec3Utilities::RandomUnitVectorOnXZPlane ());
            SetSide (localRotateForwardToSide (Forward()));
        }

		void Update(const float currentTime, const float elapsedTime) { }

    private:
		CPlayer*	m_Player;		// Used to get the player this vehical is attached to
        float		_mass;			// mass (defaults to unity so acceleration=force)
        float		_radius;		// size of bounding sphere, for obstacle avoidance, etc.
        float		_speed;			// speed along Forward direction.  Because local space
									// is velocity-aligned, velocity = Forward * Speed
        float		_maxForce;		// the maximum steering force this vehicle can apply
									// (steering force is clipped to this magnitude)
        float		_maxSpeed;		// the maximum speed this vehicle is allowed to move
									// (velocity is clipped to this magnitude)
		float		_smoothedCurvature;
        float		_curvature;
        Vector3		_lastForward;
        Vector3		_lastPosition;
        Vector3		_smoothedPosition;
        Vector3		_smoothedAcceleration;

        // measure path GetCurvature (1/turning-radius), maintain smoothed version
        void MeasurePathCurvature (const float elapsedTime);
    };


}
}
    
#endif // __CFPSVEHICLE_H__
