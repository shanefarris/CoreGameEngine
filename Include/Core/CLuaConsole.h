#ifndef __CLUACONSOLE_H__
#define __CLUACONSOLE_H__

#include "Defines.h"
#include "OgreFrameListener.h"
#include "ToLua/lua.hpp"

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
	class CLuaInterpreter;

	class CORE_EXPORT CLuaConsole: public Ogre::FrameListener
	{
	public:
		static CLuaConsole* Instance();
		virtual ~CLuaConsole();

		void    SetVisible(bool Visible);
		bool    IsVisible() { return isVisible; }
		void    Print(const String& Text);
		bool    OnKeyPressed(const CInputKeyEvent &evt);

		// Frame listener
		bool frameStarted(const Ogre::FrameEvent &evt);
		bool frameEnded(const Ogre::FrameEvent &evt);

	protected:
		CLuaConsole();

		void Init();
		void Shutdown();
		void UpdateConsole();
		void UpdatePrompt();

		lua_State*			 mL;
		static CLuaConsole*  LuaConsole;

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

		Vector<String>			 m_Lines;
		Vector<String>			 m_LineQueue;			// Used when there are more lines to output then there are lines to show
		std::list<String>		 m_History;				// Commands entered
		std::list<String>::iterator m_HistoryLine;

		void  AddToHistory(const String& cmd);

		class CEditString
		{
		public:
			CEditString(void) : mInsert(true), mPosition(mText.begin()), mCaret(0) { }
			~CEditString(void) { }

			CEditString(const String& newText) { setText(newText); }

		protected:
			String mText;				// The text for editing
			String::iterator mPosition;	// Position for insert / overwrite
			int mCaret;					// Caret Position - for positioning the cursor.
			bool mInsert;				// Overwrite or insert

		public:
			void setText(const String& newText);
			void clear();

			inline String& getText() { return mText; }
			inline bool inserting() { return mInsert; }
			inline bool injectKeyPress( const CInputKeyEvent& KeyEvent );
			inline int getPosition(void) { return mCaret; }
		};

		class CLuaInterpreter
		{
		public:
			enum State
			{
				LI_READY = 0,
				LI_NEED_MORE_INPUT,
				LI_ERROR
			};

			CLuaInterpreter(lua_State *L);
			virtual ~CLuaInterpreter();

			// Retrieves the current output from the interpreter.
			String getOutput();
			void clearOutput() { mOutput.clear(); }

			String getPrompt() { return mPrompt; }

			// Insert (another) line of text into the interpreter.
			// If fInsertInOutput is true, the line will also go into the
			// output.
			State insertLine(String& line, bool fInsertInOutput = false);

			// Callback for lua to provide output.
			static int insertOutputFromLua( lua_State *L );

			// Retrieve the current state of affairs.
			State getState() { return mState; }

		protected:
			lua_State *mL;
			std::string mCurrentStatement;
			std::string mOutput;
			std::string mPrompt;
			State mState;
			bool mFirstLine;
		};

		CLuaInterpreter*	interpreter;
		CEditString*		editline;
	};
}

#endif // __CLUACONSOLE_H__
