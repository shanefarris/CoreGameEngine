#ifndef __CDEBUGMANANGER_H__
#define __CDEBUGMANANGER_H__

#include "Defines.h"

namespace Core
{
namespace Debug
{
	// Enum used to describe debug levels used in logging debugging information
	enum DEBUG_LEVEL
	{
		NONE		= 0,	// Used to set the specific object not do log any info messages 
		INFO_BASIC	= 1,	// This is for messages that happens rarely e.g. initializing, shutdown messages 
		INFO_EVENT	= 2,	// For messages that happens prety often but not "all the time" e.g. events 
		INFO_HEAVY	= 3		// This is for the rely frequent messages e.g "every frame information" 
	};

	// class used by the Debuger to store managedLogs
	class ManagedLogElement
	{
	public:
		ManagedLogElement(const std::string *fileName, const std::string *text) { file = *fileName; textBuffer = *text;}
		~ManagedLogElement() {}

		std::string file;
		std::string textBuffer;
	};

	#define MAX_MANAGED_BUFFER_SIZE  131072 // The max sise of one file in the managedLog buffer, when full the log is writen to the file 128kb
	#define FORMAT_CBUFFER_SIZE 4096		// This is size of the buffer used for parsing formated text

	// A debug manager for creating and writing logs.
	/* 
	 *	Note: Writing to a file is not a very fast operation, so it might couse a small lag and shuld only be used for debuging.
	 *	The ManagedLogAdd dosent write the data emitetly it saves the data and writes it on program shutdown or on a call to ManagedLogEnd. 
	 */
	class CORE_EXPORT CDebugManager
	{
	public:
		~CDebugManager();
		
		static CDebugManager* Instance();

		void AddWarning(const char* formatText, ...);		// Adds a warning using a printf style formated text.
		void AddError(const char* formatText, ...);			// Adds a error using a printf style formated text.
		void AddLog(const char* formatText, ...);			// Adds a log using a printf style formated text.
		
		void ManagedLogAdd(const char* fileName, const char* formatText, ...);	// Adds a managed Log message using a printf style formated text.
		void ManagedLogEnd(const char* fileName);			// This function writes a text buffer to a file and delets the buffer.
		void ManagedLogEndAll();							// Function that wites all managed logs, cald at shutdown.

		const char* GetDate();								// Retreves the system date as a string
		const char* GetTime();								// Retreves the system time as a string

	private:
		CDebugManager();

		void WriteToFile(const char* fileName, const std::string& text, bool append = true); // Writes the string to a file
		void AddWarning(const std::string& text);		// Adds a line to the warnings.log file, the msg is writen imeditly.
		void AddError(const std::string& text);			// Adds a line to the errors.log file, the msg is writen imeditly.
		void AddLog(const std::string& text);			// Adds a line to the log file, the msg is writen imeditly.
		void ManagedLogAdd(const char* fileName, const std::string& text);	// This function adds the text to a buffer for later writing.
		void DeleteOldLogs();
		void TimeFormatText(std::string& text);

		static CDebugManager* DebugManager;
		std::string m_LogPath;
		char* m_dateAndTime;
		char* m_time;
		unsigned int m_bytesLoged;
		bool m_errorAdded;
		bool m_warningAdded;
		char* m_pFormatBuffer;
		std::vector<ManagedLogElement> m_managedLogs;

	};

}
}

#endif // __CDEBUGMANANGER_H__
