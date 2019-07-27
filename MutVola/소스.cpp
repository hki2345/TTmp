class processA
{
	mutable int ia;
	int ib;
	
	
	processA() : ia(0), ib(0)
	{

	}

	void TT() const
	{
		ia = 3;
		// ib = 3; // 이 부분에서 E0137 오류가 뜬다 - 내용은 수정할 수 없다고 한다.
	}
};

// volatile.cpp
// compile with: /EHsc /O2
#include <iostream>
#include <windows.h>
using namespace std;
volatile bool Sentinel = true;
int CriticalData = 0;
unsigned ThreadFunc1( void* pArguments ) 
{ 
	while (Sentinel) Sleep(0); // volatile spin lock 
						
							   
	// CriticalData load guaranteed after every load of Sentinel 
	cout << "Critical Data = " << CriticalData << endl;
	return 0;
}

unsigned ThreadFunc2( void* pArguments ) 
{
	Sleep(2000);
	CriticalData++; // guaranteed to occur before write to Sentinel
	Sentinel = false; // exit critical section
	return 0;
} 

int main()
{ 
	HANDLE hThread1, hThread2;
	DWORD retCode;
	
	hThread1 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ThreadFunc1, NULL, 0, NULL); 
	hThread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)&ThreadFunc2, NULL, 0, NULL);
	
	if (hThread1 == NULL || hThread2 == NULL)
	{ 
		if (hThread1 != NULL) CloseHandle(hThread1);
		if (hThread2 != NULL) CloseHandle(hThread2);
		
		cout << "CreateThread failed." << endl;
		return 1;
	} 
	
	retCode = WaitForSingleObject(hThread1,3000);
	
	CloseHandle(hThread1);
	CloseHandle(hThread2);
	
	if (retCode == WAIT_OBJECT_0 && CriticalData == 1 ) cout << "Success" << endl;
	else cout << "Failure" << endl; 
}