#include "KTimer.h"
#include <Windows.h>
#include <iostream>

KTimer::KTimer(const char* _Name) :
	StartingTime(LARGE_INTEGER()),
	EndingTime(LARGE_INTEGER()),
	ElapsedMicroseconds(LARGE_INTEGER()),
	Frequency(LARGE_INTEGER()),
	m_Name(nullptr)
{
	m_Name = new char[NAME];

	for (size_t i = 0; i < NAME; i++)
	{
		m_Name[i] = _Name[i];
	}
}

KTimer::~KTimer()
{
	if (m_Name != nullptr)
	{
		delete[] m_Name;
	}
}



void KTimer::start()
{
	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);
}

void KTimer::stop()
{
	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;


	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;
}

void KTimer::log_second()
{
	std::cout << m_Name << ": " << ElapsedMicroseconds.QuadPart * .000001 << "sec"<< std:: endl;
}

void KTimer::log_us()
{
	std::cout << m_Name << ": " << ElapsedMicroseconds.QuadPart << "us" << std::endl;
}