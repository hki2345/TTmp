#include "kthis.h"

class A
{
public:
	int __cdecl Func1(int _x, int _y, int _z, ...)
	{
		return _x + _y + _z;
	}
	//int __clrcall Func2(int _x, int _y, int _z)
	//{
	//	return _x + _y + _z;
	//}
	int __stdcall Func3(int _x, int _y, int _z, ...)
	{
		return _x + _y + _z;
	}
	int __fastcall Func4(int _x, int _y, int _z)
	{
		return _x + _y + _z;
	}
	int __fastcall Func4x(int _x, int _y, int _z, int _w, int _k, int _l)
	{
		return _x + _y + _z + _w + _k + _l;
	}
	int __thiscall Func5(int _x, int _y, int _z)
	{
		return _x + _y + _z;
	}
	int __vectorcall Func6(int _x, int _y, int _z)
	{
		return _x + _y + _z;
	}

public:
	A() {};
	~A() {};
};

int main()
{
	A a;

	a.Func1(1, 2, 3, 4);
	a.Func3(1, 2, 3, 4);
	a.Func4(1, 2, 3);
	a.Func4x(1, 2, 3, 4, 5, 6);
	a.Func5(1, 2, 3);
	a.Func6(1, 2, 3);
}