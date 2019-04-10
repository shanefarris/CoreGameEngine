#ifndef __PRECISIONTIMER_H__
#define __PRECISIONTIMER_H__

#include <windows.h>

namespace Core
{
	class CPrecisionTimer
	{
		LARGE_INTEGER lFreq, lStart;

	public:
		CPrecisionTimer()
		{
			QueryPerformanceFrequency(&lFreq);
		}

		inline void Start()
		{
			QueryPerformanceCounter(&lStart);
		}
	  
		inline double Stop()
		{
			// Return duration in seconds...
			LARGE_INTEGER lEnd;
			QueryPerformanceCounter(&lEnd);
			return (double(lEnd.QuadPart - lStart.QuadPart) / lFreq.QuadPart);
		}
	};
}

#endif // __PRECISIONTIMER_H__