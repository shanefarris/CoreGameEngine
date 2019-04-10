#ifndef _OGREODEUTILITY_H_
#define _OGREODEUTILITY_H_

#include "PreReqs.h"

namespace Ode
{
	class Utility
	{
	public:
		Utility(){}
		~Utility(){}

		static f32 randomReal();

		static const f32 Infinity;

		/** returns a CFM value for use on joints or contacts
			@param timeStep is the the stepping time for the world, see Steppers
		*/
		static f32 getCFM(const f32& spring, const f32& dampening,const f32& timeStep);

		/** returns a ERP value for use on joints or contacts
		*/
		static f32 getERP(const f32& spring, const f32& dampening, const f32& timeStep);
		
		/** can be used to get spring constants out of a ERP and CFM value
		*/
		static void getSpringConstants(const f32& CFM, const f32& ERP, const f32& timeStep, f32& spring, f32& dampening);
	};
}

#endif

