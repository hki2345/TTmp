#include <Windows.h>
#include <iostream>
#include "Timer.h"



int main()
{
	LARGE_INTEGER StartingTime, EndingTime, ElapsedMicroseconds;
	LARGE_INTEGER Frequency;

	Timer t1("TEST");
	t1.start();

	QueryPerformanceFrequency(&Frequency);
	QueryPerformanceCounter(&StartingTime);


	int  a = 0;
	// Activity to be timed
	for (size_t i = 0; i < 100000; i++)
	{
		a = i;
	}


	QueryPerformanceCounter(&EndingTime);
	ElapsedMicroseconds.QuadPart = EndingTime.QuadPart - StartingTime.QuadPart;
	t1.stop();

	//
	// We now have the elapsed number of ticks, along with the
	// number of ticks-per-second. We use these values
	// to convert to the number of elapsed microseconds.
	// To guard against loss-of-precision, we convert
	// to microseconds *before* dividing by ticks-per-second.
	//

	ElapsedMicroseconds.QuadPart *= 1000000;
	ElapsedMicroseconds.QuadPart /= Frequency.QuadPart;


	t1.log();
	std::cout << "Frequency: " << Frequency.QuadPart << std::endl;
	std::cout << "Start: " << StartingTime.QuadPart << std::endl;
	std::cout << "Ending: " << EndingTime.QuadPart << std::endl;
	std::cout << "Elapse: " << ElapsedMicroseconds.QuadPart << "us" << std::endl;

	return 0;
}