#pragma region SELECT


// 빅오 표기법 N^2 -> squre 면적 만큼 돈다.
// https://ko.wikipedia.org/wiki/%EC%84%A0%ED%83%9D_%EC%A0%95%EB%A0%AC - Wiki
template <typename T>
void selectsort(T* _Arr, const int& _Size)
{
	// 이렇게 포구문이 중첩되거나 제귀형식으로 짜여지면 n^2
	// 배열 인덱스 하나하나에 접근하여 정보를 바꾸는 ㅅ기
	for (int i = 0; i < _Size; i++)
	{
		// 구현 방법 -> 배열 하나하나에 대하여 가장 작은 값 혹은 가장 큰 값을
		// 가장 앞으로 땡기는 방법
		// 가장 작은(큰) 수를 찾았으면 넘어가고
		// 그 다음 인덱스에 대하여 같은 방법으로 자리를 채워나간다.
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
	// 이렇게 포구문이 중첩되거나 제귀형식으로 짜여지면 n^2
	// 배열 인덱스 하나하나에 접근하여 정보를 바꾸는 ㅅ기
	for (int i = 0; i < _Size; i++)
	{
		// 구현 방법 -> 배열 하나하나에 대하여 가장 작은 값 혹은 가장 큰 값을
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


// 빅오 표기법 N^2 -> squre 면적 만큼 돈다.
// 벡터 및 리스트만 지원 할 듯
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
// 두번째 인덱스 부터 시작하며,
// 이전 인덱스들로부터 비교연산을 시작해
// 현재 값보다 큰 값이 왔을 경우에만 바로 앞에 위치 시킨다.
// 이를 해당 위치에 [삽입]한다 표현한다.
// https://ko.wikipedia.org/wiki/%EC%82%BD%EC%9E%85_%EC%A0%95%EB%A0%AC - WiKi
void insertsort(T* _Arr, int _Size)
{
	int j; 
	T Cur;
	for (int i = 1; i < _Size; ++i)
	{
		j = i;
		Cur = _Arr[j];

		// 여기서 인덱스가 앞으로 갈수 있는 최대한의 방법으로 앞으로 땡겨지며
		// 가장 작은 값이 될때까지 앞으로간다.
		// 이는 버블 소트의 반대 버젼이라봐도 무방
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
// 빅오 표기법 N^2 -> squre 면적 만큼 돈다.
template <typename T>
void bubblesort(T* _Arr, const int& _Size)
{
	// 이렇게 포구문이 중첩되거나 제귀형식으로 짜여지면 n^2
	// 배열 인덱스 하나하나에 접근하여 정보를 바꾸는 ㅅ기
	for (int i = 0; i < _Size - 1; ++i)
	{
		for (int j = 0; j < _Size - i - 1; ++j)
		{
			// 다음 꺼가 더 작으면 바꾼다.
			// 이것은 가장 큰 것이 가장 마지막에 보내지는 방식으로
			// 배열 상 뒤쪽에서부터 정렬되는 방식
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
	// 이렇게 포구문이 중첩되거나 제귀형식으로 짜여지면 n^2
	// 배열 인덱스 하나하나에 접근하여 정보를 바꾸는 ㅅ기
	for (int i = 0; i < _Size - 1; ++i)
	{
		for (int j = 0; j < _Size - i - 1; ++j)
		{
			// 다음 꺼가 더 작으면 바꾼다.
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


	// 인터페이스 부분
public:
	static void mergesort(int* _Arr, const int& _Size);
	static void quicksort(int* _Arr, const int& _Size);
	static void heapsort(int* _Arr, const int& _Size);


	// 구현 부분
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