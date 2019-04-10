#ifndef __SOUNDENGINE_MEMBER_FUNCTION_POINTER_H__
#define __SOUNDENGINE_MEMBER_FUNCTION_POINTER_H__

#include "SoundEnginePrereqs.h"

namespace Sound 
{
	// Predeclare so we don't need to include CSound.h
	class CSound;

	class CMemberFunctionSlot
	{
	public:
		virtual ~CMemberFunctionSlot(){};
		virtual void execute(CSound* source) = 0;
	};

	template<typename T> class CMemberFunctionPointer : public CMemberFunctionSlot
	{
	public:
		typedef void (T::*MemberFunction)(CSound* source);

		CMemberFunctionPointer() : mUndefined(true){}

		CMemberFunctionPointer(MemberFunction func, T* obj) :
			mFunction(func),
			mObject(obj),
			mUndefined(false)
		{
		}

		virtual ~CMemberFunctionPointer(){}

		void execute(CSound* source)
		{
			if(!mUndefined)
				(mObject->*mFunction)(source);
		}

	protected:
		MemberFunction mFunction;
		T* mObject;
		bool mUndefined;

	}; 

} // Namespace

#endif
