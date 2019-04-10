#ifndef __CORE_LOGGING_H__
#define __CORE_LOGGING_H__

#include "IO/CDebugManager.h"

#ifdef _DEBUG
	#define CORE_TEXT(name, text) Core::OgreSpecific::CTextOutput::Instance()->SetText(name, text);
	#define CORE_ERR Core::Debug::CDebugManager::Instance()->AddError
	#define CORE_WARN Core::Debug::CDebugManager::Instance()->AddWarning
	#define CORE_LOG Core::Debug::CDebugManager::Instance()->AddLog

	#define CORE_ASSERT(x) \
	if(false == x) { \
		std::cout << "On line " << __LINE__ << ":"; \
		std::cout << " in file " << __FILE__ << ":"; \
		std::cout << " Error !! Assert "<< #x << " failed\n"; \
		abort(); \
	} 
#else
	#define CORE_TEXT(name, text)
	#define CORE_ERR Core::Debug::CDebugManager::Instance()->AddError
	#define CORE_WARN
	#define CORE_LOG
	#define CORE_ASSERT(x)
#endif

#endif // __CORE_LOGGING_H__