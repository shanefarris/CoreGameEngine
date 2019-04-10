#include "CPostEffect_SSAO.h"
#include "CEffectsManager.h"

#include "OgreCompositorManager.h"
#include "OgreCompositionTechnique.h"
#include "OgreResourceGroupManager.h"
#include "OgreCompositionPass.h"
#include "OgreCompositionTargetPass.h"
#include "OgreCamera.h"
#include "OgrePass.h"
#include "OgreTechnique.h"

using namespace Core::Effects;
using namespace Core::Plugin;

CPostEffect_SSAO::CPostEffect_SSAO() : CPostEffect("SSAO")
{
	CompositorPtr comp = CompositorManager::getSingleton().create(mCompName, ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	{
		CompositionTechnique* t = comp->createTechnique();
		{
			CompositionTechnique::TextureDefinition* def = t->createTextureDefinition("scene");
			def->width = 0;
			def->height = 0;
			def->formatList.push_back(PF_R8G8B8);
		}
		{
			CompositionTechnique::TextureDefinition* def = t->createTextureDefinition("sum");
			def->width = 0;
			def->height = 0;
			def->formatList.push_back(PF_R8G8B8);
		}
		{
			CompositionTechnique::TextureDefinition* def = t->createTextureDefinition("temp");
			def->width = 0;
			def->height = 0;
			def->formatList.push_back(PF_R8G8B8);
		}
		/// Render scene
		{
			CompositionTargetPass* tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_PREVIOUS);
			tp->setOutputName("scene");
		}
		/// Initialisation pass for sum texture
		{
			CompositionTargetPass* tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_PREVIOUS);
			tp->setOutputName("sum");
			tp->setOnlyInitial(true);
		}
		/// Do the motion blur
		{
			CompositionTargetPass* tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setOutputName("temp");
			{
				CompositionPass* pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("Ainur/Compositor/Combine");
				pass->setInput(0, "scene");
				pass->setInput(1, "sum");
			}
		}
		/// Copy back sum texture
		{
			CompositionTargetPass* tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setOutputName("sum");
			{
				CompositionPass* pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("Ainur/Compositor/Copyback");
				pass->setInput(0, "temp");
			}
		}
		/// Display result
		{
			CompositionTargetPass* tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			{
				CompositionPass* pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("Ainur/Compositor/MotionBlur");
				pass->setInput(0, "sum");
			}
		}
	}
}

void CPostEffect_SSAO::RegisterPostEffect()
{
	CompositorManager::getSingleton().addCompositor(m_Viewport, mCompName);
}

void CPostEffect_SSAO::notifyMaterialRender(u32 pass_id, MaterialPtr& mat)
{
	// Just return if it's not CSsao
	if (pass_id != 42)
		return;

	// Calculate the far-top-right corner in view-space
	Vector3 farCorner = m_Camera->getViewMatrix(true) * 
		m_Camera->getWorldSpaceCorners()[4];

	// Take the first pass
	Pass* pass = mat->getBestTechnique()->getPass(0);

	// Get the vertex shader parameters
	GpuProgramParametersSharedPtr params = pass->getVertexProgramParameters();

	// Set the camera's far-top-right corner
	if (params->_findNamedConstantDefinition("farCorner"))
		params->setNamedConstant("farCorner", farCorner);

	// Get the fragment shader parameters
	params = pass->getFragmentProgramParameters();

	// Set the projection matrix we need
	static const Matrix4 CLIP_SPACE_TO_IMAGE_SPACE(
		0.5, 0, 0, 0.5,
		0, -0.5, 0, 0.5,
		0, 0, 1, 0,
		0, 0, 0, 1
	);
	if (params->_findNamedConstantDefinition("ptMat"))
		params->setNamedConstant("ptMat", CLIP_SPACE_TO_IMAGE_SPACE * m_Camera->getProjectionMatrixWithRSDepth());
	if (params->_findNamedConstantDefinition("far"))
		params->setNamedConstant("far", m_Camera->getFarClipDistance());
}
