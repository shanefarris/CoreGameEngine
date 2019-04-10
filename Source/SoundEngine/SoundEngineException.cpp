#include "SoundEngineException.h"
#include "IO/CoreLogging.h"

#include "OgreException.h"
#include "OgreLogManager.h"

namespace Sound 
{
void Check(bool condition, const int errorNumber, const String& description, const String& source)
{
	if (!condition)
	{
		Ogre::Exception exception(errorNumber, description, source);
		CORE_LOG(exception.getFullDescription().c_str());
	}
}

void Check(const Error error, const String& description, const String& source)
{
	if (error != AL_NO_ERROR)
	{
		std::stringstream ss;
		ss << description << ": OpenAL Error: " << GetErrorDescription(error);
		CORE_LOG(ss.str().c_str());
	}
}

String GetErrorDescription(const Error error)
{
	switch(error)
	{
	case AL_INVALID_VALUE:
		return String("The value pointer given is not valid");
		break;
	case AL_INVALID_ENUM:
		return String("The specified parameter is not valid");
		break;
	case AL_INVALID_NAME:
		return String("The specified source name is not valid");
		break;
	case AL_INVALID_OPERATION:
		return String("There is no current context");
		break;
	case AL_OUT_OF_MEMORY:
		return String("The requested operation resulted in OpenAL running out of memory");
		break;
/*		case OV_EREAD:
		return String("Read from media.");
		break;
	case OV_ENOTVORBIS:
		return String("Not Vorbis data.");
		break;
	case OV_EVERSION:
		return String("Vorbis version mismatch.");
		break;
	case OV_EBADHEADER:
		return String("Invalid Vorbis header.");
		break;
	case OV_EFAULT:
		return String("Internal logic fault (bug or heap/stack corruption.");
		break;
*/		default:
		return String("Unknown Error");
		break;
	}
}

} // Namespace
