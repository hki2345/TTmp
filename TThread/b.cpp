#include "b.h"
#include <iostream>
#include <mutex>
#include <Windows.h>


#include <thread>
#include <process.h>

#include <crtdbg.h>

#define COUNT 100000
int g_nSum = 0;
CRITICAL_SECTION g_cs;

void  FiTh(int a)
{
	EnterCriticalSection(&g_cs);
	Sleep(100);
	for (int i = 0; i < COUNT; i++)
	{
		g_nSum += i;
	}
	std::cout << "12345678901234567890" << std::endl;
	LeaveCriticalSection(&g_cs);
	return;
}void  SeTh(int a)
{
	EnterCriticalSection(&g_cs);
	Sleep(100);
	for (int i = 0; i < COUNT; i++)
	{
		g_nSum += i;
	}
	std::cout << "12345678901234567890" << std::endl;
	LeaveCriticalSection(&g_cs);
	return;
}
void  ThTh(int a)
{
	EnterCriticalSection(&g_cs);
	Sleep(100);
	for (int i = 0; i < COUNT; i++)
	{
		g_nSum += i;
	}
	std::cout << "12345678901234567890" << std::endl;
	LeaveCriticalSection(&g_cs);
	return;
}


class processA
{
private:
	int iA, iB;

public:
	processA(const int& _x, const int& _y);
	~processA();

public:
	void  FoTh(int _a, int _b)
	{
		EnterCriticalSection(&g_cs);
		Sleep(100);
		for (int i = 0; i < COUNT; i++)
		{
			g_nSum += i;
		}
		std::cout << "12345678901234567890" << std::endl;
		LeaveCriticalSection(&g_cs);
		return;
	}
};

processA::processA(const int& _x, const int& _y) : iA(_x), iB(_y)
{
}

processA::~processA()
{
}

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	new int;

	// _CrtSetBreakAlloc(152);

	InitializeCriticalSection(&g_cs);

	processA ca(2, 3);

	// 생성자
	std::thread t1(FiTh, 0);

	// 람다식
	std::thread t2([](int x, int y) {
		EnterCriticalSection(&g_cs);
		Sleep(100);
		for (int i = 0; i < COUNT; i++)
		{
			g_nSum += i;
		}
		std::cout << "12345678901234567890" << std::endl;
		LeaveCriticalSection(&g_cs);
		return; }, 2, 3);

	// 객체 안의 함수
	std::thread t3{ &processA::FoTh, &ca, 2, 3 };

	t1.join();
	t2.join();
	t3.join();

	std::cout << std::endl << g_nSum << std::endl;
}