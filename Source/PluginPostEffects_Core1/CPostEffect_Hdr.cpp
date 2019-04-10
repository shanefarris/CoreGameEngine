#include "CPostEffect_Hdr.h"
#include "CPostEffect.h"

#include "OgreViewport.h"
#include "OgreTechnique.h"
#include "OgreCompositorManager.h"
#include "OgreCompositionTechnique.h"

using namespace Core::Effects;
using namespace Core::Plugin;

CPostEffect_Hdr::CPostEffect_Hdr() : CPostEffect("HDR")
{
}

void CPostEffect_Hdr::RegisterPostEffect()
{
	CompositorInstance* instance = CompositorManager::getSingleton().addCompositor(m_Viewport, mCompName, 0);
	if(instance)
	{
		instance->addListener(this);
		notifyViewportSize(m_Viewport->getActualWidth(), m_Viewport->getActualHeight());
		notifyCompositor(instance);
	}
}

void CPostEffect_Hdr::notifyViewportSize(int width, int height)
{
	mVpWidth = width;
	mVpHeight = height;
}

void CPostEffect_Hdr::notifyCompositor(CompositorInstance* instance)
{
	// Get some RTT dimensions for later calculations
	CompositionTechnique::TextureDefinitionIterator defIter = instance->getTechnique()->getTextureDefinitionIterator();
	while (defIter.hasMoreElements())
	{
		CompositionTechnique::TextureDefinition* def = defIter.getNext();
		if(def->name == "rt_bloom0")
		{
			mBloomSize = (int)def->width; // should be square

			// Calculate gaussian texture offsets & weights
			float deviation = 3.0f;
			float texelSize = 1.0f / (float)mBloomSize;

			// Central sample, no offset
			mBloomTexOffsetsHorz[0][0] = 0.0f;
			mBloomTexOffsetsHorz[0][1] = 0.0f;
			mBloomTexOffsetsVert[0][0] = 0.0f;
			mBloomTexOffsetsVert[0][1] = 0.0f;
			mBloomTexWeights[0][0] = mBloomTexWeights[0][1] =
				mBloomTexWeights[0][2] = Math::gaussianDistribution(0, 0, deviation);
			mBloomTexWeights[0][3] = 1.0f;

			// 'pre' samples
			for(int i = 1; i < 8; ++i)
			{
				mBloomTexWeights[i][0] = mBloomTexWeights[i][1] = mBloomTexWeights[i][2] = 1.25f * Math::gaussianDistribution((f32)i, 0.0f, deviation);
				mBloomTexWeights[i][3] = 1.0f;
				mBloomTexOffsetsHorz[i][0] = (f32)i * texelSize;
				mBloomTexOffsetsHorz[i][1] = 0.0f;
				mBloomTexOffsetsVert[i][0] = 0.0f;
				mBloomTexOffsetsVert[i][1] = (f32)i * texelSize;
			}
			// 'post' samples
			for(int i = 8; i < 15; ++i)
			{
				mBloomTexWeights[i][0] = mBloomTexWeights[i][1] = mBloomTexWeights[i][2] = mBloomTexWeights[i - 7][0];
				mBloomTexWeights[i][3] = 1.0f;

				mBloomTexOffsetsHorz[i][0] = -mBloomTexOffsetsHorz[i - 7][0];
				mBloomTexOffsetsHorz[i][1] = 0.0f;
				mBloomTexOffsetsVert[i][0] = 0.0f;
				mBloomTexOffsetsVert[i][1] = -mBloomTexOffsetsVert[i - 7][1];
			}
		}
	}
}

void CPostEffect_Hdr::notifyMaterialSetup(u32 pass_id, MaterialPtr &mat)
{
	// Prepare the fragment params offsets
	switch (pass_id)
	{
	//case 994: // rt_lum4
	case 993: // rt_lum3
	case 992: // rt_lum2
	case 991: // rt_lum1
	case 990: // rt_lum0
		break;
	case 800: // rt_brightpass
		break;
	case 701: // rt_bloom1
		{
			// horizontal bloom
			mat->load();
			GpuProgramParametersSharedPtr fparams = mat->getBestTechnique()->getPass(0)->getFragmentProgramParameters();
			const String& progName = mat->getBestTechnique()->getPass(0)->getFragmentProgramName();
			fparams->setNamedConstant("sampleOffsets", mBloomTexOffsetsHorz[0], 15);
			fparams->setNamedConstant("sampleWeights", mBloomTexWeights[0], 15);
			break;
		}
	case 700: // rt_bloom0
		{
			// vertical bloom
			mat->load();
			GpuProgramParametersSharedPtr fparams = mat->getTechnique(0)->getPass(0)->getFragmentProgramParameters();
			const String& progName = mat->getBestTechnique()->getPass(0)->getFragmentProgramName();
			fparams->setNamedConstant("sampleOffsets", mBloomTexOffsetsVert[0], 15);
			fparams->setNamedConstant("sampleWeights", mBloomTexWeights[0], 15);
			break;
		}
	}
}

void CPostEffect_Hdr::notifyMaterialRender(u32 pass_id, MaterialPtr& mat)
{
}
