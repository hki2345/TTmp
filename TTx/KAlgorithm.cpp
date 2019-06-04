#include "KAlgorithm.h"



KAlgorithm::KAlgorithm()
{
}

KAlgorithm::~KAlgorithm()
{
}

int* KAlgorithm::Ori = nullptr;
int* KAlgorithm::TT = nullptr;


// 피벗값을 잘 고른 퀵소트와 같은 N Log N 
// 단, 소트를 하는 과정에서 별도의 저장공간을 필요로 함으로 
// 공간 필요
// 깊이에 따른 스텍이 필요하므로, 1차배열로 마련하여 그 비교ㅗ를 모두 병합하는 
// 방법이 있겠지만 차라리 그럴 빠에 클래스로 만들어 병합하고
// 그 병합과정을 캡슐화로 숨기는 게 낫겠다.
void KAlgorithm::mergesort(int* _Arr, const int& _Size)
{
	Ori = _Arr;
	TT = new int[_Size];
	Parting(0, _Size - 1);
	delete[] TT;
}


// 많은 코딩이 앞부분 파팅 뒷부분 파팅 식으로 진행을 한다.
// 이는 약간 이진 정렬과 비슷한 모습 같다.
void KAlgorithm::Parting(const int& _Start, const int& _End)
{
	int mid = (_Start + _End) / 2;

	if (_Start < _End)
	{
		Parting(_Start, mid);
		Parting(mid + 1, _End);
		Merge(_Start, mid, _End);
	}
}


// 임시 스텍이 쌓이는 공간
void KAlgorithm::Merge(const int& _Start, const int& _Mid, const int& _End)
{
	for (int i = _Start; i <= _End; ++i)
	{
		TT[i] = Ori[i];
	}

	// 마련된 공간에 비교하는 인덱스 위치
	int X1 = _Start;
	int X2 = _Mid + 1;

	// 지정 공간이 채워지는 인덱스
	int IDX = _Start;
	int Tmp = 0;

	while (X1 <= _Mid && X2 <= _End)
	{
		if (TT[X1] > TT[X2])
		{
			Ori[IDX] = TT[X2];
			++X2;
		}
		else
		{
			Ori[IDX] = TT[X1];
			++X1;
		}
		++IDX;
	}

	// 남아있는 메모리 공간
	// While문이 인덱스 조건이 아닌 임시 인덱스 이기 때문에
	// 비교 중 빠져나올 수 있다. 이는 남아있는 임시 보관소에 비교가 되지 않는
	// 부분이 존재한다는 것
	// 뒤쪽에서 남아있는 경우는 어차피 원본에서 복사한 형태이기 때문에
	// 뒤쪽은 정렬이 되어있는 경우이다.
	for (; X1 <= _Mid; ++X1)
	{
		Ori[IDX] = TT[X1];
		++IDX;
	}
}




// 피벗값을 잘 고른 퀵소트는 N Log N 
// 여기서 피벗이란 난수로 정의될수 있는데 반으로 가를 경우가 안정적임 ->
// 다수의 피벗이 가운데를 가르는 경우가 많기 떄문ㅇ
// 끝에서 피벗으로 몰려드는 방식이고 몰려들면서 피벗기준으로 큰수와 작은수를 정리하는 식
void KAlgorithm::quicksort(int* _Arr, const int& _Size)
{
	Ori = _Arr;

	// 마지막이 피벗인데 난수가 원래 구성이긴 하지만
	// 보통 가운데서 나뉜다는 설명이 주를 이룸 - 안정성을 위해 가운데서 나누는 형식
	Quick(0, _Size - 1);
}

void KAlgorithm::Quick(const int& _Start, const int& _End)
{
	int Pivot = (_End + _Start) / 2;
	int Left = _Start;
	int Right = _End;
	int Tmp;


	do
	{
		// 피봇을 만날 때까지 왼쪽 인덱스와 오른쪽 인덱스를 땡긴다.
		while (Ori[Left] < Ori[Pivot])
		{
			++Left;
		}
		while (Ori[Right] > Ori[Pivot])
		{
			--Right;
		}

		// 왼쪽 인덱스가 값이 더 클 경우 바꾸어준다.
		if (Left <= Right)
		{
			Tmp = Ori[Left];
			Ori[Left] = Ori[Right];
			Ori[Right] = Tmp;

			++Left;
			--Right;
		}
	} while (Left <= Right);

	   	  
	if (Left < _End)
	{
		Quick(Left, _End);
	}

	if (Right > _Start)
	{
		Quick(_Start, Right);
	}
}




void KAlgorithm::heapsort(int* _Arr, const int& _Size)
{
	Ori = _Arr;
	Max_heap(0, _Size - 1);
}

void KAlgorithm::Max_heap(const int& _Start, const int& _End)
{
	// 이진화 - 트리구조 정렬 - 루트 찾기
	// 일차적인 이진트리 구현
	for (int i = _Start; i < _End; i++)
	{
		int idx = i;
		do
		{
			// 현재를 루트로 보고 있는 것
			int root = (idx - 1) / 2;
			if (Ori[root] < Ori[idx])
			{
				int Tmp = Ori[root];
				Ori[root] = Ori[idx];
				Ori[idx] = Tmp;
			}
			idx = root;
		} while (idx != 0);
	}

	for (int i = _End - 1; i >= 0; --i)
	{
		// 루트 설정 -> 루트를 제일 뒤로 보내는 작업
		int tmp = Ori[0];
		Ori[0] = Ori[i];
		Ori[i] = tmp;


		int root = 0;
		int c = 1;
	
		
		// 재 이진 트리 구현
		do
		{
			// 부모 노드 설정 - 부모노드 * 2 + 1 = 부모노드 왼쪽, + 2 오른쪽
			c = 2 * root + 1;

			if (c < i - 1 && Ori[c] < Ori[c +1])
			{
				++c;
			}

			if (c < i && Ori[root] < Ori [c])
			{
				tmp = Ori[root];
				Ori[root] = Ori[c];
				Ori[c] = tmp;
			}

			root = c;
		} while (c < i);
	}
}

void KAlgorithm::Min_heap(const int& _Start, const int& _End)
{

}


#include <iostream>
void KAlgorithm::print_test(const int& _Size)
{
	for (int i = 0; i < _Size; i++)
	{
		std::cout << Ori[i] << ' ';
	}

	std::cout << std::endl;
}