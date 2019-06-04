#include "KAlgorithm.h"



KAlgorithm::KAlgorithm()
{
}

KAlgorithm::~KAlgorithm()
{
}

int* KAlgorithm::Ori = nullptr;
int* KAlgorithm::TT = nullptr;


// �ǹ����� �� �� ����Ʈ�� ���� N Log N 
// ��, ��Ʈ�� �ϴ� �������� ������ ��������� �ʿ�� ������ 
// ���� �ʿ�
// ���̿� ���� ������ �ʿ��ϹǷ�, 1���迭�� �����Ͽ� �� �񱳤Ǹ� ��� �����ϴ� 
// ����� �ְ����� ���� �׷� ���� Ŭ������ ����� �����ϰ�
// �� ���հ����� ĸ��ȭ�� ����� �� ���ڴ�.
void KAlgorithm::mergesort(int* _Arr, const int& _Size)
{
	Ori = _Arr;
	TT = new int[_Size];
	Parting(0, _Size - 1);
	delete[] TT;
}


// ���� �ڵ��� �պκ� ���� �޺κ� ���� ������ ������ �Ѵ�.
// �̴� �ణ ���� ���İ� ����� ��� ����.
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


// �ӽ� ������ ���̴� ����
void KAlgorithm::Merge(const int& _Start, const int& _Mid, const int& _End)
{
	for (int i = _Start; i <= _End; ++i)
	{
		TT[i] = Ori[i];
	}

	// ���õ� ������ ���ϴ� �ε��� ��ġ
	int X1 = _Start;
	int X2 = _Mid + 1;

	// ���� ������ ä������ �ε���
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

	// �����ִ� �޸� ����
	// While���� �ε��� ������ �ƴ� �ӽ� �ε��� �̱� ������
	// �� �� �������� �� �ִ�. �̴� �����ִ� �ӽ� �����ҿ� �񱳰� ���� �ʴ�
	// �κ��� �����Ѵٴ� ��
	// ���ʿ��� �����ִ� ���� ������ �������� ������ �����̱� ������
	// ������ ������ �Ǿ��ִ� ����̴�.
	for (; X1 <= _Mid; ++X1)
	{
		Ori[IDX] = TT[X1];
		++IDX;
	}
}




// �ǹ����� �� �� ����Ʈ�� N Log N 
// ���⼭ �ǹ��̶� ������ ���ǵɼ� �ִµ� ������ ���� ��찡 �������� ->
// �ټ��� �ǹ��� ����� ������ ��찡 ���� ������
// ������ �ǹ����� ������� ����̰� ������鼭 �ǹ��������� ū���� �������� �����ϴ� ��
void KAlgorithm::quicksort(int* _Arr, const int& _Size)
{
	Ori = _Arr;

	// �������� �ǹ��ε� ������ ���� �����̱� ������
	// ���� ����� �����ٴ� ������ �ָ� �̷� - �������� ���� ����� ������ ����
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
		// �Ǻ��� ���� ������ ���� �ε����� ������ �ε����� �����.
		while (Ori[Left] < Ori[Pivot])
		{
			++Left;
		}
		while (Ori[Right] > Ori[Pivot])
		{
			--Right;
		}

		// ���� �ε����� ���� �� Ŭ ��� �ٲپ��ش�.
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
	// ����ȭ - Ʈ������ ���� - ��Ʈ ã��
	// �������� ����Ʈ�� ����
	for (int i = _Start; i < _End; i++)
	{
		int idx = i;
		do
		{
			// ���縦 ��Ʈ�� ���� �ִ� ��
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
		// ��Ʈ ���� -> ��Ʈ�� ���� �ڷ� ������ �۾�
		int tmp = Ori[0];
		Ori[0] = Ori[i];
		Ori[i] = tmp;


		int root = 0;
		int c = 1;
	
		
		// �� ���� Ʈ�� ����
		do
		{
			// �θ� ��� ���� - �θ��� * 2 + 1 = �θ��� ����, + 2 ������
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