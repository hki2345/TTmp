//#include "Convention.h"
//#include <xmmintrin.h>
//#include <iostream>
//
//
//class ACC
//{
//public:
//	int ix, iy, iz;
//
//public:
//	ACC();
//	~ACC();
//
//public:
//	// int __clrcall Func2(int _x, int _y, int _z)
//	// {
//	// 	return _x + _y + _z;
//	// }
//};
//
//ACC::ACC() : ix(0), iy(0), iz(0)
//{
//}
//
//ACC::~ACC()
//{
//}
//
//
//
//// https://docs.microsoft.com/ko-kr/dotnet/standard/managed-code - 관리 코드
//// https://docs.microsoft.com/ko-kr/cpp/cpp/clrcall?view=vs-2019 - __clrcall
//// https://docs.microsoft.com/ko-kr/cpp/build/reference/clr-common-language-runtime-compilation?view=vs-2019 - /clr
//// https://ko.wikipedia.org/wiki/%EB%A7%88%EC%9D%B4%ED%81%AC%EB%A1%9C%EC%86%8C%ED%94%84%ED%8A%B8 - clr wiki
//// https://blog.naver.com/work1989/221281910738 - clr 블로그
//
//
//
//int __cdecl Func1(int _x, int _y, int _z, ...)
//{
//	return _x + _y + _z;
//}
////int __clrcall Func2(int _x, int _y, int _z)
////{
////	return _x + _y + _z;
////}
//int __stdcall Func3(int _x, int _y, int _z,...)
//{
//	return _x + _y + _z;
//}
//int __fastcall Func4(int _x, int _y, int _z)
//{
//	return _x + _y + _z;
//}
//int __fastcall Func4test(int _x, int _y, int _z, ... )
//{
//	return _x + _y + _z;
//}
//int __fastcall Func4x(int _x, int _y, int _z, int _w, int _k, int _l)
//{
//	return _x + _y + _z + _w + _k + _l;
//}
////int __thiscall Func5(int _x, int _y, int _z)
////{
////	return _x + _y + _z;
////}
//int __vectorcall Func6(int _x, int _y, int _z)
//{
//	return _x + _y + _z;
//}
//
//
//
//
//int __cdecl Func7(float _x, float _y, float _z)
//{
//	return _x + _y + _z;
//}
//int __cdecl Func7x(float _x, float _y, float _z, float _w, float _k, float _l)
//{
//	return _x + _y + _z;
//}
////int __clrcall Func8(int _x, int _y, int _z)
////{
////	return _x + _y + _z;
////}
//int __stdcall Func9(float _x, float _y, float _z)
//{
//	return _x + _y + _z;
//}
//int __fastcall Func10(float _x, float _y, float _z)
//{
//	return _x + _y + _z;
//}
////int __thiscall Func11(int _x, int _y, int _z)
////{
////	return _x + _y + _z;
////}
//int __vectorcall Func12(float _x, float _y, float _z)
//{
//	return _x + _y + _z;
//}
//
//
//
//
//int __cdecl Func13(__m128 _x, __m128 _y, __m128 _z)
//{
//	return 0;
//}
//int __cdecl Func13x(__m128 _x, __m128 _y, __m128 _z, __m128 _w, __m128 _k, __m128 _l)
//{
//	return 0;
//}
////int __clrcall Func14(int _x, int _y, int _z)
////{
////	return _x + _y + _z;
////}
//int __stdcall Func15(__m128 _x, __m128 _y, __m128 _z)
//{
//	return 0;
//}
//int __fastcall Func16(__m128 _x, __m128 _y, __m128 _z)
//{
//	return 0;
//}
////int __thiscall Func17(int _x, int _y, int _z)
////{
////	return _x + _y + _z;
////}
//int __vectorcall Func18(__m128 _x, __m128 _y, __m128 _z)
//{
//	return 0;
//}
//
//int main()
//{
//	// int(__clrcall * pf)(int, int, int) = &Func2;
//
//
//
//	Func1(1, 2, 3, 4);
//
//	// pf(1, 2, 3);
//
//	Func3(1, 2, 3, 4);
//	Func4(1, 2, 3);
//	Func4test(1, 2, 3, 4, 5, 6, 7);
//	Func4x(1, 2, 3, 4, 5, 6);
//	//Func5(1, 2, 3);
//	Func6(1, 2, 3);
//
//	Func7(1.0f, 2.0f, 3.0f);
//	Func7x(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f);
//	//Func8(1, 2, 3);
//	Func9(1.0f, 2.0f, 3.0f);
//	Func10(1.0f, 2.0f, 3.0f);
//	//Func11(1);
//	Func12(1.0f, 2.0f, 3.0f);
//
//
//	__m128 X = { 0, 0, 0, 0 };
//	__m128 Y = { 0, 0, 0, 0 };
//	__m128 Z = { 0, 0, 0, 0 };
//
//	Func13(X, Y, Z);
//	Func13x(X, Y, Z, X, Y, Z);
//	//Func14(1, 2, 3);
//	Func15(X, Y, Z);
//	Func16(X, Y, Z);
//	//Func17(1, 2, 3);
//	Func18(X, Y, Z);
//
//	return 0;
//}

// crt_vc64.c
// Build for amd64 with: cl /arch:AVX /W3 /FAs crt_vc64.c
// This example creates an annotated assembly listing in
// crt_vc64.asm.
//#include <intrin.h>
//#include <xmmintrin.h>
//typedef struct {
//	__m128 array[2];
//} hva2;    // 2 element HVA type on __m128
//typedef struct {
//	__m256 array[4];
//} hva4;    // 4 element HVA type on __m256
//// Example 1: All vectors
//// Passes a in XMM0, b in XMM1, c in YMM2, d in XMM3, e in YMM4.
//// Return value in XMM0.
//__m128 __vectorcall
//example1(__m128 a, __m128 b, __m256 c, __m128 d, __m256 e) {
//	return d;
//}
//// Example 2: Mixed int, float and vector parameters
//// Passes a in RCX, b in XMM1, c in R8, d in XMM3, e in YMM4,
//// f in XMM5, g pushed on stack.
//// Return value in YMM0.
//__m256 __vectorcall
//example2(int a, __m128 b, int c, __m128 d, __m256 e, float f, int g) {
//	return e;
//}
//// Example 3: Mixed int and HVA parameters
//// Passes a in RCX, c in R8, d in R9, and e pushed on stack.
//// Passes b by element in [XMM0:XMM1];
//// b's stack shadow area is 8-bytes of undefined value.
//// Return value in XMM0.
//__m128 __vectorcall example3(int a, hva2 b, int c, int d, int e) {
//	return b.array[0];
//}
//// Example 4: Discontiguous HVA
//// Passes a in RCX, b in XMM1, d in XMM3, and e is pushed on stack.
//// Passes c by element in [YMM0,YMM2,YMM4,YMM5], discontiguous because
//// vector arguments b and d were allocated first.
//// Shadow area for c is an 8-byte undefined value.
//// Return value in XMM0.
//float __vectorcall example4(int a, float b, hva4 c, __m128 d, int e) {
//	return b;
//}
//// Example 5: Multiple HVA arguments
//// Passes a in RCX, c in R8, e pushed on stack.
//// Passes b in [XMM0:XMM1], d in [YMM2:YMM5], each with
//// stack shadow areas of an 8-byte undefined value.
//// Return value in RAX.
//int __vectorcall example5(int a, hva2 b, int c, hva4 d, int e) {
//	return c + e;
//}
//// Example 6: HVA argument passed by reference, returned by register
//// Passes a in [XMM0:XMM1], b passed by reference in RDX, c in YMM2,
//// d in [XMM3:XMM4].
//// Register space was insufficient for b, but not for d.
//// Return value in [YMM0:YMM3].
//hva4 __vectorcall example6(hva2 a, hva4 b, __m256 c, hva2 d) {
//	return b;
//}
//
//float __vectorcall example7(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l) {
//	return b;
//}
//int __vectorcall example8(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
//	return b;
//}
//
//float __fastcall example7x(float a, float b, float c, float d, float e, float f, float g, float h, float i, float j, float k, float l) {
//	return b;
//}
//int __fastcall example8x(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l) {
//	return b;
//}
//
//int __cdecl main(void)
//{
//	hva4 h4;
//	hva2 h2;
//	int i;
//	float f;
//	__m128 a, b, d;
//	__m256 c, e;
//	a = b = d = _mm_set1_ps(3.0f);
//	c = e = _mm256_set1_ps(5.0f);
//	h2.array[0] = _mm_set1_ps(6.0f);
//	h4.array[0] = _mm256_set1_ps(7.0f);
//	b = example1(a, b, c, d, e);
//	e = example2(1, b, 3, d, e, 6.0f, 7);
//	d = example3(1, h2, 3, 4, 5);
//	f = example4(1, 2.0f, h4, d, 5);
//	i = example5(1, h2, 3, h4, 5);
//	h4 = example6(h2, h4, c, h2);
//	f = example7(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f);
//	i = example8(1,2,3,4,5,6,7,8,9,10,11,12);
//	f = example7x(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f, 10.0f, 11.0f, 12.0f);
//	i = example8x(1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12);
//}