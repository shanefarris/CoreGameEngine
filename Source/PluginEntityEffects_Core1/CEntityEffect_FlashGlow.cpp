#include "CEntityEffect_FlashGlow.h"
#include "CEntityEffect.h"
#include "CGameObject.h"
#include "CGameManager.h"

using namespace Core;
using namespace Core::Effects;
using namespace Core::Plugin;

// render queues
#define RENDER_QUEUE_OUTLINE_GLOW_OBJECTS	RENDER_QUEUE_MAIN + 1
#define RENDER_QUEUE_OUTLINE_GLOW_GLOWS		RENDER_QUEUE_MAIN + 2
#define RENDER_QUEUE_FULL_GLOW_ALPHA_GLOW	RENDER_QUEUE_MAIN + 3
#define RENDER_QUEUE_FULL_GLOW_GLOW			RENDER_QUEUE_MAIN + 4
#define LAST_STENCIL_OP_RENDER_QUEUE		RENDER_QUEUE_OUTLINE_GLOW_GLOWS
#define MAT_NAME "cg/glow"

CEntityEffect_FlashGlow::CEntityEffect_FlashGlow() : CEntityEffect()
{
}

CEntityEffect_FlashGlow::~CEntityEffect_FlashGlow()
{
	RemoveEffectFromGameObject();
}

void CEntityEffect_FlashGlow::AddEffectToGameObject(CGameObject* GameObject)
{
	Entity* entity = GameObject->Entity->clone(GameObject->Entity->getName() + "_glow"); 
	entity->setRenderQueueGroup(RENDER_QUEUE_FULL_GLOW_ALPHA_GLOW); 
	entity->setMaterialName(MAT_NAME); 
	
	SceneNode* node = GameObject->Entity->getParentSceneNode()->createChildSceneNode(entity->getName() + "_Node"); 
	node->attachObject(entity); 

	m_GameObject = new CDummyGameObject();
	m_GameObject->Entity = entity;
	m_GameObject->Node = node;
}

void CEntityEffect_FlashGlow::RemoveEffectFromGameObject()
{
	if(m_GameObject)
	{
		m_GameObject->Node->detachAllObjects();
		CGameManager::Instance()->GetSceneManager()->destroySceneNode(m_GameObject->Node);
		CGameManager::Instance()->GetSceneManager()->destroyEntity(m_GameObject->Entity);
	}
}