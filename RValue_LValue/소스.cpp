// string_concatenation.cpp
// compile with: /EHsc
#include <iostream>
#include <string>
using namespace std;


#include <vector>



int TT = 1000;
int X = 0;


void funcA(int& _X)
{
	X = _X;
}


void funcB(int&& _X)
{
	X = _X;
}

class TEST
{
public:
	TEST(const int& _X)
	{
		cout << _X << endl;
	}
	TEST(const int&& _X)
	{
		cout << _X << endl;
	}

	~TEST()
	{

	}
};

int main()
{
	//funcA(TT);
	//funcB(12);

	//// 오류나는 코드
	//// funcA(12); -> RValue(변수)자리에 LValue(상수)를 넣으려 함 E0461
	//// funcB(TT); -> LValue(상수)자리에 RValue(변수)를 넣으려 함 E1768

	//cout << X << endl;


	TEST XY = TEST(X);
	TEST XX= TEST(5); 
}