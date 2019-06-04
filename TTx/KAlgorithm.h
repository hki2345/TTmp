#pragma region SELECT


// ��� ǥ��� N^2 -> squre ���� ��ŭ ����.
// https://ko.wikipedia.org/wiki/%EC%84%A0%ED%83%9D_%EC%A0%95%EB%A0%AC - Wiki
template <typename T>
void selectsort(T* _Arr, const int& _Size)
{
	// �̷��� �������� ��ø�ǰų� ������������ ¥������ n^2
	// �迭 �ε��� �ϳ��ϳ��� �����Ͽ� ������ �ٲٴ� ����
	for (int i = 0; i < _Size; i++)
	{
		// ���� ��� -> �迭 �ϳ��ϳ��� ���Ͽ� ���� ���� �� Ȥ�� ���� ū ����
		// ���� ������ ����� ���
		// ���� ����(ū) ���� ã������ �Ѿ��
		// �� ���� �ε����� ���Ͽ� ���� ������� �ڸ��� ä��������.
		T Min = _Arr[i];
		int X = i;

		for (int j = i + 1; j < _Size; ++j)
		{
			if (Min > _Arr[j])
			{
				X = j;
				Min = _Arr[j];
			}
		}

		if (X != i)
		{
			T Tmp = _Arr[i];
			_Arr[i] = _Arr[X];
			_Arr[X] = Tmp;
		}
	}
}

template <typename T>
void selectsort_rev(T* _Arr, const int& _Size)
{
	// �̷��� �������� ��ø�ǰų� ������������ ¥������ n^2
	// �迭 �ε��� �ϳ��ϳ��� �����Ͽ� ������ �ٲٴ� ����
	for (int i = 0; i < _Size; i++)
	{
		// ���� ��� -> �迭 �ϳ��ϳ��� ���Ͽ� ���� ���� �� Ȥ�� ���� ū ����
		// 
		T Max = _Arr[i];
		int X = i;

		for (int j = i + 1; j < _Size; ++j)
		{
			if (Max > _Arr[j])
			{
				X = j;
				Max = _Arr[j];
			}
		}

		if (X != i)
		{
			T Tmp = _Arr[i];
			_Arr[i] = _Arr[X];
			_Arr[X] = Tmp;
		}
	}
}


// ��� ǥ��� N^2 -> squre ���� ��ŭ ����.
// ���� �� ����Ʈ�� ���� �� ��
//template <typename T>
//void selectsort(T& _STL, const bool& _Rev = false)
//{
//	T::iterator S = _STL.begin();
//	T::iterator E = _STL.end();
//
//	for (int i = 0; i < _Size; i++)
//	{
//		T Min = _STL[i];
//		int X = i;
//
//		for (int j = i + 1; j < _Size; ++j)
//		{
//			if (_Rev == false && Min > _STL[j])
//			{
//				X = j;
//				Min = _STL[j];
//			}
//			else if (_Rev == true && Min < _STL[j])
//			{
//				X = j;
//				Min = _STL[j];
//			}
//		}
//
//		if (X != i)
//		{
//			T Tmp = _STL[i];
//			_STL[i] = _STL[X];
//			_STL[X] = Tmp;
//		}
//	}
//}

#pragma endregion

#pragma region INSERT

template <typename T>
// �ι�° �ε��� ���� �����ϸ�,
// ���� �ε�����κ��� �񱳿����� ������
// ���� ������ ū ���� ���� ��쿡�� �ٷ� �տ� ��ġ ��Ų��.
// �̸� �ش� ��ġ�� [����]�Ѵ� ǥ���Ѵ�.
// https://ko.wikipedia.org/wiki/%EC%82%BD%EC%9E%85_%EC%A0%95%EB%A0%AC - WiKi
void insertsort(T* _Arr, int _Size)
{
	int j; 
	T Cur;
	for (int i = 1; i < _Size; ++i)
	{
		j = i;
		Cur = _Arr[j];

		// ���⼭ �ε����� ������ ���� �ִ� �ִ����� ������� ������ ��������
		// ���� ���� ���� �ɶ����� �����ΰ���.
		// �̴� ���� ��Ʈ�� �ݴ� �����̶���� ����
		while (--j >= 0 && Cur < _Arr[j]) 
		{
			_Arr[j + 1] = _Arr[j];
			_Arr[j] = Cur;
		}
	}
}


#pragma endregion

#pragma region BUBBLE

// https://ko.wikipedia.org/wiki/%EA%B1%B0%ED%92%88_%EC%A0%95%EB%A0%AC - Wiki
// ��� ǥ��� N^2 -> squre ���� ��ŭ ����.
template <typename T>
void bubblesort(T* _Arr, const int& _Size)
{
	// �̷��� �������� ��ø�ǰų� ������������ ¥������ n^2
	// �迭 �ε��� �ϳ��ϳ��� �����Ͽ� ������ �ٲٴ� ����
	for (int i = 0; i < _Size - 1; ++i)
	{
		for (int j = 0; j < _Size - i - 1; ++j)
		{
			// ���� ���� �� ������ �ٲ۴�.
			// �̰��� ���� ū ���� ���� �������� �������� �������
			// �迭 �� ���ʿ������� ���ĵǴ� ���
			if (_Arr[j] > _Arr[j + 1])
			{
				T Tmp = _Arr[j];
				_Arr[j] = _Arr[j + 1];
				_Arr[j + 1] = Tmp;
			}
		}
	}
}


template <typename T>
void bubblesort_rev(T* _Arr, const int& _Size)
{
	// �̷��� �������� ��ø�ǰų� ������������ ¥������ n^2
	// �迭 �ε��� �ϳ��ϳ��� �����Ͽ� ������ �ٲٴ� ����
	for (int i = 0; i < _Size - 1; ++i)
	{
		for (int j = 0; j < _Size - i - 1; ++j)
		{
			// ���� ���� �� ������ �ٲ۴�.
			if (_Arr[j] < _Arr[j + 1])
			{
				T Tmp = _Arr[j];
				_Arr[j] = _Arr[j + 1];
				_Arr[j + 1] = Tmp;
			}
		}
	}
}

#pragma endregion

#pragma region MERGE
class KAlgorithm
{
private:
	KAlgorithm();
	~KAlgorithm();

private:
	static int* Ori;
	static int* TT;


	// �������̽� �κ�
public:
	static void mergesort(int* _Arr, const int& _Size);
	static void quicksort(int* _Arr, const int& _Size);
	static void heapsort(int* _Arr, const int& _Size);


	// ���� �κ�
private:
	// MERGE
	static void Parting(const int& _Start, const int& _End);
	static void Merge(const int& _Start, const int& _Mid, const int& _End);

	// QUICK
	static void Quick(const int& _Start, const int& _End);

	// HEAP
	static void Max_heap(const int& _Start, const int& _End);
	static void Min_heap(const int& _Start, const int& _End);

	static void print_test(const int& _Size);
};
#pragma endregion