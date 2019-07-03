//#include <iostream>
//#include <mutex>
//#include <Windows.h>
//
//
//#include <thread>
//#include <process.h>
//
//#include <crtdbg.h>
//
//#define COUNT 100000
//int g_nSum = 0;
//CRITICAL_SECTION g_cs;
//
//UINT WINAPI FTh(PVOID _Param)
//{
//	EnterCriticalSection(&g_cs);
//	Sleep(100);
//	for (int i = 0; i < COUNT; i++)
//	{
//		g_nSum += i;
//	}
//	std::cout << "12345678901234567890" << std::endl;
//	LeaveCriticalSection(&g_cs);
//
//	_endthreadex(0);
//	
//	return 0;
//}
//
//
//void STh(PVOID _Param)
//{
//	EnterCriticalSection(&g_cs);
//	Sleep(100);
//	for (int i = 0; i < COUNT; i++)
//	{
//		g_nSum += i;
//	}
//	std::cout << "12345678901234567890" << std::endl;
//	LeaveCriticalSection(&g_cs);
//
//	_endthread();
//	// return 0;
//}
//
//
//DWORD WINAPI TTh(LPVOID _Param)
//{
//	EnterCriticalSection(&g_cs);
//	//Sleep(100);
//	for (int i = 0; i < COUNT; i++)
//	{
//		g_nSum += i;
//	}
//	std::cout << "12345678901234567890" << std::endl;
//	LeaveCriticalSection(&g_cs);
//	// _endthread();
//	return 0;
//}
//
//
//void WINAPI FoTh(int a)
//{
//	EnterCriticalSection(&g_cs);
//	Sleep(100);
//	for (int i = 0; i < COUNT; i++)
//	{
//		g_nSum += i;
//	}
//	std::cout << "12345678901234567890" << std::endl;
//	LeaveCriticalSection(&g_cs);
//
//
//	// join ���� �� ����
//	// _endthread();
//	return ;
//}
//
//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	new int;
//	
//	// _CrtSetBreakAlloc(152);
//
//	InitializeCriticalSection(&g_cs);
//	
//	HANDLE H1 = 0;
//	HANDLE H2 = 0;
//	HANDLE H3 = 0;
//
//
//	DWORD TID1;
//	DWORD TID2;
//	DWORD TID3;
//	DWORD EXID1;
//	DWORD EXID2;
//	DWORD EXID3;
//
//	// ������� ���� ���� ����
//	// �ڵ��� ���ο��� �� ��� reinterpret�� ���Źڴ� ���̴�. �ᱸ;�� �ǰ�
//	// ���ø����� �Ǿ��ֱ⿡ ��ȯ��(void)�� ������ �Ű������� ����µ� �� �� �ִ�.
//	std::thread t1(FoTh, 0);
//	// ���� ����, ������ - 0���� �ϸ� �˾Ƽ� ������, �Լ� �ּ�
//	// Arglist �ѱ� ������ ���� ������ nullptr - (void*)������ �ѱ�ٴ� ��,
//	// _InitFlag �ʱ���¸� �����ϴ� �÷��� -�̸� �Ͻ��ߴܵ� ���¿��� ����
//	// ������ ������ �ĺ��� ������ nullptr
//
//	std::cout << g_nSum << std::endl;
//
//	// ex ������ �� �Լ��Ծ��� �ٸ����� - ex ������ �ƴϸ� ���ο���  closehandle�� ȣ���ϹǷ�
//	// �ᱹ ���װ� �ǹ��� �Լ��� �Ǿ���. 
//	H1 = (HANDLE)_beginthreadex(nullptr, 0, &FTh, nullptr, 0, (unsigned*)&TID1);
//	H2 = (HANDLE)_beginthread(&STh, 0, nullptr);
//	H3 = (HANDLE)CreateThread(nullptr, 0, &TTh, nullptr, 0, &TID3);
//
//	GetExitCodeThread(H1, &EXID1);
//	GetExitCodeThread(H2, &EXID2);
//	GetExitCodeThread(H3, &EXID3);
//
//	
//	// �����Լ��� ������ ������� ���� ���� �����Ƿ� ��ٷ��־�� �Ѵ�.
//	WaitForSingleObject(H1, INFINITE);
//	WaitForSingleObject(H2, INFINITE);
//	WaitForSingleObject(H3, INFINITE);
//
//	TerminateThread(H3, EXID3);
//
//	GetExitCodeThread(H1, &EXID1);
//	GetExitCodeThread(H2, &EXID2);
//	GetExitCodeThread(H3, &EXID3);
//
//	std::cout << std::endl << "_beginthreadex ���� ��" << std::endl;
//	std::cout << EXID1 << std::endl;
//	std::cout << EXID2 << std::endl;
//	std::cout << EXID3 << std::endl;
//
//	CloseHandle(H1);
//
//	GetExitCodeThread(H1, &EXID1);
//	GetExitCodeThread(H2, &EXID2);
//	GetExitCodeThread(H3, &EXID3);
//
//	std::cout << std::endl << "_beginthreadex ���� ��" << std::endl;
//	std::cout << EXID1 << std::endl;
//	std::cout << EXID2 << std::endl;
//	std::cout << EXID3 << std::endl;
//
//	t1.join();
//
//	std::cout << std::endl << g_nSum << std::endl;
//	std::cout << "TT" << std::endl;
//	return 0;
//}