 // cl.exe /analyze /EHsc /W4
//#include <iostream>
//
//using namespace std;
//
//int main()
//{
//	int count = 10;
//	int& countRef = count;
//	auto& myAuto = countRef;
//
//	countRef = 11;
//	cout << count << " ";
//
//	myAuto = 12;
//	cout << count << endl;
//
//
//	//const int TT = 10;
//	//const auto CT = TT;
//
//	//CT = 11;
//
//	//cout << endl;
//	//cout << TT << " ";
//	//cout << CT;
//}
//
//#include <initializer_list>
//
//int main()
//{
//	// std::initializer_list<int>
//	auto A = { 1, 2 };
//
//	// std::initializer_list<int>
//	auto B = { 3 };
//
//	// int
//	auto C{ 4 };
//
//	// C3535: cannot deduce type for 'auto' from initializer list'
//	auto D = { 5, 6.7 };
//
//	// C3518 in a direct-list-initialization context the type for 'auto'
//	// can only be deduced from a single initializer expression
//	auto E{ 8, 9 };
//
//	return 0;
//}

// cl /EHsc /nologo /W4
#include <deque>
#include <iostream>
using namespace std;

int main()
{
	deque<double> dqDoubleData(10, 0.1);
	int cnt = 0;

	for (auto iter = dqDoubleData.begin(); iter != dqDoubleData.end(); ++iter)
	{
		std::cout << ++cnt << std::endl;
	}

	// prefer range-for loops with the following information in mind
	// (this applies to any range-for with auto, not just deque)

	for (auto elem : dqDoubleData) // COPIES elements, not much better than the previous examples
	{
		std::cout << ++cnt << std::endl;
	}

	for (auto& elem : dqDoubleData) // observes and/or modifies elements IN-PLACE
	{
		std::cout << ++cnt << std::endl;
	}

	for (const auto& elem : dqDoubleData) // observes elements IN-PLACE
	{
		std::cout << ++cnt << std::endl;
	}

	int v1 = 100, v2 = 200;
	auto x = v1 > v2 ? v1 : v2;
}