#if 0
#include "CLoadingScreen.h"

#include <OgreOverlayElement.h>
#include <OgreOverlay.h>
#include <OgreOverlayManager.h>
#include <OgreRenderWindow.h>

using namespace Core;
using namespace Core::OgreSpecific;

void CLoadingScreen::Start(RenderWindow* window, u32 numGroupsInit, u32 numGroupsLoad, f32 initProportion)
{
	m_Window = window;
	m_NumGroupsInit = numGroupsInit;
	m_NumGroupsLoad = numGroupsLoad;
	m_InitProportion = initProportion;

	// We need to pre-initialise the 'Bootstrap' group so we can use
	// the basic contents in the loading screen
	//ResourceGroupManager::getSingleton().initialiseResourceGroup("Core");

	OverlayManager& omgr = OverlayManager::getSingleton();
	m_LoadOverlay = (Overlay*)omgr.getByName("Core/LoadOverlay");
	if (!m_LoadOverlay)
	{
		OGRE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND,
			"Cannot find loading overlay", "LoadingBar::Start");
	}
	m_LoadOverlay->show();

	// Save links to the bar and to the loading text, for updates as we go
	m_LoadingBarElement = omgr.getOverlayElement("Core/LoadPanel/Bar/Progress");
	m_LoadingCommentElement = omgr.getOverlayElement("Core/LoadPanel/Comment");
	m_LoadingDescriptionElement = omgr.getOverlayElement("Core/LoadPanel/Description");

	OverlayElement* barContainer = omgr.getOverlayElement("Core/LoadPanel/Bar");
	m_ProgressBarMaxSize = barContainer->getWidth();
	m_LoadingBarElement->setWidth(0);

	// self is listener
	ResourceGroupManager::getSingleton().addResourceGroupListener(this);
}

void CLoadingScreen::Finish()
{
	// hide loading screen
	m_LoadOverlay->hide();

	// Unregister listener
	ResourceGroupManager::getSingleton().removeResourceGroupListener(this);
}

void CLoadingScreen::resourceGroupScriptingStarted(const String& groupName, size_t scriptCount)
{
	assert(m_NumGroupsInit > 0 && "You stated you were not going to init "
		"any groups, but you did! Divide by zero would follow...");

	// Lets assume script loading is 70%
	m_ProgressBarInc = m_ProgressBarMaxSize * m_InitProportion / (f32)scriptCount;
	m_ProgressBarInc /= m_NumGroupsInit;
	m_LoadingDescriptionElement->setCaption("Parsing scripts...");
	m_Window->update();
}

void CLoadingScreen::scriptParseStarted(const String& scriptName, bool& skipThisScript)
{
	m_LoadingCommentElement->setCaption(scriptName);
	m_Window->update();
}

void CLoadingScreen::scriptParseEnded(const String& scriptName, bool skipped)
{
	m_LoadingBarElement->setWidth(
		m_LoadingBarElement->getWidth() + m_ProgressBarInc);
	m_Window->update();
}

void CLoadingScreen::resourceGroupScriptingEnded(const String& groupName)
{
}

void CLoadingScreen::resourceGroupLoadStarted(const String& groupName, size_t resourceCount)
{
	assert(m_NumGroupsLoad > 0 && "You stated you were not going to load "
		"any groups, but you did! Divide by zero would follow...");
	m_ProgressBarInc = m_ProgressBarMaxSize * (1-m_InitProportion) /
		(f32)resourceCount;
	m_ProgressBarInc /= m_NumGroupsLoad;
	m_LoadingDescriptionElement->setCaption("Loading resources...");
	m_Window->update();
}

void CLoadingScreen::resourceLoadStarted(const ResourcePtr& resource)
{
	m_LoadingCommentElement->setCaption(resource->getName());
	m_Window->update();
}

void CLoadingScreen::resourceLoadEnded()
{
}

void CLoadingScreen::worldGeometryStageStarted(const String& description)
{
	m_LoadingCommentElement->setCaption(description);
	m_Window->update();
}

void CLoadingScreen::worldGeometryStageEnded()
{
	m_LoadingBarElement->setWidth(
		m_LoadingBarElement->getWidth() + m_ProgressBarInc);
	m_Window->update();
}

void CLoadingScreen::resourceGroupLoadEnded(const String& groupName)
{
}

DataStreamPtr CLoadingScreen::ResourceLoading(const String &name, const String &group, Resource* resource)
{
	return DataStreamPtr();
}

bool CLoadingScreen::ResourceCollision(ResourcePtr &resource, ResourceManager *resourceManager)
{
	return false;
}

#endif