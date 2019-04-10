#ifndef OPENSTEER_VEC3UTILITIES_H
#define OPENSTEER_VEC3UTILITIES_H

#include "Defines.h"
#include "Utilities.h"
#include "OgreVector3.h"

namespace Core 
{
namespace AI
{
	class Vec3Utilities
	{
	public:           
		/**
		 * Retuns distance between @a a and @a b.
		 */
		static inline float distance (const Vector3& a, const Vector3& b) 
		{
			return (a-b).length();
		} 

		// normalize: returns normalized version (parallel to this, length = 1)
		static inline Vector3 normalise (const Vector3& vec)
		{
			// skip divide if length is zero
			const float len = vec.length ();
			return (len>0) ? vec / len : vec;
		}

		static inline Vector3 setYtoZero (Vector3 vec)  
		{
			return Vector3 (vec.x, 0, vec.z);
		}

		// ----------------------------------------------------------------------------
		// Returns a position randomly distributed inside a sphere of unit radius
		// centered at the origin.  Orientation will be random and length will range
		// between 0 and 1
		static Vector3 RandomVectorInUnitRadiusSphere (void)
		{
			Vector3 v;

			do
			{
				v.x = frandom01()*2 - 1;
				v.y = frandom01()*2 - 1;
				v.z = frandom01()*2 - 1;
			}
			while (v.length() >= 1);

			return v;
		}

		// ----------------------------------------------------------------------------
		// Returns a position randomly distributed on a disk of unit radius
		// on the XZ (Y=0) plane, centered at the origin.  Orientation will be
		// random and length will range between 0 and 1
		static Vector3 randomVectorOnUnitRadiusXZDisk (void)
		{
			Vector3 v;

			do
			{
				v.x = frandom01()*2 - 1;
				v.y = 0;
				v.z = frandom01()*2 - 1;
			}
			while (v.length() >= 1);

			return v;
		}

		// ----------------------------------------------------------------------------
		// Returns a position randomly distributed on the surface of a sphere
		// of unit radius centered at the origin.  Orientation will be random
		// and length will be 1
		static inline Vector3 RandomUnitVector (void)
		{
			return Vec3Utilities::normalise(RandomVectorInUnitRadiusSphere());
		}

		// ----------------------------------------------------------------------------
		// Returns a position randomly distributed on a circle of unit radius
		// on the XZ (Y=0) plane, centered at the origin.  Orientation will be
		// random and length will be 1
		static inline Vector3 RandomUnitVectorOnXZPlane (void)
		{
			return normalise(setYtoZero(RandomVectorInUnitRadiusSphere()));
		}

		// ----------------------------------------------------------------------------
		// used by limitMaxDeviationAngle / limitMinDeviationAngle below
		static Vector3 vecLimitDeviationAngleUtility (const bool insideOrOutside,
											const Vector3& source,
											const float cosineOfConeAngle,
											const Vector3& basis)
		{
			// immediately return zero length input vectors
			float sourceLength = source.length();
			if (sourceLength == 0) return source;

			// measure the angular diviation of "source" from "basis"
			const Vector3 direction = source / sourceLength;
			float cosineOfSourceAngle = direction.dotProduct (basis);

			// Simply return "source" if it already meets the angle criteria.
			// (note: we hope this top "if" gets compiled out since the flag
			// is a constant when the function is inlined into its caller)
			if (insideOrOutside)
			{
			// source vector is already inside the cone, just return it
			if (cosineOfSourceAngle >= cosineOfConeAngle) return source;
			}
			else
			{
			// source vector is already outside the cone, just return it
			if (cosineOfSourceAngle <= cosineOfConeAngle) return source;
			}

			// find the portion of "source" that is perpendicular to "basis"
			Vector3 perp = source.perpendicularComponent (basis);

			// normalize that perpendicular
			const Vector3 unitPerp = Vec3Utilities::normalise(perp);

			// construct a new vector whose length equals the source vector,
			// and lies on the intersection of a plane (formed the source and
			// basis vectors) and a cone (whose axis is "basis" and whose
			// angle corresponds to cosineOfConeAngle)
			float perpDist = sqrt(1 - (cosineOfConeAngle * cosineOfConeAngle));
			const Vector3 c0 = basis * cosineOfConeAngle;
			const Vector3 c1 = unitPerp * perpDist;
			return (c0 + c1) * sourceLength;
		}

		// ----------------------------------------------------------------------------
		// Enforce an upper bound on the angle by which a given arbitrary vector
		// diviates from a given reference direction (specified by a unit basis
		// vector).  The effect is to clip the "source" vector to be inside a cone
		// defined by the basis and an angle.
		static inline Vector3 limitMaxDeviationAngle (const Vector3& source,
											const float cosineOfConeAngle,
											const Vector3& basis)
		{
			return vecLimitDeviationAngleUtility (true,  source, cosineOfConeAngle, basis);
		}

		// ----------------------------------------------------------------------------
		// Enforce a lower bound on the angle by which a given arbitrary vector
		// diviates from a given reference direction (specified by a unit basis
		// vector).  The effect is to clip the "source" vector to be outside a cone
		// defined by the basis and an angle.
		static inline Vector3 limitMinDeviationAngle (const Vector3& source,
											const float cosineOfConeAngle,
											const Vector3& basis)
		{    
			return vecLimitDeviationAngleUtility (false,  source, cosineOfConeAngle, basis);
		}

		// return cross product a x b
		static inline Vector3 crossProduct(const Vector3& a, const Vector3& b)
		{
			Vector3 result((a.y * b.z) - (a.z * b.y),
						(a.z * b.x) - (a.x * b.z),
						(a.x * b.y) - (a.y * b.x));
			return result;
		}

		// ----------------------------------------------------------------------------
		// given a vector, return a vector perpendicular to it (note that this
		// arbitrarily selects one of the infinitude of perpendicular vectors)
		static Vector3 findPerpendicularIn3d (const Vector3& direction)
		{
			// to be filled in:
			Vector3 quasiPerp;  // a direction which is "almost perpendicular"
			Vector3 result;     // the computed perpendicular to be returned

			// three mutually perpendicular basis vectors
			const Vector3 i (1, 0, 0);
			const Vector3 j (0, 1, 0);
			const Vector3 k (0, 0, 1);

			// measure the projection of "direction" onto each of the axes
			const float id = i.dotProduct (direction);
			const float jd = j.dotProduct (direction);
			const float kd = k.dotProduct (direction);

			// set quasiPerp to the basis which is least parallel to "direction"
			if ((id <= jd) && (id <= kd))
			{
				quasiPerp = i;               // projection onto i was the smallest
			}
			else
			{
				if ((jd <= id) && (jd <= kd))
					quasiPerp = j;           // projection onto j was the smallest
				else
					quasiPerp = k;           // projection onto k was the smallest
			}

			// return the cross product (direction x quasiPerp)
			// which is guaranteed to be perpendicular to both of them
			result = crossProduct (direction, quasiPerp);
			return result;
		}

		// ----------------------------------------------------------------------------
		// Returns the distance between a point and a line.  The line is defined in
		// terms of a point on the line ("lineOrigin") and a UNIT vector parallel to
		// the line ("lineUnitTangent")
		static inline float distanceFromLine (const Vector3& point,
									   const Vector3& lineOrigin,
									   const Vector3& lineUnitTangent)
		{
			const Vector3 offset = point - lineOrigin;
			const Vector3 perp = offset.perpendicularComponent (lineUnitTangent);
			return perp.length();
		}

		/**
		 * Returns the nearest point on the segment @a segmentPoint0 to 
		 * @a segmentPoint1 from @a point.
		 */
		static Vector3 nearestPointOnSegment( const Vector3& point,
										  const Vector3& segmentPoint0,
										  const Vector3& segmentPoint1 )
		{
			// convert the test point to be "local" to ep0
			Vector3 const local( point - segmentPoint0 );
		    
			// find the projection of "local" onto "segmentNormal"
			Vector3 const segment( segmentPoint1 - segmentPoint0 );
			float const segmentLength( segment.length() );
		    
			assert( 0 != segmentLength && "Segment mustn't be of length zero." );
		    
			Vector3 const segmentNormalized( segment / segmentLength ); 
			float segmentProjection = segmentNormalized.dotProduct (local);
		    
			segmentProjection = clamp( segmentProjection, 0.0f, segmentLength );
		    
			Vector3 result( segmentNormalized * segmentProjection );
			result +=  segmentPoint0;
			return result;    
		}

		/**
		 * Computes minimum distance from @a point to the line segment defined by
		 * @a segmentPoint0 and @a segmentPoint1.
		 */
		static inline float pointToSegmentDistance ( const Vector3& point,
										const Vector3& segmentPoint0,
										const Vector3& segmentPoint1)
		{
			return distance( point, nearestPointOnSegment( point, segmentPoint0, segmentPoint1 ) );
		}
	};

}
}

#endif // OPENSTEER_VEC3UTILITIES_H
