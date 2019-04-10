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
	class CGameObject;

namespace Plugin
{
	class CConsoleParserCheat : public Core::Plugin::IConsoleParser
	{
	public:
		CConsoleParserCheat();
		~CConsoleParserCheat();

		E_COMMAND_RET ParseLine(String& Line, String& Message);

	private:
		std::vector<String>& Split(String& s, char delim, std::vector<String>& Elements);

		E_COMMAND_RET ParseAdd(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseList(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseSet(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET ParseMission(std::vector<String>& Elements, String& Message);

		E_COMMAND_RET LoadLevel(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET SaveLevel(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET AddPlayer(std::vector<String>& Elements, String& Message);
		E_COMMAND_RET AddObject(std::vector<String>& Elements, String& Message);
		CPlayer*	  FindPlayer(String& Name);

		void CreateWall(const Vector3& From, const Vector3& To, String Name);

		// List of all objects created from the console
		std::vector<String>				m_PlayerList;
		std::vector<Core::CGameObject*>	m_ObjectList;

	};

}
}

#endif //__CCONSOLEPARSER_H__