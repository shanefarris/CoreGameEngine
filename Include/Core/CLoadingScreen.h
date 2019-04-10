#if 0
#ifndef __CLOADINGSCREEN_H__
#define __CLOADINGSCREEN_H__

#include "Defines.h"
#include <OgreResourceGroupManager.h>

namespace Core
{
namespace OgreSpecific
{
	class CORE_EXPORT CLoadingScreen : public ResourceGroupListener
	{
	public:
		CLoadingScreen() { }
		virtual ~CLoadingScreen() { }

		virtual void Start(RenderWindow* window, u32 numGroupsInit = 1, u32 numGroupsLoad = 1, f32 initProportion = 0.70f);
		virtual void Finish(void);

		// ResourceGroupListener callbacks
		void resourceGroupScriptingStarted(const String& groupName, size_t scriptCount);
		void scriptParseStarted(const String& scriptName, bool& skipThisScript);
		void scriptParseEnded(const String& scriptName, bool skipped);
		void resourceGroupScriptingEnded(const String& groupName);
		void resourceGroupLoadStarted(const String& groupName, size_t resourceCount);
		void resourceLoadStarted(const ResourcePtr& resource);
		void resourceLoadEnded();
		void worldGeometryStageStarted(const String& description);
		void worldGeometryStageEnded();
		void resourceGroupLoadEnded(const String& groupName);

		DataStreamPtr ResourceLoading(const String& name, const String& group, Resource *resource);
		bool ResourceCollision(ResourcePtr& resource, ResourceManager* resourceManager);

	protected:
		RenderWindow*		m_Window;
		Overlay*			m_LoadOverlay;
		f32	m_InitProportion;
		f32 m_ProgressBarMaxSize;
		//f32 m_ProgressBarScriptSize;
		f32 m_ProgressBarInc;
		u32 m_NumGroupsInit;
		u32 m_NumGroupsLoad;
		
		OverlayElement* m_LoadingBarElement;
		OverlayElement* m_LoadingDescriptionElement;
		OverlayElement* m_LoadingCommentElement;
	};
}
}

#endif // __CLOADINGSCREEN_H__

#endif