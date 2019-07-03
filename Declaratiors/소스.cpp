// hiding_class_names.cpp
// compile with: /EHsc
#include <iostream>
using namespace std;

// Declare class Account at global scope.
class Account
{
public:
	Account(double InitialBalance)
	{
		balance = InitialBalance;
	}
	double GetBalance()
	{
		return balance;
	}
private:
	double balance;
};

double Account = 15.37;            // Hides class name Account



class Outer
{
public:
	class Inner
	{

	};
};

class X
{
public:
	int a, b, c;
	int func1() {};
	int* func2() {};
	int func3(char*) {};

private:

};

int Y()
{
}

int main()
{

	class Account Checking(Account); // Qualifies Account as
									   //  class name

	cout << "Opening account with balance of: "
		<< Checking.GetBalance() << "\n";


	int X::* pIntMember = &X::a;
	int ::X::* pIntMemberX; // the initial :: specifies X is in global scope
	char Outer::Inner::* pIntMemberY; // pointer to char in a nested class

	int (X:: * pmf)(); // pointer to member function of X returning int
	int* (X:: * pmf2)(); // pointer to member function returning pointer to int

	pmf = &X::func1;
	pmf2 = &X::func2;

	//  Function returning type int that takes one
//   argument of type char *.
	typedef int (X::*PIFN)(char*);
	//  Declare an array of 7 pointers to functions
	//   returning int and taking one argument of type
	//   char *.
	PIFN pifnDispatchArray[7];

	pifnDispatchArray[0] = X::func3;
}
const int func1()
{

}