#pragma once
#include <Windows.h>


#if X64

#if _DEBUG 
#pragma comment(lib, "KTimer64DEBUG")
#elif _NDEBUG
#pragma comment(lib, "KTimer64RELEASE")
#elif _NDEBUG
#endif

#elif X86

#if _DEBUG 
#pragma comment(lib, "KTimer86DEBUG")
#elif _NDEBUG
#pragma comment(lib, "KTimer86RELEASE")
#endif


#endif


#define NAME 64

class KTimer
{
private:
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;
	char* m_Name;

public:
	KTimer(const char* _Name);
	~KTimer();

public:
	void start();
	void stop();
	void log_second();
	void log_us();

	const LONGLONG& frequency() const
	{
		return  Frequency.QuadPart;
	}

	const long double& elapsed_time() const
	{
		return  ElapsedMicroseconds.QuadPart * .000001;
	}
};

