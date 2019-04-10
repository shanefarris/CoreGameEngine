#include "CLuaConsole.h"
#include "CGameManager.h"
#include "CCameraManager.h"
#include "CGuiManager.h"
#include "CInputEvent.h"

#include "OgreRoot.h"

#include "Gui3D/Gorilla.h"

#define CONSOLE_LINE_LENGTH 85
#define CONSOLE_LINE_COUNT 15
#define CONSOLE_MAX_LINES 32000
#define CONSOLE_MAX_HISTORY 64
#define CONSOLE_TAB_STOP 8
#define LI_PROMPT  ">"
#define LI_PROMPT2 ">>"
#define CONSOLE_FONT_INDEX 9
#define CONSOLE_LINE_LENGTH 85
#define CONSOLE_LINE_COUNT 20
static const unsigned char legalchars[]="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890+!\"'#%&/()=?[]\\*-_.:,; ";

using namespace Core;

static const char LuaRegistryGUID = 0;
CLuaConsole* CLuaConsole::LuaConsole = nullptr;

CLuaConsole* CLuaConsole::Instance()
{
	if(!LuaConsole)
		LuaConsole = new CLuaConsole();
	return LuaConsole;
}

CLuaConsole::CLuaConsole()
	: isVisible(false), 
	isInitialised(false), 
	isInsertmode(false),
	m_Screen(nullptr), 
	m_UpdateConsole(false), 
	m_UpdatePrompt(false), 
	m_Startline(0), 
	m_CursorPosition(0),
	m_HistoryPos(0)
{
	Init();

	m_History.push_back("");
	isShowFpsInfo = false;
	isShowPos = false;
}

CLuaConsole::~CLuaConsole()
{
	if (isInitialised)
		Shutdown();
}

void CLuaConsole::Shutdown()
{
	try
	{
		CORE_DELETE(interpreter);
		CORE_DELETE(editline);

		lua_close(mL);

		isInitialised = false;
		Ogre::Root::getSingletonPtr()->removeFrameListener(this);
		m_Screen->destroy(m_Layer);
	}
	catch(std::exception& e)
	{
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CLuaConsole()");
	}
}

void CLuaConsole::Init()
{
	if(isInitialised)
		Shutdown();

	// 'myprint' function
	String myPrint = "function myprint(...)\n local str;str = ''; for i = 1, arg.n do \n if str ~= '' then str = str .. '\\t' end \n" \
		"str = str .. tostring( arg[i] ); end; str = str .. '\\n'; interpreterOutput( str ); end; print = myprint";

	// Initialize Lua
	mL = lua_open();
	luaL_openlibs(mL);
	if(luaL_dostring(mL, myPrint.c_str()) != 0)
	{
		CORE_THROW("Unable to execute 'myprint' function.", "CLuaConsole::Init");
	}

	interpreter = new CLuaInterpreter(mL);
	Print(interpreter->getOutput());
	interpreter->clearOutput();

	CGameManager::Instance()->GetEngineDevice()->addFrameListener(this);

	// Initialize editline
	editline = new CEditString();

	// Create gorilla things here.
	auto gorilla = GUI::CGuiManager::Instance()->GetSilverback();
	GUI::CGuiManager::Instance()->LoadAtlas(GUI::E_GORILLA_ATLAS::EGA_DEFAULT);
	m_Screen = gorilla->createScreen(CCameraManager::Instance()->GetViewport(), "dejavu");
	m_Layer = m_Screen->createLayer(15);
	m_GlyphData = m_Layer->_getGlyphData(CONSOLE_FONT_INDEX); // Font.CONSOLE_FONT_INDEX

	m_ConsoleText = m_Layer->createMarkupText(CONSOLE_FONT_INDEX,  5, 5, StringUtil::BLANK);
	m_ConsoleText->width(m_Screen->getWidth() - 5);
	m_PromptText = m_Layer->createCaption(CONSOLE_FONT_INDEX,  5, 5, "> _");
	m_Decoration = m_Layer->createRectangle(3, 3, m_Screen->getWidth(), m_GlyphData->mLineHeight);
	m_Decoration->background_colour(ColourValue(0.2f, 0.2f, 0.2f));
	m_Decoration->border(1, ColourValue::Black);
	m_Layer->setVisible(isVisible);

	isInitialised = true;
}

void CLuaConsole::SetVisible(bool Visible)
{
	isVisible = Visible;
	m_Layer->setVisible(isVisible);
}

bool CLuaConsole::frameStarted(const Ogre::FrameEvent &evt)
{
	if(m_UpdateConsole)
		UpdateConsole();

	if (m_UpdatePrompt)
		UpdatePrompt();

	return true;
}

bool CLuaConsole::frameEnded(const Ogre::FrameEvent &evt)
{
	return true;
}

void CLuaConsole::Print(const String& Text)
{
	// Subdivide it into lines
	auto str = Text.c_str();
	auto len = Text.length();
	String line;
	for(u32 c = 0; c < len; c++)
	{
		if(str[c] == '\n' || line.length() >= CONSOLE_LINE_LENGTH)
		{
			m_Lines.push_back(line);
			line = "";
		}

		if(str[c] != '\n')
		{
			line += str[c];
		}
	}

	if(line.length())
		m_Lines.push_back(line);
	if(m_Lines.size() > CONSOLE_LINE_COUNT)
		m_Startline = m_Lines.size() - CONSOLE_LINE_COUNT;
	else
		m_Startline = 0;
	m_UpdateConsole = true;
}

void CLuaConsole::AddToHistory(const String& cmd)
{
	m_History.remove(cmd);
	m_History.push_back( cmd );
	if(m_History.size() > CONSOLE_MAX_HISTORY)
		m_History.pop_front();
	m_HistoryLine = m_History.end();
}

bool CLuaConsole::OnKeyPressed(const CInputKeyEvent &evt)
{
	if(!isVisible)
		return true;

	// Do we still have more in the line queue to print
	if(m_LineQueue.size() > 0)
	{
		Print(0);
		return true;
	}

	switch( evt.KeyCode )
	{
	case KC_RETURN:
		Print(interpreter->getPrompt() + editline->getText());
		interpreter->insertLine(editline->getText());
		AddToHistory(editline->getText());
		Print(interpreter->getOutput());
		interpreter->clearOutput();
		editline->clear();

		m_UpdateConsole = true;
		break;

	case KC_PGUP:
		if(m_HistoryPos > 0)
		{
			if(m_HistoryLine == m_History.begin())
				m_HistoryLine = m_History.end();
			m_HistoryLine--;
			editline->setText(*m_HistoryLine);
		}
		m_UpdateConsole = true;
		break;

	case KC_PGDOWN:
		if(!m_History.empty())
		{
			if(m_HistoryLine != m_History.end())
				m_HistoryLine++;
			if( m_HistoryLine == m_History.end() )
				m_HistoryLine = m_History.begin();
			editline->setText(*m_HistoryLine);
		}

		m_UpdateConsole = true;
		break;

	case KC_UP:
		m_Startline -= CONSOLE_LINE_COUNT;
		m_UpdateConsole = true;
		break;

	case KC_DOWN:
		m_Startline += CONSOLE_LINE_COUNT;
		m_UpdateConsole = true;
		break;

	default:
		m_UpdatePrompt = editline->injectKeyPress(evt);
		break;
	}

	m_UpdatePrompt = true;

	return true;
}

void CLuaConsole::UpdateConsole()
{
	m_UpdateConsole = false;

	//make sure is in range
	if(m_Startline> m_Lines.size())
		m_Startline = m_Lines.size();

	int lcount = 0;
	auto start = m_Lines.begin();
	for(u32 c = 0; c < m_Startline; c++)
	{
		start++;
	}

	auto end = start;
	for(u32 c = 0; c < CONSOLE_LINE_COUNT;c++)
	{
		if(end == m_Lines.end())
			break;
		end++;
	}

	std::stringstream text;
	for(auto i = start; i != end; i++)
	{
		lcount++;
		text << (*i) << "\n";
	}

	//if(m_CursorPosition > (int)entry.size())
	//	m_CursorPosition = (u32)entry.size();

	//String blank = "";
	//for(u32 i = 0; i < m_CursorPosition; i++)
	//	blank += " ";

	// Move prompt downwards.
	m_PromptText->top(10 + (lcount * m_GlyphData->mLineHeight));

	// Change background height so it covers the text and prompt
	m_Decoration->height(((lcount + 1) * m_GlyphData->mLineHeight) + 4);

	m_ConsoleText->width(m_Screen->getWidth() - 20);
	m_Decoration->width(m_Screen->getWidth() - 16);
	m_PromptText->width(m_Screen->getWidth() - 20);

}

void CLuaConsole::UpdatePrompt()
{
	m_UpdatePrompt = false;

	if(m_Startline < 0 )
		m_Startline = 0;
	if((u32)m_Startline > m_Lines.size())
		m_Startline = m_Lines.size();

	auto start = m_Lines.begin();

	for(u32 c = 0; c < m_Startline; c++)
		start++;

	auto end = start;
	for(int c = 0; c < CONSOLE_LINE_COUNT; c++)
	{
		if(end == m_Lines.end())
			break;
		end++;
	}

	int lcount = 0;
	std::stringstream text;
	for(auto i = start; i != m_Lines.end(); i++)
	{
		lcount++;
		text << (*i) + "\n";
	}

	//add the edit line with cursor
	String editLineText( editline->getText() + " " );
	editLineText[editline->getPosition()] = '_';

	text << interpreter->getPrompt() + editLineText;

	m_ConsoleText->text(text.str());

	// Move prompt downwards.
	m_PromptText->top(10 + (lcount * m_GlyphData->mLineHeight));

	// Change background height so it covers the text and prompt
	m_Decoration->height(((lcount + 1) * m_GlyphData->mLineHeight) + 4);

	m_ConsoleText->width(m_Screen->getWidth() - 20);
	m_Decoration->width(m_Screen->getWidth() - 16);
	m_PromptText->width(m_Screen->getWidth() - 20);
}

// CEditString
void CLuaConsole::CEditString::setText(const String & newText) 
{ 
	mText = newText;
	mPosition = mText.end();
	mCaret = (int)mText.length();
}

void CLuaConsole::CEditString::clear()
{
	mText.clear();
	mPosition = mText.end();
	mCaret = 0;
}

bool CLuaConsole::CEditString::injectKeyPress( const CInputKeyEvent& arg )
{
	bool keyUsed = true;

	if( isgraph( arg.Text ) || isspace( arg.Text ) )
	{
		if( mInsert || mPosition == mText.end() )
		{
			mPosition = mText.insert( mPosition, arg.Text );
		}
		else
		{
			*mPosition = arg.Text;
		}
		mPosition++;
		mCaret++;        
	}
	else
	{
		switch( arg.KeyCode )
		{
		case KC_BACK:
			if( mPosition != mText.begin() )
			{
				mPosition = mText.erase( --mPosition );
				--mCaret;
			}
			break;
		case KC_INSERT:
			mInsert = ! mInsert;
			break;
		case KC_HOME:
			mPosition = mText.begin();
			mCaret = 0;
			break;
		case KC_END:
			mPosition = mText.end();
			mCaret = (int)mText.length();
			break;
		case KC_LEFT:
			if( mPosition != mText.begin() )
			{
				mPosition--;
				mCaret--;
			}
			break;
		case KC_RIGHT:
			if( mPosition != mText.end() )
			{
				mPosition++;
				mCaret++;
			}
			break;
		case KC_DELETE:
			if( mPosition != mText.end() )
				mPosition = mText.erase( mPosition );
			break;
		default:
			keyUsed = false;
			break;
		}
	}

	return keyUsed;
}

// CLuaInterpreter
CLuaConsole::CLuaInterpreter::CLuaInterpreter(lua_State *L) : mL(L), mState(LI_READY), mFirstLine(true)
{
	mOutput.clear();
	mCurrentStatement.clear();
	lua_pushlightuserdata( mL, (void *)&LuaRegistryGUID );
	lua_pushlightuserdata( mL, this );
	lua_settable( mL, LUA_REGISTRYINDEX );

	lua_register( mL, "interpreterOutput", &CLuaInterpreter::insertOutputFromLua );

	mPrompt = LI_PROMPT;
}

CLuaConsole::CLuaInterpreter::~CLuaInterpreter()
{
	try
	{
		lua_register( mL, "interpreterOutput", nullptr );
		lua_pushlightuserdata( mL, (void *)&LuaRegistryGUID );
		lua_pushnil( mL );
		lua_settable( mL, LUA_REGISTRYINDEX );
	}
	catch(std::exception& e)
	{
		throw(e);
	}
	catch(...)
	{
		throw("Error in ~CLuaIterpreter()");
	}
}

// Retrieves the current output from the interpreter.
String CLuaConsole::CLuaInterpreter::getOutput()
{
	return mOutput;
}

// Insert (another) line of text into the interpreter.
CLuaConsole::CLuaInterpreter::State CLuaConsole::CLuaInterpreter::insertLine(String& line, bool fInsertInOutput )
{
	if( fInsertInOutput == true )
	{
		mOutput += line;
		mOutput += '\n';
	}

	if( mFirstLine && line.substr(0,1) == "=" )
	{
		line = "return " + line.substr(1, line.length()-1 );
	}

	mCurrentStatement += " ";
	mCurrentStatement += line;
	mFirstLine = false;

	mState = LI_READY;

	if( luaL_loadstring( mL, mCurrentStatement.c_str() ) )
	{
		String error( lua_tostring( mL, -1 ) );
		lua_pop( mL, 1 );

		// If the error is not a syntax error cuased by not enough of the
		// statement been yet entered...
		if( error.substr( error.length()-6, 5 ) != "<eof>" )
		{
			mOutput += error;
			mOutput += "\n";
			mOutput += LI_PROMPT;
			mCurrentStatement.clear();
			mState = LI_ERROR;
		}
		// Otherwise...
		else
		{
			// Secondary prompt
			mPrompt = LI_PROMPT2;

			mState = LI_NEED_MORE_INPUT;
		}
		return mState;
	}
	else
	{
		// The statment compiled correctly, now run it.

		if( lua_pcall( mL, 0, LUA_MULTRET, 0 ) )
		{
			// The error message (if any) will be added to the output as part
			// of the stack reporting.
			lua_gc( mL, LUA_GCCOLLECT, 0 );     // Do a full garbage collection on errors.
			mState = LI_ERROR;
		}
	}

	mCurrentStatement.clear();
	mFirstLine = true;

	// Report stack contents
	if ( lua_gettop(mL) > 0)
	{
		//char command[] = "function myprint(...) local str;str = '';for i = 1, arg.n do if str ~= '' then str = str .. '\t' end str = str .. tostring( arg[i] ); end;str = str .. '\n';interpreterOutput( str );end; print = myprint;";

		lua_getglobal(mL, "print");
		lua_insert(mL, 1);
		//luaL_dostring(mL, command);
		lua_pcall(mL, lua_gettop(mL)-1, 0, 0);
	}


	mPrompt = LI_PROMPT;

	// Clear stack
	lua_settop( mL, 0 );

	return mState;
}

// Callback for lua to provide output.
int CLuaConsole::CLuaInterpreter::insertOutputFromLua( lua_State *L )
{
	// Retreive the current interpreter for current lua state.
	CLuaInterpreter *interpreter;

	lua_pushlightuserdata( L, (void *)&LuaRegistryGUID );
	lua_gettable( L, LUA_REGISTRYINDEX );
	interpreter = static_cast<CLuaInterpreter *>(lua_touserdata( L, -1 ));

	if( interpreter )
		interpreter->mOutput += lua_tostring( L, -2 );

	lua_settop( L, 0 );
	return 0;
}

//function myprint(...)
//	local str
//	str = ''
// 
//	for i = 1, arg.n do
//		if str ~= '' then str = str .. '\t' end
//		str = str .. tostring( arg[i] )
//	end
// 
//	str = str .. '\n'
// 
//	interpreterOutput( str )
//end
// 
//oldprint = print
//print = myprint