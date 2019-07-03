#include "Timer.h"
#include <Windows.h>
#include <iostream>

Timer::Timer(const char* _Name) :
	StartingTime(LARGE_INTEGER()),
	EndingTime(LARGE_INTEGER()),
	ElapsedMicroseconds(LARGE_INTEGER()),
	Frequency(LARGE_INTEGER())
{
	for (size_t i = 0; i < NAME; i++)
	{
		m_Name[i] = _Name[i];
	}
}

Timer::~Timer()
{
}



void Timer::start()
{
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);
}

void Timer::stop()
{
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;


	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
}

void Timer::log()
{
	std::cout << m_Name << ": " << ElapsedMicroseconds.QuadPart * .000001 << "sec"<< std:: endl;
}