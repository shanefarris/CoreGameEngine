#include "CFpsVehicle.h"
#include <algorithm>

using namespace Core;
using namespace Core::AI;

int CFpsVehicle::SerialNumberCounter = 0;

CFpsVehicle::CFpsVehicle (CPlayer* Player) : m_Player(Player)
{
    // set inital state
    Reset();

    // maintain unique serial numbers
    SerialNumber = SerialNumberCounter++;
}

CFpsVehicle::~CFpsVehicle (void)
{
}

// Adjust the steering force passed to ApplySteeringForce. allows a specific vehicle class to redefine this adjustment.
// default is to disallow backward-facing steering at low speed. parameter names commented out to prevent compiler warning from "-W"
Vector3 CFpsVehicle::AdjustRawSteeringForce (const Vector3& force, const float /* deltaTime */)
{
    const float maxAdjustedSpeed = 0.2f * MaxSpeed ();

    if ((Speed () > maxAdjustedSpeed) || (force == Vector3::ZERO))
    {
        return force;
    }
    else
    {
        const float range = Speed() / maxAdjustedSpeed;
        // const float cosine = interpolate (pow (range, 6), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 10), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 20), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 100), 1.0f, -1.0f);
        // const float cosine = interpolate (pow (range, 50), 1.0f, -1.0f);
        const float cosine = interpolate (pow (range, 20), 1.0f, -1.0f);
        return Vec3Utilities::limitMaxDeviationAngle (force, cosine, Forward());
    }
}

// apply a given braking force (for a given dt) to our momentum.
//
// (this is intended as a companion to ApplySteeringForce, but I'm not sure how well integrated it is.  It was motivated by the fact that "braking" (as in
// "capture the flag" endgame) by using "forward * speed * -rate" as a steering force was causing problems in AdjustRawSteeringForce.  In fact it made it
// get NAN, but even if it had worked it would have defeated the braking.
//
// maybe the guts of ApplySteeringForce should be split off into a subroutine used by both ApplySteeringForce and ApplyBrakingForce?
void CFpsVehicle::ApplyBrakingForce (const float rate, const float deltaTime)
{
    const float rawBraking = Speed() * rate;
    const float clipBraking = ((rawBraking < MaxForce()) ?
                               rawBraking :
                               MaxForce());

    SetSpeed (Speed() - (clipBraking * deltaTime));
}

// apply a given steering force to our momentum, adjusting our orientation to maintain velocity-alignment.
void CFpsVehicle::ApplySteeringForce (const Vector3& force, const float elapsedTime)
{

    const Vector3 adjustedForce = AdjustRawSteeringForce (force, elapsedTime);

    // enforce limit on magnitude of steering force
    const Vector3 clippedForce = adjustedForce.truncateLength (MaxForce());

    // compute acceleration and velocity
    Vector3 newAcceleration = (clippedForce / Mass());
    Vector3 newVelocity = Velocity();

    // damp out abrupt changes and oscillations in steering acceleration
    // (rate is proportional to time step, then clipped into useful range)
    if (elapsedTime > 0)
    {
        const float smoothRate = clip (9 * elapsedTime, 0.15f, 0.4f);
        blendIntoAccumulator (smoothRate, newAcceleration,  _smoothedAcceleration);
    }

    // Euler integrate (per frame) acceleration into velocity
    newVelocity += _smoothedAcceleration * elapsedTime;

    // enforce speed limit
    newVelocity = newVelocity.truncateLength (MaxSpeed());

    // update Speed
    SetSpeed(newVelocity.length());

    // Euler integrate (per frame) velocity into position
    SetPosition(Position() + (newVelocity * elapsedTime));

    // regenerate local space (by default: align vehicle's forward axis with
    // new velocity, but this behavior may be overridden by derived classes.)
    RegenerateLocalSpace (newVelocity, elapsedTime);

    // maintain path GetCurvature information
    MeasurePathCurvature (elapsedTime);

    // running average of recent positions
    blendIntoAccumulator (elapsedTime * 0.06f, Position(), _smoothedPosition);
}

// the default version: keep FORWARD parallel to velocity, change UP as
// little as possible. parameter names commented out to prevent compiler warning from "-W"
void CFpsVehicle::RegenerateLocalSpace (const Vector3& newVelocity, const float /* elapsedTime */)
{
    // adjust orthonormal basis vectors to be aligned with new velocity
    if (Speed() > 0) 
		regenerateOrthonormalBasisUF (newVelocity / Speed());
}

// alternate version: keep FORWARD parallel to velocity, adjust UP according to a no-basis-in-reality "banking" behavior, something like what birds and airplanes do
void CFpsVehicle::RegenerateLocalSpaceForBanking (const Vector3& newVelocity, const float elapsedTime)
{
    // the length of this global-upward-pointing vector controls the vehicle's
    // tendency to right itself as it is rolled over from turning acceleration
    const Vector3 globalUp (0, 0.2f, 0);

    // acceleration points toward the center of local path GetCurvature, the
    // length determines how much the vehicle will roll while turning
    const Vector3 accelUp = _smoothedAcceleration * 0.05f;

    // combined banking, sum of UP due to turning and global UP
    const Vector3 bankUp = accelUp + globalUp;

    // blend bankUp into vehicle's UP basis vector
    const float smoothRate = elapsedTime * 3;
    Vector3 tempUp = Up();
    blendIntoAccumulator (smoothRate, bankUp, tempUp);
    SetUp(Vec3Utilities::normalise(tempUp));

    // adjust orthonormal basis vectors to be aligned with new velocity
    if (Speed() > 0) 
		regenerateOrthonormalBasisUF (newVelocity / Speed());
}

// measure path GetCurvature (1/turning-radius), maintain smoothed version
void CFpsVehicle::MeasurePathCurvature(const float elapsedTime)
{
    if (elapsedTime > 0)
    {
        const Vector3 dP = _lastPosition - Position();
        const Vector3 dF = (_lastForward - Forward()) / dP.length ();
        const Vector3 lateral = dF.perpendicularComponent (Forward());
        const float sign = (lateral.dotProduct (Side()) < 0) ? 1.0f : -1.0f;
        _curvature = lateral.length() * sign;
        blendIntoAccumulator (elapsedTime * 4.0f,
                              _curvature,
                              _smoothedCurvature);
        _lastForward = Forward();
        _lastPosition = Position();
    }
}

// predict position of this vehicle at some time in the future (assumes velocity remains constant, hence path is a straight line)
Vector3 CFpsVehicle::PredictFuturePosition(const float predictionTime) const
{
    return Position() + (Velocity() * predictionTime);
}
