// Interface for logging messages, warnings and errors
// Updated 3-17-07

#ifndef __ILOGGER_H__
#define __ILOGGER_H__

namespace IO
{
	enum LOG_LEVEL
	{
		LOG_INFORMATION = 0,
		LOG_WARNING,	// Default log level, warnings and errors are printed out
		LOG_ERROR,		// Low log level, only errors are printed into the log
		LOG_NONE		// Nothing is printed out to the log
	};

	class CORE_EXPORT ILogger
	{
	public:
		virtual ~ILogger() {}
		virtual LOG_LEVEL GetLogLevel() = 0;														// Returns the current set log level.
		virtual void SetLogLevel(LOG_LEVEL ll) = 0;
		virtual void Log(const char* Text, LOG_LEVEL Level = LOG_INFORMATION) = 0;					// Prints out a text into the log
		virtual void Log(const char* Text, const char* Hint, LOG_LEVEL Level = LOG_INFORMATION) = 0;// Prints out a text into the log
	};

} // End namespace

#endif

