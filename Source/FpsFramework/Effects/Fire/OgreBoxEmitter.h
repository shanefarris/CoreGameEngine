#ifdef COMPILE_EFFECT_FIRE

#ifndef __BoxEmitter_H__
#define __BoxEmitter_H__

#include "OgreAreaEmitter.h"

namespace Ogre 
{

    /** Particle emitter which emits particles randomly from points inside a box.
    @remarks
        This basic particle emitter emits particles from a box area. The
        initial direction of these particles can either be a single direction (i.e. a line),
        a random scattering inside a cone, or a random scattering in all directions, 
        depending the 'angle' parameter, which is the angle across which to scatter the 
        particles either side of the base direction of the emitter. 
    */
    class BoxEmitter : public AreaEmitter
    {
    public:
        BoxEmitter(ParticleSystem* psys);

        /** See ParticleEmitter. */
        void _initParticle(Particle* pParticle);
    };

	/** Factory class for particle emitter of type "Box".
        Creates instances of BoxEmitter to be used in particle systems. 
    */
    class BoxEmitterFactory : public ParticleEmitterFactory
    {
    protected:

    public:
        /** See ParticleEmitterFactory */
        String getName() const
        { 
            return "BoxWithCustomParam"; 
        }

        /** See ParticleEmitterFactory */
        ParticleEmitter* createEmitter(ParticleSystem* psys) 
        {
            ParticleEmitter* emit = OGRE_NEW BoxEmitter(psys);
            mEmitters.push_back(emit);
            return emit;
        }
    };
}

#endif

#endif // COMPILE_EFFECT_FIRE