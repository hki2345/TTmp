//#include <stdlib.h>
//#include "KAlgorithm.h"
//#include "KSTL.h"
//
//#include <iostream>
//#include <crtdbg.h>
//
//#include <vector>
//
//int main()
//{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//
//	new int;
//
//	int* T1;
//	int* T2;
//	int** T3;
//
//	T1 = (int*)malloc(sizeof(int) * 5);
//	T2 = (int*)calloc(5, sizeof(int));
//	T3 = new int* [5];
//
//	int a = 0;
//
//	free(T1);
//	free(T2);
//	delete[] T3;
//
//	char C3[6] = { 'd', 'e', 'v', 'q','a','x' };
//
//	selectsort(C3, 6);
//
//
//
//	char C4[6] = { 'd', 'e', 'v', 'q','a','x' };
//
//	bubblesort(C4, 6);
//
//	char C5[6] = { 'd', 'e', 'v', 'q','a','x' };
//
//	insertsort(C5, 6);
//
//	int I1[7] = { 32, 10, 35, 46,78,12,82 };
//
//	KAlgorithm::mergesort(I1, 7);
//
//
//	int I2[7] = { 32, 10, 35, 35,78,12,82 };
//
//	KAlgorithm::quicksort(I2, 7);
//
//
//
//
//	int I3[7] = { 32, 10, 35, 35,78,12,82 };
//
//	KAlgorithm::heapsort(I3, 7);
//
//
//	std::vector<char> TC;
//
//	TC.push_back('a');
//	TC.push_back('4');
//	TC.push_back('d');
//	TC.push_back('1');
//	TC.push_back('f');
//	TC.push_back('c');
//	TC.push_back('v');
//	TC.push_back('g');
//
//	KSTL::vector<char> TT;
//
//	TT.push_back('a');
//	TT.push_back('4');
//	TT.push_back('d');
//	TT.push_back('1');
//	TT.push_back('f');
//	TT.push_back('c');
//	TT.push_back('v');
//	TT.push_back('g');
//
//	for (int i = 0; i < TT.size(); i++)
//	{
//		std::cout << TT[i] << ' ';
//	}
//	std::cout << std::endl;
//
//	KSTL::vector<char>::iterator S = TT.begin();
//	KSTL::vector<char>::iterator E = TT.end();
//
//	for (; S != E; ++S)
//	{
//		std::cout << (*S) << ' ';
//	}
//
//	std::vector<char> TSS;
//
//
//	KSTL::list TL;
//	TL.push_back(2);
//	TL.push_back(2);
//	TL.push_back(2);
//	TL.push_back(2);
//}