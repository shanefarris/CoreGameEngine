// DECLDIR will perform an export for us
#define DLL_EXPORT

#include "CConsoleParser.h"
#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "CPluginManager.h"
#include "OgreConsole.h"
#include "CTextOutput.h"
#include "PlayerEnums.h"
#include "CPlayer.h"

#include "OgreStringConverter.h"

// Plugin fatories
#include "Plugins/IAiStateFactory.h"
#include "Plugins/IGameObjectFactory.h"
#include "Plugins/IMissionFactory.h"
#include "Plugins/IPlayerFactory.h"

using namespace Core;

// Get rid of name mangeling
extern "C"
{
	DECLDIR Core::Plugin::IConsoleParser* GetFactories(void)
	{
		return new Core::Plugin::CConsoleParser();
	}

	DECLDIR Core::Plugin::E_PLUGIN GetPluginType(void)
	{
		return Core::Plugin::EP_CONSOLE;
	}
}

namespace Core
{
namespace Plugin
{

CConsoleParser::CConsoleParser()
{
}

CConsoleParser::~CConsoleParser()
{
}

E_COMMAND_RET CConsoleParser::ParseLine(String& Line, String& Message)
{
	std::vector<String> Elements;	// List of words

	// Nothing to process
	if(Line.length() == 0)
		return ECR_SUCCESS;

	// Get our list of words
	Split(Line, ' ', Elements);

	// Process the words and find the command
	if(Elements.size() > 0)
	{
		// Find the command
		for(u32 i = 0; i < Elements.size(); i++)
		{
			String str = Elements[i];
			transform(str.begin(), str.end(), str.begin(), tolower);
			if(str == "show")
			{
				return ParseShow(Elements, Message);
			}
			else if(str == "hide")
			{
				return ParseHide(Elements, Message);
			}
			else if(str == "exit")
			{
				return ParseExit(Elements, Message);
			}
			else if(str == "list")
			{
				return ParseList(Elements, Message);
			}
			else if(str == "save")
			{
				return ParseSave(Elements, Message);
			}
			else if(str == "load")
			{
				return ParseLoad(Elements, Message);
			}
			else if(str == "camera")
			{
				return ParseCamera(Elements, Message);
			}
			else if(str == "clear")
			{
				OgreConsole::Instance()->ClearConsole();
			}
			else if(str == "team")
			{
				return ParseTeam(Elements, Message);
			}
			else if(str == "plugin")
			{
				return ParsePlugin(Elements, Message);
			}
			else
			{
				// Not reconzied
				return ECR_NOT_FOUND;
			}
		}
	}

	return ECR_SUCCESS;		// Returns good
}

E_COMMAND_RET CConsoleParser::ParseShow(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "show", does nothing
	 *				"show fps", shows all fps info
	 *				"show pos", shows the players position
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() == 1)
	{
		Message = "Need an option for the show command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 2)
	{
		if(Elements[1] == "fps")
		{
			OgreConsole::Instance()->SetShowFpsInfo(true);
		}
		else if(Elements[1] == "pos")
		{
			OgreConsole::Instance()->SetShowPos(true);
		}
		else
		{
			Message = "Option for the show command not found.";
			return ECR_NOT_CORRECT;
		}
	}

	if(Elements.size() > 2)
	{
		Message = "Too many options for show command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParser::ParseHide(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "hide", does nothing
	 *				"hide fps", hides all fps info
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() == 1)
	{
		Message = "Need an option for the hide command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 2)
	{
		if(Elements[1] == "fps")
		{
			OgreConsole::Instance()->SetShowFpsInfo(false);
			return ECR_SUCCESS;
		}
		else if(Elements[1] == "pos")
		{
			OgreConsole::Instance()->SetShowPos(false);
			return ECR_SUCCESS;
		}
		else
		{
			Message = "Option for the hide command not found.";
			return ECR_NOT_CORRECT;
		}
	}

	if(Elements.size() > 2)
	{
		Message = "Too many options for hide command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParser::ParseExit(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "exit", exits the current game state
	 *				"exit all", exits the game
	 */

	// Check for "exit" command
	if(Elements.size() == 1)
		CGameManager::Instance()->AdvanceGameState();
	else if(Elements.size() > 1)
	{
		if(Elements[1] == "all")
		{
			CGameManager::Instance()->SetQuit(true);
			return ECR_SUCCESS;
		}
		else
		{
			// Don't have any other options for "exit"
			Message = "Option for the exit command not found.";
			return ECR_NOT_CORRECT;
		}
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParser::ParseList(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "list", lists all high level commans
	 *				"list show" 
	 *				"list hide"
	 *				"list state"
	 *				"list clear"
	 *				"list team"
	 *				"list plugins"
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() == 1)
		Message = "**Player Console:**\n"
				"show: show runtime info\n"
				"hide: hide runtime info\n"
				"exit: leaves a level or game\n"
				"save: saves all console commands to a text file\n"
				"load: loads saved console commands to the console for reuse\n"
				"state: shows the available states you can set players to\n"
				"clear: clears the console and command history\n"
				"team: update members or your own team\n"
				"plugins: lists the plugins that are loaded\n";

	if(Elements.size() == 2)
	{
		// Find what to list
		if(Elements[1] == "show")
		{
			Message = "show:\nshow fps: displays FPS info\nshow pos: displays the players 3D position";
		}
		else if(Elements[1] == "hide")
		{
			Message = "hide:\nhide fps: removes FPS info\nhide pos: removes the players 3D position";
		}
		else if(Elements[1] == "exit")
		{
			Message = "exit:\nexit: leaves the current leavel\nexit all: leaves the game";
		}
		else if(Elements[1] == "save")
		{
			Message = "save:\nsave console: saves all console commands to a text file";
		}
		else if(Elements[1] == "load")
		{
			Message = "load:\nload console: loads saved console commands to the console for reuse\n"
				"load console execute: loads saved console commands and executes them in order";
		}
		else if(Elements[1] == "state")
		{
			Message = "Available states: wander, evade, seek";
		}
		else if(Elements[1] == "clear")
		{
			Message = "clear: clears the console and command history";
		}
		else if(Elements[1] == "team")
		{
			Message = "test: list the team you are on\n"
				"team state PLAYER STATE: set the AI state of the player on the same team";
		}
		else if(Elements[1] == "plugins")
		{
			ListPlugins(Message);
			return ECR_SUCCESS;
		}
	}

	if(Elements.size() > 2)
	{
		Message = "Too many options for list command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_CONTINUE;
}

E_COMMAND_RET CConsoleParser::ParseSave(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "save", does nothing
	 *				"save console", saves history to text file
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() == 1)
	{
		Message = "Need an option for the save command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 2)
	{
		// Find what to list
		if(Elements[1] == "console")
		{
			OgreConsole::Instance()->SaveCommands();
			return ECR_SUCCESS;
		}
		else
		{
			Message = "Option for the save command not found.";
			return ECR_NOT_CORRECT;
		}
	}

	if(Elements.size() > 2)
	{
		Message = "Too many options for save command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParser::ParseLoad(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "load", does nothing
	 *				"load console", loads history to text file
	 *				"load console execute", loads history to text file
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() == 1)
	{
		Message = "Need an option for the load command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 2)
	{
		// Find what to list
		if(Elements[1] == "console")
		{
			OgreConsole::Instance()->LoadCommands(false);
			return ECR_SUCCESS;
		}
		else
		{
			Message = "Option for the load command not found.";
			return ECR_NOT_CORRECT;
		}
	}
	else if(Elements.size() == 3)
	{
		if(Elements[2] == "execute")
		{
			OgreConsole::Instance()->LoadCommands(true);	
			return ECR_SUCCESS;
		}
	}
	else if(Elements.size() > 3)
	{
		Message = "Too many options for load command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParser::ParseCamera(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "camera", shows the type of the current camera
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() == 1)
	{
		E_CAMERA_MODE mode;
		mode = CCameraManager::Instance()->GetMode();
		if(mode == ECM_CHASE)
			Message = "Current camera: CHASE";
		else if(mode == ECM_FIXED)
			Message = "Current camera: FIXED";
		else if(mode == ECM_FPS)
			Message = "Current camera: FPS";
		else if(mode == ECM_TOP_DOWN)
			Message = "Current camera: TOP DOWN";
		else if(mode == ECM_SIDE)
			Message = "Current camera: SIDE";
		else if(mode == ECM_FREE)
			Message = "Current camera: FREE";
		else if(mode == ECM_GOD)
			Message = "Current camera: GOD";
		else if(mode == ECM_RTS)
			Message = "Current camera: RTS";
		else if(mode == ECM_SPRING)
			Message = "Current camera: SPRING";
		else if(mode == ECM_NONE)
			Message = "Current camera: NONE";
		else
		{
			Message = "Could not find the current camera mode";
			return ECR_NOT_CORRECT;
		}
	}

	if(Elements.size() > 1)
	{
		Message = "Too many options for show command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParser::ParseTeam(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "team", list the team you are on
	 *				"team state PLAYER STATE", set the AI state of the player on the same team
	 */

	if(Elements.size() == 1)
	{
		// List the team the player is on
		if(CGameObjectManager::Instance()->GetHumanPlayer())
		{
			Message = "Team: " + StringConverter::toString((u32)CGameObjectManager::Instance()->GetHumanPlayer()->GetPlayerTeam());
			return ECR_SUCCESS;
		}
		else
		{
			Message = "No player selected.";
			return ECR_SUCCESS;
		}
	}

	if(Elements.size() == 4)
	{
		if(Elements[1] == "state")
		{
			CPlayer* player = nullptr;

			// Obj id
			player = FindPlayer(Elements[2]);

			// Check if we're on the same team
			if(CGameObjectManager::Instance()->GetHumanPlayer()->GetPlayerTeam() != player->GetPlayerTeam())
			{
				// Return error and don't tell the user this player exists
				Message = "Player not found.";
				return ECR_SUCCESS;
			}

			// Get state
			String state = Elements[3];
			if(player)
			{
				if(state == "evade")
					player->SetCharacterState(EPS_EVADING);
				else if(state == "seek_enemy")
					player->SetCharacterState(EPS_SEEK_ENEMY);
				else if(state == "seek_obstacle")
					player->SetCharacterState(EPS_SEEK_OBS);
				else if(state == "seek_item")
					player->SetCharacterState(EPS_SEEK_ITEM);
				else if(state == "wander")
					player->SetCharacterState(EPS_WANDERING);
				else
				{
					Message = "State not found (list state)";
					return ECR_NOT_CORRECT;
				}
			}
		}
	}
	else
	{
		Message = "Option for the set command not found.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() > 4)
	{
		Message = "Too many options for set command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParser::ParsePlugin(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   
	 */

	return ECR_SUCCESS;
}

CPlayer* CConsoleParser::FindPlayer(String& Name)
{
	// Obj id
	if(Name.at(0) == '-')
	{
		// they are using the alias
		String str = Name.substr(1, Name.size() - 1);
		u32 i = atoi(str.c_str());
		if(i <= m_PlayerList.size())
			return CGameObjectManager::Instance()->GetPlayerByName(m_PlayerList[i].c_str());
	}
	else
	{
		// they are using the full name
		return CGameObjectManager::Instance()->GetPlayerByName(Name.c_str());
	}
	return nullptr;
}

void CConsoleParser::ListPlugins(String& Message)
{
	CPluginManager* pm = CPluginManager::Instance();

	// Game Objects
	size_t size = pm->GetGameObjectFactories().size();
	if(size > 0)
	{
		Message += "Game Object:\n";
		for(size_t i = 0; i < size; i++)
		{
			Message += "\t" + pm->GetGameObjectFactories()[i]->GameObjectType;
		}
		Message += "\n";
	}

	//// Consoles
	//size = pm->GetConsoleParsers().size();
	//if(size > 0)
	//{
	//	Message += "Consoles:\n";
	//	for(size_t i = 0; i < size; i++)
	//	{
	//		//Message += "\t" + pm->GetConsoleParsers()[i]->;
	//	}
	//	Message += "\n";
	//}

	// Missions
	size = pm->GetMissionFactories().size();
	if(size > 0)
	{
		Message += "Missions:\n";
		for(size_t i = 0; i < size; i++)
		{
			Message += "\t" + pm->GetMissionFactories()[i]->LabelName;
		}
		Message += "\n";
	}

	// AI state
	size = pm->GetAiStateFactories().size();
	if(size > 0)
	{
		Message += "Ai States:\n";
		for(size_t i = 0; i < size; i++)
		{
			Message += "\t" + pm->GetAiStateFactories()[i]->LabelName;
		}
		Message += "\n";
	}

	// Players
	size = pm->GetPlayerFactories().size();
	if(size > 0)
	{
		Message += "Players:\n";
		for(size_t i = 0; i < size; i++)
		{
			Message += "\t" + String(pm->GetPlayerFactories()[i]->PlayerType);
		}
		Message += "\n";
	}
}

std::vector<String>& CConsoleParser::Split(String& s, char delim, std::vector<String>& Elements) 
{
    std::stringstream ss(s);
    String item;
    while(std::getline(ss, item, delim)) 
	{
		if(item != "")
			Elements.push_back(item);
    }
    return Elements;
}

}
}