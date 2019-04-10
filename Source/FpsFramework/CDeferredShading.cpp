#if 0
#include "CDeferredShading.h"
#include "CMiniLight.h"
#include "CRayLight.h"
#include "CLightMaterialGenerator.h"
#include "CGameManager.h"

using namespace Core;
using namespace Core::Effects;

CDeferredShading::CDeferredShading(): CPostEffect("DEFERRED_SHADING"), m_LightMaterialGenerator(0)
{
	mSceneMgr = CGameManager::Instance()->GetSceneManager();

	for(int i=0; i<DSM_COUNT; ++i)
		mInstance[i]=0;

	m_CurrentMode = DSM_MULTIPASS;

	rttTex = 0;

	// Postfilter for rendering to fat render target. Excludes skies, backgrounds and other unwanted objects.
	CompositorPtr comp7 = CompositorManager::getSingleton().create("DeferredShading/Fat", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME);
	{
		CompositionTechnique *t = comp7->createTechnique();
		{
			CompositionTargetPass *tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setVisibilityMask(CDeferredShading::SceneVisibilityMask);
			/// Clear
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_CLEAR);
				pass->setClearColour(ColourValue(0,0,0,0));
			}
			/// Render geometry
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERSCENE);
				pass->setFirstRenderQueue(RENDER_QUEUE_1);
				pass->setLastRenderQueue(RENDER_QUEUE_9);
				//pass->setIdentifier(21);
			}

			//{	CompositionPass *pass = tp->createPass();
			//	pass->setType(CompositionPass::PT_RENDERSCENE);
			//	pass->setFirstRenderQueue(92);
			//	pass->setLastRenderQueue(94);
			//	pass->setIdentifier(22);
			//}
		}
	}

	CompositorPtr comp6 = CompositorManager::getSingleton().create(
				"DeferredShading/Alpha", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME
			);
	{
		CompositionTechnique *t = comp6->createTechnique();
		{
			CompositionTargetPass *tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setVisibilityMask(CDeferredShading::AlphaVisibilityMask);
			/// Render geometry
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERSCENE);
				pass->setFirstRenderQueue(RENDER_QUEUE_1);
				pass->setLastRenderQueue(RENDER_QUEUE_9);
				//pass->setIdentifier(21);
			}

			//{	CompositionPass *pass = tp->createPass();
			//	pass->setType(CompositionPass::PT_RENDERSCENE);
			//	pass->setFirstRenderQueue(92);
			//	pass->setLastRenderQueue(94);
			//	pass->setIdentifier(22);
			//}
		}
	}

	/** Postfilter doing full deferred shading with two lights in one pass
	*/
	CompositorPtr comp = CompositorManager::getSingleton().create(
				"DeferredShading/Single", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME
			);
	{
		CompositionTechnique *t = comp->createTechnique();
		{
			CompositionTargetPass *tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setVisibilityMask(CDeferredShading::PostVisibilityMask);
			/// Render skies
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERSCENE);
				pass->setFirstRenderQueue(RENDER_QUEUE_SKIES_EARLY);
				pass->setLastRenderQueue(RENDER_QUEUE_SKIES_EARLY);
			}
			/// Render ambient pass
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("DeferredShading/Post/Single");
				pass->setIdentifier(1);
			}
			/// Render overlayed geometry
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERSCENE);
				pass->setFirstRenderQueue(RENDER_QUEUE_1);
				pass->setLastRenderQueue(RENDER_QUEUE_9);
			}
		}
	}
	/** Postfilter doing full deferred shading with an ambient pass and multiple light passes
	*/
	CompositorPtr comp2 = CompositorManager::getSingleton().create(
				"DeferredShading/Multi", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME
			);
	{
		CompositionTechnique *t = comp2->createTechnique();
		{
			CompositionTechnique::TextureDefinition* texDef = t->createTextureDefinition( "rt0" );
			texDef->formatList.push_back(PF_A8R8G8B8);
			CompositionTargetPass *tp = t->createTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			tp->setOutputName( "rt0" );
			tp->setVisibilityMask(CDeferredShading::PostVisibilityMask);

			{
				CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_CLEAR);
			}

			/// Render skies
			//{	CompositionPass *pass = tp->createPass();
			//	pass->setType(CompositionPass::PT_RENDERSCENE);
			//	pass->setFirstRenderQueue(RENDER_QUEUE_SKIES_EARLY);
			//	pass->setLastRenderQueue(RENDER_QUEUE_SKIES_EARLY);
			//}
			/// Render ambient pass
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("DeferredShading/Post/Multi");
				pass->setIdentifier(1);
			}
			/// Render overlayed geometry
			{
				CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERSCENE);
				pass->setFirstRenderQueue(RENDER_QUEUE_1);
				pass->setLastRenderQueue(RENDER_QUEUE_9);
				pass->setIdentifier(12);
			}

			{
				CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("DeferredShading/Post/Alpha");
				pass->setIdentifier(56);
			}

			CompositionTargetPass *fp = t->getOutputTargetPass();
			fp->setInputMode(CompositionTargetPass::IM_NONE);

			{
				CompositionPass *pass = fp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("DeferredShading/Post/Distortion");
				pass->setInput(0, "rt0");
				pass->setIdentifier(57);
			}
		}
	}	
	/** Postfilter that shows the normal channel
	*/
	CompositorPtr comp3 = CompositorManager::getSingleton().create(
				"DeferredShading/ShowNormal", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME
			);
	{
		CompositionTechnique *t = comp3->createTechnique();
		{
			CompositionTargetPass *tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("DeferredShading/Post/ShowNormal");
				pass->setIdentifier(1);
			}
		}
	}	
	/** Postfilter that shows the depth and specular channel
	*/
	CompositorPtr comp4 = CompositorManager::getSingleton().create(
				"DeferredShading/ShowDepthSpecular", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME
			);
	{
		CompositionTechnique *t = comp4->createTechnique();
		{
			CompositionTargetPass *tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("DeferredShading/Post/ShowDS");
				pass->setIdentifier(1);
			}
		}
	}	
	/** Postfilter that shows the depth and specular channel
	*/
	CompositorPtr comp5 = CompositorManager::getSingleton().create(
				"DeferredShading/ShowColour", ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME
			);
	{
		CompositionTechnique *t = comp5->createTechnique();
		{
			CompositionTargetPass *tp = t->getOutputTargetPass();
			tp->setInputMode(CompositionTargetPass::IM_NONE);
			{	CompositionPass *pass = tp->createPass();
				pass->setType(CompositionPass::PT_RENDERQUAD);
				pass->setMaterialName("DeferredShading/Post/ShowColour");
				pass->setIdentifier(78);
			}
		}
	}

	// Hide post geometry
	mSceneMgr->setVisibilityMask(mSceneMgr->getVisibilityMask() & ~PostVisibilityMask);
	mSceneMgr->setVisibilityMask(mSceneMgr->getVisibilityMask() & ~AlphaVisibilityMask);
	mSceneMgr->setVisibilityMask(mSceneMgr->getVisibilityMask() & ~EffectVisibilityMask);
}

CDeferredShading::~CDeferredShading()
{
	// Delete mini lights
	for(std::set<CMiniLight*>::iterator i=m_Lights.begin(); i!=m_Lights.end(); ++i)
	{
		CORE_DELETE((*i));
	}

	CompositorChain *chain = CompositorManager::getSingleton().getCompositorChain(m_Viewport);
	for(int i=0; i<DSM_COUNT; ++i)
		chain->_removeInstance(mInstance[i]);

	CORE_DELETE(m_LightMaterialGenerator);
}

void CDeferredShading::SetMode(DSMode mode)
{
	for(int i=0; i<DSM_COUNT; ++i)
	{
		if(i == mode)
			mInstance[i]->setEnabled(mEnabled);
		else
			mInstance[i]->setEnabled(false);
	}
	m_CurrentMode = mode;
}

void CDeferredShading::RegisterPostEffect(void)
{
	CompositorManager &compMan = CompositorManager::getSingleton();
	// Create 'fat' render target
	unsigned int width = m_Viewport->getActualWidth();
	unsigned int height = m_Viewport->getActualHeight();
	PixelFormat format = PF_FLOAT16_RGBA;
	//PixelFormat format = PF_FLOAT32_RGBA;

	m_Texture0 = TextureManager::getSingleton().createManual("RttTex0", 
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, 
		width, height, 0, format, TU_RENDERTARGET );
	m_Texture1 = TextureManager::getSingleton().createManual("RttTex1", 
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, 
		width, height, 0, format, TU_RENDERTARGET );
	m_Texture2 = TextureManager::getSingleton().createManual("RttTex2", 
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, 
		width, height, 0, format, TU_RENDERTARGET );
	m_Texture3 = TextureManager::getSingleton().createManual("RttTex3", 
		ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, TEX_TYPE_2D, 
		width, height, 0, format, TU_RENDERTARGET );
	//assert(m_Texture0->getFormat() == format);
	//assert(m_Texture1->getFormat() == format);
	rttTex = Root::getSingleton().getRenderSystem()->createMultiRenderTarget("MRT");
	rttTex->bindSurface(0, m_Texture0->getBuffer()->getRenderTarget());
	rttTex->bindSurface(1, m_Texture1->getBuffer()->getRenderTarget());
	rttTex->bindSurface(2, m_Texture2->getBuffer()->getRenderTarget());
	rttTex->bindSurface(3, m_Texture3->getBuffer()->getRenderTarget());
	rttTex->setAutoUpdated( true );

	// Setup viewport on 'fat' render target
	Viewport* v = rttTex->addViewport( m_Camera );
	v->setClearEveryFrame( true );
	v->setOverlaysEnabled( false );
	v->setSkiesEnabled(false);
	v->setBackgroundColour( ColourValue( 0.1, 0.1, 0.1, 1.0) );

	compMan.addCompositor(v, "DeferredShading/Fat");
	compMan.addCompositor(v, "DeferredShading/Alpha");

	// Create lights material generator
	SetupMaterial(MaterialManager::getSingleton().getByName("DeferredShading/LightMaterialQuad"));
	SetupMaterial(MaterialManager::getSingleton().getByName("DeferredShading/LightMaterial"));
	SetupMaterial(MaterialManager::getSingleton().getByName("DeferredShading/CRayLight/Quad"));
	SetupMaterial(MaterialManager::getSingleton().getByName("DeferredShading/CRayLight/Mini"));
	m_LightMaterialGenerator = new CLightMaterialGenerator("hlsl");

	//if( MaterialManager::getSingleton().resourceExists("DeferredShading/Post/Alpha") )
	//{
	//	const MaterialPtr& jaha = MaterialManager::getSingleton().getByName("DeferredShading/Post/Alpha");
	//	for(unsigned short i=0; i<jaha->getNumTechniques(); ++i)
	//	{
	//		Pass *pass = jaha->getTechnique(i)->getPass(0);
	//		pass->getTextureUnitState(0)->setTextureName(m_Texture2->getName());
	//	}
	//}

	// Create filters
	mInstance[DSM_SINGLEPASS] = compMan.addCompositor(m_Viewport, "DeferredShading/Single");
	mInstance[DSM_MULTIPASS] = compMan.addCompositor(m_Viewport, "DeferredShading/Multi");
	mInstance[DSM_SHOWNORMALS] = compMan.addCompositor(m_Viewport, "DeferredShading/ShowNormal");
	mInstance[DSM_SHOWDSP] = compMan.addCompositor(m_Viewport, "DeferredShading/ShowDepthSpecular");
	mInstance[DSM_SHOWCOLOUR] = compMan.addCompositor(m_Viewport, "DeferredShading/ShowColour");

	// Add material setup callback
	for(int i=0; i<DSM_COUNT; ++i)
		mInstance[i]->addListener(this);

	// Default to normal deferred shading mode
	SetMode(m_CurrentMode);
}
void CDeferredShading::SetupMaterial(const MaterialPtr &mat)
{
	for(unsigned short i=0; i<mat->getNumTechniques(); ++i)
	{
		Pass *pass = mat->getTechnique(i)->getPass(0);
		pass->getTextureUnitState(0)->setTextureName(m_Texture0->getName());
		pass->getTextureUnitState(1)->setTextureName(m_Texture1->getName());
	}
}

CMiniLight *CDeferredShading::CreateMLight()
{
	CMiniLight *rv = new CMiniLight(m_LightMaterialGenerator);
	rv->setVisibilityFlags(PostVisibilityMask);
	m_Lights.insert(rv);

	return rv;
}


CRayLight *CDeferredShading::CreateRayLight()
{
	CRayLight *rv = new CRayLight(m_LightMaterialGenerator);
	rv->setVisibilityFlags(PostVisibilityMask);
	m_Lights.insert(rv);

	return rv;
}

void CDeferredShading::DestroydeferredLight(CMiniLight *m)
{
	m_Lights.erase(m);
	CORE_DELETE(m);
}

void CDeferredShading::Update(const Vector3& camPos)
{
	for(std::set<CMiniLight*>::iterator i=m_Lights.begin(); i!=m_Lights.end(); ++i)
	{
		(*i)->updateGeometry(camPos);
	}
}

void CDeferredShading::notifyMaterialSetup(u32 pass_id, MaterialPtr &mat)
{
	/// Local pass identifier 1 is the render quad pass
	if(pass_id == 1)
	{
		SetupMaterial(mat);
		rttTex->unbindSurface(1);
		rttTex->unbindSurface(2);
		rttTex->unbindSurface(3);
	}
	else if(pass_id == 78) 
	{
		for(unsigned short i=0; i<mat->getNumTechniques(); ++i)
		{
			Pass *pass = mat->getTechnique(i)->getPass(0);
			pass->getTextureUnitState(0)->setTextureName(m_Texture0->getName());
			pass->getTextureUnitState(1)->setTextureName(m_Texture2->getName());
		}
	}
	else if(pass_id == 56) 
	{
		for(unsigned short i=0; i<mat->getNumTechniques(); ++i)
		{
			Pass *pass = mat->getTechnique(i)->getPass(0);
			pass->getTextureUnitState(0)->setTextureName(m_Texture2->getName());
		}
	}
	else if(pass_id == 57) 
	{
		for(unsigned short i=0; i<mat->getNumTechniques(); ++i)
		{
			Pass *pass = mat->getTechnique(i)->getPass(0);
			pass->getTextureUnitState(1)->setTextureName(m_Texture3->getName());
		}
		
		rttTex->bindSurface(1, m_Texture1->getBuffer()->getRenderTarget());
		rttTex->bindSurface(2, m_Texture2->getBuffer()->getRenderTarget());
		rttTex->bindSurface(3, m_Texture3->getBuffer()->getRenderTarget());
	}
	//else if(pass_id == 21)
	//{
	//	rttTex->bindSurface(0, m_Texture0->getBuffer()->getRenderTarget());
	//	rttTex->bindSurface(1, m_Texture1->getBuffer()->getRenderTarget());
	//}
	//else if(pass_id == 22)
	//{
	//	rttTex->unbindSurface(1);
	//	rttTex->bindSurface(0, m_Texture2->getBuffer()->getRenderTarget());
	//}
}

#endif