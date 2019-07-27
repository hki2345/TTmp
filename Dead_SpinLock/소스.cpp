#include <iostream>
#include <thread>
#include <mutex>

//using namespace std;
//
//// 자원 2개
//mutex resX, resY;
//
//void processA(int i)
//{
//	lock_guard<mutex> m1(resX); // X 자원 소유
//	lock_guard<mutex> m2(resY); // Y 자원 요구
//	cout << " " << i << " ";
//}
//
//void processB(int i)
//{
//	lock_guard<mutex> m2(resY); // Y 자원 소유
//	lock_guard<mutex> m1(resX); // X 자원 요구
//	cout << " " << i << " ";
//}
//
//int main()
//{
//	thread t1(processA, 1);
//	thread t2(processB, 2);
//
//	t1.join();
//	t2.join();
//
//	return 0;
//}

using namespace std;

// 자원 2개
mutex resX;
bool TT = true;

void processA(int i)
{
	lock_guard<mutex> m1(resX); // X 자원 소유
	while (TT == true)
	{

	}

	cout << " " << i << " ";
}

void processB(int i)
{
	lock_guard<mutex> m1(resX); // X 자원 요구

	TT = false;
	cout << " " << i << " ";
}

int main()
{
	thread t1(processA, 1);
	thread t2(processB, 2);

	t1.join();
	t2.join();

	return 0;
}