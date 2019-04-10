#include "OgreConsole.h"
#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "CPluginManager.h"
#include "CGuiManager.h"
#include "CPlayer.h"
#include "CTextOutput.h"
#include "CUtility.h"
#include "IO/CoreLogging.h"
#include "CInputEvent.h"

// Plugin
#include "Plugins\IConsoleParser.h"

#include "Gui3D/Gorilla.h"

#include "OgreRoot.h"
#include "OgreRenderWindow.h"
#include "OgreUTFString.h"		// TODO: Shouldn't need this for the "+" in OnKeyPressed m_History[m_HistoryPos]

#define CONSOLE_FONT_INDEX 9
#define CONSOLE_LINE_LENGTH 85
#define CONSOLE_LINE_COUNT 20
static const unsigned char legalchars[]=">ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890+!\"'#%&/()=?[]\\*-_.:,; ";

using namespace Core;
using namespace Core::Plugin;
using namespace Core::OgreSpecific;

OgreConsole* OgreConsole::Console = nullptr;

OgreConsole* OgreConsole::Instance()
{
	if(!Console)
		Console = new OgreConsole();
	return Console;
}

OgreConsole::OgreConsole() 
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
	//m_Parser = new CConsoleParser();
	m_GameObjectManager = Core::CGameObjectManager::Instance();

	Init();

	m_History.push_back("");
	isShowFpsInfo = false;
	isShowPos = false;
}

OgreConsole::~OgreConsole()
{
	if (isInitialised)
		Shutdown();
}

void OgreConsole::Init()
{
	if(isInitialised)
		Shutdown();

	Ogre::Root::getSingletonPtr()->addFrameListener(this);

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

	// Get list of parsers
	m_Parsers = CPluginManager::Instance()->GetConsoleFactories();
}

void OgreConsole::Shutdown()
{
	if(!isInitialised)
		return;

	isInitialised = false;
	Ogre::Root::getSingletonPtr()->removeFrameListener(this);
	m_Screen->destroy(m_Layer);
}

void OgreConsole::OnKeyPressed(const CInputKeyEvent &arg)
{

	if(!isVisible)
		return;

	// Do we still have more in the line queue to print
	if(m_LineQueue.size() > 0)
	{
		Print(0);
		m_UpdateConsole = true;
		return;
	}

	switch(arg.KeyCode)
	{
	case KC_RETURN:
		// normal from now on
		Print(m_History[m_HistoryPos]);

		// Interpret the command and print the outcome
		ParseLine(m_History[m_HistoryPos]);

		m_CursorPosition = 0;
		if(!(m_HistoryPos < (m_History.size() -1)))
			m_History.push_back("");					// new, empty last entry
		m_HistoryPos = (u32)m_History.size() - 1;		// switch to the new line

		m_UpdateConsole = true;
		break;

	case KC_BACK:
		// if you try to edit the history, rather make a new copy and edit that then :)
		if((u32)m_HistoryPos != m_History.size() - 1)
		{
			// add the edited element to the back
			m_History.push_back(m_History[m_HistoryPos]);
			m_HistoryPos = (u32)m_History.size() - 1;
		}
		// combine what is before and after the cursor
		if(m_CursorPosition > 0)
		{
			m_History[m_HistoryPos] = m_History[m_HistoryPos].substr(0, m_CursorPosition - 1) + m_History[m_HistoryPos].substr(m_CursorPosition);
			if(m_CursorPosition > 0)
				m_CursorPosition--;
		}
		break;

	case KC_DELETE:
		// if you try to edit the history, rather make a new copy and edit that then :)
		if((u32)m_HistoryPos != m_History.size() - 1)
		{
			// add the edited element to the back
			m_History.push_back(m_History[m_HistoryPos]);
			m_HistoryPos = (u32)m_History.size() - 1;
		}
		// combine what is before and after the cursor
		if(m_CursorPosition < (s32)m_History[m_HistoryPos].size())
		{
			m_History[m_HistoryPos] = m_History[m_HistoryPos].substr(0, m_CursorPosition) + m_History[m_HistoryPos].substr(m_CursorPosition + 1);
			m_CursorPosition++;
		}
		break;

	case KC_INSERT:
		isInsertmode = !isInsertmode;
		break;

	case KC_UP:
		if(m_HistoryPos > 0)
		{
			m_HistoryPos--;
			m_CursorPosition = (u32)m_History[m_HistoryPos].size() - 1;
		}
		break;

	case KC_DOWN:
		if(m_HistoryPos < m_History.size() - 1)
		{
			m_HistoryPos++;
			m_CursorPosition = (u32)m_History[m_HistoryPos].size() - 1;
		}
		break;

	case KC_PGUP:
		if(m_Startline>0)
			m_Startline--;
		m_UpdateConsole = true;

		break;

	case KC_LEFT:
		if(m_CursorPosition > 0)
			m_CursorPosition--;
		break;

	case KC_RIGHT:
		if(m_CursorPosition < m_History[m_HistoryPos].size())
			m_CursorPosition++;
		break;

	case KC_PGDOWN:
		if(m_Startline < m_Lines.size())
			m_Startline++;
		m_UpdateConsole = true;

		break;

	default:
		for(unsigned int c = 0; c < sizeof(legalchars) - 1; c++)
		{
			if(legalchars[c] == (char)arg.Text)
			{
				// if you try to edit the history, rather make a new copy and edit that then :)
				if((u32)m_HistoryPos != m_History.size() - 1)
				{
					// add the edited element to the back
					m_History.push_back(m_History[m_HistoryPos]);
					m_HistoryPos = (u32)m_History.size() - 1;
				}
				if((u32)m_CursorPosition == m_History[m_HistoryPos].size())
					m_History[m_HistoryPos] += (c8)arg.Text;
				else if(isInsertmode)
					m_History[m_HistoryPos] = m_History[m_HistoryPos].substr(0, m_CursorPosition) + arg.Text + m_History[m_HistoryPos].substr(m_CursorPosition);
				else if(!isInsertmode)
					m_History[m_HistoryPos] = m_History[m_HistoryPos].substr(0, m_CursorPosition) + arg.Text + m_History[m_HistoryPos].substr(m_CursorPosition + 1);

				m_CursorPosition++;
				break;
			}
		}
	}
	m_UpdatePrompt = true;
}

bool OgreConsole::frameStarted(const Ogre::FrameEvent &evt)
{
	if(m_UpdateConsole)
		UpdateConsole();

	if (m_UpdatePrompt)
		UpdatePrompt();

	CheckCommands();

	return true;
}

void OgreConsole::ParseLine(String& Line)
{
	E_COMMAND_RET ret = ECR_NOT_FOUND;
	String Message;

	// Get the type of output.
	OgreConsole::OUTPUT out = GetOutput(Line);

	for(u32 i = 0; i < m_Parsers.size(); i++)
	{
		// Attempt to execute the command
		String TempMsg;
		ret = m_Parsers[i]->ParseLine(Line, TempMsg);
		Message += TempMsg;

		if(ret == ECR_SUCCESS || ret == ECR_NOT_CORRECT || ret == ECR_ERROR)
		{
			// Command was found and will not be tried in any other parser
			Print(TempMsg, OUTPUT::STD);		// Use TempMsg because we are only printing this message
			return;
		}
	}

	// Need to check because ECR_CONTINUE will not break and return
	if(!(ret == ECR_CONTINUE))
		Message = "Command not found.";

	Print(Message, out);
}

void OgreConsole::UpdateConsole()
{
	m_UpdateConsole = false;

	//make sure is in range
	if(m_Startline > m_Lines.size())
		m_Startline = m_Lines.size();

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

	int lcount = 0;
	std::stringstream text;
	for(auto i = start; i != end; i++)
	{
		lcount++;
		text << (*i) << "\n";
	}

	m_ConsoleText->text(text.str());

	// Move prompt downwards.
	m_PromptText->top(10 + (lcount * m_GlyphData->mLineHeight));

	// Change background height so it covers the text and prompt
	m_Decoration->height(((lcount + 1) * m_GlyphData->mLineHeight) + 4);

	m_ConsoleText->width(m_Screen->getWidth() - 20);
	m_Decoration->width(m_Screen->getWidth() - 16);
	m_PromptText->width(m_Screen->getWidth() - 20);

}

void OgreConsole::UpdatePrompt()
{
	m_UpdatePrompt = false;
	std::stringstream text;

	// Browsing in history
	String entry = m_History[m_HistoryPos];
	if(m_LineQueue.size() > 0)
		text << "> [ANY KEY]";
	else
		text << "> " + entry;

	if(m_CursorPosition > (int)entry.size())
		m_CursorPosition = (u32)entry.size();

	String blank = "";
	for(u32 i = 0; i < m_CursorPosition; i++)
		blank += " ";

	text << "  " + blank + (isInsertmode ? "_" : "_");

	m_PromptText->text(text.str());
}

void OgreConsole::Print(const String& Text, OUTPUT Out)
{
	if(Out == STD)
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
	else
	{
		std::ofstream out;
		out.open (m_OutFile.c_str());
		out << Text;
		out.close();
	}
}

bool OgreConsole::frameEnded(const Ogre::FrameEvent &evt)
{
	return true;
}

void OgreConsole::SetVisible(bool Visible)
{
	isVisible = Visible;
	m_Layer->setVisible(isVisible);
}

OgreConsole::OUTPUT OgreConsole::GetOutput(String& Command)
{
	OUTPUT ret;
	size_t index = Command.find(">");
	if(index != std::string::npos)
		ret = FILE;
	else
		ret = STD;

	// Get the file name
	if(ret ==  FILE)
	{
		//  If the command has something like [cmd] > [out], then we will output to a file.
		m_OutFile = Command.substr(index);
		CUtility::StringReplace(m_OutFile, ">", "");
		CUtility::StringReplace(m_OutFile, " ", "");
	}

	// If the output is piped to a file, then there are extra options that need to be removed or the command will reject it
	if(ret == FILE)
	{
		Command = Command.substr(0, index);
	}

	return ret;
}

void OgreConsole::SetShowFpsInfo(bool Visible)
{
	if(!Visible)
	{
		CTextOutput::Instance()->RemoveTextBox("afps");
		CTextOutput::Instance()->RemoveTextBox("bestFPS");
		CTextOutput::Instance()->RemoveTextBox("worstFPS");
		CTextOutput::Instance()->RemoveTextBox("triangleCount");
		CTextOutput::Instance()->RemoveTextBox("batchCount");
	}
	isShowFpsInfo = Visible;
}

void OgreConsole::SetShowPos(bool Visible)
{
	if(!Visible)
	{
		CTextOutput::Instance()->RemoveTextBox("position");
	}
	isShowPos = Visible;
}

void OgreConsole::ClearConsole()
{
	m_HistoryPos = 0;
	m_History.clear();
	m_Lines.clear();
	m_History.push_back("");
}

void OgreConsole::CheckCommands()
{
	if(isShowFpsInfo)
	{
		try {
			auto stats = CGameManager::Instance()->GetRenderWindow()->getStatistics();
			CORE_TEXT("afps", "avgFPS: " + StringConverter::toString(stats.avgFPS));
			CORE_TEXT("bestFPS", "bestFPS: " + StringConverter::toString(stats.bestFPS));
			CORE_TEXT("worstFPS", "worstFPS: " +  StringConverter::toString(stats.worstFPS));
			CORE_TEXT("triangleCount", "triangleCount: " + StringConverter::toString(stats.triangleCount));
			CORE_TEXT("batchCount", "batchCount: " + StringConverter::toString(stats.batchCount));

		}
		catch(...) { /* ignore */ }
	}

	if(isShowPos)
	{
		CORE_TEXT("position", "position:" + StringConverter::toString(m_GameObjectManager->GetHumanPlayer()->GetPlayerNode()->getPosition()));
	}

}

void OgreConsole::SaveCommands()
{
	std::ofstream out;
	out.open ("./ConsoleHistory.txt");
	for(u32 i = 0; i < m_History.size(); i++)
	{
		out << m_History[i] << std::endl;
	}
	out.close();
}

void OgreConsole::LoadCommands(bool Execute)
{
	std::ifstream in;
	in.open("./ConsoleHistory.txt");
	if (in.is_open()) 
	{
		while (!in.eof()) 
		{
			String str;
			getline(in, str);
			m_History.push_back(str);
			if(Execute)
			{
				if(strncmp(str.c_str(), "load console", 12) == 0 ||
					strncmp(str.c_str(), "save console", 12) == 0)
				{
					// Don't execute save or load commands
				}
				else
				{
					// normal from now on
					Print(str.c_str());

					// Interpret the command and print the outcome
					//Print(m_Parser->ParseLine(str));
				}
			}
		}
		in.close();
		m_HistoryPos = (u32)m_History.size() - 1;
	}
}

void OgreConsole::AddCommandToHistory(const char* Command)
{
	m_History.push_back(String(Command));
}