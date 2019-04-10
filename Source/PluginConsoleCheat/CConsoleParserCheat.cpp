// DECLDIR will perform an export for us
#define DLL_EXPORT

#include "CConsoleParserCheat.h"
#include "CGameManager.h"
#include "CGameObjectManager.h"
#include "CCameraManager.h"
#include "OgreConsole.h"
#include "CTextOutput.h"
#include "PlayerEnums.h"
#include "CPlayer.h"
#include "CGameObject.h"
#include "CMissionManager.h"
#include "IPhysicsStrategy.h"
#include "CPhysicsManager.h"
#include "CPlayer.h"
#include "CUtility.h"

#include "RuntimeEditor\CRuntimeEditorManager.h"

// Ogre
#include "OgreSceneNode.h"
#include "OgreSceneManager.h"
#include "OgreTechnique.h"
#include "OgreMaterialManager.h"
#include "OgreManualObject.h"
#include "OgreMovableObject.h"

using namespace Core;

// Get rid of name mangeling
extern "C"
{
	DECLDIR Core::Plugin::IConsoleParser* GetFactories(void)
	{
		return new Core::Plugin::CConsoleParserCheat();
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

CConsoleParserCheat::CConsoleParserCheat()
{
}

CConsoleParserCheat::~CConsoleParserCheat()
{
}

E_COMMAND_RET CConsoleParserCheat::ParseLine(String& Line, String& Message)
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
			if(str == "add")
			{
				return ParseAdd(Elements, Message);
			}
			else if(str == "list")
			{
				return ParseList(Elements, Message);
			}
			else if(str == "set")
			{
				return ParseSet(Elements, Message);
			}
			else if(str == "clear")
			{
				OgreConsole::Instance()->ClearConsole();
			}
			else if(str == "mission")
			{
				return ParseMission(Elements, Message);
			}
			else if(str == "load_level")
			{
				return LoadLevel(Elements, Message);
			}
			else if(str == "save_level")
			{
				return SaveLevel(Elements, Message);
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

E_COMMAND_RET CConsoleParserCheat::ParseAdd(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "add", does nothing
	 *				"add player TYPE TEAM", adds a player in a randmon position
	 *				"add obj TYPE", adds a model to the scene in a random position
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() < 3)
	{
		Message = "Need an option for the add command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 3)
	{
		// Find what to add
		if(Elements[1] == "obj")
		{
			return AddObject(Elements, Message);
			return ECR_SUCCESS;
		}
		else
		{
			Message = "Option for the add command not found.";
			return ECR_NOT_CORRECT;
		}
	}
	else if(Elements.size() == 4)
	{
		// Find what to add
		if(Elements[1] == "player")
		{
			return AddPlayer(Elements, Message);
			return ECR_SUCCESS;
		}
	}

	if(Elements.size() > 4)
	{
		Message = "Too many options for add command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParserCheat::ParseList(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "list", lists all high level commans
	 *				"list add"
	 *				"list obj"
	 *				"list state"
	 *				"list set"
	 *				"list mission"
	 *				"list scenario"
	 *				"list players"
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() == 1)
		Message = "**Cheat Console:**\n"
				"add: create new game objects\n"
				"obj: lists the objects created by the console with an alias that can be used\n"
				"state: shows the available states you can set players to\n"
				"set: setting attributes to different objects in the world\n"
				"mission: update and get status on missions and acheivements\n"
				"load_level: loads predefined level\n"
				"save_level: saves current state\n"
				"players: list player names\n";

	if(Elements.size() == 2)
	{
		// Find what to list
		if(Elements[1] == "add")
		{
			Message = "add:\nadd player TYPE: creates a new player of TYPE (1-5)";
		}
		else if(Elements[1] == "obj")
		{
			for(u32 i = 0; i < m_PlayerList.size(); i++)
			{
				Message += "-" + StringConverter::toString(i) + ": " + m_PlayerList[i];
			}
		}
		else if(Elements[1] == "state")
		{
			Message = "Available states: wander, evade, seek";
		}
		else if(Elements[1] == "set")
		{
			Message = "set:\nset pos OBJ_NAME x y z: sets the position of the object\n"
				"set state PLAYER STATE: sets the AI state of the character\n"
				"set runspeed PLAYER X: sets the running speed of the player\n";
		}
		else if(Elements[1] == "mission")
		{
			Message = "mission: \nmission start NAME: starts a misison by name\n"
				"mission list available: lists the available missions that can be loaded";
		}
		else if(Elements[1] == "load_level")
		{
			Message = "load_level: \nload_level filename: loads a level by file name";
		}
		else if(Elements[1] == "save_level")
		{
			Message = "save_level: \nsave_level filename: saves a level by file name";
		}
		else if(Elements[1] == "players")
		{
			Vector<CPlayer*> players;
			CGameObjectManager::Instance()->GetAllPlayers(players);
			for(u32 i = 0; i < players.size(); i++)
			{
				Message += String(players[i]->GetName()) + "\n";
			}
		}
	}

	if(Elements.size() > 2)
	{
		Message = "Too many options for list command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_CONTINUE;
}

E_COMMAND_RET CConsoleParserCheat::ParseSet(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "set", does nothing
	 *				"set pos OBJ_NAME X Y Z", sets position for object
	 *				"set state PLAYER STATE", set the AI state of the player
	 *				"set runspeed PLAYER X", set the running speed of the player
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() < 3)
	{
		Message = "Need an option for the set command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 6)
	{
		// Find what to set
		if(Elements[1] == "pos")
		{
			CPlayer* player = nullptr;

			// Obj id
			player = FindPlayer(Elements[2]);

			// Get pos
			f32 x = (f32)atof(Elements[3].c_str());
			f32 y = (f32)atof(Elements[4].c_str());
			f32 z = (f32)atof(Elements[5].c_str());
			
			if(player)
			{
				player->SetPlayerPosition(x, y, z);
			}
		}
		else
		{
			Message = "Option for the set command not found.";
			return ECR_NOT_CORRECT;
		}
	}
	else if(Elements.size() == 4)
	{
		if(Elements[1] == "state")
		{
			CPlayer* player = nullptr;

			// Obj id
			player = FindPlayer(Elements[2]);

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
		else if(Elements[1] == "runspeed")
		{
			CPlayer* player = nullptr;

			// Obj id
			player = FindPlayer(Elements[2]);

			if(player)
			{
				// Get speed value
				f32 value = StringConverter::parseReal(Elements[3]);
				if(value > 0.0)
				{
					player->SetRunSpeed(value);
					Message = String(player->GetName()) + ": run speed at " + Elements[3];
				}
			}
			else
			{
				Message = "Could not find player by name.";
				return ECR_ERROR;
			}
		}
	}
	else
	{
		Message = "Option for the set command not found.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() > 6)
	{
		Message = "Too many options for set command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParserCheat::ParseMission(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "mission", does nothing
	 *				"mission start NAME", starts a mission of given name
	 *				"mission list available", lists the available missions that can be loaded
	 */

	// Check to make sure they have at least one show option
	if(Elements.size() < 3)
	{
		Message = "Need an option for the mission command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 3)
	{
		// Are we starting something
		if(Elements[1] == "start")
		{
			CPlayer* player = CGameObjectManager::Instance()->GetHumanPlayer();
			if(Mission::CMissionManager::Instance()->StartMission(Elements[2].c_str(), player))
			{
				Message = "Mission: " + Elements[2] + " started";
				return ECR_SUCCESS;
			}
			else
			{
				Message = "Could not start mission: " + Elements[2];
				return ECR_ERROR;
			}
		}
		// Are we listing something
		else if(Elements[1] == "list")
		{
			Vector<String> list;
			Mission::CMissionManager::Instance()->ListAllAvailableMissions(list);
			for(u32 i = 0; i < list.size(); i++)
			{
				Message += list[i] + "\n";
			}
			return ECR_SUCCESS;
		}
		else
		{
			Message = "Option for the mission command not found.";
			return ECR_NOT_CORRECT;
		}
	}
	else
	{
		Message = "Option for the mission command not found.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() > 3)
	{
		Message = "Too many options for mission command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParserCheat::AddPlayer(std::vector<String>& Elements, String& Message)
{
	Vector3 pos;
	u32			Team;

	// Find the player type
	String playerType = Elements[2];

	// Find the team
	Team = StringConverter::parseUnsignedInt(Elements[3]);
	if(Team > NUM_TEAMS)
	{
		Message = "Invalid team for player";
		return ECR_ERROR;
	}
	else if(Team == 0 && Elements[3] != "0")
	{
		// parseUnsignedInt returns 0 if it could not be parsed
		Message = "Invalid team for player";
		return ECR_ERROR;
	}

	// Set random position
	pos.x = (((float) rand ()) / ((float) RAND_MAX)) * 1000;
	pos.z = (((float) rand ()) / ((float) RAND_MAX)) * 1000;
	pos.y = 0;

	CPlayer* player = CGameObjectManager::Instance()->CreatePlayer(playerType.c_str(), (E_PLAYER_TEAM)Team);
	if(player)
	{
		player->SetPlayerPosition(pos);
		m_PlayerList.push_back(player->GetName());
	}
	else
	{
		Message = "Could not create player.";
		return ECR_ERROR;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParserCheat::LoadLevel(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "load_level", does nothing
	 *				"load_level filename", loads a level
	 */

	if(Elements.size() < 2)
	{
		Message = "Need an option for the load_level command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 2)
	{
		if(CGameManager::Instance()->LoadGame(Elements[1].c_str(), Elements[1].c_str()))
		{
			if(!Editor::CRuntimeEditorManager::Instance()->IsRunning())
				Editor::CRuntimeEditorManager::Instance()->Shutdown();

			Message = "Level: " + Elements[1] + " loaded.";
			return ECR_SUCCESS;
		}
		else
		{
			Message = "Could not load: " + Elements[1];
			return ECR_ERROR;
		}
	}
	else
	{
		Message = "File name required for the load_level command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

E_COMMAND_RET CConsoleParserCheat::SaveLevel(std::vector<String>& Elements, String& Message)
{
	/*
	 *  Commands:   "save_level", does nothing
	 *				"save_level filename", saves a level
	 */

	if(Elements.size() < 2)
	{
		Message = "Need an option for the save_level command.";
		return ECR_NOT_CORRECT;
	}

	if(Elements.size() == 2)
	{
		if(CGameManager::Instance()->SaveGame(Elements[1].c_str()))
		{
			Message = "Save: " + Elements[1] + " saved.";
			return ECR_SUCCESS;
		}
		else
		{
			Message = "Could not save: " + Elements[1];
			return ECR_ERROR;
		}
	}
	else
	{
		Message = "File name required for the save_level command.";
		return ECR_NOT_CORRECT;
	}

	return ECR_SUCCESS;
}

CPlayer* CConsoleParserCheat::FindPlayer(String& Name)
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

E_COMMAND_RET CConsoleParserCheat::AddObject(std::vector<String>& Elements, String& Message)
{
	Vector3		pos;

	// Create random position
	pos.x = (((float) rand ()) / ((float) RAND_MAX)) * 1000;
	pos.z = (((float) rand ()) / ((float) RAND_MAX)) * 1000;
	pos.y = 0;

	// Find the obj type
	Core::CGameObject* obj = CGameObjectManager::Instance()->CreateObject(Elements[2].c_str(), "", pos);
	if(obj)
	{
		m_ObjectList.push_back(obj);
	}
	else
	{
		Message = String("Could not create object type: ") + Elements[2];
		return ECR_ERROR;
	}

	return ECR_SUCCESS;
}

std::vector<String>& CConsoleParserCheat::Split(String& s, char delim, std::vector<String>& Elements) 
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