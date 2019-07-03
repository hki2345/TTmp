#pragma once
#include <Windows.h>

#define NAME 64

class Timer
{
private:
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;
	char m_Name[NAME];

public:
	Timer(const char* _Name);
	~Timer();

public:
	void start();
	void stop();
	void log();
	const long double& elapsed_time() const
	{
		return  ElapsedMicroseconds.QuadPart * .000001;
	}
};

