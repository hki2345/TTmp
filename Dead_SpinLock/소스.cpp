#include <iostream>
#include <thread>
#include <mutex>

//using namespace std;
//
//// �ڿ� 2��
//mutex resX, resY;
//
//void processA(int i)
//{
//	lock_guard<mutex> m1(resX); // X �ڿ� ����
//	lock_guard<mutex> m2(resY); // Y �ڿ� �䱸
//	cout << " " << i << " ";
//}
//
//void processB(int i)
//{
//	lock_guard<mutex> m2(resY); // Y �ڿ� ����
//	lock_guard<mutex> m1(resX); // X �ڿ� �䱸
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

// �ڿ� 2��
mutex resX;
bool TT = true;

void processA(int i)
{
	lock_guard<mutex> m1(resX); // X �ڿ� ����
	while (TT == true)
	{

	}

	cout << " " << i << " ";
}

void processB(int i)
{
	lock_guard<mutex> m1(resX); // X �ڿ� �䱸

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