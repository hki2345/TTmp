#include <iostream>
#include <typeinfo.h>
#include <iostream>

using namespace std;

// Returns a hash code based on an address
unsigned short Hash(void* p) {
	unsigned int val = reinterpret_cast<unsigned int>(p);
	return (unsigned short)(val ^ (val >> 16));
}

using namespace std;
int main() {
	int a[20];
	for (int i = 0; i < 20; i++)
		cout << Hash(a + i) << endl;
}


// https://docs.microsoft.com/ko-kr/cpp/cpp/lvalues-and-rvalues-visual-cpp?view=vs-2019 - Lvalue + RValue
// https://docs.microsoft.com/en-us/cpp/cpp/const-cpp?view=vs-2019 - const
// https://ko.wikipedia.org/wiki/%EB%B0%B0%ED%83%80%EC%A0%81_%EB%85%BC%EB%A6%AC%ED%95%A9 - 논리합 XOR
// https://docs.microsoft.com/ko-kr/cpp/cpp/overview-of-declarators?view=vs-2019 - 선언지정자

// https://docs.microsoft.com/ko-kr/cpp/extensions/interior-ptr-cpp-cli?view=vs-2019 - interptr??