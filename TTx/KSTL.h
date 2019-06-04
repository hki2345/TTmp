#pragma once
#include <string>
#include <stdarg.h>


class KSTL
{

public:
	template <typename T>
	class vector
	{
		static_assert(!_ENFORCE_MATCHING_ALLOCATORS,
			_MISMATCHED_ALLOCATOR_MESSAGE("vector<T, Allocator>", "T"));
	public:
		class iterator
		{
		public:
			friend class vector;

		private:
			T* m_Ptr;
		public:
			iterator() : m_Ptr(nullptr)
			{
			}
			iterator(T* _Ptr) : m_Ptr(_Ptr)
			{
			}
			~iterator()
			{}

		public:
			iterator operator=(const iterator& _Other)
			{
				m_Ptr = _Other.m_Ptr;
			}

			// preincrement
			iterator& operator++()
			{
				m_Ptr += 1;
				return *this;
			}

			// postdecrement
			const iterator operator++(int)
			{
				const iterator Tmp = iterator(m_Ptr);
				m_Ptr += 1;
				return Tmp;
			}
			bool operator!=(const iterator& _Other)
			{
				bool Res = false;
				if (m_Ptr != _Other.m_Ptr)
				{
					Res = true;
				}

				return Res;
			}
			bool operator==(const iterator& _Other)
			{
				bool Res = false;
				if (m_Ptr == _Other.m_Ptr)
				{
					Res = true;
				}

				return Res;
			}

			T& operator*()
			{
				return *m_Ptr;
			}
		};

	public:
		vector() : m_TT(new T[0]), m_Size(0), m_Capacity(0)
		{

		};
		~vector()
		{
			if (nullptr != m_TT)
			{
				delete m_TT;
			}

			m_Size = 0;
		};


	private:
		iterator m_Iter;
		T* m_TT;
		int m_Size;
		int m_Capacity;

	public:
		T& operator[](const T& _Value) const
		{
			return m_TT[_Value];
		}

		T* data()
		{
			return m_TT;
		}

		int& size()
		{
			return m_Size;
		}

		int& capacity()
		{
			return m_Capacity;
		}

		void push_back(const T& _Value)
		{
			++m_Size;
			if (m_Size >= m_Capacity)
			{
				m_Capacity = m_Size + (T)(m_Size * .5f);
				T* Tmp = new T[m_Capacity];

				memcpy_s(Tmp, sizeof(T) * (m_Size - 1), m_TT, sizeof(T) * (m_Size - 1));

				delete m_TT;
				m_TT = Tmp;

				m_TT[m_Size - 1] = _Value;
				return;
			}

			m_TT[m_Size - 1] = _Value;
		}
		
		void reserve(const T& _Value)
		{
			if (_Value < m_Size)
			{
				m_Size = _Value;
			}
			m_Capacity = _Value;
			T* Tmp = new T[m_Capacity];

			memcpy_s(Tmp, sizeof(T) * (m_Size - 1), m_TT, sizeof(T) * (m_Size - 1));

			delete m_TT;
			m_TT = Tmp;
		}

		iterator begin()
		{
			m_Iter.m_Ptr = &m_TT[0];
			return m_Iter;
		}
		iterator end()
		{
			m_Iter.m_Ptr = &m_TT[m_Size];
			return m_Iter;
		}
	};

public:
	// template <typename T>
	class list 
	{
		class iterator
		{
		public:
			friend class list;

		private:
			int* m_Cur;
			int* m_Left;
			int* m_Right;


		public:
			iterator(const int& _Value) : m_Cur(new int(_Value)), m_Left(new int), m_Right(new int)
			{
			}
			iterator() : m_Cur(new int), m_Left(new int), m_Right(new int)
			{
			}
			~iterator()
			{
				delete m_Cur;
				delete m_Left;
				delete m_Left;
			}

		public:
			iterator operator=(const iterator& _Other)
			{
				m_Cur = _Other.m_Cur;
				m_Right = _Other.m_Right;
				m_Left = _Other.m_Left;
			}

			// preincrement
			iterator& operator++()
			{
				m_Cur += 1;
				return *this;
			}

			// postdecrement
			const iterator operator++(int)
			{
				iterator Tmp = *this;
				Tmp.m_Cur += 1;
				return Tmp;
			}
			bool operator!=(const iterator& _Other)
			{
				bool Res = false;
				if (m_Cur != _Other.m_Cur)
				{
					Res = true;
				}

				return Res;
			}
			bool operator==(const iterator& _Other)
			{
				bool Res = false;
				if (m_Cur == _Other.m_Cur)
				{
					Res = true;
				}

				return Res;
			}

			int& operator*()
			{
				return *m_Cur;
			}
		};



	private:
		iterator m_Begin;
		iterator m_End;
		iterator Tmp;
		int m_Size;

	public:
		list() : m_Size(0)
		{

		};
		~list()
		{
			m_Size = 0;
		};
		
	public:
		int& size()
		{
			return m_Size;
		}

		void push_back(const int& _Value)
		{
			/*if (0 == m_Size)
			{
				m_Begin = iterator(_Value);
				m_End = iterator();


				m_Begin.m_Right = m_End.m_Cur;
				m_End.m_Left = m_Begin.m_Cur;
			}
			else
			{
				Tmp = iterator(_Value);
				m_End.m_Right = Tmp.m_Cur;
				
				m_End = iterator();
				Tmp.m_Left = m_End.m_Cur;
			}*/
		}

		iterator begin()
		{
			return m_Begin;
		}
		iterator end()
		{
			return m_End;
		}
	};

public:
	KSTL();
	~KSTL();
};