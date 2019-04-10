#include "CPostEffect_Bloom.h"
#include "CPostEffect.h"

#include "OgreCompositorManager.h"
#include "OgreResourceGroupManager.h"
#include "OgreCompositionTargetPass.h"
#include "OgreCompositionPass.h"

using namespace Core::Effects;
using namespace Core::Plugin;

CPostEffect_Bloom::CPostEffect_Bloom() : CPostEffect("BLOOM")
{
	CompositorPtr comp = CompositorManager::getSingleton().create(mCompName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	{
		CompositionTechnique *t = comp->createTechnique();
		{
			CompositionTechnique::TextureDefinition *def = t->createTextureDefinition("rt0");
			def->width = 128;
			def->height = 128;
			//def->format = PF_A8R8G8B8;
		}
		{
			CompositionTechnique::TextureDefinition *def = t->createTextureDefinition("rt1");
			def->width = 128;
			def->height = 128;
			//def->format = PF_A8R8G8B8;
		}
		{
			CompositionTargetPass *tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_PREVIOUS);
			tp->setOutputName("rt1");
		}
		{
			CompositionTargetPass *tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setOutputName("rt0");
			CompositionPass *pass = tp->createPass();
			pass->setType(CompositionPass::PT_RENDERQUAD);
			pass->setMaterialName("Core/Compositor/Blur0");
			pass->setInput(0, "rt1");
		}
		{
			CompositionTargetPass *tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setOutputName("rt1");
			CompositionPass *pass = tp->createPass();
			pass->setType(CompositionPass::PT_RENDERQUAD);
			pass->setMaterialName("Core/Compositor/Blur1");
			pass->setInput(0, "rt0");
		}
		{
			CompositionTargetPass *tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_PREVIOUS);
			{ CompositionPass *pass = tp->createPass();
			pass->setType(CompositionPass::PT_RENDERQUAD);
			pass->setMaterialName("Core/Compositor/BloomBlend");
			pass->setInput(0, "rt1");
			}
		}
	}
}

CPostEffect_Bloom::~CPostEffect_Bloom()
{
}

void CPostEffect_Bloom::RegisterPostEffect()
{
	CompositorManager::getSingleton().addCompositor(m_Viewport, mCompName);
}
