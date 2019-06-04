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
	std::cout << "�Ϲ�Ŭ�����ɹ��Լ������� : " << sizeof(fk) << std::endl;
	typedef void(C:: * fc)();
	std::cout << "���ϻ�� �ɹ��Լ� ������ : " << sizeof(fc) << std::endl;
	typedef void(D:: * fd)();
	std::cout << "���߻�� �ɹ��Լ� ������ : " << sizeof(fd) << std::endl;
	typedef void(Z:: * fz)();
	std::cout << "������ �ɹ��Լ� ������ : " << sizeof(fz) << std::endl;
	class T;
	typedef void(T:: * ft)();
	std::cout << "���漱�� �ɹ��Լ� ������ : " << sizeof(ft) << std::endl;


	std::cout << "�Լ�ũ�� : " << sizeof(A) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(B) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(C) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(D) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(K) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(Z) << std::endl;


	std::cout << "�Լ�ũ�� : " << sizeof(long) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(int) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(long long) << std::endl;
	std::cout << "�Լ�ũ�� : " << sizeof(long long int) << std::endl;

	int(*T)();

	T = Test;

	T();

	[]()->double {
		return 42;
	};

	return;
}
