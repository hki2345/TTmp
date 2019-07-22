#include <KTimer.h>
#include <iostream>

int main()
{
	KTimer t1("t1");
	t1.start();

	int a = 0;
	
	for (size_t i = 0; i < 1000; i++)
	{
		std::cout << "T" << std::endl;
	}

	t1.stop();
	t1.log_us();
	 

	return 0;
}