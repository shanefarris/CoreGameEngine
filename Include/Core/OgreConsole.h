#ifndef __OGRECONCOLE_H__
#define __OGRECONCOLE_H__

#include "Defines.h"
#include "OgreFrameListener.h"

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
	class CInputKeyEvent;
	class CGameObjectManager;
	class CConsoleParser;

	namespace Plugin
	{
		class IConsoleParser;
	}

	class CORE_EXPORT OgreConsole : public Ogre::FrameListener
	{

	public:
		static OgreConsole* Instance();
		virtual ~OgreConsole();

		void SetVisible(bool Visible);
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

		void OnKeyPressed(const CInputKeyEvent &arg);

		// Frame listener
		bool frameStarted(const Ogre::FrameEvent &evt);
		bool frameEnded(const Ogre::FrameEvent &evt);

	private:
		enum OUTPUT { STD, FILE };					// Where is the command output going to go

		OgreConsole();

		void Init();
		void Shutdown();
		void CheckCommands();
		void ParseLine(String& Line);				// Calls the command parsers loaded
		void Print(const String& Text, OUTPUT Out = STD);
		OUTPUT GetOutput(String& Command);			// Supports two types of output, console and file
		void UpdateConsole();
		void UpdatePrompt();

		// Plugin
		Vector<Core::Plugin::IConsoleParser*>	m_Parsers;

		static OgreConsole*  Console;
		CGameObjectManager*	 m_GameObjectManager;

		bool                 isVisible;
		bool                 isInitialised;
		bool				 isShowFpsInfo;
		bool				 isShowPos;
		bool				 isInsertmode;
		bool                 m_UpdateConsole;
		bool                 m_UpdatePrompt;
		u32					 m_HistoryPos;
		u32					 m_CursorPosition;
		u32					 m_Startline;
		Gorilla::Screen*     m_Screen;
		Gorilla::Layer*      m_Layer;
		Gorilla::Caption*    m_PromptText;
		Gorilla::MarkupText* m_ConsoleText;
		Gorilla::Rectangle*  m_Decoration;
		Gorilla::GlyphData*  m_GlyphData;

		String				 m_OutFile;				// File name where the output will go

		Vector<String>		 m_Lines;
		Vector<String>		 m_LineQueue;			// Used when there are more lines to output then there are lines to show
		Vector<String>		 m_History;				// Commands entered
	};
}

#endif  // __OGRECONCOLE_H__