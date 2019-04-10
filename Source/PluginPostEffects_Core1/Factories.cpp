#define DLL_EXPORT

#include "Factories.h"
#include "CPostEffect_Bloom.h"
#include "CPostEffect_Hdr.h"
#include "CPostEffect_MotionBlur.h"
#include "CPostEffect_SSAO.h"

using namespace Core::Plugin;

// CPostEffectFactory_Bloom
CPostEffectFactory_Bloom::CPostEffectFactory_Bloom()
{
	LabelName = "BLOOM";
}

CPostEffectFactory_Bloom::~CPostEffectFactory_Bloom()
{
}

Core::Effects::CPostEffect* CPostEffectFactory_Bloom::GetPostEffect()
{
	return new CPostEffect_Bloom();
}

// CPostEffectFactory_Hdr
CPostEffectFactory_Hdr::CPostEffectFactory_Hdr()
{
	LabelName = "HDR";
}

CPostEffectFactory_Hdr::~CPostEffectFactory_Hdr()
{
}

Core::Effects::CPostEffect* CPostEffectFactory_Hdr::GetPostEffect()
{
	return new CPostEffect_Hdr();
}

// CPostEffectFactory_MotionBlur
CPostEffectFactory_MotionBlur::CPostEffectFactory_MotionBlur()
{
	LabelName = "MOTION_BLUR";
}

CPostEffectFactory_MotionBlur::~CPostEffectFactory_MotionBlur()
{
}

Core::Effects::CPostEffect* CPostEffectFactory_MotionBlur::GetPostEffect()
{
	return new CPostEffect_MotionBlur();
}

// CPostEffectFactory_SSAO
CPostEffectFactory_SSAO::CPostEffectFactory_SSAO()
{
	LabelName = "SSAO";
}

CPostEffectFactory_SSAO::~CPostEffectFactory_SSAO()
{
}

Core::Effects::CPostEffect* CPostEffectFactory_SSAO::GetPostEffect()
{
	return new CPostEffect_SSAO();
}