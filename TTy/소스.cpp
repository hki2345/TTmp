#include <iostream>


class A {
	int a;
	void fa(const int& _TETETE, const int& _TETETd) { a++; }
	virtual void fva() { a++; }
};
class B {
	int b;
	void fb() { b++; }
	virtual void fvb() { b++; }
};
class C : public A {
	int c;
	void fc() { c++; }
	virtual void fvb() { c++; }
};
class D : public A, B {
	int d;
	void fd() { d++; }
	virtual void fvd() { d++; }
};
class K {
	int k; void fk() { k++; }
	virtual void fvk() { k++; }
};
class Z : virtual public A {
	int z;
	void fz() { z++; }
	virtual void fvz() { z++; }
};





int Test()
{
	std::cout << "dd";

	return 90;
}

void main()
{
	std::cout << "int* : " << sizeof(int*) << std::endl;
	typedef void(K:: * fk)();
	std::cout << "일반클래스맴버함수포인터 : " << sizeof(fk) << std::endl;
	typedef void(C:: * fc)();
	std::cout << "단일상속 맴버함수 포인터 : " << sizeof(fc) << std::endl;
	typedef void(D:: * fd)();
	std::cout << "다중상속 맴버함수 포인터 : " << sizeof(fd) << std::endl;
	typedef void(Z:: * fz)();
	std::cout << "가상상속 맴버함수 포인터 : " << sizeof(fz) << std::endl;
	class T;
	typedef void(T:: * ft)();
	std::cout << "전방선언 맴버함수 포인터 : " << sizeof(ft) << std::endl;


	std::cout << "함수크기 : " << sizeof(A) << std::endl;
	std::cout << "함수크기 : " << sizeof(B) << std::endl;
	std::cout << "함수크기 : " << sizeof(C) << std::endl;
	std::cout << "함수크기 : " << sizeof(D) << std::endl;
	std::cout << "함수크기 : " << sizeof(K) << std::endl;
	std::cout << "함수크기 : " << sizeof(Z) << std::endl;


	std::cout << "함수크기 : " << sizeof(long) << std::endl;
	std::cout << "함수크기 : " << sizeof(int) << std::endl;
	std::cout << "함수크기 : " << sizeof(long long) << std::endl;
	std::cout << "함수크기 : " << sizeof(long long int) << std::endl;

	int(*T)();

	T = Test;

	T();

	[]()->double {
		return 42;
	};

	return;
}
