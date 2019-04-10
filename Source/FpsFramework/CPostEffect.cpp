#include "CPostEffect.h"
#include "CCameraManager.h"
#include "IO/CoreLogging.h"

#include "OgreCompositorManager.h"

using namespace Core::Effects;

CPostEffect::CPostEffect(const String& compName) : mCompName(compName), mEnabled(false)
{
	m_Viewport = CCameraManager::Instance()->GetViewport();
	m_Camera = CCameraManager::Instance()->GetCamera();
}

void CPostEffect::SetEnabled(bool flag)
{
	CompositorManager::getSingleton().setCompositorEnabled(m_Viewport, mCompName, flag);
	mEnabled = flag;
	String msg;
	if (mEnabled)
		msg = "[CPostEffect] Enabling " + mCompName;
	else
		msg = "[CPostEffect] Disabling " + mCompName;

	CORE_LOG(msg.c_str());
}
