// dynamic_cast_clr.cpp
// compile with: /clr
using namespace System;

void PrintObjectType(Object^ o) {
	if (dynamic_cast<String^>(o))
		Console::WriteLine("Object is a String");
	else if (dynamic_cast<int^>(o))
		Console::WriteLine("Object is an int");
}

int main() {
	Object^ o1 = "hello";
	Object^ o2 = 10;

	PrintObjectType(o1);
	PrintObjectType(o2);
}