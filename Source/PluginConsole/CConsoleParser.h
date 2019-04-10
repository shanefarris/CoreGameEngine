#ifndef __CCONSOLEPARSER_H__
#define __CCONSOLEPARSER_H__

#include "Defines.h"
#include "Plugins/IConsoleParser.h"
#include "Plugins/PluginTypes.h"

#include <vector>

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
	class CPlayer;

namespace Plugin
{
	class CConsoleParser : public Core::Plugin::IConsoleParser
	{
	public:
		CConsoleParser();
		~CConsoleParser();

		E_COMMAND_RET ParseLine(String& Line, String& Message);

	private:
		std::vector<String>& Split(String& s, char delim, std::vector<String>& Elements);

		E_COMMAND_RET ParseShow(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseHide(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseExit(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseList(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseSave(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseLoad(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseCamera(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseTeam(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParsePlugin(std::vector<String>& Elements, String& Message);

		CPlayer* FindPlayer(String& Name);
		void	 ListPlugins(String& Message);

		// List of all objects created from the console (only players for now, but could be more in the future)
		std::vector<String> m_PlayerList;

	};

}
}

#endif //__CCONSOLEPARSER_H__