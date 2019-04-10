#ifndef __ICONSOLEPARSER_H__
#define __ICONSOLEPARSER_H__

#include "Defines.h"
#include "PluginTypes.h"

#if defined DLL_EXPORT
#define DECLDIR __declspec(dllexport)
#else
#define DECLDIR __declspec(dllimport)
#endif

namespace Core
{
namespace Plugin
{
	class IConsoleParser
	{
	public:
		virtual E_COMMAND_RET ParseLine(String& Line, String& Message) = 0;
	};

	extern "C"
	{
		DECLDIR IConsoleParser* GetConsoleParser();
		DECLDIR E_PLUGIN GetPluginType(void);
	}
}
}

#endif //__ICONSOLEPARSER_H__