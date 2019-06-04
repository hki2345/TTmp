#include <iostream>
#include <mutex>
#include <Windows.h>


#include <thread>
#include <process.h>

#include <crtdbg.h>

const int COUNT = 10;
int g_nSum = 0;
CRITICAL_SECTION g_cs;

UINT WINAPI FTh(PVOID _Param)
{
	EnterCriticalSection(&g_cs);
	Sleep(100);
	for (int i = 0; i < COUNT; i++)
	{
		g_nSum += i;
	}
	std::cout << "12345678901234567890" << std::endl;
	LeaveCriticalSection(&g_cs);


	_endthread();
	return 0;
}


UINT WINAPI STh(PVOID _Param)
{
	EnterCriticalSection(&g_cs);
	Sleep(100);
	for (int i = 0; i < COUNT; i++)
	{
		g_nSum += i;
	}
	std::cout << "12345678901234567890" << std::endl;
	LeaveCriticalSection(&g_cs);
	_endthread();
	return 0;
}


DWORD WINAPI TTh(LPVOID _Param)
{
	EnterCriticalSection(&g_cs);
	Sleep(100);
	for (int i = 0; i < COUNT; i++)
	{
		g_nSum += i;
	}
	std::cout << "12345678901234567890" << std::endl;
	LeaveCriticalSection(&g_cs);
	_endthread();
	return 0;
}


void FoTh(int a)
{
	EnterCriticalSection(&g_cs);
	Sleep(100);
	for (int i = 0; i < COUNT; i++)
	{
		g_nSum += i;
	}
	std::cout << "12345678901234567890" << std::endl;
	LeaveCriticalSection(&g_cs);
	_endthread();
	return ;
}

int main()
{

	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	new int;
	
	InitializeCriticalSection(&g_cs);
	
	HANDLE H1 = 0;
	HANDLE H2 = 0;
	HANDLE H3 = 0;


	DWORD TID1;
	DWORD TID2;
	DWORD TID3;

	// 사람들이 많이 쓰는 형태
	// 핸들은 내부에서 본 결과 reinterpret로 쑤셔박는 식이다. 결구;ㄱ 되과
	// 템플릿으로 되어있기에 반환값(void)만 같으면 매개변수는 어떤형태든 들어갈 수 있다.
	std::thread t1 = std::thread(&FoTh, 0);
	// 보안 수준, 사이즈 - 0으로 하면 알아서 맞춰줌, 함수 주소
	// Arglist 넘길 ㅁㅐ개 변수 없으면 nullptr - (void*)형으로 넘긴다는 뜻,
	// _InitFlag 초기상태를 제어하는 플래그 -이면 일시중단된 상태에서 시작
	// 마지막 스레드 식별자 없으면 nullptr

	// ex 버젼은 또 함수규약이 다르더라 - ex 버젼이 아니면 내부에서  closehandle을 호출하므로
	// 결국 버그가 되버린 함수가 되었다. 
	H1 = (HANDLE)_beginthreadex(nullptr, 0, &FTh, nullptr, 0, (unsigned*)&TID1);
	H2 = (HANDLE)_beginthreadex(nullptr, 0, &STh, nullptr, 0, (unsigned*)& TID2);
	H3 = (HANDLE)CreateThread(nullptr, 0, &TTh, nullptr, 0, &TID3);

	// _beginthread(&FTh, 0, nullptr);
	// std::cout << g_nSum << std::endl;
	// _beginthreadex(nullptr, 0, &STh, nullptr, 0, nullptr);

	std::cout << g_nSum << std::endl;
	// 메인함수가 꺼지면 스레드고 뭐고 같이 꺼지므로 기다려주어야 한다.
	//WaitForSingleObject(H2, INFINITE);

	WaitForSingleObject(H1, INFINITE);
	WaitForSingleObject(H2, INFINITE);
	WaitForSingleObject(H3, INFINITE);
	t1.join();


	std::cout << g_nSum << std::endl;
	std::cout << "TT" << std::endl;
	return 0;
}