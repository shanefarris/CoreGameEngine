#include "Utility.h"

using namespace Ode;
using namespace Ogre;

const f32 Utility::Infinity = (f32)dInfinity;

f32 Utility::randomReal()
{
	return (f32)dRandReal();
}

/**
According to the ODE docs;
	
By adjusting the values of ERP and CFM, you can achieve various effects. 
For example you can simulate springy constraints, where the two bodies oscillate 
as though connected by springs. Or you can simulate more spongy constraints, without 
the oscillation. In fact, ERP and CFM can be selected to have the same effect as any 
desired spring and damper constants. If you have a spring constant kp and damping constant kd, 
then the corresponding ODE constants are:
	
ERP = h kp / (h kp + kd)
CFM = 1 / (h kp + kd)
	
where h is the stepsize. These values will give the same effect as a spring-and-damper 
system simulated with implicit first order integration.
*/
//-----------------------------------------------------------------------
f32 Utility::getCFM(const f32& spring, const f32& dampening, const f32& timeStep)
{
	return 1 / ((timeStep * spring) + dampening);
}

//-----------------------------------------------------------------------
f32 Utility::getERP(const f32& spring, const f32& dampening, const f32& timeStep)
{
	return  (timeStep * spring) / ((timeStep * spring) + dampening);
}
	
//-----------------------------------------------------------------------
void Utility::getSpringConstants(const f32& CFM, const f32& ERP, const f32& timeStep, f32& spring, f32& dampening)
{
	spring = (ERP / CFM) / timeStep;
	dampening = (1 / CFM) - timeStep * spring;
}
