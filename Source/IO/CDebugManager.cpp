#include "CDebugManager.h"
#include "Ogre.h"
#include "windows.h"
#include "strsafe.h"

#include <fstream>

using namespace Core::Debug;

CDebugManager* CDebugManager::DebugManager = nullptr;

CDebugManager* CDebugManager::Instance()
{
	if(!DebugManager)
		DebugManager = new CDebugManager();
	return DebugManager;
}

CDebugManager::CDebugManager()
{
	// walue initalization
	m_bytesLoged = 0;
	m_errorAdded = false;
	m_warningAdded = false;

	m_dateAndTime = new char[32];
	m_time = new char[32];
	m_pFormatBuffer = new char[FORMAT_CBUFFER_SIZE];	
	
	// delete all old logs
	DeleteOldLogs();
}

CDebugManager::~CDebugManager()
{
	// writes all bufferd logs and clears the _managedLogs vector
	ManagedLogEndAll();

	delete[] m_dateAndTime;
	delete[] m_time;
	delete[] m_pFormatBuffer;
}

void CDebugManager::DeleteOldLogs()
{
	WIN32_FIND_DATA findData;
	HANDLE hFind = INVALID_HANDLE_VALUE;
	std::string loghPath;

	loghPath.assign( m_LogPath );
	loghPath.append( "*" );

	hFind = FindFirstFile( loghPath.c_str(), &findData );
	
	if( hFind == INVALID_HANDLE_VALUE )
	{
		AddWarning( "Faild to delete old logs, error: %u", GetLastError() );
	}
	else
	{
		std::string fileName = findData.cFileName;
		if(  fileName.length() > 4 )
		{
			if( fileName.compare( fileName.length()-4, 4, ".log") == 0 )
			{
				std::string fulFileName;
				fulFileName.assign( m_LogPath );
				fulFileName.append( fileName );

				if( DeleteFile( fulFileName.c_str() ) == false )
				{
					AddWarning( "Faild to delete log file \"%s\", error: %u", fulFileName.c_str(), GetLastError() );
				}
			}
		}
		while( FindNextFile( hFind, &findData ) )
		{
			fileName = findData.cFileName;
			if(  fileName.length() > 4 )
			{
				if( fileName.compare( fileName.length()-4, 4, ".log") == 0 )
				{
					std::string fulFileName;
					fulFileName.assign( m_LogPath );
					fulFileName.append( fileName );

					if( DeleteFile( fulFileName.c_str() ) == false )
					{
						AddWarning( "Faild to delete log file \"%s\", error: %u", fulFileName.c_str(), GetLastError() );
					}
				}
			}
		}

		FindClose( hFind );
	}	

}

void CDebugManager::WriteToFile(const char* fileName, const std::string& text, bool append)
{	
	/* 
	 *	This function will open/create the file, write the data and then close it again.\n
	 *	The ManagedLogAdd + ManagedLogEnd shuld be used if the log is writen to freguently.\n\n
	 *	Note: This function is not fast at all so freguently calls is not good, if posible add all the text to one big string and cal the function once.\n
	 *  \param fileName The file name of the log, where it will be created is specified by the define LOG_PATH.
	 *  \param text A string with the data to write.
	 *	\param append Should the data be added or overwritten?
	 *	\sa ManagedLogAdd(), ManagedLogEnd()
	 */
	std::string filePathAndName;
	filePathAndName.append(m_LogPath);
	filePathAndName.append(fileName);

	// Saves the amount of data writen in the debuger
	m_bytesLoged += (unsigned int)text.size();

	// the file handel
	std::ofstream file;

	// Opens the file 
	if ( append )
		file.open( filePathAndName.c_str(), std::ios::app);
	else
		file.open( filePathAndName.c_str(), std::ios::trunc);

	// writes the string to the file
	file << text;

	// TODO: Needed?
	file.flush();

	// Closes the file befor return
	file.close();

	return;
}

void CDebugManager::TimeFormatText(std::string& text)
{
	text.insert(0, GetTime() + std::string( " - " ) );
	
	// make sure that the msg ends with a "new line" 
	if ( text.at( text.size()-1 ) != '\n' )
		text.append( "\n" ); 

}

void CDebugManager::AddWarning(const std::string& text)
{
	// the first time a error is writen a log "header" is added to the file
	if( m_errorAdded == false )
	{
		char cBuff[512];
		StringCchPrintf( cBuff, 512, "Session started %s - %s\n", GetDate(), GetTime() );
		WriteToFile( "error.log", std::string( cBuff ) );
		m_errorAdded = true;
	}

	// format the text
	std::string msg = text;
	TimeFormatText( msg );
	// Adds the msg to the Warning.log file
	WriteToFile( "warning.log", msg, true);
	return;
}

void CDebugManager::AddWarning(const char* formatText, ...)
{
    HRESULT hr;
    va_list argList;
    va_start(argList, formatText);
	hr = StringCchVPrintfEx(m_pFormatBuffer, FORMAT_CBUFFER_SIZE, nullptr, nullptr, STRSAFE_IGNORE_NULLS, formatText, argList);
    va_end(argList);
	
	if (hr != S_OK)
		AddError(std::string("Parsing a formated warning failed!"));  
	else
		AddWarning(std::string( m_pFormatBuffer));
}

void CDebugManager::AddError(const std::string& text)
{
	// the first time a warning is writen a log "header" is added to the file
	if( m_warningAdded == false )
	{
		char cBuff[512];
		StringCchPrintf( cBuff, 512, "Session started %s - %s\n", GetDate(), GetTime() );
		WriteToFile( "error.log", std::string( cBuff ) );
		m_warningAdded = true;
	}

	// format the text
	std::string msg = text;
	TimeFormatText( msg );
	// Adds the msg to the Warning.log file
	WriteToFile( "error.log", msg, true);
	return;
}

void CDebugManager::AddError(const char* formatText, ...)
{
    HRESULT hr;
    va_list argList;
    va_start(argList, formatText);
	hr = StringCchVPrintfEx( m_pFormatBuffer, FORMAT_CBUFFER_SIZE, nullptr, nullptr, STRSAFE_IGNORE_NULLS, formatText, argList );
    va_end(argList);
	
	if ( hr != S_OK )
		AddError( std::string("Parsing a formated error failed!") );  
	else
		AddError( std::string( m_pFormatBuffer ) );
}

void CDebugManager::AddLog(const std::string& text)
{
	Ogre::LogManager::getSingleton().logMessage(text);
}

void CDebugManager::AddLog(const char* formatText, ...)
{
    HRESULT hr;
    va_list argList;
    va_start(argList, formatText);
	hr = StringCchVPrintfEx( m_pFormatBuffer, FORMAT_CBUFFER_SIZE, nullptr, nullptr, STRSAFE_IGNORE_NULLS, formatText, argList );
    va_end(argList);
	
	if ( hr != S_OK )
		AddError(std::string("Parsing a formated error failed!") );  
	else
		AddLog(std::string(m_pFormatBuffer));
}

void CDebugManager::ManagedLogAdd(const char* fileName, const std::string& text)
{
	// format the text
	std::string msg = text;
	TimeFormatText( msg );

	// first we chek if the managed log olredy exists
	for ( std::vector<class ManagedLogElement>::iterator it = m_managedLogs.begin(); it != m_managedLogs.end(); it++ )
	{
		if ( (*it).file.compare( fileName ) == 0) // The log was found
		{
			(*it).textBuffer += msg; // The text is added to the buffer
			
			if ( (*it).textBuffer.size() > MAX_MANAGED_BUFFER_SIZE ) // cheks if the buffer is to bigg
				ManagedLogEnd( fileName );
			return;
		}
	}

	// the log wasent found so we create it
	m_managedLogs.push_back( ManagedLogElement(&std::string(fileName), &msg) );

	return;
}

void CDebugManager::ManagedLogAdd(const char* fileName, const char* formatText, ...)
{
    HRESULT hr;
    va_list argList;
    va_start(argList, formatText);
	hr = StringCchVPrintfEx( m_pFormatBuffer, FORMAT_CBUFFER_SIZE, nullptr, nullptr, STRSAFE_IGNORE_NULLS, formatText, argList );
    va_end(argList);
	
	if ( hr != S_OK )
		AddError( std::string("Parsing a formated managed log message failed!") );  
	else
		ManagedLogAdd( fileName, std::string( m_pFormatBuffer ) );
}

void CDebugManager::ManagedLogEnd(const char* fileName)
{
	// finds the log in the vector
	for ( std::vector<class ManagedLogElement>::iterator it = m_managedLogs.begin(); it != m_managedLogs.end(); it++ )
	{
		if ( (*it).file.compare( fileName ) == 0 ) // The log was found
		{
			WriteToFile( (*it).file.c_str(), (*it).textBuffer, true); // writes the buffer
			m_managedLogs.erase(it); // and erases the log element
			return;
		}
	}	

	// the log to end wasent in the vector
	AddWarning( std::string("Warning: ManagedLogEnd did not find log ") + std::string(fileName) ); 

	return;
}

void CDebugManager::ManagedLogEndAll()
{
	// loops trow all logs and writes them and then delete them from the vector
	for ( std::vector<class ManagedLogElement>::iterator it = m_managedLogs.begin(); it != m_managedLogs.end(); )
	{
		WriteToFile( (*it).file.c_str(), (*it).textBuffer ); // writes the buffer
		it = m_managedLogs.erase(it); // and erases the log element
	}	

	return;
}


const char* CDebugManager::GetDate()
{
	// get the time
	SYSTEMTIME st;
    GetSystemTime(&st);
	
	// format the string
	StringCchPrintf( m_dateAndTime, 32, "%i-%i-%i", st.wYear, st.wMonth, st.wDay );
	
	return m_dateAndTime;
}


const char* CDebugManager::GetTime()
{
	// get the time
	SYSTEMTIME st;
    GetSystemTime(&st);
	
	// format the string
	StringCchPrintf( m_time, 32, "%02i:%02i %02i:%03i", st.wHour, st.wMinute, st.wSecond, st.wMilliseconds );

	return m_time;
}
