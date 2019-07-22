// static3.cpp
// compile with: /EHsc
#include <iostream>


static int var2 = 30;

using namespace std;
struct C {
	void Test(int value) {
		static int var = 22;
		if (var == value)
			cout << "var == value" << endl;
		else
			cout << "var != value" << endl;

		var = value;
	}
};

class A 
{
public:
	void func1()
	{
		cout << "A class func1" << endl;
	}

	void func1() const
	{
		cout << "A class const func1" << endl;
	}

public:
	constexpr A() {};
	~A() {}
};


constexpr float exp(float _x, float _y)
{
	return _x + _y;
}




constexpr float x = 42.0;
constexpr float y{ 108 };
constexpr float z = exp(5, 3);
// constexpr int i; // Error! Not initialized
 constexpr float j = 0;
 constexpr int k = j + 1; //Error! j not a constant expression






class B
{
public:
	int bx;

public:
	constexpr B(const char* _X) : bx(0) {}
	B(const int& _x) : bx(_x) {}
};

constexpr int PLUS(int _x, B _y)
{
	return _x + _y.bx;
}

class TT
{
public:
	int x;
	
public:
	constexpr TT() : x(0) {};
	constexpr TT(const int& _X) : x(_X) {};
};

class TU
{
public:
	int x;


	constexpr void Test()
	{
		// static int I = 0;
		thread_local int I = 0;
	}




public:
	TU() : x(0) {};
	TU(const int& _X) : x(_X) {};
};

constexpr void TMP(TT _x, TU _y)
{

}

constexpr void Test()
{
	//goto A;

	try
	{

	}
	catch (const std::exception&)
	{

	}
}






int main() 
{
	A a;
	a.func1();

	const A ac = A();
	ac.func1();


	PLUS(0, 9);
	PLUS(0, "dd");

	constexpr TT tx = TT();

	constexpr TT yx = { 1 };
}

// https://docs.microsoft.com/ko-kr/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=vs-2019 - Lvalue + RValue
// https://docs.microsoft.com/ko-kr/cpp/cpp/temporary-objects?view=vs-2019 - 임시개체
// https://docs.microsoft.com/ko-kr/cpp/cpp/trivial-standard-layout-and-pod-types?view=vs-2019#literal_types - trivial
// https://ko.wikipedia.org/wiki/%EB%B0%B0%ED%83%80%EC%A0%81_%EB%85%BC%EB%A6%AC%ED%95%A9 - 논리합 XOR
// https://docs.microsoft.com/ko-kr/cpp/extensions/interior-ptr-cpp-cli?view=vs-2019 - interptr??

// 클래스 및 구조체
// https://en.wikipedia.org/wiki/Name_mangling#C++, https://spikez.tistory.com/19 - 네임 멩글링
// https://docs.microsoft.com/ko-kr/cpp/cpp/functions-cpp?view=vs-2019 - 함수
// 함수 오버로딩
// https://docs.microsoft.com/ko-kr/cpp/cpp/overview-of-member-functions?view=vs-2019 - 함수 오버라이딩 (맴버 함수 개요)
// https://docs.microsoft.com/ko-kr/cpp/cpp/constructors-cpp?view=vs-2019 - 생성자