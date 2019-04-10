#ifndef __SOUNDENGINE_EXCEPTION_H__
#define __SOUNDENGINE_EXCEPTION_H__

#include "SoundEnginePrereqs.h"

namespace Sound 
{
	void Check(bool condition, const int errorNumber, const String& description, const String& source);
	void Check(const Error error, const String& description, const String& source);

	String GetErrorDescription(const Error error);

	#define CheckCondition(condition, errorNumber, description) Check((condition), (errorNumber), (description), __FUNCTION__)
	#define CheckError(error, description) Check((error), (description), __FUNCTION__)

} // Namespace

#endif
