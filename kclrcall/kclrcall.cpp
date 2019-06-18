#include "pch.h"
#include <xmmintrin.h>


using namespace System;
int __cdecl Func1(int _x, int _y, int _z, ...)
{
	return 0;
}
int __clrcall Func2(int _x, int _y, int _z)
{
	return 0;
}
int __stdcall Func3(int _x, int _y, int _z, ...)
{
	return 0;
}
int __fastcall Func4(int _x, int _y, int _z)
{
	return 0;
}
int __fastcall Func4x(int _x, int _y, int _z, int _w, int _k, int _l)
{
	return 0;
}
// int __thiscall Func5(int _x, int _y, int _z)
// {
// 	return _x + _y + _z;
// }
int __vectorcall Func6(int _x, int _y, int _z)
{
	return 0;
}



int __cdecl Func7(float _x, float _y, float _z)
{
	return 0;
}
int __cdecl Func7x(float _x, float _y, float _z, float _w, float _k, float _l)
{
	return 0;
}
int __clrcall Func8(float _x, float _y, float _z)
{
	return 0;
}
int __stdcall Func9(float _x, float _y, float _z)
{
	return 0;
}
int __fastcall Func10(float _x, float _y, float _z)
{
	return 0;
}
//int __thiscall Func11(int _x, int _y, int _z)
//{
//	return _x + _y + _z;
//}
int __vectorcall Func12(float _x, float _y, float _z)
{
	return 0;
}




int __cdecl Func13(__m128 _x, __m128 _y, __m128 _z)
{
	return 0;
}
int __cdecl Func13x(__m128 _x, __m128 _y, __m128 _z, __m128 _w, __m128 _k, __m128 _l)
{
	return 0;
}
int __clrcall Func14(__m128 _x, __m128 _y, __m128 _z)
{
	return 0;
}
int __stdcall Func15(__m128 _x, __m128 _y, __m128 _z)
{
	return 0;
}
int __fastcall Func16(__m128 _x, __m128 _y, __m128 _z)
{
	return 0;
}
//int __thiscall Func17(int _x, int _y, int _z)
//{
//	return _x + _y + _z;
//}
int __vectorcall Func18(__m128 _x, __m128 _y, __m128 _z)
{
	return 0;
}


int main() {
	
	//Func1(1,2,3);
	//Func2(1, 2, 3);
	//Func3(1, 2, 3);
	//Func4(1, 2, 3);
	//Func4x(1, 2, 3,4,5,6);
	//Func6(1, 2, 3);

	//Func7(1.0f, 2.0f, 3.0f);
	//Func7x(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f);
	//Func8(1.0f, 2.0f, 3.0f);
	//Func9(1.0f, 2.0f, 3.0f);
	//Func10(1.0f, 2.0f, 3.0f);
	////Func11(1);
	//Func12(1.0f, 2.0f, 3.0f);


	__m128 X = { 0, 0, 0, 0 };
	__m128 Y = { 0, 0, 0, 0 };
	__m128 Z = { 0, 0, 0, 0 };

	Func13(X, Y, Z);
	Func13x(X, Y, Z, X, Y, Z);
	Func14(X, Y, Z);
	Func15(X, Y, Z);
	Func16(X, Y, Z);
	//Func17(1, 2, 3);
	Func18(X, Y, Z);

}


// clr 橇肺璃飘 积己 规过 ぞぞ;;
// https://stackoverflow.com/questions/28777834/using-namespace-system-in-visual-studio-2013?lq=1