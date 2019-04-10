#ifdef COMPILE_EFFECT_FIRE

#include "OgreAreaEmitter.h"
#include "OgreParticleCustomParam.h"

#include <OgreParticle.h>
#include <OgreQuaternion.h>
#include <OgreException.h>
#include <OgreStringConverter.h>


namespace Ogre {

    // Instatiate statics
    AreaEmitter::CmdWidth AreaEmitter::msWidthCmd;
    AreaEmitter::CmdHeight AreaEmitter::msHeightCmd;
    AreaEmitter::CmdDepth AreaEmitter::msDepthCmd;
	AreaEmitter::CmdCustomParamValue AreaEmitter::msCustomParamValue;

    //-----------------------------------------------------------------------
    bool AreaEmitter::initDefaults(const String& t)
    {
        // called by the constructor as initDefaults("Type")

        // Defaults
        mDirection = Vector3::UNIT_Z;
        mUp = Vector3::UNIT_Y;
        setSize(100,100,100);
        mType = t;
		mCustomParamValue = Ogre::Vector4::ZERO;

        // Set up parameters
        if (createParamDictionary(mType + "Emitter"))
        {

            addBaseParameters();
            ParamDictionary* dict = getParamDictionary();

            // Custom params
            dict->addParameter(ParameterDef("width", 
                "Width of the shape in world coordinates.",
                PT_REAL),&msWidthCmd);
            dict->addParameter(ParameterDef("height", 
                "Height of the shape in world coordinates.",
                PT_REAL),&msHeightCmd);
            dict->addParameter(ParameterDef("depth", 
                "Depth of the shape in world coordinates.",
                PT_REAL),&msDepthCmd);
            dict->addParameter(ParameterDef("custom_params", 
                "Custom parameter value per particle as Vector4",
                PT_STRING),&msCustomParamValue);
            return true;

        }
        return false;
    }

    //-----------------------------------------------------------------------
    unsigned short AreaEmitter::_getEmissionCount(Real timeElapsed)
    {
        // Use basic constant emission 
        return genConstantEmissionCount(timeElapsed);
    }
    //-----------------------------------------------------------------------
    void AreaEmitter::setDirection( const Vector3& direction )
    {
        ParticleEmitter::setDirection( direction );

        // Update the ranges
        genAreaAxes();

        
    }
    //-----------------------------------------------------------------------
    void AreaEmitter::setSize(const Vector3& size)
    {
        mSize = size;
        genAreaAxes();
    }
    //-----------------------------------------------------------------------
    void AreaEmitter::setSize(Real x, Real y, Real z)
    {
        mSize.x = x;
        mSize.y = y;
        mSize.z = z;
        genAreaAxes();
    }
    //-----------------------------------------------------------------------
    void AreaEmitter::setWidth(Real width)
    {
        mSize.x = width;
        genAreaAxes();
    }
    //-----------------------------------------------------------------------
    Real AreaEmitter::getWidth(void) const
    {
        return mSize.x;
    }
    //-----------------------------------------------------------------------
    void AreaEmitter::setHeight(Real height)
    {
        mSize.y = height;
        genAreaAxes();
    }
    //-----------------------------------------------------------------------
    Real AreaEmitter::getHeight(void) const
    {
        return mSize.y;
    }
    //-----------------------------------------------------------------------
    void AreaEmitter::setDepth(Real depth)
    {
        mSize.z = depth;
        genAreaAxes();
    }
    //-----------------------------------------------------------------------
    Real AreaEmitter::getDepth(void) const
    {
        return mSize.z;
    }
	//-----------------------------------------------------------------------
	void AreaEmitter::setCustomParamValue(const Vector4& v)
	{
		mCustomParamValue = v;
	}
	//-----------------------------------------------------------------------
	const Vector4& AreaEmitter::getCustomParamValue(void) const
	{
		return mCustomParamValue;
	}

	//-----------------------------------------------------------------------
    void AreaEmitter::genAreaAxes(void)
    {
        Vector3 mLeft = mUp.crossProduct(mDirection);

        mXRange = mLeft * (mSize.x * 0.5f);
        mYRange = mUp * (mSize.y * 0.5f);
        mZRange = mDirection * (mSize.z * 0.5f);
    }

	//-----------------------------------------------------------------------
	void AreaEmitter::_initParticle(Particle* pParticle)
	{
		// parent
		ParticleEmitter::_initParticle(pParticle);

		// setup
		ParticleVisualData* pData = pParticle->getVisualData();
		if(pData != NULL) {
			ParticleCustomParam* pCustom = static_cast<ParticleCustomParam*>(pData);
			pCustom->paramValue = mCustomParamValue;
		}
	}

    //-----------------------------------------------------------------------
    // Command objects
    //-----------------------------------------------------------------------
    //-----------------------------------------------------------------------
    String AreaEmitter::CmdWidth::doGet(const void* target) const
    {
        return StringConverter::toString(
            static_cast<const AreaEmitter*>(target)->getWidth() );
    }
    void AreaEmitter::CmdWidth::doSet(void* target, const String& val)
    {
        static_cast<AreaEmitter*>(target)->setWidth(StringConverter::parseReal(val));
    }
    //-----------------------------------------------------------------------
    String AreaEmitter::CmdHeight::doGet(const void* target) const
    {
        return StringConverter::toString(
            static_cast<const AreaEmitter*>(target)->getHeight() );
    }
    void AreaEmitter::CmdHeight::doSet(void* target, const String& val)
    {
        static_cast<AreaEmitter*>(target)->setHeight(StringConverter::parseReal(val));
    }
    //-----------------------------------------------------------------------
    String AreaEmitter::CmdDepth::doGet(const void* target) const
    {
        return StringConverter::toString(
            static_cast<const AreaEmitter*>(target)->getDepth() );
    }
    void AreaEmitter::CmdDepth::doSet(void* target, const String& val)
    {
        static_cast<AreaEmitter*>(target)->setDepth(StringConverter::parseReal(val));
    }
    //-----------------------------------------------------------------------
    String AreaEmitter::CmdCustomParamValue::doGet(const void* target) const
    {
		return StringConverter::toString( static_cast<const AreaEmitter*>(target)->getCustomParamValue() );
	}
    void AreaEmitter::CmdCustomParamValue::doSet(void* target, const String& val)
    {
		static_cast<AreaEmitter*>(target)->setCustomParamValue( StringConverter::parseVector4(val) );
	}
}

#endif // COMPILE_EFFECT_FIRE