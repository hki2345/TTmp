#pragma once
#include <mutex>
#include <iostream>


class C1
{
private:
	virtual void T1()
	{

	}
	virtual void T2()
	{

	}
	int c1;
	int c2;
	int c3;
	int c4;
	int i1;

public:
	C1();
	~C1();

private:

};

C1::C1()
{
}

C1::~C1()
{
}

int main() {
	std::mutex m1;
	std::mutex m2;
	std::thread t1([&m1, &m2] {
		std::lock_guard<std::mutex> guard1(m1);
		std::lock_guard<std::mutex> guard2(m2);
		std::cout << "1. Acquiring m1." << std::endl;
		//m1.lock();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::cout << "1. Acquiring m2" << std::endl;
		//m2.lock();
		});
	std::thread t2([&m1, &m2] {
		std::lock_guard<std::mutex> guard1(m1);
		std::lock_guard<std::mutex> guard2(m2);
		std::cout << "2. Acquiring m2" << std::endl;
		//m2.lock();
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
		std::cout << "2. Acquiring m1" << std::endl;
		//m1.lock();
		});

	t1.join();
	t2.join();


	C1 T;
	std::cout << sizeof(C1);
}