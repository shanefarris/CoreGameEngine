#ifndef __OGRECONCOLE_H__
#define __OGRECONCOLE_H__

#include "Core\Defines.h"
#include "OgreFrameListener.h"

namespace OIS
{
	class KeyEvent;
}

namespace Ogre
{
	class Overlay;
	class OverlayElement;
	class Rectangle2D;
	class StringVector;
}

namespace Gorilla
{
	class Screen;
	class Layer;
	class Caption;
	class MarkupText;
	class Rectangle;
	class GlyphData;
}

namespace Core
{
	class CGameObjectManager;
	class CConsoleParser;

	namespace Plugin
	{
		class IConsoleParser;
	}
}

class OgreConsole : public Ogre::FrameListener
{

public:
	static OgreConsole* Instance();
	~OgreConsole();

	void SetVisible(bool visible) { isVisible = visible; }
	bool GetVisible() { return isVisible; }

	// Commands
	bool GetShowFpsInfo() { return isShowFpsInfo; }
	void SetShowFpsInfo(bool Visible);
	bool GetShowPos() { return isShowPos; }
	void SetShowPos(bool Visible);
	void ClearConsole();

	// Save/Load
	void SaveCommands();
	void LoadCommands(bool Execute);
	void AddCommandToHistory(const char* Command);

	void OnKeyPressed(const OIS::KeyEvent &arg);

	// Frame listener
	bool    frameStarted(const Ogre::FrameEvent &evt);
	bool    frameEnded(const Ogre::FrameEvent &evt);

private:

	void  updateConsole();
	void  updatePrompt();

	// Plugin
	Vector<Core::Plugin::IConsoleParser*>	m_Parsers;

	static OgreConsole*  Console;
	CGameObjectManager*	 m_GameObjectManager;

	bool                 isVisible;
	bool                 isInitialised;
	bool				 isShowFpsInfo;
	bool				 isShowPos;
	Gorilla::Screen*     m_Screen;
	Gorilla::Layer*      m_Layer;
	Gorilla::Caption*    m_PromptText;
	Gorilla::MarkupText* m_ConsoleText;
	Gorilla::Rectangle*  m_Decoration;
	Gorilla::GlyphData*  m_GlyphData;

	bool                 m_UpdateConsole;
	bool                 m_UpdatePrompt;

	uint				 m_Startline;
	std::list<String>    m_Lines;
	String				 m_Prompt;

};

#endif  // __OGRECONCOLE_H__