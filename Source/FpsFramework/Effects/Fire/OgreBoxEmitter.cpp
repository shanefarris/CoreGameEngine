#ifdef COMPILE_EFFECT_FIRE

#include "OgreBoxEmitter.h"
#include <OgreParticle.h>
#include <OgreException.h>
#include <OgreStringConverter.h>

namespace Ogre 
{
    BoxEmitter::BoxEmitter(ParticleSystem* psys)
        : AreaEmitter(psys)
    {
        initDefaults("BoxWithCustomParam");
    }
    //-----------------------------------------------------------------------
    void BoxEmitter::_initParticle(Particle* pParticle)
    {
        Vector3 xOff, yOff, zOff;

        // Call superclass
        AreaEmitter::_initParticle(pParticle);

        xOff = Math::SymmetricRandom() * mXRange;
        yOff = Math::SymmetricRandom() * mYRange;
        zOff = Math::SymmetricRandom() * mZRange;

        pParticle->position = mPosition + xOff + yOff + zOff;
        

        // Generate complex data by reference
        genEmissionColour(pParticle->colour);
        genEmissionDirection(pParticle->direction);
        genEmissionVelocity(pParticle->direction);

        // Generate simpler data
        pParticle->timeToLive = pParticle->totalTimeToLive = genEmissionTTL();
        
    }

}

#endif // COMPILE_EFFECT_FIRE
